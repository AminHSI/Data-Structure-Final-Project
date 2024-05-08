#include <iostream>
#include <random>
#include <string>
#include <array>
using namespace std;

/*
○ Bubble Sort
○ Selection Sort
○ Insertion Sort
○ Merge Sort
○ Quick Sort
○ Heap Sort
○ Radix Sort (particularly useful for large numerical datasets or strings)
○ Shell Sort
*/



const int range = 1000;

//this is a simple function to print our numbers in order
void print(int(&numbers)[range]) {
    
    for(int i=0 ; i<range ; i++) {
        cout << numbers[i] << endl;
    }
}


//this function generates random numbers in the specified range
int randomnum() {

    random_device rand;

    uniform_int_distribution<int> num(0,range);

    return num(rand);
}

//this is the main function where we create our random list of numbers and call functions to sort it 
int main() {

    int numbers[range];

    for(int i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }
    
    print(numbers);
}

