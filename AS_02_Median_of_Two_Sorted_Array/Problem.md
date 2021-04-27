### Programming Assignment #2
[Problem](Problem.md)
# The Median of Two Sorted Array

## Problem Description
There are 2 sorted arrays A and B of size n each, your task is to find the median
of the array obtained after merging the above 2 arrays (i.e. array of length 2n).
The median of an array is defined as the mean of the two middlemost elements
in the array if the array’s length is even.

    For example, given that
    A = {1, 12, 15, 26, 38} and B = {2, 13, 17, 30, 45},
    the merged array will be
    {1, 2, 12, 13, 15, 17, 26, 30, 38, 45}.
    The two middlemost elements are 15 and 17, so the median of the merged array
    should be (15 + 17)/2 = 16.
It is easy to come up with an algorithm that runs in 𝐎(𝒏 𝐥𝐠𝒏) or 𝐎(𝒏) to solve this
problem. However, in this assignment, you need to develop another algorithm that runs
in 𝐎(𝐥𝐠𝒏).
Implement two version of algorithm to find the median of two sorted arrays, one
runs in 𝐎(𝒏 𝐥𝐠 𝒏) or 𝐎(𝒏) and the other runs in 𝐎(𝐥𝐠𝒏).


## I/O Format
Use standard I/O. (stdin, stdout)
### <b>Input</b>

The 1st line contains one integer N (N ≥ 1), representing the length of the arrays.

The 2nd line has N integers, representing the elements of one array 

the 3rd line
also has N integers, representing the elements of the other array.


## <b>Output</b>
Output the median of the two arrays and a new line after it.
    
Note that if the median you get is not integer, round it down to the nearest integer.
    
    For example, A = {2, 10} and B = {7, 16}, the median should be (7 + 10) / 2 = 8.5
    → 8 (rounded down).

#### <b>Examples</b>
Input 1<br>
5<br>
1 12 15 26 38<br>
2 13 17 30 45<br>

Output 1<br>
16<br>

Input 2<br>
2<br>
2 10<br>
7 16<br>

Output 2<br>
8<br>


