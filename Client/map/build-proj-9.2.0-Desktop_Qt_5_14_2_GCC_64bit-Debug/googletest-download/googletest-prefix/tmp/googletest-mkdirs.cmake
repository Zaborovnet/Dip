# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/googletest-src"
  "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/googletest-build"
  "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/googletest-download/googletest-prefix"
  "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/googletest-download/googletest-prefix/tmp"
  "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp"
  "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src"
  "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/googletest-download/googletest-prefix/src/googletest-stamp${cfgdir}") # cfgdir has leading slash
endif()
