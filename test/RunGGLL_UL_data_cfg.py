import FWCore.ParameterSet.Config as cms
#process = cms.Process("ggll")
#from Configuration.StandardSequences.Eras import eras
year = '2018'

#if year == '2017':
#   process = cms.Process("ggll", eras.Run2_2017)
#if year == '2018':
#   process = cms.Process("ggll", eras.Run2_2018)

runOnMC = False
useAOD = True # AOD or MiniAOD?
MINIAOD = True
runOnMuon = False
runOnElectron = not runOnMuon
#Run2_2017 = False
#Run2_2018 = not Run2_2017


if year == '2017':
    from Configuration.Eras.Era_Run2_2017_cff import *
    process = cms.Process("CTPPSTestProtonReconstruction", Run2_2017)
if year == '2018':
    from Configuration.Eras.Era_Run2_2018_cff import *
    process = cms.Process("CTPPSTestProtonReconstruction", Run2_2018)



#########################
#    General options    #
#########################

process.load("FWCore.MessageService.MessageLogger_cfi")
process.options   = cms.untracked.PSet(
      wantSummary = cms.untracked.bool(True),
      #SkipEvent = cms.untracked.vstring('ProductNotFound'),
      allowUnscheduled = cms.untracked.bool(True),
      )

#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

#########################
#      Input files      #
#########################

process.source = cms.Source("PoolSource",
      fileNames = cms.untracked.vstring(
         #'/store/data/Run2018A/EGamma/MINIAOD/UL2018_MiniAODv2-v1/230000/1DC29AF8-7091-4245-A0D8-CFDF650310CC.root'
         #'/store/data/Run2017B/DoubleMuon/MINIAOD/31Mar2018-v1/00000/4C58EEB0-6337-E811-8D28-D4AE527EEA1D.root'
         #'/store/data/Run2017B/DoubleMuon/MINIAOD/09Aug2019_UL2017-v1/50000/E88872FD-A2CE-FD47-B781-3094AF7E9A2D.root'

         #'/store/data/Run2018A/DoubleMuon/MINIAOD/UL2018_MiniAODv2-v1/260000/C72EAAD1-3931-104C-9721-045F2404C30B.root'
         '/store/data/Run2017B/DoubleMuon/MINIAOD/UL2017_MiniAODv2-v1/260000/CC1BF6CC-AC5A-FC41-9AD7-E4D1305438C1.root'
         #'/store/data/Run2017B/DoubleEG/MINIAOD/UL2017_MiniAODv2-v1/230000/65BBFF26-535F-FD4C-B9D4-3F85CF3A7EF7.root'

         #'/store/data/Run2018C/DoubleMuon/AOD/12Nov2019_UL2018-v2/130000/E09FD76D-7B2C-5041-8C0F-4D39CBAEEF97.root'
         #'/store/data/Run2018B/DoubleMuon/AOD/12Nov2019_UL2018-v2/70001/B49D7F0A-3AF4-F948-BE0C-15C845091793.root'
         #       'file:/tmp/jjhollar/32D7FDE9-748B-ED43-A45D-587019CC5D92.root'
         ),
      #firstEvent = cms.untracked.uint32(0)
      )

#########################
#        Triggers       #
#########################

process.load("DiffractiveForwardAnalysis.GammaGammaLeptonLepton.HLTFilter_cfi")
process.hltFilter.TriggerResultsTag = cms.InputTag("TriggerResults","","HLT")
if runOnMuon:
   process.hltFilter.HLTPaths = cms.vstring(
         'HLT_DoubleMu43NoFiltersNoVtx_*',
         'HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_*',
         'HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_*'
         )
if runOnElectron:
   process.hltFilter.HLTPaths = cms.vstring(
         'HLT_DoubleEle33_CaloIdL_MW_v*',
         'HLT_Ele27_HighEta_Ele20_Mass55_v*',
         'HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v*'
         )

# If using full proton re-reco (legacy) - local RP reconstruction chain with standard settings
process.load("RecoCTPPS.Configuration.recoCTPPS_cff")
process.ctppsLocalTrackLiteProducer.includePixels = cms.bool(True)
process.ctppsLocalTrackLiteProducer.includeStrips = cms.bool(True)
#process.ctppsLocalTrackLiteProducer.includeDiamonds = cms.bool(True)
process.ctppsProtons.doSingleRPReconstruction = cms.bool(True)
process.ctppsProtons.tagLocalTrackLite = cms.InputTag("ctppsLocalTrackLiteProducer","","CTPPSTest")


#########################
#      Preskimming      #
#########################
# declare global tag
process.load("Configuration.StandardSequences.GeometryDB_cff") ## FIXME need to ensure that this is the good one                                     
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, "106X_dataRun2_v32")

process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")


#########################
#     PAT-ification     #
#########################
## Look at https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuidePATTools#Core_Tools for more information

process.out = cms.OutputModule("PoolOutputModule",
      fileName = cms.untracked.string('PATuple.root'),
      outputCommands = cms.untracked.vstring(
         #        'drop *',
         #        'keep *_offline*PrimaryVertices*_*_*',
         #        'keep *_selectedPatMuons*_*_*',
         #        'keep *_*lectron*_*_*',
         #        'keep *_selectedPatElectrons*_*_*',
         #        'keep *_selectedPat*Photons*_*_*',
         #        'keep *_selectedPatJets*_*_*',
         #        'keep *_*MET*_*_*',
         #        'keep *_*particleFlow*_*_*',
         'keep *_*_*_*'
         ),
      )

