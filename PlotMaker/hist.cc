void setDataStyle(TH1D *h, int bin, int MarkerStyle, double MarkerSize , int MarkerColor);
void setMCStyle(TH1D *h, int bin, int LineColor, int FillColor, double LineWidth/*, double lumi, double xsec, double ws*/);

void hist(TString Analyzer = "NIsoMuon", TString Object = "Dilepton", TString Variable = "Mass", TString sign = "OS", TString MuonID1 = "POGTightWithTightTrkIso", TString MuonID2 = "POGTightWithVetoTightTrkIso", TString Trigger = "DoubleMuon", TString AddOption = "") {

  bool letLogX = false; bool letLogY = false;
  double YRangeMin = 0; double YRangeMax = 0;
  double XRangeMin = 0; double XRangeMax = 0;
  int bin = 1;

  double LineWidth_ = 1.0;

  bool IsMass = false;
  if( Variable.Index("Mass")!=kNPOS ) {
    IsMass = true;
    XRangeMin = 0; XRangeMax = 150;
  }
  else if( Variable.Index("Pt")!=kNPOS ) {
    XRangeMin = 0; XRangeMax = 100;
  }


  TString addr = "/data6/Users/joonblee/SKFlatOutput/Run2Legacy_v3/"+Analyzer+"/2016/"+Trigger+"/";

  TString Directory = sign+"_"+MuonID1+"_"+MuonID2;
  if( AddOption != "" )
    Directory += "_" + AddOption;
  TString ObjectVariable = Object+"_"+Variable+"___"+Directory;

  
  vector<string> AllVariables = {"Mass","DeltaR","Pt","Eta","Phi"};
  vector<int> BinSize = {20,500,5,10,10};
  for(int iVar = 0; iVar < AllVariables.size(); iVar++) {
    if( ObjectVariable.Index(AllVariables[iVar])==kNPOS ) continue;
    bin = BinSize[iVar];
    break;
  }
  
  if( IsMass ) {
    XRangeMin = 0; XRangeMax = 150; // 200;
  }

  // ---------- Call HIST ---------- //
  TFile *f0 = new TFile(addr+"DATA/"+Trigger+".root");
  TH1D *h0 = (TH1D*)f0 -> Get(Directory+"/"+ObjectVariable);


  //////////// BIN SIZE SELECTION ///////////
  setDataStyle(h0, bin, 20, .5, kBlack);

  vector<TString> MCName = {"WW_pythia","WZ_pythia","ZZ_pythia","SingleTop_tW_antitop_NoFullyHad","SingleTop_tW_top_NoFullyHad","TTLJ_powheg","TTLL_powheg","WJets_MG","DYJets10to50","DYJets"};
  vector<Color_t> MCColor = {kViolet,kViolet,kViolet,kRed,kRed,kRed+2,kRed+2,kOrange,kAzure-2,kAzure-2};


  // Irreducible Bg //
  TFile *f1 = new TFile(addr+Analyzer+"_"+MCName[0]+".root");
  TFile *f2 = new TFile(addr+Analyzer+"_"+MCName[1]+".root");
  TFile *f3 = new TFile(addr+Analyzer+"_"+MCName[2]+".root");
  TFile *f4 = new TFile(addr+Analyzer+"_"+MCName[3]+".root");
  TFile *f5 = new TFile(addr+Analyzer+"_"+MCName[4]+".root");
  TFile *f6 = new TFile(addr+Analyzer+"_"+MCName[5]+".root");
  TFile *f7 = new TFile(addr+Analyzer+"_"+MCName[6]+".root");
  TFile *f8 = new TFile(addr+Analyzer+"_"+MCName[7]+".root");
  TFile *f9 = new TFile(addr+Analyzer+"_"+MCName[8]+".root");
  TFile *f10 = new TFile(addr+Analyzer+"_"+MCName[9]+".root");

  /*
  f1->cd(Directory); TH1D *h1 = (TH1D*)gDirectory->Get( ObjectVariable );
  f2->cd(Directory); TH1D *h2 = (TH1D*)gDirectory->Get( ObjectVariable );
  f3->cd(Directory); TH1D *h3 = (TH1D*)gDirectory->Get( ObjectVariable );
  f4->cd(Directory); TH1D *h4 = (TH1D*)gDirectory->Get( ObjectVariable );
  f5->cd(Directory); TH1D *h5 = (TH1D*)gDirectory->Get( ObjectVariable );
  f6->cd(Directory); TH1D *h6 = (TH1D*)gDirectory->Get( ObjectVariable );
  f7->cd(Directory); TH1D *h7 = (TH1D*)gDirectory->Get( ObjectVariable );
  f8->cd(Directory); TH1D *h8 = (TH1D*)gDirectory->Get( ObjectVariable );
  f9->cd(Directory); TH1D *h9 = (TH1D*)gDirectory->Get( ObjectVariable );
  f10->cd(Directory); TH1D *h10 = (TH1D*)gDirectory->Get( ObjectVariable );
  */



  TH1D *h1 = (TH1D*)f1 -> Get(Directory+"/"+ObjectVariable); // gg
  setMCStyle(h1, bin, MCColor[0], MCColor[0], LineWidth_);

  TH1D *h2 = (TH1D*)f2 -> Get(Directory+"/"+ObjectVariable); // qq
  setMCStyle(h2, bin, MCColor[1], MCColor[1], LineWidth_);

  TH1D *h3 = (TH1D*)f3 -> Get(Directory+"/"+ObjectVariable);
  setMCStyle(h3, bin, MCColor[2], MCColor[2], LineWidth_);

  TH1D *h4 = (TH1D*)f4 -> Get(Directory+"/"+ObjectVariable);
  setMCStyle(h4, bin, MCColor[3], MCColor[3], LineWidth_);

  TH1D *h5 = (TH1D*)f5 -> Get(Directory+"/"+ObjectVariable); // higgs
  setMCStyle(h5, bin, MCColor[4], MCColor[4], LineWidth_);

  TH1D *h6 = (TH1D*)f6 -> Get(Directory+"/"+ObjectVariable); // WWZ
  setMCStyle(h6, bin, MCColor[5], MCColor[5], LineWidth_);

  TH1D *h7 = (TH1D*)f7 -> Get(Directory+"/"+ObjectVariable);
  setMCStyle(h7, bin, MCColor[6], MCColor[6], LineWidth_);

  TH1D *h8 = (TH1D*)f8 -> Get(Directory+"/"+ObjectVariable);
  setMCStyle(h8, bin, MCColor[7], MCColor[7], LineWidth_);

  TH1D *h9 = (TH1D*)f9 -> Get(Directory+"/"+ObjectVariable); // ttZ
  setMCStyle(h9, bin, MCColor[8], MCColor[8], LineWidth_);

  TH1D *h10 = (TH1D*)f10 -> Get(Directory+"/"+ObjectVariable); // WZ
  setMCStyle(h10, bin, MCColor[9], MCColor[9], LineWidth_);



//  h0->Sumw2(); h1->Sumw2(); h2->Sumw2(); h3->Sumw2(); h4->Sumw2(); h5->Sumw2(); h6->Sumw2(); h7->Sumw2(); h8->Sumw2(); h9->Sumw2(); h10->Sumw2(); //h11->Sumw2(); 


  THStack *hs = new THStack("hs","");
  hs->Add(h1); hs->Add(h2); hs->Add(h3); hs->Add(h4); hs->Add(h5); hs->Add(h6); hs->Add(h7); hs->Add(h8); hs->Add(h9); hs->Add(h10);

  TH1D *h_mc = (TH1D*)h1->Clone("h_mc");
  h_mc->Add(h1); h_mc->Add(h2); h_mc->Add(h3); h_mc->Add(h4); h_mc->Add(h5); h_mc->Add(h6); h_mc->Add(h7); h_mc->Add(h8); h_mc->Add(h9); h_mc->Add(h10);
  //h_mc->Sumw2();


  double BinLowEdge;
  vector<double> BinContents_ZPeak, BinContents_VetoZPeak;
  if( IsMass ) {
    for(int i=0; i<h0->GetNbinsX(); i++) {
      BinLowEdge = ((TAxis*)h0->GetXaxis())->GetBinLowEdge(i);
      if( BinLowEdge < 60 || BinLowEdge > 120 ) 
        BinContents_VetoZPeak.push_back( h0->GetBinContent(i) );
      else
        BinContents_ZPeak.push_back( h0->GetBinContent(i) );
    }

    if( *max_element(BinContents_VetoZPeak.begin(),BinContents_VetoZPeak.end())
    > *max_element(BinContents_ZPeak.begin(),BinContents_ZPeak.end()) * 5 
    || *max_element(BinContents_VetoZPeak.begin(),BinContents_VetoZPeak.end()) * 5
    < *max_element(BinContents_ZPeak.begin(),BinContents_ZPeak.end())
    ) {
      letLogY = true;
    }
  }

  double multiplier = 1.05;
  if( letLogY ) {
    multiplier = 3.0;
    YRangeMin = 0.1;
  }
  // YRangeMax = *max_element(v.begin(),v.end()) * multiplier;
  YRangeMax = max(
    h0->GetBinContent(h0->GetMaximumBin()),
    h_mc->GetBinContent(h_mc->GetMaximumBin())
  )
  * multiplier;

  if(XRangeMax == 0) {
    XRangeMin = h0->GetXaxis()->GetXmin();
    XRangeMax = h0->GetXaxis()->GetXmax();
  }

  h0 -> GetXaxis()->SetRangeUser(XRangeMin,XRangeMax);
  if(YRangeMax!=0) h0 -> GetYaxis()->SetRangeUser(YRangeMin,YRangeMax);
  if( letLogX )
    h0->GetXaxis()->SetMoreLogLabels();
  if( letLogY ) {
    h0->GetYaxis()->SetMoreLogLabels();
    h0->GetYaxis()->SetNoExponent();
  }




  TCanvas *c1 = new TCanvas("c1","histogram",1000,1000);
  //c1->SetBottomMargin(0.2);
  c1->cd();

  auto pad1 = new TPad("pad1","",0,0.26,1,1,0);
  pad1->SetLeftMargin(0.1);
  //pad1->SetBottomMargin(0.3);
  if(letLogX) pad1 -> SetLogx();
  if(letLogY) pad1 -> SetLogy();
  pad1->Draw();

  auto pad2 = new TPad("pad2","",0,0,1,0.33,0);
  pad2->SetLeftMargin(0.1);
  pad2->SetBottomMargin(0.3);
  if(letLogX) pad2->SetLogx();
  pad2->Draw();

  /////////////////////////////////////////////////////////////////////////////
  pad1->cd();


  h0 -> Draw("P");
  hs -> Draw("HIST SAME");
  h0 -> SetStats(0);
  h0 -> Draw("E1 P SAME");

  pad1->SetGridx(); pad1->SetGridy();

  TString xTitle = "";

  if( Variable.Index("Mass")!=kNPOS ) {
    xTitle += "M(#mu";
    if( sign.Index("OS")!=kNPOS ) 
      xTitle += "^{+},#mu^{-})";
    else
      xTitle += "^{#pm},#mu^{#pm})";
    xTitle += " [GeV]";
  }
  else if( Variable.Index("DeltaR")!=kNPOS ) {
    xTitle += "#DeltaR(#mu";
    if( sign.Index("OS")!=kNPOS ) 
      xTitle += "^{+},#mu^{-})";
    else
      xTitle += "^{#pm},#mu^{#pm})";
  }
  else if( Variable.Index("Pt")!=kNPOS ) {
    xTitle += "pT(";
    if( Object.Index("0")!=kNPOS )
      xTitle += "#mu_{Leading})";
    else
      xTitle += "#mu_{Subleading})";
    xTitle += " [GeV]";
  }
  else if( Variable.Index("Eta")!=kNPOS ) {
    xTitle += "#eta(";
    if( Object.Index("0")!=kNPOS )
      xTitle += "#mu_{Leading})";
    else
      xTitle += "#mu_{Subleading})";
  }
  else if( Variable.Index("Phi")!=kNPOS ) {
    xTitle += "#phi(";
    if( Object.Index("0")!=kNPOS )
      xTitle += "#mu_{Leading})";
    else
      xTitle += "#mu_{Subleading})";
  }


  TString yTitle = "Events";
  if(letLogY) yTitle = "Events (log)";

  h0 -> GetYaxis()->SetTitle(yTitle);
  h0 -> GetYaxis()->SetTitleSize(0.045);
  h0 -> GetYaxis()->SetLabelSize(0.040);
  h0 -> GetYaxis()->SetTitleOffset(1.0);

  h0 -> GetXaxis()->SetTitle(xTitle);
  h0 -> GetXaxis()->SetTitleSize(0);
  h0 -> GetXaxis()->SetTitleOffset(0.7);
  h0 -> GetXaxis()->SetLabelSize(0.025);

MCName = {"WW_pythia","WZ_pythia","ZZ_pythia","SingleTop_tW_antitop_NoFullyHad","SingleTop_tW_top_NoFullyHad","TTLJ_powheg","TTLL_powheg","WJets_MG","DYJets10to50","DYJets"};

  if( Variable.Index("Phi") == kNPOS ) {
  TLegend* leg;
  leg = new TLegend(0.75,0.65,0.99,0.90);
  leg -> AddEntry(h0,"DATA","lep");
  leg -> AddEntry(h9,"DYJets","f");
  leg -> AddEntry(h8,"WJets","f");
  leg -> AddEntry(h6,"tt","f");
  leg -> AddEntry(h4,"tW","f");
  leg -> AddEntry(h1,"VV","f");
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);

  leg -> Draw();
  }

  TLatex *tex = new TLatex(0.6,0.92,"#font[60]{35.9 fb^{-1} (13 TeV)}"); //"#font[60]{CMS Preliminary            35.9 fb^{-1} (13 TeV)}");
  tex->SetNDC();
  tex->SetLineWidth(2);
  tex->Draw();

  gPad->RedrawAxis();

  ////////////////////////////////////////////////////////////////////////
  pad2->cd();

  TH1D *h_ratio = (TH1D*)h0->Clone("h_ratio");
  h_ratio->Sumw2();

  h_ratio->GetYaxis()->SetRangeUser(0.0,2.0);
  h_ratio->GetXaxis()->SetRangeUser(XRangeMin,XRangeMax);
  h_ratio->Divide(h_mc);

  h_ratio->GetXaxis()->SetTitle(xTitle); //"M_{4#mu} [GeV]");
  h_ratio->GetXaxis()->SetTitleOffset(1.1);
  h_ratio->GetXaxis()->SetTitleSize(0.1);
  h_ratio->GetXaxis()->SetLabelSize(0.09);
  h_ratio->GetXaxis()->SetLabelOffset(0.01);

  h_ratio->GetYaxis()->SetTitle("Data / MC");
  h_ratio->GetYaxis()->SetTitleSize(0.095);
  h_ratio->GetYaxis()->SetTitleOffset(0.40);
  h_ratio->GetYaxis()->SetLabelSize(0.075);

  h_ratio->SetStats(0);
  h_ratio->Draw("P");

  pad2->SetGridx(); pad2->SetGridy();

  TF1 *hline = new TF1("","1",XRangeMin,XRangeMax);
  hline->SetLineColor(kRed);
  hline->Draw("SAME");

  TString logTag = "";
  if( letLogY ) logTag = "_logY";

  c1->SaveAs(ObjectVariable+".png");
  // c1->SaveAs(ObjectVariable+".pdf");
  cout<<"end"<<endl;

}

void setDataStyle(TH1D *h, int bin, int MarkerStyle, double MarkerSize , int MarkerColor) {
  h->Rebin(bin);

  h->SetMarkerStyle(MarkerStyle);
  h->SetMarkerSize(MarkerSize);
  h->SetLineColor(MarkerColor);
  h->SetStats(0);
}


void setMCStyle(TH1D *h, int bin, int LineColor, int FillColor, double LineWidth/*, double lumi, double xsec, double ws*/) {
  h->Rebin(bin);

  h->SetLineColor(LineColor);
  h->SetFillColor(FillColor);
  h->SetLineWidth(LineWidth);
  // h->Scale(lumi*xsec/ws);
}
