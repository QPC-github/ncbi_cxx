# $Id: Makefile.triecreate.app 14717 2013-03-08 15:25:05Z ucko $

WATCHERS = ucko

APP = triecreate
SRC = triecreate

CPPFLAGS = $(SRA_INCLUDE) $(SRA_INTERNAL_CPPFLAGS) $(ORIG_CPPFLAGS)
LIB = kapp$(FORCE_STATIC) kfs$(FORCE_STATIC) klib$(FORCE_STATIC) \
      $(Z_LIB) $(BZ2_LIB)
LIBS = $(DL_LIBS) $(Z_LIBS) $(BZ2_LIBS) $(ORIG_LIBS)

CHECK_CMD = triecreate < Makefile
CHECK_REQUIRES = unix
