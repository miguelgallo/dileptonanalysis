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
run("/mnt/hadoop/cms/store/user/malvesga/MC_bkg/$file", "/mnt/hadoop/cms/store/user/malvesga/pileup/pileup_protons_DoubleMuon_3+3.root", "3+3_$file", "all", true, 10, true, true)
.q
EOS

