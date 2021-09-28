/*
7-4 List Leaves (25 points)
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

Sample Output:
4 1 5

*/


#include <iostream>
#include <queue>
using namespace std;


struct listNode{
    int left,right,parent;
};


inline int findRoot(listNode *list, int listSize){
    for (int i = 0; i < listSize; i++)
    {
        if(list[i].parent==-1) return i;
    }
    return -1;
}

void findLeves(listNode *list, int listSize,int root){
    queue<int> q;
    q.push(root);
    int tempNode;
    bool spaceFlag=0;
    while (!q.empty())
    {
        tempNode=q.front();
        q.pop();
        if(list[tempNode].left==-1 && list[tempNode].right==-1) {
            if(spaceFlag) cout<<' ';
            else spaceFlag=1;
            cout<<tempNode;
        }
        else{
            if(list[tempNode].left!=-1) q.push(list[tempNode].left);
            if(list[tempNode].right!=-1) q.push(list[tempNode].right);
        }
    }
}

int main(){
    int N;
    cin>>N;
    listNode *list=new listNode[N];

    for (int i = 0; i < N; i++)
    {
        list[i].left=list[i].right=list[i].parent=-1;
    }
    char c1,c2;
    for (int i = 0; i < N; i++)
    {
        cin>>c1>>c2;
        if(c1!='-') {
            list[i].left=c1-'0';
            list[list[i].left].parent=i;
        }
        if(c2!='-') {
            list[i].right=c2-'0';
            list[list[i].right].parent=i;
        }
    }

    int root=findRoot(list,N);

    findLeves(list,N,root);
    
    return 0;
}