ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)

#ROOTCFLAGS    = $(shell /usr/bin/root-config --cflags)
#ROOTLIBS      = $(shell /usr/bin/root-config --libs)
#ROOTGLIBS     = $(shell /usr/bin/root-config --glibs)

CXX           = g++
CXXFLAGS      = -g -Wall -fPIC -Wno-deprecated

NGLIBS         = $(ROOTGLIBS)
NGLIBS        += -lMinuit

CXXFLAGS      += $(ROOTCFLAGS)
CXX           += -I./
LIBS           = $(ROOTLIBS)

GLIBS          = $(filter-out -lNew, $(NGLIBS))

CXX	      += -I./obj/
OUTLIB	      = ./obj/
.SUFFIXES: .C
.PREFIXES: ./obj/

#----------------------------------------------------#

main: main.cpp
	g++ -o main main.cpp `root-config --cflags --glibs`

lab9: lab9.cpp
	g++ -o lab9 lab9.cpp `root-config --cflags --glibs`

plotsFast: plotsFast.cc analysis_corto.o
	g++ -o plotsFast plotsFast.cc *.o `root-config --cflags --glibs`

analysis_corto.o: analysis_corto.cc analysis_corto.h
	$(CXX) $(CXXFLAGS) -c -I. -o analysis_corto.o $<

clean:
	rm -f main
	rm -f *~

cleananalysis:
	rm -f analysis_corto.o
	rm -f plotsFast
	rm -f *~
