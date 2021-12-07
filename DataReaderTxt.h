#pragma once
#include "utilitis.h"
#include "DataReaderInterface.h"
#include "TuringMachineConfig.h"

class DataReaderTxt: public DataReaderInterface
{
public:
    DataReaderTxt();
    ~DataReaderTxt();

    void readMachineConfig(string argv) override;
    TuringMachineConfig getConfig() override;
private:
    void parseConfigData(vector<string> lines);
    void openFile(const string& file_name);

    int headPosition;
    string tape;
    int state;
    vector<string> rules;
    vector<string> fileContent;
};