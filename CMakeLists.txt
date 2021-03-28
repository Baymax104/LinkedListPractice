cmake_minimum_required(VERSION 3.17)
project(LinkList C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkList SingleLinkedList.h SingleLinkedList.c DoubleLinkedList.h DoubleLinkedList.c CircularDoubleList.h CircularDoubleList.c StaticLinkedList.h StaticLinkedList.c BucketSort.h BucketSort.c CardinalSort.h CardinalSort.c Polynomial.h Polynomial.c main.c)