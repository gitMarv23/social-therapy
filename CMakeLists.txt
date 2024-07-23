cmake_minimum_required(VERSION 3.29.3)

project(Social_Therapy VERSION 1.0.0 DESCRIPTION "Social Therapy for everyone" LANGUAGES CXX)

add_subdirectory(src)

execute_process(COMMAND cp ${CMAKE_SOURCE_DIR}/credentials.dat ${CMAKE_CURRENT_BINARY_DIR}/src)
