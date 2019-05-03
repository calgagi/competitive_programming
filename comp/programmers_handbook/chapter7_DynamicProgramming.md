Chapter 7: Dynamic programming
===
 * Technique that combines greedy and complete search
 * Can be applied if problem can be divided into overlapping subproblems
 * Used for counting solutions + optimal solution

Coin problem
---
 * Recursively, if coins = {1, 3, 4}, use `solve(x) = min(solve(x-1)+1, solve(x-3)+1, solve(x-4)+1);`
 * `INF` in C++ denotes infinity!
 * Use memoization to speed things up. Memoization just remembers solutions to past sub-problems so we don't have to calculate it again.
 * Both the recursive memoization problem AND the iterative version are DP. 
 * Iteration is better though since it's shorter and often simpler to read.
 * In order to find the solution as well as the answer, use another array to keep track of the "parent" index.
 * In order to count the number of solutions, use another array as well that stores the count.

Longest increasing subsequence
---
 * Longest subarray that increases between elements
 * Use DP array that keeps track of length. Search for largest length where array[curr] > array[i]. O(n<sup>2</sup>). 
 * There is a O(nlogn) solution though that uses binary search.
