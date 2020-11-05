//
// Created by denislav on 21.08.19 г..
//

#ifndef LIST_TAPCODE_H
#define LIST_TAPCODE_H

#include "string"
#include "vector"

std::vector<std::vector<int>> encodeTap(std::string text)
{
    std::vector<std::vector<int>> coordinates = {{1,1}, {1,2}, {1,3}, {1,4}, {1,5},
                                                 {2,1}, {2,2}, {2,3}, {2,4}, {2,5},
                                                 {3,1}, {3,2}, {3,3}, {3,4}, {3,5},
                                                 {4,1}, {4,2}, {4,3}, {4,4}, {4,5},
                                                 {5,1}, {5,2}, {5,3}, {5,4}, {5,5}};

    std::vector<std::vector<int>>alpToCoordinates;

    for (int i = 0; i < text.length(); ++i)
    {
        if(text[i] != ' ')
        {
            if(text[i] == 'K')
            {
                alpToCoordinates.push_back(coordinates['C' - 65]);
            }
            else
            {
                if(text[i] > 'J')
                {
                    alpToCoordinates.push_back(coordinates[text[i] - 66]);
                }
                else
                {
                    alpToCoordinates.push_back(coordinates[text[i] - 65]);
                }
            }
        }
    }

    return alpToCoordinates;
}

std::string decodeTap(std::vector<std::vector<int>>alpToCoordinates)
{
    char alphabet[5][5] = {'A', 'B', 'C', 'D', 'E',
                           'F', 'G', 'H', 'I', 'J',
                           'L', 'M', 'N', 'O', 'P',
                           'Q', 'R', 'S', 'T', 'U',
                           'V', 'W', 'X', 'Y', 'Z'};

    std::string text = "";

    for(auto address : alpToCoordinates)
    {
        text += alphabet[(address[0] - 1)][(address[1] - 1)];
    }

    return text;
}

/*
 * std::string text = "Place your test text here!";

    std::vector<std::vector<int>> result = encodeTap(text);

    for(auto address : result)
    {
        for(auto element : address)
        {
            std::cout<<element;
        }
        std::cout<<' ';
    }

    std::string strResult = decodeTap(result);

    std::cout<<'\n'<<strResult;*/

#endif //LIST_TAPCODE_H
