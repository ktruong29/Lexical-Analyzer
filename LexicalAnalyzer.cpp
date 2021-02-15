#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(){}

LexicalAnalyzer::~LexicalAnalyzer(){}

bool LexicalAnalyzer::IsSeparator(char &c)
{
  bool found;
  int  i;
  found = false;
  i = 0;

  while(!found && i < NUM_SEPARATORS)
  {
    //When an element is found, stops the iteration and returns 'found' back to the driver
    if(c == separators[i])
    {
      found = true;
    }
    //Keeps incrementing i to access the next element in an array
    else
    {
      i++;
    }
  }//END while(!found && i < NUM_SEPARATORS)
  return found;
}

bool LexicalAnalyzer::IsOperator(char &c)
{
  bool found;
  int  i;
  found = false;
  i = 0;

  while(!found && i < NUM_OPERATORS)
  {
    //When an element is found, stops the iteration and returns 'found' back to the driver
    if(c == operators[i])
    {
      found = true;
    }
    //Keeps incrementing i to access the next element in an array
    else
    {
      i++;
    }
  }//END while(!found && i < NUM_SEPARATORS)
  return found;
}

bool LexicalAnalyzer::IsKeyword(string &s)
{
  bool found;
  int  i;
  found = false;
  i = 0;

  while(!found && i < NUM_KEYWORDS)
  {
    //When an element is found, stops the iteration and returns 'found' back to the driver
    if(s == keywords[i])
    {
      found = true;
    }
    //Keeps incrementing i to access the next element in an array
    else
    {
      i++;
    }
  }//END while(!found && i < NUM_SEPARATORS)
  return found;
}
