/*
 * Library value type test program
 *
 * Copyright (C) 2010-2024, Joachim Metz <joachim.metz@gmail.com>
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

#include "../libfvalue/libfvalue_value.h"
#include "../libfvalue/libfvalue_value_type.h"

/* Tests the libfvalue_value_initialize function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libfvalue_value_t *value        = NULL;
	int result                      = 0;

#if defined( HAVE_FVALUE_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test error cases
	 */
	result = libfvalue_value_initialize(
	          NULL,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	result = libfvalue_value_initialize(
	          &value,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

		result = libfvalue_value_initialize(
		          &value,
		          "test",
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
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

		result = libfvalue_value_initialize(
		          &value,
		          "test",
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
		          NULL,
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

/* Tests the libfvalue_value_free function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfvalue_value_free(
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

/* Tests the libfvalue_value_clone function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_clone(
     void )
{
	libcerror_error_t *error             = NULL;
	libfvalue_value_t *destination_value = NULL;
	libfvalue_value_t *source_value      = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &source_value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          0,
	          &error );


	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "source_value",
	 source_value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfvalue_value_clone(
	          &destination_value,
	          source_value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "destination_value",
	 destination_value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_free(
	          &destination_value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_value",
	 destination_value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfvalue_value_clone(
	          &destination_value,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "destination_value",
	 destination_value );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfvalue_value_clone(
	          NULL,
	          source_value,
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

	destination_value = (libfvalue_value_t *) 0x12345678UL;

	result = libfvalue_value_clone(
	          &destination_value,
	          source_value,
	          &error );

	destination_value = NULL;

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

	/* Test libfvalue_value_clone with malloc failing
	 */
	fvalue_test_malloc_attempts_before_fail = 0;

	result = libfvalue_value_clone(
	          &destination_value,
	          source_value,
	          &error );

	if( fvalue_test_malloc_attempts_before_fail != -1 )
	{
		fvalue_test_malloc_attempts_before_fail = -1;

		if( destination_value != NULL )
		{
			libfvalue_value_free(
			 &destination_value,
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
		 "destination_value",
		 destination_value );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}

	/* Test libfvalue_value_clone with memcpy failing
	 */
	fvalue_test_memcpy_attempts_before_fail = 0;

	result = libfvalue_value_clone(
	          &destination_value,
	          source_value,
	          &error );

	if( fvalue_test_memcpy_attempts_before_fail != -1 )
	{
		fvalue_test_memcpy_attempts_before_fail = -1;

		if( destination_value != NULL )
		{
			libfvalue_value_free(
			 &destination_value,
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
		 "destination_value",
		 destination_value );

		FVALUE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FVALUE_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libfvalue_value_free(
	          &source_value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "source_value",
	 source_value );

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
	if( destination_value != NULL )
	{
		libfvalue_value_free(
		 &destination_value,
		 NULL );
	}
	if( source_value != NULL )
	{
		libfvalue_value_free(
		 &source_value,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfvalue_value_clear function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_clear(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_clear(
	          value,
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
	result = libfvalue_value_clear(
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

/* Tests the libfvalue_value_get_type function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_type(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;
	int value_type           = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	value_type = 0;

	result = libfvalue_value_get_type(
	          value,
	          &value_type,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_type",
	 value_type,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	value_type = 0;

	result = libfvalue_value_get_type(
	          NULL,
	          &value_type,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_type",
	 value_type,
	 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_value_get_type(
	          value,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "value_type",
	 value_type,
	 0 );

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

/* Tests the libfvalue_value_get_identifier function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_identifier(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint8_t *identifier      = NULL;
	size_t identifier_size   = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	result = libfvalue_value_set_identifier(
	          value,
	          (uint8_t *) "identifier",
	          11,
	          LIBFVALUE_VALUE_IDENTIFIER_FLAG_MANAGED,
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
	identifier      = NULL;
	identifier_size = 0;

	result = libfvalue_value_get_identifier(
	          value,
	          &identifier,
	          &identifier_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "identifier_size",
	 identifier_size,
	 (size_t) 11 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          "identifier",
	          identifier,
	          11 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	identifier      = NULL;
	identifier_size = 0;

	result = libfvalue_value_get_identifier(
	          NULL,
	          &identifier,
	          &identifier_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "identifier_size",
	 identifier_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_value_get_identifier(
	          value,
	          NULL,
	          &identifier_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "identifier_size",
	 identifier_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_value_get_identifier(
	          value,
	          &identifier,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "identifier_size",
	 identifier_size,
	 (size_t) 0 );

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

/* Tests the libfvalue_value_set_identifier function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_set_identifier(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_set_identifier(
	          value,
	          (uint8_t *) "identifier",
	          11,
	          LIBFVALUE_VALUE_IDENTIFIER_FLAG_MANAGED,
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
	result = libfvalue_value_set_identifier(
	          NULL,
	          (uint8_t *) "identifier",
	          11,
	          LIBFVALUE_VALUE_IDENTIFIER_FLAG_MANAGED,
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

	result = libfvalue_value_set_identifier(
	          value,
	          NULL,
	          11,
	          LIBFVALUE_VALUE_IDENTIFIER_FLAG_MANAGED,
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

	result = libfvalue_value_set_identifier(
	          value,
	          (uint8_t *) "identifier",
	          0,
	          LIBFVALUE_VALUE_IDENTIFIER_FLAG_MANAGED,
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

	result = libfvalue_value_set_identifier(
	          value,
	          (uint8_t *) "identifier",
	          (size_t) SSIZE_MAX + 1,
	          LIBFVALUE_VALUE_IDENTIFIER_FLAG_MANAGED,
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

	result = libfvalue_value_set_identifier(
	          value,
	          (uint8_t *) "identifier",
	          11,
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

/* Tests the libfvalue_value_get_data_flags function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_data_flags(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint32_t data_flags      = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	data_flags = 0;

	result = libfvalue_value_get_data_flags(
	          value,
	          &data_flags,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT32(
	 "data_flags",
	 data_flags,
	 (uint32_t) 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	data_flags = 0;

	result = libfvalue_value_get_data_flags(
	          NULL,
	          &data_flags,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT32(
	 "data_flags",
	 data_flags,
	 (uint32_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_value_get_data_flags(
	          value,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT32(
	 "data_flags",
	 data_flags,
	 (uint32_t) 0 );

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

/* Tests the libfvalue_value_set_data_flags function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_set_data_flags(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_set_data_flags(
	          value,
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
	result = libfvalue_value_set_data_flags(
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

/* Tests the libfvalue_value_has_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_has_data(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_has_data(
	          value,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libfvalue_value_set_data(
	          value,
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

	/* Test regular cases
	 */
	result = libfvalue_value_has_data(
	          value,
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
	result = libfvalue_value_has_data(
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

/* Tests the libfvalue_value_initialize_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_initialize_data(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_initialize_data(
	          value,
	          32,
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
	result = libfvalue_value_initialize_data(
	          NULL,
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

	result = libfvalue_value_initialize_data(
	          value,
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

	result = libfvalue_value_initialize_data(
	          value,
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

	result = libfvalue_value_initialize_data(
	          value,
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

/* Tests the libfvalue_value_get_data_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_data_size(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	size_t data_size         = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	data_size = 0;

	result = libfvalue_value_get_data_size(
	          value,
	          &data_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "data_size",
	 data_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	data_size = 0;

	result = libfvalue_value_get_data_size(
	          NULL,
	          &data_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "data_size",
	 data_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_value_get_data_size(
	          value,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "data_size",
	 data_size,
	 (size_t) 0 );

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

/* Tests the libfvalue_value_get_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_data(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint8_t *data            = NULL;
	size_t data_size         = 0;
	int encoding             = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	data      = NULL;
	data_size = 0;
	encoding  = 0;

	result = libfvalue_value_get_data(
	          value,
	          &data,
	          &data_size,
	          &encoding,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data",
	 data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "data_size",
	 data_size,
	 (size_t) 0 );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "encoding",
	 encoding,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	data      = NULL;
	data_size = 0;

	result = libfvalue_value_get_data(
	          NULL,
	          &data,
	          &data_size,
	          &encoding,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data",
	 data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "data_size",
	 data_size,
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

	result = libfvalue_value_get_data(
	          value,
	          NULL,
	          &data_size,
	          &encoding,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "data",
	 data );

	FVALUE_TEST_ASSERT_EQUAL_SIZE(
	 "data_size",
	 data_size,
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

/* Tests the libfvalue_value_set_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_set_data(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_set_data(
	          value,
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

	/* Test error cases
	 */
	result = libfvalue_value_set_data(
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

	result = libfvalue_value_set_data(
	          value,
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

/* Tests the libfvalue_value_copy_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_data(
     void )
{
	uint8_t data[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test error cases
	 */
	result = libfvalue_value_copy_data(
	          value,
	          data,
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

	/* Initialize test
	 */
	result = libfvalue_value_set_data(
	          value,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_data(
	          value,
	          data,
	          32,
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
	result = libfvalue_value_copy_data(
	          NULL,
	          data,
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

	result = libfvalue_value_copy_data(
	          value,
	          NULL,
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

	result = libfvalue_value_copy_data(
	          value,
	          data,
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

	result = libfvalue_value_copy_data(
	          value,
	          data,
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

/* Tests the libfvalue_value_get_format_flags function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_format_flags(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint32_t format_flags    = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	format_flags = 0;

	result = libfvalue_value_get_format_flags(
	          value,
	          &format_flags,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT32(
	 "format_flags",
	 format_flags,
	 (uint32_t) 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	format_flags = 0;

	result = libfvalue_value_get_format_flags(
	          NULL,
	          &format_flags,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT32(
	 "format_flags",
	 format_flags,
	 (uint32_t) 0 );

	FVALUE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfvalue_value_get_format_flags(
	          value,
	          NULL,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FVALUE_TEST_ASSERT_EQUAL_UINT32(
	 "format_flags",
	 format_flags,
	 (uint32_t) 0 );

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

/* Tests the libfvalue_value_set_format_flags function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_set_format_flags(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_set_format_flags(
	          value,
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
	result = libfvalue_value_set_format_flags(
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

/* Tests the libfvalue_value_get_value_instance_by_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_value_instance_by_index(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	intptr_t *value_instance = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
#ifdef TODO
/* TODO initialize test */
	result = libfvalue_value_get_value_instance_by_index(
	          value,
	          0,
	          &value_instance,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value_instance = NULL;
#endif

	/* Test error cases
	 */
	result = libfvalue_value_get_value_instance_by_index(
	          NULL,
	          0,
	          &value_instance,
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

	result = libfvalue_value_get_value_instance_by_index(
	          value,
	          -1,
	          &value_instance,
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

	result = libfvalue_value_get_value_instance_by_index(
	          value,
	          0,
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

	value_instance = (libfvalue_value_t *) 0x12345678UL;

	result = libfvalue_value_get_value_instance_by_index(
	          value,
	          0,
	          NULL,
	          &error );

	value_instance = NULL;

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

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

/* Tests the libfvalue_value_get_number_of_value_entries function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_number_of_value_entries(
     void )
{
	libcerror_error_t *error    = NULL;
	libfvalue_value_t *value    = NULL;
	int number_of_value_entries = 0;
	int result                  = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	number_of_value_entries = 0;

	result = libfvalue_value_get_number_of_value_entries(
	          value,
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

/* TODO test with data */
/* TODO test with value instances */

	/* Test error cases
	 */
	number_of_value_entries = 0;

	result = libfvalue_value_get_number_of_value_entries(
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

	result = libfvalue_value_get_number_of_value_entries(
	          value,
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

/* Tests the libfvalue_value_get_entry function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_entry(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	size_t entry_data_offset = 0;
	size_t entry_data_size   = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
#ifdef TODO
/* TODO initialize value with data */
	result = libfvalue_value_get_entry(
	          value,
	          0,
	          &entry_data_offset,
	          &entry_data_size,
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
	result = libfvalue_value_get_entry(
	          NULL,
	          0,
	          &entry_data_offset,
	          &entry_data_size,
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

#ifdef TODO
/* TODO initialize value with data */
	result = libfvalue_value_get_entry(
	          value,
	          -1,
	          &entry_data_offset,
	          &entry_data_size,
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
#endif

	result = libfvalue_value_get_entry(
	          value,
	          0,
	          NULL,
	          &entry_data_size,
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

	result = libfvalue_value_get_entry(
	          value,
	          0,
	          &entry_data_offset,
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

/* Tests the libfvalue_value_set_entry function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_set_entry(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
#ifdef TODO
/* TODO initialize value with data */
	result = libfvalue_value_set_entry(
	          value,
	          0,
	          0,
	          32,
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
	result = libfvalue_value_set_entry(
	          NULL,
	          0,
	          0,
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

/* Tests the libfvalue_value_get_entry_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_entry_data(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint8_t *entry_data      = NULL;
	size_t entry_data_size   = 0;
	int encoding             = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
#ifdef TODO
/* TODO initialize value with data */
	result = libfvalue_value_get_entry_data(
	          value,
	          0,
	          &entry_data,
	          &entry_data_size,
	          &encoding,
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
	result = libfvalue_value_get_entry_data(
	          NULL,
	          0,
	          &entry_data,
	          &entry_data_size,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_get_entry_data(
	          value,
	          -1,
	          &entry_data,
	          &entry_data_size,
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
#endif

	result = libfvalue_value_get_entry_data(
	          value,
	          0,
	          NULL,
	          &entry_data_size,
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

	result = libfvalue_value_get_entry_data(
	          value,
	          0,
	          &entry_data,
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

	result = libfvalue_value_get_entry_data(
	          value,
	          0,
	          &entry_data,
	          &entry_data_size,
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

/* Tests the libfvalue_value_copy_entry_data function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_entry_data(
     void )
{
	uint8_t entry_data[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int encoding             = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
#ifdef TODO
/* TODO initialize value with data */
	result = libfvalue_value_copy_entry_data(
	          value,
	          0,
	          entry_data,
	          32,
	          &encoding,
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
	result = libfvalue_value_copy_entry_data(
	          NULL,
	          0,
	          entry_data,
	          32,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_entry_data(
	          value,
	          -1,
	          entry_data,
	          32,
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
#endif

	result = libfvalue_value_copy_entry_data(
	          value,
	          0,
	          NULL,
	          32,
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

	result = libfvalue_value_copy_entry_data(
	          value,
	          0,
	          entry_data,
	          (size_t) SSIZE_MAX + 1,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_entry_data(
	          value,
	          0,
	          entry_data,
	          32,
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
#endif

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

/* Tests the libfvalue_value_copy_from_boolean function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_boolean(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_from_boolean(
	          value,
	          0,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_boolean(
	          NULL,
	          0,
	          1,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_boolean(
	          value,
	          -1,
	          1,
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
#endif

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

/* Tests the libfvalue_value_copy_to_boolean function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_boolean(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint8_t value_boolean    = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_boolean(
	          value,
	          0,
	          &value_boolean,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_boolean(
	          NULL,
	          0,
	          &value_boolean,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_boolean(
	          value,
	          -1,
	          &value_boolean,
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
#endif

	result = libfvalue_value_copy_to_boolean(
	          value,
	          0,
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

/* Tests the libfvalue_value_copy_from_8bit function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_8bit(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_from_8bit(
	          value,
	          0,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_8bit(
	          NULL,
	          0,
	          1,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_8bit(
	          value,
	          -1,
	          1,
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
#endif

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

/* Tests the libfvalue_value_copy_to_8bit function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_8bit(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint8_t value_8bit       = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_8bit(
	          value,
	          0,
	          &value_8bit,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_8bit(
	          NULL,
	          0,
	          &value_8bit,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_8bit(
	          value,
	          -1,
	          &value_8bit,
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
#endif

	result = libfvalue_value_copy_to_8bit(
	          value,
	          0,
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

/* Tests the libfvalue_value_copy_from_16bit function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_16bit(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_from_16bit(
	          value,
	          0,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_16bit(
	          NULL,
	          0,
	          1,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_16bit(
	          value,
	          -1,
	          1,
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
#endif

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

/* Tests the libfvalue_value_copy_to_16bit function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_16bit(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint16_t value_16bit     = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_16bit(
	          value,
	          0,
	          &value_16bit,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_16bit(
	          NULL,
	          0,
	          &value_16bit,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_16bit(
	          value,
	          -1,
	          &value_16bit,
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
#endif

	result = libfvalue_value_copy_to_16bit(
	          value,
	          0,
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

/* Tests the libfvalue_value_copy_from_32bit function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_32bit(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_from_32bit(
	          value,
	          0,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_32bit(
	          NULL,
	          0,
	          1,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_32bit(
	          value,
	          -1,
	          1,
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
#endif

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

/* Tests the libfvalue_value_copy_to_32bit function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_32bit(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint32_t value_32bit     = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_32bit(
	          value,
	          0,
	          &value_32bit,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_32bit(
	          NULL,
	          0,
	          &value_32bit,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_32bit(
	          value,
	          -1,
	          &value_32bit,
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
#endif

	result = libfvalue_value_copy_to_32bit(
	          value,
	          0,
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

/* Tests the libfvalue_value_copy_from_64bit function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_64bit(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_from_64bit(
	          value,
	          0,
	          1,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_64bit(
	          NULL,
	          0,
	          1,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_64bit(
	          value,
	          -1,
	          1,
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
#endif

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

/* Tests the libfvalue_value_copy_to_64bit function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_64bit(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	uint64_t value_64bit     = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_64bit(
	          value,
	          0,
	          &value_64bit,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_64bit(
	          NULL,
	          0,
	          &value_64bit,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_64bit(
	          value,
	          -1,
	          &value_64bit,
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
#endif

	result = libfvalue_value_copy_to_64bit(
	          value,
	          0,
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

/* Tests the libfvalue_value_copy_from_float function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_float(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_from_float(
	          value,
	          0,
	          1.0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_float(
	          NULL,
	          0,
	          1.0,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_float(
	          value,
	          -1,
	          1.0,
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
#endif

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

/* Tests the libfvalue_value_copy_to_float function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_float(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	float value_float        = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_float(
	          value,
	          0,
	          &value_float,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_float(
	          NULL,
	          0,
	          &value_float,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_float(
	          value,
	          -1,
	          &value_float,
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
#endif

	result = libfvalue_value_copy_to_float(
	          value,
	          0,
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

/* Tests the libfvalue_value_copy_from_double function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_double(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_from_double(
	          value,
	          0,
	          1.0,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_double(
	          NULL,
	          0,
	          1.0,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_double(
	          value,
	          -1,
	          1.0,
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
#endif

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

/* Tests the libfvalue_value_copy_to_double function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_double(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	double value_double      = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_double(
	          value,
	          0,
	          &value_double,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_double(
	          NULL,
	          0,
	          &value_double,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_double(
	          value,
	          -1,
	          &value_double,
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
#endif

	result = libfvalue_value_copy_to_double(
	          value,
	          0,
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

/* Tests the libfvalue_value_copy_from_utf8_string function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_utf8_string(
     void )
{
	uint8_t utf8_string[ 5 ] = { 't', 'e', 's', 't', 0 };
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_utf8_string(
	          value,
	          0,
	          utf8_string,
	          4,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_utf8_string(
	          NULL,
	          0,
	          utf8_string,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_utf8_string(
	          value,
	          -1,
	          utf8_string,
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
#endif

	result = libfvalue_value_copy_from_utf8_string(
	          value,
	          0,
	          NULL,
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

	result = libfvalue_value_copy_from_utf8_string(
	          value,
	          0,
	          utf8_string,
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

/* Tests the libfvalue_value_get_utf8_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_utf8_string_size(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	size_t string_size       = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_get_utf8_string_size(
	          value,
	          0,
	          &string_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_get_utf8_string_size(
	          NULL,
	          0,
	          &string_size,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_get_utf8_string_size(
	          value,
	          -1,
	          &string_size,
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

	result = libfvalue_value_get_utf8_string_size(
	          value,
	          0,
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
#endif

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

/* Tests the libfvalue_value_copy_to_utf8_string function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_utf8_string(
     void )
{
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_utf8_string(
	          value,
	          0,
	          utf8_string,
	          32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_utf8_string(
	          NULL,
	          0,
	          utf8_string,
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

/* Tests the libfvalue_value_copy_to_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_utf8_string_with_index(
     void )
{
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	size_t string_index      = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	string_index = 0;

	result = libfvalue_value_copy_to_utf8_string_with_index(
	          value,
	          0,
	          utf8_string,
	          32,
	          &string_index,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_value_copy_to_utf8_string_with_index(
	          NULL,
	          0,
	          utf8_string,
	          32,
	          &string_index,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_utf8_string_with_index(
	          value,
	          -1,
	          utf8_string,
	          32,
	          &string_index,
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

	result = libfvalue_value_copy_to_utf8_string_with_index(
	          value,
	          0,
	          NULL,
	          32,
	          &string_index,
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

	result = libfvalue_value_copy_to_utf8_string_with_index(
	          value,
	          0,
	          utf8_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
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

	result = libfvalue_value_copy_to_utf8_string_with_index(
	          value,
	          0,
	          utf8_string,
	          32,
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
#endif

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

/* Tests the libfvalue_value_copy_from_utf16_string function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_utf16_string(
     void )
{
	uint16_t utf16_string[ 5 ] = { 't', 'e', 's', 't', 0 };
	libcerror_error_t *error   = NULL;
	libfvalue_value_t *value   = NULL;
	int result                 = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_utf16_string(
	          value,
	          0,
	          utf16_string,
	          4,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_utf16_string(
	          NULL,
	          0,
	          utf16_string,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_utf16_string(
	          value,
	          -1,
	          utf16_string,
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
#endif

	result = libfvalue_value_copy_from_utf16_string(
	          value,
	          0,
	          NULL,
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

	result = libfvalue_value_copy_from_utf16_string(
	          value,
	          0,
	          utf16_string,
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

/* Tests the libfvalue_value_get_utf16_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_utf16_string_size(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	size_t string_size       = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_get_utf16_string_size(
	          value,
	          0,
	          &string_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_get_utf16_string_size(
	          NULL,
	          0,
	          &string_size,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_get_utf16_string_size(
	          value,
	          -1,
	          &string_size,
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

	result = libfvalue_value_get_utf16_string_size(
	          value,
	          0,
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
#endif

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

/* Tests the libfvalue_value_copy_to_utf16_string function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_utf16_string(
     void )
{
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_utf16_string(
	          value,
	          0,
	          utf16_string,
	          32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_utf16_string(
	          NULL,
	          0,
	          utf16_string,
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

/* Tests the libfvalue_value_copy_to_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_utf16_string_with_index(
     void )
{
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	size_t string_index      = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	string_index = 0;

	result = libfvalue_value_copy_to_utf16_string_with_index(
	          value,
	          0,
	          utf16_string,
	          32,
	          &string_index,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_value_copy_to_utf16_string_with_index(
	          NULL,
	          0,
	          utf16_string,
	          32,
	          &string_index,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_utf16_string_with_index(
	          value,
	          -1,
	          utf16_string,
	          32,
	          &string_index,
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

	result = libfvalue_value_copy_to_utf16_string_with_index(
	          value,
	          0,
	          NULL,
	          32,
	          &string_index,
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

	result = libfvalue_value_copy_to_utf16_string_with_index(
	          value,
	          0,
	          utf16_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
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

	result = libfvalue_value_copy_to_utf16_string_with_index(
	          value,
	          0,
	          utf16_string,
	          32,
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
#endif

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

/* Tests the libfvalue_value_copy_from_utf32_string function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_from_utf32_string(
     void )
{
	uint32_t utf32_string[ 5 ] = { 't', 'e', 's', 't', 0 };
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_utf32_string(
	          value,
	          0,
	          utf32_string,
	          4,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_from_utf32_string(
	          NULL,
	          0,
	          utf32_string,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_from_utf32_string(
	          value,
	          -1,
	          utf32_string,
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
#endif

	result = libfvalue_value_copy_from_utf32_string(
	          value,
	          0,
	          NULL,
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

	result = libfvalue_value_copy_from_utf32_string(
	          value,
	          0,
	          utf32_string,
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

/* Tests the libfvalue_value_get_utf32_string_size function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_get_utf32_string_size(
     void )
{
	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	size_t string_size       = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_get_utf32_string_size(
	          value,
	          0,
	          &string_size,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_get_utf32_string_size(
	          NULL,
	          0,
	          &string_size,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_get_utf32_string_size(
	          value,
	          -1,
	          &string_size,
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

	result = libfvalue_value_get_utf32_string_size(
	          value,
	          0,
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
#endif

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

/* Tests the libfvalue_value_copy_to_utf32_string function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_utf32_string(
     void )
{
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	result = libfvalue_value_copy_to_utf32_string(
	          value,
	          0,
	          utf32_string,
	          32,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	result = libfvalue_value_copy_to_utf32_string(
	          NULL,
	          0,
	          utf32_string,
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

/* Tests the libfvalue_value_copy_to_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fvalue_test_value_copy_to_utf32_string_with_index(
     void )
{
	uint32_t utf32_string[ 32 ];

	libcerror_error_t *error = NULL;
	libfvalue_value_t *value = NULL;
	size_t string_index      = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libfvalue_value_initialize(
	          &value,
	          "test",
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          NULL,
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

	/* Test regular cases
	 */
	string_index = 0;

	result = libfvalue_value_copy_to_utf32_string_with_index(
	          value,
	          0,
	          utf32_string,
	          32,
	          &string_index,
	          &error );

	FVALUE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FVALUE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

/* TODO test with value entries */

	/* Test error cases
	 */
	string_index = 0;

	result = libfvalue_value_copy_to_utf32_string_with_index(
	          NULL,
	          0,
	          utf32_string,
	          32,
	          &string_index,
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

#ifdef TODO
/* TODO fix test */
	result = libfvalue_value_copy_to_utf32_string_with_index(
	          value,
	          -1,
	          utf32_string,
	          32,
	          &string_index,
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

	result = libfvalue_value_copy_to_utf32_string_with_index(
	          value,
	          0,
	          NULL,
	          32,
	          &string_index,
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

	result = libfvalue_value_copy_to_utf32_string_with_index(
	          value,
	          0,
	          utf32_string,
	          (size_t) SSIZE_MAX + 1,
	          &string_index,
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

	result = libfvalue_value_copy_to_utf32_string_with_index(
	          value,
	          0,
	          utf32_string,
	          32,
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
#endif

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
	 "libfvalue_value_initialize",
	 fvalue_test_value_initialize );

	FVALUE_TEST_RUN(
	 "libfvalue_value_free",
	 fvalue_test_value_free );

	FVALUE_TEST_RUN(
	 "libfvalue_value_clone",
	 fvalue_test_value_clone );

	FVALUE_TEST_RUN(
	 "libfvalue_value_clear",
	 fvalue_test_value_clear );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_type",
	 fvalue_test_value_get_type );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_identifier",
	 fvalue_test_value_get_identifier );

	FVALUE_TEST_RUN(
	 "libfvalue_value_set_identifier",
	 fvalue_test_value_set_identifier );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_data_flags",
	 fvalue_test_value_get_data_flags );

	FVALUE_TEST_RUN(
	 "libfvalue_value_set_data_flags",
	 fvalue_test_value_set_data_flags );

	FVALUE_TEST_RUN(
	 "libfvalue_value_has_data",
	 fvalue_test_value_has_data );

	FVALUE_TEST_RUN(
	 "libfvalue_value_initialize_data",
	 fvalue_test_value_initialize_data );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_data_size",
	 fvalue_test_value_get_data_size );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_data",
	 fvalue_test_value_get_data );

	FVALUE_TEST_RUN(
	 "libfvalue_value_set_data",
	 fvalue_test_value_set_data );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_data",
	 fvalue_test_value_copy_data );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_format_flags",
	 fvalue_test_value_get_format_flags );

	FVALUE_TEST_RUN(
	 "libfvalue_value_set_format_flags",
	 fvalue_test_value_set_format_flags );

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_value_instance_by_index",
	 fvalue_test_value_get_value_instance_by_index );

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_number_of_value_entries",
	 fvalue_test_value_get_number_of_value_entries );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_entry",
	 fvalue_test_value_get_entry );

	FVALUE_TEST_RUN(
	 "libfvalue_value_set_entry",
	 fvalue_test_value_set_entry );

	/* TODO: add tests for libfvalue_value_append_entry */

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_entry_data",
	 fvalue_test_value_get_entry_data );

	/* TODO: add tests for libfvalue_value_set_entry_data */

	/* TODO: add tests for libfvalue_value_append_entry_data */

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_entry_data",
	 fvalue_test_value_copy_entry_data );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_boolean",
	 fvalue_test_value_copy_from_boolean );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_boolean",
	 fvalue_test_value_copy_to_boolean );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_8bit",
	 fvalue_test_value_copy_from_8bit );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_8bit",
	 fvalue_test_value_copy_to_8bit );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_16bit",
	 fvalue_test_value_copy_from_16bit );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_16bit",
	 fvalue_test_value_copy_to_16bit );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_32bit",
	 fvalue_test_value_copy_from_32bit );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_32bit",
	 fvalue_test_value_copy_to_32bit );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_64bit",
	 fvalue_test_value_copy_from_64bit );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_64bit",
	 fvalue_test_value_copy_to_64bit );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_float",
	 fvalue_test_value_copy_from_float );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_float",
	 fvalue_test_value_copy_to_float );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_double",
	 fvalue_test_value_copy_from_double );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_double",
	 fvalue_test_value_copy_to_double );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_utf8_string",
	 fvalue_test_value_copy_from_utf8_string );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_utf8_string_size",
	 fvalue_test_value_get_utf8_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_utf8_string",
	 fvalue_test_value_copy_to_utf8_string );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_utf8_string_with_index",
	 fvalue_test_value_copy_to_utf8_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_utf16_string",
	 fvalue_test_value_copy_from_utf16_string );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_utf16_string_size",
	 fvalue_test_value_get_utf16_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_utf16_string",
	 fvalue_test_value_copy_to_utf16_string );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_utf16_string_with_index",
	 fvalue_test_value_copy_to_utf16_string_with_index );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_from_utf32_string",
	 fvalue_test_value_copy_from_utf32_string );

	FVALUE_TEST_RUN(
	 "libfvalue_value_get_utf32_string_size",
	 fvalue_test_value_get_utf32_string_size );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_utf32_string",
	 fvalue_test_value_copy_to_utf32_string );

	FVALUE_TEST_RUN(
	 "libfvalue_value_copy_to_utf32_string_with_index",
	 fvalue_test_value_copy_to_utf32_string_with_index );

	/* TODO: add tests for libfvalue_value_read_from_file_stream */

	/* TODO: add tests for libfvalue_value_write_to_file_stream */

#if defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT )

	/* TODO: add tests for libfvalue_value_print */

#endif /* defined( __GNUC__ ) && !defined( LIBFVALUE_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

