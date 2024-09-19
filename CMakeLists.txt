cmake_minimum_required(VERSION 3.26)
project(ngrams)

set(CMAKE_CXX_STANDARD 17)

# Trova Python e NumPy
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

# Aggiungi le directory di include
include_directories(${Python3_INCLUDE_DIRS})
include_directories(${Python3_NumPy_INCLUDE_DIRS})

# Aggiungi l'eseguibile
add_executable(ngrams main.cpp)

# Link alle librerie di Python
target_link_libraries(ngrams ${Python3_LIBRARIES} ${Python3_NumPy_LIBRARIES})