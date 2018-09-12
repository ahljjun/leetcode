
#ifndef __THREAD_POOL_H
#define __THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <functional>

// we need a bounded queue???

class ThreadPool {
public:
    using Task = std::function<void()>;
    ThreadPool(int threadNum, int qSize) {}

    void putTask(Task);
    void start();
    void stop();

private:
    void threadFunc();
    int thrNum;
    bool bRunning;
    std::vector<std::unique_ptr<std::thread>> thrVec;
    std::condition_variable cv_NotEmpty;
    std::condition_variable cv_NotFull;
    std::mutex  mtx; // protect the following variable
    int qlen;
    std::queue<Task> taskQ;
};


ThreadPool::ThreadPool(int threadNum, int qSize) 
: thrNum(threadNum), bRunning(false), qlen(qSize)
{

}

ThreadPool::start() 
{
    bRunning = true; // if this need to be only_once. consider singlton.
    for(int i=0; i<thrNum; ++i) {
        thrVec.push_back(std::unique_ptr<std::thread>(new std::thread(std::bind(ThreadPool::threadFunc, this)));
    }
}

void ThreadPool::threadFunc() 
{
    while(bRunning) {
        std::unique_lock<std::mutex> lk(mtx);
        while(taskQ.empty()) {
            cv_NotEmpty.wait(lk);
        }
        assert(!taskQ.empty());
        Task t = taskQ.pop_front();
        //execute the task
        t();

        cv_NotFull.notify_one(); //wakeup one thread
        lk.unlock();
    }
}

void ThreadPool::putTask(Task t)
{
    std::unique_lock<std::mutex> lk(mtx);
    while(qlen <= taskQ.size() && bStart) {
        cv_NotFull.wait(lk);
    }

    assert(!taskQ.full());
    taskQ.push_back(std::move(t)); // use move operator for enhancement

    cv_NotEmpty.notify_one(); // wakeup one thread 
    lk.unlock();
}

void ThreadPool::stop() 
{
    //bStart = false; // no lock protected, right????
    if (bStart == false) 
        return;

    {
        std::lock_guard<std::mutex> lk(mtx);
        bStart = false;
        //clear the task queue
        while(!taskQ.empty()) {
            taskQ.pop_front();
        }
    }

    //
    cv_NotEmpty.notify_all();
    cv_NotFull.notify_all();

    // wake up all the waiting threads 
    cv_NotEmpty.notify_all(); // wakeup all thread
    cv_NotFull.notify_all(); //

    //for(auto thrIt = thrVec.begin(); thrIt != thrVec.end(); ++thrIt) 
    //    thrIt->join();       
    for(auto& thr : thrVec) { // this way is better
        thr->join();
    }  
}

void ThreadPool::~ThreadPool() 
{
    // how to gurantee if other threads is calling putTask.... and will not 
    // get an half-dead ThreadPool object
    // in case it dose not call stop before
    if (!bStart) {
        stop();
    }      
}

#endif