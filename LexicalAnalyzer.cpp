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

int LexicalAnalyzer::ConvertCharToCol(char &c)
{
  int col;

  if(isalpha(c)) //letter
  {
    col = 0;
  }
  else if(isdigit(c))
  {
    col = 1;
  }
  else if(IsOperator(c))
  {
    col = 2;
  }
  else if(IsSeparator(c) && c != '.')
  {
    col = 3;
  }
  else if(c == '!')
  {
    col = 4;
  }
  else if(c == '_')
  {
    col = 5;
  }
  else if(c == ' ')
  {
    col = 6;
  }
  else if(c == '.')
  {
    col = 7;
  }
  else if(c == '$')
  {
    col = 8;
  }
  //Other cases - special characters
  else
  {
    col = 9;
  }
  return col;
}

void LexicalAnalyzer::LexAnalyzer(string fileName, ofstream &fout)
{
  // index                          0  1  2  3  4  5  6  7  8  9
  //                               l  d  O  S  !  _ sp  .  $  Other
  const int STATE_TABLE[12][10] = {{1, 4, 8, 9, 10, 3, 3, 3, 3, 3},  //0
                                   {1, 1, 2, 2, 3, 1, 2, 3, 1, 2},   //1   
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   //2
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   //3
                                   {3, 4, 5, 5, 3, 3, 5, 6, 3, 3},   //4
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   //5
                                   {3, 6, 7, 7, 3, 3, 7, 3, 3, 3},   //6
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   //7
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   //8
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   //9
                                   {10, 10, 10, 10, 11, 10, 10, 10, 10, 10},  //10
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}    //11
                                  };
  ifstream fin;
  char c;
  string lex;
  int row;
  int col;
  int state;
  lex = "";
  row   = 0;
  state = 0;

  fin.open(fileName);
  if(fin.is_open())
  {
    while(!fin.eof())
    {
      fin.get(c);
      // cout << "New char: " << c << endl;
      // cout << "New lex: " << lex << endl;
      col = ConvertCharToCol(c);

      state = STATE_TABLE[row][col];
      // cout << "Current state: " << state << endl;
      switch(state)
      {
        case 0:
            break;
        //Appending a char into the string buffer

        case 1:
          lex += c; // lex = lex + c   lex = int
            break;

        case 2:
          //Comparing keywords vs. identifiers
          if(IsKeyword(lex))
          {
            fout << "KEYWORD\t\t\t" << "=\t\t" << lex << endl;
          }
          else
          {
            fout << "IDENTIFIER\t" << "=\t\t" << lex << endl;
          }
          //Comparing the current character in the buffer (operator or separator?)
          if(IsSeparator(c))
          {
            fout << "SEPARATOR\t\t" << "=\t\t" << c << endl;
          }
          else if(IsOperator(c))
          {
            fout << "OPERATOR\t\t" << "=\t\t" << c << endl;
          }
          //Clear the string buffer for the next input
          lex = "";
          state = 0;
            break;

        case 3: //Example: num%, num^
          // cout << "Unknow lexeme: " << lex << c << endl;
          lex = "";
          state = 0;
            break;

        //Appending digit into the string buffer
        case 4:
          lex += c;
            break;

        case 5:
          fout << "INTEGER\t\t" << "=\t\t" << lex << endl;
          //Comparing the current character in the buffer (operators or separators?)
          if(IsSeparator(c) && c != '.')
          {
            fout << "SEPARATOR\t\t" << "=\t\t" << c << endl;
          }
          else if(IsOperator(c))
          {
            fout << "OPERATOR\t\t" << "=\t\t" << c << endl;
          }
          lex = "";
          state = 0;
            break;

        //For real and float numbers
        case 6:
          lex += c;
            break;

        //Real, float numbers
        case 7:
          fout << "REAL\t\t\t" << "=\t\t" << lex << endl;
          if(IsSeparator(c))
          {
            fout << "SEPARATOR\t\t" << "=\t\t" << c << endl;
          }
          else if(IsOperator(c))
          {
            fout << "OPERATOR\t\t" << "=\t\t" << c << endl;
          }
          lex = "";
          state = 0;
            break;

        case 8:
          fout << "OPERATOR\t\t" << "=\t\t" << c << endl;
          state = 0;
            break;

        case 9:
          fout << "SEPARATOR\t\t" << "=\t\t" << c << endl;
          state = 0;
            break;

        case 10:
            break;

        case 11:
          state = 0;
            break;

       default:
          state = 0;
            break;
      }//END switch(state)

      row = state;
    }//END while(!fin.eof())
    fin.close();
  }//END if(fin.is_open())
  else
  {
    cout << "Can't open " << fileName << endl;
  }
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
