#include <sstream>

#include "parser.hpp"

using std:: cin;

int main (int argc, char* argv[]) {
  Parser parser = Parser();
  string input;
  do {
    string input;
    getline(cin, input);
    std::stringstream sstream(input);
    string command;
    string expression;
    
    sstream >> command;
    if (command == "LER") {
      command = "";
      sstream >> command;
      if (command == "INFIXA") {
        expression = sstream.str();
        expression.erase(0, 10);
        parser.ler(expression);
      } else if (command == "POSFIXA") {
        expression = sstream.str();
        expression.erase(0, 11);
        parser.ler(expression);
      } else {
        std::cout << "Comando inválido" << std::endl;     
      }
    } else if (command == "INFIXA") {
      parser.infixa();
    } else if (command == "POSFIXA") {
      parser.posfixa();
    } else if (command == "RESOLVE") {
      parser.resolve();
    } else {
      std::cout << "Comando inválido" << std::endl;
    }
  } while (true);
}