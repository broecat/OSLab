cmake_minimum_required(VERSION 2.8)
project(lab2)
set(lab2_sources
shell.cxx
command.h
command.cxx
)
include_directories(boost /usr/include/boost)
add_executable(lab2 ${lab2_sources})