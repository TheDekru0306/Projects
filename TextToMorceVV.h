//
// Created by denislav on 20.08.19 г..
//

#ifndef LIST_TEXTTOMORCEVV_H
#define LIST_TEXTTOMORCEVV_H
#include <string>
#include <map>

class Morse
{
private:
    std::map<char, std::string> morse;
    std::map<std::string, char> text;

public:
    Morse() {
        morse['a'] = ".-";
        morse['b'] = "-...";
        morse['c'] = "-.-.";
        morse['d'] = "-..";
        morse['e'] = ".";
        morse['f'] = "..-.";
        morse['g'] = "--.";
        morse['h'] = "....";
        morse['i'] = "..";
        morse['j'] = ".---";
        morse['k'] = "-.-";
        morse['l'] = ".-..";
        morse['m'] = "--";
        morse['n'] = "-.";
        morse['o'] = "---";
        morse['p'] = ".--.";
        morse['q'] = "--.-";
        morse['r'] = ".-.";
        morse['s'] = "...";
        morse['t'] = "-";
        morse['u'] = "..-";
        morse['v'] = "...-";
        morse['w'] = ".--";
        morse['x'] = "-..-";
        morse['y'] = "-.--";
        morse['z'] = "--..";
        morse['.'] = ".-.-.-";
        morse['!'] = "-.-.--";
        morse['?'] = "..--..";
        morse[','] = "--..--";
        morse['-'] = "-....-";

        text[".-"] = 'a';
        text["-..."] = 'b';
        text["-.-."] = 'c';
        text["-.."] = 'd';
        text["."] = 'e';
        text["..-."] = 'f';
        text["--."] = 'g';
        text["...."] = 'h';
        text[".."] = 'i';
        text[".---"] = 'j';
        text["-.-"] = 'k';
        text[".-.."] = 'l';
        text["--"] = 'm';
        text["-."] = 'n';
        text["---"] = 'o';
        text[".--."] = 'p';
        text["--.-"] = 'q';
        text[".-."] = 'r';
        text["..."] = 's';
        text["-"] = 't';
        text["..-"] = 'u';
        text["...-"] = 'v';
        text[".--"] = 'w';
        text["-..-"] = 'x';
        text["-.--"] = 'y';
        text["--.."] = 'z';
        text[".-.-.-"] = '.';
        text["-.-.--"] = '!';
        text["..--.."] = '?';
        text["--..--"] = ',';
        text["-....-"] = '-';
    }
    static std::string text_to_morse(std::string text);
    static std::string morse_to_text(std::string morseVersion);

};

std::string Morse::text_to_morse(std::string text)
{
    Morse morse;
    std::string morseVersion;

    for(auto& c : text)
    {
        c = tolower(c);
    }

    for (int i = 0; i < text.length(); ++i) {
        if(text[i] == ' ')
        {
            continue;
        }
        else if(text[i] == ' ' || text[i] == '\n')
        {
            morseVersion += text[i] + " ";
        }
        else
        {
            morseVersion += morse.morse[text[i]] + " ";
        }
    }

    return morseVersion;
}
std::string Morse::morse_to_text(std::string morseVersion)
{
    Morse morseForText;
    std::string text;
    std::string morsePartion;

    for (int i = 0; i < morseVersion.length(); ++i)
    {
        if(morseVersion[i] == '.' || morseVersion[i] == '-')
        {
            morsePartion += morseVersion[i];
        }
        else
        {
            text += morseForText.text[morsePartion];
            morsePartion = "";
        }
    }

    return text;
}
#endif //LIST_TEXTTOMORCEVV_H
