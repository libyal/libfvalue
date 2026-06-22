AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
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


BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages

check_PROGRAMS = \
	fvalue_test_binary_data \
	fvalue_test_data_handle \
	fvalue_test_error \
	fvalue_test_filetime \
	fvalue_test_floating_point \
	fvalue_test_integer \
	fvalue_test_split_utf8_string \
	fvalue_test_split_utf16_string \
	fvalue_test_string \
	fvalue_test_support \
	fvalue_test_table \
	fvalue_test_utf8_string \
	fvalue_test_utf16_string \
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

fvalue_test_utf8_string_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h \
	fvalue_test_utf8_string.c

fvalue_test_utf8_string_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

fvalue_test_utf16_string_SOURCES = \
	fvalue_test_libcerror.h \
	fvalue_test_libfvalue.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h \
	fvalue_test_utf16_string.c

fvalue_test_utf16_string_LDADD = \
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
	fvalue_test_libfwnt.h \
	fvalue_test_macros.h \
	fvalue_test_memory.c fvalue_test_memory.h \
	fvalue_test_unused.h \
	fvalue_test_value_type.c

fvalue_test_value_type_LDADD = \
	../libfvalue/libfvalue.la \
	@LIBCERROR_LIBADD@

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_library: \
	package.m4 \
	test_library.at \
	test_macros.at

test_manpages: \
	package.m4 \
	test_manpages.at

EXTRA_DIST = \
	$(check_AUTOTESTS:=.at) \
	package.m4 \
	test_macros.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

