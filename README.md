# DS-probelm-set-english-version-PTA
data structure problem set (pintia.cn)
## 7-12 How Long Does It Take (25 points)
Given the relations of all the activities of a project, you are supposed to find the earliest completion time of the project.

***Input Specification:***  
Each input file contains one test case. Each case starts with a line containing two positive integers N (≤100), the number of activity check points (hence it is assumed that the check points are numbered from 0 to N−1), and M, the number of activities. Then M lines follow, each gives the description of an activity. For the i-th activity, three non-negative numbers are given: S[i], E[i], and L[i], where S[i] is the index of the starting check point, E[i] of the ending check point, and L[i] the lasting time of the activity. The numbers in a line are separated by a space.

***Output Specification:***  
For each test case, if the scheduling is possible, print in a line its earliest completion time; or simply output "Impossible".

***Sample Input 1:***

    9 12
    0 1 6
    0 2 4
    0 3 5
    1 4 1
    2 4 1
    3 5 2
    5 4 0
    4 6 9
    4 7 7
    5 7 4
    6 8 2
    7 8 4

***Sample Output 1:***

    18

***Sample Input 2:***

    4 5
    0 1 1
    0 2 2
    2 1 3
    1 3 4
    3 2 5
***Sample Output 2:***
    
    Impossible

## 7-13 Insert or Merge (25 points)
According to Wikipedia:  

**Insertion sort** iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.  

**Merge sort** works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.  

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

***Input Specification:***  
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

***Output Specification:***  
For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

***Sample Input 1:***
    
    10
    3 1 2 8 7 5 9 4 6 0
    1 2 3 7 8 5 9 4 6 0

***Sample Output 1:***

    Insertion Sort
    1 2 3 5 7 8 9 4 6 0

***Sample Input 2:***

    10
    3 1 2 8 7 5 9 4 0 6
    1 3 2 8 5 7 4 9 0 6

***Sample Output 2:***

    Merge Sort
    1 2 3 8 4 5 7 9 0 6

## 7-14 Insertion or Heap Sort (25 points)
According to Wikipedia:  
**Insertion sort** iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.  

**Heap sort** divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

***Input Specification:***  
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

***Output Specification:***  
For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resulting sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

***Sample Input 1:***  
```
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
```
***Sample Output 1:***
```
Insertion Sort
1 2 3 5 7 8 9 4 6 0
```
***Sample Input 2:***
```
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
```
***Sample Output 2:***
```
Heap Sort
5 4 3 1 0 2 6 7 8 9
```