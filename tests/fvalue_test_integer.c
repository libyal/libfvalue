/*
 * Library integer type test program
 *
 * Copyright (C) 2010-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fvalue_test_libcerror.h"
#include "fvalue_test_libfvalue.h"
#include "fvalue_test_macros.h"
#include "fvalue_test_memory.h"
#include "fvalue_test_unused.h"

#include "../libfvalue/libfvalue_integer.h"

#if defined( __GNUC__ )

/* Tests the libfvalue_integer_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libfvalue_integer_t *integer    = NULL;
	int result                      = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libfvalue_integer_initialize(
	          &integer,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "integer",
         integer );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfvalue_integer_free(
	          &integer,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NULL(
         "integer",
         integer );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfvalue_integer_initialize(
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	integer = (libfvalue_integer_t *) 0x12345678UL;

	result = libfvalue_integer_initialize(
	          &integer,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	integer = NULL;

#if defined( HAVE_FVALUE_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfvalue_integer_initialize with malloc failing
		 */
		fvalue_test_malloc_attempts_before_fail = test_number;

		result = libfvalue_integer_initialize(
		          &integer,
		          &error );

		if( fvalue_test_malloc_attempts_before_fail != -1 )
		{
			fvalue_test_malloc_attempts_before_fail = -1;

			if( integer != NULL )
			{
				libfvalue_integer_free(
				 &integer,
				 NULL );
			}
		}
		else
		{
			FVALUE_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FVALUE_TEST_ASSERT_IS_NULL(
			 "integer",
			 integer );

			FVALUE_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfvalue_integer_initialize with memset failing
		 */
		fvalue_test_memset_attempts_before_fail = test_number;

		result = libfvalue_integer_initialize(
		          &integer,
		          &error );

		if( fvalue_test_memset_attempts_before_fail != -1 )
		{
			fvalue_test_memset_attempts_before_fail = -1;

			if( integer != NULL )
			{
				libfvalue_integer_free(
				 &integer,
				 NULL );
			}
		}
		else
		{
			FVALUE_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FVALUE_TEST_ASSERT_IS_NULL(
			 "integer",
			 integer );

			FVALUE_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FVALUE_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( integer != NULL )
	{
		libfvalue_integer_free(
		 &integer,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_integer_free function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvalue_integer_free(
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfvalue_integer_clone function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_clone(
     void )
{
	libcerror_error_t *error                 = NULL;
	libfvalue_integer_t *destination_integer = NULL;
	libfvalue_integer_t *source_integer      = NULL;
	int result                               = 0;

	/* Initialize test
	 */
	result = libfvalue_integer_initialize(
	          &source_integer,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "source_integer",
         source_integer );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test regular cases
	 */
	result = libfvalue_integer_clone(
	          &destination_integer,
	          source_integer,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "destination_integer",
         destination_integer );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfvalue_integer_free(
	          &destination_integer,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NULL(
         "destination_integer",
         destination_integer );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfvalue_integer_clone(
	          &destination_integer,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NULL(
         "destination_integer",
         destination_integer );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfvalue_integer_clone(
	          NULL,
	          source_integer,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_integer_free(
	          &source_integer,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NULL(
         "source_integer",
         source_integer );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( destination_integer != NULL )
	{
		libfvalue_integer_free(
		 &destination_integer,
		 NULL );
	}
	if( source_integer != NULL )
	{
		libfvalue_integer_free(
		 &source_integer,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_utf8_string_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf8_string_copy_to_integer(
     void )
{
	const uint8_t valid_source_string[]   = "4890";
	const uint8_t invalid_source_string[] = "/:";
	uint64_t integer_value                = 0;
	libcerror_error_t *error              = NULL;
	int result                            = 0;

	/* Test a valid conversion
	 */
	result = libfvalue_utf8_string_copy_to_integer(
	          valid_source_string,
	          sizeof( valid_source_string ),
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 4890ul );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test an invalid conversion
	 */
	result = libfvalue_utf8_string_copy_to_integer(
	          invalid_source_string,
	          sizeof( valid_source_string ),
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfvalue_utf16_string_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf16_string_copy_to_integer(
     void )
{
	const uint16_t valid_source_string[]   = {'4', '8', '9', '0', '\0'};
	const uint16_t invalid_source_string[] = {'/', ':', '\0'};
	uint64_t integer_value                 = 0;
	libcerror_error_t *error               = NULL;
	int result                             = 0;

	/* Test a valid conversion
	 */
	result = libfvalue_utf16_string_copy_to_integer(
	          valid_source_string,
	          sizeof( valid_source_string ),
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 4890ul );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test an invalid conversion
	 */
	result = libfvalue_utf16_string_copy_to_integer(
	          invalid_source_string,
	          sizeof( valid_source_string ),
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfvalue_utf32_string_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf32_string_copy_to_integer(
     void )
{
	const uint32_t valid_source_string[]   = {'4', '8', '9', '0', '\0'};
	const uint32_t invalid_source_string[] = {'/', ':', '\0'};
	uint64_t integer_value                 = 0;
	libcerror_error_t *error               = NULL;
	int result                             = 0;

	/* Test a valid conversion
	 */
	result = libfvalue_utf32_string_copy_to_integer(
	          valid_source_string,
	          sizeof( valid_source_string ),
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 4890ul );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test an invalid conversion
	 */
	result = libfvalue_utf32_string_copy_to_integer(
	          invalid_source_string,
	          sizeof( valid_source_string ),
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FVALUE_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FVALUE_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FVALUE_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FVALUE_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FVALUE_TEST_UNREFERENCED_PARAMETER( argc )
	FVALUE_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ )

	FVALUE_TEST_RUN(
	 "libfvalue_integer_initialize",
	 fvalue_test_integer_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_free",
	 fvalue_test_integer_free );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_clone",
	 fvalue_test_integer_clone );

	/* TODO: add tests for libfvalue_integer_copy_from_byte_stream */

	/* TODO: add tests for libfvalue_integer_copy_from_integer */

	/* TODO: add tests for libfvalue_integer_copy_to_integer */

	/* TODO: add tests for libfvalue_integer_get_string_size */

	/* TODO: add tests for libfvalue_integer_copy_from_utf8_string_with_index */

	/* TODO: add tests for libfvalue_integer_copy_to_utf8_string_with_index */

	/* TODO: add tests for libfvalue_integer_copy_from_utf16_string_with_index */

	/* TODO: add tests for libfvalue_integer_copy_to_utf16_string_with_index */

	/* TODO: add tests for libfvalue_integer_copy_from_utf32_string_with_index */

	/* TODO: add tests for libfvalue_integer_copy_to_utf32_string_with_index */

	FVALUE_TEST_RUN(
	 "libfvalue_utf8_string_copy_to_integer",
	 fvalue_test_utf8_string_copy_to_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf16_string_copy_to_integer",
	 fvalue_test_utf16_string_copy_to_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf32_string_copy_to_integer",
	 fvalue_test_utf32_string_copy_to_integer );

#endif /* defined( __GNUC__ ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

