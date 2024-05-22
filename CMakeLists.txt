cmake_minimum_required(VERSION 3.29.3)

project(Social_Therapy VERSION 1.0.0 DESCRIPTION "Social Therapy for everyone" LANGUAGES CXX)

execute_process(COMMAND cp ${CMAKE_SOURCE_DIR}/src/credentials.dat .)

add_executable(Social_Therapy src/BBoard.h src/BBoard.cpp src/Message.h src/Message.cpp src/User.h src/User.cpp src/main.cpp)
