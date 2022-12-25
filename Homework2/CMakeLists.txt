cmake_minimum_required(VERSION 3.8)

project(hello_world CXX)

add_executable(hello_world 
    main.cpp
    example.cpp
    example.h
    move_me.cpp
    move_me.h
)

target_compile_features(hello_world PUBLIC cxx_std_17)

if(MSVC)
    target_compile_options(hello_world PUBLIC /W4 /WX)
else()
    target_compile_options(hello_world PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
