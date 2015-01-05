// =====================================================================================
//
//       Filename:  code.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/29/2014 01:36:55 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

/*
 * 简化的锁
 */
#include <stdlib.h>
#include <pthread.h>

#define NHASH 29
#define HASH(id) (((unsigned long)id) % NHASH)

struct foo *fh[NHASH];
pthread_mutex_t hashlock = PTHREAD_MUTEX_INITIALIZER;

struct foo
{
    int             f_count;
    pthread_mutex_t f_lock;
    int             f_id;
    struct foo      *f_next;
};

struct foo* foo_alloc(int id)
{
    //allocate the object
    struct foo  *fp;
    int         idx;

    if ( (fp = malloc(sizeof(struct foo))) != NULL )
    {
        fp->f_count = 1;
        fp->f_id = id;
        if ( pthread_mutex_init(&fp->f_lock, NULL) != 0 )
        {
            free(fp);
            return (NULL);
        }
        idx = HASH(id);
        pthread_mutex_lock(&hashlock);
        fp->f_next = fh[idx];
        fh[idx] = fp;
        pthread_mutex_lock(&fp->f_lock);
        pthread_mutex_unlock(&hashlock);
        //continue initialization
        pthread_mutex_unlock(&fp->f_lock);
    }
    return (fp);
}

void foo_hold(struct foo *fp)
{
    //add a reference to the object
    pthread_mutex_lock(&hashlock);
    fp->f_count++;
    pthread_mutex_unlock(&hashlock);
}

struct foo *foo_find(int id)
{
    //find an exiting object
    struct foo *fp;
    pthread_mutex_lock(&hashlock);
    for ( fp = fh[HASH(id)]; fp != NULL; fp = fp->next )
    {
        if ( fp->f_id == id )
        {
            fp->f_count++;
            break;
        }
    }
    pthread_mutex_unlock(&hashlock);
    return (fp);
}

void foo_rele(struct foo *fp)
{
    //release a reference to the object
     struct foo *tfp;
     int        idx;

     pthread_mutex_unlock(&hashlock);
     if ( --fp->f_count == 0 )
     {
        idx = HASH(fp->f_id);
        tfp = fh[idx];
        if ( tfp == fp )
            fh[idx] = fp->f_next;
        else
        {
            while ( tfp->f_next != fp )
                tfp = tfp->f_next;
            tfp->f_next = fp->f_next;
        }
        pthread_mutex_unlock(&hashlock);
        pthread_mutex_destroy(&fp->f_lock);
        free(fp);
     }
     else
         pthread_mutex_unlock(&hashlock);
}

/*
 * 使用读写锁
 */
struct job
{
    struct job *j_next;
    struct job *j_prev;
    pthread_t   j_id;   //tell which thread handles the job
};

struct queue
{
    struct job          *q_head;
    struct job          *q_tail;
    pthread_rwlock_t    q_lock;
};

//initialize a queue
int queue_init(struct queue *qp)
{
    int err
    qp->q_head = NULL;
    qp->q_tail = NULL;
    err = pthead_rwlock_init(&qp->q_lock, NULL);
    if ( err != 0 )
        return (err);
    //continue initialization
    return 0;
}

//insert a job to the head of the queue
void job_insert(struct queue *qp, struct job *jp)
{
    pthread_rwlock_wrlock(&qp->q_lock);
    jp->j_next = qp->q_head;
    jp->j_prev = NULL;
    if ( qp->q_head != NULL )
        qp->q_head->j_prev = jp;
    else
        qp->q_tail = jp;
    qp->q_head = jp;
    pthread_rwlock_unlock(&qp->q_lock);
}

//append a job on the tail of the queue
void job_append(struct queue *qp, struct job *jp)
{
    pthread_rwlock_wrlock(&qp->q_lock);
    jp->j_next = NULL;
    jp->j_prev = qp->q_tail;
    if ( qp->q_tail != NULL )
        qp->q_tail->j_next = jp;
    else
        qp->q_head = jp;
    qp->q_tail = jp;
    pthread_rwlock_unlock(&qp->q_lock);
}

//remove the given job from a queue
void job_remove(struct queue *qp, struct job *jp)
{
    pthread_rwlock_wrlock(&qp->q_lock);
    if ( jp == qp->q_head )
    {
        qp->head = jp->j_next;
        if ( qp->q_tail == jp )
            qp->q_tail = NULL;
        else
            jp->j_next->j_prev = jp->j_prev;
    }
    else if ( jp == qp->q_tail )
    {
        qp->q_tail = jp->j_prev;
        jp->j_prev->j_next = jp->j_next;
    }
    else
    {
        jp->j_prev->j_next = jp->j_next;
        jp->j_next->j_prev = jp->j_prev;
    }
    pthread_rwlock_unlock(&qp->q_lock);
}

