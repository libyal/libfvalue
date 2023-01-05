/*
 * Library data_handle type test program
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
#include "fvalue_test_libfvalue.h"
#include "fvalue_test_macros.h"
#include "fvalue_test_memory.h"
#include "fvalue_test_unused.h"

#include "../libfvalue/libfvalue_data_handle.h"

/* Tests the libfvalue_data_handle_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_initialize(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	int result                           = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests      = 1;
	int number_of_memset_fail_tests      = 1;
	int test_number                      = 0;
#endif

	/* Test regular cases
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_data_handle_initialize(
	          NULL,
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

	data_handle = (libfvalue_data_handle_t *) 0x12345678UL;

	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	data_handle = NULL;

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
		/* Test libfvalue_data_handle_initialize with malloc failing
		 */
		fvalue_test_malloc_attempts_before_fail = test_number;

		result = libfvalue_data_handle_initialize(
		          &data_handle,
		          NULL,
		          &error );

		if( fvalue_test_malloc_attempts_before_fail != -1 )
		{
			fvalue_test_malloc_attempts_before_fail = -1;

			if( data_handle != NULL )
			{
				libfvalue_data_handle_free(
				 &data_handle,
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
			 "data_handle",
			 data_handle );

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
		/* Test libfvalue_data_handle_initialize with memset failing
		 */
		fvalue_test_memset_attempts_before_fail = test_number;

		result = libfvalue_data_handle_initialize(
		          &data_handle,
		          NULL,
		          &error );

		if( fvalue_test_memset_attempts_before_fail != -1 )
		{
			fvalue_test_memset_attempts_before_fail = -1;

			if( data_handle != NULL )
			{
				libfvalue_data_handle_free(
				 &data_handle,
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
			 "data_handle",
			 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_free function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvalue_data_handle_free(
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

/* Tests the libfvalue_data_handle_clear function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_clear(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_data_handle_clear(
	          data_handle,
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
	result = libfvalue_data_handle_clear(
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

#if defined( HAVE_FVALUE_TEST_MEMORY )

	/* Test libfvalue_data_handle_clear with memset failing
	 */
	fvalue_test_memset_attempts_before_fail = 0;

	result = libfvalue_data_handle_clear(
	          data_handle,
	          &error );

	if( fvalue_test_memset_attempts_before_fail != -1 )
	{
		fvalue_test_memset_attempts_before_fail = -1;
	}
	else
	{
		FVALUE_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FVALUE_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_clone function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_clone(
     void )
{
	libcerror_error_t *error                         = NULL;
	libfvalue_data_handle_t *destination_data_handle = NULL;
	libfvalue_data_handle_t *source_data_handle      = NULL;
	int result                                       = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &source_data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "source_data_handle",
	 source_data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_data_handle_clone(
	          &destination_data_handle,
	          source_data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "destination_data_handle",
	 destination_data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_data_handle_free(
	          &destination_data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_data_handle",
	 destination_data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_data_handle_clone(
	          &destination_data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_data_handle",
	 destination_data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_data_handle_clone(
	          NULL,
	          source_data_handle,
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

	destination_data_handle = (libfvalue_data_handle_t *) 0x12345678UL;

	result = libfvalue_data_handle_clone(
	          &destination_data_handle,
	          source_data_handle,
	          &error );

	destination_data_handle = NULL;

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

	/* Test libfvalue_data_handle_clone with malloc failing in libfvalue_data_handle_initialize
	 */
	fvalue_test_malloc_attempts_before_fail = 0;

	result = libfvalue_data_handle_clone(
	          &destination_data_handle,
	          source_data_handle,
	          &error );

	if( fvalue_test_malloc_attempts_before_fail != -1 )
	{
		fvalue_test_malloc_attempts_before_fail = -1;

		if( destination_data_handle != NULL )
		{
			libfvalue_data_handle_free(
			 &destination_data_handle,
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
		 "destination_data_handle",
		 destination_data_handle );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#if defined( OPTIMIZATION_DISABLED )

	/* Test libfvalue_data_handle_clone with memcpy failing in libfvalue_data_handle_set_data
	 */
	fvalue_test_memcpy_attempts_before_fail = 0;

	result = libfvalue_data_handle_clone(
	          &destination_data_handle,
	          source_data_handle,
	          &error );

	if( fvalue_test_memcpy_attempts_before_fail != -1 )
	{
		fvalue_test_memcpy_attempts_before_fail = -1;

		if( destination_data_handle != NULL )
		{
			libfvalue_data_handle_free(
			 &destination_data_handle,
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
		 "destination_data_handle",
		 destination_data_handle );

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
	result = libfvalue_data_handle_free(
	          &source_data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "source_data_handle",
	 source_data_handle );

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
	if( destination_data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &destination_data_handle,
		 NULL );
	}
	if( source_data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &source_data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_get_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_get_data(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	uint8_t *data                        = NULL;
	size_t data_size                     = 0;
	int encoding                         = 0;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_data_handle_get_data(
	          data_handle,
	          &data,
	          &data_size,
	          &encoding,
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
	result = libfvalue_data_handle_get_data(
	          NULL,
	          &data,
	          &data_size,
	          &encoding,
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

	result = libfvalue_data_handle_get_data(
	          data_handle,
	          NULL,
	          &data_size,
	          &encoding,
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

	result = libfvalue_data_handle_get_data(
	          data_handle,
	          &data,
	          NULL,
	          &encoding,
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

	result = libfvalue_data_handle_get_data(
	          data_handle,
	          &data,
	          &data_size,
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

	/* Clean up
	 */
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_set_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_set_data(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
	          0,
	          LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_data_handle_set_data(
	          data_handle,
	          NULL,
	          0,
	          0,
	          LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
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
	result = libfvalue_data_handle_set_data(
	          NULL,
	          data,
	          32,
	          0,
	          LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
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

	result = libfvalue_data_handle_set_data(
	          data_handle,
	          NULL,
	          32,
	          0,
	          LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
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

	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          (size_t) SSIZE_MAX + 1,
	          0,
	          LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
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

	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
	          0,
	          0xff,
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

	/* Test libfvalue_data_handle_set_data with malloc failing
	 */
	fvalue_test_malloc_attempts_before_fail = 0;

	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
	          0,
	          LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
	          &error );

	if( fvalue_test_malloc_attempts_before_fail != -1 )
	{
		fvalue_test_malloc_attempts_before_fail = -1;
	}
	else
	{
		FVALUE_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#if defined( OPTIMIZATION_DISABLED )

	/* Test libfvalue_data_handle_set_data with memcpy failing
	 */
	fvalue_test_memcpy_attempts_before_fail = 0;

	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
	          0,
	          LIBFVALUE_VALUE_DATA_FLAG_MANAGED,
	          &error );

	if( fvalue_test_memcpy_attempts_before_fail != -1 )
	{
		fvalue_test_memcpy_attempts_before_fail = -1;
	}
	else
	{
		FVALUE_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

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
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_get_data_flags function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_get_data_flags(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	uint32_t data_flags                  = 0;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_data_handle_get_data_flags(
	          data_handle,
	          &data_flags,
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
	result = libfvalue_data_handle_get_data_flags(
	          NULL,
	          &data_flags,
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

	result = libfvalue_data_handle_get_data_flags(
	          data_handle,
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

	/* Clean up
	 */
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_set_data_flags function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_set_data_flags(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_data_handle_set_data_flags(
	          data_handle,
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
	result = libfvalue_data_handle_set_data_flags(
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

	/* Clean up
	 */
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_get_number_of_value_entries function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_get_number_of_value_entries(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	int number_of_value_entries          = 0;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	number_of_value_entries = 0;

	result = libfvalue_data_handle_get_number_of_value_entries(
	          data_handle,
	          &number_of_value_entries,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "number_of_value_entries",
	 number_of_value_entries,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
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

	/* Test regular cases
	 */
	number_of_value_entries = 0;

	result = libfvalue_data_handle_get_number_of_value_entries(
	          data_handle,
	          &number_of_value_entries,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "number_of_value_entries",
	 number_of_value_entries,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libfvalue_data_handle_set_value_entry(
	          data_handle,
	          0,
	          8,
	          16,
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
	number_of_value_entries = 0;

	result = libfvalue_data_handle_get_number_of_value_entries(
	          data_handle,
	          &number_of_value_entries,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "number_of_value_entries",
	 number_of_value_entries,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	number_of_value_entries = 0;

	result = libfvalue_data_handle_get_number_of_value_entries(
	          NULL,
	          &number_of_value_entries,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "number_of_value_entries",
	 number_of_value_entries,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_get_number_of_value_entries(
	          data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "number_of_value_entries",
	 number_of_value_entries,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_get_value_entry function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_get_value_entry(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	size_t value_entry_offset            = 0;
	size_t value_entry_size              = 0;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	value_entry_offset = 0;
	value_entry_size   = 0;

	result = libfvalue_data_handle_get_value_entry(
	          data_handle,
	          0,
	          &value_entry_offset,
	          &value_entry_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_offset",
	 value_entry_offset,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_size",
	 value_entry_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Initialize test
	 */
	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
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

	/* Test regular cases
	 */
	value_entry_offset = 0;
	value_entry_size   = 0;

	result = libfvalue_data_handle_get_value_entry(
	          data_handle,
	          0,
	          &value_entry_offset,
	          &value_entry_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_offset",
	 value_entry_offset,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_size",
	 value_entry_size,
	 (size_t) 32 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libfvalue_data_handle_set_value_entry(
	          data_handle,
	          0,
	          8,
	          16,
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
	value_entry_offset = 0;
	value_entry_size   = 0;

	result = libfvalue_data_handle_get_value_entry(
	          data_handle,
	          0,
	          &value_entry_offset,
	          &value_entry_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_offset",
	 value_entry_offset,
	 (size_t) 8 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_size",
	 value_entry_size,
	 (size_t) 16 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	value_entry_offset = 0;
	value_entry_size   = 0;

	result = libfvalue_data_handle_get_value_entry(
	          NULL,
	          0,
	          &value_entry_offset,
	          &value_entry_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_offset",
	 value_entry_offset,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_size",
	 value_entry_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_get_value_entry(
	          data_handle,
	          -1,
	          &value_entry_offset,
	          &value_entry_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_offset",
	 value_entry_offset,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_size",
	 value_entry_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_get_value_entry(
	          data_handle,
	          0,
	          NULL,
	          &value_entry_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_offset",
	 value_entry_offset,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_size",
	 value_entry_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_get_value_entry(
	          data_handle,
	          0,
	          &value_entry_offset,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_offset",
	 value_entry_offset,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_size",
	 value_entry_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_set_value_entry function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_set_value_entry(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_data_handle_set_value_entry(
	          data_handle,
	          0,
	          8,
	          16,
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

	/* Initialize test
	 */
	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
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

	/* Test regular cases
	 */
	result = libfvalue_data_handle_set_value_entry(
	          data_handle,
	          0,
	          8,
	          16,
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
	result = libfvalue_data_handle_set_value_entry(
	          NULL,
	          0,
	          8,
	          16,
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

	result = libfvalue_data_handle_set_value_entry(
	          data_handle,
	          -1,
	          8,
	          16,
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

	result = libfvalue_data_handle_set_value_entry(
	          data_handle,
	          0,
	          (size_t) SSIZE_MAX + 1,
	          16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	result = libfvalue_data_handle_set_value_entry(
	          data_handle,
	          0,
	          8,
	          (size_t) SSIZE_MAX + 1,
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
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_append_value_entry function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_append_value_entry(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	int result                           = 0;
	int value_entry_index                = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
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

	/* Test regular cases
	 */
	value_entry_index = 0;

	result = libfvalue_data_handle_append_value_entry(
	          data_handle,
	          &value_entry_index,
	          8,
	          16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	value_entry_index = 0;

	result = libfvalue_data_handle_append_value_entry(
	          NULL,
	          &value_entry_index,
	          8,
	          16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_append_value_entry(
	          data_handle,
	          NULL,
	          8,
	          16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_append_value_entry(
	          data_handle,
	          &value_entry_index,
	          (size_t) SSIZE_MAX + 1,
	          16,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	result = libfvalue_data_handle_append_value_entry(
	          data_handle,
	          &value_entry_index,
	          8,
	          (size_t) SSIZE_MAX + 1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_get_value_entry_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_get_value_entry_data(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	uint8_t *value_entry_data            = NULL;
	size_t value_entry_data_size         = 0;
	int encoding                         = 0;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	value_entry_data      = NULL;
	value_entry_data_size = 0;
	encoding              = 0;

	result = libfvalue_data_handle_get_value_entry_data(
	          data_handle,
	          0,
	          &value_entry_data,
	          &value_entry_data_size,
	          &encoding,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_entry_data",
	 value_entry_data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_data_size",
	 value_entry_data_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "encoding",
	 encoding,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Initialize test
	 */
	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
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

	result = libfvalue_data_handle_set_value_entry(
	          data_handle,
	          0,
	          8,
	          16,
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
	value_entry_data      = NULL;
	value_entry_data_size = 0;
	encoding              = 0;

	result = libfvalue_data_handle_get_value_entry_data(
	          data_handle,
	          0,
	          &value_entry_data,
	          &value_entry_data_size,
	          &encoding,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value_entry_data",
	 value_entry_data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_data_size",
	 value_entry_data_size,
	 (size_t) 16 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "encoding",
	 encoding,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	value_entry_data      = NULL;
	value_entry_data_size = 0;
	encoding              = 0;

	result = libfvalue_data_handle_get_value_entry_data(
	          NULL,
	          0,
	          &value_entry_data,
	          &value_entry_data_size,
	          &encoding,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_entry_data",
	 value_entry_data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_data_size",
	 value_entry_data_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "encoding",
	 encoding,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_get_value_entry_data(
	          data_handle,
	          -1,
	          &value_entry_data,
	          &value_entry_data_size,
	          &encoding,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_entry_data",
	 value_entry_data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_data_size",
	 value_entry_data_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "encoding",
	 encoding,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_get_value_entry_data(
	          data_handle,
	          0,
	          NULL,
	          &value_entry_data_size,
	          &encoding,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_entry_data",
	 value_entry_data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_data_size",
	 value_entry_data_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "encoding",
	 encoding,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_get_value_entry_data(
	          data_handle,
	          0,
	          &value_entry_data,
	          NULL,
	          &encoding,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_entry_data",
	 value_entry_data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_data_size",
	 value_entry_data_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "encoding",
	 encoding,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_get_value_entry_data(
	          data_handle,
	          0,
	          &value_entry_data,
	          &value_entry_data_size,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_entry_data",
	 value_entry_data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "value_entry_data_size",
	 value_entry_data_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "encoding",
	 encoding,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_set_value_entry_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_set_value_entry_data(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_data_handle_set_value_entry_data(
	          data_handle,
	          0,
	          data,
	          32,
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

	/* Initialize test
	 */
	result = libfvalue_data_handle_set_data(
	          data_handle,
	          data,
	          32,
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

	/* Test regular cases
	 */
	result = libfvalue_data_handle_set_value_entry_data(
	          data_handle,
	          0,
	          data,
	          32,
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
	result = libfvalue_data_handle_set_value_entry_data(
	          NULL,
	          0,
	          data,
	          32,
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

	result = libfvalue_data_handle_set_value_entry_data(
	          data_handle,
	          -1,
	          data,
	          32,
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

	result = libfvalue_data_handle_set_value_entry_data(
	          data_handle,
	          0,
	          NULL,
	          32,
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

	result = libfvalue_data_handle_set_value_entry_data(
	          data_handle,
	          0,
	          data,
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

	result = libfvalue_data_handle_set_value_entry_data(
	          data_handle,
	          0,
	          data,
	          32,
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

	/* Test value entry offset out of bounds
	 */
	result = libfvalue_data_handle_set_value_entry_data(
	          data_handle,
	          0,
	          data + 32,
	          32,
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

	/* Test value entry size out of bounds
	 */
	result = libfvalue_data_handle_set_value_entry_data(
	          data_handle,
	          0,
	          data + 16,
	          32,
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
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_data_handle_append_value_entry_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_data_handle_append_value_entry_data(
     void )
{
	uint8_t data1[ 32 ];
	uint8_t data2[ 32 ];
	uint8_t data3[ 32 ];

	libcerror_error_t *error             = NULL;
	libfvalue_data_handle_t *data_handle = NULL;
	int result                           = 0;
	int value_entry_index                = 0;

	/* Initialize test
	 */
	result = libfvalue_data_handle_initialize(
	          &data_handle,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "data_handle",
	 data_handle );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	value_entry_index = 0;

	result = libfvalue_data_handle_append_value_entry_data(
	          data_handle,
	          &value_entry_index,
	          data1,
	          32,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value_entry_index = 0;

	result = libfvalue_data_handle_append_value_entry_data(
	          data_handle,
	          &value_entry_index,
	          data2,
	          32,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	value_entry_index = 0;

	result = libfvalue_data_handle_append_value_entry_data(
	          NULL,
	          &value_entry_index,
	          data3,
	          32,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_append_value_entry_data(
	          data_handle,
	          NULL,
	          data3,
	          32,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_data_handle_append_value_entry_data(
	          data_handle,
	          &value_entry_index,
	          NULL,
	          32,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	result = libfvalue_data_handle_append_value_entry_data(
	          data_handle,
	          &value_entry_index,
	          data3,
	          (size_t) SSIZE_MAX + 1,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	result = libfvalue_data_handle_append_value_entry_data(
	          data_handle,
	          &value_entry_index,
	          data3,
	          32,
	          -1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_entry_index",
	 value_entry_index,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_data_handle_free(
	          &data_handle,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data_handle",
	 data_handle );

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
	if( data_handle != NULL )
	{
		libfvalue_data_handle_free(
		 &data_handle,
		 NULL );
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

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_initialize",
	 fvalue_test_data_handle_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_free",
	 fvalue_test_data_handle_free );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_clear",
	 fvalue_test_data_handle_clear );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_clone",
	 fvalue_test_data_handle_clone );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_get_data",
	 fvalue_test_data_handle_get_data );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_set_data",
	 fvalue_test_data_handle_set_data );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_get_data_flags",
	 fvalue_test_data_handle_get_data_flags );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_set_data_flags",
	 fvalue_test_data_handle_set_data_flags );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_get_number_of_value_entries",
	 fvalue_test_data_handle_get_number_of_value_entries );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_get_value_entry",
	 fvalue_test_data_handle_get_value_entry );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_set_value_entry",
	 fvalue_test_data_handle_set_value_entry );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_append_value_entry",
	 fvalue_test_data_handle_append_value_entry );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_get_value_entry_data",
	 fvalue_test_data_handle_get_value_entry_data );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_set_value_entry_data",
	 fvalue_test_data_handle_set_value_entry_data );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_append_value_entry_data",
	 fvalue_test_data_handle_append_value_entry_data );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

