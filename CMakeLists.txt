cmake_minimum_required(VERSION 3.25)
project(V_SGMS C)

set(CMAKE_C_STANDARD 99)

add_executable(V_SGMS main.c Struct.h FunctionLib.c FunctionLib.h Init.c Init.h LoginSystem.c LoginSystem.h GradeManagement.c GradeManagement.h StudentDoubleList.c StudentDoubleList.h)
