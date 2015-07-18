cmake_minimum_required(VERSION 3.0)
project(LibeventLearning)



#This is settings area
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set (LibeventLearning_VERSION_MAJOR 1)
set (LibeventLearning_VERSION_MINOR 2)

set(SOURCE_FILES src/main.c)

#This is option area
option (USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file (
  "${PROJECT_SOURCE_DIR}/LibeventLearningConfig.h.in"
  "${PROJECT_BINARY_DIR}/LibeventLearningConfig.h"
)

#This is message area
MESSAGE(STATUS "We are building LibeventLearning Project ~")
MESSAGE(STATUS "System is " ${CMAKE_SYSTEM_NAME})

MESSAGE(STATUS "SOURCE dir " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "BINARY dir " ${PROJECT_BINARY_DIR})




#include (CheckFunctionExists.cmake)
include_directories ("${PROJECT_SOURCE_DIR}/src/MathFunctions")
include_directories ("${PROJECT_SOURCE_DIR}/src/thread")
include_directories ("${PROJECT_SOURCE_DIR}/src/http")
include_directories ("${PROJECT_BINARY_DIR}")

#add_subdirectory (src/MathFunctions)

#library
add_library(LibeventLearningMathFunctions src/MathFunctions/mysqrt.h src/MathFunctions/mysqrt.c)
add_library(LibeventLearningPid SHARED src/thread/pid.c)
add_library(LibeventLearningHttp SHARED src/http/fetch.c)

add_executable(LibeventLearning ${SOURCE_FILES} )


target_link_libraries (LibeventLearning LibeventLearningMathFunctions)
target_link_libraries (LibeventLearning LibeventLearningPid)
target_link_libraries (LibeventLearning LibeventLearningHttp)
target_link_libraries (LibeventLearning event)


install (FILES src/MathFunctions/mysqrt.h DESTINATION include)
install (FILES src/http/fetch.h DESTINATION include)
install (FILES src/thread/pid.h DESTINATION include)
install (FILES "${PROJECT_BINARY_DIR}/LibeventLearningConfig.h" DESTINATION include)

install (TARGETS LibeventLearning DESTINATION bin)
install (TARGETS LibeventLearningPid DESTINATION lib)
install (TARGETS LibeventLearningHttp DESTINATION lib)




# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${LibeventLearning_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${LibeventLearning_VERSION_MINOR}")
include (CPack)

