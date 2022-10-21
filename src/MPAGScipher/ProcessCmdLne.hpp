#include <vector>
#ifndef PROCESSCMDLNE_HPP
#define PROCESSCMDLNE_TRANSFORMCHAR_HPP

#include <string>

bool ProcessCmdLne(
    const std::vector<std::string>& args,
    bool& helpRequested,
    bool& versionRequested,
    std::string& inputFileName,
    std::string& outputFileName);

#endif // PROCESSCMDLNE_HPP