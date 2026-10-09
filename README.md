# K-Way Merge Using Min Heap vs Pairwise Merge in C

## 1. Introduction
This project merges three sorted transaction lists into one sorted list using two algorithms: Min Heap merging and Pairwise merging.

## 2. Input
- L1 = 10, 30, 50, 70
- L2 = 20, 40, 60, 80
- L3 = 15, 35, 55, 75

## 3. Objectives
- Implement K-way merging using a Min Heap.
- Display heap states during execution.
- Implement pairwise merging.
- Count comparisons and compare both algorithms.

## 4. Algorithms

### Min Heap
1. Insert the first element of every list into the heap.
2. Remove the smallest element.
3. Add it to the result.
4. Insert the next element from the same list.
5. Repeat until the heap is empty.

### Pairwise Merge
1. Merge L1 with L2.
2. Merge the result with L3.
3. Store the final sorted list.

## 5. Expected Output

10 15 20 30 35 40 50 55 60 70 75 80

## 6. Complexity Analysis

| Parameter | Min Heap | Pairwise |
|---|---|---|
| Time complexity | O(N log K) | O(NK), general bound |
| Auxiliary space | O(K) | O(N) |
| Heap size | Maximum K | Not applicable |
| Comparisons | Counted by program | Counted by program |

Here, N is the total number of elements and K is the number of sorted lists.

## 7. Conclusion
Both algorithms produce the same sorted output. Pairwise merging is easy to understand, but Min Heap merging is generally more efficient when the number of sorted lists increases.
