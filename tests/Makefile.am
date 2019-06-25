AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBFDATETIME_CPPFLAGS@ \
	@LIBFGUID_CPPFLAGS@ \
	@LIBFWNT_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFVALUE_DLL_IMPORT@

TESTS = \
	test_library.sh

check_SCRIPTS = \
	test_library.sh \
	test_manpage.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fvalue_test_binary_data \
	fvalue_test_data_handle \
	fvalue_test_error \
	fvalue_test_filetime \
	fvalue_test_floating_point \
	fvalue_test_integer \
	fvalue_test_split_utf16_string \
	fvalue_test_split_utf8_string \
	fvalue_test_string \
	fvalue_test_support \
	fvalue_test_table \
	fvalue_test_value \
	fvalue_test_value_entry \
	fvalue_test_value_type

fvalue_test_binary_data_SOURCES = \
	fvalue_test_binary_data.c \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h

fvalue_test_binary_data_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_data_handle_SOURCES = \
	fvalue_test_data_handle.c \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h

fvalue_test_data_handle_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_error_SOURCES = \
	fvalue_test_error.c \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_unused.h

fvalue_test_error_LDADD = \
	../libfvalue/libfvalue.la

fvalue_test_filetime_SOURCES = \
	fvalue_test_filetime.c \
	fvalue_test_libcerror.h \
	fvalue_test_libfdatetime.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_unused.h

fvalue_test_filetime_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_floating_point_SOURCES = \
	fvalue_test_floating_point.c \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h

fvalue_test_floating_point_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_integer_SOURCES = \
	fvalue_test_integer.c \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h

fvalue_test_integer_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_split_utf16_string_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_split_utf16_string.c \
	fvalue_test_unused.h

fvalue_test_split_utf16_string_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_split_utf8_string_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_split_utf8_string.c \
	fvalue_test_unused.h

fvalue_test_split_utf8_string_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_string_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_string.c \
	fvalue_test_unused.h

fvalue_test_string_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_support_SOURCES = \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_support.c \
	fvalue_test_unused.h

fvalue_test_support_LDADD = \
	../libfvalue/libfvalue.la

fvalue_test_table_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_table.c \
	fvalue_test_unused.h

fvalue_test_table_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_value_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h \
	fvalue_test_value.c

fvalue_test_value_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_value_entry_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h \
	fvalue_test_value_entry.c

fvalue_test_value_entry_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_value_type_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfdatetime.h \
	fvalue_test_libfguid.h \
	fvalue_test_libfvalue.h \
	fvalue_test_libfwnte.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h \
	fvalue_test_value_type.c

fvalue_test_value_type_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

