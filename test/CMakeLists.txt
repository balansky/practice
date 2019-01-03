
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# file(GLOB_RECURSE UNIT_TESTS_SRC_FILES ${PROJECT_SOURCE_DIR}/boost_tests/*.cpp)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${PROJECT_INCLUDE_DIR})

#message(${Boost_LIBRARIES})

#add_definitions(-DBOOST_TEST_DYN_LINK)

set(TEST_SOURCE hacker_rank_test.cpp ${SOURCE})


add_executable(hacker_rank_test ${TEST_SOURCE})

target_link_libraries(hacker_rank_test ${Boost_LIBRARIES})

add_test(HackerRankTest hacker_rank_test COMMAND hacker_rank_test)
