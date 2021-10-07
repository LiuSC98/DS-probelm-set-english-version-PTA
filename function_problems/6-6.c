#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */
void PrintNode( Tree NodePtr )
{
   printf(" %d", NodePtr->Element);
}

void Level_order ( Tree T, void (*visit)(Tree ThisNode) );

int main()
{
    Tree T = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}

/* Your function will be put here */
typedef struct QueueNode *Ptr2QNode;
struct QueueNode{
    Tree Ptr2TreeNode;
    Ptr2QNode next;
};
typedef struct QueueHead *Queue;
struct QueueHead{
    Ptr2QNode front,rear;
};


Queue CreatQ(){
    Ptr2QNode Qstart = (Ptr2QNode)malloc(sizeof(struct QueueNode));
    Qstart->next=NULL;
    Qstart->Ptr2TreeNode=NULL;

    Queue Q = (Queue)malloc(sizeof(struct QueueHead));
    Q->front=Q->rear=Qstart;
    return Q;
}

Queue InsertQ(Queue Q, Tree T){
    Ptr2QNode TempNode =(Ptr2QNode)malloc(sizeof(struct QueueNode));
    TempNode->Ptr2TreeNode=T;
    TempNode->next=NULL;

    Q->rear->next=TempNode;
    Q->rear=TempNode;
    return Q;
}

int isEmptyQ(Queue Q){
    return Q->front==Q->rear;
}

Tree PopQ(Queue Q){
    if(isEmptyQ(Q)) return NULL;
    else {
        Ptr2QNode TempNode;
        TempNode=Q->front->next;
        Tree T=TempNode->Ptr2TreeNode;
        Q->front->next=TempNode->next;
        if(Q->rear==TempNode) Q->rear=Q->front;
        free(TempNode);
        return T;
    } 
}

void Level_order ( Tree T, void (*visit)(Tree ThisNode) ){
    if(!T) return;
    Queue Q=CreatQ();
    Q=InsertQ(Q,T);
    Tree tempTree;
    while (!isEmptyQ(Q))
    {
        tempTree=PopQ(Q);
        visit(tempTree);
        if(tempTree->Left) Q=InsertQ(Q,tempTree->Left);
        if(tempTree->Right) Q=InsertQ(Q,tempTree->Right);
    }
}