#include <iostream>
#include <vector>

using namespace std;

void adder(int *num2){
    *num2 = *num2 + 1;
}

void test(const char* str){
   int num = str;
}

int main (){

    int num = 5;
    cout << "FUNCTION TEST: " << endl;
    adder(&num);
    cout << num << endl;
    cout << endl;

    char msg[] = "12345";
    test(msg);

    cout << "STANDARD POINTER TEST:" << endl;
    int *ptr = &num;
    cout << ptr << endl;

    int nums[7] = {1, 2, 5, 6, 8, 10, 3};
    cout << endl;
    cout << "ARRAY VALUES, THEN ADDRESSES:" << endl;
    for (int i = 0; i < 7; i++){
        int *pnums = &nums[i];
        cout << "Value " << i << " : " << *pnums << endl; 
    }   
    cout << endl;
    for (int i = 0; i < 7; i++){
        int *pnums = &nums[i];
        cout << "Addres for Value " << i << " : " << pnums << endl; 
    }

    cout << endl;
    vector <int> vect;
    cout << "VECTOR VALUES, THEN ADDRESSES:" << endl;
    for (int i = 0; i < 7; i++){
        vect.push_back(i);
        cout << "Value " << i << " : " << vect[i] << endl;
    }
    cout << endl;
    for (auto thing : vect){
        int *pvect = &thing;
        cout << "Addres for Value " << thing << " : " << pvect << endl;
    }
    cout << endl;

    return 0;
}