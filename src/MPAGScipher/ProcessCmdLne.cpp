#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TransformChar.hpp"

bool ProcessCmdLne(
    const std::vector<std::string>& args,
    bool& helpRequested,
    bool& versionRequested,
    std::string& inputFileName,
    std::string& outputFileName
    )

    {

    bool encrypt{false};

    bool decrypt{false};

    int key;

    bool keyset{false};

    const std::size_t nCmdLineArgs{args.size()};

    // Options that might be set by the command-line arguments


    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
        } else if (args[i] == "--version") {
            versionRequested = true;
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return false;
            } else {
                // Got filename, so assign value and advance past it
                inputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return false;
            } else {
                // Got filename, so assign value and advance past it
                outputFileName = args[i + 1];
                ++i;
            }
        }else if (args[i] == "-e") {

            encrypt = true;
        
        }else if (args[i] == "-d"){

            decrypt = true;

        } else if (args[i] == "-k"){
            //checks only one key has been entered
            if (keyset == true){
                std::cerr << "[error] only enter one key" << std::endl;
                return false;
            }
            //checks that the cipher key is between 1 and 25
            keyset = true;
            key = abs(stoul(args[i+1]));//does not work with non integer
            if (key > 25 || key < 1){
                std::cerr << "Key must be integer between 1 and 25" << std::endl;
                return false;
            }
            ++i;
        
        }else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            return false;
        }
    }
    //checks that user has selected only chosen either to decrypt or encrypt
    if (!helpRequested && !versionRequested){
        if (encrypt && decrypt){
            std::cerr << "[error] Cannot decrypt and encrypt at the same time\n\n";
            return false;

        }else if (!encrypt && !decrypt){       
            std::cerr << "[error] Must select to either encrypt or decrypt\n\n";
            return false;
        }
            
    }

    char in_char{'x'};

    std::string intext;

        // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFileName.empty()) {
        std::ifstream in_file {inputFileName};

        if (!in_file.good()){
            std::cerr <<"unable to open file" << std::endl;
            return 1;
        }

        while (in_file >> in_char) {
            intext += TransformChar(in_char,key,decrypt);

        }
    }
    else
    {
        while (std::cin >> in_char) {
            intext += TransformChar(in_char,key,decrypt);//if no input file then take input directly from user

        }

    }

    // Warn that output file option not yet implemented
    if (!outputFileName.empty()) {
        std::ofstream out_file {outputFileName};

        if (!out_file.good()){
            std::cerr << "Unable to Save File";
        }

        out_file << intext << std::endl;

    }
    else
    {

        std::cout << intext << std::endl;

    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>] [-e/-d] [key]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << "  -e               This tells the code to encrypt the message\n\n"
            << "  -d               This tells the programme to decrypt the file\n\n "
            << "  -k int           This tell the code the key (Must be be between 1 and 25\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return true;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.2.0" << std::endl;
        return true;
    }

    // Initialise variables

    // loop over each character from user input

    // Print out the transliterated text
    
    //std::cout << intext << std::endl;

    return true;

}
    