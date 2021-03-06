#ifndef NIsoMuon_h
#define NIsoMuon_h

#include "AnalyzerCore.h"

class NIsoMuon : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  std::vector<Lepton*> NIsoMuonSelection(vector<Muon>& muons, vector<Muon>& Vmuons, int sgn);
  double MCweight(Event ev);
  void executeEvent();

  vector<TString> MuonIDs, NIsoMuonIDs;
  TString  MuonIDSFKey, MuonISOSFKey;

  TString JetID;

  vector<TString> IsoMuTriggerName;
  double TriggerSafePtCut;

  vector<Muon> AllMuons;
  vector<Jet> AllJets;

  double weight_Prefire;


  NIsoMuon();
  ~NIsoMuon();

};



#endif

