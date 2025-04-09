cmake_minimum_required(VERSION 3.30)
project(Task1 C)

set(CMAKE_C_STANDARD 11)

file(GLOB SOURCES1 "LinkList/*.c")
file(GLOB SOURCES2 "queue/*.c")
file(GLOB SOURCES3 "HashMap/*.c")

set(SOURCES ${SOURCES1} ${SOURCES2})

add_executable(Task1
        ${SOURCES}
        queue/test.c
)
