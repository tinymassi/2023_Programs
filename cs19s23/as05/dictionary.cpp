#include <fstream>
#include <iostream>
#include <set>
#include <string>

std::string find_rhyme(std::string &pro) {
  bool find = false;
  std::string rhyme_chunk = "";
  for (int i = pro.size() - 1; i >= 0; i--) {
    if (pro[i] != ' ') {
      rhyme_chunk = pro[i] + rhyme_chunk;
    }
    if (pro[i] == '1' || pro[i] == '2') {
      find = true;
    }
    if (find == true && pro[i] == ' ') {
      break;
    }
  }
  return rhyme_chunk;
}

int count_syl(std::string &str) {
  int syl_check = 0;
  int str_size = str.size();
  for (int i = 0; i < str_size; i++) {
    if (str[i] == '0' || str[i] == '1' || str[i] == '2') {
      syl_check++;
    }
  }

  return syl_check;
}

int main(int argc, char **argv) {
  std::set<std::string> all_results;
  std::set<std::string> all_word_versions;
  std::set<int> all_syl_versions;
  std::set<std::string> all_rhymes_versions;
  std::ifstream dict_file("/srv/datasets/cmudict/cmudict.dict");
  std::string input_word = argv[1];
  bool a = false;
  if (argv[2]) {
    std::string second_input = argv[2];
    if (second_input == "-a") {
      a = true;
    }
  }
  std::string word;
  std::string pro;
  bool input_seen = false;
  while (dict_file >> word && dict_file.seekg(1, std::ios_base::cur) &&
         std::getline(dict_file, pro)) {
    if (word[word.size() - 2] == '2' || word[word.size() - 2] == '3' ||
        word[word.size() - 2] == '4') {
      word.erase(word.begin() + (word.size() - 3), word.end());
    }
    if (input_word == word) {
      all_syl_versions.insert(count_syl(pro));
      all_rhymes_versions.insert(find_rhyme(pro));
      input_seen = true;
    } else if (input_seen) {
      break;
    }
  }

  dict_file.seekg(0, std::ios::beg);

  while (dict_file >> word && dict_file.seekg(1, std::ios_base::cur) &&
         std::getline(dict_file, pro)) {
    if (all_rhymes_versions.find(find_rhyme(pro)) !=
        all_rhymes_versions.end()) {
      if (word[word.size() - 2] == '2' || word[word.size() - 2] == '3' ||
        word[word.size() - 2] == '4') {
        word.erase(word.begin() + (word.size() - 3), word.end());
      }
      if (a == true && word != input_word) {
        all_results.insert(word);
      }

      for (auto syl_count : all_syl_versions) {
        if (a == false && (count_syl(pro) == syl_count) && word != input_word) {
          all_results.insert(word);
        }
      }
    }
  }

  if (a == false) {
    for (auto word : all_results) {
      std::cout << word << std::endl;
    }
  } else {
    for (auto word : all_results) {
      std::cout << word << std::endl;
    }
  }
}