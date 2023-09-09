#include <iostream>
#include <iomanip>
int main(){
  std::string dna_info;
  std::string total_info = "";
  while (getline(std::cin, dna_info)){
    total_info += dna_info;
  }
  int total_info_size = total_info.size();
  int char_count = 0;
  double c_g_counter = 0.0;
  for (int i = 0; i < total_info_size; i++){
    if (total_info[i] == 'G' || total_info[i] == 'C'){
      c_g_counter++;
      char_count++;
    } else if (total_info[i] == 'A' || total_info[i] == 'T'){
      char_count++;
    }
  }
  double gc_content = c_g_counter / char_count;
  if (char_count > 0){
    std::cout << std::fixed << std::setprecision(6) << gc_content * 100 << std::endl;
  } else{
    std::cout << std::fixed << std::setprecision(6) << c_g_counter << std::endl;
  }
}
