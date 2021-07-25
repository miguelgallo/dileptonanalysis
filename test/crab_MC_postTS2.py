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
config.Data.splitting = 'EventAwareLumiBased' #'FileBased'
#config.Data.splitting = 'Automatic' #'FileBased'
#config.Data.totalUnits = 100
config.Data.publication = False

config.section_('Site')
config.Site.storageSite = 'T2_BR_UERJ'
#config.Site.whitelist = ['T2_CH_*','T2_BE_*', 'T2_DE_*', 'T2_RU_*','T2_US_*', 'T2_IT_*', 'T2_ES_*']
#config.Site.whitelist = ['T1_UK_RAL_Disk', 'T1_US_FNAL_Disk', 'T2_US_Nebraska']
config.Site.whitelist = ['T1_UK_RAL', 'T1_US_FNAL']
#config.Site.storageSite = 'T2_IT_Bari'

def submit(config):
   try:
      crabCommand('submit', config = config)
   except HTTPException as hte:
      print "Failed submitting task: %s" % (hte.headers)
   except ClientException as cle:
      print "Failed submitting task: %s" % (cle)

if __name__ == '__main__':

   #config.General.requestName = 'DYToMuMu_M-50-RunIISummer19UL17-postTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg_postTS2.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_postTS2/direct_simu_reco_cff.py','PUHistos_data.root','PUHistos_mc.root']
   #config.Data.unitsPerJob = 11000
   #config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer19UL17MiniAOD-106X_mc2017_realistic_v6-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/DYToMuMu_M-50-RunIISummer19UL17'
   #submit(config)

   config.General.requestName = 'GGToMuMu_Pt-25_Inel-Inel-RunIISummer19UL17-postTS2'
   config.JobType.psetName = 'RunGGLL_UL_MC_cfg_postTS2.py'
   config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_postTS2/direct_simu_reco_cff.py','PUHistos_data.root','PUHistos_mc.root']
   config.Data.unitsPerJob = 6200
   config.Data.inputDataset = '/GGToMuMu_Pt-25_Inel-Inel_13TeV-lpair/RunIISummer20UL17MiniAOD-106X_mc2017_realistic_v6-v2/MINIAODSIM'
   config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/GGToMuMu_Pt-25_Inel-Inel-RunIISummer19UL17'
   submit(config)

   #config.General.requestName = 'GGToMuMu_Pt-25_Inel-El-RunIISummer19UL17-postTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg_postTS2.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_postTS2/direct_simu_reco_cff.py','PUHistos_data.root','PUHistos_mc.root']
   #config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToMuMu_Pt-25_Inel-El_13TeV-lpair/RunIISummer20UL17MiniAOD-106X_mc2017_realistic_v6-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/GGToMuMu_Pt-25_Inel-El-RunIISummer19UL17'
   #submit(config)

   #config.General.requestName = 'GGToMuMu_Pt-25_Elastic-RunIISummer19UL17-postTS2'
   #config.JobType.psetName = 'RunGGLL_UL_MC_cfg_postTS2.py'
   #config.JobType.inputFiles = ['../proton_simulation_validation/settings/2017_postTS2/direct_simu_reco_cff.py','PUHistos_data.root','PUHistos_mc.root']
   #config.Data.unitsPerJob = 6200
   #config.Data.inputDataset = '/GGToMuMu_Pt-25_Elastic_13TeV-lpair/RunIISummer20UL17MiniAOD-106X_mc2017_realistic_v6-v2/MINIAODSIM'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/GGToMuMu_Pt-25_Elastic-RunIISummer19UL17'
   #submit(config)
