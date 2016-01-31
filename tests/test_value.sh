#!/bin/bash
# Library value testing script
#
# Version: 20160131

EXIT_SUCCESS=0;
EXIT_FAILURE=1;
EXIT_IGNORE=77;

TEST_PREFIX=`pwd`;
TEST_PREFIX=`dirname ${TEST_PREFIX}`;
TEST_PREFIX=`basename ${TEST_PREFIX} | sed 's/^lib//'`;

TEST_EXECUTABLE="${TEST_PREFIX}_test_value";

test_value()
{ 
	echo "Testing value";

	./${TEST_VALUE};

	RESULT=$?;

	echo "";

	return ${RESULT};
}

if ! test -z ${SKIP_LIBRARY_TESTS};
then
	exit ${EXIT_IGNORE};
fi

TEST_VALUE="./${TEST_EXECUTABLE}";

if ! test -x "${TEST_VALUE}";
then
	TEST_VALUE="${TEST_EXECUTABLE}.exe";
fi

if ! test -x "${TEST_VALUE}";
then
	echo "Missing executable: ${TEST_VALUE}";

	exit ${EXIT_FAILURE};
fi

if ! test_value;
then
	exit ${EXIT_FAILURE};
fi

exit ${EXIT_SUCCESS};

