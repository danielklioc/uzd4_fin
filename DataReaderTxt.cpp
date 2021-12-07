#include "DataReaderTxt.h"
#include "DataReaderJson.h"

DataReaderTxt::DataReaderTxt():
    headPosition(),
    tape(),
    state(0),
    rules(),
    fileContent()    
{
}

DataReaderTxt::~DataReaderTxt()
{
}

TuringMachineConfig DataReaderTxt::getConfig() 
{
    TuringMachineConfig config;

    config.headPosition = headPosition;
    config.tape = tape;
    config.rules = rules;

    return config;
}

void DataReaderTxt::readMachineConfig(string argv)
{
    openFile(argv);
    parseConfigData( fileContent );
}

void DataReaderTxt::parseConfigData(vector<string> lines)
{
    headPosition = stoi(lines.at(0));
    tape = lines.at(1);
    lines.erase(lines.begin());
    lines.erase(lines.begin());
    rules = lines;
}

void DataReaderTxt::openFile(const string& file_name)
{
    string new_value;
    vector<string> file_contents;

    string line;
    ifstream file(file_name, ios::in);
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            new_value = line ;
            file_contents.push_back(new_value);
        }
        file.close();
    }
    else cout << "Unable to open file"; 

    fileContent =  file_contents;
}
