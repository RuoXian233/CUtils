#pragma once

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#if defined (WIN32) || defined (__WIN32__) 

#endif

#if defined (__linux__)

#endif

#define type(obj) _Generic((obj), \
                    char*: "char[]", \
                    int: "int", \
                    float: "float", \
                    int*: "int[]", \
                    float*: "float[]", \
                    double: "double", \
                    double*: "double[]", \
                    long: "long", \
                    long*: "long[]", \
                    str: "str", \
                    default: "object" \
                )
