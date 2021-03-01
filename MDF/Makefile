CPUC      = gcc
CFLAGS    = -O3 --std=c11 -m64	 #     -Wunused-variable #-Wno-conversion-null -Wdelete-non-virtual-dtor
DEFS      =
INCLUDES  = 
LIBDIR   = -L/usr/lib
LIBS     = -lm
LINK     =  $(LIBDIR) $(LIBS)
CPU_COMPILE_C  = $(CPUC) $(DEFS) $(INCLUDES) $(CFLAGS)

all:
	$(CPU_COMPILE_C) main-mdf.c  $(LINK)   -o mdf
	$(CPU_COMPILE_C) -fopenmp parallel-main-mdf.c $(LINK) -o parallel-mdf

clean:
	rm mdf
	rm parallel-mdf
