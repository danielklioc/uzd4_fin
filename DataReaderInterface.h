#pragma once
#include "utilitis.h"
#include "TuringMachineConfig.h"

class DataReaderInterface
{
public:

    virtual void readMachineConfig(string argv) = 0;
    virtual TuringMachineConfig getConfig() = 0;
private:
    // void parseConfigData(vector<string> lines);
    // // vector<string> openFile(const string& file_name);
    // void openFile(const string& file_name);

    // void processMachine();
    // std::vector<std::string> splitWords(string str);

    // int headPosition;
    // string tape;
    // int state;
    // vector<string> rules;
    // vector<string> fileContent;
};