//find a job for the given thread id
struct job* job_find(struct queue *qp, pthread_t id)
{
    struct job *jp;
    if ( pthread_rwlock_rdlock(&qp->q_lock) != 0 )
        return (NULL);
    for ( jp = qp->q_head; jp != NULL, jp = jp->j_next )
        if ( pthread_equal(jp->j_id, id) )
            break;
    pthread_rwlock_unlock(&qp->q_lock);
    return (jp);
}

//获取超时的绝对时间
#include <sys/time.h>
void maketimeout(struct timespec *tsp, long minutes)
{
    struct timeval now;
    //get the current time
    gettimeofday(&now, NULL);
    tsp->tv_sec = now.tv_sec;
    tsp->tv_nsec = now.tv_usec * 1000;
    //add the offset to get timeout value
    tsp->tv_sec += minutes * 60;
}

/*
 * 使用条件变量和互斥量对线程进行同步
 */
struct msg
{
    struct msg *m_next;
};

struct msg *workq;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg()
{
    struct msg *mp;
    for ( ;; )
    {
        pthread_mutex_lock(&qlock);
        while ( workq == NULL )
            pthread_cond_wait(&qready, &qlock);
        mp = workq;
        workq = mp->m_next;
        pthread_mutex_unlock(&qlock);
        //now process the message mp
    }
}

void enqueue_msg(struct msg *mp)
{
    pthread_mutex_lock(&qlock);
    mp->m_next = workq;
    workq = mp;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);
}

/* 
 * 以分离状态创建线程*/
int makethread(void *(*fn)(void *), void *arg)
{
    int             err;
    pthread_t       tid;
    pthread_attr_t  attr;

    err = pthread_attr_init(&attr);
    if ( err != 0 )
        return (err);
    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if ( err == 0 )
        err = pthread_create(&tid, &attr, fn, arg);
    pthread_attr_destroy(&attr);
    return(err);
}

/*
 * getenv的非可重入版本
 */
#define MAXSTRINGSZ     4096
static char envbuf[MAXSTRINGSZ];
extern char **environ;

char *getenv(const char *name)
{
    int i, len;

    len = strlen(name);
    for ( i = 0; environ[i] != NULL; i++ )
        if ( (strncmp(name, envrion[i], len) == 0) && (environ[i][len] == '=') )
        {
            strncpy(envbuf, &environ[i][len], MAXSTRINGSZ-1);
            return envbuf;
        }
    return NULL;
}

/*
 * getenv的可重入（线程安全）版本
 */
extern char **environ;
pthread_mutex_t env_mutex;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;

static void thread_init()
{
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&env_mutex, &attr);
    pthread_mutexattr_destroy(&attr);
}

int getenv_r(const char *name, char *buf, int buflen)
{
    int i, len, olen;

    pthread_once(&init_done, thread_init);
    len = strlen(name);
    pthread_mutex_lock(&env_mutex);
    for ( i = 0; envrion[i] != NULL; i++ )
        if ( (strncmp(name, environ[i], len) == 0) && (envrion[i][len] == '=') )
        {
            olen = strlen(&environ[i][len+1]);
            if ( olen >= buflen )
            {
                pthread_mutex_unlock(&env_mutex);
                return ENOSPC;
            }
            strcpy(buf, &environ[i][len+1]);
            pthread_mutex_unlock(&env_mutex);
            return 0;
        }
    pthread_mutex_unlock(&env_mutex);
    return ENOENT;
}

/*
 *线程安全的getenv兼容版本
 */
#define MAXSTRINGSZ 4096
static pthread_key_t key;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;
pthread_mutex_t env_mutex = PTHREAD_MUTEX_INITIALIZER;

extern char **environ;

static void thread_init()
{
    pthread_key_create(&key, free);
}

char *getenv(const char *name)
{
    int i, len;
    char *envbuf;

    pthread_once(&init_done, thread_init);
    pthread_mutex_lock(&env_mutex);
    envbuf = (char *)pthread_getspecific(key);
    if ( envbuf == NULL )
    {
        envbuf = malloc(MAXSTRINGSZ);
        if ( envbuf == NULL )
        {
            pthread_mutex_unlock(&env_mutex);
            return NULL;
        }
        pthread_setspecific(key, envbuf);
    }
    len = strlen(name);
    for ( i = 0; environ[i] != NULL; i++ )
        if ( (strncmp(name, environ[i], len) == 0) && (environ[i][len] == '=') )
        {
            strncpy(envbuf, &envrion[i][len+1], MAXSTRINGSZ-1);
            pthread_mutex_unlock(&env_mutex);
            return envbuf;
        }
    pthread_mutex_unlock(&env_mutex);
    return NULL;
}







































































































































































































































































































































































