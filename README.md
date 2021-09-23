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

    10
    3 1 2 8 7 5 9 4 6 0
    1 2 3 7 8 5 9 4 6 0

***Sample Output 1:***

    Insertion Sort
    1 2 3 5 7 8 9 4 6 0

***Sample Input 2:***

    10
    3 1 2 8 7 5 9 4 6 0
    6 4 5 1 0 3 2 7 8 9

***Sample Output 2:***

    Heap Sort
    5 4 3 1 0 2 6 7 8 9
## 7-15 PAT Judge (25 points)
The ranklist of PAT is generated from the status list, which shows the scores of the submissions. This time you are supposed to generate the ranklist for PAT.

***Input Specification:***  
Each input file contains one test case. For each case, the first line contains 3 positive integers, N (≤10<sup>4</sup>), the total number of users, K (≤5), the total number of problems, and M (≤10<sup>5</sup>), the total number of submissions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers `p[i]` (`i`=1, ..., K), where `p[i]` corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submission in the following format:

    user_id problem_id partial_score_obtained

where `partial_score_obtained` is either −1 if the submission cannot even pass the compiler, or is an integer in the range [0, `p[problem_id]`]. All the numbers in a line are separated by a space.

***Output Specification:***  
For each test case, you are supposed to output the ranklist in the following format:

    rank user_id total_score s[1] ... s[K]
where `rank` is calculated according to the `total_score`, and all the users with the same `total_score` obtain the same `rank`; and `s[i]` is the partial score obtained for the `i`-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

***Sample Input:***

    7 4 20
    20 25 25 30
    00002 2 12
    00007 4 17
    00005 1 19
    00007 2 25
    00005 1 20
    00002 2 2
    00005 1 15
    00001 1 18
    00004 3 25
    00002 2 25
    00005 3 22
    00006 4 -1
    00001 2 18
    00002 1 20
    00004 1 15
    00002 4 18
    00001 3 4
    00001 4 2
    00005 2 -1
    00004 2 0

***Sample Output:***

    1 00002 63 20 25 - 18
    2 00005 42 20 0 22 -
    2 00007 42 - 25 - 17
    2 00001 42 18 18 4 2
    5 00004 40 15 0 25 -

## 7-16 Sort with Swap(0, i) (25 points)
Given any permutation of the numbers {0, 1, 2,..., N−1}, it is easy to sort them in increasing order. But what if `Swap(0, *)` is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

    Swap(0, 1) => {4, 1, 2, 0, 3}
    Swap(0, 3) => {4, 1, 2, 3, 0}
    Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

***Input Specification:***  
Each input file contains one test case, which gives a positive N (≤10<sup>5</sup>) followed by a permutation sequence of {0, 1, ..., N−1}. All the numbers in a line are separated by a space.

***Output Specification:***  
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

***Sample Input:***  

    10
    3 5 7 2 6 4 9 0 8 1

***Sample Output:***

    9