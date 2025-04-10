cmake_minimum_required(VERSION 3.30)
project(unique C)

set(CMAKE_C_STANDARD 11)

include_directories(Task1/HashMap)
include_directories(Task1/LinkList)
include_directories(Task1/queue)
include_directories(Task1/tree)

add_executable(unique
    Task1/HashMap/HashMap.c
    Task1/HashMap/HashMap.h
        Task1/LinkList/Link.c
    Task1/LinkList/Link.h
        Task1/queue/queue.c
    Task1/queue/queue.h
        Task1/tree/Tree.c
    Task1/tree/Tree.h
    Task1/main.c
        Task1/skipList/skipList.c
        Task1/skipList/skipList.h)
