cmake_minimum_required(VERSION 2.8.12)
project(qt5_bcalc_cmake)

# http://www.cmake.org/Wiki/CMake_Useful_Variables


# Instruct CMake to run Qt moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(MSVC)
	ADD_DEFINITIONS(-D_SCL_SECURE_NO_WARNINGS)
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
	
	set(LIBS ${LIBS} kernel32.lib)
	
	# the MSVC target gets cranky if you use / instead of \\ in a path
	
	# this works
	set(CMAKE_PREFIX_PATH "C:\\vclibs\\qt551msvc2015x64")
	# or specifing all three works also
	#set(Qt5Core_DIR "C:\\vclibs\\qt551msvc2015x64\\lib\\cmake\\Qt5Core")
	#set(Qt5Gui_DIR "C:\\vclibs\\qt551msvc2015x64\\lib\\cmake\\Qt5Gui")
	#set(Qt5Widgets_DIR "C:\\vclibs\\qt551msvc2015x64\\lib\\cmake\\Qt5Widgets")
	find_package(Qt5Core)
	find_package(Qt5Widgets)
endif(MSVC)

if(MINGW OR MSYS)
	set(CMAKE_PREFIX_PATH "c:/msys64/mingw64")
	set(CMAKE_INCLUDE_PATH "c:/msys64/mingw64/include")
	set(CMAKE_LIBRARY_PATH "c:/msys64/mingw64/lib")
	
	find_package(Qt5Core)
	find_package(Qt5Widgets)
	
	set(LIBS ${LIBS} -lmingw32)
	include_directories("c:/msys64/mingw64/include/eigen3")
endif(MINGW OR MSYS)

if(APPLE)
	set(CMAKE_PREFIX_PATH "/usr/local")
	set(CMAKE_INCLUDE_PATH "/usr/local/include")
	set(CMAKE_LIBRARY_PATH "/usr/local/lib")
	set(LIBS ${LIBS})
	
	set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt5/5.5.1_2")
	find_package(Qt5Core)
	find_package(Qt5Widgets)
	set(CMAKE_PREFIX_PATH "/usr/local")
	
	include_directories("/usr/local/Cellar/qt5/5.5.1_2/include")
	include_directories("/usr/local/include")
	include_directories("/usr/local/include/eigen3")
	
endif(APPLE)

# this probably only works on Arch Linux
if(UNIX AND NOT APPLE)
	set(CMAKE_PREFIX_PATH "/usr")
	set(CMAKE_INCLUDE_PATH "/usr/include")
	set(CMAKE_LIBRARY_PATH "/usr/lib")
	set(LIBS ${LIBS} )
	
	find_package(Qt5Core)
	find_package(Qt5Widgets)
	
	include_directories("/usr/include")
	include_directories("/usr/include/eigen3")

endif(UNIX AND NOT APPLE)

# enable C14/C++14 for gcc and clang
if(NOT MSVC)
	set(EXTRA_CXX_FLAGS "-std=c++14 -ffast-math -ftree-vectorize")
	set(EXTRA_C_FLAGS "-std=c14 -ffast-math -ftree-vectorize")
	
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${EXTRA_C_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_CXX_FLAGS}")

	set(CMAKE_BUILD_TYPE "debug")
endif(NOT MSVC)

# TODO: enable C11/C++11 for MSVC
if(MSVC)
	# figure out how to enable C11/C++11
	set(CMAKE_BUILD_TYPE "debug")
endif(MSVC)

set(SOURCE_FILES main.cpp
	MainWindow.cpp
	)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


#include_directories("../common-cpp")
target_link_libraries (${PROJECT_NAME} ${LIBS} Qt5::Widgets)

MESSAGE( STATUS "MINGW: " ${MINGW} )
MESSAGE( STATUS "MSYS: " ${MSYS} )
MESSAGE( STATUS "MSVC: " ${MSVC} )
MESSAGE( STATUS "APPLE: " ${APPLE} )
MESSAGE( STATUS "INCLUDE_DIRECTORIES: " ${INCLUDE_DIRECTORIES} )
MESSAGE( STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS} )
MESSAGE( STATUS "CMAKE_C_FLAGS_DEBUG: " ${CMAKE_C_FLAGS_DEBUG} )
MESSAGE( STATUS "CMAKE_C_FLAGS_RELEASE: " ${CMAKE_C_FLAGS_RELEASE} )
MESSAGE( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS} )
MESSAGE( STATUS "CMAKE_CXX_FLAGS_DEBUG: " ${CMAKE_CXX_FLAGS_DEBUG} )
MESSAGE( STATUS "CMAKE_CXX_FLAGS_RELEASE: " ${CMAKE_CXX_FLAGS_RELEASE} )
get_target_property(QtCore_location Qt5::Core LOCATION)
MESSAGE( STATUS "QtCore_location: " ${QtCore_location})
