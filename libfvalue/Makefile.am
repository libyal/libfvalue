AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBFDATETIME_CPPFLAGS@ \
	@LIBFGUID_CPPFLAGS@ \
	@LIBFWNT_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@

lib_LTLIBRARIES = libfvalue.la

libfvalue_la_SOURCES = \
	libfvalue.c \
	libfvalue_binary_data.c libfvalue_binary_data.h \
	libfvalue_codepage.h \
	libfvalue_data_handle.c libfvalue_data_handle.h \
	libfvalue_definitions.h \
	libfvalue_error.c libfvalue_error.h \
	libfvalue_extern.h \
	libfvalue_filetime.c libfvalue_filetime.h \
	libfvalue_floating_point.c libfvalue_floating_point.h \
	libfvalue_integer.c libfvalue_integer.h \
	libfvalue_libcdata.h \
	libfvalue_libcerror.h \
	libfvalue_libcnotify.h \
	libfvalue_libcstring.h \
	libfvalue_libfdatetime.h \
	libfvalue_libfguid.h \
	libfvalue_libfwnt.h \
	libfvalue_libuna.h \
	libfvalue_split_string.c libfvalue_split_string.h \
	libfvalue_string.c libfvalue_string.h \
	libfvalue_types.h \
	libfvalue_table.c libfvalue_table.h \
	libfvalue_value.c libfvalue_value.h \
	libfvalue_value_entry.c libfvalue_value_entry.h \
	libfvalue_value_type.c libfvalue_value_type.h \
	libfvalue_support.c libfvalue_support.h \
	libfvalue_unused.h

libfvalue_la_LIBADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	@LIBCTHREADS_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBFDATETIME_LIBADD@ \
	@LIBFGUID_LIBADD@ \
	@LIBFWNT_LIBADD@ \
	@PTHREAD_LIBADD@

libfvalue_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libfvalue_definitions.h.in \
	libfvalue.rc \
	libfvalue.rc.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libfvalue_definitions.h
	/bin/rm -f libfvalue.rc
	/bin/rm -f Makefile

splint:
	@echo "Running splint on libfvalue ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libfvalue_la_SOURCES)

