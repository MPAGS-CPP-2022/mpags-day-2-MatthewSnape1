#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include "TransformChar.hpp"

std::string TransformChar (const char in_char){

    std::string intext;

    if (std::isalpha(in_char)) {
         intext += std::toupper(in_char);
            //return;
        }

    // Transliterate digits to English words
    switch (in_char) {
        case '0':
         intext += "ZERO";
            break;
         case '1':
          intext += "ONE";
          break;
        case '2':
         intext += "TWO";
         break;
         case '3':
           intext += "THREE";
           break;
        case '4':
           intext += "FOUR";
           break;
        case '5':
            intext += "FIVE";
            break;
        case '6':
           intext += "SIX";
           break;
        case '7':
          intext += "SEVEN";
          break;
        case '8':
            intext += "EIGHT";
            break;
        case '9':
         intext += "NINE";
            break;
    }

        // If the character isn't alphabetic or numeric, DONT add it
    return intext;

    return 0;

}



