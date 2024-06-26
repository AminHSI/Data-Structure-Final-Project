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
○ Radix Sort 
○ Shell Sort        (functional)
*/

//------------------------------------- ARRAY-SIZE ----------------------------------------//

//this determines the length of our list of numbers
int range;
int latency = 0;

//--------------------------- GENERATION-PRINTING-CALCULATION -----------------------------//
//-----------------------------------------------------------------------------------------//

//this function generates random numbers in the specified range

int randomnum() {
    random_device rand;
    uniform_int_distribution<int> num(0,range);
    return num(rand);
}

//this is a simple function to print our numbers in order
void print(int(&numbers)[]) {    
    for(int i=0 ; i<range ; i++) {
        cout << numbers[i] << " ";
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
			//cout << "latency of the selected sorting function was: " << duration << " microseconds";
            latency = duration;
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> starttime;
};

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
        while((index-1) >= 0 && numbers[index] < numbers[index-1]) {
            int temp = numbers[index];
            numbers[index] = numbers[index-1];
            numbers[index-1] = temp;
            index--;
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

//--------------------------------------- HEAP-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

//first version of heapsort

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

//-------------------------------------- SHELL-SORT ---------------------------------------//
//-----------------------------------------------------------------------------------------//

//shell sort function done

void shellSort(int(&numbers)[]) {
	for (int n = range/2; n > 0; n /= 2) {
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
    cin >> size;
    range = size;
    int numbers[range];
    for(int i=0 ; i<range ; i++) {
        numbers[i] = randomnum();
    }

    cout << "here is your original array: [ ";
    print(numbers);
    cout <<"]"<<endl;
    cout << endl;
    {
        Timer timer;
        //bubblesort(numbers);
        //selectionsort(numbers);
        //insertionsort(numbers);
        //heapSort(numbers);
        //shellSort(numbers);
        //mergeSort(numbers, range);
        //quickSort(numbers, 0, range - 1);      
    }
    cout << "sorted array: [ ";
    print(numbers);
    cout <<"]"<<endl;
    cout << "the latency of this sorting function was: "<<latency<<" microseconds";
    return 0;
}

