#!/bin/bash

file=$1
echo "Input file: $file"
echo "Listing input file:"
ls -la $file
echo "Listing current dir:"
ls -la .
pwd

echo 'Running'
root -b -l <<EOS
.L ntp1-miniaod_MC_pileup.C
run("/eos/user/m/malvesga/miniaod/from_analysis/MC_bkg/$file", "/eos/user/m/malvesga/miniaod/from_analysis/pileup/pileup_protons_DoubleMuon_3+3.root", "$file", "all", false, 1, false, true)
.q
EOS

