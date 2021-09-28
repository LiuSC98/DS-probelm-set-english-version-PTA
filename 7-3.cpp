/*
7-3 Pop Sequence (25 points)
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains 3 numbers (all no more than 1000): 
M (the maximum capacity of the stack), 
N (the length of push sequence), 
and K (the number of pop sequences to be checked). 
Then K lines follow, each contains a pop sequence of N numbers. 
All the numbers in a line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

Sample Output:
YES
NO
NO
YES
NO

*/

#include <iostream>

using namespace std;

bool isStackPopSeq(int list[],int listSize,int stackSize){
    int p2list=0,p2stack=0;
    int *stk=new int[stackSize+1];
    stk[0]=0;

    for(int i=1;i<=listSize;i++){
        if((++p2stack)>stackSize) break;
        stk[p2stack]=i;
        while (stk[p2stack]==list[p2list] && p2stack>0 && p2list<listSize)
        {
            p2stack--;
            p2list++;
        }
    }
    delete[] stk;
    if(p2stack==0 && p2list==listSize) return 1;
    else return 0;
}


int main(){
    int M,N,K;
    cin>>M>>N>>K;
    int *list =new int[N];

    while (K--)
    {
        for(int i = 0; i < N; i++) cin>>list[i];
        if(isStackPopSeq(list,N,M)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}