/*
7-7 Complete Binary Search Tree (30 points)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:
10
1 2 3 4 5 6 7 8 9 0

Sample Output:
6 3 8 1 5 7 9 0 2 4

*/


#include <iostream>
#include <algorithm>
using namespace std;

void build_cbt(int *list,int *cbt,int start,int end,int root){
    if(start>end) return;
    
    int n=end-start+1;
    int cnt=1,sum=0;
    for(cnt=1;sum+cnt<n;cnt*=2){
        sum+=cnt;
    }
    if((n-sum)<cnt/2){
        cbt[root]=list[n-(sum+1)/2+start];
        build_cbt(list,cbt,start,n-(sum+1)/2+start-1,root*2+1);
        build_cbt(list,cbt,n-(sum+1)/2+start+1,end,root*2+2);
    }else{
        cbt[root]=list[(cnt+sum-1)/2+start];
        build_cbt(list,cbt,start,(cnt+sum-1)/2+start-1,root*2+1);
        build_cbt(list,cbt,(cnt+sum-1)/2+start+1,end,root*2+2);
    }
}

int main(){
    int N;
    cin>>N;
    int *input=new int[N],*cbt=new int[N];
    for (int  i = 0; i < N; i++)
    {
        cin>>input[i];       
    }
    sort(input,input+N,less<int>());
    build_cbt(input,cbt,0,N-1,0);
    for (int i = 0; i < N; i++)
    {
        if(i) cout<<' ';
        cout<<cbt[i];
    }
    return 0;
}