/*
 * Library binary_data type test program
 *
 * Copyright (C) 2010-2019, Joachim Metz <joachim.metz@gmail.com>
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
#include <memory.h>
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

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

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

	binary_data = NULL;

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

	destination_binary_data = (libfvalue_binary_data_t *) 0x12345678UL;

	result = libfvalue_binary_data_clone(
	          &destination_binary_data,
	          source_binary_data,
	          &error );

	destination_binary_data = NULL;

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

	/* Test libfvalue_binary_data_clone with malloc failing
	 */
	fvalue_test_malloc_attempts_before_fail = 0;

	result = libfvalue_binary_data_clone(
	          &destination_binary_data,
	          source_binary_data,
	          &error );

	if( fvalue_test_malloc_attempts_before_fail != -1 )
	{
		fvalue_test_malloc_attempts_before_fail = -1;

		if( destination_binary_data != NULL )
		{
			libfvalue_binary_data_free(
			 &destination_binary_data,
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
		 "destination_binary_data",
		 destination_binary_data );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#if defined( OPTIMIZATION_DISABLED )

	/* Test libfvalue_binary_data_clone with memcpy failing
	 */
	fvalue_test_memcpy_attempts_before_fail = 0;

	result = libfvalue_binary_data_clone(
	          &destination_binary_data,
	          source_binary_data,
	          &error );

	if( fvalue_test_memcpy_attempts_before_fail != -1 )
	{
		fvalue_test_memcpy_attempts_before_fail = -1;

		if( destination_binary_data != NULL )
		{
			libfvalue_binary_data_free(
			 &destination_binary_data,
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
		 "destination_binary_data",
		 destination_binary_data );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( OPTIMIZATION_DISABLED ) */
#endif /* defined( HAVE_FVALUE_TEST_MEMORY ) */

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

/* Tests the libfvalue_binary_data_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_binary_data_t *binary_data = NULL;
	int result                           = 0;

	/* Initialize test
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

	/* Test regular cases
	 */
	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          (uint8_t *) "test",
	          4,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          NULL,
	          0,
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
	result = libfvalue_binary_data_copy_from_byte_stream(
	          NULL,
	          (uint8_t *) "test",
	          4,
	          0,
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

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          NULL,
	          4,
	          0,
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

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          (uint8_t *) "test",
	          (size_t) SSIZE_MAX + 1,
	          0,
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

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          (uint8_t *) "test",
	          4,
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

	/* Clean up
	 */
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

/* Tests the libfvalue_binary_data_get_utf8_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_get_utf8_string_size(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_binary_data_t *binary_data = NULL;
	size_t utf8_string_size              = 0;
	int result                           = 0;

	/* Initialize test
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

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          (uint8_t *) "test",
	          4,
	          0,
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
	result = libfvalue_binary_data_get_utf8_string_size(
	          binary_data,
	          &utf8_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_size",
	 utf8_string_size,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_binary_data_get_utf8_string_size(
	          binary_data,
	          &utf8_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_size",
	 utf8_string_size,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_binary_data_get_utf8_string_size(
	          binary_data,
	          &utf8_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE64,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_size",
	 utf8_string_size,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_binary_data_get_utf8_string_size(
	          NULL,
	          &utf8_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
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

	result = libfvalue_binary_data_get_utf8_string_size(
	          binary_data,
	          NULL,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
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

	result = libfvalue_binary_data_get_utf8_string_size(
	          binary_data,
	          &utf8_string_size,
	          0xffffff00UL,
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

	result = libfvalue_binary_data_get_utf8_string_size(
	          binary_data,
	          &utf8_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | 0x000000ffUL,
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

	/* TODO test with libuna_base16_stream_size_from_byte_stream failing */

	/* TODO test with libuna_base32_stream_size_from_byte_stream failing */

	/* TODO test with libuna_base64_stream_size_from_byte_stream failing */

	/* Clean up
	 */
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

/* Tests the libfvalue_binary_data_copy_to_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_copy_to_utf8_string_with_index(
     void )
{
	uint8_t expected_utf8_string_base16[ 9 ] = {
		'7', '4', '6', '5', '7', '3', '7', '4', 0 };
	uint8_t expected_utf8_string_base32[ 9 ] = {
		'O', 'R', 'S', 'X', 'G', '5', 'A', '=', 0 };
	uint8_t expected_utf8_string_base64[ 9 ] = {
		'd', 'G', 'V', 'z', 'd', 'A', '=', '=', 0 };
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_binary_data_t *binary_data = NULL;
	size_t utf8_string_index             = 0;
	int result                           = 0;

	/* Initialize test
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

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          (uint8_t *) "test",
	          4,
	          0,
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
	utf8_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          binary_data,
	          utf8_string,
	          32,
	          &utf8_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          utf8_string,
	          expected_utf8_string_base16,
	          sizeof( uint8_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          binary_data,
	          utf8_string,
	          32,
	          &utf8_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          utf8_string,
	          expected_utf8_string_base32,
	          sizeof( uint8_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          binary_data,
	          utf8_string,
	          32,
	          &utf8_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE64,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          utf8_string,
	          expected_utf8_string_base64,
	          sizeof( uint8_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf8_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          NULL,
	          utf8_string,
	          32,
	          &utf8_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          binary_data,
	          NULL,
	          32,
	          &utf8_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
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

	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          binary_data,
	          utf8_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf8_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          binary_data,
	          utf8_string,
	          32,
	          NULL,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	utf8_string_index = 32;

	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          binary_data,
	          utf8_string,
	          32,
	          &utf8_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 32 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	utf8_string_index = 0;

	/* Unsupported flags
	 */
	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          binary_data,
	          utf8_string,
	          32,
	          &utf8_string_index,
	          0xffffff00UL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Unsupported encoding
	 */
	result = libfvalue_binary_data_copy_to_utf8_string_with_index(
	          binary_data,
	          utf8_string,
	          32,
	          &utf8_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | 0x000000ffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* TODO test with libuna_base16_stream_with_index_copy_from_byte_stream failing */

	/* TODO test with libuna_base32_stream_with_index_copy_from_byte_stream failing */

	/* TODO test with libuna_base64_stream_with_index_copy_from_byte_stream failing */

	/* Clean up
	 */
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

/* Tests the libfvalue_binary_data_get_utf16_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_get_utf16_string_size(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_binary_data_t *binary_data = NULL;
	size_t utf16_string_size             = 0;
	int result                           = 0;

	/* Initialize test
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

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          (uint8_t *) "test",
	          4,
	          0,
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
	result = libfvalue_binary_data_get_utf16_string_size(
	          binary_data,
	          &utf16_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_size",
	 utf16_string_size,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_binary_data_get_utf16_string_size(
	          binary_data,
	          &utf16_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_size",
	 utf16_string_size,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_binary_data_get_utf16_string_size(
	          binary_data,
	          &utf16_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE64,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_size",
	 utf16_string_size,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* TODO test with big endian byte order */

	/* Test error cases
	 */
	result = libfvalue_binary_data_get_utf16_string_size(
	          NULL,
	          &utf16_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
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

	result = libfvalue_binary_data_get_utf16_string_size(
	          binary_data,
	          NULL,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
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

	result = libfvalue_binary_data_get_utf16_string_size(
	          binary_data,
	          &utf16_string_size,
	          0xffffff00UL,
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

	result = libfvalue_binary_data_get_utf16_string_size(
	          binary_data,
	          &utf16_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | 0x000000ffUL,
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

	/* TODO test with unsupported byte order */

	/* TODO test with libuna_base16_stream_size_from_byte_stream failing */

	/* TODO test with libuna_base32_stream_size_from_byte_stream failing */

	/* TODO test with libuna_base64_stream_size_from_byte_stream failing */

	/* Clean up
	 */
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

/* Tests the libfvalue_binary_data_copy_to_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_copy_to_utf16_string_with_index(
     void )
{
	uint16_t expected_utf16_string_base16[ 9 ] = {
		'7', '4', '6', '5', '7', '3', '7', '4', 0 };
	uint16_t expected_utf16_string_base32[ 9 ] = {
		'O', 'R', 'S', 'X', 'G', '5', 'A', '=', 0 };
	uint16_t expected_utf16_string_base64[ 9 ] = {
		'd', 'G', 'V', 'z', 'd', 'A', '=', '=', 0 };
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_binary_data_t *binary_data = NULL;
	size_t utf16_string_index            = 0;
	int result                           = 0;

	/* Initialize test
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

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          (uint8_t *) "test",
	          4,
	          0,
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
	utf16_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          binary_data,
	          utf16_string,
	          32,
	          &utf16_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          utf16_string,
	          expected_utf16_string_base16,
	          sizeof( uint16_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          binary_data,
	          utf16_string,
	          32,
	          &utf16_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          utf16_string,
	          expected_utf16_string_base32,
	          sizeof( uint16_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          binary_data,
	          utf16_string,
	          32,
	          &utf16_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE64,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          utf16_string,
	          expected_utf16_string_base64,
	          sizeof( uint16_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf16_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          NULL,
	          utf16_string,
	          32,
	          &utf16_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          binary_data,
	          NULL,
	          32,
	          &utf16_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
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

	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          binary_data,
	          utf16_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf16_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          binary_data,
	          utf16_string,
	          32,
	          NULL,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	utf16_string_index = 32;

	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          binary_data,
	          utf16_string,
	          32,
	          &utf16_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 32 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	utf16_string_index = 0;

	/* Unsupported flags
	 */
	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          binary_data,
	          utf16_string,
	          32,
	          &utf16_string_index,
	          0xffffff00UL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Unsupported encoding
	 */
	result = libfvalue_binary_data_copy_to_utf16_string_with_index(
	          binary_data,
	          utf16_string,
	          32,
	          &utf16_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | 0x000000ffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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

/* Tests the libfvalue_binary_data_get_utf32_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_get_utf32_string_size(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_binary_data_t *binary_data = NULL;
	size_t utf32_string_size             = 0;
	int result                           = 0;

	/* Initialize test
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

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          (uint8_t *) "test",
	          4,
	          0,
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
	result = libfvalue_binary_data_get_utf32_string_size(
	          binary_data,
	          &utf32_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_size",
	 utf32_string_size,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_binary_data_get_utf32_string_size(
	          binary_data,
	          &utf32_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_size",
	 utf32_string_size,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_binary_data_get_utf32_string_size(
	          binary_data,
	          &utf32_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE64,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_size",
	 utf32_string_size,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_binary_data_get_utf32_string_size(
	          NULL,
	          &utf32_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
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

	result = libfvalue_binary_data_get_utf32_string_size(
	          binary_data,
	          NULL,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
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

	result = libfvalue_binary_data_get_utf32_string_size(
	          binary_data,
	          &utf32_string_size,
	          0xffffff00UL,
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

	result = libfvalue_binary_data_get_utf32_string_size(
	          binary_data,
	          &utf32_string_size,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | 0x000000ffUL,
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

/* Tests the libfvalue_binary_data_copy_to_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_binary_data_copy_to_utf32_string_with_index(
     void )
{
	uint32_t expected_utf32_string_base16[ 9 ] = {
		'7', '4', '6', '5', '7', '3', '7', '4', 0 };
	uint32_t expected_utf32_string_base32[ 9 ] = {
		'O', 'R', 'S', 'X', 'G', '5', 'A', '=', 0 };
	uint32_t expected_utf32_string_base64[ 9 ] = {
		'd', 'G', 'V', 'z', 'd', 'A', '=', '=', 0 };
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_binary_data_t *binary_data = NULL;
	size_t utf32_string_index            = 0;
	int result                           = 0;

	/* Initialize test
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

	result = libfvalue_binary_data_copy_from_byte_stream(
	          binary_data,
	          (uint8_t *) "test",
	          4,
	          0,
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
	utf32_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          binary_data,
	          utf32_string,
	          32,
	          &utf32_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          utf32_string,
	          expected_utf32_string_base16,
	          sizeof( uint32_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          binary_data,
	          utf32_string,
	          32,
	          &utf32_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          utf32_string,
	          expected_utf32_string_base32,
	          sizeof( uint32_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          binary_data,
	          utf32_string,
	          32,
	          &utf32_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE64,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          utf32_string,
	          expected_utf32_string_base64,
	          sizeof( uint32_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          NULL,
	          utf32_string,
	          32,
	          &utf32_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          binary_data,
	          NULL,
	          32,
	          &utf32_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
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

	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          binary_data,
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          binary_data,
	          utf32_string,
	          32,
	          NULL,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	utf32_string_index = 32;

	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          binary_data,
	          utf32_string,
	          32,
	          &utf32_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | LIBFVALUE_BINARY_DATA_FORMAT_TYPE_BASE16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 32 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	utf32_string_index = 0;

	/* Unsupported flags
	 */
	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          binary_data,
	          utf32_string,
	          32,
	          &utf32_string_index,
	          0xffffff00UL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Unsupported encoding
	 */
	result = libfvalue_binary_data_copy_to_utf32_string_with_index(
	          binary_data,
	          utf32_string,
	          32,
	          &utf32_string_index,
	          LIBFVALUE_BINARY_DATA_FORMAT_FLAG_CASE_UPPER | 0x000000ffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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
	 "libfvalue_binary_data_initialize",
	 fvalue_test_binary_data_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_free",
	 fvalue_test_binary_data_free );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_clone",
	 fvalue_test_binary_data_clone );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_copy_from_byte_stream",
	 fvalue_test_binary_data_copy_from_byte_stream );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_get_utf8_string_size",
	 fvalue_test_binary_data_get_utf8_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_copy_to_utf8_string_with_index",
	 fvalue_test_binary_data_copy_to_utf8_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_get_utf16_string_size",
	 fvalue_test_binary_data_get_utf16_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_copy_to_utf16_string_with_index",
	 fvalue_test_binary_data_copy_to_utf16_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_get_utf32_string_size",
	 fvalue_test_binary_data_get_utf32_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_binary_data_copy_to_utf32_string_with_index",
	 fvalue_test_binary_data_copy_to_utf32_string_with_index );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

