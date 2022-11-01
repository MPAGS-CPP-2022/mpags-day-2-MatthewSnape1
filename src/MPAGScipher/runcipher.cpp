#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "runcipher.hpp"

std::string runcipher(
    std::string input,
    int key
    )
    {
        std::vector<char> abc = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
        std::string out;
        std::vector<std::string> vec_str = {"msg1", "msg2"};
        int index;
        int len = input.length();

        for (int i = 0;i < len;i++){

            for (size_t j = 0;j < abc.size();j++){
                if (abc[j] == input[i]){

                    index = j;
                    break;
                }

            }

            index = index + key;

            index = index % 26;
            
            std::string let{abc[index]};

            out.append(let);

        }

        std::cout << out << std::endl;

        return out;

}

