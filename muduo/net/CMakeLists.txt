include(CheckFunctionExists)

check_function_exists(accept4 HAVE_ACCEPT4)
if(NOT HAVE_ACCEPT4)
    set_source_files_properties(SocketsOps.cc PROPERTIES COMPILE_FLAGS "-DNO_ACCEPT4")
endif()

set(net_SRCS
    Buffer.cc
    Channel.cc
    EventLoop.cc
    Poller.cc
    SocketsOps.cc
    Timer.cc
    TimerQueue.cc    
)

add_library(muduo_net ${net_SRCS})
target_link_libraries(muduo_net muduo_base)

install(TARGETS muduo_net DESTINATION lib)

set(HEADERS
  Buffer.h
  Callbacks.h
  Channel.h
  Endian.h
  EventLoop.h
  Poller.h
  SocketsOps.h
  Timer.h
  TimerId.h
  TimerQueue.h
)
install(FILES ${HEADERS} DESTINATION include/muduo/net)

add_subdirectory(http)

if(MUDUO_BUILD_EXAMPLES)
  add_subdirectory(tests)
endif()