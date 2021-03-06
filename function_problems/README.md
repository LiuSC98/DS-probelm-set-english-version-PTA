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

## 6-5 Evaluate Postfix Expression (25 points)
Write a program to evaluate a postfix expression. You only have to handle four kinds of operators: +, -, x, and /.

***Format of functions:***
```C
ElementType EvalPostfix( char *expr );
```
where `expr` points to a string that stores the postfix expression. It is guaranteed that there is exactly one space between any two operators or operands. The function `EvalPostfix` is supposed to return the value of the expression. If it is not a legal postfix expression, `EvalPostfix` must return a special value `Infinity` which is defined by the judge program.

***Sample program of judge:***
```C
#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */
```
***Sample Input 1:***

    11 -2 5.5 * + 23 7 / -

***Sample Output 1:***

    -3.285714

***Sample Input 2:***

    11 -2 5.5 * + 23 0 / -

***Sample Output 2:***

    ERROR

***Sample Input 3:***

    11 -2 5.5 * + 23 7 / - *

***Sample Output 3:***

    ERROR

## 6-6 Level-order Traversal (25 points)
Write a routine to list out the nodes of a binary tree in "level-order". List the root, then nodes at depth 1, followed by nodes at depth 2, and so on. You must do this in linear time.

***Format of functions:***
```C
void Level_order ( Tree T, void (*visit)(Tree ThisNode) );
```

where `void (*visit)(Tree ThisNode)` is a function that handles `ThisNode` being visited by `Level_order`, and `Tree` is defined as the following:
```C
typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};
```

***Sample program of judge:***
```C
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
```
***Sample Output (for the tree shown in the figure):***

![6-6 Figure 1](/img/6-6-fig-1.jpg "6-6 Figure 1")  

    Level-order: 3 5 6 1 8 10 9

## 6-7 Isomorphic (20 points)
Two trees, `T1` and `T2`, are **isomorphic** if `T1` can be transformed into `T2` by swapping left and right children of (some of the) nodes in `T1`. For instance, the two trees in Figure 1 are isomorphic because they are the same if the children of A, B, and G, but not the other nodes, are swapped. Give a polynomial time algorithm to decide if two trees are isomorphic.

<div align='center'>

![6-7 Figure 1](/img/6-7-fig-1.jpg "6-7 Figure 1")  
Figure 1
</div>

***Format of functions:***
```C
int Isomorphic( Tree T1, Tree T2 );
```
where `Tree` is defined as the following:
```C
typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};
```
The function is supposed to return 1 if `T1` and `T2` are indeed isomorphic, or 0 if not.

***Sample program of judge:***
```C
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */

int Isomorphic( Tree T1, Tree T2 );

int main()
{
    Tree T1, T2;
    T1 = BuildTree();
    T2 = BuildTree();
    printf("%d\n", Isomorphic(T1, T2));
    return 0;
}

/* Your function will be put here */
```
***Sample Output 1 (for the trees shown in Figure 1):***

    1

***Sample Output 2 (for the trees shown in Figure 2):***

    0

<div align='center'>

![6-7 Figure 2](/img/6-7-fig-2.jpg "6-7 Figure 2")  
Figure 2
</div>


## 6-8 Percolate Up and Down (20 points)
Write the routines to do a "percolate up" and a "percolate down" in a binary min-heap.

***Format of functions:***
```C
void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );
```
where int `p` is the position of the element, and `PriorityQueue` is defined as the following:
```C
typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};
```
***Sample program of judge:***
```C
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ); /* details omitted */

void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H ) 
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H ) 
{ 
    ElementType MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;

    scanf("%d", &n);
    H = Initialize(n);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &op);
        switch( op ) {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("%d ", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for ( i=1; i<=H->Size; i++ )
        printf(" %d", H->Elements[i]);
    return 0;
}

/* Your function will be put here */
```
***Sample Input:***

    9
    1 10
    1 5
    1 2
    0
    1 9
    1 1
    1 4
    0
    0

***Sample Output:***

    2 1 4 
    Inside H: 5 10 9


## 6-9 Sort Three Distinct Keys (20 points)
Suppose you have an array of `N` elements, containing three distinct keys, "true", "false", and "maybe". Given an *O(`N`)* algorithm to rearrange the list so that all "false" elements precede "maybe" elements, which in turn precede "true" elements. You may use only constant extra space.

***Format of functions:***
```C
void MySort( ElementType A[], int N );
```
where `ElementType A[]` contains the `N` elements.

