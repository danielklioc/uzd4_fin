#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

int headPosition;
string tape;
int state = 0;
vector<string> rules;

vector<string> open_file(const string& file_name);
void readMachineConfig(string argv);
int parseConfigData(vector<string> lines);
void processMachine();


vector<string> open_file(const string& file_name)
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

    return file_contents;
}

void readMachineConfig(string argv)
{
    parseConfigData( open_file(argv) );
    // tm.process();

    if( !rules.empty() )
    {
        while (true)
        // for (int i = 0; i < 10; i++)
        {
            processMachine();
        }
    }
}

std::vector<std::string> split(string str)
{
    std::string buf;                 // Have a buffer string
    std::stringstream ss(str);       // Insert the string into a stream
    std::vector<std::string> tokens; // Create vector to hold our words

    while (ss >> buf)
        tokens.push_back(buf);

    return tokens;
}

void processMachine()
{
    int n = 0;
    for(auto i = rules.begin(); i != rules.end(); i++)
    {
        vector<string> splittedRule = split(*i);
        int newState = stoi(splittedRule[0]);
        int readValue = stoi(splittedRule[1]);

        bool stateResult = newState == state;
        int readValueTape = tape[headPosition] - '0';
        bool headResult =  readValue == readValueTape;

        // cout<< "rule: " << n << " compare state:" << state<< " New state:" << newState
        //    << " newTape: " << readValue <<" oldTape: "<< readValueTape << "Head: "<< headPosition<< endl;


        // if( rules[i][0].equals(state) && rules[i][1].charAt(0) == tape[headPosition]) {
        if( stateResult && headResult )
        {
            // tape[headPosition] = rules[i][2].charAt(0);
            string oldTape = tape;
            // cout<< "oldTape"<< oldTape<<endl;
            string newTape = splittedRule[2];
            oldTape.replace(headPosition, 1, newTape); 
            // cout<< "newTape"<< oldTape<<endl;

            if( splittedRule[3] == "L")
            {   // if( rules[i][3].charAt(0) == 'L') headPosition--;
                headPosition--;
                // cout<<"workedL"<<endl;
            }
            else
            {   // else headPosition++;
                headPosition++;
                cout<<"workedR"<< headPosition <<endl;
                cout<< "rule: " << n << " compare state:" << state<< " New state:" << newState
                << " newTape: " << readValue <<" oldTape: "<< readValueTape << "Head: "<< headPosition<< endl;
            }
            // state = rules[i][4];
            state = stoi(splittedRule[4]);
            // for(int j = 0; j < tape.length; j++) { System.out.print(tape[j]); }
            cout<< tape << endl;
        }
        // n++;
    }
}

int parseConfigData(vector<string> lines)
{
    headPosition = stoi(lines.at(0));
    tape = lines.at(1);
    lines.erase(lines.begin());
    lines.erase(lines.begin());
    rules = lines;

    return 0;
}


int main (int argc, char** argv)
{
    string path = "tmprog.txt";
    // open_file(argv[1]);
    parseConfigData( open_file(path) );

    if( !rules.empty() )
    {
        // while (true)
        for (int i = 0; i < 20; i++)
        {
            processMachine();
        }
    }

    return 0;
}