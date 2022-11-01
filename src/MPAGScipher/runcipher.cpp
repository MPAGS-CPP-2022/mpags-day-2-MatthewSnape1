#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include "runcipher.hpp"

std::string runcipher(
    std::string input,
    int key,
    const bool decrypt
    )
    {
        std::vector<char> abc = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 
        std::string out;
        int index;
        int len = input.length();

        if (decrypt == true){
            key = -key;
        }

        for (int i = 0;i < len;i++){

            input[i] = toupper(input[i]);

            for (size_t j = 0;j < abc.size();j++){

                if (abc[j] == input[i]){

                    index = j;
                    break;
                }

            }

            index = index + key;

            index = index % 26;

            if (index < 0){
                index = index + 26;
            }
            
            std::string let{abc[index]};

            out.append(let);

        }

        std::cout << out << std::endl;

        return out;

}

