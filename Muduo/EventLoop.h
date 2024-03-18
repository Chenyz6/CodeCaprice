#include <boost/core/noncopyable.hpp>
#include <iostream>
using namespace std;

class EventLoop : boost::noncopyable // no copy class
{
public:
    EventLoop(/* args */);
    ~EventLoop();

    void loop();

    void assertInLoopThread(){
        if(!isInLoopThread()){
            abortNotInLoopThread();
        }
    }
    // bool isInLoopThread() const { return threadId_ == CurrentThread::tid();}
    bool isInLoopThread() const { return threadId_ == gettid();}

private:
    void abortNotInLoopThread();
    bool looping_;
    const pid_t threadId_; // 本对象所属线程ID
};


