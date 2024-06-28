# Sorting Algorithms in C++

This project implements and compares various sorting algorithms in C++. The algorithms included are:

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Shell Sort
- Radix Sort

Each sorting algorithm is measured for its latency, which is the time it takes to sort a randomly generated list of numbers.

you can also find details and demonstrations for each sorting algorithm inside the code by referring to the notes above all sorting functions.

## Getting Started

### Prerequisites

To compile and run this project, you will need:

- A C++ compiler (e.g., g++)
- C++11 or later

### Compiling the Code

To compile the code, use the following command:

```sh
g++ -std=c++11 -o sorting main.cpp
```

### Running the Code

After compiling, you can run the executable:
```sh
./sorting
```

You will be prompted to enter the size of the dataset you want to sort. The program will then generate a list of random numbers and sort it using each of the implemented algorithms, printing the latency for each one.

### Example

```yaml
welcome
enter your preferred size for the dataset: 1000
the latency of bubble sorting function was: 12345 microseconds
the latency of selection sorting function was: 6789 microseconds
the latency of insertion sorting function was: 4567 microseconds
the latency of heap sorting function was: 3456 microseconds
the latency of shell sorting function was: 2345 microseconds
the latency of merge sorting function was: 1234 microseconds
the latency of quick sorting function was: 567 microseconds
the latency of radix sorting function was: 217 microseconds
```

You will also be given the option to print both the original and sorted datasets. Note that printing a very large dataset can be a bit messy.

```yaml
would you like to see the original and sorted arrays?(y/n) y

)=> original array: [ 1148 254 8211 6785 9791 4349 829 6550 1923 2096 ]

)=> sorted array: [ 254 829 1148 1923 2096 4349 6550 6785 8211 9791 ]
```