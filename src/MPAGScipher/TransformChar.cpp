#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include "TransformChar.hpp"
#include "runcipher.hpp"

std::string TransformChar (const char in_char, int cipherkey, bool decrypt){

    std::string out;


    if (std::isalpha(in_char)) {
         out += toupper(in_char);
 
    }

    // Transliterate digits to English words
    switch (in_char) {
        case '0':
         out += "ZERO";
            break;
         case '1':
          out += "ONE";
          break;
        case '2':
            out += "TWO";
            break;
         case '3':
           out += "THREE";
           break;
        case '4':
           out += "FOUR";
           break;
        case '5':
            out += "FIVE";
            break;
        case '6':
           out += "SIX";
           break;
        case '7':
          out += "SEVEN";
          break;
        case '8':
            out += "EIGHT";
            break;
        case '9':
            out += "NINE";
            break;
    }

        // If the character isn't alphabetic or numeric, DONT add it

    out = runcipher(out,cipherkey,decrypt);

    return out;

    return 0;

}



