// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_THREADPOOL_H
#define MUDUO_BASE_THREADPOOL_H

#include "muduo/base/Condition.h"
#include "muduo/base/Mutex.h"
#include "muduo/base/Thread.h"
#include "muduo/base/Types.h"

#include <deque>
#include <vector>

namespace muduo
{

class ThreadPool : noncopyable
{
public:
    typedef std::function<void()> Task;

    explicit ThreadPool(const string& nameArg = string("ThreadPool"));
    ~ThreadPool();

    // Must be called before start
    void setMaxQueueSize(int maxSize) { maxQueueSize_ = maxSize; }
    void setThreadInitCallback(const Task& cb) { threadInitCallback_ = cb; };

    void start(int numThreads);
    void stop();

    const string& name() const { return name_; }

    size_t queueSize() const;

    // 运行传入的task任务
    // run() 后运行 stop() 将立即返回
    void run(Task f);

private:
    bool isFull() const REQUIRES(mutex_);
    void runInThread();
    Task take();

    mutable MutexLock mutex_;
    Condition notEmpty_ GUARDED_BY(mutex_);
    Condition notFull_ GUARDED_BY(mutex_);
    string name_;
    Task threadInitCallback_;
    std::vector<std::unique_ptr<muduo::Thread>> threads_;
    std::deque<Task> queue_ GUARDED_BY(mutex_);
    size_t maxQueueSize_;
    bool running_;
};

} // namespace muduo

#endif