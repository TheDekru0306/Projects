//
// Created by denislav on 27.08.19 г..
//

#ifndef LIST_SKYTALE_H
#define LIST_SKYTALE_H
#include <string>
#include <vector>

using namespace std;

class Skytale
{
private:
    vector<int> wordLengths;//Keep's track of the length of each word in the text.
    string word;
    vector<vector<char>>arr;//Keep's each element of the text in a two dimensional array of char's
    int indexCounter = 0;
    int colLength;

    void removeSpaces(string& text);
public:
    void encode(string& text, int key);
    void decode(string& text, int key);
};

void Skytale::encode(string &text, int key)
{
    for (int i = 0; i < text.length(); ++i)//Initializes wordLengths vector
    {
        if(text[i] == ' ' || i == text.length() - 1)
        {
            if(isalpha(text[i]))
            {
                word += text[i];
            }
            wordLengths.push_back(word.length());
            word = "";
        }
        else
        {
            word += text[i];
        }
    }

    removeSpaces(text);
    if(text.length() % key != 0)//Checks for how many cows should the vector have.
    {
        colLength = text.length() / key + 1;
        arr =  vector<vector<char>>(colLength, vector<char>(key));

    }
    else
    {
        colLength = text.length() / key;
        arr =  vector<vector<char>>(colLength, vector<char>(key));
    }

    for (int j = 0; j < arr.size(); ++j)//Add's each element from text to the arr parameter
    {
        for (int i = 0; i < arr[j].size(); ++i)
        {
            if(indexCounter == text.length())
            {
                break;
            }
            arr[j][i] = text[indexCounter];
            indexCounter++;
        }
    }

    indexCounter = 0;

    for (int row = 0; row < arr[0].size(); ++row)
    {
        for (int col = 0; col < colLength; ++col, indexCounter++)
        {
            if(isalpha(arr[col][row]))
            {
                if(col == colLength - 2)
                {
                    if(isalpha(arr[colLength - 1][row]))
                    {
                        text[indexCounter] = arr[col][row];
                        indexCounter++;
                        text[indexCounter] = arr[colLength - 1][row];
                    }
                    else
                    {
                        text[indexCounter] = arr[col][row];
                    }
                }
                else
                {
                    text[indexCounter] = arr[col][row];
                }
            }
        }
    }

    indexCounter = 0;

    for(auto legth : wordLengths)
    {
        for (int i = 0; i < legth; ++i, indexCounter++)
        {
            word += text[indexCounter];
        }
        word += " ";
    }

    text = word;
}

void Skytale::decode(string &text, int key) {

}

void Skytale::removeSpaces(string &text)
{
    string removedSpacesSTR;

    for (int i = 0; i < text.length(); ++i)
    {
        if(text[i] != ' ')
        {
            removedSpacesSTR += text[i];
        }
    }

    text = removedSpacesSTR;
}


#endif //LIST_SKYTALE_H