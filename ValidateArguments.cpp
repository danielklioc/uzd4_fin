#include "ValidateArguments.h"

ValidateArguments::ValidateArguments():
  readerType(0)
{
}

ValidateArguments::~ValidateArguments()
{
}

int ValidateArguments::selectReaderType(string argv)
{
    return argv.find(".txt") ? 1 : 2;
}

// TODO: make dynamic choise of input type
// create separete class for TXT and json datareadet
// data reader interface 
int ValidateArguments::validate(int count, char** argv)
{
  if (count >= 2)
  {
    cout << "Correct input command" << endl;
    readerType = selectReaderType( argv[1]);
    cout << endl;
    cout << endl;
  }
  else
  {
      cout<<"Missing argumet file name in command line"<<endl;
  }

  return readerType;
}
