dnl Process this file with autoconf to produce a configure script

AC_INIT(gtans, 1.99.1,
        [http://gtans.sourceforge.net/])
AC_CONFIG_SRCDIR(src/main.c)
AM_INIT_AUTOMAKE([1.10 dist-bzip2])
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES(yes)])

AM_MAINTAINER_MODE

dnl AM_CONFIG_HEADER(config.h)

AC_PROG_CC
AC_ISC_POSIX
AC_HEADER_STDC
IT_PROG_INTLTOOL([0.40.5])

AC_CHECK_LIBM

GTK_REQUIRED=2.6.0
PKG_CHECK_MODULES(GTK, [gtk+-2.0 >= $GTK_REQUIRED])

AC_PROG_SED
AC_CHECK_PROGS(GTK_UPDATE_ICON_CACHE, gtk-update-icon-cache, :)
AC_CHECK_PROGS(RSVG_CONVERT, rsvg-convert, :)

GETTEXT_PACKAGE=gtans
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [gettext domain])
AM_GLIB_GNU_GETTEXT

AC_OUTPUT([
Makefile
data/Makefile
data/icons/Makefile
doc/Makefile
po/Makefile.in
src/Makefile
])
