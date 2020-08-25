#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TSystem.h>
#include <TROOT.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TMultiGraph.h>
#include <TSpline.h>
#include <math.h>
#include <TH1F.h>
#include <THStack.h>
#include "tdrstyle.C"
#include "CMS_lumi.C"


#include <iostream>
#include <vector>
#include <set>
using namespace std;

int CompHistos(std::string era, bool threeplusthree)
{
   gStyle->SetOptStat(0);

   char const* hist[] = {"mumu_mass","mumu_mass_rp23","mumu_mass_rp123","mumu_pt","mumu_pt_rp23","mumu_pt_rp123","mumu_y","mumu_y_rp23","mumu_y_rp123","proton_xi_left_rp23","proton_xi_left_rp23_nprot","proton_xi_right_rp123","proton_xi_right_rp123_nprot","proton_xi_left_multi","proton_xi_right_multi","diff_proton_reco_pair_xi_left_rp23","diff_proton_reco_pair_xi_left_rp23_nprot","diff_proton_reco_pair_xi_right_rp123","diff_proton_reco_pair_xi_right_rp123_nprot","diff_proton_reco_pair_xi_left_multi","diff_proton_reco_pair_xi_right_multi","ratio_proton_reco_pair_xi_left_rp23","ratio_proton_reco_pair_xi_left_rp23_nprot","ratio_proton_reco_pair_xi_right_rp123","ratio_proton_reco_pair_xi_right_rp123_nprot","ratio_proton_reco_pair_xi_left_multi","ratio_proton_reco_pair_xi_right_multi","pair_xi_left_rp23","pair_xi_right_rp123","n_fromPV","n_fromPV_2","n_fromPV_3","n_ext_fromPV","n_ext_fromPV_2","n_ext_fromPV_3","n_fromPV_dz02","n_fromPV_2_dz02","n_fromPV_3_dz02","n_ext_fromPV_dz02","n_ext_fromPV_2_dz02","n_ext_fromPV_3_dz02","n_fromPV_dz01","n_fromPV_2_dz01","n_fromPV_3_dz01","n_ext_fromPV_dz01","n_ext_fromPV_2_dz01","n_ext_fromPV_3_dz01","mu1_z_mu2_z","mu1_z_primevertex_z","mu2_z_primevertex_z"};
   char const* hist_bkg[] = {"proton_xi_left_rp3_match_2","proton_xi_left_rp23_match_2","proton_xi_left_rp23_nprot_match_2","proton_xi_right_rp103_match_2","proton_xi_right_rp123_match_2","proton_xi_right_rp123_nprot_match_2","proton_xi_left_multi_match_1","proton_xi_right_multi_match_1"};
   //char const* hist_bkg[] = {"mumu_mass_rp23_match","mumu_mass_rp123_match","mumu_mass_multi_match","mumu_mass_multi_match"};

   setTDRStyle();
   int iPeriod = 4;
   int iPos = 11;

   size_t Nhist = sizeof(hist)/sizeof(hist[0]);		
   size_t Nbkg = sizeof(hist_bkg)/sizeof(hist_bkg[0]);		

   double limit_lumi; //Used on the luminosity data
   double event_selection; //Used on the pile-up protons mixing on the luminosity data

   TFile *f_elastic; 
   TFile *f_inel_el;
   TFile *f_dy;
   TFile *f_data;
   TFile *f_dy_resample;
   TFile *f_elastic_mixpu;
   TFile *f_inel_el_mixpu;

	if (era == "all" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/outof3+3_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/outof3+3_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/outof3+3_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/outof3+3_output_data_UL.root", "READ");
      f_dy_resample = new TFile("histos_MC/outof3+3_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/outof3+3_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/outof3+3_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 18.341207;
      event_selection = 32374036./37787740.;
   }
   if (era == "all" && threeplusthree) {
      f_elastic = new TFile("histos_MC/3+3_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/3+3_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/3+3_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/3+3_output_data_UL.root", "READ");
      f_dy_resample = new TFile("histos_MC/3+3_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/3+3_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/3+3_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 18.849226;
      event_selection = 37201784./43067524.;
   }
	if (era == "B" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/eraB_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraB_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraB_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017B.root", "READ");
      f_dy_resample = new TFile("histos_MC/eraB_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/eraB_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/eraB_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 2.360904801;
      event_selection = 2154043./3163904.;
   }
	if (era == "C1" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/eraC1_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraC1_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraC1_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017C1.root", "READ");
      f_dy_resample = new TFile("histos_MC/eraC1_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/eraC1_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/eraC1_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 5.313012839;
      event_selection = 9183266./12827126.;
   }
	if (era == "C2" && threeplusthree) {
      f_elastic = new TFile("histos_MC/eraC2_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraC2_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraC2_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017C2.root", "READ");
      f_dy_resample = new TFile("histos_MC/eraC2_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/eraC2_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/eraC2_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 3.264135878;
      event_selection = 6562876./8047699.;
   }
	if (era == "D" && threeplusthree) {
      f_elastic = new TFile("histos_MC/eraD_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraD_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraD_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017D.root", "READ");
      f_dy_resample = new TFile("histos_MC/eraD_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/eraD_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/eraD_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 4.074723964;
      event_selection = 7772081./10098040.;
   }
	if (era == "E" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/eraE_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraE_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraE_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017E.root", "READ");
      f_dy_resample = new TFile("histos_MC/eraE_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/eraE_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/eraE_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 8.958810514;
      event_selection = 16777216./16777216.;
   }
	if (era == "F1" && !threeplusthree) {
      f_elastic = new TFile("histos_MC/eraF1_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraF1_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraF1_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017F1.root", "READ");
      f_dy_resample = new TFile("histos_MC/eraF1_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/eraF1_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/eraF1_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 1.708478656;
      event_selection = 4259512./5019495.;
   }
	if (era == "F2" && threeplusthree) {
      f_elastic = new TFile("histos_MC/eraF2_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraF2_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraF2_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017F2.root", "READ");
      f_dy_resample = new TFile("histos_MC/eraF2_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/eraF2_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/eraF2_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 7.877903151;
      event_selection = 16048852./16777216.;
   }
	if (era == "F3" && threeplusthree) {
      f_elastic = new TFile("histos_MC/eraF3_output_exclusive_new.root", "READ");
      f_inel_el = new TFile("histos_MC/eraF3_output_semi-exclusive_new.root", "READ");
      f_dy = new TFile("histos_MC/eraF3_output_dy_UL.root", "READ");
      f_data = new TFile("histos_data/DoubleMuon_UL2017F3.root", "READ");
      f_dy_resample = new TFile("histos_MC/eraF3_output_dy_UL.root", "READ");
      f_elastic_mixpu = new TFile("histos_MC/eraF3_output_exclusive_mixpu.root", "READ");
      f_inel_el_mixpu = new TFile("histos_MC/eraF3_output_semi-exclusive_mixpu.root", "READ");
      limit_lumi = 3.632463163;
      event_selection = 6817974./8144568.;
   }

   // Obtained from data separation on crossing angles
   double xangle100 = 160080.00/41730838.;
   double xangle110 = 1324607.0/41730838.;
   double xangle120 = 10886456./41730838.;
   double xangle130 = 13416491./41730838.;
   double xangle140 = 6777758.0/41730838.;
   double xangle150 = 9165446.0/41730838.;

   double n_events_h_elastic = 200000;
   double n_events_h_inel_el = 200000;
   double n_events_h_dy = 101077576;
   //double n_events_pileup = 68647048.;
   double number_of_samples = 1; //Used on the resampled DY  
   double total_lumi = 37.190433; //Used on the total luminosity data
   double rap_gap_surv_elastic = 0.89; 
   double rap_gap_surv_inel_el = 0.76; 
   double rap_gap_surv_inelastic = 0.13; 

   double scale_factor_elastic = limit_lumi*rap_gap_surv_elastic*0.017254036*1000 / n_events_h_elastic ; //
   double scale_factor_inel_el = limit_lumi*rap_gap_surv_inel_el*0.025643100*1000 / n_events_h_inel_el ; //
   double scale_factor_dy = (limit_lumi*5334000) / n_events_h_dy; 
   double scale_factor_dy_resample = (limit_lumi*5334000) / ( n_events_h_dy*number_of_samples ) ; 
   double scale_factor_dy_cutflow = (event_selection*limit_lumi*5334000) / n_events_h_dy; 
   double est = (event_selection*limit_lumi*5334000) / ( n_events_h_dy*number_of_samples ) ; 

   for (int j = 0; j < Nbkg; j++) {

      TH1 *h_est_exc = 0; f_elastic->GetObject(hist_bkg[j], h_est_exc);
      TH1 *h_est_semi = 0; f_inel_el->GetObject(hist_bkg[j], h_est_semi);
      TH1 *h_est_bkg = 0; f_dy_resample->GetObject(hist_bkg[j], h_est_bkg);
      TH1 *h_est_data = 0; f_data->GetObject(hist_bkg[j], h_est_data);
      TH1 *h_est_elastic_mixpu = 0; f_elastic_mixpu->GetObject(hist_bkg[j], h_est_elastic_mixpu);

      double int_err[8];
      double int_err_left_rp3, int_err_left_rp23, int_err_left_nprot_rp23, int_err_right_rp103, int_err_right_rp123,  int_err_right_nprot_rp123, int_err_left_multi, int_err_right_multi;
      int_err[0] =  int_err_left_rp3; int_err[1] =  int_err_left_rp23; int_err[2] = int_err_left_nprot_rp23; int_err[3] = int_err_right_rp103; int_err[4] = int_err_right_rp123; int_err[5] = int_err_right_nprot_rp123; int_err[6] = int_err_left_multi; int_err[7] = int_err_right_multi;

      h_est_exc->Scale(scale_factor_elastic); 
      h_est_semi->Scale(scale_factor_inel_el); 
      h_est_bkg->Scale(est); 
      h_est_elastic_mixpu->Scale(scale_factor_elastic); 
      cout << j << " estimativa exc: " << h_est_exc->IntegralAndError(0, (h_est_exc->GetNbinsX() + 1), int_err[j]) << " +/- " << int_err[j] << endl;
      cout << j << " estimativa semi: " << h_est_semi->IntegralAndError(0, (h_est_semi->GetNbinsX() + 1), int_err[j]) << " +/- " << int_err[j] << endl;
      cout << j << " estimativa bkg: " << h_est_bkg->IntegralAndError(0, (h_est_bkg->GetNbinsX() + 1), int_err[j]) << " +/- " << int_err[j] << endl;
      cout << j << " estimativa data: " << h_est_data->IntegralAndError(0, (h_est_data->GetNbinsX() + 1), int_err[j]) << " +/- " << int_err[j] << endl;
      if (j == 2 || j == 5) {
         cout << j << " estimativa elastic mixpu: " << h_est_elastic_mixpu->IntegralAndError(0, (h_est_elastic_mixpu->GetNbinsX() + 1), int_err[j]) << " +/- " << int_err[j] << endl;
      }

   }

   for (int i = 0; i < Nhist; i++) {
      
      if( (i >= 0 && i <= 8) ||  (i >= 47 && i <= 49) ){
         event_selection = 1; //Used on the pile-up protons mixing
      }
      
      double scale_factor_dy_prot_sel = event_selection*limit_lumi*5334000 / n_events_h_dy; 
      double scale_factor_dy_resample_prot_sel = event_selection*limit_lumi*5334000 / ( n_events_h_dy*number_of_samples ) ; 
      double scale_factor_elastic_prot_sel = event_selection*limit_lumi*rap_gap_surv_elastic*0.017254036*1000 / n_events_h_elastic ; //
      double scale_factor_inel_el_prot_sel = event_selection*limit_lumi*rap_gap_surv_inel_el*0.025643100*1000 / n_events_h_inel_el ; //

      TH1 *h_elastic_signal = 0; f_elastic->GetObject(hist[i], h_elastic_signal);
      TH1 *h_inel_el_signal = 0; f_inel_el->GetObject(hist[i], h_inel_el_signal);
      TH1 *h_dy = 0; f_dy->GetObject(hist[i], h_dy);
      TH1 *h_dy_resample = 0; 
      if(i >= 0 && i <= 28) {
         f_dy_resample->GetObject(hist[i], h_dy_resample);
      }
      TH1 *h_elastic_mixpu = 0; f_elastic_mixpu->GetObject(hist[i], h_elastic_mixpu);
      TH1 *h_inel_el_mixpu = 0; f_inel_el_mixpu->GetObject(hist[i], h_inel_el_mixpu);
      TH1 *h_data = 0; f_data->GetObject(hist[i], h_data);

      h_elastic_signal->SetLineColor(kBlue-4);
      h_inel_el_signal->SetLineColor(kGreen-3);
      h_dy->SetLineColor(kRed-3);
      if(i >= 0 && i <= 28) {
         h_dy_resample->SetLineColor(kRed-3);
      }
      h_data->SetLineColor(kBlack);
      h_elastic_mixpu->SetLineColor(kOrange-1);
      h_inel_el_mixpu->SetLineColor(kOrange-1);
      h_elastic_signal->SetFillColor(kBlue-4);
      h_inel_el_signal->SetFillColor(kGreen-3);
      h_dy->SetFillColor(kRed-3);
      if(i >= 0 && i <= 28) {
         h_dy_resample->SetFillColor(kRed-3);
      }
      h_elastic_mixpu->SetFillColor(kOrange-1);
      h_inel_el_mixpu->SetFillColor(kOrange-1);
      h_data->SetMarkerStyle(8);

      h_elastic_signal->Scale(scale_factor_elastic);
      h_inel_el_signal->Scale(scale_factor_inel_el);
      h_dy->Scale(scale_factor_dy_prot_sel);
      if(i >= 0 && i <= 28) {
         h_dy_resample->Scale(scale_factor_dy_resample_prot_sel);
      }
      h_elastic_mixpu->Scale(scale_factor_elastic_prot_sel);
      h_inel_el_mixpu->Scale(scale_factor_inel_el_prot_sel);

      THStack* hs = new THStack("hs", Form("%s", hist[i]));
      hs->Add(h_elastic_signal); 
      hs->Add(h_inel_el_signal);
      if(i == 10 || i == 12 || i == 16 || i == 18 || i == 22 || i == 24) {
         hs->Add(h_elastic_mixpu); 
         hs->Add(h_inel_el_mixpu);
      } 
      hs->Add(h_dy); 
      
      TH1F *h_new = (TH1F*)h_elastic_signal->Clone("h_new");
      h_new->Add(h_inel_el_signal); 
      if(i == 10 || i == 12 || i == 16 || i == 18 || i == 22 || i == 24) {
         h_new->Add(h_elastic_mixpu); 
         h_new->Add(h_inel_el_mixpu);
      } 
      h_new->Add(h_dy); 

      h_new->Sumw2();
      h_new->SetFillColor(1);
      h_new->SetFillStyle(3004);
      h_new->SetMarkerStyle(6);
      h_new->SetMarkerSize(0);
      h_new->SetLineWidth(0);

      THStack* hs_resample = new THStack("hs_resample", Form("%s_resample", hist[i]));
      hs_resample->Add(h_elastic_signal); 
      hs_resample->Add(h_inel_el_signal); 
      if(i == 10 || i == 12 || i == 16 || i == 18 || i == 22 || i == 24) {
         hs_resample->Add(h_elastic_mixpu); 
         hs_resample->Add(h_inel_el_mixpu);
      }
      if(i >= 0 && i <= 28) {
         hs_resample->Add(h_dy_resample); 
      }

      TH1F *h_new_resample = (TH1F*)h_elastic_signal->Clone("h_new_resample");
      h_new_resample->Add(h_inel_el_signal); 
      if(i == 10 || i == 12 || i == 16 || i == 18 || i == 22 || i == 24) {
         h_new_resample->Add(h_elastic_mixpu); 
         h_new_resample->Add(h_inel_el_mixpu);
      } 
      if(i >= 0 && i <= 28) {
         h_new_resample->Add(h_dy_resample); 
      }

      h_new_resample->Sumw2();
      h_new_resample->SetFillColor(1);
      h_new_resample->SetFillStyle(3004);
      h_new_resample->SetMarkerStyle(6);
      h_new_resample->SetMarkerSize(0);
      h_new_resample->SetLineWidth(0);

      double max_hs = 0.0;
      double max_hs_resample = 0.0;
      double max_data = 0.0;

      if(hs->GetMaximum() > h_data->GetMaximum()) {
         max_hs = hs->GetMaximum();
      }
      else {
         max_hs = h_data->GetMaximum();
      }
      if(hs_resample->GetMaximum() > h_data->GetMaximum()) {
         max_hs_resample = hs_resample->GetMaximum();
      }
      else {
         max_hs_resample = h_data->GetMaximum();
      }

      double step_hs =0.25*max_hs;
      double step_hs_resample =0.25*max_hs_resample;

      TCanvas *c = new TCanvas("c","",0,0,1200,1000);
      TPad *pad1 = new TPad("pad1", "pad1", 0.0, 0.0, 1.0, 1.0);
      //pad1->SetBottomMargin(0); // Upper and lower plot are joined
      pad1->Draw();             // Draw the upper pad: pad1
      pad1->cd();               // pad1 becomes the current pad
      hs->SetMaximum(max_hs+step_hs);
      h_data->SetMaximum(max_hs+step_hs);
      hs->Draw("HIST");
      hs->GetXaxis()->SetTitleOffset(1.1);
      if ( i >= 0 && i <= 2 )   hs->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} (GeV/c^{2})");
      if ( i >= 3 && i <= 5 )   hs->GetXaxis()->SetTitle("p_{T #mu^{+}#mu^{-}} (GeV/c)");
      if ( i >= 6 && i <= 8 )   hs->GetXaxis()->SetTitle("y_{#mu^{+}#mu^{-}}");
      if ( i >= 9 && i <= 14 )  hs->GetXaxis()->SetTitle("#xi(RP)");
      if ( i >= 15 && i <= 20 ) hs->GetXaxis()->SetTitle("#xi(RP) - #xi(#mu^{+}#mu^{-})");
      if ( i >= 21 && i <= 26 ) hs->GetXaxis()->SetTitle("1 - #xi(RP)/#xi(#mu^{+}#mu^{-})");
      if ( i == 27 || i == 28 ) hs->GetXaxis()->SetTitle("#xi(#mu^{+}#mu^{-})");
      if ( i >= 29 && i <= 46 ) hs->GetXaxis()->SetTitle("# of tracks");
      if ( i >= 47 && i <= 49 ) hs->GetXaxis()->SetTitle("z");
      hs->GetYaxis()->SetTitle("Events");
      h_data->Draw("SAME");
      h_new->Draw("E2 SAME");
      auto l = new TLegend(0.925,0.925,0.725,0.725);
      l->AddEntry(h_data,"2017 Data","lep");
      l->AddEntry(h_elastic_signal,"pp -> p #gamma#gamma p","f");
      l->AddEntry(h_inel_el_signal,"pp -> p #gamma#gamma p*","f");
      if(i == 10 || i == 12 || i == 16 || i == 18 || i == 22 || i == 24) {
         l->AddEntry(h_elastic_mixpu,"pp -> p #gamma#gamma p(*) mixed with pileup","f");
      }   
      l->AddEntry(h_dy,"Drell-Yan mixed with pileup","f");
      l->AddEntry(h_new,"Statistic Uncertainties","f");
      l->Draw();
      pad1->RedrawAxis();
      writeExtraText = true;       // if extra text
      extraText  = "Preliminary";  // default extra text is "Preliminary"
      //lumi_13TeV  = "18.34 fb^{-1}";  // default is "20.1 fb^{-1}"
      lumi_13TeV  = "18.85 fb^{-1}";  // default is "20.1 fb^{-1}"
      CMS_lumi( pad1, iPeriod, iPos );
      pad1->Update();
      c->cd();      
      gPad->Update();
      if ( i >= 21 && i <= 26 ){
         l->SetX1NDC(0.4);
         l->SetX2NDC(0.6);
      }
      gPad->Modified();
      //char const* name = Form("comp_new/normal/%s.png", hist[i]);
      char const* name;
	   if (era == "all" && !threeplusthree) name = Form("comp_histos/outof3+3/normal/%s.png", hist[i]);
	   if (era == "all" && threeplusthree) name = Form("comp_histos/3+3/normal/%s.png", hist[i]);
	   if (era == "B" && !threeplusthree) name = Form("comp_histos/eraB/normal/%s.png", hist[i]);
	   if (era == "C1" && !threeplusthree) name = Form("comp_histos/eraC1/normal/%s.png", hist[i]);
	   if (era == "C2" && threeplusthree) name = Form("comp_histos/eraC2/normal/%s.png", hist[i]);
	   if (era == "D" && threeplusthree) name = Form("comp_histos/eraD/normal/%s.png", hist[i]);
	   if (era == "E" && !threeplusthree) name = Form("comp_histos/eraE/normal/%s.png", hist[i]);
	   if (era == "F1" && !threeplusthree) name = Form("comp_histos/eraF1/normal/%s.png", hist[i]);
	   if (era == "F2" && threeplusthree) name = Form("comp_histos/eraF2/normal/%s.png", hist[i]);
	   if (era == "F3" && threeplusthree) name = Form("comp_histos/eraF3/normal/%s.png", hist[i]);
      //char const* name = Form("comp_histos/normal/%s.png", hist[i]);
      c->SaveAs(name);
      c->cd();
      c->Close();

      TCanvas *c_resample = new TCanvas("c_resample","",0,0,1200,1000);
      TPad *pad_resample = new TPad("pad_resample", "pad_resample", 0.0, 0.0, 1.0, 1.0);
      //pad_resample->SetBottomMargin(0); // Upper and lower plot are joined
      pad_resample->Draw();             // Draw the upper pad: pad1
      pad_resample->cd();               // pad1 becomes the current pad
      hs_resample->SetMaximum(max_hs_resample+step_hs_resample);
      h_data->SetMaximum(max_hs_resample+step_hs_resample);
      hs_resample->Draw("HIST");
      hs_resample->GetXaxis()->SetTitleOffset(1.1);
      if ( i >= 0 && i <= 2 )   hs_resample->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} (GeV/c^{2})");
      if ( i >= 3 && i <= 5 )   hs_resample->GetXaxis()->SetTitle("p_{T #mu^{+}#mu^{-}} (GeV/c)");
      if ( i >= 6 && i <= 8 )   hs_resample->GetXaxis()->SetTitle("y_{#mu^{+}#mu^{-}}");
      if ( i >= 9 && i <= 14 )  hs_resample->GetXaxis()->SetTitle("#xi(RP)");
      if ( i >= 15 && i <= 20 ) hs_resample->GetXaxis()->SetTitle("#xi(RP) - #xi(#mu^{+}#mu^{-})");
      if ( i >= 21 && i <= 26 ) hs_resample->GetXaxis()->SetTitle("1 - #xi(RP)/#xi(#mu^{+}#mu^{-})");
      if ( i == 27 || i == 28 ) hs_resample->GetXaxis()->SetTitle("#xi(#mu^{+}#mu^{-})");
      hs_resample->GetYaxis()->SetTitle("Events");
      h_data->Draw("SAME");
      h_new_resample->Draw("E2 SAME");
      auto l_resample = new TLegend(0.925,0.925,0.725,0.725);
      l_resample->AddEntry(h_data,"2017 Data","lep");
      l_resample->AddEntry(h_elastic_signal,"pp -> p #gamma#gamma p","f");
      l_resample->AddEntry(h_inel_el_signal,"pp -> p #gamma#gamma p*","f");
      if(i == 10 || i == 12 || i == 16 || i == 18 || i == 22 || i == 24) {
         l_resample->AddEntry(h_elastic_mixpu,"pp -> p #gamma#gamma p(*) mixed with pileup","f");
      }   
      l_resample->AddEntry(h_dy_resample,"Drell-Yan mixed with pileup","f");
      l_resample->AddEntry(h_new,"Statistic Uncertainties","f");
      l_resample->Draw();
      pad_resample->RedrawAxis();
      writeExtraText = true;       // if extra text
      extraText  = "Preliminary";  // default extra text is "Preliminary"
      //lumi_13TeV  = "18.34 fb^{-1}";  // default is "20.1 fb^{-1}"
      lumi_13TeV  = "18.85 fb^{-1}";  // default is "20.1 fb^{-1}"
      CMS_lumi( pad_resample, iPeriod, iPos );
      pad_resample->Update();
      c_resample->cd();
      gPad->Update();
      if ( i >= 21 && i <= 26 ){
         l_resample->SetX1NDC(0.4);
         l_resample->SetX2NDC(0.6);
      }
      gPad->Modified();
      //char const* name_resample = Form("comp_new/resample/%s_resample.png", hist[i]);
      char const* name_resample;
	   if (era == "all" && !threeplusthree) name_resample = Form("comp_histos/outof3+3/resample/%s.png", hist[i]);
	   if (era == "all" && threeplusthree) name_resample = Form("comp_histos/3+3/resample/%s.png", hist[i]);
	   if (era == "B" && !threeplusthree) name_resample = Form("comp_histos/eraB/resample/%s.png", hist[i]);
	   if (era == "C1" && !threeplusthree) name_resample = Form("comp_histos/eraC1/resample/%s.png", hist[i]);
	   if (era == "C2" && threeplusthree) name_resample = Form("comp_histos/eraC2/resample/%s.png", hist[i]);
	   if (era == "D" && threeplusthree) name_resample = Form("comp_histos/eraD/resample/%s.png", hist[i]);
	   if (era == "E" && !threeplusthree) name_resample = Form("comp_histos/eraE/resample/%s.png", hist[i]);
	   if (era == "F1" && !threeplusthree) name_resample = Form("comp_histos/eraF1/resample/%s.png", hist[i]);
	   if (era == "F2" && threeplusthree) name_resample = Form("comp_histos/eraF2/resample/%s.png", hist[i]);
	   if (era == "F3" && threeplusthree) name_resample = Form("comp_histos/eraF3/resample/%s.png", hist[i]);
      //char const* name_resample = Form("comp_histos/resample/%s_resample.png", hist[i]);
      c_resample->SaveAs(name_resample);
      c_resample->cd();
      c_resample->Close();

   }

   char const* hist_cf[] = {"cut_flow"};

   size_t Ncf = sizeof(hist_cf)/sizeof(hist_cf[0]);		

   for (int h = 0; h < Ncf; h++) {
      
      TH1 *h_elastic_cf = 0; f_elastic->GetObject(hist_cf[h], h_elastic_cf);
      TH1 *h_inel_el_cf = 0; f_inel_el->GetObject(hist_cf[h], h_inel_el_cf);
      TH1 *h_dy_cf = 0; f_dy->GetObject(hist_cf[h], h_dy_cf);
      TH1 *h_data_cf = 0; f_data->GetObject(hist_cf[h], h_data_cf);
      
      h_elastic_cf->Scale(scale_factor_elastic);
      h_inel_el_cf->Scale(scale_factor_inel_el);
      h_dy_cf->Scale(scale_factor_dy_cutflow);

      h_elastic_cf->SetLineColor(kBlue-4);
      h_elastic_cf->SetLineWidth(4);
      h_elastic_cf->SetMarkerStyle(22);
      h_elastic_cf->SetMarkerSize(2);
      h_inel_el_cf->SetLineColor(kGreen-3);
      h_inel_el_cf->SetLineWidth(4);
      h_inel_el_cf->SetMarkerStyle(22);
      h_inel_el_cf->SetMarkerSize(2);
      h_dy_cf->SetLineColor(kRed-3);
      h_dy_cf->SetLineWidth(4);
      h_dy_cf->SetMarkerStyle(23);
      h_dy_cf->SetMarkerSize(2);
      h_data_cf->SetLineColor(kBlack);
      h_data_cf->SetLineWidth(4);
      h_data_cf->SetMarkerStyle(8);
      h_data_cf->SetMarkerSize(2);

      TCanvas *c1 = new TCanvas("c1","",0,0,1200,1000); 
      TPad *pad_cf = new TPad("pad_cf", "pad_cf", 0.0, 0.0, 1.0, 1.0);
      //pad_cf->SetBottomMargin(0); // Upper and lower plot are joined
      pad_cf->Draw();             // Draw the upper pad: pad1
      pad_cf->cd();               // pad1 becomes the current pad
      
      double max = 0.0;
      double min = 0.0;
      
      if( h_dy_cf->GetMaximum() > h_data_cf->GetMaximum()) {
         max = h_dy_cf->GetMaximum();
      }
      else {
         max = h_data_cf->GetMaximum();
      }
      if( h_elastic_cf->GetMinimum() < h_inel_el_cf->GetMinimum()) {
         min = h_elastic_cf->GetMinimum();
      }
      else {
         min = h_inel_el_cf->GetMinimum();
      }

      double step = 12*max;
      double stop = 0.5*min;
 
      h_elastic_cf->SetMaximum(step+max); 
      h_inel_el_cf->SetMaximum(step+max); 
      h_dy_cf->SetMaximum(step+max); 
      h_data_cf->SetMaximum(step+max); 
      h_elastic_cf->SetMinimum(min-stop); 
      h_inel_el_cf->SetMinimum(min-stop); 
      h_dy_cf->SetMinimum(min-stop); 
      h_data_cf->SetMinimum(min-stop); 
      
      h_elastic_cf->Draw("LP"); 
      h_inel_el_cf->Draw("LPSAME");
      h_dy_cf->Draw("LPSAME");
      h_data_cf->Draw("LPSAME");
  
      c1->cd(); 
      c1->SetLogy(true);
      pad_cf->cd();
      pad_cf->SetLogy(true);
      auto l_cf = new TLegend(0.925,0.925,0.725,0.725);
      l_cf->AddEntry(h_data_cf,"2017 Data","lep");
      l_cf->AddEntry(h_elastic_cf,"pp -> p #gamma#gamma p","lep");
      l_cf->AddEntry(h_inel_el_cf,"pp -> p #gamma#gamma p*","lep");
      l_cf->AddEntry(h_dy_cf,"Drell-Yan mixed with pileup","lep");
      l_cf->Draw();
      pad_cf->RedrawAxis();
      writeExtraText = true;       // if extra text
      extraText  = "Preliminary";  // default extra text is "Preliminary"
      //lumi_13TeV  = "18.34 fb^{-1}";  // default is "20.1 fb^{-1}"
      lumi_13TeV  = "18.85 fb^{-1}";  // default is "20.1 fb^{-1}"
      CMS_lumi( pad_cf, iPeriod, iPos );
      pad_cf->Update();
      c1->cd();
      //char const* name_cf = Form("comp_histos/%s.png", hist_cf[h]);
      char const* name_cf;
	   if (era == "all" && !threeplusthree) name_cf = Form("comp_histos/outof3+3/%s.png", hist_cf[h]);
	   if (era == "all" && threeplusthree) name_cf = Form("comp_histos/3+3/%s.png", hist_cf[h]);
	   if (era == "B" && !threeplusthree) name_cf = Form("comp_histos/eraB/%s.png", hist_cf[h]);
	   if (era == "C1" && !threeplusthree) name_cf = Form("comp_histos/eraC1/%s.png", hist_cf[h]);
	   if (era == "C2" && threeplusthree) name_cf = Form("comp_histos/eraC2/%s.png", hist_cf[h]);
	   if (era == "D" && threeplusthree) name_cf = Form("comp_histos/eraD/%s.png", hist_cf[h]);
	   if (era == "E" && !threeplusthree) name_cf = Form("comp_histos/eraE/%s.png", hist_cf[h]);
	   if (era == "F1" && !threeplusthree) name_cf = Form("comp_histos/eraF1/%s.png", hist_cf[h]);
	   if (era == "F2" && threeplusthree) name_cf = Form("comp_histos/eraF2/%s.png", hist_cf[h]);
	   if (era == "F3" && threeplusthree) name_cf = Form("comp_histos/eraF3/%s.png", hist_cf[h]);
      c1->SaveAs(name_cf);
      c1->cd();
      c1->Close();
      
         
   }    
   char const* hist_multiplicity[] = {"multiplicity_0prot_cut","multiplicity_cut"};

   size_t Nmultiplicity = sizeof(hist_multiplicity)/sizeof(hist_multiplicity[0]);		

   for (int i = 0; i < Nmultiplicity; i++) {

      TH1 *h_elastic_signal_0prot = 0; f_elastic->GetObject(hist_multiplicity[i], h_elastic_signal_0prot);
      TH1 *h_inel_el_signal_0prot = 0; f_inel_el->GetObject(hist_multiplicity[i], h_inel_el_signal_0prot);
      TH1 *h_dy_0prot = 0; f_dy->GetObject(hist_multiplicity[i], h_dy_0prot);
      TH1 *h_data_0prot = 0; f_data->GetObject(hist_multiplicity[i], h_data_0prot);

      h_elastic_signal_0prot->SetLineColor(kBlue-4);
      h_inel_el_signal_0prot->SetLineColor(kGreen-3);
      h_dy_0prot->SetLineColor(kRed-3);
      h_elastic_signal_0prot->SetFillColor(kBlue-4);
      h_inel_el_signal_0prot->SetFillColor(kGreen-3);
      h_dy_0prot->SetFillColor(kRed-3);
      h_data_0prot->SetMarkerStyle(8);

      h_elastic_signal_0prot->Scale(scale_factor_elastic);
      h_inel_el_signal_0prot->Scale(scale_factor_inel_el);
      h_dy_0prot->Scale(scale_factor_dy_cutflow);

      THStack hs_0prot("hs_0prot","ExtraTracks Multiplicity - All Cuts;Number of extra tracks;Events");
      hs_0prot.Add(h_elastic_signal_0prot); 
      hs_0prot.Add(h_inel_el_signal_0prot); 
      hs_0prot.Add(h_dy_0prot); 

      TH1F *h_new_0prot = (TH1F*)h_elastic_signal_0prot->Clone("h_new_0prot");
      h_new_0prot->Add(h_inel_el_signal_0prot); 
      h_new_0prot->Add(h_dy_0prot); 

      h_new_0prot->Sumw2();
      h_new_0prot->SetFillColor(1);
      h_new_0prot->SetFillStyle(3004);
      h_new_0prot->SetMarkerStyle(6);
      h_new_0prot->SetMarkerSize(0);
      h_new_0prot->SetLineWidth(0);

      double max_hs_0prot = 0.0;
      if(hs_0prot.GetMaximum() > h_data_0prot->GetMaximum()) {
         max_hs_0prot = hs_0prot.GetMaximum();
      }
      else {
         max_hs_0prot = h_data_0prot->GetMaximum();
      }
      double step_hs_0prot =0.25*max_hs_0prot;

      TCanvas *c_0prot = new TCanvas("c_0prot","",0,0,1200,1000);
      TPad *pad_0prot = new TPad("pad_0prot", "pad_0prot", 0.0, 0.0, 1.0, 1.0);
      //pad_0prot->SetBottomMargin(0); // Upper and lower plot are joined
      pad_0prot->Draw();             // Draw the upper pad: pad1
      pad_0prot->cd();               // pad1 becomes the current pad
      hs_0prot.SetMaximum(max_hs_0prot+step_hs_0prot);
      h_data_0prot->SetMaximum(max_hs_0prot+step_hs_0prot);
      hs_0prot.Draw("HIST");
      h_data_0prot->Draw("SAME");
      h_new_0prot->Draw("E2 SAME");
      auto l_0prot = new TLegend(0.925,0.925,0.725,0.725);
      l_0prot->AddEntry(h_data_0prot,"2017 Data","lep");
      l_0prot->AddEntry(h_elastic_signal_0prot,"pp -> p #gamma#gamma p","f");
      l_0prot->AddEntry(h_inel_el_signal_0prot,"pp -> p #gamma#gamma p*","f");
      l_0prot->AddEntry(h_dy_0prot,"Drell-Yan mixed with pileup","f");
      l_0prot->AddEntry(h_new_0prot,"Statistic Uncertainties","f");
      l_0prot->Draw();
      pad_0prot->RedrawAxis();
      writeExtraText = true;       // if extra text
      extraText  = "Preliminary";  // default extra text is "Preliminary"
      //lumi_13TeV  = "18.34 fb^{-1}";  // default is "20.1 fb^{-1}"
      lumi_13TeV  = "18.85 fb^{-1}";  // default is "20.1 fb^{-1}"
      CMS_lumi( pad_0prot, iPeriod, iPos );
      pad_0prot->Update();
      c_0prot->cd();
      //char const* name_0prot = Form("comp_new/normal/%s.png", hist_multiplicity[i]);
      char const* name_0prot;
	   if (era == "all" && !threeplusthree) name_0prot = Form("comp_histos/outof3+3/normal/%s.png", hist_multiplicity[i]);
	   if (era == "all" && threeplusthree) name_0prot = Form("comp_histos/3+3/normal/%s.png", hist_multiplicity[i]);
	   if (era == "B" && !threeplusthree) name_0prot = Form("comp_histos/eraB/normal/%s.png", hist_multiplicity[i]);
	   if (era == "C1" && !threeplusthree) name_0prot = Form("comp_histos/eraC1/normal/%s.png", hist_multiplicity[i]);
	   if (era == "C2" && threeplusthree) name_0prot = Form("comp_histos/eraC2/normal/%s.png", hist_multiplicity[i]);
	   if (era == "D" && threeplusthree) name_0prot = Form("comp_histos/eraD/normal/%s.png", hist_multiplicity[i]);
	   if (era == "E" && !threeplusthree) name_0prot = Form("comp_histos/eraE/normal/%s.png", hist_multiplicity[i]);
	   if (era == "F1" && !threeplusthree) name_0prot = Form("comp_histos/eraF1/normal/%s.png", hist_multiplicity[i]);
	   if (era == "F2" && threeplusthree) name_0prot = Form("comp_histos/eraF2/normal/%s.png", hist_multiplicity[i]);
	   if (era == "F3" && threeplusthree) name_0prot = Form("comp_histos/eraF3/normal/%s.png", hist_multiplicity[i]);
      //char const* name_0prot = Form("comp_histos/normal/%s.png", hist_multiplicity[i]);
      c_0prot->SaveAs(name_0prot);
      c_0prot->cd();
      c_0prot->Close();

   }
   return 0;
}
