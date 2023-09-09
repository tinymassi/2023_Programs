#include <iostream>

// int rec_prac (int num){

//     int new_num = 0 + num;
//     if (new_num == 50) {
//         return new_num;
//     }
//     std::cout << new_num << std::endl;
    
//     return rec_prac(new_num + 1);
// }

int rec_prac2 (int num, int i) {
    int mult = num;

    if (mult >= 10000|| i>=10000){
        return mult;
    }

    std::cout << mult << " " << i << std::endl;
    
    return rec_prac2(mult * i, (i + 1));
}


int main(){

    int num = 5;
    int i = 1;
    //std::cout << rec_prac(num) << std::endl;

    std::cout << rec_prac2(num, i) << std::endl;

    return 0;
}