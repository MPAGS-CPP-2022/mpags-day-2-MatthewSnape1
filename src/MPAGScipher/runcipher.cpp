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
        //sets us alphabet vector
        std::vector<char> abc = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 
        std::string out;
        int index;
        int len = input.length();
        //if user want to decrypt make key negetive (leftward movement)
        if (decrypt == true){
            key = -key;
        }
        //loop through all characters in input string
        for (int i = 0;i < len;i++){
            //compares current imput character to every element in alphabet vector
            for (size_t j = 0;j < abc.size();j++){
                //if input character matches, stop comparison
                if (abc[j] == input[i]){
                    index = j;
                    break;
                }

            }
            //applies key to index (shifts character)
            index = index + key;

            index = index % 26;

            if (index < 0){
                index = index + 26;
            }
            
            std::string let{abc[index]};

            out.append(let);

        }

        //std::cout << out << std::endl;

        return out;

}

