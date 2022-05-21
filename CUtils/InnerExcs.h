#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "Console.h"

#define DEFAULT_ERR_MSG_SIZE 128
#define START_EXCEPTION_STREAM puts(RED);
#define IndexException "IndexException"
#define IndexException_code 3
#define END_EXCEPTION_STREAM puts(NONE);
#define RAISE_INDEX_EXCEPTION(msg) raise(ERROR, IndexException, msg, IndexException_code, 1, __LINE__, __FILE__, __func__)

typedef enum _err_lvl {
    WARN,
    ERROR,
    FATAL
} ExceptionLevel;

void raise(
    ExceptionLevel level,
    const char *exc, const char *msg,
    int code, int status,
    size_t line_num, const char *file, const char *func
);
