#include "AnalysisSkeleton.hxx"

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <string>

int 
main(int argc, char* argv[])
{
  std::string fileName("");  
  int c;

  while ( (c = getopt(argc, argv, "I:") ) !=-1 ) {
    switch (c) {
    case 'I':
      fileName = optarg;
      break;
    default: // default block
      break;
    }  
  }
  
  if (fileName.empty()) {
    std::cout << "please specify fileName with -I" << std::endl;
    return EXIT_FAILURE;
  }
  
  TChain myChain("tree");
  if (fileName.substr(fileName.size()-4, 4)==".txt") {
    std::ifstream inputfile(fileName.c_str());
    char line[BUFSIZ];
    int counter = 0; 
    
    int iFile=0;
    while (not (inputfile.eof())) {
      if ( ((iFile+1)%1000)==0 ) { printf("%d files are loaded (UtilsOk.cxx ListOfFiles())\n", iFile); }
      inputfile.getline(line, sizeof(line));
      std::string lineStr(line);
      if (lineStr.empty()) {continue;}
      if (lineStr.substr(0, 1)=="#") {continue;}
      myChain.AddFile(lineStr.c_str());
      iFile++;
    }
    printf("%d files are loaded\n", iFile);
  } else {
    myChain.AddFile(fileName.c_str());
  }
  AnalysisSkeleton as(&myChain);
  as.Loop();
  
  return EXIT_SUCCESS;
}

