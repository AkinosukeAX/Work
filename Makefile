ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS  = $(shell root-config --libs)

objs=NtupleAnalysisBase.o AnalysisSkeleton.o 
exes=RunAnalysis.exe 

all:$(exes)

.PRECIOUS: $(objs)

%.exe:%.cxx $(objs) *.hxx
	g++ -o $@ $(objs) $< $(ROOTFLAGS) $(ROOTLIBS)

%.o:%.cxx %.hxx $(incl) *.hxx
	g++ -o $@ -c $<  $(ROOTFLAGS)

clean:
	\rm -f $(exes) $(objs) *~ *_cxx.d *_cxx_ACLiC_dict_rdict.pcm *_cxx.so

