/*
 * Library integer type test program
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

#include "../libfvalue/libfvalue_integer.h"

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

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

	integer = NULL;

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

	destination_integer = (libfvalue_integer_t *) 0x12345678UL;

	result = libfvalue_integer_clone(
	          &destination_integer,
	          source_integer,
	          &error );

	destination_integer = NULL;

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

	/* Test libfvalue_integer_clone with malloc failing
	 */
	fvalue_test_malloc_attempts_before_fail = 0;

	result = libfvalue_integer_clone(
	          &destination_integer,
	          source_integer,
	          &error );

	if( fvalue_test_malloc_attempts_before_fail != -1 )
	{
		fvalue_test_malloc_attempts_before_fail = -1;

		if( destination_integer != NULL )
		{
			libfvalue_integer_free(
			 &destination_integer,
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
		 "destination_integer",
		 destination_integer );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}

	/* Test libfvalue_integer_clone with memcpy failing
	 */
	fvalue_test_memcpy_attempts_before_fail = 0;

	result = libfvalue_integer_clone(
	          &destination_integer,
	          source_integer,
	          &error );

	if( fvalue_test_memcpy_attempts_before_fail != -1 )
	{
		fvalue_test_memcpy_attempts_before_fail = -1;

		if( destination_integer != NULL )
		{
			libfvalue_integer_free(
			 &destination_integer,
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
		 "destination_integer",
		 destination_integer );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FVALUE_TEST_MEMORY ) */

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

/* Tests the libfvalue_integer_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	int result                   = 0;

	/* Initialize test
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

	/* Test regular cases
	 */
	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12",
	          1,
	          LIBFVALUE_ENDIAN_BIG,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12\x34",
	          2,
	          LIBFVALUE_ENDIAN_BIG,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x1234UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x34\x12",
	          2,
	          LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x1234UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x34\x12",
	          2,
	          LIBFVALUE_ENDIAN_NATIVE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	if( _BYTE_STREAM_HOST_IS_ENDIAN_BIG )
	{
		FVALUE_TEST_ASSERT_EQUAL_UINT64(
		 "integer->value",
		 integer->value,
		 (uint64_t) 0x3412UL );
	}
	else if( _BYTE_STREAM_HOST_IS_ENDIAN_LITTLE )
	{
		FVALUE_TEST_ASSERT_EQUAL_UINT64(
		 "integer->value",
		 integer->value,
		 (uint64_t) 0x1234UL );
	}
	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12\x34\x56\x78",
	          4,
	          LIBFVALUE_ENDIAN_BIG,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x78\x56\x34\x12",
	          4,
	          LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x78\x56\x34\x12",
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
		 "integer->value",
		 integer->value,
		 (uint64_t) 0x78563412UL );
	}
	else if( _BYTE_STREAM_HOST_IS_ENDIAN_LITTLE )
	{
		FVALUE_TEST_ASSERT_EQUAL_UINT64(
		 "integer->value",
		 integer->value,
		 (uint64_t) 0x12345678UL );
	}
	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12\x34\x56\x78\x90\xab\xcd\xef",
	          8,
	          LIBFVALUE_ENDIAN_BIG,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x1234567890abcdefUL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\xef\xcd\xab\x90\x78\x56\x34\x12",
	          8,
	          LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x1234567890abcdefUL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\xef\xcd\xab\x90\x78\x56\x34\x12",
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
		 "integer->value",
		 integer->value,
		 (uint64_t) 0xefcdab9078563412UL );
	}
	else if( _BYTE_STREAM_HOST_IS_ENDIAN_LITTLE )
	{
		FVALUE_TEST_ASSERT_EQUAL_UINT64(
		 "integer->value",
		 integer->value,
		 (uint64_t) 0x1234567890abcdefUL );
	}
	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_integer_copy_from_byte_stream(
	          NULL,
	          (uint8_t *) "\x12\x34\x56\x78",
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

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
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

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12\x34\x56\x78",
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

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12\x34\x56\x78",
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

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12\x34\x56\x78",
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

/* Tests the libfvalue_integer_copy_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_copy_from_integer(
     void )
{
	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	int result                   = 0;

	/* Initialize test
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

	/* Test regular cases
	 */
	result = libfvalue_integer_copy_from_integer(
	          integer,
	          (uint64_t) 0x12345678UL,
	          32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_integer_copy_from_integer(
	          NULL,
	          (uint64_t) 0x12345678UL,
	          32,
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

	result = libfvalue_integer_copy_from_integer(
	          integer,
	          (uint64_t) 0x12345678UL,
	          4,
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

/* Tests the libfvalue_integer_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_copy_to_integer(
     void )
{
	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	size_t integer_value_size    = 0;
	uint64_t integer_value       = 0;
	int result                   = 0;

	/* Initialize test
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

	integer->value      = (uint64_t) 0x12345678UL;
	integer->value_size = 32;

	/* Test regular cases
	 */
	integer_value      = 0;
	integer_value_size = 0;

	result = libfvalue_integer_copy_to_integer(
	          integer,
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
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "integer_value_size",
	 integer_value_size,
	 (size_t) 32 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	integer_value      = 0;
	integer_value_size = 0;

	result = libfvalue_integer_copy_to_integer(
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

	result = libfvalue_integer_copy_to_integer(
	          integer,
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

	result = libfvalue_integer_copy_to_integer(
	          integer,
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

/* Tests the libfvalue_integer_get_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_get_string_size(
     void )
{
	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	size_t string_size           = 0;
	int result                   = 0;

	/* Initialize test
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

	result = libfvalue_integer_copy_from_integer(
	          integer,
	          (uint64_t) 0x12345678UL,
	          32,
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

	result = libfvalue_integer_get_string_size(
	          integer,
	          &string_size,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

	/* Test error cases
	 */
	string_size = 0;

	result = libfvalue_integer_get_string_size(
	          NULL,
	          &string_size,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

	result = libfvalue_integer_get_string_size(
	          integer,
	          NULL,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

/* Tests the libfvalue_integer_copy_from_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_copy_from_utf8_string_with_index(
     void )
{
	uint8_t utf8_string[ 11 ] = {
		'0', 'x', '1', '2', '3', '4', '5', '6', '7', '8', 0 };

	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	size_t string_index          = 0;
	int result                   = 0;

	/* Initialize test
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

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12\x34\x56\x78",
	          4,
	          LIBFVALUE_ENDIAN_BIG,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_index = 0;

	result = libfvalue_integer_copy_from_utf8_string_with_index(
	          integer,
	          utf8_string,
	          10,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 10 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_integer_copy_from_utf8_string_with_index(
	          NULL,
	          utf8_string,
	          10,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

	result = libfvalue_integer_copy_from_utf8_string_with_index(
	          integer,
	          NULL,
	          10,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

/* Tests the libfvalue_integer_copy_to_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_copy_to_utf8_string_with_index(
     void )
{
	uint8_t expected_utf8_string[ 11 ] = {
		'0', 'x', '1', '2', '3', '4', '5', '6', '7', '8', 0 };
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	size_t string_index          = 0;
	int result                   = 0;

	/* Initialize test
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

	result = libfvalue_integer_copy_from_integer(
	          integer,
	          (uint64_t) 0x12345678UL,
	          32,
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

	result = libfvalue_integer_copy_to_utf8_string_with_index(
	          integer,
	          utf8_string,
	          32,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 11 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string,
	          utf8_string,
	          sizeof( uint8_t ) * 11 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_integer_copy_to_utf8_string_with_index(
	          NULL,
	          utf8_string,
	          32,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

	result = libfvalue_integer_copy_to_utf8_string_with_index(
	          integer,
	          NULL,
	          32,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

/* Tests the libfvalue_integer_copy_from_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_copy_from_utf16_string_with_index(
     void )
{
	uint16_t utf16_string[ 11 ] = {
		'0', 'x', '1', '2', '3', '4', '5', '6', '7', '8', 0 };

	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	size_t string_index          = 0;
	int result                   = 0;

	/* Initialize test
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

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12\x34\x56\x78",
	          4,
	          LIBFVALUE_ENDIAN_BIG,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_index = 0;

	result = libfvalue_integer_copy_from_utf16_string_with_index(
	          integer,
	          utf16_string,
	          10,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 10 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_integer_copy_from_utf16_string_with_index(
	          NULL,
	          utf16_string,
	          10,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

	result = libfvalue_integer_copy_from_utf16_string_with_index(
	          integer,
	          NULL,
	          10,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

/* Tests the libfvalue_integer_copy_to_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_copy_to_utf16_string_with_index(
     void )
{
	uint16_t expected_utf16_string[ 11 ] = {
		'0', 'x', '1', '2', '3', '4', '5', '6', '7', '8', 0 };
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	size_t string_index          = 0;
	int result                   = 0;

	/* Initialize test
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

	result = libfvalue_integer_copy_from_integer(
	          integer,
	          (uint64_t) 0x12345678UL,
	          32,
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

	result = libfvalue_integer_copy_to_utf16_string_with_index(
	          integer,
	          utf16_string,
	          32,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 11 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string,
	          utf16_string,
	          sizeof( uint16_t ) * 11 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_integer_copy_to_utf16_string_with_index(
	          NULL,
	          utf16_string,
	          32,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

	result = libfvalue_integer_copy_to_utf16_string_with_index(
	          integer,
	          NULL,
	          32,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

/* Tests the libfvalue_integer_copy_from_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_copy_from_utf32_string_with_index(
     void )
{
	uint32_t utf32_string[ 11 ] = {
		'0', 'x', '1', '2', '3', '4', '5', '6', '7', '8', 0 };

	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	size_t string_index          = 0;
	int result                   = 0;

	/* Initialize test
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

	result = libfvalue_integer_copy_from_byte_stream(
	          integer,
	          (uint8_t *) "\x12\x34\x56\x78",
	          4,
	          LIBFVALUE_ENDIAN_BIG,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_index = 0;

	result = libfvalue_integer_copy_from_utf32_string_with_index(
	          integer,
	          utf32_string,
	          10,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer->value",
	 integer->value,
	 (uint64_t) 0x12345678UL );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 10 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_integer_copy_from_utf32_string_with_index(
	          NULL,
	          utf32_string,
	          10,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

	result = libfvalue_integer_copy_from_utf32_string_with_index(
	          integer,
	          NULL,
	          10,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

/* Tests the libfvalue_integer_copy_to_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_integer_copy_to_utf32_string_with_index(
     void )
{
	uint32_t expected_utf32_string[ 11 ] = {
		'0', 'x', '1', '2', '3', '4', '5', '6', '7', '8', 0 };
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error     = NULL;
	libfvalue_integer_t *integer = NULL;
	size_t string_index          = 0;
	int result                   = 0;

	/* Initialize test
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

	result = libfvalue_integer_copy_from_integer(
	          integer,
	          (uint64_t) 0x12345678UL,
	          32,
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

	result = libfvalue_integer_copy_to_utf32_string_with_index(
	          integer,
	          utf32_string,
	          32,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 11 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 11 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_integer_copy_to_utf32_string_with_index(
	          NULL,
	          utf32_string,
	          32,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

	result = libfvalue_integer_copy_to_utf32_string_with_index(
	          integer,
	          NULL,
	          32,
	          &string_index,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

/* Tests the libfvalue_string_size_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_size_from_integer(
     void )
{
	libcerror_error_t *error = NULL;
	size_t string_size       = 0;
	int result               = 0;

	/* Test regular cases
	 */
	string_size = 0;

	result = libfvalue_string_size_from_integer(
	          &string_size,
	          0,
	          16,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_BOOLEAN,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 6 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_integer(
	          &string_size,
	          1,
	          16,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_BOOLEAN,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = 0;

	result = libfvalue_string_size_from_integer(
	          &string_size,
	          4890,
	          32,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#ifdef TODO
/* TODO fix test */
	string_size = 0;

	result = libfvalue_string_size_from_integer(
	          &string_size,
	          -4890,
	          32,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_SIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_size",
	 string_size,
	 (size_t) 6 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif

	string_size = 0;

	result = libfvalue_string_size_from_integer(
	          &string_size,
	          4890,
	          32,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_HEXADECIMAL,
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

	/* Test error cases
	 */
	string_size = 0;

	result = libfvalue_string_size_from_integer(
	          NULL,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_string_size_from_integer(
	          &string_size,
	          4890,
	          4,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	result = libfvalue_string_size_from_integer(
	          &string_size,
	          4890,
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
	result = libfvalue_string_size_from_integer(
	          &string_size,
	          4890,
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

/* Tests the libfvalue_utf8_string_copy_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf8_string_copy_from_integer(
     void )
{
	uint8_t expected_utf8_string[ 5 ] = {
		'4', '8', '9', '0', 0 };
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfvalue_utf8_string_copy_from_integer(
	          utf8_string,
	          32,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	          sizeof( uint8_t ) * 5 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfvalue_utf8_string_copy_from_integer(
	          NULL,
	          32,
	          4890,
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

/* Tests the libfvalue_utf8_string_with_index_copy_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf8_string_with_index_copy_from_integer(
     void )
{
	uint8_t expected_utf8_string_boolean_false[ 6 ] = {
		'f', 'a', 'l', 's', 'e', 0 };
	uint8_t expected_utf8_string_boolean_true[ 5 ] = {
		't', 'r', 'u', 'e', 0 };
	uint8_t expected_utf8_string_decimal[ 5 ] = {
		'4', '8', '9', '0', 0 };
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error = NULL;
	size_t utf8_string_index = 0;
	int result               = 0;

	/* Test regular cases
	 */
	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_integer(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          0,
	          16,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_BOOLEAN,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 6 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_boolean_false,
	          utf8_string,
	          sizeof( uint8_t ) * 6 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_integer(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          1,
	          16,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_BOOLEAN,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_boolean_true,
	          utf8_string,
	          sizeof( uint8_t ) * 5 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_integer(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_index",
	 utf8_string_index,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string_decimal,
	          utf8_string,
	          sizeof( uint8_t ) * 5 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf8_string_index = 0;

	result = libfvalue_utf8_string_with_index_copy_from_integer(
	          NULL,
	          32,
	          &utf8_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf8_string_with_index_copy_from_integer(
	          utf8_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf8_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf8_string_with_index_copy_from_integer(
	          utf8_string,
	          32,
	          NULL,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf8_string_with_index_copy_from_integer(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf8_string_with_index_copy_from_integer(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          4890,
	          4,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	result = libfvalue_utf8_string_with_index_copy_from_integer(
	          utf8_string,
	          32,
	          &utf8_string_index,
	          4890,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfvalue_utf8_string_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf8_string_copy_to_integer(
     void )
{
	uint8_t utf8_string[ 5 ] = {
		'4', '8', '9', '0', 0 };

	libcerror_error_t *error = NULL;
	uint64_t integer_value   = 0;
	int result               = 0;

	/* Test regular cases
	 */
	integer_value = 0;

	result = libfvalue_utf8_string_copy_to_integer(
	          utf8_string,
	          4,
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
	 (uint64_t) 4890 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	integer_value = 0;

	result = libfvalue_utf8_string_copy_to_integer(
	          NULL,
	          4,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
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

/* Tests the libfvalue_utf8_string_with_index_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf8_string_with_index_copy_to_integer(
     void )
{
	uint8_t utf8_string[ 5 ] = {
		'4', '8', '9', '0', 0 };
	uint8_t utf8_string_invalid[ 3 ] = {
		'/', ':', 0 };

	libcerror_error_t *error = NULL;
	uint64_t integer_value   = 0;
	size_t string_index      = 0;
	int result               = 0;

	/* Test regular cases
	 */
	string_index  = 0;
	integer_value = 0;

	result = libfvalue_utf8_string_with_index_copy_to_integer(
	          utf8_string,
	          4,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 (uint64_t) 4890 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index  = 0;
	integer_value = 0;

	result = libfvalue_utf8_string_with_index_copy_to_integer(
	          NULL,
	          4,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf8_string_with_index_copy_to_integer(
	          utf8_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf8_string_with_index_copy_to_integer(
	          utf8_string,
	          4,
	          NULL,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf8_string_with_index_copy_to_integer(
	          utf8_string,
	          4,
	          &string_index,
	          NULL,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf8_string_with_index_copy_to_integer(
	          utf8_string,
	          4,
	          &string_index,
	          &integer_value,
	          4,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported format flags
	 */
	result = libfvalue_utf8_string_with_index_copy_to_integer(
	          utf8_string,
	          4,
	          &string_index,
	          &integer_value,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with invalid input data
	 */
	result = libfvalue_utf8_string_with_index_copy_to_integer(
	          utf8_string_invalid,
	          3,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
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

/* Tests the libfvalue_utf16_string_copy_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf16_string_copy_from_integer(
     void )
{
	uint16_t expected_utf16_string[ 5 ] = {
		'4', '8', '9', '0', 0 };
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfvalue_utf16_string_copy_from_integer(
	          utf16_string,
	          32,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	          sizeof( uint16_t ) * 5 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfvalue_utf16_string_copy_from_integer(
	          NULL,
	          32,
	          4890,
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

/* Tests the libfvalue_utf16_string_with_index_copy_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf16_string_with_index_copy_from_integer(
     void )
{
	uint16_t expected_utf16_string_boolean_false[ 6 ] = {
		'f', 'a', 'l', 's', 'e', 0 };
	uint16_t expected_utf16_string_boolean_true[ 5 ] = {
		't', 'r', 'u', 'e', 0 };
	uint16_t expected_utf16_string_decimal[ 5 ] = {
		'4', '8', '9', '0', 0 };
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error  = NULL;
	size_t utf16_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_integer(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          0,
	          16,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_BOOLEAN,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 6 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_boolean_false,
	          utf16_string,
	          sizeof( uint16_t ) * 6 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_integer(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          1,
	          16,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_BOOLEAN,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_boolean_true,
	          utf16_string,
	          sizeof( uint16_t ) * 5 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_integer(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_index",
	 utf16_string_index,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string_decimal,
	          utf16_string,
	          sizeof( uint16_t ) * 5 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf16_string_index = 0;

	result = libfvalue_utf16_string_with_index_copy_from_integer(
	          NULL,
	          32,
	          &utf16_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf16_string_with_index_copy_from_integer(
	          utf16_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf16_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf16_string_with_index_copy_from_integer(
	          utf16_string,
	          32,
	          NULL,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf16_string_with_index_copy_from_integer(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf16_string_with_index_copy_from_integer(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          4890,
	          4,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	result = libfvalue_utf16_string_with_index_copy_from_integer(
	          utf16_string,
	          32,
	          &utf16_string_index,
	          4890,
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
	uint16_t utf16_string[ 5 ] = {
		'4', '8', '9', '0', 0 };

	libcerror_error_t *error = NULL;
	uint64_t integer_value   = 0;
	int result               = 0;

	/* Test regular cases
	 */
	integer_value = 0;

	result = libfvalue_utf16_string_copy_to_integer(
	          utf16_string,
	          4,
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
	 (uint64_t) 4890 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	integer_value = 0;

	result = libfvalue_utf16_string_copy_to_integer(
	          NULL,
	          4,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
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

/* Tests the libfvalue_utf16_string_with_index_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf16_string_with_index_copy_to_integer(
     void )
{
	uint16_t utf16_string[ 5 ] = {
		'4', '8', '9', '0', 0 };
	uint16_t utf16_string_invalid[ 3 ] = {
		'/', ':', 0 };

	libcerror_error_t *error = NULL;
	uint64_t integer_value   = 0;
	size_t string_index      = 0;
	int result               = 0;

	/* Test regular cases
	 */
	string_index  = 0;
	integer_value = 0;

	result = libfvalue_utf16_string_with_index_copy_to_integer(
	          utf16_string,
	          4,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 (uint64_t) 4890 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index  = 0;
	integer_value = 0;

	result = libfvalue_utf16_string_with_index_copy_to_integer(
	          NULL,
	          4,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf16_string_with_index_copy_to_integer(
	          utf16_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf16_string_with_index_copy_to_integer(
	          utf16_string,
	          4,
	          NULL,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf16_string_with_index_copy_to_integer(
	          utf16_string,
	          4,
	          &string_index,
	          NULL,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf16_string_with_index_copy_to_integer(
	          utf16_string,
	          4,
	          &string_index,
	          &integer_value,
	          4,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported format flags
	 */
	result = libfvalue_utf16_string_with_index_copy_to_integer(
	          utf16_string,
	          4,
	          &string_index,
	          &integer_value,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with invalid input data
	 */
	result = libfvalue_utf16_string_with_index_copy_to_integer(
	          utf16_string_invalid,
	          3,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
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

/* Tests the libfvalue_utf32_string_copy_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf32_string_copy_from_integer(
     void )
{
	uint32_t expected_utf32_string[ 5 ] = {
		'4', '8', '9', '0', 0 };
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfvalue_utf32_string_copy_from_integer(
	          utf32_string,
	          32,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	          sizeof( uint32_t ) * 5 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfvalue_utf32_string_copy_from_integer(
	          NULL,
	          32,
	          4890,
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

/* Tests the libfvalue_utf32_string_with_index_copy_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf32_string_with_index_copy_from_integer(
     void )
{
	uint32_t expected_utf32_string_boolean_false[ 6 ] = {
		'f', 'a', 'l', 's', 'e', 0 };
	uint32_t expected_utf32_string_boolean_true[ 5 ] = {
		't', 'r', 'u', 'e', 0 };
	uint32_t expected_utf32_string_decimal[ 5 ] = {
		'4', '8', '9', '0', 0 };
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error  = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test regular cases
	 */
	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_integer(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          0,
	          16,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_BOOLEAN,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 6 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_boolean_false,
	          utf32_string,
	          sizeof( uint32_t ) * 6 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_integer(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          1,
	          16,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_BOOLEAN,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_boolean_true,
	          utf32_string,
	          sizeof( uint32_t ) * 5 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_integer(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "utf32_string_index",
	 utf32_string_index,
	 (size_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string_decimal,
	          utf32_string,
	          sizeof( uint32_t ) * 5 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	utf32_string_index = 0;

	result = libfvalue_utf32_string_with_index_copy_from_integer(
	          NULL,
	          32,
	          &utf32_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf32_string_with_index_copy_from_integer(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &utf32_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf32_string_with_index_copy_from_integer(
	          utf32_string,
	          32,
	          NULL,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf32_string_with_index_copy_from_integer(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          4890,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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

	result = libfvalue_utf32_string_with_index_copy_from_integer(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          4890,
	          4,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	result = libfvalue_utf32_string_with_index_copy_from_integer(
	          utf32_string,
	          32,
	          &utf32_string_index,
	          4890,
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
	uint32_t utf32_string[ 5 ] = {
		'4', '8', '9', '0', 0 };

	libcerror_error_t *error = NULL;
	uint64_t integer_value   = 0;
	int result               = 0;

	/* Test regular cases
	 */
	integer_value = 0;

	result = libfvalue_utf32_string_copy_to_integer(
	          utf32_string,
	          4,
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
	 (uint64_t) 4890 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	integer_value = 0;

	result = libfvalue_utf32_string_copy_to_integer(
	          NULL,
	          4,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
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

/* Tests the libfvalue_utf32_string_with_index_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_utf32_string_with_index_copy_to_integer(
     void )
{
	uint32_t utf32_string[ 5 ] = {
		'4', '8', '9', '0', 0 };
	uint32_t utf32_string_invalid[ 3 ] = {
		'/', ':', 0 };

	libcerror_error_t *error = NULL;
	uint64_t integer_value   = 0;
	size_t string_index      = 0;
	int result               = 0;

	/* Test regular cases
	 */
	string_index  = 0;
	integer_value = 0;

	result = libfvalue_utf32_string_with_index_copy_to_integer(
	          utf32_string,
	          4,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 4 );

	FVALUE_TEST_ASSERT_EQUAL_UINT64(
	 "integer_value",
	 integer_value,
	 (uint64_t) 4890 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index  = 0;
	integer_value = 0;

	result = libfvalue_utf32_string_with_index_copy_to_integer(
	          NULL,
	          4,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf32_string_with_index_copy_to_integer(
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf32_string_with_index_copy_to_integer(
	          utf32_string,
	          4,
	          NULL,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf32_string_with_index_copy_to_integer(
	          utf32_string,
	          4,
	          &string_index,
	          NULL,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_utf32_string_with_index_copy_to_integer(
	          utf32_string,
	          4,
	          &string_index,
	          &integer_value,
	          4,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with unsupported format flags
	 */
	result = libfvalue_utf32_string_with_index_copy_to_integer(
	          utf32_string,
	          4,
	          &string_index,
	          &integer_value,
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
	 "integer_value",
	 integer_value,
	 (uint64_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with invalid input data
	 */
	result = libfvalue_utf32_string_with_index_copy_to_integer(
	          utf32_string_invalid,
	          3,
	          &string_index,
	          &integer_value,
	          64,
	          LIBFVALUE_INTEGER_FORMAT_TYPE_DECIMAL | LIBFVALUE_INTEGER_FORMAT_FLAG_UNSIGNED,
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
	 "integer_value",
	 integer_value,
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
	 "libfvalue_integer_initialize",
	 fvalue_test_integer_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_free",
	 fvalue_test_integer_free );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_clone",
	 fvalue_test_integer_clone );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_copy_from_byte_stream",
	 fvalue_test_integer_copy_from_byte_stream );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_copy_from_integer",
	 fvalue_test_integer_copy_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_copy_to_integer",
	 fvalue_test_integer_copy_to_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_get_string_size",
	 fvalue_test_integer_get_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_copy_from_utf8_string_with_index",
	 fvalue_test_integer_copy_from_utf8_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_copy_to_utf8_string_with_index",
	 fvalue_test_integer_copy_to_utf8_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_copy_from_utf16_string_with_index",
	 fvalue_test_integer_copy_from_utf16_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_copy_to_utf16_string_with_index",
	 fvalue_test_integer_copy_to_utf16_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_copy_from_utf32_string_with_index",
	 fvalue_test_integer_copy_from_utf32_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_integer_copy_to_utf32_string_with_index",
	 fvalue_test_integer_copy_to_utf32_string_with_index );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	FVALUE_TEST_RUN(
	 "libfvalue_string_size_from_integer",
	 fvalue_test_string_size_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf8_string_copy_from_integer",
	 fvalue_test_utf8_string_copy_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf8_string_with_index_copy_from_integer",
	 fvalue_test_utf8_string_with_index_copy_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf8_string_copy_to_integer",
	 fvalue_test_utf8_string_copy_to_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf8_string_with_index_copy_to_integer",
	 fvalue_test_utf8_string_with_index_copy_to_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf16_string_copy_from_integer",
	 fvalue_test_utf16_string_copy_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf16_string_with_index_copy_from_integer",
	 fvalue_test_utf16_string_with_index_copy_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf16_string_copy_to_integer",
	 fvalue_test_utf16_string_copy_to_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf16_string_with_index_copy_to_integer",
	 fvalue_test_utf16_string_with_index_copy_to_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf32_string_copy_from_integer",
	 fvalue_test_utf32_string_copy_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf32_string_with_index_copy_from_integer",
	 fvalue_test_utf32_string_with_index_copy_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf32_string_copy_to_integer",
	 fvalue_test_utf32_string_copy_to_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_utf32_string_with_index_copy_to_integer",
	 fvalue_test_utf32_string_with_index_copy_to_integer );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

