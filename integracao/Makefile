CPUC      = gcc
CFLAGS    = -O3 --std=c11 -m64	 #     -Wunused-variable #-Wno-conversion-null -Wdelete-non-virtual-dtor
DEFS      =
INCLUDES  =
LIBDIR   = -L/usr/lib
LIBS     = -lm
LINK     =  $(LIBDIR) $(LIBS)
CPU_COMPILE_C  = $(CPUC) $(DEFS) $(INCLUDES) $(CFLAGS)

all:
	$(CPU_COMPILE_C) main-int.c  $(LINK)  -o integral
	$(CPU_COMPILE_C) -fopenmp parallel-main-int.c  $(LINK) -o parallel-integral

clean:
	rm integral
	rm parallel-integral
