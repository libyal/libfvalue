/*
 * Library floating_point type test program
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

#include "../libfvalue/libfvalue_floating_point.h"

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

/* Tests the libfvalue_floating_point_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_initialize(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	int result                                 = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests            = 1;
	int number_of_memset_fail_tests            = 1;
	int test_number                            = 0;
#endif

	/* Test regular cases
	 */
	result = libfvalue_floating_point_initialize(
	          &floating_point,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "floating_point",
	 floating_point );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_floating_point_free(
	          &floating_point,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "floating_point",
	 floating_point );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_floating_point_initialize(
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

	floating_point = (libfvalue_floating_point_t *) 0x12345678UL;

	result = libfvalue_floating_point_initialize(
	          &floating_point,
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

	floating_point = NULL;

#if defined( HAVE_FVALUE_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfvalue_floating_point_initialize with malloc failing
		 */
		fvalue_test_malloc_attempts_before_fail = test_number;

		result = libfvalue_floating_point_initialize(
		          &floating_point,
		          &error );

		if( fvalue_test_malloc_attempts_before_fail != -1 )
		{
			fvalue_test_malloc_attempts_before_fail = -1;

			if( floating_point != NULL )
			{
				libfvalue_floating_point_free(
				 &floating_point,
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
			 "floating_point",
			 floating_point );

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
		/* Test libfvalue_floating_point_initialize with memset failing
		 */
		fvalue_test_memset_attempts_before_fail = test_number;

		result = libfvalue_floating_point_initialize(
		          &floating_point,
		          &error );

		if( fvalue_test_memset_attempts_before_fail != -1 )
		{
			fvalue_test_memset_attempts_before_fail = -1;

			if( floating_point != NULL )
			{
				libfvalue_floating_point_free(
				 &floating_point,
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
			 "floating_point",
			 floating_point );

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
	if( floating_point != NULL )
	{
		libfvalue_floating_point_free(
		 &floating_point,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_floating_point_free function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvalue_floating_point_free(
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

/* Tests the libfvalue_floating_point_clone function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_clone(
     void )
{
	libcerror_error_t *error                               = NULL;
	libfvalue_floating_point_t *destination_floating_point = NULL;
	libfvalue_floating_point_t *source_floating_point      = NULL;
	int result                                             = 0;

	/* Initialize test
	 */
	result = libfvalue_floating_point_initialize(
	          &source_floating_point,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "source_floating_point",
	 source_floating_point );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_floating_point_clone(
	          &destination_floating_point,
	          source_floating_point,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "destination_floating_point",
	 destination_floating_point );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_floating_point_free(
	          &destination_floating_point,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_floating_point",
	 destination_floating_point );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_floating_point_clone(
	          &destination_floating_point,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_floating_point",
	 destination_floating_point );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_floating_point_clone(
	          NULL,
	          source_floating_point,
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
	result = libfvalue_floating_point_free(
	          &source_floating_point,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "source_floating_point",
	 source_floating_point );

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
	if( destination_floating_point != NULL )
	{
		libfvalue_floating_point_free(
		 &destination_floating_point,
		 NULL );
	}
	if( source_floating_point != NULL )
	{
		libfvalue_floating_point_free(
		 &source_floating_point,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

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

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_initialize",
	 fvalue_test_floating_point_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_free",
	 fvalue_test_floating_point_free );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_clone",
	 fvalue_test_floating_point_clone );

	/* TODO: add tests for libfvalue_floating_point_copy_from_byte_stream */

	/* TODO: add tests for libfvalue_floating_point_copy_from_integer */

	/* TODO: add tests for libfvalue_floating_point_copy_to_integer */

	/* TODO: add tests for libfvalue_floating_point_copy_from_floating_point */

	/* TODO: add tests for libfvalue_floating_point_copy_to_floating_point */

	/* TODO: add tests for libfvalue_floating_point_get_string_size */

	/* TODO: add tests for libfvalue_floating_point_copy_from_utf8_string_with_index */

	/* TODO: add tests for libfvalue_floating_point_copy_to_utf8_string_with_index */

	/* TODO: add tests for libfvalue_floating_point_copy_from_utf16_string_with_index */

	/* TODO: add tests for libfvalue_floating_point_copy_to_utf16_string_with_index */

	/* TODO: add tests for libfvalue_floating_point_copy_from_utf32_string_with_index */

	/* TODO: add tests for libfvalue_floating_point_copy_to_utf32_string_with_index */

#endif /* #if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

