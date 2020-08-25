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
run("/mnt/hadoop/cms/store/user/malvesga/MC_signal/$file", "/mnt/hadoop/cms/store/user/malvesga/pileup/pileup_protons_DoubleMuon_C2.root", "eraC2_$file", "C2", false, 1, false, true)
.q
EOS
