cmake_minimum_required(VERSION 3.8)

project(homework6 CXX)

add_executable(cont Mycontainer.cpp my_list.cpp main.cpp )
target_compile_features(cont PUBLIC cxx_std_17)

if(MSVC)
    target_compile_options(cont PUBLIC /W4 /WX)
else()
    target_compile_options(cont PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
