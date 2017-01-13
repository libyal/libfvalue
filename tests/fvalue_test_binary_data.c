/*
 * Library binary_data type test program
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

#include "../libfvalue/libfvalue_binary_data.h"

#if defined( __GNUC__ )

/* Tests the libfvalue_binary_data_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_initialize(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_binary_data_t *binary_data = NULL;
	int result                           = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests      = 1;
	int number_of_memset_fail_tests      = 1;
	int test_number                      = 0;
#endif

	/* Test regular cases
	 */
	result = libfvalue_binary_data_initialize(
	          &binary_data,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "binary_data",
         binary_data );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfvalue_binary_data_free(
	          &binary_data,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NULL(
         "binary_data",
         binary_data );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfvalue_binary_data_initialize(
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

	binary_data = (libfvalue_binary_data_t *) 0x12345678UL;

	result = libfvalue_binary_data_initialize(
	          &binary_data,
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

	binary_data = NULL;

#if defined( HAVE_FVALUE_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfvalue_binary_data_initialize with malloc failing
		 */
		fvalue_test_malloc_attempts_before_fail = test_number;

		result = libfvalue_binary_data_initialize(
		          &binary_data,
		          &error );

		if( fvalue_test_malloc_attempts_before_fail != -1 )
		{
			fvalue_test_malloc_attempts_before_fail = -1;

			if( binary_data != NULL )
			{
				libfvalue_binary_data_free(
				 &binary_data,
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
			 "binary_data",
			 binary_data );

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
		/* Test libfvalue_binary_data_initialize with memset failing
		 */
		fvalue_test_memset_attempts_before_fail = test_number;

		result = libfvalue_binary_data_initialize(
		          &binary_data,
		          &error );

		if( fvalue_test_memset_attempts_before_fail != -1 )
		{
			fvalue_test_memset_attempts_before_fail = -1;

			if( binary_data != NULL )
			{
				libfvalue_binary_data_free(
				 &binary_data,
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
			 "binary_data",
			 binary_data );

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
	if( binary_data != NULL )
	{
		libfvalue_binary_data_free(
		 &binary_data,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_binary_data_free function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvalue_binary_data_free(
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

/* Tests the libfvalue_binary_data_clone function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_clone(
     void )
{
	libcerror_error_t *error                         = NULL;
	libfvalue_binary_data_t *destination_binary_data = NULL;
	libfvalue_binary_data_t *source_binary_data      = NULL;
	int result                                       = 0;

	/* Initialize test
	 */
	result = libfvalue_binary_data_initialize(
	          &source_binary_data,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "source_binary_data",
         source_binary_data );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test regular cases
	 */
	result = libfvalue_binary_data_clone(
	          &destination_binary_data,
	          source_binary_data,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NOT_NULL(
         "destination_binary_data",
         destination_binary_data );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfvalue_binary_data_free(
	          &destination_binary_data,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NULL(
         "destination_binary_data",
         destination_binary_data );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfvalue_binary_data_clone(
	          &destination_binary_data,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NULL(
         "destination_binary_data",
         destination_binary_data );

        FVALUE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfvalue_binary_data_clone(
	          NULL,
	          source_binary_data,
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
	result = libfvalue_binary_data_free(
	          &source_binary_data,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FVALUE_TEST_ASSERT_IS_NULL(
         "source_binary_data",
         source_binary_data );

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
	if( destination_binary_data != NULL )
	{
		libfvalue_binary_data_free(
		 &destination_binary_data,
		 NULL );
	}
	if( source_binary_data != NULL )
	{
		libfvalue_binary_data_free(
		 &source_binary_data,
		 NULL );
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
	 "libfvalue_binary_data_initialize",
	 fvalue_test_binary_data_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_free",
	 fvalue_test_binary_data_free );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_clone",
	 fvalue_test_binary_data_clone );

	/* TODO: add tests for libfvalue_binary_data_copy_from_byte_stream */

	/* TODO: add tests for libfvalue_binary_data_get_utf8_string_size */

	/* TODO: add tests for libfvalue_binary_data_copy_to_utf8_string_with_index */

	/* TODO: add tests for libfvalue_binary_data_get_utf16_string_size */

	/* TODO: add tests for libfvalue_binary_data_copy_to_utf16_string_with_index */

	/* TODO: add tests for libfvalue_binary_data_get_utf32_string_size */

	/* TODO: add tests for libfvalue_binary_data_copy_to_utf32_string_with_index */

#endif /* defined( __GNUC__ ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

