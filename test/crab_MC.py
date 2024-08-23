#from CRABClient.UserUtiilities import config, getUsernameFromSiteDB

from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException
from httplib import HTTPException

# We want to put all the CRAB project directories from the tasks we submit here into one common directory.
# That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).

from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.transferLogs = True
config.General.workArea = 'crab_projects'

config.section_('JobType')
config.JobType.pluginName = 'Analysis'
#config.JobType.maxMemoryMB = 760
#config.JobType.outputFiles = ['output_HepMC.root', 'output_track_xy.root']
config.JobType.allowUndistributedCMSSW = True

config.section_('Data')
config.Data.inputDBS = 'global'
#config.Data.splitting = 'EventAwareLumiBased' #'FileBased'
#config.Data.splitting = 'FileBased'
config.Data.splitting = 'Automatic' #'FileBased'
#config.Data.totalUnits = 100
config.Data.publication = False

config.section_('Site')
config.Site.storageSite = 'T3_CH_CERNBOX'
#config.Site.storageSite = 'T2_BR_UERJ'
#config.Site.whitelist = ['T1_ES_PIC', 'T1_US_FNAL', 'T1_IT_CNAF','T2_BE_*', 'T2_DE_*', 'T2_US_*', 'T2_IT_*', 'T2_ES_*', 'T2_FR_*', 'T2_KR_*', 'T2_HU_*', 'T2_TW_*', 'T2_EE_*', 'T2_IT_*', 'T2_FI_*', 'T2_TR_*']
#config.Site.blacklist = ['T2_CH_CERN_HLT', 'T2_RU_SINP', 'T2_RU_ITEP']
#config.Site.whitelist = ['T1_UK_RAL', 'T1_US_FNAL']
#config.Site.whitelist = ['T2_FR_IPHC']
#config.Site.storageSite = 'T2_IT_Bari'

def submit(config):
   try:
      crabCommand('submit', config = config)
   except HTTPException as hte:
      print "Failed submitting task: %s" % (hte.headers)
   except ClientException as cle:
      print "Failed submitting task: %s" % (cle)

