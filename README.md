# SortAndSearch
This project implements sorting and searching algorithms.

## Introduction
This code was designed to demonstrate the implementation of various sorting and searching algorithms. Thanks to that, we are able to explore Insertion Sort, Selection Sort, Merge Sort, and Quick Sort, each with its distinct approach to rearranging elements in an array. Additionally, two algorithms for searching through arrays, Sequential Search and Binary Search, were implemented.

### Sorting Algorithms
1. Insertion Sort: This algorithm builds the sorted list one element at a time. The algorithm repeatedly inserts the next element into its correct position among the already sorted elements. Time complexity: O(n²) in the worst case.
2. Selection Sort: Selection Sort repeatedly selects the smallest remaining element and places it in its correct position. Time complexity: O(n²).
3. Merge Sort: A divide-and-conquer algorithm, Merge Sort recursively splits the array into halves, sorts each half, and then merges the sorted halves together. Time complexity: O(n log n).
4. Quick Sort: Another divide-and-conquer algorithm, Quick Sort partitions the array around a pivot element, recursively sorting the subarrays. Time complexity: O(n log n) on average, O(n²) in the worst case.

Each of these sorting functions returns the number of comparisons made, which helps in analyzing their relative efficiency when sorting random data.

### Searching Algorithms
1. Sequential Search: This naive search method traverses the array linearly until the target value is found or all elements have been checked. Time complexity: O(n).
2. Binary Search: Binary Search works recursively dividing the array in half until the target element is found or the search space is exhausted. Time complexity: O(log n).

### Main Program
The main program creates a random array, applies each sorting algorithm, and prints the sorted array, along with the number of comparisons made and the time taken for each sorting method. It also performs both Sequential Search and Binary Search on the sorted arrays, displaying the results and the number of comparisons.

## Conclusion
This project highlights the performance characteristics of different sorting and searching algorithms. While simple algorithms like Insertion Sort and Selection Sort perform poorly on large datasets (due to their O(n²) complexity), more advanced algorithms like Merge Sort and Quick Sort offer significantly better performance with O(n log n) complexity. Similarly, Binary Search demonstrates how sorted data can dramatically improve search efficiency.
