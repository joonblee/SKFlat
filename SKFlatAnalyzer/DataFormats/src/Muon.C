#include "Muon.h"

ClassImp(Muon)

Muon::Muon() : Lepton() {
  j_chi2 = 999.;
  j_PFCH04 = -999.;
  j_PFNH04 = -999.;
  j_PFPH04 = -999.;
  j_PU04 = -999.;
  j_trkiso = -999.;
  this->SetLeptonFlavour(MUON);
  j_MiniAODPt = -999.;
  j_MomentumScaleUp = -999.;
  j_MomentumScaleDown = -999.;
  j_TunePPtError = -999.;
  j_trackerLayers = 0;
}

Muon::~Muon(){
}

void Muon::SetTypeBit(unsigned int typebit){
  j_TypeBit = typebit;
}

void Muon::SetIDBit(unsigned int idbit){
  j_IDBit = idbit;
}

void Muon::SetisPOGHighPt(bool b){
  j_isPOGHighPt = b;
}

void Muon::SetIso(double ch04, double nh04, double ph04, double pu04, double trkiso){
  j_PFCH04 = ch04;
  j_PFNH04 = nh04;
  j_PFPH04 = ph04;
  j_PU04 = pu04;
  j_trkiso = trkiso;
  CalcPFRelIso();
}

void Muon::SetChi2(double chi2){
  j_chi2 = chi2;
}

void Muon::CalcPFRelIso(){
  double absiso = j_PFCH04+std::max( 0., j_PFNH04 + j_PFPH04 - 0.5*j_PU04 );
  //cout << "[Muon::CalcPFRelIso] j_PFCH04 = " << j_PFCH04 << endl;
  //cout << "[Muon::CalcPFRelIso] j_PFNH04 = " << j_PFNH04 << endl;
  //cout << "[Muon::CalcPFRelIso] j_PFPH04 = " << j_PFPH04 << endl;
  //cout << "[Muon::CalcPFRelIso] j_PU04 = " << j_PU04 << endl;
  //cout << "[Muon::CalcPFRelIso] --> absiso = " << absiso << endl;
  this->SetRelIso(absiso/this->Pt());
  //this->SetRelIso(absiso/this->MiniAODPt()); //TODO This is same as IDBit
}

double Muon::EA(){

  double eta = fabs(this->Eta());

  if     (eta<0.8000) return 0.0566;
  else if(eta<1.3000) return 0.0562;
  else if(eta<2.0000) return 0.0363;
  else if(eta<2.2000) return 0.0119;
  else if(eta<2.4000) return 0.0064;
  else return 0.0064;

}

void Muon::SetMiniAODPt(double d){
  j_MiniAODPt = d;
}
void Muon::SetMiniAODTunePPt(double d){
  j_MiniAODTunePPt = d;
}

void Muon::SetMomentumScaleUpDown(double pt_up, double pt_down){
  j_MomentumScaleUp = pt_up;
  j_MomentumScaleDown = pt_down;
}

void Muon::SetTuneP4(double pt, double pt_err, double eta, double phi, double q){
  j_TuneP4.SetPtEtaPhiM(pt,eta,phi,M());
  j_TuneP4.SetCharge(q);
  j_TunePPtError = pt_err;
}

// --- My Variables --- //
void Muon::SetInner(double pt, double eta, double phi){
  j_Inner.SetPtEtaPhiM(pt,eta,phi,M());
}

void Muon::SetOuter(double pt, double eta, double phi){
  j_Outer.SetPtEtaPhiM(pt,eta,phi,M());
}

void Muon::SetBest(double pt, double eta, double phi){
  j_Best.SetPtEtaPhiM(pt,eta,phi,M());
}

void Muon::SetGLB(double pt, double eta, double phi){
  j_GLB.SetPtEtaPhiM(pt,eta,phi,M());
}
// -------------------- //

bool Muon::PassID(TString ID) const {
  //==== POG
  if(ID=="POGTight") return isPOGTight();
  else if(ID=="POGHighPt") return isPOGHighPt();
  else if(ID=="POGMedium") return isPOGMedium();
  else if(ID=="POGLoose") return isPOGLoose();
  else if(ID=="POGTightWithTightIso") return Pass_POGTightWithTightIso();
  else if(ID=="POGTightWithTightTrkIso") return Pass_POGTightWithTightTrkIso();
  else if(ID=="POGTightWithVetoTightTrkIso") return Pass_POGTightWithVetoTightTrkIso();
  else if(ID=="POGTightWithVetoLooseTrkIso") return Pass_POGTightWithVetoLooseTrkIso();
  else if(ID=="POGHighPtWithLooseTrkIso") return Pass_POGHighPtWithLooseTrkIso();
  else if(ID=="isGlobalMuon") return isGlobalMuon();
  else if(ID=="isTrackerMuon") return isTrackerMuon();
  else if(ID=="isPFMuon") return isPFMuon();
  else if(ID=="NoID") return true;

  //==== Customized
  else if(ID=="TEST") return Pass_TESTID();

  cout << "[Electron::PassID] No id : " << ID << endl;
  exit(EXIT_FAILURE);

  return false;

}
bool Muon::Pass_POGTightWithTightIso() const {
  if( isPOGTight() && RelIso() < 0.15 ) return true;
  return false;
}
bool Muon::Pass_POGTightWithTightTrkIso() const {
  if( isPOGTight() && TrkIso()/TuneP4().Pt() < 0.05 ) return true;
  return false;
}
bool Muon::Pass_POGTightWithVetoTightTrkIso() const {
  if( isPOGTight() && TrkIso()/TuneP4().Pt() > 0.05 ) return true;
  return false;
}
bool Muon::Pass_POGTightWithVetoLooseTrkIso() const {
  if( isPOGTight() && TrkIso()/TuneP4().Pt() > 0.1 ) return true;
  return false;
}
bool Muon::Pass_POGHighPtWithLooseTrkIso() const {
  if( isPOGHighPt() && TrkIso()/TuneP4().Pt() < 0.1 ) return true;
  return false;
}

//==== TEST ID

bool Muon::Pass_TESTID() const {
  return true;
}

void Muon::SetTrackerLayers(int n){
  j_trackerLayers = n;
}