if __name__ == '__main__':

   #config.General.requestName = 'DYToEE_M-50-RunIISummer20UL17-postTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_postTS2/direct_simu_reco_cff.py','PUHistos_data_2017.root','PUHistos_mc_2017_UL.root']
   #config.Data.unitsPerJob = 11000
   #config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL17MiniAODv2-106X_mc2017_realistic_v9-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_MC/DYToEE_M-50-RunIISummer20UL17'
   #submit(config)

   #config.General.requestName = 'GGToEE_Pt-35_Inel-Inel-RunIISummer20UL17-postTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_postTS2/direct_simu_reco_cff.py','PUHistos_data_2017.root','PUHistos_mc_2017_UL.root']
   ##config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToEE_Pt-35_Inel-Inel_13TeV-lpair/RunIISummer20UL17MiniAODv2-106X_mc2017_realistic_v9-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_MC/GGToEE_Pt-35_Inel-Inel-RunIISummer20UL17'
   #submit(config)

   #config.General.requestName = 'GGToEE_Pt-35_Inel-El-RunIISummer20UL17-preTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_preTS2/direct_simu_reco_cff.py','PUHistos_data_2017.root','PUHistos_mc_2017_UL.root']
   ##config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToEE_Pt-35_Inel-El_13TeV-lpair/RunIISummer20UL17MiniAODv2-106X_mc2017_realistic_v9-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_MC/GGToEE_Pt-35_Inel-El-RunIISummer20UL17'
   #submit(config)

   #config.General.requestName = 'GGToEE_Pt-35_Elastic-RunIISummer20UL17-postTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_postTS2/direct_simu_reco_cff.py','PUHistos_data_2017.root','PUHistos_mc_2017_UL.root']
   ##config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToEE_Pt-35_Elastic_13TeV-lpair/RunIISummer20UL17MiniAODv2-106X_mc2017_realistic_v9-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_MC/GGToEE_Pt-35_Elastic-RunIISummer20UL17'
   #submit(config)
   
   #config.General.requestName = 'GGToMuMu_Pt-25_Inel-Inel-RunIISummer20UL17-preTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_preTS2/direct_simu_reco_cff.py','PUHistos_data_2017.root','PUHistos_mc_2017_UL.root']
   ##config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToMuMu_Pt-25_Inel-Inel_13TeV-lpair/RunIISummer20UL17MiniAODv2-106X_mc2017_realistic_v9-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_MC/GGToMuMu_Pt-25_Inel-Inel-RunIISummer20UL17'
   #submit(config)

   #config.General.requestName = 'GGToMuMu_Pt-25_Inel-El-RunIISummer20UL17-preTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_preTS2/direct_simu_reco_cff.py','PUHistos_data_2017.root','PUHistos_mc_2017_UL.root']
   ##config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToMuMu_Pt-25_Inel-El_13TeV-lpair/RunIISummer20UL17MiniAODv2-106X_mc2017_realistic_v9-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_MC/GGToMuMu_Pt-25_Inel-El-RunIISummer20UL17'
   #submit(config)

   #config.General.requestName = 'GGToMuMu_Pt-25_Elastic-RunIISummer20UL17-preTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_preTS2/direct_simu_reco_cff.py','PUHistos_data_2017.root','PUHistos_mc_2017_UL.root']
   ##config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToMuMu_Pt-25_Elastic_13TeV-lpair/RunIISummer20UL17MiniAODv2-106X_mc2017_realistic_v9-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_MC/GGToMuMu_Pt-25_Elastic-RunIISummer20UL17'
   #submit(config)

   #config.General.requestName = 'DYToEE_M-50-RunIISummer20UL18'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2018/direct_simu_reco_cff.py','PUHistos_data_2018.root','PUHistos_mc_2018_UL.root']
   #config.Data.unitsPerJob = 11000
   #config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL18MiniAODv2-106X_upgrade2018_realistic_v16_L1v1-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_MC/DYToEE_M-50-RunIISummer20UL18'
   #submit(config)

   #config.General.requestName = 'GGToMuMu_Pt-25_Inel-Inel-RunIISummer20UL18'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2018/direct_simu_reco_cff.py','PUHistos_data_2018.root','PUHistos_mc_2018_UL.root']
   ##config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToMuMu_Pt-25_Inel-Inel_13TeV-lpair/RunIISummer20UL18MiniAODv2-106X_upgrade2018_realistic_v16_L1v1-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_MC/GGToMuMu_Pt-25_Inel-Inel-RunIISummer20UL18'
   #submit(config)

   #config.General.requestName = 'GGToMuMu_Pt-25_Inel-El-RunIISummer20UL18'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2018/direct_simu_reco_cff.py','PUHistos_data_2018.root','PUHistos_mc_2018_UL.root']
   ##config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToMuMu_Pt-25_Inel-El_13TeV-lpair/RunIISummer20UL18MiniAODv2-106X_upgrade2018_realistic_v16_L1v1-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_MC/GGToMuMu_Pt-25_Inel-El-RunIISummer20UL18'
   #submit(config)

   #config.General.requestName = 'GGToMuMu_Pt-25_Elastic-RunIISummer20UL18'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2018/direct_simu_reco_cff.py','PUHistos_data_2018.root','PUHistos_mc_2018_UL.root']
   ##config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToMuMu_Pt-25_Elastic_13TeV-lpair/RunIISummer20UL18MiniAODv2-106X_upgrade2018_realistic_v16_L1v1-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_MC/GGToMuMu_Pt-25_Elastic-RunIISummer20UL18'
   #submit(config)
   
   #config.General.requestName = 'DYToEE_M-50-RunIISummer20UL18'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2018/direct_simu_reco_cff.py','PUHistos_data_2018.root','PUHistos_mc_2018_UL.root']
   ##config.Data.unitsPerJob = 11000
   #config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL18MiniAODv2-106X_upgrade2018_realistic_v16_L1v1-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_MC/DYToEE_M-50-RunIISummer20UL18'
   #submit(config)
   #
   config.General.requestName = 'GGToEE_Pt-35_Inel-Inel-RunIISummer20UL18'
   config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   config.JobType.inputFiles = ['../proton_simulation_validation/settings/2018/direct_simu_reco_cff.py','PUHistos_data_2018.root','PUHistos_mc_2018_UL.root']
   #config.Data.unitsPerJob = 6200
   config.Data.inputDataset = '/GGToEE_Pt-35_Inel-Inel_13TeV-lpair/RunIISummer20UL18MiniAODv2-106X_upgrade2018_realistic_v16_L1v1-v2/MINIAODSIM'
   config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_MC/GGToEE_Pt-35_Inel-Inel-RunIISummer20UL18'
   submit(config)

   config.General.requestName = 'GGToEE_Pt-35_Inel-El-RunIISummer20UL18'
   config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   config.JobType.inputFiles = ['../proton_simulation_validation/settings/2018/direct_simu_reco_cff.py','PUHistos_data_2018.root','PUHistos_mc_2018_UL.root']
   #config.Data.unitsPerJob = 6200
   config.Data.inputDataset = '/GGToEE_Pt-35_Inel-El_13TeV-lpair/RunIISummer20UL18MiniAODv2-106X_upgrade2018_realistic_v16_L1v1-v2/MINIAODSIM'
   config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_MC/GGToEE_Pt-35_Inel-El-RunIISummer20UL18'
   submit(config)

   config.General.requestName = 'GGToEE_Pt-35_Elastic-RunIISummer20UL18'
   config.JobType.psetName = 'RunGGLL_UL_MC_cfg.py'
   config.JobType.inputFiles = ['../proton_simulation_validation/settings/2018/direct_simu_reco_cff.py','PUHistos_data_2018.root','PUHistos_mc_2018_UL.root']
   #config.Data.unitsPerJob = 6200
   config.Data.inputDataset = '/GGToEE_Pt-35_Elastic_13TeV-lpair/RunIISummer20UL18MiniAODv2-106X_upgrade2018_realistic_v16_L1v1-v2/MINIAODSIM'
   config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_MC/GGToEE_Pt-35_Elastic-RunIISummer20UL18'
   submit(config)
