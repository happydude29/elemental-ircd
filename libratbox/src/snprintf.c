
/*
 * Modified and hacked into libratbox by Aaron Sethman <androsyn@ratbox.org>
 * The original headers are below..
 * Note that this implementation does not process floating point numbers so
 * you will likely need to fall back to using sprintf yourself to do those...
 */

/*
 *  linux/lib/vsprintf.c
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 */

/* vsprintf.c -- Lars Wirzenius & Linus Torvalds. */
/*
 * Wirzenius wrote this portably, Torvalds fucked it up :-)
 */

/*
 * Fri Jul 13 2001 Crutcher Dunnavant <crutcher+kernel@datastacks.com>
 * - changed to provide snprintf and vsnprintf functions
 * So Feb  1 16:51:32 CET 2004 Juergen Quade <quade@hsnr.de>
 * - scnprintf and vscnprintf
 */
#include <libratbox_config.h>
#include <ratbox_lib.h>

#include <string.h>

/*
 * vsprintf_append()
 * appends sprintf formatted string to the end of the buffer
 */

int
vsprintf_append(char *str, const char *format, va_list ap)
{
    size_t x = strlen(str);
    return (vsprintf(str + x, format, ap) + x);
}

/*
 * sprintf_append()
 * appends sprintf formatted string to the end of the buffer
 */
int
sprintf_append(char *str, const char *format, ...)
{
    int x;
    va_list ap;
    va_start(ap, format);
    x = vsprintf_append(str, format, ap);
    va_end(ap);
    return (x);
}

/*
 * vsnprintf_append()
 * appends sprintf formatted string to the end of the buffer but not
 * exceeding len
 */

int
vsnprintf_append(char *str, size_t len, const char *format, va_list ap)
{
    size_t x;
    if(len == 0)
        return 0;
    x = strlen(str);

    if(len < x) {
        str[len - 1] = '\0';
        return len - 1;
    }
    return (vsnprintf(str + x, len - x, format, ap) + x);
}

/*
 * snprintf_append()
 * appends snprintf formatted string to the end of the buffer but not
 * exceeding len
 */

int
nprintf_append(char *str, size_t len, const char *format, ...)
{
    int x;
    va_list ap;
    va_start(ap, format);
    x = vsnprintf_append(str, len, format, ap);
    va_end(ap);
    return (x);
}
