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

int CompHistos_match(std::string era, bool threeplusthree)
{
   gStyle->SetOptStat(0);

   char const* hist_match[]= {"mumu_mass_rp23_match","mumu_mass_rp123_match","mumu_pt_rp23_match","mumu_pt_rp123_match","mumu_y_rp23_match","mumu_y_rp123_match","proton_xi_left_rp23_match_1","proton_xi_left_rp23_nprot_match_1","proton_xi_right_rp123_match_1","proton_xi_right_rp123_nprot_match_1","proton_xi_left_multi_match_1","proton_xi_right_multi_match_1","proton_xi_left_rp23_match_2","proton_xi_left_rp23_nprot_match_2","proton_xi_right_rp123_match_2","proton_xi_right_rp123_nprot_match_2","proton_xi_left_multi_match_2","proton_xi_right_multi_match_2","diff_proton_reco_pair_xi_left_rp23_match","diff_proton_reco_pair_xi_left_rp23_nprot_match","diff_proton_reco_pair_xi_right_rp123_match","diff_proton_reco_pair_xi_right_rp123_nprot_match","diff_proton_reco_pair_xi_left_multi_match","diff_proton_reco_pair_xi_right_multi_match","ratio_proton_reco_pair_xi_left_rp23_match","ratio_proton_reco_pair_xi_left_rp23_nprot_match","ratio_proton_reco_pair_xi_right_rp123_match","ratio_proton_reco_pair_xi_right_rp123_nprot_match","ratio_proton_reco_pair_xi_left_multi_match","ratio_proton_reco_pair_xi_right_multi_match","pair_xi_left_rp23_match","pair_xi_right_rp123_match","proton_left_reco_multi_ThX_match","proton_left_reco_multi_ThY_match","proton_right_reco_multi_ThX_match","proton_right_reco_multi_ThY_match"};

   setTDRStyle();
   int iPeriod = 4;
   int iPos = 11;

   size_t Nmatch = sizeof(hist_match)/sizeof(hist_match[0]);		

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
   double scale_factor_dy = limit_lumi*5334000 / n_events_h_dy; 
   double scale_factor_dy_resample = limit_lumi*5334000 / ( n_events_h_dy*number_of_samples ) ; 

   for (int k = 0; k < Nmatch; k++) {

      if( (k >= 0 && k <= 5) || k == 30 || k == 31 ){
         event_selection = 1; //Used on the pile-up protons mixing
      }

      double scale_factor_dy_prot_sel = event_selection*limit_lumi*5334000 / n_events_h_dy; 
      double scale_factor_dy_resample_prot_sel = event_selection*limit_lumi*5334000 / ( n_events_h_dy*number_of_samples ) ; 
      double scale_factor_elastic_prot_sel = event_selection*limit_lumi*rap_gap_surv_elastic*0.017254036*1000 / n_events_h_elastic ; //
      double scale_factor_inel_el_prot_sel = event_selection*limit_lumi*rap_gap_surv_inel_el*0.025643100*1000 / n_events_h_inel_el ; //

      TH1 *h_match_elastic_signal = 0; f_elastic->GetObject(hist_match[k], h_match_elastic_signal);
      TH1 *h_match_inel_el_signal = 0; f_inel_el->GetObject(hist_match[k], h_match_inel_el_signal);
      TH1 *h_match_dy = 0; f_dy->GetObject(hist_match[k], h_match_dy);
      TH1 *h_match_dy_resample = 0; f_dy_resample->GetObject(hist_match[k], h_match_dy_resample);
      TH1 *h_match_elastic_mixpu = 0; f_elastic_mixpu->GetObject(hist_match[k], h_match_elastic_mixpu);
      TH1 *h_match_inel_el_mixpu = 0; f_inel_el_mixpu->GetObject(hist_match[k], h_match_inel_el_mixpu);
      TH1 *h_match_data = 0; f_data->GetObject(hist_match[k], h_match_data);

      if ( k >= 0 && k <= 31 ) {
         h_match_elastic_signal->SetLineColor(kBlue-4);
         h_match_inel_el_signal->SetLineColor(kGreen-3);
         h_match_dy->SetLineColor(kRed-3);
         h_match_dy_resample->SetLineColor(kRed-3);
         h_match_data->SetLineColor(kBlack);
         h_match_elastic_mixpu->SetLineColor(kOrange-1);
         h_match_inel_el_mixpu->SetLineColor(kOrange-1);
         h_match_elastic_signal->SetFillColor(kBlue-4);
         h_match_inel_el_signal->SetFillColor(kGreen-3);
         h_match_dy->SetFillColor(kRed-3);
         h_match_dy_resample->SetFillColor(kRed-3);
         h_match_elastic_mixpu->SetFillColor(kOrange-1);
         h_match_inel_el_mixpu->SetFillColor(kOrange-1);
         h_match_data->SetMarkerStyle(8);
      }
      else { 
         h_match_data->SetLineColor(kBlack);
         h_match_data->SetMarkerStyle(8);
      }

      if( k >= 0 && k <= 5 ){
         h_match_elastic_signal->Scale(scale_factor_elastic);
         h_match_inel_el_signal->Scale(scale_factor_inel_el);
         h_match_dy->Scale(scale_factor_dy_prot_sel);
         h_match_dy_resample->Scale(scale_factor_dy_resample_prot_sel);
         h_match_data->Scale(1);
         h_match_elastic_mixpu->Scale(scale_factor_elastic_prot_sel);
         h_match_inel_el_mixpu->Scale(scale_factor_inel_el_prot_sel);
      }
      else if ( k >= 32 && k <= 35 ) {
         h_match_data->Scale(1); 
      }   
      else { 
         h_match_elastic_signal->Scale(scale_factor_elastic, "width");
         h_match_inel_el_signal->Scale(scale_factor_inel_el, "width");
         h_match_dy->Scale(scale_factor_dy_prot_sel, "width");
         h_match_dy_resample->Scale(scale_factor_dy_resample_prot_sel, "width");
         h_match_data->Scale(1, "width");
         h_match_elastic_mixpu->Scale(scale_factor_elastic_prot_sel, "width");
         h_match_inel_el_mixpu->Scale(scale_factor_inel_el_prot_sel, "width");
      }

      THStack* hs_match = new THStack("hs_match", Form("%s", hist_match[k]));
      if ( k >= 0 && k <= 31 ) {
         hs_match->Add(h_match_elastic_signal); 
         hs_match->Add(h_match_inel_el_signal); 
         if(k == 7 || k == 9 || k == 13 || k == 15 || k == 19 || k == 21 || k == 25 || k == 27) {
            hs_match->Add(h_match_elastic_mixpu); 
            hs_match->Add(h_match_inel_el_mixpu); 
         }
         hs_match->Add(h_match_dy); 
      }

      TH1F *h_match_new = 0;
      if ( k >= 0 && k <= 31 ) {
         h_match_new = (TH1F*)h_match_elastic_signal->Clone("h_match_new");
         h_match_new->Add(h_match_inel_el_signal); 
         if(k == 7 || k == 9 || k == 13 || k == 15 || k == 19 || k == 21 || k == 25 || k == 27) {
            h_match_new->Add(h_match_elastic_mixpu); 
            h_match_new->Add(h_match_inel_el_mixpu);
         } 
         h_match_new->Add(h_match_dy); 

         h_match_new->Sumw2();
         h_match_new->SetFillColor(1);
         h_match_new->SetFillStyle(3004);
         h_match_new->SetMarkerStyle(6);
         h_match_new->SetMarkerSize(0);
         h_match_new->SetLineWidth(0);
      }

      THStack* hs_match_resample = new THStack("hs_match_resample", Form("%s_resample", hist_match[k]));
      if ( k >= 0 && k <= 31 ) {
         hs_match_resample->Add(h_match_elastic_signal); 
         hs_match_resample->Add(h_match_inel_el_signal); 
         if(k == 7 || k == 9 || k == 13 || k == 15 || k == 19 || k == 21 || k == 25 || k == 27) {
            hs_match_resample->Add(h_match_elastic_mixpu); 
            hs_match_resample->Add(h_match_inel_el_mixpu);
         }   
         hs_match_resample->Add(h_match_dy_resample); 
      }

      TH1F *h_match_new_resample = 0; 
      if ( k >= 0 && k <= 31 ) {
         h_match_new_resample = (TH1F*)h_match_elastic_signal->Clone("h_match_new_resample");
         h_match_new_resample->Add(h_match_inel_el_signal); 
         if(k == 7 || k == 9 || k == 13 || k == 15 || k == 19 || k == 21 || k == 25 || k == 27) {
            h_match_new_resample->Add(h_match_elastic_mixpu); 
            h_match_new_resample->Add(h_match_inel_el_mixpu);
         }   
         h_match_new_resample->Add(h_match_dy_resample); 

         h_match_new_resample->Sumw2();
         h_match_new_resample->SetFillColor(1);
         h_match_new_resample->SetFillStyle(3004);
         h_match_new_resample->SetMarkerStyle(6);
         h_match_new_resample->SetMarkerSize(0);
         h_match_new_resample->SetLineWidth(0);
      }

      double max_hs_match = 0.0;
      double max_hs_match_resample = 0.0;

      if ( k >= 0 && k <= 31 ) {
         if(hs_match->GetMaximum() > h_match_data->GetMaximum()) {
            max_hs_match = hs_match->GetMaximum();
         }
         else {
            max_hs_match = h_match_data->GetMaximum();
         }
         if(hs_match_resample->GetMaximum() > h_match_data->GetMaximum()) {
            max_hs_match_resample = hs_match_resample->GetMaximum();
         }
         else {
            max_hs_match_resample = h_match_data->GetMaximum();
         }
      }
      double step_hs_match =0.25*max_hs_match;
      double step_hs_match_resample =0.25*max_hs_match_resample;

      TCanvas *c_match = new TCanvas("c_match","",0,0,1200,1000);
      TPad *pad_match = new TPad("pad_match", "pad_match", 0.0, 0.0, 1.0, 1.0);
      //pad_match->SetBottomMargin(0); // Upper and lower plot are joined
      pad_match->Draw();             // Draw the upper pad: pad1
      pad_match->cd();               // pad1 becomes the current pad
      if ( k >= 0 && k <= 31 ) { 
         hs_match->SetMaximum(max_hs_match+step_hs_match);
         h_match_data->SetMaximum(max_hs_match+step_hs_match);
         hs_match->Draw("HIST");
         hs_match->GetXaxis()->SetTitleOffset(1.1);
         if ( k == 0 || k == 1) {
            hs_match->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} (GeV/c^{2})");
            hs_match->GetYaxis()->SetTitle("Events");
         }
         if ( k == 2 || k == 3) {
            hs_match->GetXaxis()->SetTitle("p_{T #mu^{+}#mu^{-}} (GeV/c)");
            hs_match->GetYaxis()->SetTitle("Events");
         }
         if ( k == 4 || k == 5) {
            hs_match->GetXaxis()->SetTitle("y_{#mu^{+}#mu^{-}}");
            hs_match->GetYaxis()->SetTitle("Events");
         }    
         if ( k >= 6 && k <= 17 ) {
            hs_match->GetXaxis()->SetTitle("#xi(RP)");
            hs_match->GetYaxis()->SetTitle("dN/d#xi(RP)");
            hs_match->GetYaxis()->SetTitleOffset(1.3);
         }   
         if ( k >= 18 && k <= 23 ) {
            hs_match->GetXaxis()->SetTitle("#xi(RP) - #xi(#mu^{+}#mu^{-})");
            hs_match->GetYaxis()->SetTitle("dN/d(#xi(RP) - #xi(#mu^{+}#mu^{-}))");
            hs_match->GetYaxis()->SetTitleOffset(1.3);
         }   
         if ( k >= 24 && k <= 29 ) {
            hs_match->GetXaxis()->SetTitle("1 - #xi(RP)/#xi(#mu^{+}#mu^{-})");
            hs_match->GetYaxis()->SetTitle("dN/d(1 - #xi(RP)/#xi(#mu^{+}#mu^{-}))");
            hs_match->GetYaxis()->SetTitleOffset(1.3);
         }   
         if ( k == 30 || k == 31 ) {
            hs_match->GetXaxis()->SetTitle("#xi(#mu^{+}#mu^{-})");
            hs_match->GetYaxis()->SetTitle("dN/d#xi(#mu^{+}#mu^{-})");
            hs_match->GetYaxis()->SetTitleOffset(1.3);
         }
         h_match_data->Draw("SAME");
         h_match_new->Draw("E2 SAME");
      }
      else {
         h_match_data->SetMaximum(6.5);
         h_match_data->Draw();
         if ( k == 32 || k == 34 ) h_match_data->GetXaxis()->SetTitle("#theta_{X} (rad)");
         if ( k == 33 || k == 35 ) h_match_data->GetXaxis()->SetTitle("#theta_{Y} (rad)");
         h_match_data->GetYaxis()->SetTitle("Events");
         //h_match_data->GetYaxis()->SetTitleOffset(1.3);

      }   
      auto l_match = new TLegend(0.895,0.925,0.695,0.725);
      if ( k >= 0 && k <= 31 ) { 
         l_match->AddEntry(h_match_data,"2017 Data","lep");
         l_match->AddEntry(h_match_elastic_signal,"pp -> p #gamma#gamma p","f");
         l_match->AddEntry(h_match_inel_el_signal,"pp -> p #gamma#gamma p*","f");
         if(k == 7 || k == 9 || k == 13 || k == 15 || k == 19 || k == 21 || k == 25 || k == 27) {
            l_match->AddEntry(h_match_elastic_mixpu,"pp -> p #gamma#gamma p(*) mixed with pileup","f");
         }   
         l_match->AddEntry(h_match_dy,"Drell-Yan mixed with pileup","f");
         l_match->AddEntry(h_match_new,"Statistic Uncertainties","f");
      }
      l_match->Draw();
      pad_match->RedrawAxis();
      writeExtraText = true;       // if extra text
      extraText  = "Preliminary";  // default extra text is "Preliminary"
      //lumi_13TeV  = "18.34 fb^{-1}";  // default is "20.1 fb^{-1}"
      lumi_13TeV  = "18.85 fb^{-1}";  // default is "20.1 fb^{-1}"
      CMS_lumi( pad_match, iPeriod, iPos );
      pad_match->Update();
      c_match->cd();
      gPad->Update();
      if ( k >= 24 && k <= 29 ){
         l_match->SetX1NDC(0.4);
         l_match->SetX2NDC(0.6);
      }
      gPad->Modified();
      //char const* name_match = Form("comp_histos/match/%s.png", hist_match[k]);
      //char const* name_match = Form("comp_histos/match/%s.pdf", hist_match[k]);
      char const* name_match;
	   if (era == "all" && !threeplusthree) name_match = Form("comp_histos/outof3+3/match/%s.png", hist_match[k]);
	   if (era == "all" && threeplusthree) name_match = Form("comp_histos/3+3/match/%s.png", hist_match[k]);
	   if (era == "B" && !threeplusthree) name_match = Form("comp_histos/eraB/match/%s.png", hist_match[k]);
	   if (era == "C1" && !threeplusthree) name_match = Form("comp_histos/eraC1/match/%s.png", hist_match[k]);
	   if (era == "C2" && threeplusthree) name_match = Form("comp_histos/eraC2/match/%s.png", hist_match[k]);
	   if (era == "D" && threeplusthree) name_match = Form("comp_histos/eraD/match/%s.png", hist_match[k]);
	   if (era == "E" && !threeplusthree) name_match = Form("comp_histos/eraE/match/%s.png", hist_match[k]);
	   if (era == "F1" && !threeplusthree) name_match = Form("comp_histos/eraF1/match/%s.png", hist_match[k]);
	   if (era == "F2" && threeplusthree) name_match = Form("comp_histos/eraF2/match/%s.png", hist_match[k]);
	   if (era == "F3" && threeplusthree) name_match = Form("comp_histos/eraF3/match/%s.png", hist_match[k]);
      c_match->SaveAs(name_match);
      c_match->cd();
      c_match->Close();

      TCanvas *c_match_resample = new TCanvas("c_match_resample","",0,0,1200,1000);
      TPad *pad_match_resample = new TPad("pad_match_resample", "pad_match_resample", 0.0, 0.0, 1.0, 1.0);
      if ( k >= 0 && k <= 31 ) {
         //pad_match_resample->SetBottomMargin(0); // Upper and lower plot are joined
         pad_match_resample->Draw();             // Draw the upper pad: pad1
         pad_match_resample->cd();               // pad1 becomes the current pad
         if ( (k >= 0 && k <= 5) || (k >= 18 && k <= 31) ) {
            hs_match_resample->SetMaximum(max_hs_match_resample+step_hs_match_resample);
            h_match_data->SetMaximum(max_hs_match_resample+step_hs_match_resample);
         }
         if ( k == 6 || k == 12 ) {
            hs_match_resample->SetMaximum(1400.);
            h_match_data->SetMaximum(1400.);
         }   
         if ( k == 7 || k == 13 ) {
            hs_match_resample->SetMaximum(4000.);
            h_match_data->SetMaximum(4000.);
         }   
         if ( k == 8 || k == 14 ) {
            hs_match_resample->SetMaximum(800.);
            h_match_data->SetMaximum(800.);
         }   
         if ( k == 9 || k == 15 ) {
            hs_match_resample->SetMaximum(2500.);
            h_match_data->SetMaximum(2500.);
         }   
         if ( k == 10 || k == 11 || k == 16 || k == 17 ) {
            hs_match_resample->SetMaximum(450.);
            h_match_data->SetMaximum(450.);
         }   
         hs_match_resample->Draw("HIST");
         hs_match_resample->GetXaxis()->SetTitleOffset(1.1);
         if ( k == 0 || k == 1) {
            hs_match_resample->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} (GeV/c^{2})");
            hs_match_resample->GetYaxis()->SetTitle("Events");
         }
         if ( k == 2 || k == 3) {
            hs_match_resample->GetXaxis()->SetTitle("p_{T #mu^{+}#mu^{-}} (GeV/c)");
            hs_match_resample->GetYaxis()->SetTitle("Events");
         }
         if ( k == 4 || k == 5) {
            hs_match_resample->GetXaxis()->SetTitle("y_{#mu^{+}#mu^{-}}");
            hs_match_resample->GetYaxis()->SetTitle("Events");
         }    
         if ( k >= 6 && k <= 17 ) {
            hs_match_resample->GetXaxis()->SetTitle("#xi(RP)");
            hs_match_resample->GetYaxis()->SetTitle("dN/d#xi(RP)");
            hs_match_resample->GetYaxis()->SetTitleOffset(1.3);
         }   
         if ( k >= 18 && k <= 23 ) {
            hs_match_resample->GetXaxis()->SetTitle("#xi(RP) - #xi(#mu^{+}#mu^{-})");
            hs_match_resample->GetYaxis()->SetTitle("dN/d(#xi(RP) - #xi(#mu^{+}#mu^{-}))");
            hs_match_resample->GetYaxis()->SetTitleOffset(1.3);
         }   
         if ( k >= 24 && k <= 29 ) {
            hs_match_resample->GetXaxis()->SetTitle("1 - #xi(RP)/#xi(#mu^{+}#mu^{-})");
            hs_match_resample->GetYaxis()->SetTitle("dN/d(1 - #xi(RP)/#xi(#mu^{+}#mu^{-}))");
            hs_match_resample->GetYaxis()->SetTitleOffset(1.3);
         }   
         if ( k == 30 || k == 31 ) {
            hs_match_resample->GetXaxis()->SetTitle("#xi(#mu^{+}#mu^{-})");
            hs_match_resample->GetYaxis()->SetTitle("dN/d#xi(#mu^{+}#mu^{-})");
            hs_match_resample->GetYaxis()->SetTitleOffset(1.3);
         }   
         h_match_data->Draw("SAME");
         h_match_new_resample->Draw("E2 SAME");
      }
      auto l_match_resample = new TLegend(0.925,0.925,0.725,0.725);
      if ( k >= 0 && k <= 31 ) {
         l_match_resample->AddEntry(h_match_data,"2017 Data","lep");
         l_match_resample->AddEntry(h_match_elastic_signal,"pp -> p #gamma#gamma p","f");
         l_match_resample->AddEntry(h_match_inel_el_signal,"pp -> p #gamma#gamma p*","f");
         if(k == 7 || k == 9 || k == 13 || k == 15 || k == 19 || k == 21 || k == 25 || k == 27) {
            l_match_resample->AddEntry(h_match_elastic_mixpu,"pp -> p #gamma#gamma p(*) mixed with pileup","f");
         }   
         l_match_resample->AddEntry(h_match_dy_resample,"Drell-Yan mixed with pileup","f");
         l_match_resample->AddEntry(h_match_new_resample,"Statistic Uncertainties","f");
         l_match_resample->Draw();
         pad_match_resample->RedrawAxis();
         writeExtraText = true;       // if extra text
         extraText  = "Preliminary";  // default extra text is "Preliminary"
         //lumi_13TeV  = "18.34 fb^{-1}";  // default is "20.1 fb^{-1}"
         lumi_13TeV  = "18.85 fb^{-1}";  // default is "20.1 fb^{-1}"
         CMS_lumi( pad_match_resample, iPeriod, iPos );
         pad_match_resample->Update();
         c_match_resample->cd();
         gPad->Update();
         if ( k >= 24 && k <= 29 ){
            l_match_resample->SetX1NDC(0.4);
            l_match_resample->SetX2NDC(0.6);
         }
         gPad->Modified();
      }
      //char const* name_match_resample = Form("comp_histos/match_resample/%s_resample.png", hist_match[k]);
      char const* name_match_resample;
	   if (era == "all" && !threeplusthree) name_match_resample = Form("comp_histos/outof3+3/match_resample/%s.png", hist_match[k]);
	   if (era == "all" && threeplusthree) name_match_resample = Form("comp_histos/3+3/match_resample/%s.png", hist_match[k]);
	   if (era == "B" && !threeplusthree) name_match_resample = Form("comp_histos/eraB/match_resample/%s.png", hist_match[k]);
	   if (era == "C1" && !threeplusthree) name_match_resample = Form("comp_histos/eraC1/match_resample/%s.png", hist_match[k]);
	   if (era == "C2" && threeplusthree) name_match_resample = Form("comp_histos/eraC2/match_resample/%s.png", hist_match[k]);
	   if (era == "D" && threeplusthree) name_match_resample = Form("comp_histos/eraD/match_resample/%s.png", hist_match[k]);
	   if (era == "E" && !threeplusthree) name_match_resample = Form("comp_histos/eraE/match_resample/%s.png", hist_match[k]);
	   if (era == "F1" && !threeplusthree) name_match_resample = Form("comp_histos/eraF1/match_resample/%s.png", hist_match[k]);
	   if (era == "F2" && threeplusthree) name_match_resample = Form("comp_histos/eraF2/match_resample/%s.png", hist_match[k]);
	   if (era == "F3" && threeplusthree) name_match_resample = Form("comp_histos/eraF3/match_resample/%s.png", hist_match[k]);
      //char const* name_match_resample = Form("comp_histos/match_resample/%s_resample.pdf", hist_match[k]);
      if ( k >= 0 && k <= 31 ) {
         c_match_resample->SaveAs(name_match_resample);
         c_match_resample->cd();
         c_match_resample->Close();
      }
   }
   return 0;
}
