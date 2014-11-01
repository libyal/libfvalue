AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFVALUE_DLL_IMPORT@

TESTS = \
	test_value.sh

check_SCRIPTS = \
	test_value.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fvalue_test_value

fvalue_test_value_SOURCES = \
	fvalue_test_value.c \
	fvalue_test_libcerror.h \
	fvalue_test_libcstring.h \
	fvalue_test_libfvalue.h \
	fvalue_test_unused.h

fvalue_test_value_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

