#include "TuringMachine.h"

TuringMachine::TuringMachine()
{
}

TuringMachine::~TuringMachine()
{
}

std::vector<std::string> splitWords1(string str)
{
    std::string buf;                 // Have a buffer string
    std::stringstream ss(str);       // Insert the string into a stream
    std::vector<std::string> tokens; // Create vector to hold our words

    while (ss >> buf)
        tokens.push_back(buf);

    return tokens;
}

// void TuringMachine::process(TuringMachineConfig& config)
void TuringMachine::process(DataReaderInterface& reader)
{
    TuringMachineConfig config = reader.getConfig();
    while (true)
    {
    for(auto i = config.rules.begin(); i != config.rules.end(); i++)
    {
        vector<string> splittedRule = splitWords1(*i);
        int newState = stoi(splittedRule[0]);
        int readValue = stoi(splittedRule[1]);

        bool stateResult = newState == config.state;
        int readValueTape = config.tape[config.headPosition] - '0';
        bool headResult =  readValue == readValueTape;

        // if( rules[i][0].equals(state) && rules[i][1].charAt(0) == tape[headPosition]) {
        if( stateResult && headResult )
        {
            // tape[headPosition] = rules[i][2].charAt(0);
            string newTape = splittedRule[2];
            config.tape.replace(config.headPosition, 1, newTape); 

            if( splittedRule[3] == "L")
            {   // if( rules[i][3].charAt(0) == 'L') headPosition--;
                config.headPosition--;
            }
            else
            {   // else headPosition++;
                config.headPosition++;
            }
            // state = rules[i][4];
            config.state = stoi(splittedRule[4]);
            cout<< config.tape << endl;
        }
    }
    }
}
