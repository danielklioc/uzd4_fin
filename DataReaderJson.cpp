#include "DataReaderJson.h"

using json = nlohmann::json;

DataReaderJson::DataReaderJson():
    headPosition(),
    tape(),
    state(0),
    rules(),
    fileContent()    
{
}

DataReaderJson::~DataReaderJson()
{
}

TuringMachineConfig DataReaderJson::getConfig() 
{
    TuringMachineConfig config;

    config.headPosition = headPosition;
    config.tape = tape;
    config.rules = rules;

    return config;
}

void DataReaderJson::readMachineConfig(string argv)
{
    openFile(argv);
    parseConfigData( fileContent );
}

void DataReaderJson::parseConfigData(vector<string> lines)
{
    headPosition = stoi(lines.at(0));
    tape = lines.at(1);
    lines.erase(lines.begin());
    lines.erase(lines.begin());
    rules = lines;
}

void DataReaderJson::openFile(const string& file_name)
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
