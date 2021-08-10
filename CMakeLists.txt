cmake_minimum_required(VERSION 3.10)
project(cpp2wasm VERSION 1.0)

message( "Current dir: ${CMAKE_CURRENT_LIST_DIR}" )

#make sure it is all static
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBRARIES OFF)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_C_COMPILER emcc)
SET(CMAKE_CPP_COMPILER em++)


include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES src/*.cpp)
add_executable(cpp2wasm ${SOURCES})

set(CMAKE_EXECUTABLE_SUFFIX ".js")

     
 target_link_options(cpp2wasm
    PRIVATE        
        --bind 
        -g -v
        -s --std=c++17
        -sWASM=1  
        -sLINKABLE=1
        -sEXPORT_ALL=1  
        # -sEXPORTED_FUNCTIONS=_lerp,_incrementX
        # -sEXPORTED_RUNTIME_METHODS=ccall,cwrap
#  --post-js
 )
