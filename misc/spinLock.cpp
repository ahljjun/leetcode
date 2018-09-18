// C++11 memory 
#include <iostream>
#include <atomic>

class spinLock {
public:
    spinLock() : flag(false) {}
    spinLock(const spinLock&) = delete;
    spinLock& operator=(const spinLock&) = delete;

    void lock() {
        bool expected = false;
        while(!flag.compare_exchange_strong(expected, true)) {
            expected = false;
        }
    }
    void unlock() {
        flag.store(false);
    }

private:
    std::atomic<bool> flag;
};

int num = 0;
spinLock sl;

void thread_proc() {
    for(int i=0; i < 100000; ++i) {
        sm.lock();
        ++num;
        sm.unlock();
    }
}

int main() {
    std::thread t1(thread_proc);
    std::thread t2(thread_proc);

    t1.join();
    t2.join();

    assert(num == 200000);

    std::cout<<"num: "<<num<<std::endl;
    return 0;
}