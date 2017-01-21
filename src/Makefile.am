## Process this file with automake to produce Makefile.in

AM_CFLAGS = \
	-Wall	\
	-DG_LOG_DOMAIN=\"$(PACKAGE)\"	\
	-DPKGDATADIR=\"$(pkgdatadir)\"	\
	-DSYSCONFDIR=\"$(sysconfdir)\"	\
	$(GTK_CFLAGS)

if MAINTAINER_MODE
DEPRECATED_CFLAGS = \
	-DG_DISABLE_DEPRECATED			\
	-DGDK_PIXBUF_DISABLE_DEPRECATED	\
	-DGDK_DISABLE_DEPRECATED		\
	-DGTK_DISABLE_DEPRECATED
endif

bin_PROGRAMS = gtans

gtans_SOURCES = \
	callbacks.c	\
	callbacks.h	\
	interface.c	\
	interface.h	\
	main.c		\
	main.h		\
	support.c	\
	support.h

gtans_LDADD = $(GTK_LIBS) $(LIBINTL) $(LIBM)
