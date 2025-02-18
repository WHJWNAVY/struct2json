/***
example
***/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#ifndef _MC_USER_DEF_
#define _MC_USER_DEF_

#define MAX_HOME_LEN 2
#define MAX_SCHOOL_LEN 4
#define MAX_ADDR_LEN 100
#define MAX_NAME_LEN 100

typedef struct addr_info_s
{
    uint32_t id;
    char name[MAX_NAME_LEN];
    char addr[MAX_ADDR_LEN];
} addr_info_t;

typedef struct student_info_s
{
    uint32_t id;
    uint32_t age;
    uint32_t height;
    uint32_t weight;
    char name[MAX_NAME_LEN];
    addr_info_t home[MAX_HOME_LEN];
    addr_info_t school[MAX_SCHOOL_LEN];
} student_info_t;

#endif /* _MC_USER_DEF_ */
