//
// Created by dennykrumov on 6.09.19 г..
//

#ifndef TASKS_SQUARETEXTFORMAT_H
#define TASKS_SQUARETEXTFORMAT_H

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> split(std::string text);

void formatToSquare(std::string text)
{
    int width, height = 0;

    std::vector<std::string> splitText;
    splitText = split(text);

    height = splitText.size();

    for(auto obj : splitText)
    {
        if(obj.length() > width)
        {
            width = obj.length();
        }
    }

    if(height > width)
    {
        width = height;
    }
    else
    {
        height = width;
    }

    for (int i = 0; i < width; ++i)
    {
        std::cout<<'*';
    }
    std::cout<<'\n';

    for (int i = 0; i < splitText.size(); i++)
    {
        std::cout<<'*'<<splitText[i];
        for (int j = 0; j < width - splitText[i].length(); ++j)
        {
            std::cout<<' ';
        }
        std::cout<<'*'<<'\n';
    }

    for (int i = 0; i < width; ++i)
    {
        std::cout<<'*';
    }
}


std::vector<std::string> split(std::string text)
{
    std::vector<std::string> splitText;
    std::string word;

    for (int i = 0; i < text.length(); ++i)
    {
        if(text[i] != ' ')
        {
            if(i == text.length() - 1)
            {
                word += text[i];
                splitText.push_back(word);
            }
            else
            {
                word += text[i];
            }
        }
        else
        {
            splitText.push_back(word);
            word = "";
        }

    }

    return splitText;
}

#endif //TASKS_SQUARETEXTFORMAT_H
