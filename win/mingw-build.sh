#!/bin/bash

#
# References:
#
#	* https://www.msys2.org/docs/ci/
#

echo "Running ${0}"

LOGFILE=build.log
rm -f ${LOGFILE}

die ( ) {
	[ -s $LOGFILE ] && tail $LOGFILE
	[ "$1" ] && echo "$*"
	exit -1
}

cd $(dirname $(dirname $(readlink -f ${0})))

#
# Build
#
echo "Building package..."
dos2unix PKGBUILD.mingw  || die "dos2unix failure"
makepkg BUILDDIR=/tmp/pkg -f -p PKGBUILD.mingw || die "makepkg failure"

echo "Build complete"

