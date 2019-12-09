/*
 * Library table type test program
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
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fvalue_test_libcerror.h"
#include "fvalue_test_libfvalue.h"
#include "fvalue_test_macros.h"
#include "fvalue_test_memory.h"
#include "fvalue_test_unused.h"

#include "../libfvalue/libfvalue_table.h"

/* Tests the libfvalue_table_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_table_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libfvalue_table_t *table        = NULL;
	int result                      = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests = 2;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libfvalue_table_initialize(
	          &table,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "table",
	 table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_table_free(
	          &table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "table",
	 table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_table_initialize(
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

	table = (libfvalue_table_t *) 0x12345678UL;

	result = libfvalue_table_initialize(
	          &table,
	          0,
	          &error );

	table = NULL;

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
		/* Test libfvalue_table_initialize with malloc failing
		 */
		fvalue_test_malloc_attempts_before_fail = test_number;

		result = libfvalue_table_initialize(
		          &table,
		          0,
		          &error );

		if( fvalue_test_malloc_attempts_before_fail != -1 )
		{
			fvalue_test_malloc_attempts_before_fail = -1;

			if( table != NULL )
			{
				libfvalue_table_free(
				 &table,
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
			 "table",
			 table );

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
		/* Test libfvalue_table_initialize with memset failing
		 */
		fvalue_test_memset_attempts_before_fail = test_number;

		result = libfvalue_table_initialize(
		          &table,
		          0,
		          &error );

		if( fvalue_test_memset_attempts_before_fail != -1 )
		{
			fvalue_test_memset_attempts_before_fail = -1;

			if( table != NULL )
			{
				libfvalue_table_free(
				 &table,
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
			 "table",
			 table );

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
	if( table != NULL )
	{
		libfvalue_table_free(
		 &table,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_table_free function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_table_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvalue_table_free(
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

/* Tests the libfvalue_table_empty function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_table_empty(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_table_t *table = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_table_initialize(
	          &table,
	          10,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "table",
	 table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libfvalue_test_table_empty
	 */
	result = libfvalue_table_empty(
	          table,
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
	result = libfvalue_table_empty(
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
	result = libfvalue_table_free(
	          &table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "table",
	 table );

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
	if( table != NULL )
	{
		libfvalue_table_free(
		 &table,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_table_resize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_table_resize(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_table_t *table = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_table_initialize(
	          &table,
	          10,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "table",
	 table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libfvalue_table_resize to resize to a larger number of entries
	 */
	result = libfvalue_table_resize(
	          table,
	          35,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libfvalue_table_resize to resize to a smaller number of entries
	 */
	result = libfvalue_table_resize(
	          table,
	          4,
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
	result = libfvalue_table_resize(
	          NULL,
	          10,
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

	result = libfvalue_table_resize(
	          table,
	          -10,
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

#if INT_MAX == SSIZE_MAX

	result = libfvalue_table_resize(
	          table,
	          INT_MAX,
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

#endif /* INT_MAX == SSIZE_MAX */

	/* Clean up
	 */
	result = libfvalue_table_free(
	          &table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "table",
	 table );

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
	if( table != NULL )
	{
		libfvalue_table_free(
		 &table,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_table_clone function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_table_clone(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_table_t *destination_table = NULL;
	libfvalue_table_t *source_table      = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_table_initialize(
	          &source_table,
	          10,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "source_table",
	 source_table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_table_clone(
	          &destination_table,
	          source_table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "destination_table",
	 destination_table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_table_free(
	          &destination_table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_table",
	 destination_table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_table_clone(
	          &destination_table,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_table",
	 destination_table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_table_clone(
	          NULL,
	          source_table,
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

	destination_table = (libfvalue_table_t *) 0x12345678UL;

	result = libfvalue_table_clone(
	          &destination_table,
	          source_table,
	          &error );

	destination_table = NULL;

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

	/* Test libfvalue_table_clone with malloc failing
	 */
	fvalue_test_malloc_attempts_before_fail = 0;

	result = libfvalue_table_clone(
	          &destination_table,
	          source_table,
	          &error );

	if( fvalue_test_malloc_attempts_before_fail != -1 )
	{
		fvalue_test_malloc_attempts_before_fail = -1;

		if( destination_table != NULL )
		{
			libfvalue_table_free(
			 &destination_table,
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
		 "destination_table",
		 destination_table );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfvalue_table_clone with malloc failing in libcdata_array_clone
	 */
	fvalue_test_malloc_attempts_before_fail = 1;

	result = libfvalue_table_clone(
	          &destination_table,
	          source_table,
	          &error );

	if( fvalue_test_malloc_attempts_before_fail != -1 )
	{
		fvalue_test_malloc_attempts_before_fail = -1;

		if( destination_table != NULL )
		{
			libfvalue_table_free(
			 &destination_table,
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
		 "destination_table",
		 destination_table );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfvalue_table_clone with memset failing
	 */
	fvalue_test_memset_attempts_before_fail = 0;

	result = libfvalue_table_clone(
	          &destination_table,
	          source_table,
	          &error );

	if( fvalue_test_memset_attempts_before_fail != -1 )
	{
		fvalue_test_memset_attempts_before_fail = -1;

		if( destination_table != NULL )
		{
			libfvalue_table_free(
			 &destination_table,
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
		 "destination_table",
		 destination_table );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FVALUE_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libfvalue_table_free(
	          &source_table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "source_table",
	 source_table );

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
	if( destination_table != NULL )
	{
		libfvalue_table_free(
		 &destination_table,
		 NULL );
	}
	if( source_table != NULL )
	{
		libfvalue_table_free(
		 &source_table,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_table_get_number_of_values function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_table_get_number_of_values(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_table_t *table = NULL;
	int number_of_values     = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_table_initialize(
	          &table,
	          10,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "table",
	 table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_table_get_number_of_values(
	          table,
	          &number_of_values,
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
	result = libfvalue_table_get_number_of_values(
	          NULL,
	          &number_of_values,
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

	result = libfvalue_table_get_number_of_values(
	          table,
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
	result = libfvalue_table_free(
	          &table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "table",
	 table );

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
	if( table != NULL )
	{
		libfvalue_table_free(
		 &table,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_table_get_index_by_identifier function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_table_get_index_by_identifier(
     void )
{
	uint8_t value_identifier[ 5 ] = { 't', 'e', 's', 't', 0 };
	libcerror_error_t *error      = NULL;
	libfvalue_table_t *table      = NULL;
	int result                    = 0;
	int value_index               = 0;

	/* Initialize test
	 */
	result = libfvalue_table_initialize(
	          &table,
	          10,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "table",
	 table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
#ifdef TODO
/* TODO set table value with identifier */
	result = libfvalue_table_get_index_by_identifier(
	          table,
	          value_identifier,
	          5,
	          &value_index,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif

	/* Test error cases
	 */
	result = libfvalue_table_get_index_by_identifier(
	          NULL,
	          value_identifier,
	          5,
	          &value_index,
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

	result = libfvalue_table_get_index_by_identifier(
	          table,
	          NULL,
	          5,
	          &value_index,
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

	result = libfvalue_table_get_index_by_identifier(
	          table,
	          value_identifier,
	          0,
	          &value_index,
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

	result = libfvalue_table_get_index_by_identifier(
	          table,
	          value_identifier,
	          (size_t) SSIZE_MAX + 1,
	          &value_index,
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

	result = libfvalue_table_get_index_by_identifier(
	          table,
	          value_identifier,
	          5,
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

	result = libfvalue_table_get_index_by_identifier(
	          table,
	          value_identifier,
	          5,
	          &value_index,
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

	/* Clean up
	 */
	result = libfvalue_table_free(
	          &table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "table",
	 table );

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
	if( table != NULL )
	{
		libfvalue_table_free(
		 &table,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_table_get_value_by_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_table_get_value_by_index(
     void )
{
	libcerror_error_t *error          = NULL;
	libfvalue_table_t *table          = NULL;
	libfvalue_value_t *value_by_index = 0;
	int result                        = 0;

	/* Initialize test
	 */
	result = libfvalue_table_initialize(
	          &table,
	          10,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "table",
	 table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
#ifdef TODO
/* TODO fix test
 */
	result = libfvalue_table_get_value_by_index(
	          table,
	          0,
	          &value_by_index,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "value_by_index",
	 value_by_index );

	result = libfvalue_value_free(
	          &value_by_index,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif

	/* Test error cases
	 */
	result = libfvalue_table_get_value_by_index(
	          NULL,
	          0,
	          &value_by_index,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_by_index",
	 value_by_index );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_table_get_value_by_index(
	          table,
	          -1,
	          &value_by_index,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_by_index",
	 value_by_index );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_table_get_value_by_index(
	          table,
	          0,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "value_by_index",
	 value_by_index );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfvalue_table_free(
	          &table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "table",
	 table );

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
	if( table != NULL )
	{
		libfvalue_table_free(
		 &table,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_table_get_value_by_identifier function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_table_get_value_by_identifier(
     void )
{
	uint8_t value_identifier[ 5 ] = { 't', 'e', 's', 't', 0 };
	libcerror_error_t *error      = NULL;
	libfvalue_table_t *table      = NULL;
	libfvalue_value_t *value      = NULL;
	int result                    = 0;

	/* Initialize test
	 */
	result = libfvalue_table_initialize(
	          &table,
	          10,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "table",
	 table );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
#ifdef TODO
/* TODO set table value with identifier */
	result = libfvalue_table_get_value_by_identifier(
	          table,
	          value_identifier,
	          5,
	          &value,
	          0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif

	/* Test error cases
	 */
	result = libfvalue_table_get_value_by_identifier(
	          NULL,
	          value_identifier,
	          5,
	          &value,
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

	result = libfvalue_table_get_value_by_identifier(
	          table,
	          NULL,
	          5,
	          &value,
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

	result = libfvalue_table_get_value_by_identifier(
	          table,
	          value_identifier,
	          5,
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
	result = libfvalue_table_free(
	          &table,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "table",
	 table );

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
	if( table != NULL )
	{
		libfvalue_table_free(
		 &table,
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
	 "libfvalue_table_initialize",
	 fvalue_test_table_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_table_free",
	 fvalue_test_table_free );

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

	/* TODO: add tests for libfvalue_table_free_as_value */

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	FVALUE_TEST_RUN(
	 "libfvalue_table_empty",
	 fvalue_test_table_empty );

	FVALUE_TEST_RUN(
	 "libfvalue_table_resize",
	 fvalue_test_table_resize );

	FVALUE_TEST_RUN(
	 "libfvalue_table_clone",
	 fvalue_test_table_clone );

	FVALUE_TEST_RUN(
	 "libfvalue_table_get_number_of_values",
	 fvalue_test_table_get_number_of_values );

	FVALUE_TEST_RUN(
	 "libfvalue_table_get_index_by_identifier",
	 fvalue_test_table_get_index_by_identifier );

	FVALUE_TEST_RUN(
	 "libfvalue_table_get_value_by_index",
	 fvalue_test_table_get_value_by_index );

	FVALUE_TEST_RUN(
	 "libfvalue_table_get_value_by_identifier",
	 fvalue_test_table_get_value_by_identifier );

	/* TODO: add tests for libfvalue_table_set_value_by_index */

	/* TODO: add tests for libfvalue_table_set_value */

	/* TODO: add tests for libfvalue_table_copy_from_utf8_xml_string */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

