/*
 * Library value testing program
 *
 * Copyright (c) 2010-2014, Joachim Metz <joachim.metz@gmail.com>
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

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include <stdio.h>

#include "fvalue_test_libfvalue.h"
#include "fvalue_test_libcerror.h"
#include "fvalue_test_libcstring.h"
#include "fvalue_test_unused.h"

/* Tests initializing the value
 * Make sure the value value is referencing, is set to NULL
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fvalue_test_value_initialize(
     libfvalue_value_t **value,
     int value_type,
     int expected_result )
{
	libcerror_error_t *error = NULL;
	static char *function    = "fvalue_test_value_initialize";
	int result               = 0;

	fprintf(
	 stdout,
	 "Testing initialize\t" );

	result = libfvalue_value_type_initialize(
	          value,
	          value_type,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create value.",
		 function );
	}
	if( result != expected_result )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );
	}
	fprintf(
	 stdout,
	 "\n" );

	if( result == -1 )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( result == 1 )
	{
		if( libfvalue_value_free(
		     value,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free value.",
			 function );

			libcerror_error_backtrace_fprint(
			 error,
			 stdout );

			libcerror_error_free(
			 &error );

			return( -1 );
		}
	}
	if( result != expected_result )
	{
		return( 0 );
	}
	return( 1 );
}

/* Tests the signed 64-bit integer type
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fvalue_test_value_integer_64bit(
     const uint8_t *value_data,
     size_t value_data_size,
     int encoding,
     uint64_t expected_integer_64bit )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	static char *function    = "fvalue_test_value_integer_64bit";
	uint64_t integer_64bit   = 0;
	int result               = -1;

	value = NULL;

	if( libfvalue_value_type_initialize(
	     &value,
	     LIBFVALUE_VALUE_TYPE_INTEGER_64BIT,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create value.",
		 function );

		goto on_error;
	}
	if( libfvalue_value_set_data(
	     value,
	     value_data,
	     value_data_size,
	     LIBFVALUE_ENDIAN_LITTLE,
	     LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set value data.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing 64-bit integer value set data\t" );

	if( libfvalue_value_copy_to_64bit(
	     value,
	     0,
	     &integer_64bit,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
		 "%s: unable to copy value to 64-bit integer.",
		 function );

		goto on_error;
	}
	if( integer_64bit != expected_integer_64bit )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );

		result = 0;
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );

		result = 1;
	}
	fprintf(
	 stdout,
	 "\n" );

	if( libfvalue_value_free(
	     &value,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to free value.",
		 function );

		goto on_error;
	}
	return( result );

on_error:
	if( error != NULL )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( -1 );
}

/* Tests the UTF-8 string type
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fvalue_test_value_utf8_string(
     const uint8_t *value_data,
     size_t value_data_size,
     int encoding,
     const uint8_t *expected_utf8_string,
     size_t expected_utf8_string_size )
{
	uint8_t utf8_string[ 128 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	static char *function    = "fvalue_test_value_utf8_string";
	size_t utf8_string_size  = 0;
	int result               = -1;

	value = NULL;

	if( libfvalue_value_type_initialize(
	     &value,
	     LIBFVALUE_VALUE_TYPE_STRING_UTF8,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create value.",
		 function );

		goto on_error;
	}
	if( libfvalue_value_set_data(
	     value,
	     value_data,
	     value_data_size,
	     encoding,
	     LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set value data.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing UTF-8 string value set data\t" );

	if( libfvalue_value_get_utf8_string_size(
	     value,
	     0,
	     &utf8_string_size,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve UTF-8 string size.",
		 function );

		goto on_error;
	}
	if( ( expected_utf8_string_size < 128 )
	 && ( utf8_string_size == expected_utf8_string_size ) )
	{
		if( libfvalue_value_copy_to_utf8_string(
		     value,
		     0,
		     utf8_string,
		     128,
		     &error ) != 1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy value to UTF-8 string.",
			 function );

			goto on_error;
		}
		result = memory_compare(
		          expected_utf8_string,
		          utf8_string,
		          expected_utf8_string_size );
	}
	if( result != 0 )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );

		result = 0;
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );

		result = 1;
	}
	fprintf(
	 stdout,
	 "\n" );

	if( libfvalue_value_free(
	     &value,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to free value.",
		 function );

		goto on_error;
	}
	return( result );

on_error:
	if( error != NULL )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( -1 );
}

/* Tests the UTF-16 string type
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fvalue_test_value_utf16_string(
     const uint8_t *value_data,
     size_t value_data_size,
     int encoding,
     const uint16_t *expected_utf16_string,
     size_t expected_utf16_string_size )
{
	uint16_t utf16_string[ 128 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	static char *function    = "fvalue_test_value_utf16_string";
	size_t utf16_string_size = 0;
	int result               = -1;

	value = NULL;

	if( libfvalue_value_type_initialize(
	     &value,
	     LIBFVALUE_VALUE_TYPE_STRING_UTF16,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create value.",
		 function );

		goto on_error;
	}
	if( libfvalue_value_set_data(
	     value,
	     value_data,
	     value_data_size,
	     encoding,
	     LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set value data.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing UTF-16 string value set data\t" );

	if( libfvalue_value_get_utf16_string_size(
	     value,
	     0,
	     &utf16_string_size,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve UTF-16 string size.",
		 function );

		goto on_error;
	}
	if( ( expected_utf16_string_size < 128 )
	 && ( utf16_string_size == expected_utf16_string_size ) )
	{
		if( libfvalue_value_copy_to_utf16_string(
		     value,
		     0,
		     utf16_string,
		     128,
		     &error ) != 1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy value to UTF-16 string.",
			 function );

			goto on_error;
		}
		result = memory_compare(
		          expected_utf16_string,
		          utf16_string,
		          expected_utf16_string_size );
	}
	if( result != 0 )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );

		result = 0;
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );

		result = 1;
	}
	fprintf(
	 stdout,
	 "\n" );

	if( libfvalue_value_free(
	     &value,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to free value.",
		 function );

		goto on_error;
	}
	return( result );

on_error:
	if( error != NULL )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( -1 );
}

/* Tests the UTF-32 string type
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fvalue_test_value_utf32_string(
     const uint8_t *value_data,
     size_t value_data_size,
     int encoding,
     const uint32_t *expected_utf32_string,
     size_t expected_utf32_string_size )
{
	uint32_t utf32_string[ 128 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	static char *function    = "fvalue_test_value_utf32_string";
	size_t utf32_string_size = 0;
	int result               = -1;

	value = NULL;

	if( libfvalue_value_type_initialize(
	     &value,
	     LIBFVALUE_VALUE_TYPE_STRING_UTF32,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create value.",
		 function );

		goto on_error;
	}
	if( libfvalue_value_set_data(
	     value,
	     value_data,
	     value_data_size,
	     encoding,
	     LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set value data.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing UTF-32 string value set data\t" );

	if( libfvalue_value_get_utf32_string_size(
	     value,
	     0,
	     &utf32_string_size,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve UTF-32 string size.",
		 function );

		goto on_error;
	}
	if( ( expected_utf32_string_size < 128 )
	 && ( utf32_string_size == expected_utf32_string_size ) )
	{
		if( libfvalue_value_copy_to_utf32_string(
		     value,
		     0,
		     utf32_string,
		     128,
		     &error ) != 1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy value to UTF-32 string.",
			 function );

			goto on_error;
		}
		result = memory_compare(
		          expected_utf32_string,
		          utf32_string,
		          expected_utf32_string_size );
	}
	if( result != 0 )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );

		result = 0;
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );

		result = 1;
	}
	fprintf(
	 stdout,
	 "\n" );

	if( libfvalue_value_free(
	     &value,
	     &error ) != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to free value.",
		 function );

		goto on_error;
	}
	return( result );

on_error:
	if( error != NULL )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( value != NULL )
	{
		libfvalue_value_free(
		 &value,
		 NULL );
	}
	return( -1 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain( int argc, wchar_t * const argv[] FVALUE_TEST_ATTRIBUTE_UNUSED )
#else
int main( int argc, char * const argv[] FVALUE_TEST_ATTRIBUTE_UNUSED )
#endif
{
	uint32_t utf32_string[ 16 ] = {
		'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 0xe1, ' ', 't', 'e', 's', 't', '.', 0 };
	uint16_t utf16_string[ 16 ] = {
		'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 0xe1, ' ', 't', 'e', 's', 't', '.', 0 };

	uint8_t int8_data1[ 1 ] = { 0x00 };
	uint8_t int8_data2[ 1 ] = { 0x01 };
	uint8_t int8_data3[ 1 ] = { 0x7f };
	uint8_t int8_data4[ 1 ] = { 0xff };
	uint8_t int8_data5[ 1 ] = { 0x81 };
	uint8_t int8_data6[ 1 ] = { 0x80 };

	uint8_t utf32be_stream[ 64 ] = {
		0, 0, 0, 'T', 0, 0, 0, 'h', 0, 0, 0, 'i', 0, 0, 0, 's', 0, 0, 0, ' ',
		0, 0, 0, 'i', 0, 0, 0, 's', 0, 0, 0, ' ', 0, 0, 0, 0xe1, 0, 0, 0, ' ',
		0, 0, 0, 't', 0, 0, 0, 'e', 0, 0, 0, 's', 0, 0, 0, 't', 0, 0, 0, '.', 0, 0, 0, 0 };
	uint8_t utf16le_stream[ 32 ] = {
		'T', 0, 'h', 0, 'i', 0, 's', 0, ' ', 0, 'i', 0, 's', 0, ' ', 0, 0xe1, 0, ' ', 0,
		't', 0, 'e', 0, 's', 0, 't', 0, '.', 0, 0 };
	uint8_t utf8_string[ 17 ] = {
		'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 0xc3, 0xa1, ' ', 't', 'e', 's', 't', '.', 0 };

	libfvalue_value_t *value = NULL;

	FVALUE_TEST_UNREFERENCED_PARAMETER( argv )

	if( argc != 1 )
	{
		fprintf(
		 stderr,
		 "Unsupported number of arguments.\n" );

		return( EXIT_FAILURE );
	}
	/* Initialization tests
	 */
	value = NULL;

	if( fvalue_test_value_initialize(
	     &value,
	     LIBFVALUE_VALUE_TYPE_STRING_UTF8,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	value = (libfvalue_value_t *) 0x12345678UL;

	if( fvalue_test_value_initialize(
	     &value,
	     LIBFVALUE_VALUE_TYPE_STRING_UTF8,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	if( fvalue_test_value_initialize(
	     NULL,
	     LIBFVALUE_VALUE_TYPE_STRING_UTF8,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	value = NULL;

	if( fvalue_test_value_initialize(
	     &value,
	     -1,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	/* Test: 64-bit integer value
	 */
	if( fvalue_test_value_integer_64bit(
	     int8_data1,
	     1,
	     LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN,
	     (uint64_t) 0 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test 64-bit integer value from 8-bit value.\n" );

		return( EXIT_FAILURE );
	}
	if( fvalue_test_value_integer_64bit(
	     int8_data2,
	     1,
	     LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN,
	     (uint64_t) 1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test 64-bit integer value from 8-bit value.\n" );

		return( EXIT_FAILURE );
	}
	if( fvalue_test_value_integer_64bit(
	     int8_data3,
	     1,
	     LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN,
	     (uint64_t) 127 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test 64-bit integer value from 8-bit value.\n" );

		return( EXIT_FAILURE );
	}
	if( fvalue_test_value_integer_64bit(
	     int8_data4,
	     1,
	     LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN,
	     (uint64_t) 255 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test 64-bit integer value from 8-bit value.\n" );

		return( EXIT_FAILURE );
	}
	if( fvalue_test_value_integer_64bit(
	     int8_data5,
	     1,
	     LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN,
	     (uint64_t) 129 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test 64-bit integer value from 8-bit value.\n" );

		return( EXIT_FAILURE );
	}
	if( fvalue_test_value_integer_64bit(
	     int8_data6,
	     1,
	     LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN,
	     (uint64_t) 128 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test 64-bit integer value from 8-bit value.\n" );

		return( EXIT_FAILURE );
	}

	/* Test: UTF-8 string value
	 */
	if( fvalue_test_value_utf8_string(
	     utf16le_stream,
	     32,
	     LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN,
	     utf8_string,
	     17 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test UTF-8 string value from UTF-16 little-endian stream.\n" );

		return( EXIT_FAILURE );
	}
	if( fvalue_test_value_utf8_string(
	     utf32be_stream,
	     64,
	     LIBFVALUE_CODEPAGE_UTF32_BIG_ENDIAN,
	     utf8_string,
	     17 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test UTF-8 string value from UTF-32 big-endian stream.\n" );

		return( EXIT_FAILURE );
	}
	/* Test: UTF-16 string value
	 */
	if( fvalue_test_value_utf16_string(
	     utf8_string,
	     17,
	     LIBFVALUE_CODEPAGE_UTF8,
	     utf16_string,
	     16 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test UTF-16 string value from UTF-8 stream.\n" );

		return( EXIT_FAILURE );
	}
	if( fvalue_test_value_utf16_string(
	     utf32be_stream,
	     64,
	     LIBFVALUE_CODEPAGE_UTF32_BIG_ENDIAN,
	     utf16_string,
	     16 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test UTF-16 string value from UTF-32 big-endian stream.\n" );

		return( EXIT_FAILURE );
	}
	/* Test: UTF-32 string value
	 */
	if( fvalue_test_value_utf32_string(
	     utf8_string,
	     17,
	     LIBFVALUE_CODEPAGE_UTF8,
	     utf32_string,
	     16 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test UTF-32 string value from UTF-8 stream.\n" );

		return( EXIT_FAILURE );
	}
	if( fvalue_test_value_utf32_string(
	     utf16le_stream,
	     32,
	     LIBFVALUE_CODEPAGE_UTF16_LITTLE_ENDIAN,
	     utf32_string,
	     16 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test UTF-32 string value from UTF-16 little-endian stream.\n" );

		return( EXIT_FAILURE );
	}
	return( EXIT_SUCCESS );
}

