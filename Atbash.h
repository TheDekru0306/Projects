//
// Created by denislav on 25.08.19 г..
//

#ifndef LIST_ATBASH_H
#define LIST_ATBASH_H
#include <string>

void encode(std::string& text, std::string alphabet)
{
    std::string reverseAlphabet = "";

    for (int i = alphabet.length() - 1; i >= 0; i--)
    {
        reverseAlphabet += alphabet[i];
    }

    for (int j = 0; j < text.length(); ++j)
    {
        if(isalpha(text[j]))
        {
            if(isupper(text[j]))
            {
                text[j] = toupper(reverseAlphabet[text[j] - 'A']);
            }
            else
            {
                text[j] = reverseAlphabet[text[j] - 'a'];
            }
        }
    }
}
void decode(std::string& text, std::string alphabet)
{
    encode(text, alphabet);
}

#endif //LIST_ATBASH_H
