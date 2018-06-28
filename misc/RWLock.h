
#include <mutex>
#include <condition_variable>

// this is simple R/W lock with no control of read/writer
class RWLock {
public:
    RWLock(const RWLock&) = delete; // copy semantics
    RWLock(RWLock&&) = delete ; // move semantics
    RWLock& operator=(const RWLock&) = delete;
    RWLock& operator= (RWLock&&) = delete;

    void RLock() {
        std::unique_lock<std::mutex> lk(mtx);
        while( writer ) {
            writeCv.wait(mtx)
        } 
        readers++;
    }

    void RUnlock() {
        std::lock_guard<std::mutex> lk(mtx);
        if ( 0 == (--readers) ) {
            // we should wake up one writer
            writeCv.notify_one(); 
        }
    }

    void WLock() {
        std::unique_lock<std::mutex> lk(mtx);
        while( writer || readers > 0 ) {
            writeCv.wait(mtx)
        } 
        writer = true;
    }

    void WUnlock() {
        std::lock_guard<std::mutex> lk(mtx);
        writer = false;
        // notify all readers and writers
        writeCv.notify_all();
    }

private:
    bool writer = false; // indicating if there is writer
    size_t readers = 0; // Number of readers
    std::mutex mtx; // mutex protection of the counters
    std::condition_variable writeCv;
};