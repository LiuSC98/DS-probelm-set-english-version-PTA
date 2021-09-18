/*
7-12 How Long Does It Take (25 points)
Given the relations of all the activities of a project, you are supposed to find the earliest completion time of the project.

Input Specification:
Each input file contains one test case. Each case starts with a line containing two positive integers N (≤100), 
the number of activity check points (hence it is assumed that the check points are numbered from 0 to N−1), and M, 
the number of activities. Then M lines follow, each gives the description of an activity. For the i-th activity, 
three non-negative numbers are given: S[i], E[i], and L[i], where S[i] is the index of the starting check point, 
E[i] of the ending check point, and L[i] the lasting time of the activity. The numbers in a line are separated by a space.

Output Specification:
For each test case, if the scheduling is possible, print in a line its earliest completion time; or simply output "Impossible".

Sample Input 1:
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

Sample Output 1:
18

Sample Input 2:
4 5
0 1 1
0 2 2
2 1 3
1 3 4
3 2 5

Sample Output 2:
Impossible

*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
#define infinite 65535

typedef struct Node *Ptr2Node;
struct Node
{
    int val;
    Ptr2Node next;
};

struct Qnode
{
    Ptr2Node head,tail;
};

typedef struct Qnode *Queue;

Queue EnQ(int v,Queue Q){
    Ptr2Node tempNode = (Ptr2Node)malloc(sizeof(struct Node));
    tempNode->val=v;
    tempNode->next=NULL;

    if(!Q->head){
        Q->head=Q->tail=tempNode;
    }else{
        Q->tail->next=tempNode;
        Q->tail=tempNode;
    }
    return Q;
}

int DeQ(Queue Q){
    if(!Q->head) return -1;
    int v;
    Ptr2Node tempNode = (Ptr2Node)malloc(sizeof(struct Node));
    tempNode=Q->head;
    v=tempNode->val;
    Q->head=Q->head->next;
    free(tempNode);
    return v;
}

int topoSort(int N, int costMatrix[][MAXN], int indegree[]){
    int cnt=0,earliest[MAXN]={0,},totalTime=0;
    Queue Q = (Queue)malloc(sizeof(struct Qnode));
    Q->head=Q->tail=NULL;

    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            earliest[i]=0;
            EnQ(i,Q);
        }
    }

    int v;
    while(Q->head){
        v=DeQ(Q);
        cnt++;
        for(int i=0;i<N;i++){
            if(costMatrix[v][i]<infinite){
                if(earliest[i]<earliest[v]+costMatrix[v][i]){
                    earliest[i]=earliest[v]+costMatrix[v][i];
                    if(earliest[i]>totalTime) totalTime=earliest[i];
                }
                if(--indegree[i]==0){
                    EnQ(i,Q);
                }
            }
        }
    }
    if(cnt!=N){
        printf("Impossible");
        return -1;
    }
    printf("%d",totalTime);
    return totalTime;
}


int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int costMatrix[MAXN][MAXN]={0,},indegree[MAXN]={0,};

    for(int i=0;i<N;i++){
        indegree[i]=0;
        for(int j=i;j<N;j++){
            costMatrix[i][j]=costMatrix[j][i]=infinite;
        }
    }
    
    int s,e,c;
    
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&s,&e,&c);
        costMatrix[s][e]=c;
        indegree[e]++;
    }
    topoSort(N,costMatrix,indegree);
 
    return 0;
}