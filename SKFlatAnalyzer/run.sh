make clean
make

Analyzer="NIsoMuon"
#Trigger="DoubleMuon"
Trigger="DoubleMuon"
Year=2016
nBatch=2
SkimTree="NIsoMuon"

### SKFlat.py -a $1 -i DoubleMuon -t DoubleMuon -y 2016 -n 20 &>submit_DT.log&
SKFlat.py -a $Analyzer -l MCsamples.txt -t $Trigger -y $Year -n $nBatch &>submit_MC.log&

sleep 60

SKFlat.py -a $Analyzer -t $Trigger -y $Year -n $nBatch &>submit_DT.log&




#SKFlat.py -a SkimTree_NIsoMuon -l samples.txt -n 0 -y 2016 --nmax 100 &>submit_skim.log&



#sleep 60

#echo ""
#echo "### ----- Job submitted ----- ###"
#echo ""

