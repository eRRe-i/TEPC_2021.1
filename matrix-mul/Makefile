################################################################################
#
#  Universidade Federal Rural do Rio de Janeiro
#  por: Marcelo Zamith - mzamith@ufrrj.br
#  Multiplicação de matrizes
#
################################################################################
EXEFILE   = mat-mul
PARALLEL_EXE = parallel-mat-mul
CPUCC     = g++
CPPFLAGS  = -mavx -std=c++11 -m64 -fpermissive
DEFS      = $(APPLICATION)  $(VERSION)
INCLUDES  = -I. 
LIBDIR    = -L/usr/lib
LIBS      =  -lm
LINK      =  $(LIBDIR) $(LIBS)
PARALLEL  = -fopenmp

ifeq ($(TARGET), release)
  DEFS      +=
  CPPFLAGS  +=  -O3
else
  DEFS     += -D_DEBUG
  CPPFLAGS += -g -Wall -O0
endif

CPU_COMPILE = $(CPUCC) $(DEFS) $(INCLUDES) $(CPPFLAGS)
CPU_COMPILE_PARALLEL = $(CPUCC) $(PARALLEL) $(DEFS) $(INCLUDES) $(CPPFLAGS)


all:	main
	$(CPU_COMPILE)	main.o $(LINK) -o $(EXEFILE) $(PAPILIBS)
	$(CPU_COMPILE_PARALLEL) parallel-mat-mul.o $(LINK) -o $(PARALLEL_EXE) $(PAPILIBS)

main:
	$(CPU_COMPILE) -c main.cpp
	$(CPU_COMPILE_PARALLEL) -c parallel-mat-mul.cpp

clean:
	rm *.o $(EXEFILE)
	rm *.o $(PARALLEL_EXE)

