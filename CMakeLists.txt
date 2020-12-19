cmake_minimum_required(VERSION 3.8)
project(qt5_bcalc_cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# cmake .. -G "Visual Studio 16 2019" -A x64
if(MSVC)
	ADD_DEFINITIONS(-D_SCL_SECURE_NO_WARNINGS)
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
	
	set(LIBS ${LIBS} kernel32.lib)
endif(MSVC)

if(MINGW OR MSYS)
	set(LIBS ${LIBS} -lmingw32)
endif(MINGW OR MSYS)

# this probably only works on Arch Linux
if(UNIX AND NOT APPLE)
	set(LIBS ${LIBS} )
endif(UNIX AND NOT APPLE)

find_package(Qt5Core)
find_package(Qt5Widgets)

set(MAIN_SOURCE
	main.cpp
	MainWindow.cpp
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
add_executable(${PROJECT_NAME} ${MAIN_SOURCE})
target_link_libraries(${PROJECT_NAME} 
	${LIBS} Qt5::Core Qt5::Widgets)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOMOC OFF)

if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif(MSVC)
