#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TSystem.h>
#include <TROOT.h>
#include <TH1.h>
#include <TF1.h>
#include <TH2.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TGraphErrors.h>
#include <TSpline.h>
#include <math.h>
#include "DataFormats/Math/interface/deltaPhi.h"

#define PI 3.14159265358979323846

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int draw_function( std::string fileName, TFile* f, std::string h_name, std::string f_name )
{
   TFile *input = new TFile(fileName.c_str(), "READ");
   
   TH1 *h = (TH1*)input->Get( h_name.c_str() );
   h->Fit( "pol8", "S" );
   //multiplicity_0prot_cut->Fit( "pol8", "S" );
   TF1 *func = (TF1*)h->GetListOfFunctions()->FindObject( "pol8" );
   //TF1 *func = (TF1*)multiplicity_0prot_cut->GetListOfFunctions()->FindObject( "pol8" );
   if ( !func ) return -1;

   func->SetName( f_name.c_str() );
   f->cd();

   TCanvas* canvas1 = new TCanvas;
   func->Write();
   func->Draw();
   return 0;
}

int run(std::string era="all", bool threeplusthree=false) {

   TFile *f = 0;
   string fileName;
   
   if (era == "all" && !threeplusthree) {
      fileName = "reweight/outof3+3_reweight_multi.root";
      f = new TFile("pol_re/outof3+3_pol_re.root", "RECREATE");
   } 
   if (era == "all" && threeplusthree) {
      fileName = "reweight/3+3_reweight_multi.root";
      f = new TFile("pol_re/3+3_pol_re.root", "RECREATE");
   } 
   if (era == "B" && !threeplusthree) {
      fileName = "reweight/eraB_reweight_multi.root";
      f = new TFile("pol_re/eraB_pol_re.root", "RECREATE");
   }
   if (era == "C1" && !threeplusthree) {
      fileName = "reweight/eraC1_reweight_multi.root";
      f = new TFile("pol_re/eraC1_pol_re.root", "RECREATE");
   }
   if (era == "C2" && threeplusthree) {
      fileName = "reweight/eraC2_reweight_multi.root";
      f = new TFile("pol_re/eraC2_pol_re.root", "RECREATE");
   }
   if (era == "D" && threeplusthree) {
      fileName = "reweight/eraD_reweight_multi.root";
      f = new TFile("pol_re/eraD_pol_re.root", "RECREATE");
   }
   if (era == "E" && !threeplusthree) {
      fileName = "reweight/eraE_reweight_multi.root";
      f = new TFile("pol_re/eraE_pol_re.root", "RECREATE");
   }
   if (era == "F1" && !threeplusthree) {
      fileName = "reweight/eraF1_reweight_multi.root";
      f = new TFile("pol_re/eraF1_pol_re.root", "RECREATE");
   }
   if (era == "F2" && threeplusthree) {
      fileName = "reweight/eraF2_reweight_multi.root";
      f = new TFile("pol_re/eraF2_pol_re.root", "RECREATE");
   }
   if (era == "F3" && threeplusthree) {
      fileName = "reweight/eraF3_reweight_multi.root";
      f = new TFile("pol_re/eraF3_pol_re.root", "RECREATE");
   }

   int multiplicity_re = draw_function( fileName, f, "multiplicity_0prot_cut", "re_0prot_2" );

   f->Close();

   return multiplicity_re;
}

