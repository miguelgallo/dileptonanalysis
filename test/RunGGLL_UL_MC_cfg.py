import FWCore.ParameterSet.Config as cms
import sys

#from Configuration.StandardSequences.Eras import eras
#process = cms.Process("CTPPSTestProtonReconstruction", eras.Run2_2017)

runOnMC = True
useAOD = True
MINIAOD = True
runOnMuon = False
runOnElectron = not runOnMuon 

year = '2018MC'
preTS2 = True
postTS2 = not preTS2

if year == '2017MC':
   if preTS2:
      # load common code
      sys.path.insert(0, '/afs/cern.ch/user/m/malvesga/work/ProtonRecon/TEST/CMSSW_10_6_21/src/proton_simulation_validation/settings/2017_preTS2/')
      import direct_simu_reco_cff as profile
      process = cms.Process('CTPPSTest', profile.era)
      profile.LoadConfig(process)
      profile.config.SetDefaults(process)
      process.load("CalibPPS.ESProducers.ctppsBeamParametersESSource_cfi")
      process.load("Validation.CTPPS.simu_config.year_2017_preTS2_cff")
      process.load("direct_simu_reco_cff")
   
   if postTS2:
      # load common code
      sys.path.insert(0, '/afs/cern.ch/user/m/malvesga/work/ProtonRecon/TEST/CMSSW_10_6_21/src/proton_simulation_validation/settings/2017_postTS2/')
      import direct_simu_reco_cff as profile
      process = cms.Process('CTPPSTest', profile.era)
      profile.LoadConfig(process)
      profile.config.SetDefaults(process)
      process.load("CalibPPS.ESProducers.ctppsBeamParametersESSource_cfi")
      process.load("Validation.CTPPS.simu_config.year_2017_postTS2_cff")
      process.load("direct_simu_reco_cff")

if year == '2018MC':
   # load common code
   sys.path.insert(0, '/afs/cern.ch/user/m/malvesga/work/ProtonRecon/TEST/CMSSW_10_6_21/src/proton_simulation_validation/settings/2018/')
   import direct_simu_reco_cff as profile
   process = cms.Process('CTPPSTest', profile.era)
   profile.LoadConfig(process)
   profile.config.SetDefaults(process)
   process.load("CalibPPS.ESProducers.ctppsBeamParametersESSource_cfi")
   process.load("Validation.CTPPS.simu_config.year_2018_cff")
   process.load("direct_simu_reco_cff")

process.load('Configuration.EventContent.EventContent_cff')

process.load("FWCore.MessageService.MessageLogger_cfi")
process.options   = cms.untracked.PSet(
      wantSummary = cms.untracked.bool(True),
      allowUnscheduled = cms.untracked.bool(True),
      )

process.MessageLogger.cerr.FwkReport.reportEvery = 500

# minimal logger settings
#process.MessageLogger = cms.Service("MessageLogger",
#  statistics = cms.untracked.vstring(),
#  destinations = cms.untracked.vstring('cerr'),
#  cerr = cms.untracked.PSet(
#    threshold = cms.untracked.string('WARNING')
#  )
#)

