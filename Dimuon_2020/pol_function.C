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

int draw_function( std::string fileName, TFile *f, std::string gr_name, std::string f_name)
{
   TFile *input = new TFile(fileName.c_str(), "READ");

   TGraph *gr = (TGraph*)input->Get( gr_name.c_str() );
	//TF1 *func = (TF1*)gr->GetListOfFunctions()->FindObject( f_name.c_str() );
	TF1 *func = (TF1*)gr->GetListOfFunctions()->FindObject( "pol1" );
   if ( !func ) return -1;

   func->SetName( f_name.c_str() );
	double coef_lin = func->GetParameter(0);
	double coef_lin_err = func->GetParError(0);
	double coef_ang = func->GetParameter(1);
	double coef_ang_err = func->GetParError(1);
   std::cout << "p0 = " << coef_lin << "+/-" << coef_lin_err << std::endl;
   std::cout << "p1 = " << coef_ang << "+/-" << coef_ang_err << std::endl;

   f->cd();
 
   TCanvas* canvas1 = new TCanvas;
   func->Draw();

	//TFile* f = new TFile("pol_function.root", "RECREATE");
	func->Write();

	//f->Close();

	//cout << "oi" <<endl;

   return 0;
}
	
int run(std::string era="all", bool threeplusthree=false) {
   
   TFile *f = 0;
   string fileName;
	
   if (era == "all" && !threeplusthree) {
      fileName = "histos_MC/outof3+3_output_MC_signal.root";
      f = new TFile("pol_function/outof3+3_pol_function.root", "RECREATE");
   } 
	if (era == "all" && threeplusthree) {
      fileName = "histos_MC/3+3_output_MC_signal.root";
      f = new TFile("pol_function/3+3_pol_function.root", "RECREATE");
   }
   if (era == "B" && !threeplusthree) {
      fileName = "histos_MC/eraB_output_MC_signal.root";
      f = new TFile("pol_function/eraB_pol_function.root", "RECREATE");
   }
   if (era == "C1" && !threeplusthree) {
      fileName = "histos_MC/eraC1_output_MC_signal.root";
      f = new TFile("pol_function/eraC1_pol_function.root", "RECREATE");
   }
   if (era == "C2" && threeplusthree) {
      fileName = "histos_MC/eraC2_output_MC_signal.root";
      f = new TFile("pol_function/eraC2_pol_function.root", "RECREATE");
   }
   if (era == "D" && threeplusthree) {
      fileName = "histos_MC/eraD_output_MC_signal.root";
      f = new TFile("pol_function/eraD_pol_function.root", "RECREATE");
   }
   if (era == "E" && !threeplusthree) {
      fileName = "histos_MC/eraE_output_MC_signal.root";
      f = new TFile("pol_function/eraE_pol_function.root", "RECREATE");
   }
   if (era == "F1" && !threeplusthree) {
      fileName = "histos_MC/eraF1_output_MC_signal.root";
      f = new TFile("pol_function/eraF1_pol_function.root", "RECREATE");
   }
   if (era == "F2" && threeplusthree) {
      fileName = "histos_MC/eraF2_output_MC_signal.root";
      f = new TFile("pol_function/eraF2_pol_function.root", "RECREATE");
   }
   if (era == "F3" && threeplusthree) {
      fileName = "histos_MC/eraF3_output_MC_signal.root";
      f = new TFile("pol_function/eraF3_pol_function.root", "RECREATE");
   }

   int rp3 = draw_function( fileName , f, "gr_rp3", "f_rp3" );
   int rp23 = draw_function( fileName , f, "gr_rp23", "f_rp23" );
   int rp23_nprot = draw_function( fileName , f, "gr_rp23_nprot", "f_rp23_nprot" );
   int l_s = draw_function( fileName , f, "gr_left_single", "f_left_single" );
   int rp103 = draw_function( fileName , f, "gr_rp103", "f_rp103" );
   int rp123 = draw_function( fileName , f, "gr_rp123", "f_rp123" );
   int rp123_nprot = draw_function( fileName , f, "gr_rp123_nprot", "f_rp123_nprot" );
   int r_s = draw_function( fileName , f, "gr_right_single", "f_right_single" );
   int l_m = draw_function( fileName , f, "gr_left_multi", "f_left_multi" );
   int r_m = draw_function( fileName , f, "gr_right_multi", "f_right_multi" );
   int pair_l = draw_function( fileName , f, "gr_pair_left", "f_pair_left" );
   int pair_r = draw_function( fileName , f, "gr_pair_right", "f_pair_right" );

	f->Close();

 	return rp3, rp23, rp23_nprot, l_s, rp103, rp123, rp123_nprot, r_s, l_m, r_m, pair_l, pair_r;
 	}
