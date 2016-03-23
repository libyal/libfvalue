include_HEADERS = \
	libfvalue.h

pkginclude_HEADERS = \
	libfvalue/codepage.h \
	libfvalue/definitions.h \
	libfvalue/error.h \
	libfvalue/extern.h \
	libfvalue/features.h \
	libfvalue/types.h

EXTRA_DIST = \
	libfvalue.h.in \
	libfvalue/definitions.h.in \
	libfvalue/features.h.in \
	libfvalue/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libfvalue.h
	/bin/rm -f libfvalue/definitions.h
	/bin/rm -f libfvalue/types.h
	/bin/rm -f Makefile

