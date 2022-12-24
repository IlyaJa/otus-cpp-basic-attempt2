cmake_minimum_required(VERSION 3.5)

project(01.hello_world)

add_executable(hello_world 
    main.cpp
    example.cpp
    example.h
    move_me.cpp
    move_me.h
)

set_target_properties(hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)