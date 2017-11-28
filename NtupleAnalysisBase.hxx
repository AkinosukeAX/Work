//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Oct  3 07:14:54 2017 by ROOT version 6.10/04
// from TTree tree/tree
// found on file: /afs/cern.ch/user/a/akhigash/tileMuonDecoder/data17_13TeV.00337005.physics_Main.daq.RAW._lb0200._SFO-1_0001._0001.data.root
//////////////////////////////////////////////////////////

#ifndef NtupleAnalysisBase_h
#define NtupleAnalysisBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
// #include "vector"
// #include "vector"
// #include "vector"
#include <vector>

class NtupleAnalysisBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          nTgcRods;
   UInt_t          nTmdbRods;
   std::vector<unsigned int> *tmdb_rodid;
   std::vector<bool>    *tmdb_isAside;
   std::vector<unsigned int> *tmdb_rod_bcid;
   std::vector<unsigned int> *tmdb_rod_bcid6b;
   std::vector<unsigned int> *tmdb_phi;
   std::vector<std::vector<std::vector<unsigned int> > > *tmdb_adc_values;
   std::vector<unsigned int> *tmdb_adc_nsamples;
   std::vector<std::vector<unsigned int> > *tmdb_energy_values;
   std::vector<unsigned int> *tmdb_sl_result0;
   std::vector<unsigned int> *tmdb_sl_result1;
   std::vector<unsigned int> *tmdb_sl_result2;
   std::vector<unsigned int> *tmdb_sl_result0_bcid;
   std::vector<unsigned int> *tmdb_sl_result1_bcid;
   std::vector<unsigned int> *tmdb_sl_result2_bcid;
   std::vector<unsigned int> *tgcsl_rodid_prev;
   std::vector<unsigned int> *tgcsl_rodid_curr;
   std::vector<unsigned int> *tgcsl_rodid_next;
   std::vector<unsigned int> *tgcsl_rod_bcid_prev;
   std::vector<unsigned int> *tgcsl_rod_bcid_curr;
   std::vector<unsigned int> *tgcsl_rod_bcid_next;
   std::vector<unsigned int> *tgcsl_rod_bcid6b_prev;
   std::vector<unsigned int> *tgcsl_rod_bcid6b_curr;
   std::vector<unsigned int> *tgcsl_rod_bcid6b_next;
   std::vector<unsigned int> *tgcsl_sector_prev;
   std::vector<unsigned int> *tgcsl_sector_curr;
   std::vector<unsigned int> *tgcsl_sector_next;
   std::vector<bool>    *tgcsl_isAside_prev;
   std::vector<bool>    *tgcsl_isAside_curr;
   std::vector<bool>    *tgcsl_isAside_next;
   std::vector<unsigned int> *tgcsl_tmdb_tilecalbits_prev;
   std::vector<unsigned int> *tgcsl_tmdb_loc_prev;
   std::vector<unsigned int> *tgcsl_tmdb_tilecalbits_curr;
   std::vector<unsigned int> *tgcsl_tmdb_loc_curr;
   std::vector<unsigned int> *tgcsl_tmdb_tilecalbits_next;
   std::vector<unsigned int> *tgcsl_tmdb_loc_next;
   std::vector<unsigned int> *tgcsl_tmdb_tilecalbits_bcid_prev;
   std::vector<unsigned int> *tgcsl_tmdb_tilecalbits_bcid_curr;
   std::vector<unsigned int> *tgcsl_tmdb_tilecalbits_bcid_next;
   std::vector<unsigned int> *tgcsl_rodid;
   std::vector<unsigned int> *tgcsl_sectorid;
   std::vector<bool>    *tgcsl_isAside;
   std::vector<unsigned int> *tgcsl_rod_bcid;
   std::vector<unsigned int> *tgcsl_rod_bcid6b;
   std::vector<unsigned int> *tgcsl_correspondingtile0_bcid;
   std::vector<unsigned int> *tgcsl_correspondingtile1_bcid;
   std::vector<unsigned int> *tgcsl_correspondingtile2_bcid;
   std::vector<unsigned int> *tgcsl_correspondingtile3_bcid;
   std::vector<ULong64_t> *tgcsl_correspondingtile0;
   std::vector<ULong64_t> *tgcsl_correspondingtile1;
   std::vector<ULong64_t> *tgcsl_correspondingtile2;
   std::vector<ULong64_t> *tgcsl_correspondingtile3;
   std::vector<unsigned int> *tgcsl_bctiming;
   std::vector<unsigned int> *tgcsl_tilecalobits0;
   std::vector<unsigned int> *tgcsl_tilecalobits1;
   std::vector<unsigned int> *tgcsl_tilecalobits2;
   std::vector<unsigned int> *tgcsl_tilecalobits3;
   std::vector<unsigned int> *tgcsl_tilecalobits0_bcid;
   std::vector<unsigned int> *tgcsl_tilecalobits1_bcid;
   std::vector<unsigned int> *tgcsl_tilecalobits2_bcid;
   std::vector<unsigned int> *tgcsl_tilecalobits3_bcid;
   std::vector<unsigned int> *tgcsl_coin_bit0;
   std::vector<unsigned int> *tgcsl_coin_bit1;
   std::vector<unsigned int> *tgcsl_coin_bit2;
   std::vector<unsigned int> *tgcsl_coin_bit3;

   // List of branches
   TBranch        *b_nTgcRods;   //!
   TBranch        *b_nTmdbRods;   //!
   TBranch        *b_tmdb_rodid;   //!
   TBranch        *b_tmdb_isAside;   //!
   TBranch        *b_tmdb_rod_bcid;   //!
   TBranch        *b_tmdb_rod_bcid6b;   //!
   TBranch        *b_tmdb_phi;   //!
   TBranch        *b_tmdb_adc_values;   //!
   TBranch        *b_tmdb_adc_nsamples;   //!
   TBranch        *b_tmdb_energy_values;   //!
   TBranch        *b_tmdb_sl_result0;   //!
   TBranch        *b_tmdb_sl_result1;   //!
   TBranch        *b_tmdb_sl_result2;   //!
   TBranch        *b_tmdb_sl_result0_bcid;   //!
   TBranch        *b_tmdb_sl_result1_bcid;   //!
   TBranch        *b_tmdb_sl_result2_bcid;   //!
   TBranch        *b_tgcsl_rodid_prev;   //!
   TBranch        *b_tgcsl_rodid_curr;   //!
   TBranch        *b_tgcsl_rodid_next;   //!
   TBranch        *b_tgcsl_rod_bcid_prev;   //!
   TBranch        *b_tgcsl_rod_bcid_curr;   //!
   TBranch        *b_tgcsl_rod_bcid_next;   //!
   TBranch        *b_tgcsl_rod_bcid6b_prev;   //!
   TBranch        *b_tgcsl_rod_bcid6b_curr;   //!
   TBranch        *b_tgcsl_rod_bcid6b_next;   //!
   TBranch        *b_tgcsl_sector_prev;   //!
   TBranch        *b_tgcsl_sector_curr;   //!
   TBranch        *b_tgcsl_sector_next;   //!
   TBranch        *b_tgcsl_isAside_prev;   //!
   TBranch        *b_tgcsl_isAside_curr;   //!
   TBranch        *b_tgcsl_isAside_next;   //!
   TBranch        *b_tgcsl_tmdb_tilecalbits_prev;   //!
   TBranch        *b_tgcsl_tmdb_loc_prev;   //!
   TBranch        *b_tgcsl_tmdb_tilecalbits_curr;   //!
   TBranch        *b_tgcsl_tmdb_loc_curr;   //!
   TBranch        *b_tgcsl_tmdb_tilecalbits_next;   //!
   TBranch        *b_tgcsl_tmdb_loc_next;   //!
   TBranch        *b_tgcsl_tmdb_tilecalbits_bcid_prev;   //!
   TBranch        *b_tgcsl_tmdb_tilecalbits_bcid_curr;   //!
   TBranch        *b_tgcsl_tmdb_tilecalbits_bcid_next;   //!
   TBranch        *b_tgcsl_rodid;   //!
   TBranch        *b_tgcsl_sectorid;   //!
   TBranch        *b_tgcsl_isAside;   //!
   TBranch        *b_tgcsl_rod_bcid;   //!
   TBranch        *b_tgcsl_rod_bcid6b;   //!
   TBranch        *b_tgcsl_correspondingtile0_bcid;   //!
   TBranch        *b_tgcsl_correspondingtile1_bcid;   //!
   TBranch        *b_tgcsl_correspondingtile2_bcid;   //!
   TBranch        *b_tgcsl_correspondingtile3_bcid;   //!
   TBranch        *b_tgcsl_correspondingtile0;   //!
   TBranch        *b_tgcsl_correspondingtile1;   //!
   TBranch        *b_tgcsl_correspondingtile2;   //!
   TBranch        *b_tgcsl_correspondingtile3;   //!
   TBranch        *b_tgcsl_bctiming;   //!
   TBranch        *b_tgcsl_tilecalobits0;   //!
   TBranch        *b_tgcsl_tilecalobits1;   //!
   TBranch        *b_tgcsl_tilecalobits2;   //!
   TBranch        *b_tgcsl_tilecalobits3;   //!
   TBranch        *b_tgcsl_tilecalobits0_bcid;   //!
   TBranch        *b_tgcsl_tilecalobits1_bcid;   //!
   TBranch        *b_tgcsl_tilecalobits2_bcid;   //!
   TBranch        *b_tgcsl_tilecalobits3_bcid;   //!
   TBranch        *b_tgcsl_coin_bit0;   //!
   TBranch        *b_tgcsl_coin_bit1;   //!
   TBranch        *b_tgcsl_coin_bit2;   //!
   TBranch        *b_tgcsl_coin_bit3;   //!

   NtupleAnalysisBase(TTree *tree=0);
   virtual ~NtupleAnalysisBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef NtupleAnalysisBase_cxx
