#pragma once
#include "utilitis.h"
#include "TuringMachineConfig.h"
#include "DataReaderInterface.h"

class TuringMachine
{
public:
    TuringMachine();
    ~TuringMachine();

    void process(DataReaderInterface& reader);

    // Configuration tmconfig;
private:
};
