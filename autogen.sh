#!/bin/sh
# Run this to generate all the initial makefiles, etc.

srcdir="`dirname $0`"
test -z "$srcdir" && srcdir=.

ORIGDIR="`pwd`"
PKG_NAME=gtans

REQUIRED_AUTOMAKE_VERSION=1.10
REQUIRED_INTLTOOL_VERSION=0.35.0

if [ ! -f "$srcdir/gtans.desktop" ]; then
 echo "$srcdir doesn't look like source directory for $PKG_NAME" >&2
 exit 1
fi

. gnome-autogen.sh
