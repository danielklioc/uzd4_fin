#pragma once
#include "ValidateArguments.h"
#include "DataReaderTxt.h"
#include "DataReaderJson.h"
#include "TuringMachine.h"

class Run
{
public :
    Run ();
    ~Run ();  

    void	start (uint argc, char** argv);
private :
  ValidateArguments valArg;
  TuringMachine tm;
};
