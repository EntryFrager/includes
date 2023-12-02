/// @file error.h

#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Macro checking the truth of an expression.
 * @param[in] expr Expression
*/

#define DEBUG

#define RET_VOID -1000

#ifdef DEBUG
    #define CHECK_ERROR_PRINT(func) func; if (code_error != ERR_NO) my_strerr (code_error, stderr);
    #define CHECK_ERROR_RETURN(func, ret_value) func; if (*code_error != 0) {return ret_value;}
#else
    #define CHECK_ERROR_PRINT(func) func
    #define CHECK_ERROR(func) func
#endif

#define my_assert(expr, cd_err) if (!(expr)) {  \
        fprintf(stderr, "\x1b[31m%s %s:%d: My assertion failed: \"" #expr "\"\x1b[0m\n", __FILE__, __func__, __LINE__); \
        *code_error |= cd_err; \
    }

enum code_error {                               ///< Error codes.
    ERR_NO            = 0,
    ERR_PTR           = 1 << 0,
    ERR_NAN           = 1 << 1,
    ERR_MEM           = 1 << 2,
    ERR_FOPEN         = 1 << 3,
    ERR_FCLOSE        = 1 << 4,
    ERR_FREAD         = 1 << 5,
    ERR_TREE          = 1 << 6,

    TREE_ERR_PTR      = 1 << 7,
    TREE_INIT         = 1 << 8,
    TREE_ERR_SIZE     = 1 << 9,
    TREE_ERR_ROOT_PTR = 1 << 10,
    
    NODE_ERR          = 1 << 11,
    NODE_DATA_ERR_PTR = 1 << 12,

    ERR_CNT           = 13
};

void my_strerr (unsigned code_error, FILE *stream);    ///< Error print function.

#endif // ERROR_H
