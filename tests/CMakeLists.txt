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
add_test(ds_gtests ds_test)
add_test(unorderd_sets unorderd_sets)
add_test(multiply_gtests multiply_test)
