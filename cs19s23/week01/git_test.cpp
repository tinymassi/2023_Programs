/*
Given: A DNA string s
 of length at most 1000 nt.

Return: Four integers (separated by spaces) counting the respective number of times that the symbols 'A', 'C', 'G', and 'T' occur in s
.

Sample Dataset
AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC
20 12 17 21
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
  //1. read input (DNA sting)
  string dna;
  cin >> dna; // read/extract one whitespace delimited token of text from std in
  //2. count the nucleotides (A/C/G/T)
  int a_count = 0;
  int c_count = 0;
  int g_count = 0;
  int t_count = 0;
  //range based for loop
  //iterate (step through) dna, copying each char into var named "base"
  for (char base; dna){
    switch (base) {
      case 'A': ++a_count break;
      case 'C': ++c_count break;
      case 'G': ++g_count break;
      case 'T': ++t_count break;
    }
  }
  //3. print the counts
  cout << a_count << ' ' << c_count << ' ' << g_count << ' ' << t_count << endl;
}
