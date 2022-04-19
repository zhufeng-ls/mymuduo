add_executable(thread_test Thread_test.cc)
target_link_libraries(thread_test muduo_base)

add_executable(mutex_test Mutex_test.cc)
target_link_libraries(mutex_test muduo_base)

add_executable(gzipfile_test GzipFile_test.cc)
target_link_libraries(gzipfile_test muduo_base z)

add_executable(timestamp_test Timestamp_unittest.cc)
target_link_libraries(timestamp_test muduo_base)