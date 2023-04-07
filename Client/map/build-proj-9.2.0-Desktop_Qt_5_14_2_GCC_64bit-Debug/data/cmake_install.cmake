# Install script for directory: /home/denis/Documents/DIP7/Client/map/proj-9.2.0/data

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/proj/proj.ini;/usr/local/share/proj/world;/usr/local/share/proj/other.extra;/usr/local/share/proj/nad27;/usr/local/share/proj/GL27;/usr/local/share/proj/nad83;/usr/local/share/proj/nad.lst;/usr/local/share/proj/CH;/usr/local/share/proj/ITRF2000;/usr/local/share/proj/ITRF2008;/usr/local/share/proj/ITRF2014;/usr/local/share/proj/proj.db;/usr/local/share/proj/deformation_model.schema.json;/usr/local/share/proj/projjson.schema.json;/usr/local/share/proj/triangulation.schema.json")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/proj" TYPE FILE FILES
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/proj.ini"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/world"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/other.extra"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/nad27"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/GL27"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/nad83"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/nad.lst"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/CH"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/ITRF2000"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/ITRF2008"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/ITRF2014"
    "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/data/proj.db"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/deformation_model.schema.json"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/projjson.schema.json"
    "/home/denis/Documents/DIP7/Client/map/proj-9.2.0/data/triangulation.schema.json"
    )
endif()

