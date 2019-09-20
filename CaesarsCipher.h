//
// Created by denislav on 21.08.19 г..
//

#ifndef LIST_CAESARSCIPHER_H
#define LIST_CAESARSCIPHER_H

#include <string>


void encode(std::string &text, int shift, std::string key)
{
    int shiftRange = shift % key.length();
    std::string keyUpper = "";

    for (auto & c: key)
    {
        keyUpper += toupper(c);
    }
    for (auto & c: key) c = tolower(c);

    for (int i = 0; i < text.length(); ++i)
    {
        int keyIndex = key.find(tolower(text[i]));

        if(keyIndex != -1)
        {
            int shiftBy = keyIndex + shiftRange;

            if(shiftBy >= key.length())
            {
                shiftBy -= key.length();
            }
            text[i] = isupper(text[i]) ? keyUpper[shiftBy] : key[shiftBy];
        }
    }
}

void decode(std::string &text, int shift, std::string key)
{
    int shiftRange = shift % key.length();
    std::string keyUpper = "";

    for (auto & c: key)
    {
        keyUpper += toupper(c);
    }
    for (auto & c: key) c = tolower(c);

    for (int i = 0; i < text.length(); ++i)
    {
        int keyIndex = key.find(tolower(text[i]));

        if(keyIndex != -1)
        {
            int shiftBy = keyIndex - shiftRange;

            if(shiftBy < 0)
            {
                shiftBy = key.length() + shiftBy;
            }

            text[i] = isupper(text[i]) ? keyUpper[shiftBy] : key[shiftBy];
        }
    }
}


#endif //LIST_CAESARSCIPHER_H
