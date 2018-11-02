# Configuring a project that uses google test/mock
# Gene De Lisa
# http://rockhoppertech.com/

cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(gtest1 VERSION 0.0.1 LANGUAGES C CXX)

message( STATUS "PROJECT_NAME: " ${PROJECT_NAME} )

add_definitions(-std=c++0x)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall -Wextra -pedantic")


#####################
# Google Test setup
#
# the following is from
# https://github.com/google/googletest/blob/master/googletest/README.md
# it will grab googletest right here

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()



#####################
# your source and test sources

###############################################################################
## file globbing ##############################################################
###############################################################################

# These instructions search the directory tree when cmake is
# invoked and put all files that match the pattern in the variables
# `sources` and `data`.
file(GLOB_RECURSE sources      src/main/*.cpp src/main/*.hpp src/main/*.h)
file(GLOB_RECURSE sources_app      src/app/*.cpp src/app/*.hpp src/app/*.h)
file(GLOB_RECURSE sources_test src/test/*.cpp src/main/*.hpp src/main/*.h)
file(GLOB_RECURSE data resources/*)

include_directories(src/include)

###############################################################################
## target definitions #########################################################
###############################################################################

# to just do unit testing, uncomment
add_executable(example ${sources} ${sources_app} ${data})

add_executable(unit_tests ${sources_test} ${sources})

set_target_properties(example PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
set_target_properties(unit_tests PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)




# This define is added to prevent collision with the main.
# It might be better solved by not adding the source with the main to the
# testing target.
#target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)


# Now simply link against gtest or gtest_main as needed. Eg
target_link_libraries(unit_tests gtest_main)
target_link_libraries(unit_tests gmock)
target_link_libraries(unit_tests gtest)


