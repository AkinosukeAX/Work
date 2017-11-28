#include "NtupleAnalysisBase.hxx"

class AnalysisSkeleton : public NtupleAnalysisBase
{
public:
  AnalysisSkeleton(TTree *tree=0) : NtupleAnalysisBase(tree) {}
  ~AnalysisSkeleton() {}
  void Loop();
};
