set(base_SRCS
    CurrentThread.cc
    Condition.cc
    CountDownLatch.cc
    Timestamp.cc
    TimeZone.cc
)

add_library(muduo_base SHARED ${base_SRCS})
target_link_libraries(muduo_base pthread rt)

if(MUDUO_BUILD_EXAMPLES)
  add_subdirectory(tests)
endif()