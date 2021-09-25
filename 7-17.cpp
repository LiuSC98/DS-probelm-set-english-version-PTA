/*
7-17 Hashing (25 points)
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, 
and output the positions of the input numbers. 
The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. 
Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. 
If the maximum size given by the user is not prime, 
you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:
Each input file contains one test case. 
For each case, the first line contains two positive numbers: MSize (≤10^4) and N (≤MSize) 
which are the user-defined table size and the number of input numbers, respectively. 
Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. 
All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. 
In case it is impossible to insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15

Sample Output:
0 1 4 -

*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n<2) return 0;
    if(n%2==0 && n>2) return 0;
    for (int i = 3; i < sqrt(n); i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
int minPrime(int n){
    if(n==1)return 2;
    if(n%2==0 && n!=2) n++; 
    while (!isPrime(n))
    {
        n+=2;
    }
    return n;
}

int insert(int *hashtable,int x,int size){
    int h=x%size;
    int newh=h;
    int i=0;
    while (hashtable[newh]!=0 && i<size)
    {
        i++;
        newh=(h+i*i)%size;
    }
    if(hashtable[newh]==0){
        hashtable[newh]=x;
        return newh;
    }
    return -1;
}

int nextPrime(int n) {
     if (n == 1) return 2; 
     int i = n % 2 ? n + 2 : n + 1;
     while (true) {
         int j = (int)sqrt(i);
         for ( ; j > 2; j--) {
             if (i % j == 0) break;
         }
         if (j == 2) break;
         i += 2;
     }
    return i;
}

int main(){
    int Msize,N;
    cin>>Msize>>N;
    
    Msize=minPrime(Msize);
    
    int *hashtable= new int[Msize];
    for (int i = 0; i < Msize; i++)
    {
        hashtable[i]=0;
    }
    
    int insert_res,input;
    for (int i = 0; i < N; i++)
    {
        cin>>input;
        insert_res=insert(hashtable,input,Msize);
        if(i) cout<<' ';
        if(insert_res==-1) cout<<'-';
        else cout<<insert_res;
    }

    delete[] hashtable;
    return 0;
}