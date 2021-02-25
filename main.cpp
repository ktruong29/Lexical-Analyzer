#include "LexicalAnalyzer.h"

int main(int argc, char *argv[])
{
  if(argc == 1|| argc > 2)
  {
    cout << "USAGE: " << argv[0] << " <text file>" << endl;
    return 1;
  }
  else
  {
    LexicalAnalyzer lexical;
    ofstream fout;
    fout.open("output.txt");

    fout << "TOKENS\t\t\t\t" << "LEXEMES\n\n";
    lexical.LexAnalyzer(argv[1], fout);

    fout.close();
    return 0;
  }
}
