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
const string KEYWORDS[NUM_KEYWORDS]   = {"int", "float", "bool", "True", "False",
                                         "if", "else", "then", "endif", "endelse",
                                         "while", "whileend", "do", "enddo", "for",
                                         "endfor", "STDinput", "STDoutput", "and",
                                         "or", "not"};
const char SEPARATORS[NUM_SEPARATORS] = {'(', ')', '{', '}', '[', ']', ',', '.',
                                         ':', ';'};
const char OPERATORS[NUM_OPERATORS]   = {'*', '+', '-', '=', '/', '>', '<', '%'};

/*******************************************************************************
 * FUNCTION PROTOTYPES
 ******************************************************************************/
 bool FindChar(char &c, const char CHAR_AR[], const int AR_SIZE);
 bool FindString(string &s, const string STRING_AR[], const int AR_SIZE);

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
