//
// Created by denislav on 21.08.19 г..
//

#ifndef LIST_ROT13CONVERSION_H
#define LIST_ROT13CONVERSION_H

#include "string"

void encodeRot13(std::string& text)
{
    std::string upperCase ="NOPQRSTUVWXYZABCDEFGHIJKLM";
    std::string lowerCase ="nopqrstuvwxyzabcdefghijklm";

    for (int i = 0; i < text.length(); ++i)
    {
        if(text[i] > 64 && text[i] < 91)
        {
            text[i] = upperCase[text[i] - 65];
        }
        else if(text[i] > 96 && text[i] < 123)
        {
            text[i] = lowerCase[text[i] - 97];
        }
    }
}

void decodeRot13(std::string& text)
{
    encodeRot13(text);
}

#endif //LIST_ROT13CONVERSION_H
