cmake_minimum_required(VERSION 3.18)

project(CPP2_containers-1)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

set(SRC vector/vector.tpp
        set/set.tpp
        multiset/multiset.tpp
        list/list.tpp
        map/map.tpp
        stack/stack.tpp
        queue/queue.tpp
#        tests/vector_tests/test_vector.cpp
)

set(TEST tests/test.cpp
        tests/test_vector.cpp
        tests/test_swap.cpp
        tests/test_queue.cpp
        tests/test_stack.cpp
        tests/test_set.cpp
        tests/test_multiset.cpp
        tests/test_list.cpp
        tests/test_map.cpp
        tests/test_array.cpp

)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
add_library(containers STATIC ${SRC})
set_target_properties(containers PROPERTIES PREFIX "" LINKER_LANGUAGE CXX)
target_compile_options(containers PRIVATE -fprofile-arcs -ftest-coverage)

add_subdirectory(tests/googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} tests)
add_executable(tests_run ${TEST})
target_link_libraries(tests_run gtest gtest_main containers gcov)


add_custom_target(coverage
        COMMAND ./tests_run
        DEPENDS tests_run
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(coverage_report
        COMMAND gcovr -r ${CMAKE_SOURCE_DIR} --html --html-details -o coverage.html --exclude ".*tests/.*"
        DEPENDS coverage
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(test_leaks
        COMMAND valgrind --leak-check=full --error-exitcode=1 ./tests_run
        DEPENDS tests_run
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