***Sample program of judge:***
```C
#include <stdio.h>
#include <stdlib.h>

typedef enum { true, false, maybe } Keys;
typedef Keys ElementType;

void Read( ElementType A[], int N ); /* details omitted */

void MySort( ElementType A[], int N );

void PrintA( ElementType A[], int N )
{
    int i, k;

    k = i = 0;
    for ( ; i<N && A[i]==false; i++ );
    if ( i > k )
        printf("false in A[%d]-A[%d]\n", k, i-1);
    k = i;
    for ( ; i<N && A[i]==maybe; i++ );
    if ( i > k )
        printf("maybe in A[%d]-A[%d]\n", k, i-1);
    k = i;
    for ( ; i<N && A[i]==true; i++ );
    if ( i > k )
        printf("true in A[%d]-A[%d]\n", k, i-1);
    if ( i < N )
        printf("Wrong Answer\n");
}

int main()
{
    int N;
    ElementType *A;

    scanf("%d", &N);
    A = (ElementType *)malloc(N * sizeof(ElementType));
    Read( A, N );
    MySort( A, N );
    PrintA( A, N );
    return 0;
}

/* Your function will be put here */
```
***Sample Input:***

    6
    2 2 0 1 0 0

***Sample Output:***

    false in A[0]-A[0]
    maybe in A[1]-A[2]
    true in A[3]-A[5]

## 6-10 Strongly Connected Components (30 points)
Write a program to find the strongly connected components in a digraph.

***Format of functions:***
```C
void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) );
```
where `Graph` is defined as the following:
```C
typedef struct VNode *PtrToVNode;
struct VNode {
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;
struct GNode {
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};
```
Here `void (*visit)(Vertex V)` is a function parameter that is passed into `StronglyConnectedComponents` to handle (print with a certain format) each vertex that is visited. The function `StronglyConnectedComponents` is supposed to print a return after each component is found.

***Sample program of judge:***
```C
#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10  /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertices-1 */
typedef struct VNode *PtrToVNode;
struct VNode {
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;
struct GNode {
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};

Graph ReadG(); /* details omitted */

void PrintV( Vertex V )
{
   printf("%d ", V);
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) );

int main()
{
    Graph G = ReadG();
    StronglyConnectedComponents( G, PrintV );
    return 0;
}

/* Your function will be put here */
```
***Sample Input (for the graph shown in the figure):***

![6-10 Figure 1](/img/6-10-fig-1.jpg "6-10 Figure 1")

    4 5
    0 1
    1 2
    2 0
    3 1
    3 2
***Sample Output:***

    3 
    1 2 0 
Note: The output order does not matter. That is, a solution like

    0 1 2 
    3 
is also considered correct.

## 6-11 Shortest Path [1] (25 points)
Write a program to find the unweighted shortest distances from any vertex to a given source vertex in a digraph.

***Format of functions:***
```C
void ShortestDist( LGraph Graph, int dist[], Vertex S );
```
where `LGraph` is defined as the following:
```C
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;
```
The shortest distance from V to the source S is supposed to be stored in dist[V]. If V cannot be reached from S, store -1 instead.

***Sample program of judge:***
```C
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

void ShortestDist( LGraph Graph, int dist[], Vertex S );

int main()
{
    int dist[MaxVertexNum];
    Vertex S, V;
    LGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist( G, dist, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);

    return 0;
}

/* Your function will be put here */
```
***Sample Input (for the graph shown in the figure):***

![6-11 Figure 1](/img/6-11-fig-1.jpg "6-11 Figure 1")

    7 9
    0 1
    0 5
    0 6
    5 3
    2 1
    2 6
    6 4
    4 5
    6 5
    2
***Sample Output:***

    -1 1 0 3 2 2 1 

## 6-12 Shortest Path [2] (25 points)
Write a program to find the weighted shortest distances from any vertex to a given source vertex in a digraph. It is guaranteed that all the weights are positive.

***Format of functions:***
```C
void ShortestDist( MGraph Graph, int dist[], Vertex S );
```
where `MGraph` is defined as the following:
```C
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;
```
The shortest distance from `V` to the source `S` is supposed to be stored in `dist[V]`. If `V` cannot be reached from `S`, store -1 instead.

***Sample program of judge:***
```C
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG(); /* details omitted */

void ShortestDist( MGraph Graph, int dist[], Vertex S );

int main()
{
    int dist[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist( G, dist, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);

    return 0;
}

/* Your function will be put here */
```
***Sample Input (for the graph shown in the figure):***

![6-12 Figure 1](/img/6-12-fig-1.jpg "6-12 Figure 1")

    7 9
    0 1 1
    0 5 1
    0 6 1
    5 3 1
    2 1 2
    2 6 3
    6 4 4
    4 5 5
    6 5 12
    2
***Sample Output:***
    
    -1 2 0 13 7 12 3 

##