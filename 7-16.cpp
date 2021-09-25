/*
7-16 Sort with Swap(0, i) (25 points)
Given any permutation of the numbers {0, 1, 2,..., N−1}, it is easy to sort them in increasing order. 
But what if Swap(0, *) is the ONLY operation that is allowed to use? 
For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:
Each input file contains one test case, which gives a positive N (≤10^5) followed by a permutation sequence of {0, 1, ..., N−1}. All the numbers in a line are separated by a space.

Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10
3 5 7 2 6 4 9 0 8 1

Sample Output:
9

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,cnt=0,input;
    cin>>N;
    int *arr=new int[N];
    int *arr_i=new int[N];
    for (int i = 0; i < N; i++)
    {
        cin>>input;
        arr_i[input]=i;
    }
    int index1,index2;
    bool inc0,flag;
    for (int i = 0; i < N; i++)
    {
        inc0=flag=0;
        while(i!=arr_i[i]){
            if(i==0 || arr_i[i]==0) inc0=1; 
            swap(arr_i[i],arr_i[arr_i[i]]);
            cnt++;
            flag=1;
        }
        if (flag &&!inc0) cnt+=2; //if not involve 0, then swap 0 in, and swap 0 out.
    }
    
    cout<<cnt;
    return 0;
}