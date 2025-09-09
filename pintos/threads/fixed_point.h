#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <debug.h>
#include <list.h>
#include <stdint.h>
#include "threads/interrupt.h"

#define FP_f (1 << 14) // f = 2^14

// Declaration
static inline int64_t int2fp(int n);
static inline int64_t fp2int_zero(int x);
static inline int64_t fp2int_near(int x);

static inline int64_t add(int x, int y);
static inline int64_t sub(int x, int y);
static inline int64_t add_fp(int x, int n);
static inline int64_t sub_fp(int x, int n);
static inline int64_t mul(int x, int y);
static inline int64_t mul_fp(int x, int n);
static inline int64_t div(int x, int y);
static inline int64_t div_fp(int x, int n);

// Implementation
static inline int64_t int2fp(int n)
{
    return n * FP_f;
}

static inline int64_t fp2int_zero(int x)
{
    return x / FP_f;
}

static inline int64_t fp2int_near(int x)
{
    return (x >= 0 ? (x + FP_f / 2) / FP_f : (x - FP_f / 2) / FP_f);
}

static inline int64_t add(int x, int y)
{
    return x + y;
}

static inline int64_t sub(int x, int y)
{
    return x - y;
}

static inline int64_t add_fp(int x, int n)
{
    return x + n*FP_f;
}

static inline int64_t sub_fp(int x, int n)
{
    return x - n*FP_f;
}

static inline int64_t mul(int x, int y)
{
    return ((int64_t)x) * y / FP_f;
}

static inline int64_t mul_fp(int x, int n)
{
    return x * n;
}

static inline int64_t div(int x, int y)
{
    return ((int64_t)x) * FP_f / y;
}

static inline int64_t div_fp(int x, int n)
{
    return x / n;
}


#endif /* FIXED_POINT_H */