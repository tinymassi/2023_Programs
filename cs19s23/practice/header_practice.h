//What if we want to access multiple types in a function?
//Overloading lets us use multiple versions of the same function to throw in different arguments.
//Ex: doublearea(int x), doublearea(int x, int y), doublearea(double x), etc...
//So what we usually write in these function templates is something like this -
//void swap (T &x,T &y)
//The "T" in this case is used as a placeholder for a type.
//In order for the computer to understand that this is a templitized function, we usually put something like this above it-
//template <typename T>
//^Basically specifying that T is the template that can be substitiuted for any type!
//We can also use T as a type not just in the parameters of the templitized function-
//T temp = x;
#ifndef HEADER_PRACTICE_H_
#define HEADER_PRACTICE_H_

namespace practice {

template <typename T>
void swap(T &a,T &b){

    T temp = a;
    a = b;
    b = temp;
}

}
#endif //HEADER_PRACTICE_H_