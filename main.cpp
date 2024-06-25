#include <iostream>
#include <random>
using namespace std;

/*
notes
○ #Bubble Sort 
○ #Selection Sort
○ #Insertion Sort
○ #Merge Sort
○ #Quick Sort
○ Heap Sort
○ Radix Sort (particularly useful for large numerical datasets or strings)
○ Shell Sort
*/

// This determines the length of our list of numbers
const int range = 10;

//------------------------------- GENERATION-AND-PRINTING ---------------------------------//
//-----------------------------------------------------------------------------------------//

// This function generates random numbers in the specified range
int randomnum() {
    random_device rand;
    uniform_int_distribution<int> num(0, range);
    return num(rand);
}

// This is a simple function to print our numbers in order
void print(int(&numbers)[range]) {
    for (int i = 0; i < range; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

//------------------------------------- BUBBLE-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

// First version of bubble sort function
void bubblesort(int(&numbers)[range]) {
    while (1) {
        int counter = 1;
        for (int i = 0; i < (range - 1); i++) {
            if (numbers[i] > numbers[i + 1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                counter = 0;
            }
        }
        if (counter) break;
    }
}

//------------------------------------ SELECTION-SORT -------------------------------------//
//-----------------------------------------------------------------------------------------//

// First selection sort algorithm implementation
void selectionsort(int(&numbers)[range]) {
    for (int i = 0; i < (range - 1); i++) {
        int min = i;
        for (int j = i; j < range; j++) {
            if (numbers[j] < numbers[min]) {
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

// Insertion sort implementation
void insertionsort(int(&numbers)[range]) {
    for (int i = 0; i < range; i++) {
        int index = i;
        while (i > 0 && numbers[i] < numbers[i - 1]) {
            int temp = numbers[i];
            numbers[i] = numbers[i - 1];
            numbers[i - 1] = temp;
            i--;
        }
        i = index;
    }
}

//-------------------------------------- MERGE-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

void Merge(int left[], int leftSize, int right[], int rightSize, int numbers[], int totalSize) {
    int l = 0, r = 0, i = 0;

    while (l < leftSize && r < rightSize) {
        if (left[l] < right[r]) {
            numbers[i++] = left[l++];
        } else {
            numbers[i++] = right[r++];
        }
    }

    while (l < leftSize) {
        numbers[i++] = left[l++];
    }

    while (r < rightSize) {
        numbers[i++] = right[r++];
    }
}

void mergeSort(int numbers[], int length) {
    if (length <= 1) {
        return;
    }

    int mid = length / 2;
    int left[mid];
    int right[length - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = numbers[i];
    }
    for (int i = mid; i < length; i++) {
        right[i - mid] = numbers[i];
    }

    mergeSort(left, mid);
    mergeSort(right, length - mid);
    Merge(left, mid, right, length - mid, numbers, length);
}

//-------------------------------------- QUICK-SORT ----------------------------------------//
//-----------------------------------------------------------------------------------------//

int partition(int numbers[], int low, int high) {
    int pivot = numbers[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (numbers[j] < pivot) {
            i++;
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }
    }
    int temp = numbers[i + 1];
    numbers[i + 1] = numbers[high];
    numbers[high] = temp;
    return (i + 1);
}

void quickSort(int numbers[], int low, int high) {
    if (low < high) {
        int pi = partition(numbers, low, high);

        quickSort(numbers, low, pi - 1);
        quickSort(numbers, pi + 1, high);
    }
}

//-----------------------------------------------------------------------------------------//
//---------------------------------------- MAIN -------------------------------------------//
//-----------------------------------------------------------------------------------------//

// This is the main function where we create our list of numbers and call functions to sort it 

int main() {
    int numbers[range];

    for (int i = 0; i < range; i++) {
        numbers[i] = randomnum();
    }
    
    cout << "Unsorted array:" << endl;
    print(numbers);

    // Uncomment one of the following lines to test the respective sorting algorithm
    //bubblesort(numbers);
    //selectionsort(numbers);
    //insertionsort(numbers);
    //mergeSort(numbers, range);
    //quickSort(numbers, 0, range - 1);

    cout << "Sorted array:" << endl;
    print(numbers);

    return 0;
}
