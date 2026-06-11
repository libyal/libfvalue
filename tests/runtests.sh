#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libfvalue/.libs/libfvalue.1.dylib && test -f ./pyfvalue/.libs/pyfvalue.so
then
	install_name_tool -change /usr/local/lib/libfvalue.1.dylib ${PWD}/libfvalue/.libs/libfvalue.1.dylib ./pyfvalue/.libs/pyfvalue.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

