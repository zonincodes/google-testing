include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(multiply_test multiply_test.cpp)
add_executable(ds_test ds_test.cpp)
add_executable(unorderd_sets unorderd_sets.cpp)
add_executable(string_tests string_test.cpp)
add_executable(stream_tests stream_tests.cpp)
add_executable(filesystems_tests filesystems_test.cpp)
add_executable(algo_tests algo_tests.cpp)
target_link_libraries(multiply_test
 PRIVATE
  GTest::GTest
  multiply )
  target_link_libraries(ds_test
 PRIVATE
  GTest::GTest
  data_structures)

  target_link_libraries(unorderd_sets
 PRIVATE
  GTest::GTest
  )

  target_link_libraries(filesystems_tests PRIVATE GTest::GTest)


  target_link_libraries(stream_tests PRIVATE GTest::GTest)

  target_link_libraries(string_tests
 PRIVATE
  GTest::GTest
  )

target_link_libraries(algo_tests PRIVATE GTest::GTest)
add_test(ds_gtests ds_test)
add_test(unorderd_sets unorderd_sets)
add_test(multiply_gtests multiply_test)
add_test(string_tests string_tests)
add_test(stream_tests stream_tests)
add_test(filesystems_tests filesystems_tests)
add_test(algo_tests algo_tests)
