#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* Your function will be put here */
List Reverse( List L ){
    if(!L) return L;
    List nodeAfterHead=L->Next;
    if(!nodeAfterHead)return L;
    List head=L->Next->Next;
    if(!head) return L;
    nodeAfterHead->Next=NULL;
    List nodeBeforeHead = head->Next;

    while (nodeBeforeHead)
    {
        head->Next=nodeAfterHead;
        nodeAfterHead=head;
        head=nodeBeforeHead;
        nodeBeforeHead=nodeBeforeHead->Next;
    }
    head->Next=nodeAfterHead;
    L->Next=head;
    return L;
}