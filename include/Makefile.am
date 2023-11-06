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
	-rm -f libfvalue.h
	-rm -f libfvalue/definitions.h
	-rm -f libfvalue/features.h
	-rm -f libfvalue/types.h
	-rm -f Makefile

