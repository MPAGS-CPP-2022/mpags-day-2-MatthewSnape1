#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include "TransformChar.hpp"
#include "ProcessCmdLne.hpp"
#include "runcipher.hpp"

int main(int argc, char* argv[])
{

    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    bool helpRequested{false};

    bool versionRequested{false};

    std::string inputFile{""};

    std::string outputFile{""};

    ProcessCmdLne(cmdLineArgs,helpRequested,versionRequested,inputFile,outputFile);

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}