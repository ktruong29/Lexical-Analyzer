#include "LexicalAnalyzer.h"


LexicalAnalyzer::LexicalAnalyzer(){}

LexicalAnalyzer::~LexicalAnalyzer(){}

bool LexicalAnalyzer::IsSeparator(char &c)
{
  return FindChar(c, SEPARATORS, NUM_SEPARATORS);
}

bool LexicalAnalyzer::IsOperator(char &c)
{
  return FindChar(c, OPERATORS, NUM_OPERATORS);
}

bool LexicalAnalyzer::IsKeyword(string &s)
{
  return FindString(s, KEYWORDS, NUM_KEYWORDS);
}








/*******************************************************************************
 * OTHER HELPER FUNCTIONS
 ******************************************************************************/
bool FindChar(char &c, const char CHAR_AR[], const int AR_SIZE)
{
  bool found;
  int  i;
  found = false;
  i = 0;

  while(!found && i < AR_SIZE)
  {
    //When an element is found, stops the iteration and returns 'found' back to the driver
    if(c == CHAR_AR[i])
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

bool FindString(string &s, const string STRING_AR[], const int AR_SIZE)
{
 bool found;
 int  i;
 found = false;
 i = 0;

 while(!found && i < AR_SIZE)
 {
   //When an element is found, stops the iteration and returns 'found' back to the driver
   if(s == STRING_AR[i])
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
