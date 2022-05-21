cmake_minimum_required(VERSION 3.22)
project(CUtils)

include_directories(CUtils)
add_executable(CUtils main.c CUtils/Str.c CUtils/Str.h CUtils/Std.h CUtils/InnerExcs.c CUtils/InnerExcs.h CUtils/Console.c CUtils/Console.h)
