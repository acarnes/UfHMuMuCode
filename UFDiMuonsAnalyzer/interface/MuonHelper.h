
#ifndef MUON_HELPER
#define MUON_HELPER

#include "UfHMuMuCode/UFDiMuonsAnalyzer/interface/CommonIncludes.h"
#include "UfHMuMuCode/UFDiMuonsAnalyzer/interface/MuonInfo.h"
#include "UfHMuMuCode/UFDiMuonsAnalyzer/interface/PtCorrKalman.h"
#include "UfHMuMuCode/UFDiMuonsAnalyzer/interface/PtCorrRoch.h"

void FillMuonInfos( MuonInfos& _muonInfos, 
		    const pat::MuonCollection muonsSelected,
		    const reco::Vertex primaryVertex, const int _nPV,
		    const edm::Handle<reco::BeamSpot>& beamSpotHandle,
		    const edm::Event& iEvent, const edm::EventSetup& iSetup,
		    const edm::Handle<pat::TriggerObjectStandAloneCollection>& _trigObjsHandle,
		    const edm::Handle<edm::TriggerResults>& _trigResultsHandle,
		    const std::vector<std::string> _trigNames, const double _muon_trig_dR,
		    const bool _muon_use_pfIso, const double _muon_iso_dR, const bool _isData,
		    KalmanMuonCalibrator& _KaMu_calib, const bool _doSys_KaMu,
		    rochcor2016* _Roch_calib[201], const bool _doSys_Roch );

pat::MuonCollection SelectMuons( const edm::Handle<pat::MuonCollection>& muons,
				 const reco::Vertex primaryVertex, const std::string _muon_ID,
				 const double _muon_pT_min, const double _muon_eta_max, const double _muon_trig_dR,
				 const bool _muon_use_pfIso, const double _muon_iso_dR, const double _muon_iso_max );

bool MuonIsLoose ( const pat::Muon muon );
bool MuonIsMedium( const pat::Muon muon );
bool MuonIsTight ( const pat::Muon muon, const reco::Vertex primaryVertex );

double MuonCalcRelIsoPF ( const pat::Muon muon, const double _muon_iso_dR );
double MuonCalcRelIsoTrk( const pat::Muon muon, const double _muon_iso_dR );
double MuonCalcTrigEff  ( const pat::Muon muon, const int _nPV, const std::string _trigName );

bool IsHltMatched( const pat::Muon& mu, const edm::Event& iEvent, const edm::EventSetup& iSetup,
		   const edm::Handle<pat::TriggerObjectStandAloneCollection>& _trigObjsHandle,
		   const edm::Handle<edm::TriggerResults>& _trigResultsHandle,
		   const std::string _desiredTrigName, const double _muon_trig_dR );

void CalcTrigEff( float& _muon_eff, float& _muon_eff_up, float& _muon_eff_down,
		  const TH2F* _muon_eff_hist, const MuonInfos _muonInfos, const bool EMTF_bug );

#endif  // #ifndef MUON_HELPER                                                                                                                  