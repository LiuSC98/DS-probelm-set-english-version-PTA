#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */

Deque CreateDeque(){
    PtrToNode dummyHeader=(PtrToNode)malloc(sizeof(struct Node));
    dummyHeader->Element=-1;
    dummyHeader->Last=dummyHeader->Next=NULL;
    Deque QHead=(Deque)malloc(sizeof(struct DequeRecord));
    QHead->Front=QHead->Rear=dummyHeader;
    return QHead;
}

int Push( ElementType X, Deque D ){
    PtrToNode temp=(PtrToNode)malloc(sizeof(struct Node));
    if(!temp) return 0;
    temp->Last=D->Front;
    temp->Next=temp->Last->Next;
    temp->Element=X;
    D->Front->Next=temp;
    if(D->Rear==D->Front){
        D->Rear=temp;
    }else{
        temp->Next->Last=temp;
    }
    return 1;
}

ElementType Pop( Deque D ){
    if(D->Rear==D->Front) return ERROR;
    PtrToNode temp=D->Front->Next;
    D->Front->Next=temp->Next;
    ElementType x=temp->Element;
    if(D->Rear->Last==D->Front){
        D->Rear=D->Front;
    }else{
        temp->Next->Last=temp->Last;
    }
    free(temp);
    return x;
}

int Inject( ElementType X, Deque D ){
    PtrToNode temp=(PtrToNode)malloc(sizeof(struct Node));
    if(!temp) return 0;
    temp->Element=X;
    D->Rear->Next=temp;
    temp->Last=D->Rear;
    D->Rear=temp;
    D->Rear->Next=NULL;
    return 1;
}

ElementType Eject( Deque D ){
    if(D->Rear==D->Front) return ERROR;
    PtrToNode temp=D->Rear;
    D->Rear=D->Rear->Last;
    D->Rear->Next=NULL;
    ElementType x=temp->Element;
    free(temp);
    return x;
}