# number of events
process.maxEvents = cms.untracked.PSet(
      input = cms.untracked.int32(2000)
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

# override LHCInfo source
#process.load("CalibPPS.ESProducers.ctppsLHCInfoRandomXangleESSource_cfi")
#process.ctppsLHCInfoRandomXangleESSource.generateEveryNEvents = 1
#process.ctppsLHCInfoRandomXangleESSource.xangleHistogramFile = "xangle_UL2017.root"
#process.ctppsLHCInfoRandomXangleESSource.xangleHistogramObject = "xangle"
#process.ctppsLHCInfoRandomXangleESSource.beamEnergy = 6500.
#process.ctppsLHCInfoRandomXangleESSource.betaStar = 0.40

#process.esPreferLHCInfo = cms.ESPrefer("CTPPSLHCInfoRandomXangleESSource", "ctppsLHCInfoRandomXangleESSource")

# override beam-parameter source                                                                                                                       
#process.load("CalibPPS.ESProducers.ctppsBeamParametersFromLHCInfoESSource_cfi")

#process.ctppsBeamParametersFromLHCInfoESSource.beamDivX45 = process.ctppsBeamParametersESSource.beamDivX45
#process.ctppsBeamParametersFromLHCInfoESSource.beamDivX56 = process.ctppsBeamParametersESSource.beamDivX56
#process.ctppsBeamParametersFromLHCInfoESSource.beamDivY45 = process.ctppsBeamParametersESSource.beamDivY45
#process.ctppsBeamParametersFromLHCInfoESSource.beamDivY56 = process.ctppsBeamParametersESSource.beamDivY56

#process.ctppsBeamParametersFromLHCInfoESSource.vtxOffsetX45 = process.ctppsBeamParametersESSource.vtxOffsetX45
#process.ctppsBeamParametersFromLHCInfoESSource.vtxOffsetX56 = process.ctppsBeamParametersESSource.vtxOffsetX56
#process.ctppsBeamParametersFromLHCInfoESSource.vtxOffsetY45 = process.ctppsBeamParametersESSource.vtxOffsetY45
#process.ctppsBeamParametersFromLHCInfoESSource.vtxOffsetY56 = process.ctppsBeamParametersESSource.vtxOffsetY56
#process.ctppsBeamParametersFromLHCInfoESSource.vtxOffsetZ45 = process.ctppsBeamParametersESSource.vtxOffsetZ45
#process.ctppsBeamParametersFromLHCInfoESSource.vtxOffsetZ56 = process.ctppsBeamParametersESSource.vtxOffsetZ56

#process.ctppsBeamParametersFromLHCInfoESSource.vtxStddevX = process.ctppsBeamParametersESSource.vtxStddevX
#process.ctppsBeamParametersFromLHCInfoESSource.vtxStddevY = process.ctppsBeamParametersESSource.vtxStddevY
#process.ctppsBeamParametersFromLHCInfoESSource.vtxStddevZ = process.ctppsBeamParametersESSource.vtxStddevZ

# update settings of beam-smearing module                                                                                                                                                                
process.beamDivergenceVtxGenerator.src = cms.InputTag("")
process.beamDivergenceVtxGenerator.srcGenParticle = cms.VInputTag(
      #cms.InputTag("genPUProtons","genPUProtons"), 
      #cms.InputTag("genParticles")
      cms.InputTag("prunedGenParticles")
      )

# do not apply vertex smearing again                                                                         
process.ctppsBeamParametersESSource.vtxStddevX = 0
process.ctppsBeamParametersESSource.vtxStddevY = 0
process.ctppsBeamParametersESSource.vtxStddevZ = 0

# undo CMS vertex shift                                                                                      
process.ctppsBeamParametersESSource.vtxOffsetX45 = +0.024755 
process.ctppsBeamParametersESSource.vtxOffsetY45 = -0.069233
process.ctppsBeamParametersESSource.vtxOffsetZ45 = -0.82054

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

#########################
#      Preskimming      #
#########################
# declare global tag

# If using full proton re-reco (legacy) - local RP reconstruction chain with standard settings
process.load("RecoCTPPS.Configuration.recoCTPPS_cff")
process.ctppsLocalTrackLiteProducer.includePixels = cms.bool(True)
process.ctppsLocalTrackLiteProducer.includeStrips = cms.bool(True)
#process.ctppsLocalTrackLiteProducer.includeDiamonds = cms.bool(True)
process.ctppsProtons.doSingleRPReconstruction = cms.bool(True)
process.ctppsProtons.tagLocalTrackLite = cms.InputTag("ctppsLocalTrackLiteProducer","","CTPPSTest")


process.load("Configuration.StandardSequences.GeometryDB_cff") ## FIXME need to ensure that this is the good one                                     
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, "106X_dataRun2_testPPS_v1")
if year == '2017MC':
   process.GlobalTag = GlobalTag(process.GlobalTag, "106X_mc2017_realistic_v9");
if year == '2018MC':
   process.GlobalTag = GlobalTag(process.GlobalTag, "106X_upgrade2018_realistic_v16_L1v1");

process.load('Configuration.EventContent.EventContent_cff')
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("TrackingTools.TransientTrack.TransientTrackBuilder_cfi")

# event source                                                                                                                                                                                           
process.source = cms.Source("PoolSource",
      fileNames = cms.untracked.vstring(
         '/store/mc/RunIISummer20UL18MiniAOD/GGToMuMu_Pt-25_Elastic_13TeV-lpair/MINIAODSIM/106X_upgrade2018_realistic_v11_L1v1-v2/100000/052FD69E-77C0-634C-BD70-028456636387.root'
         #'/store/mc/RunIISummer20UL18MiniAODv2/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/MINIAODSIM/106X_upgrade2018_realistic_v16_L1v1-v2/120000/001C8DDF-599C-5E45-BF2C-76F887C9ADE9.root'
         #'/store/mc/RunIISummer20UL18MiniAOD/GGToEE_Pt-35_Elastic_13TeV-lpair/MINIAODSIM/106X_upgrade2018_realistic_v11_L1v1-v2/100000/14117D4C-39DE-274C-93B3-6A996779C7AC.root'
         #'/store/mc/RunIISummer20UL17MiniAODv2/GGToEE_Pt-35_Inel-El_13TeV-lpair/MINIAODSIM/106X_mc2017_realistic_v9-v2/100000/F1391FD7-9B19-2947-B529-476D36BE50FB.root'
         #'/store/mc/RunIISummer20UL17MiniAODv2/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/MINIAODSIM/106X_mc2017_realistic_v9-v2/120000/005B6A7C-B0B1-A745-879B-017FE7933B77.root'
         #'/store/mc/RunIIFall17MiniAODv2/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/MINIAODSIM/PU2017RECOSIMstep_12Apr2018_94X_mc2017_realistic_v14-v1/20000/88BE601E-6B44-E811-94D0-44A842CFD619.root' 
         )
      )

