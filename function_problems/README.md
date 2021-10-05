## 6-1 Deque (25 points)
A "deque" is a data structure consisting of a list of items, on which the following operations are possible:

- Push(X,D): Insert item X on the front end of deque D.
- Pop(D): Remove the front item from deque D and return it.
- Inject(X,D): Insert item X on the rear end of deque D.
- Eject(D): Remove the rear item from deque D and return it. Write routines to support the deque that take O(1) time per operation.

***Format of functions:***  
``` C
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );
```
where `Deque` is defined as the following:
``` C
typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
```
Here the deque is implemented by a doubly linked list with a header. `Front` and `Rear` point to the two ends of the deque respectively. `Front` always points to the header. The deque is empty when `Front` and `Rear` both point to the same dummy header. Note: `Push` and `Inject` are supposed to return 1 if the operations can be done successfully, or 0 if fail. If the deque is empty, `Pop` and `Eject` must return `ERROR` which is defined by the judge program.

***Sample program of judge:***
``` c
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
```
***Sample Input:***

    Pop
    Inject 1
    Pop
    Eject
    Push 1
    Push 2
    Eject
    Inject 3
    End

***Sample Output:***

    Deque is Empty!
    Deque is Empty!
    Inside Deque: 2 3

## 6-2 Two Stacks In One Array (20 points)
Write routines to implement two stacks using only one array. Your stack routines should not declare an overflow unless every slot in the array is used.

***Format of functions:***
``` C
Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );
```

where `int Stacknum` is the index of a stack which is either 1 or 2; `int MaxElements` is the size of the stack array; and `Stack` is defined as the following:

``` c
typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
}
```
Note: `Push` is supposed to return 1 if the operation can be done successfully, or 0 if fails. If the stack is empty, `Top_Pop` must return `ERROR` which is defined by the judge program.

***Sample program of judge:***
``` C
#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case pop:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */
```

***Sample Input:***

    5
    Push 1 1
    Pop 2
    Push 2 11
    Push 1 2
    Push 2 12
    Pop 1
    Push 2 13
    Push 2 14
    Push 1 3
    Pop 2
    End

***Sample Output:***

    Stack 2 is Empty!
    Stack 1 is Full!
    Pop from Stack 1: 1
    Pop from Stack 2: 13 12 11

## 6-3 Add Two Polynomials (20 points)
Write a function to add two polynomials. Do not destroy the input. Use a linked list implementation with a dummy head node. Note: The zero polynomial is represented by an empty list with only the dummy head node.

***Format of functions:***
``` C
Polynomial Add( Polynomial a, Polynomial b );
```
where `Polynomial` is defined as the following:

```C
typedef struct Node *PtrToNode;
struct Node {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;
/* Nodes are sorted in decreasing order of exponents.*/ 
```
The function `Add` is supposed to return a polynomial which is the sum of `a` and `b`.


***Sample program of judge:***
``` C
#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */
```

***Sample Input:***

    4
    3 4 -5 2 6 1 -2 0
    3
    5 20 -7 4 3 1

***Sample Output:***

    5 20 -4 4 -5 2 9 1 -2 0

## 6-4 Reverse Linked List (20 points)
Write a nonrecursive procedure to reverse a singly linked list in O(N) time using constant extra space.

***Format of functions:***
``` C
List Reverse( List L );
```
where `List` is defined as the following:
```C
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};
```
The function `Reverse` is supposed to return the reverse linked list of `L`, with a dummy header.

***Sample program of judge:***
```C
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
```

***Sample Input:***

    5
    1 3 4 5 2

***Sample Output:***

    2 5 4 3 1
    2 5 4 3 1