import FWCore.ParameterSet.Config as cms

from Configuration.Eras.Modifier_ctpps_2016_cff import ctpps_2016
process = cms.Process('CTPPSTestAcceptance', ctpps_2016)

# load common code
process.load("direct_simu_reco_cff")
from customisation_cff import *
SetDefaults(process)

# minimal logger settings
process.MessageLogger = cms.Service("MessageLogger",
  statistics = cms.untracked.vstring(),
  destinations = cms.untracked.vstring('cerr'),
  cerr = cms.untracked.PSet(
    threshold = cms.untracked.string('WARNING')
  )
)

# event source
process.source = cms.Source("PoolSource",
  fileNames = cms.untracked.vstring("file:/afs/cern.ch/user/m/malvesga/work/ProtonRecon/archives/10_6_0/input/2017/MC/LPAIRmumuElastic_Fall17/GGToMuMu_Pt-50_Inel-El_13TeV-lpairAODSIM92X.root")
)

# number of events
process.maxEvents = cms.untracked.PSet(
  input = cms.untracked.int32(-1)
)

# update settings of beam-smearing module
process.beamDivergenceVtxGenerator.src = cms.InputTag("")
process.beamDivergenceVtxGenerator.srcGenParticle = cms.VInputTag(
  cms.InputTag("genPUProtons", "genPUProtons"),
  cms.InputTag("prunedGenParticles")
)

# do not apply vertex smearing again
process.ctppsBeamParametersESSource.vtxStddevX = 0
process.ctppsBeamParametersESSource.vtxStddevY = 0
process.ctppsBeamParametersESSource.vtxStddevZ = 0

# undo CMS vertex shift
process.ctppsBeamParametersESSource.vtxOffsetX45 = +0.2475 * 1E-1
process.ctppsBeamParametersESSource.vtxOffsetY45 = -0.6924 * 1E-1
process.ctppsBeamParametersESSource.vtxOffsetZ45 = -8.1100 * 1E-1

# HepMC plotter
process.ctppsHepMCDistributionPlotter = cms.EDAnalyzer("CTPPSHepMCDistributionPlotter",
  tagHepMC = cms.InputTag("beamDivergenceVtxGenerator"),
  lhcInfoLabel = cms.string(""),
  outputFile = cms.string("/afs/cern.ch/user/m/malvesga/work/ProtonRecon/archives/10_6_0/output/2017/MC/LPAIRmumuElastic_Fall17/output_HepMC.root")
)

# XY distribution plotter
process.ctppsTrackDistributionPlotter = cms.EDAnalyzer("CTPPSTrackDistributionPlotter",
  tagTracks = cms.InputTag("ctppsLocalTrackLiteProducer"),
  outputFile = cms.string("/afs/cern.ch/user/m/malvesga/work/ProtonRecon/archives/10_6_0/output/2017/MC/LPAIRmumuElastic_Fall17/output_track_xy.root")
)

process.dump = cms.EDAnalyzer("EventContentAnalyzer")

#https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideGenParticlePruner
process.prunedGenParticles = cms.EDProducer(
"GenParticlePruner",
src = cms.InputTag("genParticles"),
select = cms.vstring('drop *',
# for miniAOD matching
'keep status == 1')
)

# processing path
process.p = cms.Path(
process.prunedGenParticles *
#process.dump *
process.beamDivergenceVtxGenerator *
process.ctppsDirectProtonSimulation *

process.reco_local *

process.ctppsHepMCDistributionPlotter *
process.ctppsTrackDistributionPlotter
)



