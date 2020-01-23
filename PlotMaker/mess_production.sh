#hist(TString Analyzer = "NIsoMuon", TString Object = "Dilepton", TString Variable = "Mass", TString sign = "OS", TString MuonID1 = "POGTightWithTightTrkIso", TString MuonID2 = "POGTightWithVetoTightTrkIso")

Analyzers=('"NIsoMuon"' )
#Triggers=('"DoubleMuon"' '"SingleMuon"')
Triggers=('"DoubleMuon"')

Objects=('"Dilepton"' '"Lepton_0"' '"Lepton_1"')
Signs=('"OS"' '"SS"')
MuonID1s=('"POGTightWithTightTrkIso"' '"POGTight"' '"POGTightWithVetoTightTrkIso"')
MuonID2s=('"POGTightWithTightTrkIso"' '"POGTight"' '"POGTightWithVetoTightTrkIso"')
#MuonID1s=('"POGTightWithTightTrkIso"' '"POGTight"' '"POGTightWithVetoTightTrkIso"' '"POGTightWithVetoLooseTrkIso"')
#MuonID2s=('"POGTightWithTightTrkIso"' '"POGTight"' '"POGTightWithVetoTightTrkIso"' '"POGTightWithVetoLooseTrkIso"')

#AddOptions=('""' '"1jet"' '"2jet"' '"3jet"' '"4jet"')
AddOptions=('"1jet"' '"2jet"' '"3jet"' '"4jet"')

Variables=()

#Objects=('"Dilepton"')
#Signs=('"OS"')
#MuonID1s=('"POGTightWithTightTrkIso"')
#MuonID2s=('"POGTightWithTightTrkIso"')


for Analyzer in ${Analyzers[@]}
do
  for Trigger in ${Triggers[@]}
  do
    for Object in ${Objects[@]}
    do

      if [ $Object = '"Dilepton"' ]
      then
        Variables=('"Mass"' '"DeltaR"')
      #elif (( $Object == "Lepton_0" ))
      #then
      else
        Variables=('"Pt"' '"Eta"' '"Phi"')
      fi

      for Sign in ${Signs[@]}
      do
        for MuonID1 in ${MuonID1s[@]}
        do
          for MuonID2 in ${MuonID2s[@]}
          do
            for Variable in ${Variables[@]}
            do
              for AddOption in ${AddOptions[@]}
              do

                echo ""
                echo " + - + - + - + - + Make new plot + - + - + - + - + "
                echo "   Analyzer : " $Analyzer
                echo "   Trigger  : " $Trigger
                echo "   Object   : " $Object
                echo "   Sign     : " $Sign
                echo "   Muon ID  : " $MuonID1 " , " $MuonID2
                echo "   Variable : " ${Variable}
                echo "   Option   : " $AddOption
                echo ""
                root -l -b -q "hist.cc(${Analyzer},${Object},${Variable},${Sign},${MuonID1},${MuonID2},${Trigger},${AddOption})" 
                echo " + --------------------------------------------- + "
              done
            done
          done
        done
      done
    done
  done
done


rm *POGTightWithVetoLooseTrkIso_POGTight.png
rm *POGTightWithVetoLooseTrkIso_POGTightWithVetoLooseTrkIso*
rm *POGTightWithVetoLooseTrkIso_POGTightWithVetoTightTrkIso*
rm *POGTightWithVetoTightTrkIso_POGTight.png
rm *POGTightWithVetoTightTrkIso_POGTightWithVetoLooseTrkIso*
rm *POGTightWithVetoTightTrkIso_POGTightWithVetoTightTrkIso*
rm *POGTight_POGTightWithTightTrkIso*

