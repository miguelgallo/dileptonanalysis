# DileptonAnalysis - A guide to create your Ntuple generator 

## Setting the workspace 

Install the 10_6_20 release of CMSSW and set the environment

```
export SCRAM_ARCH=slc7_amd64_gcc700 
cmsrel CMSSW_10_6_20
cd CMSSW_10_6_20/src/
cmsenv 
```

Install all additional packages that are not included in the $CMSSW_RELEASE_BASE

```
git clone git@github.com:miguelgallo/DiffractiveForwardAnalysis.git
cd DiffractiveForwardAnalysis
git checkout CMSSW106X_FromUltraLegacy
cd ..

git clone https://github.com/jan-kaspar/proton_simulation_validation.git
cd proton_simulation_validation
git checkout 9b2cff77711484e90c2323008eedc8c717cfcc41
cd ..

git clone git@github.com:miguelgallo/DileptonAnalysis.git
cd DileptonAnalysis
git checkout CMSSW_10_6_20-UL_MiniAOD
mv test/ ../
cd .. 
rm -rf DileptonAnalysis

scram b -j8
```

With everything set and done as explained in this tutorial, one should be able to run the scripts *test/RunGGLL_UL.py* and run the Ntuple generator for the Dilepton analysis

## Running 

### Directly

```
voms-proxy-init --voms cms 
cmsRun RunGGLL_UL_*.py 
```

### Via CRAB

```
voms-proxy-init --voms cms
source /cvmfs/cms.cern.ch/crab3/crab.sh
python crab_*.py 
```

**PS.: Remember to change my addresses to the one using this tutorial, in the files at the *test* folder** 
