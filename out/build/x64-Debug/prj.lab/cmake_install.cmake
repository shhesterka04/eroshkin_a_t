# Install script for directory: C:/Users/Артём/source/repos/eroshkin_a_t/prj.lab

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Артём/Source/Repos/eroshkin_a_t/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/prj.lab/complex/cmake_install.cmake")
  include("C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/prj.lab/rational/cmake_install.cmake")
  include("C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/prj.lab/bitset/cmake_install.cmake")
  include("C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/prj.lab/bitsetT/cmake_install.cmake")
  include("C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/prj.lab/qu/cmake_install.cmake")
  include("C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/prj.lab/bitsetI/cmake_install.cmake")
  include("C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/prj.lab/bitsetD/cmake_install.cmake")
  include("C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/prj.lab/queueR/cmake_install.cmake")
  include("C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/prj.lab/queueP/cmake_install.cmake")

endif()

