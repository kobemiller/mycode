#ifndef PROCESSPOOL_H
#define processpool.h
#pragma once

class CProcesspool
{
public:
    CProcesspool() {}
    virtual ~CProcesspool() {}
public:
    static void init();     //池的初始化
    void destory();         //池的销毁
    void run();             //池的主执行函数
    void schedule();        //调度
    int32_t get_task();     //获取任务
    pushtask();
    poptask();
    bool execute_task();    //执行任务
private:
    static std::map<pid_t, int> pid_map;
    static std::map<bool, task_id>status_map;
    blockingqueue;
    static process_mutex

};

#endif
