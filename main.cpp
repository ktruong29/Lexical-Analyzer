#include "LexicalAnalyzer.h"

int main()
{
  LexicalAnalyzer lexical;
  ofstream fout;
  fout.open("output.txt");

  fout << "TOKENS\t\t\t\t" << "LEXEMES\n\n";
  lexical.LexAnalyzer("input.txt", fout);

  fout.close();
  return 0;
}
