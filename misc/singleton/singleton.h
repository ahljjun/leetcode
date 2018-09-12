
#ifndef __SINGLETON_H
#define __SINGLETON_H

//https://github.com/chenshuo/muduo/blob/cpp11/muduo/base/Singleton.h
//https://gist.github.com/bianjiang/5846512
// Question: How singleton safely destoryed in mulithreaded enviroment?

#include <memory>
#include <>

template <class T>
class Singleton {
public:
// advanced tech to me: variadic parameters 
    template <typename... Args>
    static T& getInstance(Args&&... args) {
        std::call_once(
            flag,
            [](Args&&... args) {
                m_instance.reset(new T(std::forward<Args>(args)...));
            },
            std::forward<Args>(args)...)
        );
        return *m_instance.get();
    }

protected:
    explicit Singleton<T>() {}
    ~Singleton<T>() {}

private:
    static std::unique_ptr<T> m_instance;
    static std::once_flag flag;
};

template<class T> std::unique_ptr<T> Singleton<T>::m_instance = nullptr;
#endif