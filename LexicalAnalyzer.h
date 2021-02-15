#pragma once

#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

/*******************************************************************************
 * CONSTANT DECLARATION
 ******************************************************************************/
const int NUM_KEYWORDS   = 21;
const int NUM_SEPARATORS = 10;
const int NUM_OPERATORS  = 8;
const string keywords[NUM_KEYWORDS]   = {"int", "float", "bool", "True", "False",
                                         "if", "else", "then", "endif", "endelse",
                                         "while", "whileend", "do", "enddo", "for",
                                         "endfor", "STDinput", "STDoutput", "and",
                                         "or", "not"};
const char separators[NUM_SEPARATORS] = {'(', ')', '{', '}', '[', ']', ',', '.',
                                         ':', ';'};
const char operators[NUM_OPERATORS]   = {'*', '+', '-', '=', '/', '>', '<', '%'};

class LexicalAnalyzer
{
  public:
    /******************************
     * CONSTRUCTOR - DESTRUCTOR
     ******************************/
    LexicalAnalyzer();
    ~LexicalAnalyzer();

    bool IsSeparator(char &c);
    bool IsOperator(char &c);
    bool IsKeyword(string &s);

  private:
};