from PhysicsTools.PatAlgos.tools.helpers import getPatAlgosToolsTask
patAlgosToolsTask = getPatAlgosToolsTask(process)

process.load("PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff")
patAlgosToolsTask.add(process.patCandidatesTask)

process.load("PhysicsTools.PatAlgos.selectionLayer1.selectedPatCandidates_cff")
patAlgosToolsTask.add(process.selectedPatCandidatesTask)

from PhysicsTools.PatAlgos.tools.coreTools import runOnData
if not runOnMC:
   runOnData( process )

#########################
#      Electron ID      #
#########################

#from PhysicsTools.SelectorUtils.tools.vid_id_tools import switchOnVIDElectronIdProducer, setupVIDElectronSelection, setupAllVIDIdsInModule, DataFormat
from PhysicsTools.SelectorUtils.tools.vid_id_tools import *

switchOnVIDElectronIdProducer(process, DataFormat.AOD)
#setupAllVIDIdsInModule(process, 'RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Spring15_25ns_V1_cff', setupVIDElectronSelection)
setupAllVIDIdsInModule(process, 'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_GeneralPurpose_V1_cff', setupVIDElectronSelection)

#########################
#       Photon ID       #
#########################

switchOnVIDPhotonIdProducer(process, DataFormat.AOD)
setupAllVIDIdsInModule(process, 'RecoEgamma.PhotonIdentification.Identification.mvaPhotonID_Spring16_nonTrig_V1_cff', setupVIDPhotonSelection)

#########################
#     Proton RECO       #
#########################

# Not needed when running on real UL!

#########################
#       Analysis        #
#########################

process.load("DiffractiveForwardAnalysis.GammaGammaLeptonLepton.GammaGammaLL_cfi")

process.ggll_aod.triggersList = process.hltFilter.HLTPaths
if runOnMuon: 
   process.ggll_aod.leptonsType = cms.string('Muon')
if runOnElectron: 
   process.ggll_aod.leptonsType = cms.string('Electron')
#process.ggll_aod.leptonsType = cms.string('ElectronMuon')
process.ggll_aod.runOnMC = cms.bool(runOnMC)
process.ggll_aod.fetchProtons = cms.bool(True)
process.ggll_aod.saveExtraTracks = cms.bool(False)
process.ggll_aod.year = cms.string(year)

process.ggll_miniaod.triggersList = process.hltFilter.HLTPaths
if runOnMuon: 
   process.ggll_miniaod.leptonsType = cms.string('Muon')
if runOnElectron: 
   process.ggll_miniaod.leptonsType = cms.string('Electron')
process.ggll_miniaod.runOnMC = cms.bool(runOnMC)
process.ggll_miniaod.fetchProtons = cms.bool(True)
process.ggll_miniaod.saveExtraTracks = cms.bool(False)
process.ggll_miniaod.year = cms.string(year)
process.ggll_miniaod.datapupath = 'pileup'
if year == '2017':
   process.ggll_miniaod.datapufile = cms.string('PUHistos_data_2017.root')
if year == '2018':
   process.ggll_miniaod.datapufile = cms.string('PUHistos_data_2018.root')


# E/gamma identification
process.ggll_miniaod.eleIdLabels = cms.PSet(
      mediumLabel = cms.InputTag('mvaEleID-Spring16-GeneralPurpose-V1-wp90'),
      tightLabel = cms.InputTag('mvaEleID-Spring16-GeneralPurpose-V1-wp80'),
      )
process.ggll_miniaod.phoIdLabels = cms.PSet(
      mediumLabel = cms.InputTag('mvaPhoID-Spring16-nonTrig-V1-wp90'),
      tightLabel = cms.InputTag('mvaPhoID-Spring16-nonTrig-V1-wp80'),
      )
#process.ggll_aod.eleMediumIdMap = cms.InputTag("egmGsfElectronIDs:mvaEleID-Spring16-GeneralPurpose-V1-wp90")
#process.ggll_aod.eleTightIdMap = cms.InputTag("egmGsfElectronIDs:mvaEleID-Spring16-GeneralPurpose-V1-wp80")
#process.ggll_aod.phoMediumIdMap = cms.InputTag("egmPhotonIDs:mvaPhoID-Spring16-nonTrig-V1-wp90")
#process.ggll_aod.phoTightIdMap = cms.InputTag("egmPhotonIDs:mvaPhoID-Spring16-nonTrig-V1-wp80")

# prepare the output file
process.TFileService = cms.Service('TFileService',
      #fileName = cms.string('output_data_{0}.root'.format(year)),
      fileName = cms.string('output_data.root'),
      closeFileFast = cms.untracked.bool(True)
      )
# processing path
if MINIAOD == False:
   process.p = cms.Path(
         process.hltFilter*
         process.egmPhotonIDSequence*
         process.egmGsfElectronIDSequence*
         process.ggll_aod
         )

else:
   process.p = cms.Path(
         process.hltFilter*
         process.egmPhotonIDSequence*
         process.egmGsfElectronIDSequence*
         process.ggll_miniaod
         )

#process.outpath = cms.EndPath(process.out, patAlgosToolsTask)
process.outpath = cms.EndPath(patAlgosToolsTask)

#print process.dumpPython()

