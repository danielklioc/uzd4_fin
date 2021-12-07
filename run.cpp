#include "run.h"

Run::Run():
  valArg(),
  tm()
{
} 

Run::~Run ()
{
} 

void Run::start(uint argc, char** argv)
{
    if( 1 == valArg.validate( argc, argv))
    {
        DataReaderTxt dataReader;
        dataReader.readMachineConfig(argv[1]);
        
        while (true)
        {
            tm.process(dataReader);
        }
    }
    else if( 2 == valArg.validate( argc, argv))
    {
        DataReaderJson dataReader;
        // dataReader.readMachineConfig(argv[1]);
        // while (true)
        // {
        //     tm.process(dataReader);
        // }
    }
    else
    {
      cout<<"File should be text or JSON extension type"<<endl;
    }
} 