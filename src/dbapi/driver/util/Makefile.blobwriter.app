# $Id: Makefile.blobwriter.app 370257 2012-07-27 14:56:37Z ivanovp $

APP = blobwriter
SRC = blobwriter

CPPFLAGS = $(ORIG_CPPFLAGS) $(CMPRS_INCLUDE)

LIB  = dbapi_util_blobstore dbapi_driver xcompress $(CMPRS_LIB) xutil xncbi
LIBS = $(CMPRS_LIBS) $(DL_LIBS) $(ORIG_LIBS)


WATCHERS = ucko