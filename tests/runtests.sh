#!/bin/sh
# Script to run tests
#
# Version: 20260602

if test -f ${PWD}/libfvalue/.libs/libfvalue.1.dylib && test -f ./pyfvalue/.libs/pyfvalue.so
then
	install_name_tool -change /usr/local/lib/libfvalue.1.dylib ${PWD}/libfvalue/.libs/libfvalue.1.dylib ./pyfvalue/.libs/pyfvalue.so
fi

make check $@
RESULT=$?

if test ${RESULT} -ne 0 && test -f tests/test-suite.log
then
	cat tests/test-suite.log
fi
exit ${RESULT}

