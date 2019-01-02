/*
 * Library string type test program
 *
 * Copyright (C) 2010-2019, Joachim Metz <joachim.metz@gmail.com>
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

#include "../libfvalue/libfvalue_string.h"

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

/* Tests the libfvalue_string_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libfvalue_string_t *string      = NULL;
	int result                      = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_string_initialize(
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

	string = (libfvalue_string_t *) 0x12345678UL;

	result = libfvalue_string_initialize(
	          &string,
	          &error );

	string = NULL;

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
		/* Test libfvalue_string_initialize with malloc failing
		 */
		fvalue_test_malloc_attempts_before_fail = test_number;

		result = libfvalue_string_initialize(
		          &string,
		          &error );

		if( fvalue_test_malloc_attempts_before_fail != -1 )
		{
			fvalue_test_malloc_attempts_before_fail = -1;

			if( string != NULL )
			{
				libfvalue_string_free(
				 &string,
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
			 "string",
			 string );

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
		/* Test libfvalue_string_initialize with memset failing
		 */
		fvalue_test_memset_attempts_before_fail = test_number;

		result = libfvalue_string_initialize(
		          &string,
		          &error );

		if( fvalue_test_memset_attempts_before_fail != -1 )
		{
			fvalue_test_memset_attempts_before_fail = -1;

			if( string != NULL )
			{
				libfvalue_string_free(
				 &string,
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
			 "string",
			 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_free function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvalue_string_free(
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

/* Tests the libfvalue_string_clone function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_clone(
     void )
{
	libcerror_error_t *error               = NULL;
	libfvalue_string_t *destination_string = NULL;
	libfvalue_string_t *source_string      = NULL;
	int result                             = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &source_string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "source_string",
	 source_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_string_clone(
	          &destination_string,
	          source_string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "destination_string",
	 destination_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_string_free(
	          &destination_string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_string",
	 destination_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_string_clone(
	          &destination_string,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_string",
	 destination_string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_string_clone(
	          NULL,
	          source_string,
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

	destination_string = (libfvalue_string_t *) 0x12345678UL;

	result = libfvalue_string_clone(
	          &destination_string,
	          source_string,
	          &error );

	destination_string = NULL;

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

	/* Test libfvalue_string_clone with malloc failing
	 */
	fvalue_test_malloc_attempts_before_fail = 0;

	result = libfvalue_string_clone(
	          &destination_string,
	          source_string,
	          &error );

	if( fvalue_test_malloc_attempts_before_fail != -1 )
	{
		fvalue_test_malloc_attempts_before_fail = -1;

		if( destination_string != NULL )
		{
			libfvalue_string_free(
			 &destination_string,
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
		 "destination_string",
		 destination_string );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}

	/* Test libfvalue_string_clone with memcpy failing
	 */
	fvalue_test_memcpy_attempts_before_fail = 0;

	result = libfvalue_string_clone(
	          &destination_string,
	          source_string,
	          &error );

	if( fvalue_test_memcpy_attempts_before_fail != -1 )
	{
		fvalue_test_memcpy_attempts_before_fail = -1;

		if( destination_string != NULL )
		{
			libfvalue_string_free(
			 &destination_string,
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
		 "destination_string",
		 destination_string );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FVALUE_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libfvalue_string_free(
	          &source_string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "source_string",
	 source_string );

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
	if( destination_string != NULL )
	{
		libfvalue_string_free(
		 &destination_string,
		 NULL );
	}
	if( source_string != NULL )
	{
		libfvalue_string_free(
		 &source_string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          (uint8_t *) "12345678",
	          9,
	          LIBFVALUE_CODEPAGE_ASCII,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string->data",
	 string->data );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_string_copy_from_byte_stream(
	          NULL,
	          (uint8_t *) "12345678",
	          9,
	          LIBFVALUE_CODEPAGE_ASCII,
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

	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          NULL,
	          9,
	          LIBFVALUE_CODEPAGE_ASCII,
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

	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          (uint8_t *) "12345678",
	          (size_t) SSIZE_MAX + 1,
	          LIBFVALUE_CODEPAGE_ASCII,
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

	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          (uint8_t *) "12345678",
	          9,
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
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_copy_from_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_copy_from_utf8_string_with_index(
     void )
{
	uint8_t utf8_string[ 9 ] = {
		'1', '2', '3', '4', '5', '6', '7', '8', 0 };

	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	size_t string_index        = 0;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          (uint8_t *) "12345678",
	          9,
	          LIBFVALUE_CODEPAGE_ASCII,
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

	string->codepage = LIBFVALUE_CODEPAGE_UTF16_BIG_ENDIAN;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF32_BIG_ENDIAN;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF32_LITTLE_ENDIAN;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF7;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF8;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_ASCII;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_ASCII;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          NULL,
	          utf8_string,
	          9,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          NULL,
	          0,
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

	string_index = 9;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_index = 0;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
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

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string->codepage = LIBFVALUE_CODEPAGE_1200_MIXED;

	result = libfvalue_string_copy_from_utf8_string_with_index(
	          string,
	          utf8_string,
	          9,
	          &string_index,
	          0,
	          &error );

	string->codepage = LIBFVALUE_CODEPAGE_ASCII;

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
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_get_utf8_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_get_utf8_string_size(
     void )
{
	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	size_t utf8_string_size    = 0;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_string_get_utf8_string_size(
	          string,
	          &utf8_string_size,
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
	result = libfvalue_string_get_utf8_string_size(
	          NULL,
	          &utf8_string_size,
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

	result = libfvalue_string_get_utf8_string_size(
	          string,
	          NULL,
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

	result = libfvalue_string_get_utf8_string_size(
	          string,
	          &utf8_string_size,
	          0xffffffffUL,
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
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_copy_to_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_copy_to_utf8_string_with_index(
     void )
{
	uint8_t expected_utf8_string[ 9 ] = {
		'1', '2', '3', '4', '5', '6', '7', '8', 0 };
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	size_t string_index        = 0;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          (uint8_t *) "12345678",
	          9,
	          LIBFVALUE_CODEPAGE_ASCII,
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

	result = libfvalue_string_copy_to_utf8_string_with_index(
	          string,
	          utf8_string,
	          32,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf8_string,
	          utf8_string,
	          sizeof( uint8_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_string_copy_to_utf8_string_with_index(
	          NULL,
	          utf8_string,
	          32,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_to_utf8_string_with_index(
	          string,
	          NULL,
	          32,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_to_utf8_string_with_index(
	          string,
	          NULL,
	          32,
	          &string_index,
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

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_copy_from_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_copy_from_utf16_string_with_index(
     void )
{
	uint16_t utf16_string[ 9 ] = {
		'1', '2', '3', '4', '5', '6', '7', '8', 0 };

	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	size_t string_index        = 0;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          (uint8_t *) "12345678",
	          9,
	          LIBFVALUE_CODEPAGE_ASCII,
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

	string->codepage = LIBFVALUE_CODEPAGE_UTF16_BIG_ENDIAN;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF32_BIG_ENDIAN;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF32_LITTLE_ENDIAN;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF7;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF8;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_ASCII;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_ASCII;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          NULL,
	          utf16_string,
	          9,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          NULL,
	          0,
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

	string_index = 9;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_index = 0;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
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

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string->codepage = LIBFVALUE_CODEPAGE_1200_MIXED;

	result = libfvalue_string_copy_from_utf16_string_with_index(
	          string,
	          utf16_string,
	          9,
	          &string_index,
	          0,
	          &error );

	string->codepage = LIBFVALUE_CODEPAGE_ASCII;

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
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_get_utf16_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_get_utf16_string_size(
     void )
{
	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	size_t utf16_string_size   = 0;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_string_get_utf16_string_size(
	          string,
	          &utf16_string_size,
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
	result = libfvalue_string_get_utf16_string_size(
	          NULL,
	          &utf16_string_size,
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

	result = libfvalue_string_get_utf16_string_size(
	          string,
	          NULL,
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

	result = libfvalue_string_get_utf16_string_size(
	          string,
	          &utf16_string_size,
	          0xffffffffUL,
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
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_copy_to_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_copy_to_utf16_string_with_index(
     void )
{
	uint16_t expected_utf16_string[ 9 ] = {
		'1', '2', '3', '4', '5', '6', '7', '8', 0 };
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	size_t string_index        = 0;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          (uint8_t *) "12345678",
	          9,
	          LIBFVALUE_CODEPAGE_ASCII,
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

	result = libfvalue_string_copy_to_utf16_string_with_index(
	          string,
	          utf16_string,
	          32,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf16_string,
	          utf16_string,
	          sizeof( uint16_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_string_copy_to_utf16_string_with_index(
	          NULL,
	          utf16_string,
	          32,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_to_utf16_string_with_index(
	          string,
	          NULL,
	          32,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_to_utf16_string_with_index(
	          string,
	          NULL,
	          32,
	          &string_index,
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

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_copy_from_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_copy_from_utf32_string_with_index(
     void )
{
	uint32_t utf32_string[ 9 ] = {
		'1', '2', '3', '4', '5', '6', '7', '8', 0 };

	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	size_t string_index        = 0;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          (uint8_t *) "12345678",
	          9,
	          LIBFVALUE_CODEPAGE_ASCII,
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

	string->codepage = LIBFVALUE_CODEPAGE_UTF16_BIG_ENDIAN;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF32_BIG_ENDIAN;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF32_LITTLE_ENDIAN;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF7;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_UTF8;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_ASCII;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_index = 0;

	string->codepage = LIBFVALUE_CODEPAGE_ASCII;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          NULL,
	          utf32_string,
	          9,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          NULL,
	          0,
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

	string_index = 9;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_index = 0;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
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

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string->codepage = LIBFVALUE_CODEPAGE_1200_MIXED;

	result = libfvalue_string_copy_from_utf32_string_with_index(
	          string,
	          utf32_string,
	          9,
	          &string_index,
	          0,
	          &error );

	string->codepage = LIBFVALUE_CODEPAGE_ASCII;

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
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_get_utf32_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_get_utf32_string_size(
     void )
{
	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	size_t utf32_string_size   = 0;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_string_get_utf32_string_size(
	          string,
	          &utf32_string_size,
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
	result = libfvalue_string_get_utf32_string_size(
	          NULL,
	          &utf32_string_size,
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

	result = libfvalue_string_get_utf32_string_size(
	          string,
	          NULL,
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

	result = libfvalue_string_get_utf32_string_size(
	          string,
	          &utf32_string_size,
	          0xffffffffUL,
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
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_string_copy_to_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_string_copy_to_utf32_string_with_index(
     void )
{
	uint32_t expected_utf32_string[ 9 ] = {
		'1', '2', '3', '4', '5', '6', '7', '8', 0 };
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error   = NULL;
	libfvalue_string_t *string = NULL;
	size_t string_index        = 0;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_string_initialize(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "string",
	 string );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_string_copy_from_byte_stream(
	          string,
	          (uint8_t *) "12345678",
	          9,
	          LIBFVALUE_CODEPAGE_ASCII,
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

	result = libfvalue_string_copy_to_utf32_string_with_index(
	          string,
	          utf32_string,
	          32,
	          &string_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "string_index",
	 string_index,
	 (size_t) 9 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          expected_utf32_string,
	          utf32_string,
	          sizeof( uint32_t ) * 9 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_string_copy_to_utf32_string_with_index(
	          NULL,
	          utf32_string,
	          32,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_to_utf32_string_with_index(
	          string,
	          NULL,
	          32,
	          &string_index,
	          0,
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

	result = libfvalue_string_copy_to_utf32_string_with_index(
	          string,
	          NULL,
	          32,
	          &string_index,
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

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_string_free(
	          &string,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "string",
	 string );

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
	if( string != NULL )
	{
		libfvalue_string_free(
		 &string,
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
	 "libfvalue_string_initialize",
	 fvalue_test_string_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_string_free",
	 fvalue_test_string_free );

	FVALUE_TEST_RUN(
	 "libfvalue_string_clone",
	 fvalue_test_string_clone );

	FVALUE_TEST_RUN(
	 "libfvalue_string_copy_from_byte_stream",
	 fvalue_test_string_copy_from_byte_stream );

	FVALUE_TEST_RUN(
	 "libfvalue_string_copy_from_utf8_string_with_index",
	 fvalue_test_string_copy_from_utf8_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_string_get_utf8_string_size",
	 fvalue_test_string_get_utf8_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_string_copy_to_utf8_string_with_index",
	 fvalue_test_string_copy_to_utf8_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_string_copy_from_utf16_string_with_index",
	 fvalue_test_string_copy_from_utf16_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_string_get_utf16_string_size",
	 fvalue_test_string_get_utf16_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_string_copy_to_utf16_string_with_index",
	 fvalue_test_string_copy_to_utf16_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_string_copy_from_utf32_string_with_index",
	 fvalue_test_string_copy_from_utf32_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_string_get_utf32_string_size",
	 fvalue_test_string_get_utf32_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_string_copy_to_utf32_string_with_index",
	 fvalue_test_string_copy_to_utf32_string_with_index );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	/* TODO: add tests for libfvalue_utf8_string_split */

	/* TODO: add tests for libfvalue_utf16_string_split */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

