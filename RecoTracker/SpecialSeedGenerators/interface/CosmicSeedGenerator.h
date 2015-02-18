#ifndef CosmicSeedGenerator_h
#define CosmicSeedGenerator_h

//
// Package:         RecoTracker/GlobalPixelSeedGenerator
// Class:           GlobalPixelSeedGenerator
// 
// Description:     Calls RoadSeachSeedFinderAlgorithm
//                  to find TrackingSeeds.


#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/EventSetup.h"


#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "RecoTracker/SpecialSeedGenerators/interface/SeedGeneratorForCosmics.h"
#include "RecoTracker/SpecialSeedGenerators/interface/ClusterChecker.h"


class CosmicSeedGenerator : public edm::stream::EDProducer<>
{
 public:

  explicit CosmicSeedGenerator(const edm::ParameterSet& conf);

  virtual ~CosmicSeedGenerator();

  virtual void produce(edm::Event& e, const edm::EventSetup& c) override;

 private:
  edm::ParameterSet conf_;
  SeedGeneratorForCosmics  cosmic_seed;
  ClusterChecker check;
  // get Inputs
  edm::EDGetTokenT<SiStripMatchedRecHit2DCollection> matchedrecHitsToken_;
  edm::EDGetTokenT<SiStripRecHit2DCollection> rphirecHitsToken_;
  edm::EDGetTokenT<SiStripRecHit2DCollection> stereorecHitsToken_;


};

#endif
