#include "Std.h"
#include "InnerExcs.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define BYTES_PER_NON_ASCII 2
#else
    #define BYTES_PER_NON_ASCII 3
#endif

#define REAL_STR(s) (((_Str *)(s))->_data)

struct __str {};

typedef struct __str* str;

// Method declaration
typedef struct _string_utils {
    int (*println)(str _s);
    int (*print)(str _s);
    str (*new)(const char *_default);
    void (*free)(str self);
    void (*assign)(str self, const char *other);
    void (*assign_s)(str self, const str other);
    size_t (*size)(str self);
    char (*get)(str self, int index);
    void (*append)(str self, const char *tail);
    void (*insert)(str self, size_t index, const char *s);
    void (*insert_head)(str self, const char *s);
    void (*append_s)(str self, const str tail);
    void (*insert_s)(str self, size_t index, const str s);
    void (*insert_head_s)(str self, const str s);
    _Bool (*is_ascii_byte)(char ch);
    size_t (*length)(str self);
    const char *(*raw)(str self);
    str (*slice)(str src, size_t index_start, size_t index_end);
} s_utils;

extern s_utils String;
