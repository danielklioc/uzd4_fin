#pragma once 
#include "utilitis.h"

class TuringMachineConfig
{
public:
    int headPosition;
    string tape;
    int state = 0;
    vector<string> rules;
};