process.load("DiffractiveForwardAnalysis.GammaGammaLeptonLepton.GammaGammaLL_cfi")

process.ggll_aod.triggersList = process.hltFilter.HLTPaths
if runOnMuon: 
   process.ggll_aod.leptonsType = cms.string('Muon')
if runOnElectron: 
   process.ggll_aod.leptonsType = cms.string('Electron')
#process.ggll_aod.leptonsType = cms.string('ElectronMuon')
#process.ggll_aod.leptonsType = cms.string('Electron')
process.ggll_aod.runOnMC = cms.bool(runOnMC)
process.ggll_aod.fetchProtons = cms.bool(True)
process.ggll_aod.saveExtraTracks = cms.bool(False)
process.ggll_aod.year = cms.string(year)
if year == '2017MC':
   process.ggll_aod.mcpufile = cms.string('PUHistos_mc_2017_UL.root')
   process.ggll_aod.datapufile = cms.string('PUHistos_data_2017.root')
if year == '2018MC':
   process.ggll_aod.mcpufile = cms.string('PUHistos_mc_2018_UL.root')
   process.ggll_aod.datapufile = cms.string('PUHistos_data_2018.root')
process.ggll_aod.mcpupath = 'pileup'

process.ggll_miniaod.triggersList = process.hltFilter.HLTPaths
if runOnMuon: 
   process.ggll_miniaod.leptonsType = cms.string('Muon')
if runOnElectron: 
   process.ggll_miniaod.leptonsType = cms.string('Electron')
#process.ggll_miniaod.leptonsType = cms.string('ElectronMuon')
#process.ggll_miniaod.leptonsType = cms.string('Electron')
process.ggll_miniaod.runOnMC = cms.bool(runOnMC)
process.ggll_miniaod.fetchProtons = cms.bool(True)
process.ggll_miniaod.saveExtraTracks = cms.bool(False)
process.ggll_miniaod.year = cms.string(year)
if year == '2017MC':
   process.ggll_miniaod.mcpufile = cms.string('PUHistos_mc_2017_UL.root')
   process.ggll_miniaod.datapufile = cms.string('PUHistos_data_2017.root')
if year == '2018MC':
   process.ggll_miniaod.mcpufile = cms.string('PUHistos_mc_2018_UL.root')
   process.ggll_miniaod.datapufile = cms.string('PUHistos_data_2018.root')
process.ggll_miniaod.mcpupath = 'pileup'

# E/gamma identification
if runOnElectron:
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
      fileName = cms.string('output_MC.root'),
      closeFileFast = cms.untracked.bool(True)
      )

#https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideGenParticlePruner
process.prunedGenParticles = cms.EDProducer("GenParticlePruner",
      src = cms.InputTag("genParticles"),
      select = cms.vstring('drop *',
         # for miniAOD matching
         'keep status == 1')
      )

# processing path
if MINIAOD == False:
   process.p = cms.Path(
         process.prunedGenParticles *
         #process.dump *
         process.beamDivergenceVtxGenerator *
         process.ctppsDirectProtonSimulation *

         process.totemRPUVPatternFinder *
         process.totemRPLocalTrackFitter *
         process.ctppsPixelLocalTracks *
         process.ctppsLocalTrackLiteProducer *

         process.reco_local *
         process.ctppsProtons *

         process.hltFilter *

         process.ggll_aod
         )

else:
   process.p = cms.Path(
         #process.dump *
         process.beamDivergenceVtxGenerator *
         process.ctppsDirectProtonSimulation *

         process.totemRPUVPatternFinder *
         process.totemRPLocalTrackFitter *
         process.ctppsPixelLocalTracks *
         process.ctppsLocalTrackLiteProducer *

         process.reco_local *
         process.ctppsProtons *

         process.hltFilter *

         process.ggll_miniaod
         #process.ctppsAcceptancePlotter *
         #process.ctppsTrackDistributionPlotter
         )

process.outpath = cms.EndPath(patAlgosToolsTask)