NtupleAnalysisBase::NtupleAnalysisBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/cern.ch/user/a/akhigash/tileMuonDecoder/data17_13TeV.00337005.physics_Main.daq.RAW._lb0200._SFO-1_0001._0001.data.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/afs/cern.ch/user/a/akhigash/tileMuonDecoder/data17_13TeV.00337005.physics_Main.daq.RAW._lb0200._SFO-1_0001._0001.data.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

NtupleAnalysisBase::~NtupleAnalysisBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t NtupleAnalysisBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t NtupleAnalysisBase::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void NtupleAnalysisBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   tmdb_rodid = 0;
   tmdb_isAside = 0;
   tmdb_rod_bcid = 0;
   tmdb_rod_bcid6b = 0;
   tmdb_phi = 0;
   tmdb_adc_values = 0;
   tmdb_adc_nsamples = 0;
   tmdb_energy_values = 0;
   tmdb_sl_result0 = 0;
   tmdb_sl_result1 = 0;
   tmdb_sl_result2 = 0;
   tmdb_sl_result0_bcid = 0;
   tmdb_sl_result1_bcid = 0;
   tmdb_sl_result2_bcid = 0;
   tgcsl_rodid_prev = 0;
   tgcsl_rodid_curr = 0;
   tgcsl_rodid_next = 0;
   tgcsl_rod_bcid_prev = 0;
   tgcsl_rod_bcid_curr = 0;
   tgcsl_rod_bcid_next = 0;
   tgcsl_rod_bcid6b_prev = 0;
   tgcsl_rod_bcid6b_curr = 0;
   tgcsl_rod_bcid6b_next = 0;
   tgcsl_sector_prev = 0;
   tgcsl_sector_curr = 0;
   tgcsl_sector_next = 0;
   tgcsl_isAside_prev = 0;
   tgcsl_isAside_curr = 0;
   tgcsl_isAside_next = 0;
   tgcsl_tmdb_tilecalbits_prev = 0;
   tgcsl_tmdb_loc_prev = 0;
   tgcsl_tmdb_tilecalbits_curr = 0;
   tgcsl_tmdb_loc_curr = 0;
   tgcsl_tmdb_tilecalbits_next = 0;
   tgcsl_tmdb_loc_next = 0;
   tgcsl_tmdb_tilecalbits_bcid_prev = 0;
   tgcsl_tmdb_tilecalbits_bcid_curr = 0;
   tgcsl_tmdb_tilecalbits_bcid_next = 0;
   tgcsl_rodid = 0;
   tgcsl_sectorid = 0;
   tgcsl_isAside = 0;
   tgcsl_rod_bcid = 0;
   tgcsl_rod_bcid6b = 0;
   tgcsl_correspondingtile0_bcid = 0;
   tgcsl_correspondingtile1_bcid = 0;
   tgcsl_correspondingtile2_bcid = 0;
   tgcsl_correspondingtile3_bcid = 0;
   tgcsl_correspondingtile0 = 0;
   tgcsl_correspondingtile1 = 0;
   tgcsl_correspondingtile2 = 0;
   tgcsl_correspondingtile3 = 0;
   tgcsl_bctiming = 0;
   tgcsl_tilecalobits0 = 0;
   tgcsl_tilecalobits1 = 0;
   tgcsl_tilecalobits2 = 0;
   tgcsl_tilecalobits3 = 0;
   tgcsl_tilecalobits0_bcid = 0;
   tgcsl_tilecalobits1_bcid = 0;
   tgcsl_tilecalobits2_bcid = 0;
   tgcsl_tilecalobits3_bcid = 0;
   tgcsl_coin_bit0 = 0;
   tgcsl_coin_bit1 = 0;
   tgcsl_coin_bit2 = 0;
   tgcsl_coin_bit3 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nTgcRods", &nTgcRods, &b_nTgcRods);
   fChain->SetBranchAddress("nTmdbRods", &nTmdbRods, &b_nTmdbRods);
   fChain->SetBranchAddress("tmdb_rodid", &tmdb_rodid, &b_tmdb_rodid);
   fChain->SetBranchAddress("tmdb_isAside", &tmdb_isAside, &b_tmdb_isAside);
   fChain->SetBranchAddress("tmdb_rod_bcid", &tmdb_rod_bcid, &b_tmdb_rod_bcid);
   fChain->SetBranchAddress("tmdb_rod_bcid6b", &tmdb_rod_bcid6b, &b_tmdb_rod_bcid6b);
   fChain->SetBranchAddress("tmdb_phi", &tmdb_phi, &b_tmdb_phi);
   fChain->SetBranchAddress("tmdb_adc_values", &tmdb_adc_values, &b_tmdb_adc_values);
   fChain->SetBranchAddress("tmdb_adc_nsamples", &tmdb_adc_nsamples, &b_tmdb_adc_nsamples);
   fChain->SetBranchAddress("tmdb_energy_values", &tmdb_energy_values, &b_tmdb_energy_values);
   fChain->SetBranchAddress("tmdb_sl_result0", &tmdb_sl_result0, &b_tmdb_sl_result0);
   fChain->SetBranchAddress("tmdb_sl_result1", &tmdb_sl_result1, &b_tmdb_sl_result1);
   fChain->SetBranchAddress("tmdb_sl_result2", &tmdb_sl_result2, &b_tmdb_sl_result2);
   fChain->SetBranchAddress("tmdb_sl_result0_bcid", &tmdb_sl_result0_bcid, &b_tmdb_sl_result0_bcid);
   fChain->SetBranchAddress("tmdb_sl_result1_bcid", &tmdb_sl_result1_bcid, &b_tmdb_sl_result1_bcid);
   fChain->SetBranchAddress("tmdb_sl_result2_bcid", &tmdb_sl_result2_bcid, &b_tmdb_sl_result2_bcid);
   fChain->SetBranchAddress("tgcsl_rodid_prev", &tgcsl_rodid_prev, &b_tgcsl_rodid_prev);
   fChain->SetBranchAddress("tgcsl_rodid_curr", &tgcsl_rodid_curr, &b_tgcsl_rodid_curr);
   fChain->SetBranchAddress("tgcsl_rodid_next", &tgcsl_rodid_next, &b_tgcsl_rodid_next);
   fChain->SetBranchAddress("tgcsl_rod_bcid_prev", &tgcsl_rod_bcid_prev, &b_tgcsl_rod_bcid_prev);
   fChain->SetBranchAddress("tgcsl_rod_bcid_curr", &tgcsl_rod_bcid_curr, &b_tgcsl_rod_bcid_curr);
   fChain->SetBranchAddress("tgcsl_rod_bcid_next", &tgcsl_rod_bcid_next, &b_tgcsl_rod_bcid_next);
   fChain->SetBranchAddress("tgcsl_rod_bcid6b_prev", &tgcsl_rod_bcid6b_prev, &b_tgcsl_rod_bcid6b_prev);
   fChain->SetBranchAddress("tgcsl_rod_bcid6b_curr", &tgcsl_rod_bcid6b_curr, &b_tgcsl_rod_bcid6b_curr);
   fChain->SetBranchAddress("tgcsl_rod_bcid6b_next", &tgcsl_rod_bcid6b_next, &b_tgcsl_rod_bcid6b_next);
   fChain->SetBranchAddress("tgcsl_sector_prev", &tgcsl_sector_prev, &b_tgcsl_sector_prev);
   fChain->SetBranchAddress("tgcsl_sector_curr", &tgcsl_sector_curr, &b_tgcsl_sector_curr);
   fChain->SetBranchAddress("tgcsl_sector_next", &tgcsl_sector_next, &b_tgcsl_sector_next);
   fChain->SetBranchAddress("tgcsl_isAside_prev", &tgcsl_isAside_prev, &b_tgcsl_isAside_prev);
   fChain->SetBranchAddress("tgcsl_isAside_curr", &tgcsl_isAside_curr, &b_tgcsl_isAside_curr);
   fChain->SetBranchAddress("tgcsl_isAside_next", &tgcsl_isAside_next, &b_tgcsl_isAside_next);
   fChain->SetBranchAddress("tgcsl_tmdb_tilecalbits_prev", &tgcsl_tmdb_tilecalbits_prev, &b_tgcsl_tmdb_tilecalbits_prev);
   fChain->SetBranchAddress("tgcsl_tmdb_loc_prev", &tgcsl_tmdb_loc_prev, &b_tgcsl_tmdb_loc_prev);
   fChain->SetBranchAddress("tgcsl_tmdb_tilecalbits_curr", &tgcsl_tmdb_tilecalbits_curr, &b_tgcsl_tmdb_tilecalbits_curr);
   fChain->SetBranchAddress("tgcsl_tmdb_loc_curr", &tgcsl_tmdb_loc_curr, &b_tgcsl_tmdb_loc_curr);
   fChain->SetBranchAddress("tgcsl_tmdb_tilecalbits_next", &tgcsl_tmdb_tilecalbits_next, &b_tgcsl_tmdb_tilecalbits_next);
   fChain->SetBranchAddress("tgcsl_tmdb_loc_next", &tgcsl_tmdb_loc_next, &b_tgcsl_tmdb_loc_next);
   fChain->SetBranchAddress("tgcsl_tmdb_tilecalbits_bcid_prev", &tgcsl_tmdb_tilecalbits_bcid_prev, &b_tgcsl_tmdb_tilecalbits_bcid_prev);
   fChain->SetBranchAddress("tgcsl_tmdb_tilecalbits_bcid_curr", &tgcsl_tmdb_tilecalbits_bcid_curr, &b_tgcsl_tmdb_tilecalbits_bcid_curr);
   fChain->SetBranchAddress("tgcsl_tmdb_tilecalbits_bcid_next", &tgcsl_tmdb_tilecalbits_bcid_next, &b_tgcsl_tmdb_tilecalbits_bcid_next);
   fChain->SetBranchAddress("tgcsl_rodid", &tgcsl_rodid, &b_tgcsl_rodid);
   fChain->SetBranchAddress("tgcsl_sectorid", &tgcsl_sectorid, &b_tgcsl_sectorid);
   fChain->SetBranchAddress("tgcsl_isAside", &tgcsl_isAside, &b_tgcsl_isAside);
   fChain->SetBranchAddress("tgcsl_rod_bcid", &tgcsl_rod_bcid, &b_tgcsl_rod_bcid);
   fChain->SetBranchAddress("tgcsl_rod_bcid6b", &tgcsl_rod_bcid6b, &b_tgcsl_rod_bcid6b);
   fChain->SetBranchAddress("tgcsl_correspondingtile0_bcid", &tgcsl_correspondingtile0_bcid, &b_tgcsl_correspondingtile0_bcid);
   fChain->SetBranchAddress("tgcsl_correspondingtile1_bcid", &tgcsl_correspondingtile1_bcid, &b_tgcsl_correspondingtile1_bcid);
   fChain->SetBranchAddress("tgcsl_correspondingtile2_bcid", &tgcsl_correspondingtile2_bcid, &b_tgcsl_correspondingtile2_bcid);
   fChain->SetBranchAddress("tgcsl_correspondingtile3_bcid", &tgcsl_correspondingtile3_bcid, &b_tgcsl_correspondingtile3_bcid);
   fChain->SetBranchAddress("tgcsl_correspondingtile0", &tgcsl_correspondingtile0, &b_tgcsl_correspondingtile0);
   fChain->SetBranchAddress("tgcsl_correspondingtile1", &tgcsl_correspondingtile1, &b_tgcsl_correspondingtile1);
   fChain->SetBranchAddress("tgcsl_correspondingtile2", &tgcsl_correspondingtile2, &b_tgcsl_correspondingtile2);
   fChain->SetBranchAddress("tgcsl_correspondingtile3", &tgcsl_correspondingtile3, &b_tgcsl_correspondingtile3);
   fChain->SetBranchAddress("tgcsl_bctiming", &tgcsl_bctiming, &b_tgcsl_bctiming);
   fChain->SetBranchAddress("tgcsl_tilecalobits0", &tgcsl_tilecalobits0, &b_tgcsl_tilecalobits0);
   fChain->SetBranchAddress("tgcsl_tilecalobits1", &tgcsl_tilecalobits1, &b_tgcsl_tilecalobits1);
   fChain->SetBranchAddress("tgcsl_tilecalobits2", &tgcsl_tilecalobits2, &b_tgcsl_tilecalobits2);
   fChain->SetBranchAddress("tgcsl_tilecalobits3", &tgcsl_tilecalobits3, &b_tgcsl_tilecalobits3);
   fChain->SetBranchAddress("tgcsl_tilecalobits0_bcid", &tgcsl_tilecalobits0_bcid, &b_tgcsl_tilecalobits0_bcid);
   fChain->SetBranchAddress("tgcsl_tilecalobits1_bcid", &tgcsl_tilecalobits1_bcid, &b_tgcsl_tilecalobits1_bcid);
   fChain->SetBranchAddress("tgcsl_tilecalobits2_bcid", &tgcsl_tilecalobits2_bcid, &b_tgcsl_tilecalobits2_bcid);
   fChain->SetBranchAddress("tgcsl_tilecalobits3_bcid", &tgcsl_tilecalobits3_bcid, &b_tgcsl_tilecalobits3_bcid);
   fChain->SetBranchAddress("tgcsl_coin_bit0", &tgcsl_coin_bit0, &b_tgcsl_coin_bit0);
   fChain->SetBranchAddress("tgcsl_coin_bit1", &tgcsl_coin_bit1, &b_tgcsl_coin_bit1);
   fChain->SetBranchAddress("tgcsl_coin_bit2", &tgcsl_coin_bit2, &b_tgcsl_coin_bit2);
   fChain->SetBranchAddress("tgcsl_coin_bit3", &tgcsl_coin_bit3, &b_tgcsl_coin_bit3);
   Notify();
}

Bool_t NtupleAnalysisBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void NtupleAnalysisBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t NtupleAnalysisBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef NtupleAnalysisBase_cxx
