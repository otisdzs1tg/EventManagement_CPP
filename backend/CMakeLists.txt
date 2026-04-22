cmake_minimum_required(VERSION 3.15)
project(EventBackend)

set(CMAKE_CXX_STANDARD 17)

# Khai báo file thực thi
add_executable(server src/main.cpp)

# DÒNG QUAN TRỌNG NHẤT: Chỉ đường cho hệ thống tìm file trong thư mục include
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)