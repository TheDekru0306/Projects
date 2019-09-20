//
// Created by denislav on 26.08.19 г..
//

#ifndef LIST_KEYWORDCIPHER_H
#define LIST_KEYWORDCIPHER_H

#include <string>

void encode(std::string &text, std::string alphabet, std::string key)
{
    std::string convertedKey = "";
    std::string convertedAlphabet = "";

    int pos;
    for (int i = 0; i < key.length(); ++i)
    {
            if(convertedKey.find(key[i]) == -1)
            {
                convertedKey += key[i];
            }
    }

    for (int i = 0; i < convertedKey.length(); ++i)
    {
        pos = alphabet.find(convertedKey[i]);

        alphabet.erase(alphabet.begin() + pos);
    }

    convertedAlphabet = convertedKey + alphabet;

    for (int i = 0; i < text.length(); ++i)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = toupper(convertedAlphabet[text[i] - 'a']);
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = convertedAlphabet[text[i] - 'a'];
        }
    }

}

void decode(std::string &text, std::string alphabet, std::string key)
{
    std::string convertedKey = "";
    std::string convertedAlphabet = alphabet;

    int pos;
    for (int i = 0; i < key.length(); ++i)
    {
        if(convertedKey.find(key[i]) == -1)
        {
            convertedKey += key[i];
        }
    }

    for (int i = 0; i < convertedKey.length(); ++i)
    {
        pos = convertedAlphabet.find(convertedKey[i]);

        convertedAlphabet.erase(convertedAlphabet.begin() + pos);
    }

    convertedAlphabet = convertedKey + convertedAlphabet;


    for (int i = 0; i < text.length(); ++i)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            pos = convertedAlphabet.find(tolower(text[i]));
            text[i] = toupper(alphabet[pos]);
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            pos = convertedAlphabet.find(tolower(text[i]));
            text[i] = alphabet[pos];
        }
    }
}

#endif //LIST_KEYWORDCIPHER_H
