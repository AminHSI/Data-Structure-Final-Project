#include <iostream>
#include <random>
#include <string>
#include <array>
#include <algorithm>
#include <memory>
#include <chrono>
using namespace std;

/*
notes
○ Bubble Sort       (functional)
○ Selection Sort    (functional)  
○ Insertion Sort    (functional)
○ Merge Sort        (functional)
○ Quick Sort        (functional) 
○ Heap Sort         (functional)  
○ Shell Sort        (functional)
*/

//------------------------------------- ARRAY-SIZE ----------------------------------------//

int range;//this variable determines the length of our list of numbers

int latency = 0;

//--------------------------- GENERATION-PRINTING-CALCULATION -----------------------------//
//-----------------------------------------------------------------------------------------//

//this function generates a random number in the specified range

int randomnum() {
    random_device rand;
    uniform_int_distribution<int> num(0, range);
    return num(rand);
}

//this is a simple function to print our numbers in order

void print(int(&numbers)[]) {    
    for (int i = 0; i < range; i++) {
        cout << numbers[i] << "-";
    }
}

//this class will calculate the latency of a certain code block

class Timer {
public:
    Timer() {
        starttime = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        stop();
    }
    void stop() {
        auto stoptime = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(starttime).time_since_epoch().count();
        auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(stoptime).time_since_epoch().count();
        auto duration = stop - start;
        latency = duration;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> starttime;
};

//------------------------------------- BUBBLE-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

// Simple but inefficient sorting algorithm.
// Repeatedly steps through the list, compares adjacent elements,
// and swaps them if they are in the wrong order. Best for small datasets or educational purposes.

void bubblesort(int(&numbers)[]) {
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

// Repeatedly finds the minimum element from the unsorted part and puts it at the beginning.
// Also not very efficient for large datasets.

void selectionsort(int(&numbers)[]) {
    for (int i = 0; i < (range - 1); i++) {
        int min = i;
        for (int j = i; j < (range); j++) {
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

// Builds the final sorted array one item at a time.
// More efficient than bubble sort and selection sort for small datasets or nearly sorted data.

void insertionsort(int(&numbers)[]) {
    for (int i = 1; i < range; i++) {
        int index = i;
        while ((index - 1) >= 0 && numbers[index] < numbers[index - 1]) {
            int temp = numbers[index];
            numbers[index] = numbers[index - 1];
            numbers[index - 1] = temp;
            index--;
        }
        i = index;
    }
}

//-------------------------------------- MERGE-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

// A divide-and-conquer algorithm that divides the array into halves, sorts them, and then merges them back together.
// Efficient and stable, with a guaranteed time complexity of O(n log n).

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

// Picks an element as a pivot and partitions the array around the pivot.
// It has an average-case time complexity of O(n log n), but can degrade to O(n^2) if the pivot selection is poor.

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

//--------------------------------------- HEAP-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

// Builds a max heap and then extracts the maximum element one by one to build the sorted array.
// Efficient with a time complexity of O(n log n), but not stable.

void heap(int numbers[], int n, int i) {
    int root = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && numbers[l] > numbers[root]) {
        root = l;
    }
    if (r < n && numbers[r] > numbers[root]) {
        root = r;
    }
    if (root != i) {
        swap(numbers[i], numbers[root]);
        heap(numbers, n, root);
    }
}
void heapSort(int(&numbers)[]) {
    for (int i = range / 2 - 1; i >= 0; i--) {
        heap(numbers, range, i);
    }
    for (int i = range - 1; i > 0; i--) {
        swap(numbers[0], numbers[i]);
        heap(numbers, i, 0);
    }
}

//-------------------------------------- SHELL-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

// An extension of insertion sort that allows the exchange of far-apart elements to move elements quickly to their final position.
// It significantly improves the efficiency over insertion sort for larger datasets.

void shellSort(int(&numbers)[]) {
    for (int n = range / 2; n > 0; n /= 2) {
        for (int i = n; i < range; i += 1) {
            int temp = numbers[i];
            int j;		 
            for (j = i; j >= n && numbers[j - n] > temp; j -= n) {
                numbers[j] = numbers[j - n];
            }
            numbers[j] = temp;
        }
    }
}

//-----------------------------------------------------------------------------------------//
//---------------------------------------- M A I N ----------------------------------------//
//-----------------------------------------------------------------------------------------//

//this is the main function where we create our list of numbers and call functions to sort it 

int main() {
    cout << "welcome\nenter your preferred size for the dataset: ";
    int size;
    cin >> size; range = size;   
    int numbers[range];
    int originalnumbers[range];
    for (int i = 0; i < range; i++) {
        originalnumbers[i] = numbers[i] = randomnum();
    }

    {
        Timer timer;
        bubblesort(numbers);     
    }
    cout << "\nthe latency of bubble sorting function was: " << latency << " microseconds" << endl;
    for (int i = 0; i < range; i++) {
        numbers[i] = originalnumbers[i];
    }
    {
        Timer timer;
        selectionsort(numbers); 
    }
    cout << "the latency of selection sorting function was: " << latency << " microseconds" << endl;
    for (int i = 0; i < range; i++) {
        numbers[i] = originalnumbers[i];
    }
    {
        Timer timer;
        insertionsort(numbers);
    }
    cout << "the latency of insertion sorting function was: " << latency << " microseconds" << endl;
    for (int i = 0; i < range; i++) {
        numbers[i] = originalnumbers[i];
    }
    {
        Timer timer;
        heapSort(numbers);
    }
    cout << "the latency of heap sorting function was: " << latency << " microseconds" << endl;
    for (int i = 0; i < range; i++) {
        numbers[i] = originalnumbers[i];
    }
    {
        Timer timer;
        shellSort(numbers);
    }
    cout << "the latency of shell sorting function was: " << latency << " microseconds" << endl;
    for (int i = 0; i < range; i++) {
        numbers[i] = originalnumbers[i];
    }
    {
        Timer timer;
        mergeSort(numbers, range);  
    }
    cout << "the latency of merge sorting function was: " << latency << " microseconds" << endl;
    for (int i = 0; i < range; i++) {
        numbers[i] = originalnumbers[i];
    }
    {
        Timer timer;
        quickSort(numbers, 0, range - 1);      
    }
    cout << "the latency of quick sorting function was: " << latency << " microseconds" << endl;

    cout << "\nwould you like to see the original and sorted arrays?(y/n) ";
    char choice; cin >> choice;
    if (choice=='y' or choice=='Y') {
        cout << "\noriginal array: [-";
        print(originalnumbers);
        cout << "]\n\nsorted array: [-";
        print(numbers); cout << "]";
    }
    return 0;
}
