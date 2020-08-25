#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TSystem.h>
#include <TROOT.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TSpline.h>
#include <math.h>
#include <TH1F.h>
#include <THStack.h>

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int CompHistos_re(std::string era, bool threeplusthree)
{
   gStyle->SetOptStat(0);

   char* hist[] = {"multiplicity_0prot_cut"};

   //setTDRStyle();

   size_t Nhist = sizeof(hist)/sizeof(hist[0]);		

   TFile *f_elastic;
   TFile *f_inel_el;
   TFile *f_dy;
   TFile *f_data;

   double limit_lumi; 

	if (era == "all" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/outof3+3_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/outof3+3_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/outof3+3_output_dy_UL_sem_re.root", "READ");
      f_data = new TFile("histos_data/outof3+3_output_data_UL.root", "READ");
      limit_lumi = 18.341207;
   }
   if (era == "all" && threeplusthree) {
      f_elastic = new TFile("histos_MC/3+3_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/3+3_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/3+3_output_dy_UL_sem_re.root", "READ");
      f_data = new TFile("histos_data/3+3_output_data_UL.root", "READ");
      limit_lumi = 18.849226;
   }
	if (era == "B" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/eraB_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraB_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraB_output_dy_UL_sem_re.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017B.root", "READ");
      limit_lumi = 2.360904801;
   }
	if (era == "C1" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/eraC1_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraC1_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraC1_output_dy_UL_sem_re.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017C1.root", "READ");
      limit_lumi = 5.313012839;
   }
	if (era == "C2" && threeplusthree) {
      f_elastic = new TFile("histos_MC/eraC2_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraC2_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraC2_output_dy_UL_3+3_sem_re.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017C2.root", "READ");
      limit_lumi = 3.264135878;
   }
	if (era == "D" && threeplusthree) {
      f_elastic = new TFile("histos_MC/eraD_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraD_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraD_output_dy_UL_3+3_sem_re.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017D.root", "READ");
      limit_lumi = 4.074723964;
   }
	if (era == "E" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/eraE_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraE_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraE_output_dy_UL_sem_re.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017E.root", "READ");
      limit_lumi = 8.958810514;
   }
	if (era == "F1" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/eraF1_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraF1_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraF1_output_dy_UL_sem_re.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017F1.root", "READ");
      limit_lumi = 1.708478656;
   }
	if (era == "F2" && threeplusthree) {
      f_elastic = new TFile("histos_MC/eraF2_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraF2_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraF2_output_dy_UL_3+3_sem_re.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017F2.root", "READ");
      limit_lumi = 7.877903151;
   }
	if (era == "F3" && threeplusthree) {
      f_elastic = new TFile("histos_MC/eraF3_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraF3_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraF3_output_dy_UL_3+3_sem_re.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017F3.root", "READ");
      limit_lumi = 3.632463163;
   }


   double n_events_h_elastic = 200000;
   double n_events_h_inel_el = 200000;
   double n_events_h_dy = 101077576;
   double total_lumi = 37.190433; //Used on the total luminosity data
   double rap_gap_surv_elastic = 0.89; 
   double rap_gap_surv_inel_el = 0.76; 
   double rap_gap_surv_inelastic = 0.13; 

   double scale_factor_elastic = limit_lumi*rap_gap_surv_elastic*0.017254036*1000 / n_events_h_elastic ; //
   double scale_factor_inel_el = limit_lumi*rap_gap_surv_inel_el*0.025643100*1000 / n_events_h_inel_el ; //
   double scale_factor_dy = limit_lumi*5334000 / n_events_h_dy; 

   for (int i = 0; i < Nhist; i++) {

      TH1 *h_elastic = 0; f_elastic->GetObject(hist[i], h_elastic);
      TH1 *h_inel_el = 0; f_inel_el->GetObject(hist[i], h_inel_el);
      TH1 *h_dy = 0; f_dy->GetObject(hist[i], h_dy);
      TH1 *h_data = 0; f_data->GetObject(hist[i], h_data);

      h_elastic->Scale(scale_factor_elastic);
      h_inel_el->Scale(scale_factor_inel_el);
      h_dy->Scale(scale_factor_dy);

      h_elastic->Add(h_inel_el); 
      
      TH1F *h_signal = (TH1F*)h_elastic->Clone("h_signal"); 
      TH1F *h_data_sub = (TH1F*)h_data->Clone("h_data_sub"); 

      h_elastic->Add(h_dy);

      h_elastic->Scale(1/h_elastic->Integral());
      h_data->Scale(1/h_data->Integral());
      h_elastic->Divide(h_data);

      h_data_sub->Add(h_signal, -1);
      h_data_sub->Scale(1/h_data_sub->Integral());
      h_dy->Scale(1/h_dy->Integral());
      h_dy->Divide(h_data_sub);
   
      h_elastic->SetTitle("sum MC / data");
      h_dy->SetTitle("bkg MC / data - signal MC");

      TFile *f;
      
      if (era == "all" && !threeplusthree) f = new TFile("reweight/outof3+3_reweight_multi.root", "RECREATE");
      if (era == "all" && threeplusthree) f = new TFile("reweight/3+3_reweight_multi.root", "RECREATE");
	   if (era == "B" && !threeplusthree) f = new TFile("reweight/eraB_reweight_multi.root", "RECREATE");
	   if (era == "C1" && !threeplusthree) f = new TFile("reweight/eraC1_reweight_multi.root", "RECREATE");
	   if (era == "C2" && threeplusthree) f = new TFile("reweight/eraC2_reweight_multi.root", "RECREATE");
	   if (era == "D" && threeplusthree) f = new TFile("reweight/eraD_reweight_multi.root", "RECREATE");
	   if (era == "E" && !threeplusthree) f = new TFile("reweight/eraE_reweight_multi.root", "RECREATE");
	   if (era == "F1" && !threeplusthree) f = new TFile("reweight/eraF1_reweight_multi.root", "RECREATE");
	   if (era == "F2" && threeplusthree) f = new TFile("reweight/eraF2_reweight_multi.root", "RECREATE");
	   if (era == "F3" && threeplusthree) f = new TFile("reweight/eraF3_reweight_multi.root", "RECREATE");
      //h_elastic->Write();
      h_dy->Write();
   }
   return 0;
}
