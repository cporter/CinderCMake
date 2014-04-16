
cmake_minimum_required(VERSION 2.8.8)
project(CinderCMake)

set(CINDER_HOME "$ENV{HOME}/project/cinder_master")

include_directories("${CINDER_HOME}/include")
include_directories("${CINDER_HOME}/boost")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(
        CinderCMake
        MACOSX_BUNDLE
        src/CinderCMake.cpp
        resources/MainMenu.xib
)

set_source_files_properties(
  resources/MainMenu.xib
  PROPERTIES
  MACOSX_PACKAGE_LOCATION
  Resources
)

set_target_properties(
  CinderCMake
  PROPERTIES
  MACOSX_BUNDLER_INFO_PLIST
  ${CMAKE_CURRENT_LIST_DIR}/resources/plist.in
)

set(CINDER_FRAMEWORKS Accelerate AudioToolbox AudioUnit CoreAudio QTKit CoreVideo OpenGL Cocoa)

set(CMAKE_EXE_LINKER_FLAGS
  "${CMAKE_EXE_LINKER_FLAGS} -L${CINDER_HOME}/lib -L${CINDER_HOME}/lib/macosx -lcinder -lboost_system")

foreach (framework ${CINDER_FRAMEWORKS})
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework ${framework}")
endforeach ()



        
