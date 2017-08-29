/*
 * Library value_entry type test program
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

#include "../libfvalue/libfvalue_value_entry.h"

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

/* Tests the libfvalue_value_entry_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_entry_initialize(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_value_entry_t *value_entry = NULL;
	int result                           = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests      = 1;
	int number_of_memset_fail_tests      = 1;
	int test_number                      = 0;
#endif

	/* Test regular cases
	 */
	result = libfvalue_value_entry_initialize(
	          &value_entry,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value_entry",
	 value_entry );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_entry_free(
	          &value_entry,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_entry",
	 value_entry );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_value_entry_initialize(
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

	value_entry = (libfvalue_value_entry_t *) 0x12345678UL;

	result = libfvalue_value_entry_initialize(
	          &value_entry,
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

	value_entry = NULL;

#if defined( HAVE_FVALUE_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfvalue_value_entry_initialize with malloc failing
		 */
		fvalue_test_malloc_attempts_before_fail = test_number;

		result = libfvalue_value_entry_initialize(
		          &value_entry,
		          &error );

		if( fvalue_test_malloc_attempts_before_fail != -1 )
		{
			fvalue_test_malloc_attempts_before_fail = -1;

			if( value_entry != NULL )
			{
				libfvalue_value_entry_free(
				 &value_entry,
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
			 "value_entry",
			 value_entry );

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
		/* Test libfvalue_value_entry_initialize with memset failing
		 */
		fvalue_test_memset_attempts_before_fail = test_number;

		result = libfvalue_value_entry_initialize(
		          &value_entry,
		          &error );

		if( fvalue_test_memset_attempts_before_fail != -1 )
		{
			fvalue_test_memset_attempts_before_fail = -1;

			if( value_entry != NULL )
			{
				libfvalue_value_entry_free(
				 &value_entry,
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
			 "value_entry",
			 value_entry );

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
	if( value_entry != NULL )
	{
		libfvalue_value_entry_free(
		 &value_entry,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_value_entry_free function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_entry_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvalue_value_entry_free(
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

/* Tests the libfvalue_value_entry_clone function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_entry_clone(
     void )
{
	libcerror_error_t *error                         = NULL;
	libfvalue_value_entry_t *destination_value_entry = NULL;
	libfvalue_value_entry_t *source_value_entry      = NULL;
	int result                                       = 0;

	/* Initialize test
	 */
	result = libfvalue_value_entry_initialize(
	          &source_value_entry,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "source_value_entry",
	 source_value_entry );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_value_entry_clone(
	          &destination_value_entry,
	          source_value_entry,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "destination_value_entry",
	 destination_value_entry );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_entry_free(
	          &destination_value_entry,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_value_entry",
	 destination_value_entry );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_entry_clone(
	          &destination_value_entry,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_value_entry",
	 destination_value_entry );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_value_entry_clone(
	          NULL,
	          source_value_entry,
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
	result = libfvalue_value_entry_free(
	          &source_value_entry,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "source_value_entry",
	 source_value_entry );

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
	if( destination_value_entry != NULL )
	{
		libfvalue_value_entry_free(
		 &destination_value_entry,
		 NULL );
	}
	if( source_value_entry != NULL )
	{
		libfvalue_value_entry_free(
		 &source_value_entry,
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
	 "libfvalue_value_entry_initialize",
	 fvalue_test_value_entry_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_value_entry_free",
	 fvalue_test_value_entry_free );

	FVALUE_TEST_RUN(
	 "libfvalue_value_entry_clone",
	 fvalue_test_value_entry_clone );

#endif /* #if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

