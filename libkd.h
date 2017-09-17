/**
    Created by: Krzysztof Dobrzynski - k.dobrzynski94@gmail.com
                https://github.com/Sejoslaw

 ============================================================================
   You MUST

      #define LIBKD_IMPLEMENTED

   in EXACTLY _one_ C or C++ file that includes this header, BEFORE the
   include, like this:

      #define LIBKD_IMPLEMENTED
      #include "libkd.h"

   All other files should just #include "libkd.h" without the #define.
 ============================================================================
*/
#ifndef LIBKD_IMPLEMENTED

/// Include Standard C Libraries
/// More informations can be found here:   https://www.tutorialspoint.com/c_standard_library/index.htm
#include <assert.h>     /// Debug and tests
#include <ctype.h>      /// Testing and mapping characters
#include <errno.h>      /// Error indication
#include <float.h>      /// Float operations
#include <limits.h>     /// Contains limits valious
#include <locale.h>     /// Location specific setting
#include <math.h>       /// Mathematical functions
#include <setjmp.h>     /// For bypassing normal function calls
#include <signal.h>     /// Defines macros to handle signals reported during a program's execution
#include <stdarg.h>     /// For getting the number of arguments in not known
#include <stddef.h>     /// Contains various variable types and macros
#include <stdio.h>      /// I/O operations (FILE, etc.)
#include <stdlib.h>     /// General functions (stdlib could have min/max)
#include <string.h>     /// For manipulating arrays of characters (memcpy / memset / strcpy / strlen /strncmp)
#include <time.h>       /// For manipulating date and time

#ifndef LIBKD_BOOL /// Boolean definition
    #define LIBKD_BOOL
    typedef int boolean;
    #define True 1
    #define False 0
#endif /// LIBKD_BOOL

#define libkd_min(a,b) ((a) < (b) ? (a) : (b)) /// Min value
#define libkd_max(a,b) ((a) > (b) ? (a) : (b)) /// Max value

#ifndef M_PI /// Pi definition
     #define M_PI  3.14159265358979323846f
#endif /// M_PI

#ifndef deg2rad /// Degree to Radian
   #define deg2rad(a)  ((a)*(M_PI/180))
#endif /// deg2rad

#ifndef rad2deg /// Radian to Degree
   #define rad2deg(a)  ((a)*(180/M_PI))
#endif /// rad2deg

#ifdef __cplusplus /// If C++ is defined
   #define LIBKD_EXTERN   extern "C"
#else
   #define LIBKD_EXTERN   extern
#endif /// __cplusplus

/// ======================================== String Operations ========================================

/// Appends the string2 to the end of string1
LIBKD_EXTERN char *libkd_string_append(char *string1, char *string2)
{
    /// allocate memory for new string
    char *return_string = malloc(strlen(string1) + strlen(string2) + 1);
    if (return_string != NULL) {
        return_string[0] = '\0'; /// ensures the memory is an empty string
        strcat(return_string, string1);
        strcat(return_string, string2);
        return return_string; /// returns constructed string
    } else {
        printf("LIBKD: Memory allocation failed when allocating memory for new string. See libkd_string_append");
        return "NULL";
    }
}

#endif /// LIBKD_IMPLEMENTED

/***
	License page: http://www.zlib.net/zlib_license.html


	version 1.2.11, January 15th, 2017

	  Copyright (C) 2010-2017 Krzysztof Dobrzynski

	  This software is provided 'as-is', without any express or implied
	  warranty.  In no event will the authors be held liable for any damages
	  arising from the use of this software.

	  Permission is granted to anyone to use this software for any purpose,
	  including commercial applications, and to alter it and redistribute it
	  freely, subject to the following restrictions:

	  1. The origin of this software must not be misrepresented; you must not
		 claim that you wrote the original software. If you use this software
		 in a product, an acknowledgment in the product documentation would be
		 appreciated but is not required.
	  2. Altered source versions must be plainly marked as such, and must not be
		 misrepresented as being the original software.
	  3. This notice may not be removed or altered from any source distribution.

	  Krzysztof Dobrzynski
	  k.dobrzynski94@gmail.com
*/
