set(http_SRCS
    # HttpContext.cc
    HttpResponse.cc
)

add_library(muduo_http ${http_SRCS})
target_link_libraries(muduo_http muduo_net)

install(TARGETS muduo_http DESTINATION lib)
set(HEADERS
    # HttpContext.h
    HttpResponse.h
)
install(FILES ${HEADERS} DESTINATION include/muduo/net/http) 

if(MUDUO_BUILD_EXAMPLES)
    message("MUDUO_BUILD_EXAMPLES ON")

    if(BOOSTTEST_LIBRARY)
        message("BOOSTTEST_LIBRARY ON")
    endif()

endif()

# add_subdirectory(tests)