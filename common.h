#pragma once

// https://clang.llvm.org/docs/LanguageExtensions.html#variadic-function-builtins
#define va_list  __builtin_va_list
#define va_start __builtin_va_start
#define va_end   __builtin_va_end
#define va_arg   __builtin_va_arg

typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t; // physical memory addresses
typedef uint32_t vaddr_t; // virtual memory addresses

#define PAGE_SIZE 4096
#define true  1
#define false 0
#define NULL  ((void *) 0)

// https://clang.llvm.org/docs/LanguageExtensions.html __builtin functions are defined here
#define align_up(value, align)   __builtin_align_up(value, align) // align must be a power of 2
#define is_aligned(value, align) __builtin_is_aligned(value, align)
#define offsetof(type, member)   __builtin_offsetof(type, member)

void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
char *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);
void printf(const char *fmt, ...);
