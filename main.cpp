#include <iostream>
#include <random>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

/*
notes
○ Bubble Sort 
○ Selection Sort
○ Insertion Sort
○ Merge Sort
○ Quick Sort
○ Heap Sort
○ Radix Sort (particularly useful for large numerical datasets or strings)
○ Shell Sort
copy(begin(numbers), end(numbers), begin(numbers2))
*/


//this determines the length of our list of numbers
const int range = 1000;


//-------------------------------- GENERATION-AND-PRINTING --------------------------------//
//-----------------------------------------------------------------------------------------//

//this function generates random numbers in the specified range
int randomnum() {
    random_device rand;
    uniform_int_distribution<int> num(0,range);
    return num(rand);
}

//this is a simple function to print our numbers in order
void print(int(&numbers)[range]) {    
    for(int i=0 ; i<range ; i++) {
        cout << numbers[i] << endl;
    }
}

//-------------------------------------- BUBBLE-SORT --------------------------------------//
//-----------------------------------------------------------------------------------------//

//first version of bubble sort function

void bubblesort(int(&numbers)[range]) {

    while(1) {
        int counter = 1;
        for(int i=0 ; i<(range-1) ; i++) {
            if(numbers[i]>numbers[i+1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
                counter = 0;
            }
        }
        if (counter) break;
    }
}

//------------------------------------ SELECTION-SORT -------------------------------------//
//-----------------------------------------------------------------------------------------//


void selectionsort(int(&numbers)[range]) {
    for(int i=0 ; i<(range-1) ; i++) {
        int min = i;
        for(int j=i ; j<(range) ; j++) {
            if(numbers[j]<numbers[min]) {
                min = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }
}


//-----------------------------------------------------------------------------------------//
//---------------------------------------- M A I N ----------------------------------------//
//-----------------------------------------------------------------------------------------//

//this is the main function where we create our list of numbers and call functions to sort it 

int main() {

    int numbers[range];

    for(int i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }
    
    //bubblesort(numbers);
    selectionsort(numbers);
    print(numbers);

}

