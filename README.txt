You must execute 1~3 at the workspace where ATLAS library is available.

1 -  how to download RAW data
   $eos cp ${filepath} FileName.data
   
2 -  how to decompress RAW data
   $source /afs/cern.ch/atlas/project/tdaq/cmake/cmake_tdaq/bin/cm_setup.sh tdaq-07-01-00 x86_64-slc6-gcc62-opt
   $eformat-decompress.py FileName.data DecompressedFileName.data
   
3 -  how to decode
   $source $ATLAS_LOCAL_ROOT_BASE/user/atlasLocalSetup.sh
   $lsetup root	
   $make
   $./decoder -I InputFileName.data -b -O OutputFileName.root

   You can do these prosedures by shell script "All_data17_13TeV.sh"
   $sh All_data17_13TeV.sh 00341123(RunNumber) 100(lbNumber) 1(SFONumber)

4 -  how to read and make plots using the code prepared in the list (1)
   $make
   $./RunAnalysis -I InputFileName.root
   
   You derive 4 pdf files.
