#include <iostream>
#include <random>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

/*
notes
○ Bubble Sort   (functional)
○ Selection Sort    (functional)  
○ Insertion Sort    (functional)
○ Merge Sort 
○ Quick Sort 
○ Heap Sort        (functional)  
○ Radix Sort(particularly useful for large numerical datasets or strings)   
○ Shell Sort
*/

//------------------------------------- ARRAY-SIZE ----------------------------------------//

//this determines the length of our list of numbers
const int range = 100;

//------------------------------- GENERATION-AND-PRINTING ---------------------------------//
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

//------------------------------------- BUBBLE-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

//first version of bubble sort function

void bubblesort(int(&numbers)[]) {

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

//first selection sort algorithm implementation

void selectionsort(int(&numbers)[]) {
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

//------------------------------------ INSERTION-SORT -------------------------------------//
//-----------------------------------------------------------------------------------------//

//insertion sort is functiolan

void insertionsort(int(&numbers)[]) {
    for(int i=1 ; i<range ; i++) {
        int index = i;
        while(numbers[i] < numbers[i-1]) {
            int temp = numbers[i];
            numbers[i] = numbers[i-1];
            numbers[i-1] = temp;
            if(i>0) i--;
        }
        i = index;
    }
}

//-------------------------------------- MERGE-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

//--------------------------------------- HEAP-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

void heap(int numbers[], int n, int i) {
    int root = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && numbers[l] > numbers[root]){
        root = l;
    }
    if (r < n && numbers[r] > numbers[root]){
        root = r;
    }
    if (root != i) {
        swap(numbers[i], numbers[root]);
        heap(numbers, n, root);
    }
}
void heapSort(int(&numbers)[]) {
    for (int i = range / 2 - 1 ; i >= 0; i--) {
        heap(numbers, range, i);
    }
    for (int i = range - 1; i > 0; i--) {
        swap(numbers[0], numbers[i]);
        heap(numbers, i, 0);
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
    //selectionsort(numbers);
    //insertionsort(numbers);
    //print(numbers);
    heapSort(numbers);
    print(numbers);
    
    return 0;

}

