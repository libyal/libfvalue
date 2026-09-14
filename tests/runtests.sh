#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libfvalue/.libs/libfvalue.1.dylib" ] && [ -f ./pyfvalue/.libs/pyfvalue.so ]
then
    install_name_tool -change /usr/local/lib/libfvalue.1.dylib "${PWD}/libfvalue/.libs/libfvalue.1.dylib" ./pyfvalue/.libs/pyfvalue.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

