#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
int main(){
  std::string line;
  std::string word;
  double num_words = 0.0;
  int num_sentences = 0;
  double num_chars = 0.0;
  int wrd_check = 0;
  while (getline(std::cin, line)){
    std::istringstream new_file(line);
    while(getline(new_file, word, ' ')){
      wrd_check = 0;
      bool sen_check = false;
      bool char_check = false;
      for (int i = 0; i < word.size(); i++){
        if (isalpha(word[i])){char_check = true;}
        if (((word[i] == '.' || word[i] == '!' || word[i] == '?') && !sen_check) && char_check){
         sen_check = true;
         num_sentences++;
        }
        if (isalpha(word[i])){
          num_chars++;
          wrd_check++;
        }
      }
        //if (sen_check == false){std::cout << " " <<  word << " ";}
        if (wrd_check > 0){num_words++;}
      //std::cout << word << " " <<  num_chars << "c " << num_words << "w " << num_sentences << "s" << std::endl;
    }
  }
  std::cout << " " <<  num_chars << "c " << num_words << "w " << num_sentences << "s" << std::endl;
  std::cout << std::fixed << std::setprecision(4) << (4.71 * (num_chars / num_words)) + ((0.5 * (num_words / num_sentences)) - 21.43) << std::endl;
}
