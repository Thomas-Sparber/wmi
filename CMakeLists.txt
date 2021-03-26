cmake_minimum_required(VERSION 2.6...3.20)
project (Wmi)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -c -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64")

set(WMISOURCES ${PROJECT_SOURCE_DIR}/src/wmi.cpp  ${PROJECT_SOURCE_DIR}/src/wmiresult.cpp) 
include_directories(${TOTAL_INCLUDES}  ${PROJECT_SOURCE_DIR}/include)


add_library(wmi STATIC  ${WMISOURCES})
add_library(diaa_sami_comsupp STATIC ${PROJECT_SOURCE_DIR}/diaa_sami_comsupp/diaa_sami_comsupp.cpp)
add_executable(test_wmi ${PROJECT_SOURCE_DIR}/src/test.cpp)

if(${CMAKE_VERSION} VERSION_GREATER "3.0.0") 
    target_include_directories(wmi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif()
target_link_libraries(wmi ole32 oleaut32 wbemuuid )
target_link_libraries(test_wmi wmi ole32 oleaut32 wbemuuid)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
