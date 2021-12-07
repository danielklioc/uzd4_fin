#pragma once
#include "utilitis.h"
#include "DataReaderTxt.h"

class ValidateArguments
{
public:
    ValidateArguments();
    ~ValidateArguments();

    int validate(int count, char** argv);

private:
    int selectReaderType(string argv);

    int readerType;
};