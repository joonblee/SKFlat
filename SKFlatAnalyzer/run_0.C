R__LOAD_LIBRARY(libPhysics.so)
R__LOAD_LIBRARY(libTree.so)
R__LOAD_LIBRARY(libHist.so)
R__LOAD_LIBRARY(./lib/libDataFormats.so)
R__LOAD_LIBRARY(/data6/Users/joonblee/SKFlatRunlog/2020_01_17_124548__336090__NIsoMuon__Year2016__TAMSA1/lib/libAnalyzerTools.so)
R__LOAD_LIBRARY(./lib/libAnalyzers.so)
R__LOAD_LIBRARY(/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/lhapdf/6.2.1-fmblme/lib/libLHAPDF.so)


void run_0(){

  NIsoMuon m;

  m.SetTreeName("recoTree/SKFlat");

  m.MaxEvent = 10000;

  m.LogEvery = 1000;
  m.IsDATA = true;
  m.DataStream = "DoubleMuon";
  m.TriggerInput = "DoubleMuon";
  m.DataYear = 2016;
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_1.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_10.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_100.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_101.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_102.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_103.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_104.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_105.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_106.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_107.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_108.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_109.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_11.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_110.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_111.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_112.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_113.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_114.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_115.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_116.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_117.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_118.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_119.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_12.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_120.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_121.root");
  m.AddFile("/data7//DATA/SKFlat/Run2Legacy_v3/2016/DATA/DoubleMuon/periodB_ver2/190420_141810/0000/SKFlatNtuple_2016_DATA_122.root");
  m.SetOutfilePath("hists.root");
  m.Init();
  m.initializeAnalyzerTools();
  m.initializeAnalyzer();
  m.SwitchToTempDir();
  m.Loop();

  m.WriteHist();

}
