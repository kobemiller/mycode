// =====================================================================================
//
//       Filename:  code.c
//
//    Description:  unix v6源代码（未区分文件名） 
//
//        Version:  1.0
//        Created:  12/30/2014 03:25:49 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

/*fundamental constants: do not change*/

#define USIZE   16      //size of user block(*64)
#define NULL    0
#define NODEV   (-1)    
#define ROOTINO 1       //i number of all roots
#define DIRSIZ  14      //max characters per directory

/* signals: do not change*/

#define NSIG    20
#define SIGHUP  1       //hansup
#define SIGINT  2       //interrupt (rubout)
#define SIGQIT  3       //quit(FS)
#define SIGINS  4       //illegal instruction
#define SIGTRC  5       //trace or breakpoint
#define SIGIOT  6       //iot
#define SIGEMT  7       //emt
#define SIGFPT  8       //floating exception
#define SIGKIL  9       //kill
#define SIGBUS  10      //bus error
#define SIGSEG  11      //segmentation violation
#define SIGSYS  12      //sys
#define SIGPIPE 13      //end of pipe

/* tunable variables */

#define NBUF    15      //size of buffer cache
#define NINODE  100     //number of in core inodes
#define NFILE   100     //number of in core file structures
#define NMOUNT  5       //number of mountable file systems
#define NEXEC   3       //number of simultaneous exec's
#define MAXMEM  (64*32) //max core per process;first number is kw
#define SSIZE   20      //initial stack size (*64 bytes)
#define SINCR   20      //increment of stack (*64 bytes)
#define NOFILE  15      //max open files per process
#define CANBSIZ 256     //max size of typewriter line
#define CMAPSIZ 100     //size of core allocation area
#define SMAPSIZ 100     //size of swap allocation area
#define NCALL   20      //max simultaneous time callouts
#define NPROC   50      //max number of processes
#define NTEXT   40      //max number of pure texts
#define NCLIST  100     //max total clist size
#define HZ      60      //ticks/seconds of the clock

/* priorities: do not alter much */

#define PSWP    -100
#define PINOD   -90
#define PRIBIO  -50
#define PPIPE   1
#define PWAIT   40
#define PSLEP   90
#define PUSER   100

/* certain processor resisters */

#define PS      0177776
#define KL      0177560
#define SW      0177570

/* structures to access integers */

//single integer
struct { int integ; };
//in bytes
struct { char lobytes; char hibytes; };
//as a sequence
struct { int r[]; };

/* various gloval variables */

char    canonb[CANBSIZ];    //buffer for erase and kill
int     coremap[CMAPSIZ];   //space for core allocation
int     swapmap[SMAPSIZ];   //space for swap allocation

int     *rootdir;           //pointer to inode of root derectory

int     cputype;            //type of cpu = 40, 45, or 70

int     execnt;             //number of processes in exec

int     lbolt;              //time of day in 60th not in time
int     time[2];            //time in sec from 1970
int     tout[2];            //time of day of next sleep

int     mpid;               //seneric for unique process id's

char    runin;              //scheduling flag
char    runout;             //scheduling flag
char    runrun;             //scheduling flag

char    curpri;             //more scheduling

int     maxmem;             //actual max memory per process

int     *lks;               //pointer to clock device

int     rootdev;            //dev of root see conf.c
int     swapdev;            //dev of swap see conf.c

int     swplo;              //block number fo swap space
int     nswap;              //size of swap space

int     updlock;            //lock for sync
int     rablock;            //block to be read ahead

char    regloc[];           //locs of saved user registers (see trap.c)

/* 
 * The callout structure is for a routine arranging to be called by the clock
 * interrupt (see clock.c), with a specified argument, within a specified amount
 * of time. It is used, for example, to time tab delays on teletypes*/

struct callo
{
    int c_time;             //incremental time
    int c_arg;              //argument to routine
    int (*c_func)();        //routine
} callout[NCALL];

/* 
 * mount structure: used to locate the super block of a mounted file*/

struct mount
{
    int m_dev;              //device mounted
    int *m_bufp;            //pointer to superblock
    int *m_inodep;          //pointer to mounted on inode
} mount[NMOUNT];

/* kt-11 addresses and bits */

#define UISD    0177600     //first user I-space descriptor register
#define UISA    0177640     //first user I-space address register
#define UDSA    0177660     //first user D-space address register
#define UBMAP   0170200     //access to 11/70 unibus map

#define RO      02          //access abilities
#define WO      04          
#define RW      06
#define ED      010         //expand segment downwards

int             *ka6;       //11/40 KISA6; 11/45 KDSA6

/* 
 * one structure allocated per active process. It contains all data needed about the
 * process while the process may be swapped out. Other per process data (user.h) is
 * swapped with the process*/

struct proc
{
    char    p_stat;
    char    p_flag;
    char    p_pri;          //priority, negative is high
    char    p_sig;          //signal number sent to this process
    char    p_uid;          //user id, used to direct tty signals
    char    p_time;         //resident time for scheduling
    char    p_cpu;          //cpu usage for scheduling
    char    p_nice;         //nice for scheduling
    int     p_ttyp;         //controlling tty
    int     p_pid;          //unique process id
    int     p_ppid;         //process id of parent
    int     p_addr;         //address of swappable image
    int     p_size;         //size of swappable image (*64 bytes)
    int     p_wehan;        //event process is awaiting
    int     *p_textp;       //pointer to text structure
} proc[NPROC];

