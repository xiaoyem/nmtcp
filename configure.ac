#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([nmtcp], [0.0.1], [mengxiaoye@dce.com.cn])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/iph2net.c])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT

echo "
######################################################################
($PACKAGE_NAME) Version $PACKAGE_VERSION
Prefix....: $prefix
Compiler..: $CC $CFLAGS $CPPFLAGS
Linker....: $LD $LDFLAGS $LIBS
######################################################################
"

