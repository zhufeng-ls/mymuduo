set(base_SRCS
    AsyncLogging.cc
    Condition.cc
    CountDownLatch.cc
    CurrentThread.cc
    Date.cc
    Exception.cc
    FileUtil.cc
    LogFile.cc
    Logging.cc
    LogStream.cc
    ProcessInfo.cc
    Thread.cc
    ThreadPool.cc
    Timestamp.cc
    TimeZone.cc 
)

add_library(muduo_base SHARED ${base_SRCS})
target_link_libraries(muduo_base pthread rt)

if(MUDUO_BUILD_EXAMPLES)
  add_subdirectory(tests)
endif()