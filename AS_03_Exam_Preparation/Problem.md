### Programming Assignment #3
[Problem](Problem.md)
# Exam Preparation

## Problem Description
You are preparing for an important exam, and you have decided to manage your sleep
schedule to get the most out of your time.

You have decided to measure you progress by an integer describing the remaining
number of materials you need to finish reading. Initially, this number is measured as
W units.

You have N days to prepare the exam. However, since you are a busy person, for each
day you only have the choice of either not preparing the exam or sacrificing sleep.

For each day you study, you will reduce some constant number A from the number of
remaining materials. (Note it is valid to have a negative number for the remaining
materials at any moment, as it means you’ve done some work ahead of your schedule)

Everybody knows that bad sleep management leads to memory loss. Taking this into
account, if you have not been sleeping for X days in a row (including this very day that
you have decided to study), in the end of this day the number of remaining materials
will be increased by X * B, where B is some constant factor.

Also, you are an anxious person. Specifically, if you have decided to sleep in the i’th
day, you would start to think that you need to do more work, and the number of
remaining materials will be increased by D[i].

Minimize the number of remaining materials in the end of the N’th day.



## I/O Format
Use standard I/O. (stdin, stdout)
### <b>Input</b>

The 1st line contains four integers N , A ,B,W, see the definitions in the problem
description.

Then there is 1 line, with N integers each separated by a whitespace, the i’th of which
describes D[i]. 

## <b>Output</b>
Output the minimum number of remaining materials in the end of the N’th day,
followed by a newline. Do not print anything else, such as “Input/Output”.

#### <b>Examples</b>
Input 1<br>
4 1 0 4<br>
10 10 10 10<br>

Output 1<br>
0<br>

Input 2<br>
2 5 2 0<br>
0 6<br>

Output 2<br>
-4


