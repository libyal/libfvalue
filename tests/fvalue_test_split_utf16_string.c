/*
 * Library split_utf16_string type test program
 *
 * Copyright (C) 2010-2020, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
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

#include "../libfvalue/libfvalue_split_utf16_string.h"

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

/* Tests the libfvalue_split_utf16_string_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_split_utf16_string_initialize(
     void )
{
	uint16_t utf16_string[ 5 ] = {
		't', 'e', 's', 't', 0 };

	libcerror_error_t *error                     = NULL;
	libfvalue_split_utf16_string_t *split_string = NULL;
	int result                                   = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests              = 4;
	int number_of_memset_fail_tests              = 3;
	int test_number                              = 0;

#if defined( OPTIMIZATION_DISABLED )
	int number_of_memcpy_fail_tests              = 1;
#endif
#endif

	/* Test regular cases
	 */
	result = libfvalue_split_utf16_string_initialize(
	          &split_string,
	          utf16_string,
	          5,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_split_utf16_string_free(
	          &split_string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_split_utf16_string_initialize(
	          NULL,
	          utf16_string,
	          5,
	          1,
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

	split_string = (libfvalue_split_utf16_string_t *) 0x12345678UL;

	result = libfvalue_split_utf16_string_initialize(
	          &split_string,
	          utf16_string,
	          5,
	          1,
	          &error );

	split_string = NULL;

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_split_utf16_string_initialize(
	          &split_string,
	          utf16_string,
	          5,
	          -1,
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

#if defined( HAVE_FVALUE_TEST_MEMORY )

	/* 1 fail in memory_allocate_structure of internal_split_string
	 * 2 fail in memory_allocate of internal_split_string->string
	 * 3 fail in memory_allocate of internal_split_string->segments
	 * 4 fail in memory_allocate of internal_split_string->segment_sizes
	 */
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfvalue_split_utf16_string_initialize with malloc failing
		 */
		fvalue_test_malloc_attempts_before_fail = test_number;

		result = libfvalue_split_utf16_string_initialize(
		          &split_string,
		          utf16_string,
		          5,
		          1,
		          &error );

		if( fvalue_test_malloc_attempts_before_fail != -1 )
		{
			fvalue_test_malloc_attempts_before_fail = -1;

			if( split_string != NULL )
			{
				libfvalue_split_utf16_string_free(
				 &split_string,
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
			 "split_string",
			 split_string );

			FVALUE_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	/* 1 fail in memory_set of internal_split_string
	 * 2 fail in memory_set of internal_split_string->segments
	 * 3 fail in memory_set of internal_split_string->segment_sizes
	 */
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfvalue_split_utf16_string_initialize with memset failing
		 */
		fvalue_test_memset_attempts_before_fail = test_number;

		result = libfvalue_split_utf16_string_initialize(
		          &split_string,
		          utf16_string,
		          5,
		          1,
		          &error );

		if( fvalue_test_memset_attempts_before_fail != -1 )
		{
			fvalue_test_memset_attempts_before_fail = -1;

			if( split_string != NULL )
			{
				libfvalue_split_utf16_string_free(
				 &split_string,
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
			 "split_string",
			 split_string );

			FVALUE_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#if defined( OPTIMIZATION_DISABLED )

	/* 1 memcpy of utf16_string to internal_split_string->string
	 */
	for( test_number = 0;
	     test_number < number_of_memcpy_fail_tests;
	     test_number++ )
	{
		/* Test libfvalue_context_initialize with memcpy failing
		 */
		fvalue_test_memcpy_attempts_before_fail = test_number;

		result = libfvalue_split_utf16_string_initialize(
		          &split_string,
		          utf16_string,
		          5,
		          1,
		          &error );

		if( fvalue_test_memcpy_attempts_before_fail != -1 )
		{
			fvalue_test_memcpy_attempts_before_fail = -1;

			if( split_string != NULL )
			{
				libfvalue_split_utf16_string_free(
				 &split_string,
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
			 "split_string",
			 split_string );

			FVALUE_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( OPTIMIZATION_DISABLED ) */
#endif /* defined( HAVE_FVALUE_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( split_string != NULL )
	{
		libfvalue_split_utf16_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}


#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

/* Tests the libfvalue_split_utf16_string_free function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_split_utf16_string_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvalue_split_utf16_string_free(
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

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

/* Tests the libfvalue_split_utf16_string_get_string function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_split_utf16_string_get_string(
     void )
{
	uint16_t utf16_string[ 5 ] = {
		't', 'e', 's', 't', 0 };

	libcerror_error_t *error                     = NULL;
	libfvalue_split_utf16_string_t *split_string = NULL;
	uint16_t *string                             = NULL;
	size_t string_size                           = 0;
	int result                                   = 0;

	/* Initialize test
	 */
	result = libfvalue_split_utf16_string_initialize(
	          &split_string,
	          utf16_string,
	          5,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string      = NULL;
	string_size = 0;

	result = libfvalue_split_utf16_string_get_string(
	          split_string,
	          &string,
	          &string_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string      = NULL;
	string_size = 0;

	result = libfvalue_split_utf16_string_get_string(
	          NULL,
	          &string,
	          &string_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_split_utf16_string_get_string(
	          split_string,
	          NULL,
	          &string_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_split_utf16_string_get_string(
	          split_string,
	          &string,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_split_utf16_string_free(
	          &split_string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

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
	if( split_string != NULL )
	{
		libfvalue_split_utf16_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_split_utf16_string_get_number_of_segments function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_split_utf16_string_get_number_of_segments(
     void )
{
	uint16_t utf16_string[ 5 ] = {
		't', 'e', 's', 't', 0 };

	libcerror_error_t *error                     = NULL;
	libfvalue_split_utf16_string_t *split_string = NULL;
	int number_of_segments                       = 0;
	int result                                   = 0;

	/* Initialize test
	 */
	result = libfvalue_split_utf16_string_initialize(
	          &split_string,
	          utf16_string,
	          5,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	number_of_segments = 0;

	result = libfvalue_split_utf16_string_get_number_of_segments(
	          split_string,
	          &number_of_segments,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "number_of_segments",
	 number_of_segments,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	number_of_segments = 0;

	result = libfvalue_split_utf16_string_get_number_of_segments(
	          NULL,
	          &number_of_segments,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "number_of_segments",
	 number_of_segments,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_split_utf16_string_get_number_of_segments(
	          split_string,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "number_of_segments",
	 number_of_segments,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_split_utf16_string_free(
	          &split_string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

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
	if( split_string != NULL )
	{
		libfvalue_split_utf16_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_split_utf16_string_get_segment_by_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_split_utf16_string_get_segment_by_index(
     void )
{
	uint16_t utf16_string[ 5 ] = {
		't', 'e', 's', 't', 0 };

	libcerror_error_t *error                     = NULL;
	libfvalue_split_utf16_string_t *split_string = NULL;
	uint16_t *string_segment                     = NULL;
	size_t string_segment_size                   = 0;
	int result                                   = 0;

	/* Initialize test
	 */
	result = libfvalue_split_utf16_string_initialize(
	          &split_string,
	          utf16_string,
	          5,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_split_utf16_string_set_segment_by_index(
	          split_string,
	          0,
	          ( (libfvalue_internal_split_utf16_string_t *) split_string )->string,
	          5,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_segment      = NULL;
	string_segment_size = 0;

	result = libfvalue_split_utf16_string_get_segment_by_index(
	          split_string,
	          0,
	          &string_segment,
	          &string_segment_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string_segment",
	 string_segment );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_segment_size",
	 string_segment_size,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_segment      = NULL;
	string_segment_size = 0;

	result = libfvalue_split_utf16_string_get_segment_by_index(
	          NULL,
	          0,
	          &string_segment,
	          &string_segment_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string_segment",
	 string_segment );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_segment_size",
	 string_segment_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_split_utf16_string_get_segment_by_index(
	          split_string,
	          -1,
	          &string_segment,
	          &string_segment_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string_segment",
	 string_segment );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_segment_size",
	 string_segment_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_split_utf16_string_get_segment_by_index(
	          split_string,
	          0,
	          NULL,
	          &string_segment_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string_segment",
	 string_segment );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_segment_size",
	 string_segment_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_split_utf16_string_get_segment_by_index(
	          split_string,
	          0,
	          &string_segment,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string_segment",
	 string_segment );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_segment_size",
	 string_segment_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_split_utf16_string_free(
	          &split_string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

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
	if( split_string != NULL )
	{
		libfvalue_split_utf16_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_split_utf16_string_set_segment_by_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_split_utf16_string_set_segment_by_index(
     void )
{
	uint16_t utf16_string[ 5 ] = {
		't', 'e', 's', 't', 0 };

	libcerror_error_t *error                     = NULL;
	libfvalue_split_utf16_string_t *split_string = NULL;
	int result                                   = 0;

	/* Initialize test
	 */
	result = libfvalue_split_utf16_string_initialize(
	          &split_string,
	          utf16_string,
	          5,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "split_string",
	 split_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_split_utf16_string_set_segment_by_index(
	          split_string,
	          0,
	          ( (libfvalue_internal_split_utf16_string_t *) split_string )->string,
	          5,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_split_utf16_string_set_segment_by_index(
	          split_string,
	          0,
	          NULL,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_split_utf16_string_set_segment_by_index(
	          NULL,
	          0,
	          ( (libfvalue_internal_split_utf16_string_t *) split_string )->string,
	          5,
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

	result = libfvalue_split_utf16_string_set_segment_by_index(
	          split_string,
	          -1,
	          ( (libfvalue_internal_split_utf16_string_t *) split_string )->string,
	          5,
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

	result = libfvalue_split_utf16_string_set_segment_by_index(
	          split_string,
	          0,
	          NULL,
	          5,
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

	result = libfvalue_split_utf16_string_set_segment_by_index(
	          split_string,
	          0,
	          (uint16_t *) ( ( (libfvalue_internal_split_utf16_string_t *) split_string )->string - 10 ),
	          5,
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

	result = libfvalue_split_utf16_string_set_segment_by_index(
	          split_string,
	          0,
	          (uint16_t *) ( ( (libfvalue_internal_split_utf16_string_t *) split_string )->string + 10 ),
	          5,
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

	result = libfvalue_split_utf16_string_set_segment_by_index(
	          split_string,
	          0,
	          (uint16_t *) ( ( (libfvalue_internal_split_utf16_string_t *) split_string )->string + 3 ),
	          5,
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
	result = libfvalue_split_utf16_string_free(
	          &split_string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "split_string",
	 split_string );

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
	if( split_string != NULL )
	{
		libfvalue_split_utf16_string_free(
		 &split_string,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

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
	 "libfvalue_split_utf16_string_initialize",
	 fvalue_test_split_utf16_string_initialize );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	FVALUE_TEST_RUN(
	 "libfvalue_split_utf16_string_free",
	 fvalue_test_split_utf16_string_free );

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

	FVALUE_TEST_RUN(
	 "libfvalue_split_utf16_string_get_string",
	 fvalue_test_split_utf16_string_get_string );

	FVALUE_TEST_RUN(
	 "libfvalue_split_utf16_string_get_number_of_segments",
	 fvalue_test_split_utf16_string_get_number_of_segments );

	FVALUE_TEST_RUN(
	 "libfvalue_split_utf16_string_get_segment_by_index",
	 fvalue_test_split_utf16_string_get_segment_by_index );

	FVALUE_TEST_RUN(
	 "libfvalue_split_utf16_string_set_segment_by_index",
	 fvalue_test_split_utf16_string_set_segment_by_index );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

