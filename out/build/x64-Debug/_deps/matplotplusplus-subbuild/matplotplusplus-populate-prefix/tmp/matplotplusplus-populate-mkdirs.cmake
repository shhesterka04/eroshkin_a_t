# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/_deps/matplotplusplus-src"
  "C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/_deps/matplotplusplus-build"
  "C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix"
  "C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/tmp"
  "C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
  "C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src"
  "C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Артём/source/repos/eroshkin_a_t/out/build/x64-Debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp/${subDir}")
endforeach()
