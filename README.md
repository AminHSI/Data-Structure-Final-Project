# Sorting Algorithms in C++

This project implements and compares various sorting algorithms in C++. The algorithms included are:

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Shell Sort

Each sorting algorithm is measured for its latency, which is the time it takes to sort a randomly generated list of numbers.

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
```


