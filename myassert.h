#ifndef MYASSERT_H
#define MYASSERT_H

#include <assert.h>

#include "colors.h"

#define DEBUG 1

enum CODES_OF_ERRORS {
    BAD_POINTER_PASSED_IN_FUNC  = 1,
    POP_FRONT_BUT_HEAD_NULL     = 2,
    POP_FRONT_BUT_TAIL_NULL     = 3,
    CRASH_IN_CALLOC_OF_NODE     = 4,
    ERASE_HEAD_OR_TALE          = 5,
};

#ifdef DEBUG
#define MYASSERT(check, error_code, ending)                                                                         \
        do                                                                                                          \
        {                                                                                                           \
            if (!(check))                                                                                           \
            {                                                                                                       \
                printf(MAGENTA ">>>>> Error in code! Error code: %s <<<<<\n", #error_code);                         \
                printf("In File: %s, In Line: %d, In Function: %s\n", __FILE__, __LINE__,__PRETTY_FUNCTION__);      \
                printf("In this condition:\t\"%s\"\n\n" RESET, #check);                                             \
                ending;                                                                                             \
            }                                                                                                       \
        }                                                                                                           \
        while(0);
#else   
#define MYASSERT(check, error_code, ending)
#endif

#endif