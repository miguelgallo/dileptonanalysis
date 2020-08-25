#define ntp1_cxx
#include "ntp1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TSystem.h>
#include <TROOT.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TPad.h>
#include <TCanvas.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TSpline.h>
#include <math.h>
#include "DataFormats/Math/interface/deltaPhi.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#define PI 3.14159265358979323846

#include <iostream>
#include <vector>
#include <set>
using namespace std;


void ntp1::Loop()
{

   TH1::SetDefaultSumw2( true );

   TH1D *trackpixshift_multi1 = new TH1D("trackpixshift_multi1", "trackpixshift_multi1", 3, -1, 2);
   TH1D *trackpixshift_multi2 = new TH1D("trackpixshift_multi2", "trackpixshift_multi2", 3, -1, 2);
   
   TH1D *xi_singleRP_RP3 = new TH1D("xi_singleRP_RP3", "#xi - RP3", 40, 0, .2);
   TH1D *xi_singleRP_RP3_recoinfo02 = new TH1D("xi_singleRP_RP3_recoinfo02", "#xi - RP3 - Reco Info 0,2", 40, 0, .2);
   TH1D *xi_singleRP_RP3_ratio = new TH1D("xi_singleRP_RP3_ratio", "Ratio #xi - RP3", 40, 0, .2);
   
   TH1D *xi_singleRP_RP23 = new TH1D("xi_singleRP_RP23", "#xi - RP23", 40, 0, .2);
   TH1D *xi_singleRP_RP23_recoinfo02 = new TH1D("xi_singleRP_RP23_recoinfo02", "#xi - RP23 - Reco Info 0,2", 40, 0, .2);
   TH1D *xi_singleRP_RP23_ratio = new TH1D("xi_singleRP_RP23_ratio", "Ratio #xi - RP23", 40, 0, .2);

   TH1D *xi_singleRP_RP103 = new TH1D("xi_singleRP_RP103", "#xi - RP103", 40, 0, .2);
   TH1D *xi_singleRP_RP103_recoinfo02 = new TH1D("xi_singleRP_RP103_recoinfo02", "#xi - RP103 - Reco Info 0,2", 40, 0, .2);
   TH1D *xi_singleRP_RP103_ratio = new TH1D("xi_singleRP_RP103_ratio", "Ratio #xi - RP103", 40, 0, .2);
   
   TH1D *xi_singleRP_RP123 = new TH1D("xi_singleRP_RP123", "#xi - RP123", 40, 0, .2);
   TH1D *xi_singleRP_RP123_recoinfo02 = new TH1D("xi_singleRP_RP123_recoinfo02", "#xi - RP123 - Reco Info 0,2", 40, 0, .2);
   TH1D *xi_singleRP_RP123_ratio = new TH1D("xi_singleRP_RP123_ratio", "Ratio #xi - RP123", 40, 0, .2);
   
   TH1D *xi_multiRP_left = new TH1D("xi_multiRP_left", "#xi - Left", 40, 0, .2);
   TH1D *xi_multiRP_left_recoinfo02 = new TH1D("xi_multiRP_left_recoinfo02", "#xi - Left - Reco Info 0,2", 40, 0, .2);
   TH1D *xi_multiRP_left_ratio = new TH1D("xi_multiRP_left_ratio", "Ratio #xi - Left", 40, 0, .2);
   
   TH1D *xi_multiRP_right = new TH1D("xi_multiRP_right", "#xi - Right", 40, 0, .2);
   TH1D *xi_multiRP_right_recoinfo02 = new TH1D("xi_multiRP_right_recoinfo02", "#xi - Right - Reco Info 0,2", 40, 0, .2);
   TH1D *xi_multiRP_right_ratio = new TH1D("xi_multiRP_right_ratio", "Ratio #xi - Right", 40, 0, .2);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   //ttree loop 
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      double rp3_xi, rp23_xi, rp103_xi, rp123_xi, left_xi, right_xi;

      for ( size_t idx = 0; idx < nRecoProtCand; idx++ ) {
         if (ProtCand_ismultirp[idx] == 0) {
            if (ProtCand_rpid[idx] == 3) {
               xi_singleRP_RP3->Fill(ProtCand_xi[idx]);
               if (ProtCand_trackpixshift_single[idx] == 0) {
                  xi_singleRP_RP3_recoinfo02->Fill(ProtCand_xi[idx]);           
                  rp3_xi = ProtCand_xi[idx];
               }
               xi_singleRP_RP3_ratio->Divide(xi_singleRP_RP3_recoinfo02,xi_singleRP_RP3);
            }
            if (ProtCand_rpid[idx] == 23) {
               xi_singleRP_RP23->Fill(ProtCand_xi[idx]);
               if (ProtCand_trackpixshift_single[idx] == 0) {
                  xi_singleRP_RP23_recoinfo02->Fill(ProtCand_xi[idx]);           
                  rp23_xi = ProtCand_xi[idx];
               }
               xi_singleRP_RP23_ratio->Divide(xi_singleRP_RP23_recoinfo02,xi_singleRP_RP23);
            }
            if (ProtCand_rpid[idx] == 103) {
               xi_singleRP_RP103->Fill(ProtCand_xi[idx]);
               if (ProtCand_trackpixshift_single[idx] == 0) {
                  xi_singleRP_RP103_recoinfo02->Fill(ProtCand_xi[idx]);           
                  rp103_xi = ProtCand_xi[idx];
               }
               xi_singleRP_RP103_ratio->Divide(xi_singleRP_RP103_recoinfo02,xi_singleRP_RP103);
            }
            if (ProtCand_rpid[idx] == 123) {
               xi_singleRP_RP123->Fill(ProtCand_xi[idx]);
               if (ProtCand_trackpixshift_single[idx] == 0) {
                  xi_singleRP_RP123_recoinfo02->Fill(ProtCand_xi[idx]);           
                  rp123_xi = ProtCand_xi[idx];
               }
               xi_singleRP_RP123_ratio->Divide(xi_singleRP_RP123_recoinfo02,xi_singleRP_RP123);
            }
         }
         if (ProtCand_ismultirp[idx] == 1) {
            trackpixshift_multi1->Fill(ProtCand_trackpixshift_multi1[idx]);
            trackpixshift_multi2->Fill(ProtCand_trackpixshift_multi2[idx]);
            if (ProtCand_arm[idx] == 0) {
               xi_multiRP_left->Fill(ProtCand_xi[idx]);
               if (ProtCand_trackpixshift_multi1[idx] == 0 && ProtCand_trackpixshift_multi2[idx] == 0) {
                  xi_multiRP_left_recoinfo02->Fill(ProtCand_xi[idx]);
                  left_xi = ProtCand_xi[idx];
               }
               xi_multiRP_left_ratio->Divide(xi_multiRP_left_recoinfo02,xi_multiRP_left);
            }
            if (ProtCand_arm[idx] == 1) {
               xi_multiRP_right->Fill(ProtCand_xi[idx]);
               if (ProtCand_trackpixshift_multi1[idx] == 0 && ProtCand_trackpixshift_multi2[idx] == 0) {
                  xi_multiRP_right_recoinfo02->Fill(ProtCand_xi[idx]);
                  right_xi = ProtCand_xi[idx];
               }
               xi_multiRP_right_ratio->Divide(xi_multiRP_right_recoinfo02,xi_multiRP_right);
            }
         }
      }
   }
   //write the histograms
   TFile* f = new TFile(outfileName.c_str(), "RECREATE");

   trackpixshift_multi1->Write();
   trackpixshift_multi2->Write();
   
   xi_singleRP_RP3->Write();
   xi_singleRP_RP3_recoinfo02->Write();
   xi_singleRP_RP3_ratio->Write();
  
   xi_singleRP_RP23->Write();
   xi_singleRP_RP23_recoinfo02->Write();
   xi_singleRP_RP23_ratio->Write();
  
   xi_singleRP_RP103->Write();
   xi_singleRP_RP103_recoinfo02->Write();
   xi_singleRP_RP103_ratio->Write();
  
   xi_singleRP_RP123->Write();
   xi_singleRP_RP123_recoinfo02->Write();
   xi_singleRP_RP123_ratio->Write();
  
   xi_multiRP_left->Write();
   xi_multiRP_left_recoinfo02->Write();
   xi_multiRP_left_ratio->Write();
  
   xi_multiRP_right->Write();
   xi_multiRP_right_recoinfo02->Write();
   xi_multiRP_right_ratio->Write();

   f->Close();

}

int run(std::string fileName="input.root", std::string outfileName="output_cut.root", bool threeplusthree=false) {
   ntp1 m(fileName, outfileName);
   m.SetThreePlusThree( threeplusthree );
   m.Loop();

   return 0;
}


