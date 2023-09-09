
// the "math" represents the word you will input for running the code like "./a.out"

math is the destination, the names after is the source
math: math_stuff.o math_utils.o  
    g++ math_stuff.o math_utils.o -o math  // how do we get from source to destination? "-o" is the output flag

math_stuff.o: math_stuff.cpp  // basically saying that math_stuff.o comes from math_stuff.cpp
    g++ -c math_stuff.cpp  // this is the compilation needed to get from math_stuff.o to math_stuff.cpp "-c" is for grabbing object code

math_utils.o: math_utils.cpp 
    g++ -c math_utils.cpp

clean:  // this removes any files that need to be cleaned up
    rm *.o math  // "remove or clean any files that end in .o"