/* stat codes */
/*      null        0       not assigned */
#define SSLEEP      1       //sleeping on high priority
#define SWAIT       2       //sleeping on low priority
#define SRUN        3       //running
#define SIDL        4       //process is being created
#define SZOMB       5       //process is being terminated
#define SSTOP       6       //process being traced

/* flag codes */

#define SLOAD       01      //in core
#define SSYS        02      //scheduling process
#define SLOCK       04      //process cannot be swapped
#define SSWAP       010     //process is being swapped out
#define STRC        020     //process is being traced
#define SWTED       040     //another tracing flag

/* 
 * the user structure
 * one allocated per process
 * contains all per process data that doesn't need to be referenced while the proecss is swapped
 * the user block is USIZE*64 bytes long; resides at virtual kernel loc 140000; contains the system
 * stack per user; is cross referenced with the proc structure for the same process*/

struct user
{
    int     u_rsav[2];      //save r5, r6 when exchanging stacks
    int     u_fsav[25];     //save fp registers
                            //rsav and fsav must be first in structure
    char    u_segflg;       //flags for IO; uer or kernel space
    char    u_error;        //return error code
    char    u_uid;          //effective user id
    char    u_gid;          //effective group id
    char    u_ruid;         //real user id
    char    u_rgid;         //real group id
    int     u_procp;        //pointer to proc structure
    char    *u_base;        //base address for IO
    char    *u_count;       //bytes remaining for IO
    char    *u_offset[2];   //offset in file for IO
    int     *u_cdir;        //pointer to inode of current directory
    char    u_dbuf[DIRSIZ]; //current pathname component
    char    *u_dirp;        //current pointer to inode
    struct                  //current directory entry
    {
        int     u_ino;      
        char    u_name[DIRSIZ];
    } u_dent;
    int     *u_pdir;        //inode of parent directory of dirp
    int     u_uisa[16];     //prototype segmentation address
    int     u_uisd[16];     //prototype segmentation descriptors
    int     u_ofile[NOFILE];//pointers to file structures of open files
    int     u_arg[5];       //arguments to current system call
    int     u_tsize;        //text size (*64)
    int     u_dsize;        //data size (*64)
    int     u_ssize;        //stack size (*64)
    int     u_sep;          //flag for I and D separation
    int     u_qsav[2];      //label variable for quits and interrupts
    int     u_ssav[2];      //label variable for swapping
    int     u_signal[NSIG]; //disposition of signals
    int     u_utime;        //this process user time
    int     u_stime;        //this process system time
    int     u_cutime[2];    //sum of childs' utimes
    int     u_cstime[2];    //sum of childs' stimes
    int     *u_ar0;         //address of users saved R0
    int     u_prof[4];      //profile arguments
    char    u_intflg;       //catch intr from sys
} u;

/* 
 * u_error codes
 * see section INTRO(II) of the UNIX programmer's manual for meanings of these codes*/
#define EFAULT      106
#define EPERM       1
#define ENOENT      2
#define ESRCH       3
#define EINTR       4
#define EIO         5
#define ENXIO       6
#define E2BIG       7
#define ENOEXEC     8
#define EBADF       9
#define ECHILD      10
#define EAGAIN      11
#define ENOMEM      12
#define EACCES      13
#define ENOTBLK     15
#define EBUSY       16
#define EEXIST      17
#define EXDEV       18
#define ENODEV      19
#define ENOTDIR     20
#define EISDIR      21
#define EINVAL      22
#define ENFILE      23
#define EMFILE      24
#define ENOTTY      25
#define ETXTBSY     26
#define EFBIG       27
#define ENOSPC      28
#define ESPIPE      29
#define EROFS       30
#define EMLINK      31
#define EPIPE       32

/*
 * Page 49 - 68
 * 汇编（暂时掠过）
/low core
br4 = 200
br5 = 240
br6 = 300
br7 = 340
*/

#include "../param.h"
#include "../user.h"
#include "../systm.h"
#include "../proc.h"
#include "../text.h"
#include "../inode.h"
#include "../seg.h"

#define CLOCK1  0177546
#define CLOCK2  0172540

/*
 * Icode is the octal bootstrap
 * program executed in user mode
 * to bring up the system
 */
int icode[]
{
    0104413,    //sys exec;init;initp
    0000014,
    0000010,
    0000777,
    0000014,
    0000000,
    0062457,
    0061564,
    0064457,
    0064556,
    0000164,
};

/*
 * Initialization code.
 * called from m40.s or m45.s as soon as a stack and segmentation
 * have been established.
 * functions:
 * clear and free user core
 * find which clock is configured
 * hand craft 0th process
 * call all initialization routines
 * fork -process 0 to schedule
 *      -process 1 execute bootstrap
 *
 * panic:no clock --neither clock responds
 * loop at loc 6 in user mode --/etc/init
 * cannot be executed
 */
main()
{
    extern schar;
    register i, *p;

    //zero and free all of core

    updlock = 0;
    i = *ka6 + USIZE;
    UISD->r[0] = 077406;
    for ( ;; )
    {
        UISA->r[0] = i;
        if ( fuibyte(0) < 0) 
            break;
        clearseg(i);
        maxmem++;
        mfree(coremap, 1, i);
        i++;
    }
    if ( cputype == 70 )
        for ( i = 0; i < 62; i=+2 )
        {
            UBMAP->r[i] = i << 12;
            UBMAP->r[i+1] = 0;
        }
    printf("mem = %l\n", maxmem * 5 / 16);
    //1577
}
