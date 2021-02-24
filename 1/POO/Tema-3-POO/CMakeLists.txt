cmake_minimum_required(VERSION 3.7)
project(Tema3POOv2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Animal.cpp Animal.h nevertebrate.cpp nevertebrate.h vertebrate.cpp vertebrate.h Pesti.cpp Pesti.h Pasari.cpp Pasari.h Mamifere.cpp Mamifere.h Reptile.cpp Reptile.h AtlaZoologic.cpp AtlaZoologic.h Exceptie.cpp Exceptie.h)
add_executable(Tema3POOv2 ${SOURCE_FILES})