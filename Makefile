# Copyright © 1991-2006 Bart Massey
# ALL RIGHTS RESERVED
# [This program is licensed under the "3-clause ('new') BSD License"]
# Please see the file COPYING in the source
# distribution of this software for license terms.

CXX = clang++ -std=c++17 -Wall -Werror
CC = clang -std=c99 -Wall -Werror
DEBUGLEVEL = 0
ANTIALIAS = 3
DEFINES = -DDEBUG=$(DEBUGLEVEL) -DANTIALIAS=$(ANTIALIAS)
CDEBUGFLAGS = -O3
CFLAGS = $(CDEBUGFLAGS) $(DEFINES)
ANALYZE = --analyzer-output plist-multi-file --analyze

# LIBS = -lfb -lrle -lm
LIBS = -lm
CXXSRCS = render.cc point.cc poly.cc xform.cc object.cc \
  ray.cc texture.cc fast_texture.cc board_texture.cc \
  output.cc ppm_output.cc oldppm_output.cc \
  sphere.cc light.cc model.cc \
  generate.cc
CSRCS = frandom.c
OBJS = render.o point.o poly.o xform.o object.o \
  ray.o texture.o fast_texture.o board_texture.o \
  output.o ppm_output.o oldppm_output.o \
  sphere.o light.o model.o \
  generate.o frandom.o
HDRS = point.h poly.h xform.h object.h \
  ray.h texture.h fast_texture.h board_texture.h \
  output.h ppm_output.h oldppm_output.h \
  sphere.h light.h model.h
.SUFFIXES: .cc

.cc.o:
	$(CXX) $(CFLAGS) -c $<

.c.o:
	$(CC) $(CFLAGS) -c $<

render: $(OBJS)
	$(CXX) $(CFLAGS) -o render $(OBJS) $(LIBS)

$(OBJS): render.h $(HDRS)

render.o generate.o: frandom.h generate.h

clean:
	-rm -f *.o render *.plist render.out.ppm

analyze:
	$(CXX) $(ANALYZE) $(CXXSRCS)
	$(CC) $(ANALYZE) $(CSRCS)
