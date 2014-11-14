class CThreadManage {
private:
    CThreadPool* m_Pool;                //指向实际的线程池
    int m_NumOfThread;                  //初始创建时候允许创建的并发的线程个数
public:
    CThreadManage();
    CThreadManage(int num);
    virtual ~CThreadManage();
    void SetParallelNum(int num);
    void Run(CJob* job,void* jobdata);
    void TerminateAll(void);
};