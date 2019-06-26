/*
 * Library value type test program
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
#include "fvalue_test_libfdatetime.h"
#include "fvalue_test_libfguid.h"
#include "fvalue_test_libfvalue.h"
#include "fvalue_test_libfwnt.h"
#include "fvalue_test_macros.h"
#include "fvalue_test_memory.h"
#include "fvalue_test_unused.h"

#include "../libfvalue/libfvalue_value_type.h"

/* Tests the libfvalue_value_type_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_type_initialize(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfvalue_value_type_initialize(
	          &value,
	          LIBFVALUE_VALUE_TYPE_BINARY_DATA,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_free(
	          &value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_value_type_initialize(
	          NULL,
	          LIBFVALUE_VALUE_TYPE_BINARY_DATA,
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
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_value_type_initialize_with_data_handle function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_type_initialize_with_data_handle(
     void )
{
	/* TODO add support for LIBFVALUE_VALUE_TYPE_ENUMERATION
	 * TODO fix support for LIBFVALUE_VALUE_TYPE_HFSTIME
	 * TODO fix support for LIBFVALUE_VALUE_TYPE_NT_SECURITY_IDENTIFIER
	 */
	int value_types[ ] = {
		LIBFVALUE_VALUE_TYPE_FLOATING_POINT_32BIT,
		LIBFVALUE_VALUE_TYPE_NULL,
		LIBFVALUE_VALUE_TYPE_BINARY_DATA,
		LIBFVALUE_VALUE_TYPE_BOOLEAN,
		/* LIBFVALUE_VALUE_TYPE_ENUMERATION, */
		LIBFVALUE_VALUE_TYPE_INTEGER_8BIT,
		LIBFVALUE_VALUE_TYPE_UNSIGNED_INTEGER_8BIT,
		LIBFVALUE_VALUE_TYPE_INTEGER_16BIT,
		LIBFVALUE_VALUE_TYPE_UNSIGNED_INTEGER_16BIT,
		LIBFVALUE_VALUE_TYPE_INTEGER_32BIT,
		LIBFVALUE_VALUE_TYPE_UNSIGNED_INTEGER_32BIT,
		LIBFVALUE_VALUE_TYPE_INTEGER_64BIT,
		LIBFVALUE_VALUE_TYPE_UNSIGNED_INTEGER_64BIT,
		LIBFVALUE_VALUE_TYPE_FLOATING_POINT_32BIT,
		LIBFVALUE_VALUE_TYPE_FLOATING_POINT_64BIT,
		LIBFVALUE_VALUE_TYPE_STRING_BYTE_STREAM,
		LIBFVALUE_VALUE_TYPE_STRING_UTF8,
		LIBFVALUE_VALUE_TYPE_STRING_UTF16,
		LIBFVALUE_VALUE_TYPE_STRING_UTF32,

#if defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME )
		LIBFVALUE_VALUE_TYPE_FAT_DATE_TIME,
		LIBFVALUE_VALUE_TYPE_FILETIME,
		LIBFVALUE_VALUE_TYPE_FLOATINGTIME,
		/* LIBFVALUE_VALUE_TYPE_HFSTIME, */
		LIBFVALUE_VALUE_TYPE_NSF_TIMEDATE,
		LIBFVALUE_VALUE_TYPE_POSIX_TIME,
		LIBFVALUE_VALUE_TYPE_SYSTEMTIME,
#endif

#if defined( HAVE_LIBFGUID_H ) || defined( HAVE_LOCAL_LIBFGUID )
		LIBFVALUE_VALUE_TYPE_GUID,
#endif

#if defined( HAVE_LIBFWNT_H ) || defined( HAVE_LOCAL_LIBFWNT )
		/* LIBFVALUE_VALUE_TYPE_NT_SECURITY_IDENTIFIER, */
#endif
		-1 };

	libcerror_error_t *error        = NULL;
	libfvalue_value_t *value        = NULL;
	int result                      = 0;
	int value_type_index            = 0;
	int value_type                  = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	value_type = value_types[ value_type_index++ ];

	while( value_type != -1 )
	{
		result = libfvalue_value_type_initialize_with_data_handle(
		          &value,
		          value_type,
		          NULL,
		          0,
		          &error );

		FVALUE_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "value",
		 value );

		FVALUE_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libfvalue_value_free(
		          &value,
		          &error );

		FVALUE_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		FVALUE_TEST_ASSERT_IS_NULL(
		 "value",
		 value );

		FVALUE_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		value_type = value_types[ value_type_index++ ];
	}
	/* Test error cases
	 */
	result = libfvalue_value_type_initialize_with_data_handle(
	          NULL,
	          LIBFVALUE_VALUE_TYPE_BINARY_DATA,
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

	value = (libfvalue_value_t *) 0x12345678UL;

	result = libfvalue_value_type_initialize_with_data_handle(
	          &value,
	          LIBFVALUE_VALUE_TYPE_BINARY_DATA,
	          NULL,
	          0,
	          &error );

	value = NULL;

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_value_type_initialize_with_data_handle(
	          &value,
	          -1,
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

#if defined( HAVE_FVALUE_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfvalue_value_initialize with malloc failing
		 */
		fvalue_test_malloc_attempts_before_fail = test_number;

		result = libfvalue_value_type_initialize_with_data_handle(
		          &value,
		          LIBFVALUE_VALUE_TYPE_BINARY_DATA,
		          NULL,
		          0,
		          &error );

		if( fvalue_test_malloc_attempts_before_fail != -1 )
		{
			fvalue_test_malloc_attempts_before_fail = -1;

			if( value != NULL )
			{
				libfvalue_value_free(
				 &value,
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
			 "value",
			 value );

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
		/* Test libfvalue_value_initialize with memset failing
		 */
		fvalue_test_memset_attempts_before_fail = test_number;

		result = libfvalue_value_type_initialize_with_data_handle(
		          &value,
		          LIBFVALUE_VALUE_TYPE_BINARY_DATA,
		          NULL,
		          0,
		          &error );

		if( fvalue_test_memset_attempts_before_fail != -1 )
		{
			fvalue_test_memset_attempts_before_fail = -1;

			if( value != NULL )
			{
				libfvalue_value_free(
				 &value,
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
			 "value",
			 value );

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
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

/* Tests the libfvalue_value_type_get_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_type_get_string_size(
     void )
{
	uint8_t binary_data[ 5 ] = {
		't', 'e', 's', 't', 0 };
	uint8_t utf16_data[ 10 ] = {
		't', 0, 'e', 0, 's', 0, 't', 0, 0, 0 };
	uint8_t utf32_data[ 20 ] = {
		't', 0, 0, 0, 'e', 0, 0, 0, 's', 0, 0, 0, 't', 0, 0, 0, 0, 0, 0, 0 };

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	ssize_t string_size      = 0;
	int result               = 0;

/* TODO test with LIBFVALUE_VALUE_TYPE_STRING_BYTE_STREAM */

	/* Initialize test
	 */
	result = libfvalue_value_type_initialize(
	          &value,
	          LIBFVALUE_VALUE_TYPE_STRING_UTF8,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_size = libfvalue_value_type_get_string_size(
	               value,
	               binary_data,
	               5,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) 5 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = libfvalue_value_type_get_string_size(
	               value,
	               NULL,
	               5,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_size = libfvalue_value_type_get_string_size(
	               NULL,
	               binary_data,
	               5,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	string_size = libfvalue_value_type_get_string_size(
	               value,
	               binary_data,
	               (size_t) SSIZE_MAX + 1,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_value_free(
	          &value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libfvalue_value_type_initialize(
	          &value,
	          LIBFVALUE_VALUE_TYPE_STRING_UTF16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_size = libfvalue_value_type_get_string_size(
	               value,
	               utf16_data,
	               10,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) 10 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_size = libfvalue_value_type_get_string_size(
	               value,
	               utf16_data,
	               0,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (size_t) -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_value_free(
	          &value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libfvalue_value_type_initialize(
	          &value,
	          LIBFVALUE_VALUE_TYPE_STRING_UTF32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_size = libfvalue_value_type_get_string_size(
	               value,
	               utf32_data,
	               20,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (size_t) 20 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_size = libfvalue_value_type_get_string_size(
	               value,
	               utf16_data,
	               0,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (size_t) -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_value_free(
	          &value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test with unsupported value type
	 */
	result = libfvalue_value_type_initialize(
	          &value,
	          LIBFVALUE_VALUE_TYPE_INTEGER_8BIT,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	string_size = libfvalue_value_type_get_string_size(
	               value,
	               binary_data,
	               5,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_value_free(
	          &value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value",
	 value );

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
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

/* Tests the libfvalue_value_type_set_data_string function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_type_set_data_string(
     void )
{
	uint8_t utf16_data[ 10 ] = {
		't', 0, 'e', 0, 's', 0, 't', 0, 0, 0 };

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	ssize_t string_size      = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_type_initialize(
	          &value,
	          LIBFVALUE_VALUE_TYPE_STRING_UTF16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_size = libfvalue_value_type_set_data_string(
	               value,
	               utf16_data,
	               10,
	               0,
	               LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) 10 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_size = libfvalue_value_type_set_data_string(
	               NULL,
	               utf16_data,
	               10,
	               0,
	               LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_value_free(
	          &value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value",
	 value );

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
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_value_type_append_data_string function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_type_append_data_string(
     void )
{
	uint8_t utf16_data[ 10 ] = {
		't', 0, 'e', 0, 's', 0, 't', 0, 0, 0 };

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	ssize_t string_size      = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_type_initialize(
	          &value,
	          LIBFVALUE_VALUE_TYPE_STRING_UTF16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_size = libfvalue_value_type_append_data_string(
	               value,
	               utf16_data,
	               10,
	               0,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) 10 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_size = libfvalue_value_type_append_data_string(
	               NULL,
	               utf16_data,
	               10,
	               0,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_value_free(
	          &value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value",
	 value );

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
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_value_type_set_data_strings_array function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_type_set_data_strings_array(
     void )
{
	uint8_t utf16_data[ 10 ] = {
		't', 0, 'e', 0, 's', 0, 't', 0, 0, 0 };

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	ssize_t string_size      = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_type_initialize(
	          &value,
	          LIBFVALUE_VALUE_TYPE_STRING_UTF16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	string_size = libfvalue_value_type_set_data_strings_array(
	               value,
	               utf16_data,
	               10,
	               0,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) 10 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	string_size = libfvalue_value_type_set_data_strings_array(
	               NULL,
	               utf16_data,
	               10,
	               0,
	               &error );

	FVALUE_TEST_ASSERT_EQUAL_SSIZE(
	 "string_size",
	 string_size,
	 (ssize_t) -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_value_free(
	          &value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value",
	 value );

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
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )
#if defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME )

/* Tests the libfvalue_value_type_posix_time_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_type_posix_time_copy_from_byte_stream(
     void )
{
	uint8_t byte_stream_32bit[ 4 ] = {
		0x90, 0x6d, 0x12, 0x5d };

	uint8_t byte_stream_64bit[ 8 ] = {
		0x00, 0x84, 0x4a, 0x70, 0x2a, 0x8c, 0x05, 0x00 };

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_type_initialize(
	          &value,
	          LIBFVALUE_VALUE_TYPE_STRING_UTF16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_32bit,
	          4,
	          LIBFVALUE_POSIX_TIME_ENCODING_SECONDS_32BIT_SIGNED | LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_32bit,
	          4,
	          LIBFVALUE_POSIX_TIME_ENCODING_SECONDS_32BIT_UNSIGNED | LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_64bit,
	          8,
	          LIBFVALUE_POSIX_TIME_ENCODING_SECONDS_64BIT_SIGNED | LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_64bit,
	          8,
	          LIBFVALUE_POSIX_TIME_ENCODING_SECONDS_64BIT_UNSIGNED | LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_64bit,
	          8,
	          LIBFVALUE_POSIX_TIME_ENCODING_MICRO_SECONDS_64BIT_SIGNED | LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_64bit,
	          8,
	          LIBFVALUE_POSIX_TIME_ENCODING_MICRO_SECONDS_64BIT_UNSIGNED | LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_64bit,
	          8,
	          LIBFVALUE_POSIX_TIME_ENCODING_NANO_SECONDS_64BIT_SIGNED | LIBFVALUE_ENDIAN_LITTLE,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_64bit,
	          8,
	          LIBFVALUE_POSIX_TIME_ENCODING_NANO_SECONDS_64BIT_UNSIGNED | LIBFVALUE_ENDIAN_LITTLE,
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
	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          NULL,
	          byte_stream_32bit,
	          4,
	          LIBFVALUE_POSIX_TIME_ENCODING_SECONDS_32BIT_SIGNED | LIBFVALUE_ENDIAN_LITTLE,
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

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          NULL,
	          4,
	          LIBFVALUE_POSIX_TIME_ENCODING_SECONDS_32BIT_SIGNED | LIBFVALUE_ENDIAN_LITTLE,
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

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_32bit,
	          (size_t) SSIZE_MAX + 1,
	          LIBFVALUE_POSIX_TIME_ENCODING_SECONDS_32BIT_SIGNED | LIBFVALUE_ENDIAN_LITTLE,
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

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_32bit,
	          4,
	          LIBFVALUE_POSIX_TIME_ENCODING_SECONDS_32BIT_SIGNED,
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

	result = libfvalue_value_type_posix_time_copy_from_byte_stream(
	          value,
	          byte_stream_32bit,
	          4,
	          0xffffff00UL | LIBFVALUE_ENDIAN_LITTLE,
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
	result = libfvalue_value_free(
	          &value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value",
	 value );

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
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME ) */
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

	FVALUE_TEST_RUN(
	 "libfvalue_value_type_initialize",
	 fvalue_test_value_type_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_value_type_initialize_with_data_handle",
	 fvalue_test_value_type_initialize_with_data_handle );

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

	FVALUE_TEST_RUN(
	 "libfvalue_value_type_get_string_size",
	 fvalue_test_value_type_get_string_size );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	FVALUE_TEST_RUN(
	 "libfvalue_value_type_set_data_string",
	 fvalue_test_value_type_set_data_string );

	FVALUE_TEST_RUN(
	 "libfvalue_value_type_append_data_string",
	 fvalue_test_value_type_append_data_string );

	FVALUE_TEST_RUN(
	 "libfvalue_value_type_set_data_strings_array",
	 fvalue_test_value_type_set_data_strings_array );

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )
#if defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME )

	FVALUE_TEST_RUN(
	 "libfvalue_value_type_posix_time_copy_from_byte_stream",
	 fvalue_test_value_type_posix_time_copy_from_byte_stream );

#endif /* defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME ) */
#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

