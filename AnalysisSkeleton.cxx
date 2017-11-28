#include "AnalysisSkeleton.hxx"
#include <iostream>
#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"
#include "TStyle.h"
#include "TPaveStats.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "examplePlotter.C"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <map>

using namespace std;

void AnalysisSkeleton::Loop()
{
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  int FirmwareFlag = 0;

  const int NumberOfSides = 2;
  const int NumberOfRods = 48;
  const int NumberOfRODperSector = 4;
  const int NumberOfBC = 3;
  const int NumberOfTMDBs = 8;
  const int NumberOfTileEBs  = 64;
  const int NumberOfSLs = 24;
  const int NumberOfModuleperTMDB = 8;

  TH1D *h_Curr[NumberOfSides];
  TH1D *h_Prev[NumberOfSides];
  TH1D *h_Next[NumberOfSides];
  TH1D *h_NonZeroTile[NumberOfSides];
  for(int ii = 0; ii < NumberOfSides; ii++){
      h_Curr[ii] = new TH1D(Form("h_Curr_%d", ii),"Current Events",48,-0.5,47.5);
      h_Prev[ii] = new TH1D(Form("h_Prev_%d", ii),"Previous Events",48,-0.5,47.5);
      h_Next[ii] = new TH1D(Form("h_Next_%d", ii),"Next Events",48,-0.5,47.5);
      h_NonZeroTile[ii] = new TH1D(Form("h_NonZeroTile_%d", ii),"Non-zero Tile Events",48,-0.5,47.5);
  }
  
  int CorrSL[NumberOfRods];
  for(int ii = 0; ii < NumberOfRods; ii++){
    CorrSL[ii] = 0;
    CorrSL[ii] = ii / 2 + 1;
  }

  int Mask[6];
  for(int ii = 0; ii < 6; ii++){
    Mask[ii] = 0;
  }
  Mask[2] = 0x3c;
  Mask[3] = 0xf0;
  Mask[4] = 0x0f;
  Mask[5] = 0xf0;
  Mask[0] = 0x0f;
  Mask[1] = 0x3c;
  
  int CorrSL_EB[NumberOfTileEBs];
  for(int ii = 0; ii < NumberOfTileEBs; ii++){
    CorrSL_EB[ii] = 0;
  }
  CorrSL_EB[3] = 2;
  CorrSL_EB[5] = 3;
  CorrSL_EB[7] = 4;
  CorrSL_EB[11] = 5;
  CorrSL_EB[13] = 6;
  CorrSL_EB[15] = 7;
  CorrSL_EB[19] = 8;
  CorrSL_EB[21] = 9;
  CorrSL_EB[23] = 10;
  CorrSL_EB[27] = 11;
  CorrSL_EB[29] = 12;
  CorrSL_EB[31] = 13;
  CorrSL_EB[35] = 14;
  CorrSL_EB[37] = 15;
  CorrSL_EB[39] = 16;
  CorrSL_EB[43] = 17;
  CorrSL_EB[45] = 18;
  CorrSL_EB[47] = 19;
  CorrSL_EB[51] = 20;
  CorrSL_EB[53] = 21;
  CorrSL_EB[55] = 22;
  CorrSL_EB[59] = 23;
  CorrSL_EB[61] = 24;
  CorrSL_EB[63] = 1;
  
  int CorrTGC_2[NumberOfTileEBs];
  for(int ii = 0; ii < NumberOfTileEBs; ii++){
    CorrTGC_2[ii] = 0;
  }
  CorrTGC_2[3] = 3;
  CorrTGC_2[5] = 5;
  CorrTGC_2[7] = 7;
  CorrTGC_2[11] = 9;
  CorrTGC_2[13] = 11;
  CorrTGC_2[15] = 13;
  CorrTGC_2[19] = 15;
  CorrTGC_2[21] = 17;
  CorrTGC_2[23] = 19;
  CorrTGC_2[27] = 21;
  CorrTGC_2[29] = 23;
  CorrTGC_2[31] = 25;
  CorrTGC_2[35] = 27;
  CorrTGC_2[37] = 29;
  CorrTGC_2[39] = 31;
  CorrTGC_2[43] = 33;
  CorrTGC_2[45] = 35;
  CorrTGC_2[47] = 37;
  CorrTGC_2[51] = 39;
  CorrTGC_2[53] = 41;
  CorrTGC_2[55] = 43;
  CorrTGC_2[59] = 45;
  CorrTGC_2[61] = 47;
  CorrTGC_2[63] = 1;
  

  int NEntry = 0;

  for (Long64_t jentry = 0; jentry < nentries ; jentry++) {
    NEntry++;
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    int SizeZeroFlag = 0;    
    if(tgcsl_rod_bcid->size() == 0){
      SizeZeroFlag = 1;
    }
    
    //compare Curr with Prev and Next
    unsigned int tile8bit[NumberOfRODperSector][NumberOfBC];
    unsigned int tgc8bit[NumberOfRODperSector][NumberOfBC];
    unsigned int diff8bit[NumberOfRODperSector][NumberOfBC];

    unsigned int tgc8bitCurr_sort[NumberOfSides][NumberOfRods];
    for(int ii = 0; ii < NumberOfSides; ii++){
      for(int kk = 0; kk < NumberOfRods; kk++){
	tgc8bitCurr_sort[ii][kk] = 0;
      }
    }
    
    for(int ii = 0; ii < NumberOfRODperSector; ii++){
      for(int kk = 0; kk < NumberOfBC; kk++){
	tile8bit[ii][kk] = 0;
	tgc8bit[ii][kk] = 0;
	diff8bit[ii][kk] = 0;
      }
    }

     //compare Curr with Prev and Next
    unsigned int tile8bit_SL[NumberOfSides][NumberOfSLs];
    for(int ii = 0; ii < NumberOfSides; ii++){
      for(int kk = 0; kk < NumberOfSLs; kk++){
	tile8bit_SL[ii][kk] = 0;
      }
    } 
    unsigned int resultEB[NumberOfSides][NumberOfTMDBs][NumberOfModuleperTMDB];
    unsigned int resultOrD5D6[NumberOfSides][NumberOfTMDBs][NumberOfModuleperTMDB];
    unsigned int resultOrD6[NumberOfSides][NumberOfTMDBs][NumberOfModuleperTMDB];
    double RawCountD5D6[NumberOfSides][NumberOfTMDBs][NumberOfModuleperTMDB];
    double RawCountD6[NumberOfSides][NumberOfTMDBs][NumberOfModuleperTMDB];
    int D5D6H[NumberOfSides][NumberOfTMDBs][NumberOfModuleperTMDB];
    int D5D6L[NumberOfSides][NumberOfTMDBs][NumberOfModuleperTMDB];
    int D6H[NumberOfSides][NumberOfTMDBs][NumberOfModuleperTMDB];
    int D6L[NumberOfSides][NumberOfTMDBs][NumberOfModuleperTMDB];
    for(int ii = 0; ii < NumberOfSides; ii++){
      for(int kk = 0; kk < NumberOfTMDBs; kk++){
	for(int jj = 0; jj < NumberOfModuleperTMDB; jj++){
	  resultEB[ii][kk][jj] = 0;
	  resultOrD5D6[ii][kk][jj] = 0;
	  resultOrD6[ii][kk][jj] = 0;
	  RawCountD5D6[ii][kk][jj] = 0.;
	  RawCountD6[ii][kk][jj] = 0.;
	  D5D6H[ii][kk][jj] = 0;
	  D5D6L[ii][kk][jj] = 0;
	  D6H[ii][kk][jj] = 0;
	  D6L[ii][kk][jj] = 0;
	}
      }
    }
    
    for(int iTmdbSlRod = 0,nTmdbSlRods = tmdb_rod_bcid->size(); iTmdbSlRod < nTmdbSlRods; iTmdbSlRod++){
      const unsigned int& rodid = tmdb_rodid->at(iTmdbSlRod);
      const unsigned int& isAside = tmdb_isAside->at(iTmdbSlRod);
      const unsigned int& phi = tmdb_phi->at(iTmdbSlRod);
      vector <uint32_t>& EnergyValues = tmdb_energy_values->at(iTmdbSlRod);
      int EnergySize = EnergyValues.size();
       int SideFlag = 0;
      if(isAside != 1){
	SideFlag = 1;
      }
      for(int ii = 0; ii < EnergySize; ii++){
	if(ii >= 0 && ii <= 3){
	  RawCountD5D6[SideFlag][phi][0]+= EnergyValues.at(ii);
	  if(ii >= 2){
	    RawCountD6[SideFlag][phi][0]+= EnergyValues.at(ii);
	  }
	}
	if(ii >= 4 && ii <= 7){
	  RawCountD5D6[SideFlag][phi][1]+= EnergyValues.at(ii);
	  if(ii >= 6){
	    RawCountD6[SideFlag][phi][1]+= EnergyValues.at(ii);
	  }
	}
	if(ii >= 8 && ii <= 11){
	  RawCountD5D6[SideFlag][phi][2]+= EnergyValues.at(ii);
	  if(ii >= 10){
	    RawCountD6[SideFlag][phi][2]+= EnergyValues.at(ii);
	  }
	}
	if(ii >= 12 && ii <= 15){
	  RawCountD5D6[SideFlag][phi][3]+= EnergyValues.at(ii);
	  if(ii >= 14){
	    RawCountD6[SideFlag][phi][3]+= EnergyValues.at(ii);
	  }
	}
	if(ii >= 16 && ii <= 19){
	  RawCountD5D6[SideFlag][phi][4]+= EnergyValues.at(ii);
	  if(ii >= 18){
	    RawCountD6[SideFlag][phi][4]+= EnergyValues.at(ii);
	  }
	}
	if(ii >= 20 && ii <= 23){
	  RawCountD5D6[SideFlag][phi][5]+= EnergyValues.at(ii);
	  if(ii >= 22){
	    RawCountD6[SideFlag][phi][5]+= EnergyValues.at(ii);
	  }
	}
	if(ii >= 24 && ii <= 27){
	  RawCountD5D6[SideFlag][phi][6]+= EnergyValues.at(ii);
	  if(ii >= 26){
	    RawCountD6[SideFlag][phi][6]+= EnergyValues.at(ii);
	  }
	}
	if(ii >= 28 && ii <= 31){
	  RawCountD5D6[SideFlag][phi][7]+= EnergyValues.at(ii);
	  if(ii >= 30){
	    RawCountD6[SideFlag][phi][7]+= EnergyValues.at(ii);
	  }
	}
      }
      
      const unsigned int& result0 = tmdb_sl_result0->at(iTmdbSlRod);
      const unsigned int& result1 = tmdb_sl_result1->at(iTmdbSlRod);
      const unsigned int& result2 = tmdb_sl_result2->at(iTmdbSlRod);
      resultEB[SideFlag][phi][0] = ((result0&0X00F0)>>4);
      resultEB[SideFlag][phi][1] = ((result0&0X0F00)>>8);
      resultEB[SideFlag][phi][2] = ((result0&0XF000)>>12);
      resultEB[SideFlag][phi][3] = ((result1&0X00F0)>>4);
      resultEB[SideFlag][phi][4] = ((result1&0X0F00)>>8);
      resultEB[SideFlag][phi][5] = ((result1&0XF000)>>12);
      resultEB[SideFlag][phi][6] = ((result2&0X00F0)>>4);
      resultEB[SideFlag][phi][7] = ((result2&0X0F00)>>8);

      for(int ii = 0; ii < NumberOfModuleperTMDB; ii++){
	D5D6H[SideFlag][phi][ii] = ((resultEB[SideFlag][phi][ii]&0x08)>>3);
	D5D6L[SideFlag][phi][ii] = ((resultEB[SideFlag][phi][ii]&0x04)>>2);
	D6H[SideFlag][phi][ii] = ((resultEB[SideFlag][phi][ii]&0x02)>>1);
	D6L[SideFlag][phi][ii] = (resultEB[SideFlag][phi][ii]&0x01);

	resultOrD5D6[SideFlag][phi][ii] = (((resultEB[SideFlag][phi][ii]&0x08)>>3)|((resultEB[SideFlag][phi][ii]&0x04)>>2));
	resultOrD6[SideFlag][phi][ii] = (((resultEB[SideFlag][phi][ii]&0x02)>>1)|(resultEB[SideFlag][phi][ii]&0x01));
      }
      tile8bit_SL[SideFlag][CorrSL_EB[NumberOfModuleperTMDB * phi + 3] - 1] =
	(resultOrD6[SideFlag][phi][2]<<7) +
	(resultOrD5D6[SideFlag][phi][2]<<6) +
	(resultOrD6[SideFlag][phi][1]<<5) +
	(resultOrD5D6[SideFlag][phi][1]<<4) +
	(resultOrD6[SideFlag][phi][0]<<3) +
	(resultOrD5D6[SideFlag][phi][0]<<2);

      tile8bit_SL[SideFlag][CorrSL_EB[NumberOfModuleperTMDB * phi + 5] - 1] =
       	(resultOrD6[SideFlag][phi][5]<<7) +
       	(resultOrD5D6[SideFlag][phi][5]<<6) +
       	(resultOrD6[SideFlag][phi][4]<<5) +
       	(resultOrD5D6[SideFlag][phi][4]<<4) +
       	(resultOrD6[SideFlag][phi][3]<<3) +
       	(resultOrD5D6[SideFlag][phi][3]<<2) +
       	(resultOrD6[SideFlag][phi][2]<<1) +
       	resultOrD5D6[SideFlag][phi][2];

      tile8bit_SL[SideFlag][CorrSL_EB[NumberOfModuleperTMDB * phi + 7] - 1] =
	(resultOrD6[SideFlag][phi][7]<<5) +
	(resultOrD5D6[SideFlag][phi][7]<<4) +
	(resultOrD6[SideFlag][phi][6]<<3) +
	(resultOrD5D6[SideFlag][phi][6]<<2) +
	(resultOrD6[SideFlag][phi][5]<<1) +
	resultOrD5D6[SideFlag][phi][5];

    }
    
    // Analysis code here
    for (int iTgcSlRod = 0,nTgcSlRods = tgcsl_rod_bcid->size(); iTgcSlRod < nTgcSlRods; iTgcSlRod++) {
      // Set Variables and Constants     
      const unsigned int& rodid = tgcsl_rodid->at(iTgcSlRod);
      const unsigned int& bctiming = tgcsl_bctiming->at(iTgcSlRod);
      if (bctiming!=1) {continue;}
      const unsigned int sector   = (rodid&0x000000FF);
      const unsigned int sourceid = ((rodid&0x00FF0000)>>16);
      const bool isAside = (sourceid==0X67);
      int SideFlag = 0;
      if(!isAside){
	SideFlag = 1;
      }
      int SecID[NumberOfRODperSector];
      int Mod[NumberOfRODperSector];
      for(int ii = 0; ii < NumberOfRODperSector; ii++){
	SecID[ii] = ii + ((sector - 1) * 4) ;
	Mod[ii] = SecID[ii] % 6;
      }

      int bcad[3];
      for(int ii = 0; ii < NumberOfBC; ii++){
	bcad[ii] = ii - 1;
	tgc8bit[0][ii] = 0;
	tgc8bit[1][ii] = 0;
	tgc8bit[2][ii] = 0;
	tgc8bit[3][ii] = 0;
	tgc8bit[0][ii] = tgcsl_tilecalobits0->at(iTgcSlRod + bcad[ii]);
	tgc8bit[1][ii] = tgcsl_tilecalobits1->at(iTgcSlRod + bcad[ii]);
	tgc8bit[2][ii] = tgcsl_tilecalobits2->at(iTgcSlRod + bcad[ii]);
	tgc8bit[3][ii] = tgcsl_tilecalobits3->at(iTgcSlRod + bcad[ii]);
      }

      tgc8bitCurr_sort[SideFlag][SecID[0]] = tgc8bit[0][1];
      tgc8bitCurr_sort[SideFlag][SecID[1]] = tgc8bit[1][1];
      tgc8bitCurr_sort[SideFlag][SecID[2]] = tgc8bit[2][1];
      tgc8bitCurr_sort[SideFlag][SecID[3]] = tgc8bit[3][1];
      // Set Variables and Constants

      //Check Trigger Hit Pattern
      for(int ii = 0; ii < NumberOfRODperSector; ii++){
	tile8bit[ii][1] = tile8bit_SL[SideFlag][CorrSL[SecID[ii]] - 1];
	for(int kk = 0; kk < NumberOfBC; kk++){
	  if(tgc8bit[ii][kk] == 16777215){
	    tgc8bit[ii][kk] = 0;
	  }
	  diff8bit[ii][kk] = tile8bit[ii][1] - tgc8bit[ii][kk];
	}
      }

      for(int ii = 0; ii < NumberOfRODperSector; ii++){
	if(tile8bit[ii][1] == 0){
	  continue;
	}
		
	h_NonZeroTile[SideFlag]->Fill(SecID[ii]);
	if(diff8bit[ii][1] == 0){
	  h_Curr[SideFlag]->Fill(SecID[ii]);
	}
	if(diff8bit[ii][0] == 0){
	  h_Prev[SideFlag]->Fill(SecID[ii]);
	}
	if(diff8bit[ii][2] == 0){
	  h_Next[SideFlag]->Fill(SecID[ii]);
	}
      }
    }

  }

  double Accuracy_Curr[NumberOfSides][NumberOfRods];
  double Accuracy_Prev[NumberOfSides][NumberOfRods];
  double Accuracy_Next[NumberOfSides][NumberOfRods];

  double N_Curr[NumberOfSides][NumberOfRods];
  double N_Prev[NumberOfSides][NumberOfRods];
  double N_Next[NumberOfSides][NumberOfRods];

  int N_Curr_OK = 0;
  int N_Prev_OK = 0;
  int N_Next_OK = 0;
  
   for(int ii = 0; ii < NumberOfSides; ii++){
    for(int kk = 0; kk <  NumberOfRods; kk++){
      if(h_NonZeroTile[ii]->GetBinContent(kk + 1) != 0){
	N_Curr[ii][kk] = h_Curr[ii]->GetBinContent(kk + 1);
	N_Prev[ii][kk] = h_Prev[ii]->GetBinContent(kk + 1);
	N_Next[ii][kk] = h_Next[ii]->GetBinContent(kk + 1);
	Accuracy_Curr[ii][kk] = double(h_Curr[ii]->GetBinContent(kk + 1)) / double(h_NonZeroTile[ii]->GetBinContent(kk + 1));
	Accuracy_Prev[ii][kk] = double(h_Prev[ii]->GetBinContent(kk + 1)) / double(h_NonZeroTile[ii]->GetBinContent(kk + 1));
	Accuracy_Next[ii][kk] = double(h_Next[ii]->GetBinContent(kk + 1)) / double(h_NonZeroTile[ii]->GetBinContent(kk + 1));
      }
    }
  }

   TCanvas c_4Graphs;
   c_4Graphs.Divide(2,2);
   
   SetAtlasStyle();
   TGraph gr_A_Curr;
   TGraph gr_A_Prev;
   TGraph gr_A_Next;
 
   gr_A_Curr.SetMarkerColor(kBlack);
   gr_A_Prev.SetMarkerColor(kRed);
   gr_A_Next.SetMarkerColor(kBlue);
   
   gr_A_Curr.SetLineWidth(0);
   gr_A_Prev.SetLineWidth(0);
   gr_A_Next.SetLineWidth(0);
   
   TGraph gr_C_Curr;
   TGraph gr_C_Prev;
   TGraph gr_C_Next;

   gr_C_Curr.SetMarkerColor(kBlack);
   gr_C_Prev.SetMarkerColor(kRed);
   gr_C_Next.SetMarkerColor(kBlue);
   
   gr_C_Curr.SetLineWidth(0);
   gr_C_Prev.SetLineWidth(0);
   gr_C_Next.SetLineWidth(0);

   TGraph gr_A_N_Curr;
   TGraph gr_A_N_Prev;
   TGraph gr_A_N_Next;

   gr_A_N_Curr.SetMarkerColor(kBlack);
   gr_A_N_Prev.SetMarkerColor(kRed);
   gr_A_N_Next.SetMarkerColor(kBlue);

   gr_A_N_Curr.SetLineWidth(0);
   gr_A_N_Prev.SetLineWidth(0);
   gr_A_N_Next.SetLineWidth(0);

   TGraph gr_C_N_Curr;
   TGraph gr_C_N_Prev;
   TGraph gr_C_N_Next;

   gr_C_N_Curr.SetMarkerColor(kBlack);
   gr_C_N_Prev.SetMarkerColor(kRed);
   gr_C_N_Next.SetMarkerColor(kBlue);

   gr_C_N_Curr.SetLineWidth(0);
   gr_C_N_Prev.SetLineWidth(0);
   gr_C_N_Next.SetLineWidth(0);

   gStyle->SetMarkerStyle(8);
   gStyle->SetMarkerSize(0.4);
   
   for (int ii = 0; ii < NumberOfRods; ii++){
     gr_A_Curr.SetPoint(ii, ii, Accuracy_Curr[0][ii]);
     gr_A_Prev.SetPoint(ii, ii, Accuracy_Prev[0][ii]);
     gr_A_Next.SetPoint(ii, ii, Accuracy_Next[0][ii]);
     gr_C_Curr.SetPoint(ii, ii, Accuracy_Curr[1][ii]);
     gr_C_Prev.SetPoint(ii, ii, Accuracy_Prev[1][ii]);
     gr_C_Next.SetPoint(ii, ii, Accuracy_Next[1][ii]);
     
     gr_A_N_Curr.SetPoint(ii, ii, N_Curr[0][ii]);
     gr_A_N_Prev.SetPoint(ii, ii, N_Prev[0][ii]);
     gr_A_N_Next.SetPoint(ii, ii, N_Next[0][ii]);
     gr_C_N_Curr.SetPoint(ii, ii, N_Curr[1][ii]);
     gr_C_N_Prev.SetPoint(ii, ii, N_Prev[1][ii]);
     gr_C_N_Next.SetPoint(ii, ii, N_Next[1][ii]);
   }
   
   TCanvas c_A_3BC;
   c_A_3BC.cd();

   TH2D waku("waku", "", 1, -0.5, 47.5, 1, 0, 1.1);
   TH2D waku_nonzero("waku_nonzero", "", 1, -0.5, 47.5, 1, 0, 20000);
   waku.GetXaxis()->SetTitle("TGC Trigger Sector");
   waku.GetYaxis()->SetTitle("Good Event rate");
   waku_nonzero.GetXaxis()->SetTitle("TGC Trigger Sector");
   waku_nonzero.GetYaxis()->SetTitle("Events");
   waku.Draw();
   
   gr_A_Prev.Draw("PL");
   gr_A_Next.Draw("PL");
   gr_A_Curr.Draw("PL");

   TLegend leg_A_3BC(0.78, 0.6, 0.98, 0.85);
   leg_A_3BC.SetLineWidth(0);
   leg_A_3BC.SetFillColor(0);
   leg_A_3BC.AddEntry(&gr_A_Curr, "Curr", "PL");
   leg_A_3BC.AddEntry(&gr_A_Prev, "Prev", "PL");
   leg_A_3BC.AddEntry(&gr_A_Next, "Next", "PL");
   leg_A_3BC.Draw();
   
   TLatex label = GetAtlaslabel(0.78, 0.55, "Internal");
   label.Draw();
   
   c_A_3BC.Print("graph_A_3BC.pdf");

   TCanvas c_C_3BC;
   c_C_3BC.cd();
 
   waku.Draw();
   gr_C_Prev.Draw("PL");
   gr_C_Next.Draw("PL");
   gr_C_Curr.Draw("PL");
  
   TLegend leg_C_3BC(0.78, 0.3, 0.98, 0.55);
   leg_C_3BC.SetLineWidth(0);
   leg_C_3BC.SetFillColor(0);
   leg_C_3BC.AddEntry(&gr_C_Curr, "Curr", "PL");
   leg_C_3BC.AddEntry(&gr_C_Prev, "Prev", "PL");
   leg_C_3BC.AddEntry(&gr_C_Next, "Next", "PL");

   c_C_3BC.Print("graph_C_3BC.pdf");

   TCanvas c_A_NonZero;
   c_A_NonZero.cd();
   waku_nonzero.Draw();

   h_NonZeroTile[0]->SetMinimum(0);
   h_NonZeroTile[0]->SetMaximum(20000);
   h_NonZeroTile[0]->Draw();
   gr_A_N_Curr.Draw("PL");
   gr_A_N_Prev.Draw("PL");
   gr_A_N_Next.Draw("PL");

   TLegend leg_A_NonZero(0.78, 0.3, 0.98, 0.55);
   leg_A_NonZero.SetLineWidth(0);
   leg_A_NonZero.SetFillColor(0);
   leg_A_NonZero.AddEntry(&gr_A_N_Curr, "Curr", "PL");
   leg_A_NonZero.AddEntry(&gr_A_N_Prev, "Prev", "PL");
   leg_A_NonZero.AddEntry(&gr_A_N_Next, "Next", "PL");

   //   leg_A_NonZero.Draw();

   //   label.Draw();

   c_A_NonZero.Print("graph_A_NonZero.pdf");
   
   TCanvas c_C_NonZero;
   c_C_NonZero.cd();
   waku_nonzero.Draw();

   h_NonZeroTile[1]->SetMinimum(0);
   h_NonZeroTile[1]->SetMaximum(20000);
   h_NonZeroTile[1]->Draw();
   gr_C_N_Curr.Draw("PL");
   gr_C_N_Prev.Draw("PL");
   gr_C_N_Next.Draw("PL");

   TLegend leg_C_NonZero(0.78, 0.3, 0.98, 0.55);
   leg_C_NonZero.SetLineWidth(0);
   leg_C_NonZero.SetFillColor(0);
   leg_C_NonZero.AddEntry(&gr_C_N_Curr, "Curr", "PL");
   leg_C_NonZero.AddEntry(&gr_C_N_Prev, "Prev", "PL");
   leg_C_NonZero.AddEntry(&gr_C_N_Next, "Next", "PL");

   //   leg_C_NonZero.Draw();

   //   label.Draw();

   c_C_NonZero.Print("graph_C_NonZero.pdf");
   
   cerr << "----------Not Perfect Sectors----------" << endl;
   for(int ii = 0; ii < NumberOfSides; ii++){
     for(int kk = 0; kk < NumberOfRods; kk++){
       if(Accuracy_Curr[ii][kk] != 1 && Accuracy_Prev[ii][kk] != 1 && Accuracy_Next[ii][kk]!= 1){
	 cerr << "Side = "<< ii << ",TGC Trigger Sector =" << kk << ",N_Error ="<< h_NonZeroTile[ii]->GetBinContent(kk + 1) - h_Curr[ii]->GetBinContent(kk + 1) << ", Curr = " << Accuracy_Curr[ii][kk] << ", Prev = " << Accuracy_Prev[ii][kk] << ",Next = " <<  Accuracy_Next[ii][kk]<< endl;
      }

     }
   }
   cerr << "-------------------------------" << endl;
   cerr << "NEntry = " << NEntry - 1 << endl;
}
