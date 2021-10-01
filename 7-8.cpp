/*
7-8 File Transfer (25 points)
We have a network of computers and a list of bi-directional connections. Each of these connections allows a file transfer from one computer to another. Is it possible to send a file from any computer on the network to any other?

Input Specification:
Each input file contains one test case. For each test case, the first line contains N (2≤N≤10^4), the total number of computers in a network. Each computer in the network is then represented by a positive integer between 1 and N. Then in the following lines, the input is given in the format:

I c1 c2  
where I stands for inputting a connection between c1 and c2; or

C c1 c2    
where C stands for checking if it is possible to transfer files between c1 and c2; or

S
where S stands for stopping this case.

Output Specification:
For each C case, print in one line the word "yes" or "no" if it is possible or impossible to transfer files between c1 and c2, respectively. At the end of each case, print in one line "The network is connected." if there is a path between any pair of computers; or "There are k components." where k is the number of connected components in this network.

Sample Input 1:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S

Sample Output 1:
no
no
yes
There are 2 components.

Sample Input 2:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S

Sample Output 2:
no
no
yes
yes
The network is connected.

*/

#include <iostream>
using namespace std;

int connect(int collect[],int node1,int node2){ // use a negative number to record the size of collection.
    while (collect[node1]>0) node1=collect[node1];
    while (collect[node2]>0) node2=collect[node2];
    if(node1==node2)return collect[node1];
    else{
        if(collect[node1]<=collect[node2]){
            collect[node1]+=collect[node2];
            collect[node2]=node1;
            return collect[node1];
        }else{
            collect[node2]+=collect[node1];
            collect[node1]=node2;
            return collect[node2];
        }
    }
}


bool check(int collect[],int node1,int node2){
    while(collect[node1]>0) node1=collect[node1];
    while(collect[node2]>0) node2=collect[node2];
    if(node1==node2) return 1;
    return 0;
}


int main(){
    int N;
    cin>>N;
    int *collection=new int[N+1];
    for (int i = 1; i <= N; i++) collection[i]=-1;
    
    char C;
    int node1,node2;
    while (1)
    {
        cin>>C;
        if(C=='S') break;
        else if(C=='I'){
            cin>>node1>>node2;
            connect(collection,node1,node2);
        }
        else if(C=='C'){
            cin>>node1>>node2;
            if(check(collection,node1,node2)) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }

    int cnt=0;
    for (int i = 1; i <= N; i++)
    {
        if(collection[i]<0) cnt++;
    }
    if(cnt==1) cout<<"The network is connected.";
    else cout<<"There are "<<cnt<<" components.";
    
    return 0;
}