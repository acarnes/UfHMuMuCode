
#include "UfHMuMuCode/UFDiMuonsAnalyzer/interface/GenJetInfo.h"

void GenJetInfo::init() {

  px     = -999;
  py     = -999;
  pz     = -999;
  pt     = -999;
  eta    = -999;
  phi    = -999;
  mass   = -999;
  charge = -999;
}

void GenJetInfos::init() {

  nGenJets = 0;
  genJets.clear();

}
