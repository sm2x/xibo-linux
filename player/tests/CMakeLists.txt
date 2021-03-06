CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(unit_tests)

find_package(GTest REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-zero-as-null-pointer-constant")

find_library(GMOCK NAMES gmock)
file(GLOB_RECURSE TESTS_SOURCES ${CMAKE_SOURCE_DIR}/player/tests/*.cpp ${CMAKE_SOURCE_DIR}/player/tests/*.hpp)

add_executable(${PROJECT_NAME} main.cpp ${TESTS_SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} player_lib ${GMOCK} ${GTEST_LIBRARIES} gst_wrapper xibovideosink ${Gtkmm_LINK_LIBRARIES} ${GStreamer_LINK_LIBRARIES} ${WebKit_LINK_LIBRARIES} ${Boost_LIBRARIES})
