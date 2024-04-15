cmake_minimum_required(VERSION 3.18)

project(CPP2_s21_containers-1)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

set(SRC vector/s21_vector.tpp
        set/s21_set.tpp
        multiset/s21_multiset.tpp
        list/s21_list.tpp
        map/s21_map.tpp
        stack&queue/s21_stack.tpp
        stack&queue/s21_queue.tpp
        tests/vector_tests/test_s21_stress.cpp
)

set(TEST tests/test_s21_main.cpp
        tests/vector_tests/test_s21_constructors.cpp
        tests/vector_tests/test_s21_resize_fn.cpp
        tests/vector_tests/test_s21_at_fn.cpp
        tests/vector_tests/test_s21_push_back_fn.cpp
        tests/vector_tests/test_s21_operators.cpp
        tests/vector_tests/test_s21_back_fn.cpp
        tests/vector_tests/test_s21_front_fn.cpp
        tests/vector_tests/test_s21_data_fn.cpp
        tests/vector_tests/test_s21_iterator.cpp
        tests/vector_tests/test_s21_const_iterator.cpp
        tests/vector_tests/test_s21_empty_fn.cpp
        tests/vector_tests/test_s21_max_size_fn.cpp
        tests/vector_tests/test_s21_shrink_to_fit_fn.cpp
        tests/vector_tests/test_s21_reserve_fn.cpp
        tests/vector_tests/test_s21_clear_fn.cpp
        tests/vector_tests/test_s21_pop_back_fn.cpp
        tests/vector_tests/test_s21_interaction_with_objects.cpp
        tests/vector_tests/test_s21_insert_fn.cpp
        tests/vector_tests/test_s21_erase_fn.cpp
        tests/vector_tests/test_s21_swap.cpp
        tests/queue_tests/test_s21_queue.cpp
        tests/stack_tests/test_s21_stack.cpp
        tests/set_tests/test_s21_set.cpp
        tests/multiset_tests/test_s21_multiset.cpp
        tests/list_tests/test_s21_list.cpp
        tests/map_tests/test_s21_map.cpp
        tests/array_tests/test_s21_array.cpp

)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
add_library(s21_containers STATIC ${SRC})
set_target_properties(s21_containers PROPERTIES PREFIX "" LINKER_LANGUAGE CXX)
target_compile_options(s21_containers PRIVATE -fprofile-arcs -ftest-coverage)

add_subdirectory(tests/googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} tests)
add_executable(tests_run ${TEST})
target_link_libraries(tests_run gtest gtest_main s21_containers gcov)


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
