/*
 * Library floating_point type test program
 *
 * Copyright (C) 2010-2023, Joachim Metz <joachim.metz@gmail.com>
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
#include <byte_stream.h>
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

	floating_point = NULL;

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

	destination_floating_point = (libfvalue_floating_point_t *) 0x12345678UL;

	result = libfvalue_floating_point_clone(
	          &destination_floating_point,
	          source_floating_point,
	          &error );

	destination_floating_point = NULL;

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

	/* Test libfvalue_floating_point_clone with malloc failing
	 */
	fvalue_test_malloc_attempts_before_fail = 0;

	result = libfvalue_floating_point_clone(
	          &destination_floating_point,
	          source_floating_point,
	          &error );

	if( fvalue_test_malloc_attempts_before_fail != -1 )
	{
		fvalue_test_malloc_attempts_before_fail = -1;

		if( destination_floating_point != NULL )
		{
			libfvalue_floating_point_free(
			 &destination_floating_point,
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
		 "destination_floating_point",
		 destination_floating_point );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}

	/* Test libfvalue_floating_point_clone with memcpy failing
	 */
	fvalue_test_memcpy_attempts_before_fail = 0;

	result = libfvalue_floating_point_clone(
	          &destination_floating_point,
	          source_floating_point,
	          &error );

	if( fvalue_test_memcpy_attempts_before_fail != -1 )
	{
		fvalue_test_memcpy_attempts_before_fail = -1;

		if( destination_floating_point != NULL )
		{
			libfvalue_floating_point_free(
			 &destination_floating_point,
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
		 "destination_floating_point",
		 destination_floating_point );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FVALUE_TEST_MEMORY ) */

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

/* Tests the libfvalue_floating_point_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	int result                                 = 0;

	/* Initialize test
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

	/* Test regular cases
	 */
	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\x41\x45\x70\xa4",
	          4,
	          LIBFVALUE_ENDIAN_BIG,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point->value",
	 floating_point->value,
	 (uint64_t) 0x414570a4UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\xa4\x70\x45\x41",
	          4,
	          LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point->value",
	 floating_point->value,
	 (uint64_t) 0x414570a4UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\xa4\x70\x45\x41",
	          4,
	          LIBFVALUE_ENDIAN_NATIVE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	if( _BYTE_STREAM_HOST_IS_ENDIAN_BIG )
	{
		FVALUE_TEST_ASSERT_EQUAL_UINT64(
		 "floating_point->value",
		 floating_point->value,
		 (uint64_t) 0xa4704541UL );
	}
	else if( _BYTE_STREAM_HOST_IS_ENDIAN_LITTLE )
	{
		FVALUE_TEST_ASSERT_EQUAL_UINT64(
		 "floating_point->value",
		 floating_point->value,
		 (uint64_t) 0x414570a4UL );
	}
	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\x40\xb3\x1a\x45\x1e\xb8\x51\xec",
	          8,
	          LIBFVALUE_ENDIAN_BIG,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point->value",
	 floating_point->value,
	 (uint64_t) 0x40b31a451eb851ecUL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\xec\x51\xb8\x1e\x45\x1a\xb3\x40",
	          8,
	          LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point->value",
	 floating_point->value,
	 (uint64_t) 0x40b31a451eb851ecUL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\xec\x51\xb8\x1e\x45\x1a\xb3\x40",
	          8,
	          LIBFVALUE_ENDIAN_NATIVE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	if( _BYTE_STREAM_HOST_IS_ENDIAN_BIG )
	{
		FVALUE_TEST_ASSERT_EQUAL_UINT64(
		 "floating_point->value",
		 floating_point->value,
		 (uint64_t) 0xec51b81e451ab340UL );
	}
	else if( _BYTE_STREAM_HOST_IS_ENDIAN_LITTLE )
	{
		FVALUE_TEST_ASSERT_EQUAL_UINT64(
		 "floating_point->value",
		 floating_point->value,
		 (uint64_t) 0x40b31a451eb851ecUL );
	}
	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_floating_point_copy_from_byte_stream(
	          NULL,
	          (uint8_t *) "\x41\x45\x70\xa4",
	          4,
	          LIBFVALUE_ENDIAN_BIG,
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

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          NULL,
	          4,
	          LIBFVALUE_ENDIAN_BIG,
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

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\x41\x45\x70\xa4",
	          (size_t) SSIZE_MAX + 1,
	          LIBFVALUE_ENDIAN_BIG,
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

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\x41\x45\x70\xa4",
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

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\x41\x45\x70\xa4",
	          3,
	          LIBFVALUE_ENDIAN_BIG,
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

/* Tests the libfvalue_floating_point_copy_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_from_integer(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	int result                                 = 0;

	/* Initialize test
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

	/* Test regular cases
	 */
	result = libfvalue_floating_point_copy_from_integer(
	          floating_point,
	          (uint64_t) 12,
	          64,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point->value",
	 floating_point->value,
	 (uint64_t) 0x4028000000000000UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_floating_point_copy_from_integer(
	          NULL,
	          (uint64_t) 12,
	          64,
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

	result = libfvalue_floating_point_copy_from_integer(
	          floating_point,
	          (uint64_t) 12,
	          8,
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

/* Tests the libfvalue_floating_point_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_to_integer(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	size_t integer_value_size                  = 0;
	uint64_t integer_value                     = 0;
	int result                                 = 0;

	/* Initialize test
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

	floating_point->value      = (uint64_t) 0x4028ae147ae147aeUL;
	floating_point->value_size = 64;

	/* Test regular cases
	 */
	integer_value      = 0;
	integer_value_size = 0;

	result = libfvalue_floating_point_copy_to_integer(
	          floating_point,
	          &integer_value,
	          &integer_value_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 (uint64_t) 12 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "integer_value_size",
	 integer_value_size,
	 (size_t) 64 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	integer_value      = 0;
	integer_value_size = 0;

	result = libfvalue_floating_point_copy_to_integer(
	          NULL,
	          &integer_value,
	          &integer_value_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "integer_value_size",
	 integer_value_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_to_integer(
	          floating_point,
	          NULL,
	          &integer_value_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "integer_value_size",
	 integer_value_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_to_integer(
	          floating_point,
	          &integer_value,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "integer_value_size",
	 integer_value_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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

/* Tests the libfvalue_floating_point_copy_from_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_from_floating_point(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	int result                                 = 0;

	/* Initialize test
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

	/* Test regular cases
	 */
	result = libfvalue_floating_point_copy_from_floating_point(
	          floating_point,
	          (double) 12.34,
	          64,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point->value",
	 floating_point->value,
	 (uint64_t) 0x4028ae147ae147aeUL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_floating_point_copy_from_floating_point(
	          NULL,
	          (double) 12.34,
	          64,
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

	result = libfvalue_floating_point_copy_from_floating_point(
	          floating_point,
	          (double) 12.34,
	          8,
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

/* Tests the libfvalue_floating_point_copy_to_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_to_floating_point(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	size_t floating_point_value_size           = 0;
	double floating_point_value                = 0;
	int result                                 = 0;

	/* Initialize test
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

	floating_point->value      = (uint64_t) 0x4028ae147ae147aeUL;
	floating_point->value_size = 64;

	/* Test regular cases
	 */
	floating_point_value      = 0;
	floating_point_value_size = 0;

	result = libfvalue_floating_point_copy_to_floating_point(
	          floating_point,
	          &floating_point_value,
	          &floating_point_value_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_FLOAT(
	 "floating_point_value",
	 floating_point_value,
	 (double) 12.34 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "floating_point_value_size",
	 floating_point_value_size,
	 (size_t) 64 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	floating_point_value      = 0;
	floating_point_value_size = 0;

	result = libfvalue_floating_point_copy_to_floating_point(
	          NULL,
	          &floating_point_value,
	          &floating_point_value_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_FLOAT(
	 "floating_point_value",
	 floating_point_value,
	 (double) 0.0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "floating_point_value_size",
	 floating_point_value_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_to_floating_point(
	          floating_point,
	          NULL,
	          &floating_point_value_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_FLOAT(
	 "floating_point_value",
	 floating_point_value,
	 (double) 0.0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "floating_point_value_size",
	 floating_point_value_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_to_floating_point(
	          floating_point,
	          &floating_point_value,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_FLOAT(
	 "floating_point_value",
	 floating_point_value,
	 (double) 0.0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "floating_point_value_size",
	 floating_point_value_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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

/* Tests the libfvalue_floating_point_get_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_get_string_size(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	size_t string_size                         = 0;
	int result                                 = 0;

	/* Initialize test
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

	result = libfvalue_floating_point_copy_from_floating_point(
	          floating_point,
	          (double) 12.34,
	          64,
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
	string_size = 0;

	result = libfvalue_floating_point_get_string_size(
	          floating_point,
	          &string_size,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 19 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_size = 0;

	result = libfvalue_floating_point_get_string_size(
	          NULL,
	          &string_size,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_get_string_size(
	          floating_point,
	          NULL,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

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

/* Tests the libfvalue_floating_point_copy_from_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_from_utf8_string_with_index(
     void )
{
	uint8_t utf8_string[ 19 ] = {
		'0', 'x', '4', '1', 'd', '0', '5', '1', '5', 'c', '2', '9', '0', '0', '0', '0',
		'0', '0', 0 };

	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	size_t string_index                        = 0;
	int result                                 = 0;

	/* Initialize test
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

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\x40\x28\x00\x00\x00\x00\x00\x00",
	          8,
	          LIBFVALUE_ENDIAN_BIG,
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
	string_index = 0;

	result = libfvalue_floating_point_copy_from_utf8_string_with_index(
	          floating_point,
	          utf8_string,
	          18,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 18 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_floating_point_copy_from_utf8_string_with_index(
	          NULL,
	          utf8_string,
	          18,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_from_utf8_string_with_index(
	          floating_point,
	          NULL,
	          18,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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

/* Tests the libfvalue_floating_point_copy_to_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_to_utf8_string_with_index(
     void )
{
	uint8_t expected_utf8_string[ 19 ] = {
		'0', 'x', '4', '0', '2', '8', 'a', 'e', '1', '4', '7', 'a', 'e', '1', '4', '7',
		'a', 'e', 0 };
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	size_t string_index                        = 0;
	int result                                 = 0;

	/* Initialize test
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

	result = libfvalue_floating_point_copy_from_floating_point(
	          floating_point,
	          (double) 12.34,
	          64,
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
	string_index = 0;

	result = libfvalue_floating_point_copy_to_utf8_string_with_index(
	          floating_point,
	          utf8_string,
	          32,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 19 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string,
	          utf8_string,
	          sizeof( uint8_t ) * 19 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_floating_point_copy_to_utf8_string_with_index(
	          NULL,
	          utf8_string,
	          32,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_to_utf8_string_with_index(
	          floating_point,
	          NULL,
	          32,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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

/* Tests the libfvalue_floating_point_copy_from_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_from_utf16_string_with_index(
     void )
{
	uint16_t utf16_string[ 19 ] = {
		'0', 'x', '4', '1', 'd', '0', '5', '1', '5', 'c', '2', '9', '0', '0', '0', '0',
		'0', '0', 0 };

	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	size_t string_index                        = 0;
	int result                                 = 0;

	/* Initialize test
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

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\x40\x28\x00\x00\x00\x00\x00\x00",
	          8,
	          LIBFVALUE_ENDIAN_BIG,
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
	string_index = 0;

	result = libfvalue_floating_point_copy_from_utf16_string_with_index(
	          floating_point,
	          utf16_string,
	          18,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 18 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_floating_point_copy_from_utf16_string_with_index(
	          NULL,
	          utf16_string,
	          18,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_from_utf16_string_with_index(
	          floating_point,
	          NULL,
	          18,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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

/* Tests the libfvalue_floating_point_copy_to_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_to_utf16_string_with_index(
     void )
{
	uint16_t expected_utf16_string[ 19 ] = {
		'0', 'x', '4', '0', '2', '8', 'a', 'e', '1', '4', '7', 'a', 'e', '1', '4', '7',
		'a', 'e', 0 };
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	size_t string_index                        = 0;
	int result                                 = 0;

	/* Initialize test
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

	result = libfvalue_floating_point_copy_from_floating_point(
	          floating_point,
	          (double) 12.34,
	          64,
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
	string_index = 0;

	result = libfvalue_floating_point_copy_to_utf16_string_with_index(
	          floating_point,
	          utf16_string,
	          32,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 19 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string,
	          utf16_string,
	          sizeof( uint16_t ) * 19 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_floating_point_copy_to_utf16_string_with_index(
	          NULL,
	          utf16_string,
	          32,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_to_utf16_string_with_index(
	          floating_point,
	          NULL,
	          32,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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

/* Tests the libfvalue_floating_point_copy_from_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_from_utf32_string_with_index(
     void )
{
	uint32_t utf32_string[ 19 ] = {
		'0', 'x', '4', '1', 'd', '0', '5', '1', '5', 'c', '2', '9', '0', '0', '0', '0',
		'0', '0', 0 };

	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	size_t string_index                        = 0;
	int result                                 = 0;

	/* Initialize test
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

	result = libfvalue_floating_point_copy_from_byte_stream(
	          floating_point,
	          (uint8_t *) "\x40\x28\x00\x00\x00\x00\x00\x00",
	          8,
	          LIBFVALUE_ENDIAN_BIG,
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
	string_index = 0;

	result = libfvalue_floating_point_copy_from_utf32_string_with_index(
	          floating_point,
	          utf32_string,
	          18,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 18 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_floating_point_copy_from_utf32_string_with_index(
	          NULL,
	          utf32_string,
	          18,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_from_utf32_string_with_index(
	          floating_point,
	          NULL,
	          18,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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

/* Tests the libfvalue_floating_point_copy_to_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_floating_point_copy_to_utf32_string_with_index(
     void )
{
	uint32_t expected_utf32_string[ 19 ] = {
		'0', 'x', '4', '0', '2', '8', 'a', 'e', '1', '4', '7', 'a', 'e', '1', '4', '7',
		'a', 'e', 0 };
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error                   = NULL;
	libfvalue_floating_point_t *floating_point = NULL;
	size_t string_index                        = 0;
	int result                                 = 0;

	/* Initialize test
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

	result = libfvalue_floating_point_copy_from_floating_point(
	          floating_point,
	          (double) 12.34,
	          64,
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
	string_index = 0;

	result = libfvalue_floating_point_copy_to_utf32_string_with_index(
	          floating_point,
	          utf32_string,
	          32,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 19 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 19 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_floating_point_copy_to_utf32_string_with_index(
	          NULL,
	          utf32_string,
	          32,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_floating_point_copy_to_utf32_string_with_index(
	          floating_point,
	          NULL,
	          32,
	          &string_index,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
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

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

/* Tests the libfvalue_string_size_from_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_size_from_floating_point(
     void )
{
	libcerror_error_t *error = NULL;
	size_t string_size       = 0;
	int result               = 0;

	/* Test regular cases
	 */
	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x00000000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x4598d229UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x807fffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 15 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x7f800000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0xffc00000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x7fffffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x4598d229UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 11 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x800fffffffffffffUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 15 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x7ff0000000000000UL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0xfff8000000000000UL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x7fffffffffffffffUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 19 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_size = 0;

	result = libfvalue_string_size_from_floating_point(
	          NULL,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          4,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported format flags
	 */
	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          0xffffffffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported string format type
	 */
	result = libfvalue_string_size_from_floating_point(
	          &string_size,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          0x000000ffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 0 );

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

/* Tests the libfvalue_utf8_string_copy_from_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf8_string_copy_from_floating_point(
     void )
{
	uint8_t expected_utf8_string[ 14 ] = {
		'4', '.', '8', '9', '0', '2', '7', '0', 'e', '+', '0', '0', '3', 0 };
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfvalue_utf8_string_copy_from_floating_point(
	          utf8_string,
	          32,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string,
	          utf8_string,
	          sizeof( uint8_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfvalue_utf8_string_copy_from_floating_point(
	          NULL,
	          32,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

/* Tests the libfvalue_utf8_string_with_index_copy_from_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf8_string_with_index_copy_from_floating_point(
     void )
{
	uint8_t expected_utf8_string_hexadecimal_32bit[ 11 ] = {
		'0', 'x', '4', '5', '9', '8', 'd', '2', '2', '9', 0 };
	uint8_t expected_utf8_string_hexadecimal_64bit[ 19 ] = {
		'0', 'x', '4', '0', 'b', '3', '1', 'a', '4', '5', '1', 'e', 'b', '8', '5', '1',
		'e', 'c', 0 };
	uint8_t expected_utf8_string_indeterminate[ 4 ] = {
		'I', 'n', 'd', 0 };
	uint8_t expected_utf8_string_infinite[ 4 ] = {
		'I', 'n', 'f', 0 };
	uint8_t expected_utf8_string_negative_32bit[ 15 ] = {
                '-', '1', '.', '1', '7', '5', '4', '9', '4', 'e', '-', '0', '3', '8', 0 };
	uint8_t expected_utf8_string_negative_64bit[ 15 ] = {
                '-', '2', '.', '2', '2', '5', '0', '7', '4', 'e', '-', '3', '0', '8', 0 };
	uint8_t expected_utf8_string_not_a_number[ 4 ] = {
		'N', 'a', 'N', 0 };
	uint8_t expected_utf8_string_positive_32bit[ 14 ] = {
		'3', '.', '4', '0', '2', '8', '2', '3', 'e', '+', '0', '3', '8', 0 };
	uint8_t expected_utf8_string_positive_64bit[ 14 ] = {
		'1', '.', '7', '9', '7', '6', '9', '3', 'e', '+', '3', '0', '8', 0 };
	uint8_t expected_utf8_string_zero[ 14 ] = {
                '0', '.', '0', '0', '0', '0', '0', '0', 'e', '+', '0', '0', '0', 0 };
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error = NULL;
	size_t utf8_string_index = 0;
	int result               = 0;

	/* Test regular cases
	 */
	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x00000000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_zero,
	          utf8_string,
	          sizeof( uint8_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x7f7fffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_positive_32bit,
	          utf8_string,
	          sizeof( uint8_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x807fffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 15 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_negative_32bit,
	          utf8_string,
	          sizeof( uint8_t ) * 15 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x7f800000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_infinite,
	          utf8_string,
	          sizeof( uint8_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0xffc00000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_indeterminate,
	          utf8_string,
	          sizeof( uint8_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x7fffffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_not_a_number,
	          utf8_string,
	          sizeof( uint8_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x4598d229UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 11 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_hexadecimal_32bit,
	          utf8_string,
	          sizeof( uint8_t ) * 11 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x7fefffffffffffffULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_positive_64bit,
	          utf8_string,
	          sizeof( uint8_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x800fffffffffffffULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 15 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_negative_64bit,
	          utf8_string,
	          sizeof( uint8_t ) * 15 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x7ff0000000000000ULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_infinite,
	          utf8_string,
	          sizeof( uint8_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0xfff8000000000000UL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_indeterminate,
	          utf8_string,
	          sizeof( uint8_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x7fffffffffffffffULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_not_a_number,
	          utf8_string,
	          sizeof( uint8_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 19 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_hexadecimal_64bit,
	          utf8_string,
	          sizeof( uint8_t ) * 19 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          NULL,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf8_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          NULL,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          4,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	/* Test with unsupported format flags
	 */
	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          0xffffffffUL,
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

	/* Test with unsupported string format type
	 */
	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          0x000000ffUL,
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

	/* Test with string too small
	 */
	result = libfvalue_utf8_string_with_index_copy_from_floating_point(
	          utf8_string,
	          12,
	          &utf8_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfvalue_utf8_string_with_index_copy_to_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf8_string_with_index_copy_to_floating_point(
     void )
{
	uint8_t utf8_string_decimal[ 8 ] = {
		'4', '8', '9', '0', '.', '2', '7', 0 };
	uint8_t utf8_string_hexadecimal_lower_case[ 19 ] = {
		'0', 'x', '4', '1', 'd', '0', '5', '1', '5', 'c', '2', '9', '0', '0', '0', '0',
		'0', '0', 0 };
	uint8_t utf8_string_hexadecimal_upper_case[ 19 ] = {
		'0', 'x', '4', '1', 'D', '0', '5', '1', '5', 'C', '2', '9', '0', '0', '0', '0',
		'0', '0', 0 };
	uint8_t utf8_string_invalid1[ 3 ] = {
		'/', ':', 0 };
	uint8_t utf8_string_invalid2[ 4 ] = {
		'0', '/', ':', 0 };

	libcerror_error_t *error      = NULL;
	size_t string_index           = 0;
	uint64_t floating_point_value = 0;
	int result                    = 0;

	/* Test regular cases
	 */
	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 7 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0x40b31a451eb851ecUL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_hexadecimal_lower_case,
	          18,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 18 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0x41d0515c29000000UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_hexadecimal_upper_case,
	          18,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 18 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0x41d0515c29000000UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          NULL,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_decimal,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_decimal,
	          7,
	          NULL,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_index = 7;

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 7 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_decimal,
	          7,
	          &string_index,
	          NULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          4,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported format flags
	 */
	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          0xffffffffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported string format type
	 */
	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          0x000000ffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with invalid input data
	 */
	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_invalid1,
	          2,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_invalid1,
	          2,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf8_string_with_index_copy_to_floating_point(
	          utf8_string_invalid2,
	          3,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

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

/* Tests the libfvalue_utf16_string_copy_from_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf16_string_copy_from_floating_point(
     void )
{
	uint16_t expected_utf16_string[ 14 ] = {
		'4', '.', '8', '9', '0', '2', '7', '0', 'e', '+', '0', '0', '3', 0 };
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfvalue_utf16_string_copy_from_floating_point(
	          utf16_string,
	          32,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string,
	          utf16_string,
	          sizeof( uint16_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfvalue_utf16_string_copy_from_floating_point(
	          NULL,
	          32,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

/* Tests the libfvalue_utf16_string_with_index_copy_from_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf16_string_with_index_copy_from_floating_point(
     void )
{
	uint16_t expected_utf16_string_hexadecimal_32bit[ 11 ] = {
		'0', 'x', '4', '5', '9', '8', 'd', '2', '2', '9', 0 };
	uint16_t expected_utf16_string_hexadecimal_64bit[ 19 ] = {
		'0', 'x', '4', '0', 'b', '3', '1', 'a', '4', '5', '1', 'e', 'b', '8', '5', '1',
		'e', 'c', 0 };
	uint16_t expected_utf16_string_indeterminate[ 4 ] = {
		'I', 'n', 'd', 0 };
	uint16_t expected_utf16_string_infinite[ 4 ] = {
		'I', 'n', 'f', 0 };
	uint16_t expected_utf16_string_negative_32bit[ 15 ] = {
                '-', '1', '.', '1', '7', '5', '4', '9', '4', 'e', '-', '0', '3', '8', 0 };
	uint16_t expected_utf16_string_negative_64bit[ 15 ] = {
                '-', '2', '.', '2', '2', '5', '0', '7', '4', 'e', '-', '3', '0', '8', 0 };
	uint16_t expected_utf16_string_not_a_number[ 4 ] = {
		'N', 'a', 'N', 0 };
	uint16_t expected_utf16_string_positive_32bit[ 14 ] = {
		'3', '.', '4', '0', '2', '8', '2', '3', 'e', '+', '0', '3', '8', 0 };
	uint16_t expected_utf16_string_positive_64bit[ 14 ] = {
		'1', '.', '7', '9', '7', '6', '9', '3', 'e', '+', '3', '0', '8', 0 };
	uint16_t expected_utf16_string_zero[ 14 ] = {
                '0', '.', '0', '0', '0', '0', '0', '0', 'e', '+', '0', '0', '0', 0 };
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error  = NULL;
	size_t utf16_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x00000000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_zero,
	          utf16_string,
	          sizeof( uint16_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x7f7fffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_positive_32bit,
	          utf16_string,
	          sizeof( uint16_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x807fffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 15 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_negative_32bit,
	          utf16_string,
	          sizeof( uint16_t ) * 15 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x7f800000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_infinite,
	          utf16_string,
	          sizeof( uint16_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0xffc00000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_indeterminate,
	          utf16_string,
	          sizeof( uint16_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x7fffffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_not_a_number,
	          utf16_string,
	          sizeof( uint16_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x4598d229UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 11 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_hexadecimal_32bit,
	          utf16_string,
	          sizeof( uint16_t ) * 11 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x7fefffffffffffffULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_positive_64bit,
	          utf16_string,
	          sizeof( uint16_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x800fffffffffffffULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 15 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_negative_64bit,
	          utf16_string,
	          sizeof( uint16_t ) * 15 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x7ff0000000000000ULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_infinite,
	          utf16_string,
	          sizeof( uint16_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0xfff8000000000000UL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_indeterminate,
	          utf16_string,
	          sizeof( uint16_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x7fffffffffffffffULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_not_a_number,
	          utf16_string,
	          sizeof( uint16_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 19 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_hexadecimal_64bit,
	          utf16_string,
	          sizeof( uint16_t ) * 19 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          NULL,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf16_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          NULL,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          4,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	/* Test with unsupported format flags
	 */
	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          0xffffffffUL,
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

	/* Test with unsupported string format type
	 */
	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          0x000000ffUL,
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

	/* Test with string too small
	 */
	result = libfvalue_utf16_string_with_index_copy_from_floating_point(
	          utf16_string,
	          12,
	          &utf16_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfvalue_utf16_string_with_index_copy_to_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf16_string_with_index_copy_to_floating_point(
     void )
{
	uint16_t utf16_string_decimal[ 8 ] = {
		'4', '8', '9', '0', '.', '2', '7', 0 };
	uint16_t utf16_string_hexadecimal_lower_case[ 19 ] = {
		'0', 'x', '4', '1', 'd', '0', '5', '1', '5', 'c', '2', '9', '0', '0', '0', '0',
		'0', '0', 0 };
	uint16_t utf16_string_hexadecimal_upper_case[ 19 ] = {
		'0', 'x', '4', '1', 'D', '0', '5', '1', '5', 'C', '2', '9', '0', '0', '0', '0',
		'0', '0', 0 };
	uint16_t utf16_string_invalid1[ 3 ] = {
		'/', ':', 0 };
	uint16_t utf16_string_invalid2[ 4 ] = {
		'0', '/', ':', 0 };

	libcerror_error_t *error      = NULL;
	size_t string_index           = 0;
	uint64_t floating_point_value = 0;
	int result                    = 0;

	/* Test regular cases
	 */
	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 7 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0x40b31a451eb851ecUL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_hexadecimal_lower_case,
	          18,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 18 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0x41d0515c29000000UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_hexadecimal_upper_case,
	          18,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 18 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0x41d0515c29000000UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          NULL,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_decimal,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_decimal,
	          7,
	          NULL,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_index = 7;

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 7 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_decimal,
	          7,
	          &string_index,
	          NULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          4,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported format flags
	 */
	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          0xffffffffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported string format type
	 */
	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          0x000000ffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with invalid input data
	 */
	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_invalid1,
	          2,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_invalid1,
	          2,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf16_string_with_index_copy_to_floating_point(
	          utf16_string_invalid2,
	          3,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

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

/* Tests the libfvalue_utf32_string_copy_from_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf32_string_copy_from_floating_point(
     void )
{
	uint32_t expected_utf32_string[ 14 ] = {
		'4', '.', '8', '9', '0', '2', '7', '0', 'e', '+', '0', '0', '3', 0 };
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfvalue_utf32_string_copy_from_floating_point(
	          utf32_string,
	          32,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfvalue_utf32_string_copy_from_floating_point(
	          NULL,
	          32,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

/* Tests the libfvalue_utf32_string_with_index_copy_from_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf32_string_with_index_copy_from_floating_point(
     void )
{
	uint32_t expected_utf32_string_hexadecimal_32bit[ 11 ] = {
		'0', 'x', '4', '5', '9', '8', 'd', '2', '2', '9', 0 };
	uint32_t expected_utf32_string_hexadecimal_64bit[ 19 ] = {
		'0', 'x', '4', '0', 'b', '3', '1', 'a', '4', '5', '1', 'e', 'b', '8', '5', '1',
		'e', 'c', 0 };
	uint32_t expected_utf32_string_indeterminate[ 4 ] = {
		'I', 'n', 'd', 0 };
	uint32_t expected_utf32_string_infinite[ 4 ] = {
		'I', 'n', 'f', 0 };
	uint32_t expected_utf32_string_negative_32bit[ 15 ] = {
                '-', '1', '.', '1', '7', '5', '4', '9', '4', 'e', '-', '0', '3', '8', 0 };
	uint32_t expected_utf32_string_negative_64bit[ 15 ] = {
                '-', '2', '.', '2', '2', '5', '0', '7', '4', 'e', '-', '3', '0', '8', 0 };
	uint32_t expected_utf32_string_not_a_number[ 4 ] = {
		'N', 'a', 'N', 0 };
	uint32_t expected_utf32_string_positive_32bit[ 14 ] = {
		'3', '.', '4', '0', '2', '8', '2', '3', 'e', '+', '0', '3', '8', 0 };
	uint32_t expected_utf32_string_positive_64bit[ 14 ] = {
		'1', '.', '7', '9', '7', '6', '9', '3', 'e', '+', '3', '0', '8', 0 };
	uint32_t expected_utf32_string_zero[ 14 ] = {
                '0', '.', '0', '0', '0', '0', '0', '0', 'e', '+', '0', '0', '0', 0 };
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error  = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x00000000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_zero,
	          utf32_string,
	          sizeof( uint32_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x7f7fffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_positive_32bit,
	          utf32_string,
	          sizeof( uint32_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x807fffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 15 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_negative_32bit,
	          utf32_string,
	          sizeof( uint32_t ) * 15 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x7f800000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_infinite,
	          utf32_string,
	          sizeof( uint32_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0xffc00000UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_indeterminate,
	          utf32_string,
	          sizeof( uint32_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x7fffffffUL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_not_a_number,
	          utf32_string,
	          sizeof( uint32_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x4598d229UL,
	          32,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 11 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_hexadecimal_32bit,
	          utf32_string,
	          sizeof( uint32_t ) * 11 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x7fefffffffffffffULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 14 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_positive_64bit,
	          utf32_string,
	          sizeof( uint32_t ) * 14 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x800fffffffffffffULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 15 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_negative_64bit,
	          utf32_string,
	          sizeof( uint32_t ) * 15 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x7ff0000000000000ULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_infinite,
	          utf32_string,
	          sizeof( uint32_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0xfff8000000000000UL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_indeterminate,
	          utf32_string,
	          sizeof( uint32_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x7fffffffffffffffULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_not_a_number,
	          utf32_string,
	          sizeof( uint32_t ) * 4 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 19 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_hexadecimal_64bit,
	          utf32_string,
	          sizeof( uint32_t ) * 19 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          NULL,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          NULL,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          4,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	/* Test with unsupported format flags
	 */
	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          0xffffffffUL,
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

	/* Test with unsupported string format type
	 */
	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          0x000000ffUL,
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

	/* Test with string too small
	 */
	result = libfvalue_utf32_string_with_index_copy_from_floating_point(
	          utf32_string,
	          12,
	          &utf32_string_index,
	          (uint64_t) 0x40b31a451eb851ecUL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfvalue_utf32_string_with_index_copy_to_floating_point function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf32_string_with_index_copy_to_floating_point(
     void )
{
	uint32_t utf32_string_decimal[ 8 ] = {
		'4', '8', '9', '0', '.', '2', '7', 0 };
	uint32_t utf32_string_hexadecimal_lower_case[ 19 ] = {
		'0', 'x', '4', '1', 'd', '0', '5', '1', '5', 'c', '2', '9', '0', '0', '0', '0',
		'0', '0', 0 };
	uint32_t utf32_string_hexadecimal_upper_case[ 19 ] = {
		'0', 'x', '4', '1', 'D', '0', '5', '1', '5', 'C', '2', '9', '0', '0', '0', '0',
		'0', '0', 0 };
	uint32_t utf32_string_invalid1[ 3 ] = {
		'/', ':', 0 };
	uint32_t utf32_string_invalid2[ 4 ] = {
		'0', '/', ':', 0 };

	libcerror_error_t *error      = NULL;
	size_t string_index           = 0;
	uint64_t floating_point_value = 0;
	int result                    = 0;

	/* Test regular cases
	 */
	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 7 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0x40b31a451eb851ecUL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_hexadecimal_lower_case,
	          18,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 18 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0x41d0515c29000000UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_hexadecimal_upper_case,
	          18,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 18 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0x41d0515c29000000UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index         = 0;
	floating_point_value = 0;

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          NULL,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_decimal,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_decimal,
	          7,
	          NULL,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_index = 7;

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 7 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_decimal,
	          7,
	          &string_index,
	          NULL,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          4,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported format flags
	 */
	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          0xffffffffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported string format type
	 */
	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_decimal,
	          7,
	          &string_index,
	          &floating_point_value,
	          64,
	          0x000000ffUL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with invalid input data
	 */
	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_invalid1,
	          2,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_DECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_invalid1,
	          2,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf32_string_with_index_copy_to_floating_point(
	          utf32_string_invalid2,
	          3,
	          &string_index,
	          &floating_point_value,
	          64,
	          LIBFVALUE_FLOATING_POINT_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "floating_point_value",
	 floating_point_value,
	 (uint64_t) 0 );

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

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_from_byte_stream",
	 fvalue_test_floating_point_copy_from_byte_stream );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_from_integer",
	 fvalue_test_floating_point_copy_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_to_integer",
	 fvalue_test_floating_point_copy_to_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_from_floating_point",
	 fvalue_test_floating_point_copy_from_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_to_floating_point",
	 fvalue_test_floating_point_copy_to_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_get_string_size",
	 fvalue_test_floating_point_get_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_from_utf8_string_with_index",
	 fvalue_test_floating_point_copy_from_utf8_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_to_utf8_string_with_index",
	 fvalue_test_floating_point_copy_to_utf8_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_from_utf16_string_with_index",
	 fvalue_test_floating_point_copy_from_utf16_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_to_utf16_string_with_index",
	 fvalue_test_floating_point_copy_to_utf16_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_from_utf32_string_with_index",
	 fvalue_test_floating_point_copy_from_utf32_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_floating_point_copy_to_utf32_string_with_index",
	 fvalue_test_floating_point_copy_to_utf32_string_with_index );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	FVALUE_TEST_RUN(
	 "libfvalue_string_size_from_floating_point",
	 fvalue_test_string_size_from_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_utf8_string_copy_from_floating_point",
	 fvalue_test_utf8_string_copy_from_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_utf8_string_with_index_copy_from_floating_point",
	 fvalue_test_utf8_string_with_index_copy_from_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_utf8_string_with_index_copy_to_floating_point",
	 fvalue_test_utf8_string_with_index_copy_to_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_utf16_string_copy_from_floating_point",
	 fvalue_test_utf16_string_copy_from_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_utf16_string_with_index_copy_from_floating_point",
	 fvalue_test_utf16_string_with_index_copy_from_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_utf16_string_with_index_copy_to_floating_point",
	 fvalue_test_utf16_string_with_index_copy_to_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_utf32_string_copy_from_floating_point",
	 fvalue_test_utf32_string_copy_from_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_utf32_string_with_index_copy_from_floating_point",
	 fvalue_test_utf32_string_with_index_copy_from_floating_point );

	FVALUE_TEST_RUN(
	 "libfvalue_utf32_string_with_index_copy_to_floating_point",
	 fvalue_test_utf32_string_with_index_copy_to_floating_point );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

