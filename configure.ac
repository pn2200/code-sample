AC_INIT([code-sample], [0.1])
AC_LANG([C++])

# Put compiled object files into the same sub-directory as their sources
# and quiet make
AM_INIT_AUTOMAKE([1.11 foreign subdir-objects])
AM_SILENT_RULES([yes])

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

AM_PROG_AR
LT_INIT
AC_CONFIG_MACRO_DIRS([m4])

# Require C++11
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])

# Check for pthreads
ACX_PTHREAD
LIBS="$PTHREAD_LIBS $LIBS"
CFLAGS="$PTHREAD_CFLAGS $CFLAGS"
CC="$PTHREAD_CC"
# Add -pthread to linker flags also
LDFLAGS="$PTHREAD_CFLAGS $LDFLAGS"

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

