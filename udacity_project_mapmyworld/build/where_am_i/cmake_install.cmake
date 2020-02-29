# Install script for directory: /home/fftai/Documents/windows_shared_folder/class_udacity_robot_engineer/udacity_robot_software_engineer/udacity_project_mapmyworld/src/where_am_i

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/fftai/Documents/windows_shared_folder/class_udacity_robot_engineer/udacity_robot_software_engineer/udacity_project_mapmyworld/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/fftai/Documents/windows_shared_folder/class_udacity_robot_engineer/udacity_robot_software_engineer/udacity_project_mapmyworld/build/where_am_i/catkin_generated/installspace/where_am_i.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/where_am_i/cmake" TYPE FILE FILES
    "/home/fftai/Documents/windows_shared_folder/class_udacity_robot_engineer/udacity_robot_software_engineer/udacity_project_mapmyworld/build/where_am_i/catkin_generated/installspace/where_am_iConfig.cmake"
    "/home/fftai/Documents/windows_shared_folder/class_udacity_robot_engineer/udacity_robot_software_engineer/udacity_project_mapmyworld/build/where_am_i/catkin_generated/installspace/where_am_iConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/where_am_i" TYPE FILE FILES "/home/fftai/Documents/windows_shared_folder/class_udacity_robot_engineer/udacity_robot_software_engineer/udacity_project_mapmyworld/src/where_am_i/package.xml")
endif()

