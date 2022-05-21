#include "Str.h"
#include <stdio.h>
#include <string.h>

typedef struct _str {
    size_t length;
    char *_data;
} _Str; 

int println(str _s) {
    return printf("%s\n", REAL_STR(_s));
}

int print(str _s) {
    return printf("%s", REAL_STR(_s));
}

str new_str(const char *_default) {
    _Str *s = (_Str *)malloc(sizeof(_Str));
    s->length = strlen(_default);
    if (strlen(_default) != 0) {
        s->_data = (char *)malloc(sizeof(char) * strlen(_default));
    } else {
        s->_data = (char *)malloc(sizeof(char));
    }
    
    strcpy(s->_data, _default);
    return (str)s;
}

size_t size(str self) {
    return strlen(REAL_STR(self));
}

void free_str(str self) {
    free(REAL_STR(self));
    ((_Str *)self)->_data = NULL;
    free(self);
    self = NULL;
}

void assign(str self, const char *other) {
    free_str(self);
    ((_Str *)self)->_data = NULL;
    str reallocated_s = new_str(other);
    self = reallocated_s;
}

void assign_s(str self, const str other) {
    assign(self, REAL_STR(other));
}

char get(str self, int index) {
    char *s = REAL_STR(self);
    size_t len = strlen(s);
    int cur_index = 0;
    char ch;

    if ((index < 0 && abs(index) > len) || (index > 0 && index >= len)) {
        char err[DEFAULT_ERR_MSG_SIZE] = {0};
        sprintf(err, "str index out of range (-%zd to %zd accepted but got %d)", len, len - 1, index);
        RAISE_INDEX_EXCEPTION(err);
        return '\0';
    }
    
    if (index >= 0) {
        while (*s != '\0' && cur_index <= index) {
            cur_index++;
            ch = *s;
            s++;
        }
    } else {
        return get(self, len - abs(index));
    }
    
    return ch;
}

const char *str_raw(str self) {
    return ((_Str *)self)->_data;
}

void append(str self, const char *tail) {
    REAL_STR(self) = (char *) realloc(REAL_STR(self), size(self) + strlen(tail) + 1);
    strcat(REAL_STR(self), tail);
}

void insert(str self, size_t index, const char *s) {

}

void insert_head(str self, const char *s) {

}

void append_s(str self, const str tail) {
    append(self, REAL_STR(tail));
}

void insert_s(str self, size_t index, const str s) {

}

void insert_head_s(str self, const str s) {

}

_Bool is_ascii_byte(char ch) {
    return (~(ch >> 8)) == 0;
}

size_t length(str self) {
    size_t s = size(self);
    char *s_data = ((_Str *)self)->_data;
    size_t len = 0;
    char ch;
    while (*s_data != '\0') {
        ch = *s_data;
        if (is_ascii_byte(ch)) {
            s_data++;
        } else {
            s_data++;
            len++;
        }
    }

    return (s - len) / BYTES_PER_NON_ASCII + len;
}



// Method configuration
s_utils String = {
    println, 
    print,
    new_str,
    free_str, 
    assign, 
    assign_s, 
    size, 
    get,
    append,
    insert,
    insert_head,
    append_s,
    insert_s,
    insert_head_s,
    is_ascii_byte,
    length,
    str_raw
};
