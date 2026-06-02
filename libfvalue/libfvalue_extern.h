/*
 * The internal extern definition
 *
 * Copyright (C) 2010-2026, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBFVALUE_INTERNAL_EXTERN_H )
#define _LIBFVALUE_INTERNAL_EXTERN_H

#include <common.h>

#if !defined( __CYGWIN__ ) && !defined( _WIN32 ) && defined( __has_attribute )
#if __has_attribute( visibility )
#define LIBFVALUE_INTERNAL	__attribute__((visibility("hidden"))) extern

#else
#define LIBFVALUE_INTERNAL	extern

#endif /* __has_attribute( visibility ) */
#else
#define LIBFVALUE_INTERNAL	extern

#endif /* !defined( __CYGWIN__ ) && !defined( _WIN32 ) && defined( __has_attribute ) */

/* Define HAVE_LOCAL_LIBFVALUE for local use of libfvalue
 */
#if !defined( HAVE_LOCAL_LIBFVALUE )

#include <libfvalue/extern.h>

#else
#define LIBFVALUE_EXTERN		/* extern */
#define LIBFVALUE_EXTERN_VARIABLE	LIBFVALUE_INTERNAL

#endif /* !defined( HAVE_LOCAL_LIBFVALUE ) */

#if defined( __clang__ ) && defined( __has_attribute )
#if __has_attribute( ownership_holds )
#define LIBFVALUE_HOLDS_OWNERSHIP(index) __attribute__((ownership_holds(malloc, index)))

#else
#define LIBFVALUE_HOLDS_OWNERSHIP(index)

#endif /* __has_attribute( ownership_holds ) */
#else
#define LIBFVALUE_HOLDS_OWNERSHIP(index)

#endif /* defined( __clang__ ) && defined( __has_attribute ) */

#endif /* !defined( _LIBFVALUE_INTERNAL_EXTERN_H ) */

