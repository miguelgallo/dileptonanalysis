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
.L ntp1-miniaod_data.C
run("/eos/user/m/malvesga/miniaod/from_analysis/data_UL/DoubleMuon/$file", "$file", "all", true)
.q
EOS

