#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* sumCArrays(char * valueOne, char* valueTwo);
int getLength(const char* arr);
void swap(char** arrOne, char** arrTwo);
char* reverse(char* arr);
bool validation(char* arr);

int main()
{
    char valueOne[200];
    char valueTwo[200];

    printf("Enter first num: ");
    scanf("%s", valueOne);

    printf("\nEnter second num: ");
    scanf("%s", valueTwo);

    char* result = sumCArrays(valueOne, valueTwo);

    printf("\nResult: %s", result);
    printf("\n%d", getLength(result));
    return 0;
}

char* sumCArrays(char* valueOne, char* valueTwo)
{
    char* result;
    int valLengthOne = getLength(valueOne);
    int valLengthTwo = getLength(valueTwo);
    int length;
    int onMind = 0;
    int sum;
    int lengthDeference;
    int resultCounter = 0;

    if(!validation(valueOne) || !validation(valueTwo))
    {
        result = "Input not valid!";
        return result;
    }

    if(valLengthOne > valLengthTwo)
    {
        result = (char*)malloc(valLengthOne + 1 * sizeof(char));
        length = valLengthOne;
        lengthDeference = valLengthOne - valLengthTwo;
    }
    else
    {
        result = (char*)malloc(valLengthTwo + 1 * sizeof(char));
        length = valLengthTwo;
        lengthDeference = valLengthTwo - valLengthOne;
        swap(&valueOne, &valueTwo);//In order to have a single solution!
    }

    for (int i = length - 1; i >= 0 ; i--)
    {
        if(i - lengthDeference < 0)
        {
            sum = valueOne[i] - '0' + onMind;
            onMind = 0;
        }
        else
        {
            sum = valueOne[i] + valueTwo[i - lengthDeference] - '0' * 2 + onMind;
        }

        if(sum > 9)
        {
            sum %= 10;
            onMind = 1;
        }
        else
        {
            onMind = 0;
        }

        result[resultCounter] = sum + '0';
        resultCounter++;
    }

    if(onMind == 1)
    {
        result[resultCounter] = '1';
    }

    result = reverse(result);
    return result;
}

int getLength(const char* arr)
{
    int length = 0;

    while(arr[length] != '\0')
    {
        length++;
    }

    return length;
}

void swap(char** arrOne, char** arrTwo)
{
    char *temp = *arrOne;
    *arrOne = *arrTwo;
    *arrTwo = temp;
}

char* reverse(char* arr)
{
    int length = getLength(arr);
    int loopLength = length / 2;
    char temp;

    for (int i = 0; i < loopLength; ++i)
    {
        temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
    return arr;
}

bool validation(char* arr)
{
    int length = getLength(arr);
    bool valid = true;

    for (int i = 0; i < length; ++i)
    {
        if(arr[i] < '0' || arr[i] > '9')
        {
            valid = false;
            break;
        }
    }
    return valid;
}