#include "LexicalAnalyzer.h"

int main()
{
  LexicalAnalyzer lexical;

  char c;
  string s;

  c = '(';
  if(lexical.IsSeparator(c))
  {
    cout << "Yes1\n";
  }
  else
  {
    cout << "No1\n";
  }

  c = '@';
  if(lexical.IsOperator(c))
  {
    cout << "Yes2\n";
  }
  else
  {
    cout << "No2\n";
  }

  s = "hello";
  if(lexical.IsKeyword(s))
  {
    cout << "Yes3\n";
  }
  else
  {
    cout << "No3\n";
  }

  return 0;
}
