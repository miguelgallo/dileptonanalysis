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

int CompHistos_multi() {

   gStyle->SetOptStat(0);

   setTDRStyle();
   int iPeriod = 4;
   int iPos = 11;

   TFile *f_elastic = new TFile("histos_MC/output_exclusive_new.root", "READ");
   TFile *f_inel_el = new TFile("histos_MC/output_semi-exclusive_new.root", "READ");
   TFile *f_dy_resample = new TFile("histos_MC/output_dy_UL_resample.root", "READ");
   TFile *f_data = new TFile("histos_data/output_data_UL_outof3+3.root", "READ");

   double n_events_h_elastic = 200000;
   double n_events_h_inel_el = 200000;
   double n_events_h_dy = 101077576;
   //double n_events_pileup = 68647048.;
   double number_of_samples = 10; //Used on the resampled DY  
   double total_lumi = 37.190433; //Used on the total luminosity data
   double limit_lumi = 18.341207; //Used on the out of 3+3 luminosity data
   //double limit_lumi = 18.849226; //Used on the 3+3 luminosity data
   double event_selection; //Used on the pile-up protons mixing
   double rap_gap_surv_elastic = 0.89; 
   double rap_gap_surv_inel_el = 0.76; 
   double rap_gap_surv_inelastic = 0.13; 

   double scale_factor_elastic = limit_lumi*rap_gap_surv_elastic*0.017254036*1000 / n_events_h_elastic ; //
   double scale_factor_inel_el = limit_lumi*rap_gap_surv_inel_el*0.025643100*1000 / n_events_h_inel_el ; //
   double scale_factor_dy = limit_lumi*5334000 / n_events_h_dy; 
   double scale_factor_dy_resample = limit_lumi*5334000 / ( n_events_h_dy*number_of_samples ) ; 

   TH1 *left_multi_multitrack_elastic = 0; f_elastic->GetObject("proton_xi_left_multi_match_1_multitrack", left_multi_multitrack_elastic);
   TH1 *left_multi_multitrack_inel_el = 0; f_inel_el->GetObject("proton_xi_left_multi_match_1_multitrack", left_multi_multitrack_inel_el);
   TH1 *left_multi_multitrack_dy = 0; f_dy_resample->GetObject("proton_xi_left_multi_match_1_multitrack", left_multi_multitrack_dy);
   TH1 *left_multi_strips_elastic = 0; f_elastic->GetObject("proton_xi_left_multi_match_1_strips", left_multi_strips_elastic);
   TH1 *left_multi_strips_inel_el = 0; f_inel_el->GetObject("proton_xi_left_multi_match_1_strips", left_multi_strips_inel_el);
   TH1 *left_multi_strips_dy = 0; f_dy_resample->GetObject("proton_xi_left_multi_match_1_strips", left_multi_strips_dy);
   TH1 *left_multi_elastic = 0; f_elastic->GetObject("proton_xi_left_multi_match_1", left_multi_elastic);
   TH1 *left_multi_inel_el = 0; f_inel_el->GetObject("proton_xi_left_multi_match_1", left_multi_inel_el);
   TH1 *left_multi_dy = 0; f_dy_resample->GetObject("proton_xi_left_multi_match_1", left_multi_dy);
   TH1 *left_multi_data = 0; f_data->GetObject("proton_xi_left_multi_match_1", left_multi_data);

   left_multi_multitrack_elastic->SetLineColor(kBlue-4);
   left_multi_multitrack_inel_el->SetLineColor(kBlue-4);
   left_multi_multitrack_dy->SetLineColor(kBlue-4);
   left_multi_strips_elastic->SetLineColor(kGreen-3);
   left_multi_strips_inel_el->SetLineColor(kGreen-3);
   left_multi_strips_dy->SetLineColor(kGreen-3);
   left_multi_elastic->SetLineColor(kRed-3);
   left_multi_inel_el->SetLineColor(kRed-3);
   left_multi_dy->SetLineColor(kRed-3);
   left_multi_data->SetLineColor(kBlack);
   left_multi_multitrack_elastic->SetFillColor(kBlue-4);
   left_multi_multitrack_inel_el->SetFillColor(kBlue-4);
   left_multi_multitrack_dy->SetFillColor(kBlue-4);
   left_multi_strips_elastic->SetFillColor(kGreen-3);
   left_multi_strips_inel_el->SetFillColor(kGreen-3);
   left_multi_strips_dy->SetFillColor(kGreen-3);
   left_multi_elastic->SetFillColor(kRed-3);
   left_multi_inel_el->SetFillColor(kRed-3);
   left_multi_dy->SetFillColor(kRed-3);
   left_multi_data->SetMarkerStyle(8);

   left_multi_multitrack_elastic->Scale(scale_factor_elastic, "width");
   left_multi_multitrack_inel_el->Scale(scale_factor_inel_el, "width");
   left_multi_multitrack_dy->Scale(scale_factor_dy_resample, "width");
   left_multi_strips_elastic->Scale(scale_factor_elastic, "width");
   left_multi_strips_inel_el->Scale(scale_factor_inel_el, "width");
   left_multi_strips_dy->Scale(scale_factor_dy_resample, "width");
   left_multi_elastic->Scale(scale_factor_elastic, "width");
   left_multi_inel_el->Scale(scale_factor_inel_el, "width");
   left_multi_dy->Scale(scale_factor_dy_resample, "width");
   left_multi_data->Scale(1, "width");

   THStack* hs_proton_xi_left_multi_match_1 = new THStack("hs_proton_xi_left_multi_match_1", "");
   hs_proton_xi_left_multi_match_1->Add(left_multi_multitrack_elastic); 
   hs_proton_xi_left_multi_match_1->Add(left_multi_multitrack_inel_el); 
   hs_proton_xi_left_multi_match_1->Add(left_multi_multitrack_dy); 
   hs_proton_xi_left_multi_match_1->Add(left_multi_strips_elastic); 
   hs_proton_xi_left_multi_match_1->Add(left_multi_strips_inel_el); 
   hs_proton_xi_left_multi_match_1->Add(left_multi_strips_dy); 
   hs_proton_xi_left_multi_match_1->Add(left_multi_elastic); 
   hs_proton_xi_left_multi_match_1->Add(left_multi_inel_el); 
   hs_proton_xi_left_multi_match_1->Add(left_multi_dy); 

   /*
      TH1F *h_proton_xi_left_multi_match_1 = 0; 
      h_proton_xi_left_multi_match_1 = (TH1F*)left_multi_multitrack_elastic->Clone("h_proton_xi_left_multi_match_1");
      h_proton_xi_left_multi_match_1->Add(left_multi_multitrack_inel_el); 
      h_proton_xi_left_multi_match_1->Add(left_multi_multitrack_dy); 
      h_proton_xi_left_multi_match_1->Add(left_multi_strips_elastic); 
      h_proton_xi_left_multi_match_1->Add(left_multi_strips_inel_el); 
      h_proton_xi_left_multi_match_1->Add(left_multi_strips_dy); 
      h_proton_xi_left_multi_match_1->Add(left_multi_elastic); 
      h_proton_xi_left_multi_match_1->Add(left_multi_inel_el); 
      h_proton_xi_left_multi_match_1->Add(left_multi_dy); 

      h_proton_xi_left_multi_match_1->Sumw2();
      h_proton_xi_left_multi_match_1->SetFillColor(1);
      h_proton_xi_left_multi_match_1->SetFillStyle(3004);
      h_proton_xi_left_multi_match_1->SetMarkerStyle(6);
      h_proton_xi_left_multi_match_1->SetMarkerSize(0);
      h_proton_xi_left_multi_match_1->SetLineWidth(0);
      */


   TH1 *right_multi_multitrack_elastic = 0; f_elastic->GetObject("proton_xi_right_multi_match_1_multitrack", right_multi_multitrack_elastic);
   TH1 *right_multi_multitrack_inel_el = 0; f_inel_el->GetObject("proton_xi_right_multi_match_1_multitrack", right_multi_multitrack_inel_el);
   TH1 *right_multi_multitrack_dy = 0; f_dy_resample->GetObject("proton_xi_right_multi_match_1_multitrack", right_multi_multitrack_dy);
   TH1 *right_multi_strips_elastic = 0; f_elastic->GetObject("proton_xi_right_multi_match_1_strips", right_multi_strips_elastic);
   TH1 *right_multi_strips_inel_el = 0; f_inel_el->GetObject("proton_xi_right_multi_match_1_strips", right_multi_strips_inel_el);
   TH1 *right_multi_strips_dy = 0; f_dy_resample->GetObject("proton_xi_right_multi_match_1_strips", right_multi_strips_dy);
   TH1 *right_multi_elastic = 0; f_elastic->GetObject("proton_xi_right_multi_match_1", right_multi_elastic);
   TH1 *right_multi_inel_el = 0; f_inel_el->GetObject("proton_xi_right_multi_match_1", right_multi_inel_el);
   TH1 *right_multi_dy = 0; f_dy_resample->GetObject("proton_xi_right_multi_match_1", right_multi_dy);
   TH1 *right_multi_data = 0; f_data->GetObject("proton_xi_right_multi_match_1", right_multi_data);

   right_multi_multitrack_elastic->SetLineColor(kBlue-4);
   right_multi_multitrack_inel_el->SetLineColor(kBlue-4);
   right_multi_multitrack_dy->SetLineColor(kBlue-4);
   right_multi_strips_elastic->SetLineColor(kGreen-3);
   right_multi_strips_inel_el->SetLineColor(kGreen-3);
   right_multi_strips_dy->SetLineColor(kGreen-3);
   right_multi_elastic->SetLineColor(kRed-3);
   right_multi_inel_el->SetLineColor(kRed-3);
   right_multi_dy->SetLineColor(kRed-3);
   right_multi_data->SetLineColor(kBlack);
   right_multi_multitrack_elastic->SetFillColor(kBlue-4);
   right_multi_multitrack_inel_el->SetFillColor(kBlue-4);
   right_multi_multitrack_dy->SetFillColor(kBlue-4);
   right_multi_strips_elastic->SetFillColor(kGreen-3);
   right_multi_strips_inel_el->SetFillColor(kGreen-3);
   right_multi_strips_dy->SetFillColor(kGreen-3);
   right_multi_elastic->SetFillColor(kRed-3);
   right_multi_inel_el->SetFillColor(kRed-3);
   right_multi_dy->SetFillColor(kRed-3);
   right_multi_data->SetMarkerStyle(8);

   right_multi_multitrack_elastic->Scale(scale_factor_elastic, "width");
   right_multi_multitrack_inel_el->Scale(scale_factor_inel_el, "width");
   right_multi_multitrack_dy->Scale(scale_factor_dy_resample, "width");
   right_multi_strips_elastic->Scale(scale_factor_elastic, "width");
   right_multi_strips_inel_el->Scale(scale_factor_inel_el, "width");
   right_multi_strips_dy->Scale(scale_factor_dy_resample, "width");
   right_multi_elastic->Scale(scale_factor_elastic, "width");
   right_multi_inel_el->Scale(scale_factor_inel_el, "width");
   right_multi_dy->Scale(scale_factor_dy_resample, "width");
   right_multi_data->Scale(1, "width");

   THStack* hs_proton_xi_right_multi_match_1 = new THStack("hs_proton_xi_right_multi_match_1", "");
   hs_proton_xi_right_multi_match_1->Add(right_multi_multitrack_elastic); 
   hs_proton_xi_right_multi_match_1->Add(right_multi_multitrack_inel_el); 
   hs_proton_xi_right_multi_match_1->Add(right_multi_multitrack_dy); 
   hs_proton_xi_right_multi_match_1->Add(right_multi_strips_elastic); 
   hs_proton_xi_right_multi_match_1->Add(right_multi_strips_inel_el); 
   hs_proton_xi_right_multi_match_1->Add(right_multi_strips_dy); 
   hs_proton_xi_right_multi_match_1->Add(right_multi_elastic); 
   hs_proton_xi_right_multi_match_1->Add(right_multi_inel_el); 
   hs_proton_xi_right_multi_match_1->Add(right_multi_dy); 

   /*
      TH1F *h_proton_xi_right_multi_match_1 = 0; 
      h_proton_xi_right_multi_match_1 = (TH1F*)right_multi_multitrack_elastic->Clone("h_proton_xi_right_multi_match_1");
      h_proton_xi_right_multi_match_1->Add(right_multi_multitrack_inel_el); 
      h_proton_xi_right_multi_match_1->Add(right_multi_multitrack_dy); 
      h_proton_xi_right_multi_match_1->Add(right_multi_strips_elastic); 
      h_proton_xi_right_multi_match_1->Add(right_multi_strips_inel_el); 
      h_proton_xi_right_multi_match_1->Add(right_multi_strips_dy); 
      h_proton_xi_right_multi_match_1->Add(right_multi_elastic); 
      h_proton_xi_right_multi_match_1->Add(right_multi_inel_el); 
      h_proton_xi_right_multi_match_1->Add(right_multi_dy); 

      h_proton_xi_right_multi_match_1->Sumw2();
      h_proton_xi_right_multi_match_1->SetFillColor(1);
      h_proton_xi_right_multi_match_1->SetFillStyle(3004);
      h_proton_xi_right_multi_match_1->SetMarkerStyle(6);
      h_proton_xi_right_multi_match_1->SetMarkerSize(0);
      h_proton_xi_right_multi_match_1->SetLineWidth(0);
      */

   TCanvas *c_proton_xi_left_multi_match_1 = new TCanvas("c_proton_xi_left_multi_match_1","",0,0,1200,1000);
   TPad *pad_proton_xi_left_multi_match_1 = new TPad("pad_proton_xi_left_multi_match_1", "pad_proton_xi_left_multi_match_1", 0.0, 0.0, 1.0, 1.0);
   //pad_proton_xi_left_multi_match_1->SetBottomMargin(0); // Upper and lower plot are joined
   pad_proton_xi_left_multi_match_1->Draw();             // Draw the upper pad: pad1
   pad_proton_xi_left_multi_match_1->cd();               // pad1 becomes the current pad
   hs_proton_xi_left_multi_match_1->SetMaximum(450.);
   left_multi_data->SetMaximum(450.);
   hs_proton_xi_left_multi_match_1->Draw("HIST NOSTACK");
   hs_proton_xi_left_multi_match_1->GetXaxis()->SetTitle("#xi(RP)");
   hs_proton_xi_left_multi_match_1->GetYaxis()->SetTitle("dN/d#xi(RP)");
   hs_proton_xi_left_multi_match_1->GetXaxis()->SetTitleOffset(1.1);
   hs_proton_xi_left_multi_match_1->GetYaxis()->SetTitleOffset(1.3);
   left_multi_data->Draw("SAME");
   //h_proton_xi_left_multi_match_1->Draw("E2 SAME");
   auto l_proton_xi_left_multi_match_1 = new TLegend(0.925,0.925,0.725,0.725);
   l_proton_xi_left_multi_match_1->AddEntry(left_multi_data,"2017 Data","lep");
   l_proton_xi_left_multi_match_1->AddEntry(left_multi_multitrack_elastic,"only multitrack eff","f");
   l_proton_xi_left_multi_match_1->AddEntry(left_multi_strips_elastic,"multitrack + raddam eff","f");
   l_proton_xi_left_multi_match_1->AddEntry(left_multi_elastic,"all eff","f");
   //l_proton_xi_left_multi_match_1->AddEntry(h_proton_xi_left_multi_match_1,"Statistic Uncertainties","f");
   l_proton_xi_left_multi_match_1->Draw();
   pad_proton_xi_left_multi_match_1->RedrawAxis();
   writeExtraText = true;       // if extra text
   extraText  = "Preliminary";  // default extra text is "Preliminary"
   lumi_13TeV  = "18.34 fb^{-1}";  // default is "20.1 fb^{-1}"
   CMS_lumi( pad_proton_xi_left_multi_match_1, iPeriod, iPos );
   pad_proton_xi_left_multi_match_1->Update();
   c_proton_xi_left_multi_match_1->cd();
   gPad->Update();
   gPad->Modified();
   c_proton_xi_left_multi_match_1->SaveAs("comp_eff/proton_xi_left_multi_match_1.png");
   c_proton_xi_left_multi_match_1->cd();
   c_proton_xi_left_multi_match_1->Close();

   TCanvas *c_proton_xi_right_multi_match_1 = new TCanvas("c_proton_xi_right_multi_match_1","",0,0,1200,1000);
   TPad *pad_proton_xi_right_multi_match_1 = new TPad("pad_proton_xi_right_multi_match_1", "pad_proton_xi_right_multi_match_1", 0.0, 0.0, 1.0, 1.0);
   //pad_proton_xi_right_multi_match_1->SetBottomMargin(0); // Upper and lower plot are joined
   pad_proton_xi_right_multi_match_1->Draw();             // Draw the upper pad: pad1
   pad_proton_xi_right_multi_match_1->cd();               // pad1 becomes the current pad
   hs_proton_xi_right_multi_match_1->SetMaximum(450.);
   right_multi_data->SetMaximum(450.);
   hs_proton_xi_right_multi_match_1->Draw("HIST NOSTACK");
   hs_proton_xi_right_multi_match_1->GetXaxis()->SetTitle("#xi(RP)");
   hs_proton_xi_right_multi_match_1->GetYaxis()->SetTitle("dN/d#xi(RP)");
   hs_proton_xi_right_multi_match_1->GetXaxis()->SetTitleOffset(1.1);
   hs_proton_xi_right_multi_match_1->GetYaxis()->SetTitleOffset(1.3);
   right_multi_data->Draw("SAME");
   //h_proton_xi_right_multi_match_1->Draw("E2 SAME");
   auto l_proton_xi_right_multi_match_1 = new TLegend(0.925,0.925,0.725,0.725);
   l_proton_xi_right_multi_match_1->AddEntry(right_multi_data,"2017 Data","lep");
   l_proton_xi_right_multi_match_1->AddEntry(right_multi_multitrack_elastic,"only multitrack eff","f");
   l_proton_xi_right_multi_match_1->AddEntry(right_multi_strips_elastic,"multitrack + raddam eff","f");
   l_proton_xi_right_multi_match_1->AddEntry(right_multi_elastic,"all eff","f");
   //l_proton_xi_right_multi_match_1->AddEntry(h_proton_xi_right_multi_match_1,"Statistic Uncertainties","f");
   l_proton_xi_right_multi_match_1->Draw();
   pad_proton_xi_right_multi_match_1->RedrawAxis();
   writeExtraText = true;       // if extra text
   extraText  = "Preliminary";  // default extra text is "Preliminary"
   lumi_13TeV  = "18.34 fb^{-1}";  // default is "20.1 fb^{-1}"
   CMS_lumi( pad_proton_xi_right_multi_match_1, iPeriod, iPos );
   pad_proton_xi_right_multi_match_1->Update();
   c_proton_xi_right_multi_match_1->cd();
   gPad->Update();
   gPad->Modified();
   c_proton_xi_right_multi_match_1->SaveAs("comp_eff/proton_xi_right_multi_match_1.png");
   c_proton_xi_right_multi_match_1->cd();
   c_proton_xi_right_multi_match_1->Close();

   return 0;
}
