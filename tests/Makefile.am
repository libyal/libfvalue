AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFVALUE_DLL_IMPORT@

TESTS = \
	test_api_functions.sh \
	test_api_types.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_api_types.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fvalue_test_error \
	fvalue_test_support \
	fvalue_test_value

fvalue_test_error_SOURCES = \
	fvalue_test_error.c \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_unused.h

fvalue_test_error_LDADD = \
	../libfvalue/libfvalue.la

fvalue_test_support_SOURCES = \
	fvalue_test_support.c \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_unused.h

fvalue_test_support_LDADD = \
	../libfvalue/libfvalue.la

fvalue_test_value_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_value.c \
	fvalue_test_unused.h

fvalue_test_value_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

