//
// Created by denislav on 12.09.19 г..
//

#ifndef LIST_PRIMECHECKER_H
#define LIST_PRIMECHECKER_H

#include <iostream>

void primeChecker(int value)
{
    bool isPrime = true;

    for(int i = 2; i <= value / 2; ++i)
    {
        if(value % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        std::cout << "This is a prime number";
    }
    else
    {
        std::cout << "This is not a prime number";
    }
}

#endif //LIST_PRIMECHECKER_H
