/*
7-18 Hashing - Hard Version (30 points)
Given a hash table of size N, we can define a hash function H(x)=x%N. 
Suppose that the linear probing is used to solve collisions, 
we can easily obtain the status of the hash table with a given sequence of input numbers.

However, now you are asked to solve the reversed problem: 
reconstruct the input sequence from the given status of the hash table. 
Whenever there are multiple choices, the smallest number is always taken.

Input Specification:
Each input file contains one test case. 
For each test case, the first line contains a positive integer N (≤1000), which is the size of the hash table. 
The next line contains N integers, separated by a space. A negative integer represents an empty cell in the hash table. 
It is guaranteed that all the non-negative integers are distinct in the table.

Output Specification:
For each test case, print a line that contains the input sequence, with the numbers separated by a space. 
Notice that there must be no extra space at the end of each line.

Sample Input:
11
33 1 13 12 34 38 27 22 32 -1 21

Sample Output:
1 13 12 21 33 34 38 27 22 32

*/


#include <iostream>
#include <algorithm> 
#define maxN 1000
#define maxInt 2147483647
using namespace std;

struct hashTable
{
    int tableSize;
    int *table;
}inputTable;

int hashing(int x,int size){
    return x % size;
}

bool cmp(int x,int y){
    return inputTable.table[x]>inputTable.table[y]? 1:0;
}

void topologicalSort(bool matrix[][maxN],int indegree[],hashTable HT){
    
    int size=HT.tableSize;
    int *arr = new int[size];
    int cnt=0;
    for (int i = 0; i < size; i++)
    {
        if(!indegree[i] && HT.table[i]>=0){
            arr[cnt]=i;
            cnt++;
        }
    }
    make_heap(arr,arr+cnt,cmp);
    int top;
    bool flag=0;
    while (cnt)
    {
        top=arr[0];
        if(flag) cout<<' ';
        else flag=1;
        cout<<HT.table[top];
        pop_heap(arr,arr+cnt,cmp);
        cnt--;
        for (int i = 0; i < size; i++)
        {
            if(matrix[top][i]){
                if(--indegree[i]==0){
                    arr[cnt]=i;
                    cnt++;
                    push_heap(arr,arr+cnt,cmp);
                }
            }
        }
    }
    
    delete[] arr;    
}

int remainder(int x,int size){
    if(x>=0) return x%size;
    while (x<0) x+=size;
    return x;
}

void findMatrix(hashTable HT,bool Matrix[][maxN],int indegree[]){
    int hash_res;
    for (int i = 0; i < HT.tableSize; i++)
    {
        if(HT.table[i]<0) continue;
        hash_res=hashing(HT.table[i],HT.tableSize);
        if(i!=hash_res){
            while (hash_res!=i)
            {
                Matrix[hash_res][i]=1;
                hash_res=(hash_res+1)%HT.tableSize;
                indegree[i]++;
            }
        } 
    }
    
}

int main(){
    int N;
    cin>>N;
    inputTable.tableSize=N;
    inputTable.table=new int[N];

    bool Matrix[maxN][maxN]={0,};
    int indegree[maxN]={0,};

    for (int i = 0; i < N; i++)
    {
        cin>>inputTable.table[i];
    }
    findMatrix(inputTable,Matrix,indegree);
    topologicalSort(Matrix,indegree,inputTable);
    

    return 0;
}