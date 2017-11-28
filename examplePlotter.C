#include <TCanvas.h>
#include <TH2D.h>
#include <TGraph.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TLatex.h>

TLatex GetAtlaslabel(const double x, const double y, std::string label);
void SetAtlasStyle();

/*
void examplePlotter()
{
  SetAtlasStyle();
  
  TGraph a;
  TGraph b;
  TGraph c;
  
  a.SetMarkerColor(kBlack); a.SetLineColor(kBlack);
  b.SetMarkerColor(kBlue); b.SetLineColor(kBlue);
  c.SetMarkerColor(kRed); c.SetLineColor(kRed);

  a.SetMarkerStyle(8);
  b.SetMarkerStyle(8);
  c.SetMarkerStyle(8);

  a.SetLineStyle(2);
  b.SetLineStyle(2);
  c.SetLineStyle(2);
  
  for (int ii=0; ii<96; ii++) {
    // dummy data
    double curr = 1.0 - gRandom->Rndm() * 0.3 ;
    double prev = gRandom->Rndm() * (1.0 - curr);
    double next = gRandom->Rndm() * 0.05;
    a.SetPoint(ii, ii, curr);
    b.SetPoint(ii, ii, prev);
    c.SetPoint(ii, ii, next);
  }
  
  
  TCanvas c1;
  
  TH2D waku("waku", "", 1, -0.5, 95.5, 1, 0, 1.1);
  waku.GetXaxis()->SetTitle("TGC Trigger Sector");
  waku.GetYaxis()->SetTitle("Good data rate");

  waku.Draw();
  a.Draw("PL");
  b.Draw("PL");
  c.Draw("PL");
  
  TLegend leg(0.3, 0.3, 0.5, 0.55);
  leg.SetLineWidth(0);
  leg.SetFillColor(0);
  leg.AddEntry(&a, "Current", "PL");
  leg.AddEntry(&b, "Previous", "PL");
  leg.AddEntry(&c, "Next", "PL");
  leg.Draw();
  
  TLatex label = GetAtlaslabel(0.3, 0.55, "Internal");
  label.Draw();
  
  c1.Print("example.pdf");
}
*/

void SetAtlasStyle()
{
  // use plain black on white colors
  Int_t icol=0; // WHITE
  gStyle->SetFrameBorderMode(icol);
  gStyle->SetFrameFillColor(icol);
  gStyle->SetCanvasBorderMode(icol);
  gStyle->SetCanvasColor(icol);
  gStyle->SetPadBorderMode(icol);
  gStyle->SetPadColor(icol);
  gStyle->SetStatColor(icol);
  //gStyle->SetFillColor(icol); // don't use: white fill color for *all* objects
  // set the paper & margin sizes
  gStyle->SetPaperSize(20,26);

  // set margin sizes
  gStyle->SetPadTopMargin(0.05);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadBottomMargin(0.16);
  gStyle->SetPadLeftMargin(0.16);

  // set title offsets (for axis label)
  gStyle->SetTitleXOffset(1.4);
  gStyle->SetTitleYOffset(1.4);

  // use large fonts
  //Int_t font=72; // Helvetica italics
  Int_t font=42; // Helvetica
  Double_t tsize=0.05;
  gStyle->SetTextFont(font);

  gStyle->SetTextSize(tsize);
  gStyle->SetLabelFont(font,"x");
  gStyle->SetTitleFont(font,"x");
  gStyle->SetLabelFont(font,"y");
  gStyle->SetTitleFont(font,"y");
  gStyle->SetLabelFont(font,"z");
  gStyle->SetTitleFont(font,"z");
  
  gStyle->SetLabelSize(tsize,"x");
  gStyle->SetTitleSize(tsize,"x");
  gStyle->SetLabelSize(tsize,"y");
  gStyle->SetTitleSize(tsize,"y");
  gStyle->SetLabelSize(tsize,"z");
  gStyle->SetTitleSize(tsize,"z");

  // use bold lines and markers
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(1.2);
  gStyle->SetHistLineWidth(2.);
  gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  // get rid of X error bars 
  //gStyle->SetErrorX(0.001);
  // get rid of error bar caps
  gStyle->SetEndErrorSize(0.);

  // do not display any of the standard histogram decorations
  gStyle->SetOptTitle(0);
  //gStyle->SetOptStat(1111);
  gStyle->SetOptStat(0);
  //gStyle->SetOptFit(1111);
  gStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
}

TLatex GetAtlaslabel(const double x, const double y, std::string label) {
  TLatex atlasLabel(x, y, Form("#it{#bf{ATLAS}} %s", label.c_str()));
  atlasLabel.SetNDC();
  atlasLabel.SetTextFont(42);
  return atlasLabel;
}
