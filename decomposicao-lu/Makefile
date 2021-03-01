CPUC      = gcc
CFLAGS    = -O3 --std=c11 -m64 	 #     -Wunused-variable #-Wno-conversion-null -Wdelete-non-virtual-dtor
DEFS      =
INCLUDES  =
LIBDIR   = -L/usr/lib
LIBS     = -lm
LINK     =  $(LIBDIR) $(LIBS)
CPU_COMPILE_C  = $(CPUC) $(DEFS) $(INCLUDES) $(CFLAGS)

all:
	$(CPU_COMPILE_C) main-lu.c  $(LINK)  -o lu
	$(CPU_COMPILE_C) -fopenmp parallel-main-lu.c  $(LINK)  -o parallel-lu

clean:
	rm parallel-lu
	rm lu
