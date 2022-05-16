set(base_SRCS
    Condition.cc
    CountDownLatch.cc
    CurrentThread.cc
    Date.cc
    Exception.cc
    FileUtil.cc
    ProcessInfo.cc
    Thread.cc
    Timestamp.cc
    TimeZone.cc 
)

add_library(muduo_base SHARED ${base_SRCS})
target_link_libraries(muduo_base pthread rt)

if(MUDUO_BUILD_EXAMPLES)
  add_subdirectory(tests)
endif()