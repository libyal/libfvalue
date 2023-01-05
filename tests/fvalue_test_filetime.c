/*
 * Library filetime type test program
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
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fvalue_test_libcerror.h"
#include "fvalue_test_libfdatetime.h"
#include "fvalue_test_libfvalue.h"
#include "fvalue_test_macros.h"
#include "fvalue_test_unused.h"

#include "../libfvalue/libfvalue_filetime.h"

#if defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME )

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

/* Tests the libfvalue_filetime_copy_from_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_filetime_copy_from_integer(
     void )
{
	libcerror_error_t *error          = NULL;
	libfdatetime_filetime_t *filetime = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libfdatetime_filetime_initialize(
	          &filetime,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "filetime",
	 filetime );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_filetime_copy_from_integer(
	          filetime,
	          0x01cb3a623d0a17ceUL,
	          64,
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
	result = libfvalue_filetime_copy_from_integer(
	          NULL,
	          0x01cb3a623d0a17ceUL,
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

	result = libfvalue_filetime_copy_from_integer(
	          filetime,
	          0x01cb3a623d0a17ceUL,
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
	result = libfdatetime_filetime_free(
	          &filetime,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "filetime",
	 filetime );

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
	if( filetime != NULL )
	{
		libfdatetime_filetime_free(
		 &filetime,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_filetime_copy_to_integer function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_filetime_copy_to_integer(
     void )
{
	libcerror_error_t *error          = NULL;
	libfdatetime_filetime_t *filetime = NULL;
	size_t integer_value_size         = 0;
	uint64_t integer_value            = 0;
	int result                        = 0;

	/* Initialize test
	 */
	result = libfdatetime_filetime_initialize(
	          &filetime,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "filetime",
	 filetime );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	integer_value      = 0;
	integer_value_size = 0;

	result = libfvalue_filetime_copy_to_integer(
	          filetime,
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
	 (uint64_t) 0 );

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

	result = libfvalue_filetime_copy_to_integer(
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

	result = libfvalue_filetime_copy_to_integer(
	          filetime,
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

	result = libfvalue_filetime_copy_to_integer(
	          filetime,
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
	result = libfdatetime_filetime_free(
	          &filetime,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "filetime",
	 filetime );

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
	if( filetime != NULL )
	{
		libfdatetime_filetime_free(
		 &filetime,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

#endif /* defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME ) */

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

#if defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME )

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

	FVALUE_TEST_RUN(
	 "libfvalue_filetime_copy_from_integer",
	 fvalue_test_filetime_copy_from_integer );

	FVALUE_TEST_RUN(
	 "libfvalue_filetime_copy_to_integer",
	 fvalue_test_filetime_copy_to_integer );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

#endif /* defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME ) */

	return( EXIT_SUCCESS );

#if defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME )

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

on_error:
	return( EXIT_FAILURE );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

#endif /* defined( HAVE_LIBFDATETIME_H ) || defined( HAVE_LOCAL_LIBFDATETIME ) */
}

