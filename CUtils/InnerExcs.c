#include "InnerExcs.h"

void raise(
    ExceptionLevel level,
    const char *exc, const char *msg,
    int code, int status,
    size_t line_num, const char *file, const char *func
) {
    START_EXCEPTION_STREAM
    fputs("---------- ERROR ----------\n", stderr);
    fprintf(stderr, "CUtils Traceback (Inner Exception ::%d)\n", (int)level);
    fprintf(stderr, "  Code: %d | Status: %d\n", code, status);
    fprintf(stderr, "  File '%s', line %zd, in %s:\n", file, line_num, func);
    fprintf(stderr, "    %s: %s\n", exc, msg);
    fprintf(stderr, "[System Call %d] %s\n", errno, strerror(errno));
    END_EXCEPTION_STREAM

    if (status < 0) {
        exit(status);
    }
}
