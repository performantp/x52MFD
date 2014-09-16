cmake_minimum_required(VERSION 2.8.4)
project(x52MFD)

file(GLOB SOURCE_FILES "*.hpp" "*.cpp" )

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

find_package(Boost COMPONENTS system REQUIRED)
find_package(x52pro REQUIRED)

set(LIBS ${x52pro_lib} ${Boost_SYSTEM_LIBRARY})
SET(CMAKE_CXX_FLAGS "-std=c++0x")
add_executable(X52MFD ${SOURCE_FILES})
target_link_libraries(X52MFD ${LIBS})
TARGET_LINK_LIBRARIES(X52MFD pthread )