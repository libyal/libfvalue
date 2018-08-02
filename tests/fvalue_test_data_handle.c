/*
 * Library data_handle type test program
 *
 * Copyright (C) 2010-2018, Joachim Metz <joachim.metz@gmail.com>
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

#include "../libfvalue/libfvalue_data_handle.h"

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

	/* Test libfvalue_data_handle_clone with malloc failing
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

	/* Test libfvalue_data_handle_clone with memcpy failing
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
	result = libfvalue_data_handle_get_number_of_value_entries(
	          data_handle,
	          &number_of_value_entries,
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
	result = libfvalue_data_handle_get_number_of_value_entries(
	          NULL,
	          &number_of_value_entries,
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

	result = libfvalue_data_handle_get_number_of_value_entries(
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

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
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
	 "libfvalue_data_handle_free",
	 fvalue_test_data_handle_free );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_clear",
	 fvalue_test_data_handle_clear );

	FVALUE_TEST_RUN(
	 "libfvalue_data_handle_clone",
	 fvalue_test_data_handle_clone );

	/* TODO: add tests for libfvalue_data_handle_get_data */

	/* TODO: add tests for libfvalue_data_handle_set_data */

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

	/* TODO: add tests for libfvalue_data_handle_append_value_entry */

	/* TODO: add tests for libfvalue_data_handle_get_value_entry_data */

	/* TODO: add tests for libfvalue_data_handle_set_value_entry_data */

	/* TODO: add tests for libfvalue_data_handle_append_value_entry_data */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

