#include "cs19_c_strings.h"
#include <cassert>
#include <iostream>

int main(){

  //use the official functions to test outputs

  // char msg[] = "12345";
  // assert(cs19::atoi(msg) == 12345);

  // char hstck[] = "254212333";
  // char ndl = '1';
  // char ndl2 = 'a';
  // assert(cs19::strchr(hstck, ndl) == hstck + 4);
  // assert(cs19::strchr(hstck, ndl2) == nullptr);

  // char test[] = "1234";
  // char test2[] = "12345";
  // assert(cs19::strcmp(msg, hstck) < 0);

  // char hstck2[] = "hamnaps";
  // char ndl3[] = "naps";
  // assert(cs19::strstr(hstck2, ndl3) == (hstck2 + 3));
  // std::cout << cs19::strstr(hstck2, ndl3) << std::endl;

  // char hstck7[] = "snapples";
  // char ndl8[] = "napple";
  // std::cout << cs19::strstr(hstck7, ndl8) << std::endl;

  // char hstck8[] = "haab";
  // char ndl18[] = "abc";
  // assert(cs19::strstr(hstck8, ndl18) == nullptr);

  // char hstck6[] = "hhhhh";
  // char ndl7[] = "ham";
  // assert(cs19::strstr(hstck6,ndl7) == nullptr);
  

  // assert(cs19::strlen(msg) == 5);

  // char msg_2[] = "12345";
  // assert(cs19::strpbrk(msg_2, "abc543") == (msg_2 + 2));

  // char msg_3[] = "balls";
  // assert(cs19::strpbrk(msg_3, "cd281048543") == nullptr);

  // char hstck3[] = "Hanham";
  // char ndl4 = 'a';
  // assert(cs19::strrchr(hstck3, ndl4) == (hstck3 + 4));

  // char hstck4[] = "aygfye";
  // char ndl5 = 'y';
  // assert(cs19::strrchr(hstck4, ndl5) == (hstck4 + 4));

  // char hstck5[] = "gh";
  // char ndl6 = '6';
  // assert(cs19::strrchr(hstck5, ndl6) == nullptr);

  // char s1[] = "123";
  // char s2[] = "hello";
  // char s3[100];
  // cs19::strzip(s1, s2, s3);

  // std::cout << s3 << std::endl;
  
  // char balls[] = "abc";
  // std::cout << cs19::str_rot13(balls) << std::endl;


  // for (int i = 0; i < 10; i++){
  //   std::cout << balls[i] << std::endl;
  // }

  char string[] = "banger";
  cs19::strrev(string);
  std::cout << string << std::endl;

  // char char_to_int[] = "2541204674";
  // assert(cs19::atoi(char_to_int) == 2541204674);
  

  //assert(!cs19::strcmp(s3, "h1e2l3lo")); h1e2l3lo

}