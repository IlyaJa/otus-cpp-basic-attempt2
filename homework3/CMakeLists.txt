cmake_minimum_required(VERSION 3.8)

project(03.homework CXX)

add_executable(
	high_scores
	high_scores.cpp
	check_value.cpp
	random_value.cpp
)

add_executable(
	argument
	argument.cpp
)

target_compile_features(high_scores PUBLIC cxx_std_17)

if(MSVC)
    target_compile_options(high_scores PUBLIC /W4 /WX)
else()
    target_compile_options(high_scores PUBLIC -Wall -Wextra -Werror -pedantic)
endif()

