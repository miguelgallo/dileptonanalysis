CMSSW_10_6_20-UL_MiniAOD#from CRABClient.UserUtiilities import config, getUsernameFromSiteDB

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
config.JobType.psetName = 'RunGGLL_UL_data_cfg.py'
#config.JobType.maxMemoryMB = 760
#config.JobType.outputFiles = ['output_HepMC.root', 'output_track_xy.root']
config.JobType.allowUndistributedCMSSW = True

config.section_('Data')
#config.Data.useParent = True
config.Data.ignoreLocality = True
#config.Data.lumiMask = '/afs/cern.ch/user/m/malvesga/work/ProtonRecon/TEST/CMSSW_10_6_21/src/test/combined_RPIN_CMS.json'
config.Data.lumiMask = '/afs/cern.ch/user/m/malvesga/work/ProtonRecon/TEST/CMSSW_10_6_21/src/test/CMSgolden_2RPGood_anyarms.json'
config.Data.inputDBS = 'global'
#config.Data.splitting = 'EventAwareLumiBased' #'FileBased'
config.Data.splitting = 'Automatic' #'FileBased'
#config.Data.totalUnits = 100
config.Data.publication = False
config.Data.outputDatasetTag = 'data'

config.section_('Site')
config.Site.storageSite = 'T3_CH_CERNBOX'
config.Site.whitelist = ['T2_CH_*','T2_BE_*', 'T2_DE_*', 'T2_RU_*','T2_US_*', 'T2_IT_*', 'T2_ES_*']
#config.Site.storageSite = 'T2_IT_Bari'

def submit(config):
   try:
      crabCommand('submit', config = config)
   except HTTPException as hte:
      print "Failed submitting task: %s" % (hte.headers)
   except ClientException as cle:
      print "Failed submitting task: %s" % (cle)

if __name__ == '__main__':

   #config.General.requestName = 'DoubleMuon_Data_UL2017B'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleMuon/Run2017B-UL2017_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_Data/DoubleMuon_Run2017B-UL2017'
   #submit(config)

   #config.General.requestName = 'DoubleMuon_Data_UL2017C'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleMuon/Run2017C-UL2017_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_Data/DoubleMuon_Run2017C-UL2017'
   #submit(config)

   #config.General.requestName = 'DoubleMuon_Data_UL2017D'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleMuon/Run2017D-UL2017_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_Data/DoubleMuon_Run2017D-UL2017'
   #submit(config)

   #config.General.requestName = 'DoubleMuon_Data_UL2017E'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleMuon/Run2017E-UL2017_MiniAODv2-v2/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_Data/DoubleMuon_Run2017E-UL2017'
   #submit(config)

   #config.General.requestName = 'DoubleMuon_Data_UL2017F'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleMuon/Run2017F-UL2017_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/Muon_2017_Data/DoubleMuon_Run2017F-UL2017'
   #submit(config)
   
   #config.General.requestName = 'DoubleEG_Data_UL2017B'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleEG/Run2017B-UL2017_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/EG_2017_Data/DoubleEG_Run2017B-UL2017'
   #submit(config)

   #config.General.requestName = 'DoubleEG_Data_UL2017C'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleEG/Run2017C-UL2017_MiniAODv2-v2/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/EG_2017_Data/DoubleEG_Run2017C-UL2017'
   #submit(config)

   #config.General.requestName = 'DoubleEG_Data_UL2017D'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleEG/Run2017D-UL2017_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/EG_2017_Data/DoubleEG_Run2017D-UL2017'
   #submit(config)

   #config.General.requestName = 'DoubleEG_Data_UL2017E'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleEG/Run2017E-UL2017_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/EG_2017_Data/DoubleEG_Run2017E-UL2017'
   #submit(config)

   #config.General.requestName = 'DoubleEG_Data_UL2017F'
   #config.JobType.inputFiles = ['PUHistos_data_2017.root']
   #config.Data.inputDataset = '/DoubleEG/Run2017F-UL2017_MiniAODv2-v2/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/EG_2017_Data/DoubleEG_Run2017F-UL2017'
   #submit(config)
   
   #config.General.requestName = 'DoubleMuon_Data_UL2018A'
   #config.JobType.inputFiles = ['PUHistos_data_2018.root']
   #config.Data.inputDataset = '/DoubleMuon/Run2018A-UL2018_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_Data/DoubleMuon_Run2018A-UL2018'
   #submit(config)
   #
   #config.General.requestName = 'DoubleMuon_Data_UL2018B'
   #config.JobType.inputFiles = ['PUHistos_data_2018.root']
   #config.Data.inputDataset = '/DoubleMuon/Run2018B-UL2018_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_Data/DoubleMuon_Run2018B-UL2018'
   #submit(config)

   #config.General.requestName = 'DoubleMuon_Data_UL2018C'
   #config.JobType.inputFiles = ['PUHistos_data_2018.root']
   #config.Data.inputDataset = '/DoubleMuon/Run2018C-UL2018_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_Data/DoubleMuon_Run2018C-UL2018'
   #submit(config)

   #config.General.requestName = 'DoubleMuon_Data_UL2018D'
   #config.JobType.inputFiles = ['PUHistos_data_2018.root']
   #config.Data.inputDataset = '/DoubleMuon/Run2018D-UL2018_MiniAODv2-v1/MINIAOD'
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_Data/DoubleMuon_Run2018D-UL2018'
   #submit(config)

   #config.General.requestName = 'EGamma_Data_UL2018A'
   #config.JobType.inputFiles = ['PUHistos_data_2018.root']
   #config.Data.inputDataset = '/EGamma/Run2018A-UL2018_MiniAODv2-v1/MINIAOD'
   ##config.Data.unitsPerJob = 38000
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_Data/EGamma_Run2018A-UL2018'
   #submit(config)
   #
   #config.General.requestName = 'EGamma_Data_UL2018B'
   #config.JobType.inputFiles = ['PUHistos_data_2018.root']
   #config.Data.inputDataset = '/EGamma/Run2018B-UL2018_MiniAODv2-v1/MINIAOD'
   ##config.Data.unitsPerJob = 19000
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_Data/EGamma_Run2018B-UL2018'
   #submit(config)

   #config.General.requestName = 'EGamma_Data_UL2018C'
   #config.JobType.inputFiles = ['PUHistos_data_2018.root']
   #config.Data.inputDataset = '/EGamma/Run2018C-UL2018_MiniAODv2-v1/MINIAOD'
   ##config.Data.unitsPerJob = 18000
   #config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_Data/EGamma_Run2018C-UL2018'
   #submit(config)

   config.General.requestName = 'EGamma_Data_UL2018D'
   config.JobType.inputFiles = ['PUHistos_data_2018.root']
   config.Data.inputDataset = '/EGamma/Run2018D-UL2018_MiniAODv2-v2/MINIAOD'
   #config.Data.unitsPerJob = 90000
   config.Data.outLFNDirBase = '/store/user/malvesga/miniaod/Dilepton/2018_Data/EGamma_Run2018D-UL2018'
   submit(config)
