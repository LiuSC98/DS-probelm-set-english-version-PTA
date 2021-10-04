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

Polynomial Add( Polynomial a, Polynomial b ){
    Polynomial x=a->Next,y=b->Next;
    Polynomial res=(Polynomial)malloc(sizeof(struct Node));
    res->Coefficient=res->Exponent=0;
    res->Next=NULL;
    Polynomial temp=res;
    while (x&&y)
    {
        if(x->Exponent>y->Exponent){
            if(x->Coefficient){
                temp->Next=(Polynomial)malloc(sizeof(struct Node));
                temp=temp->Next;    
                temp->Next=NULL;
                temp->Exponent=x->Exponent;
                temp->Coefficient=x->Coefficient;
            }
            x=x->Next;
        }
        else if(x->Exponent<y->Exponent){
            if(y->Coefficient){
                temp->Next=(Polynomial)malloc(sizeof(struct Node));
                temp=temp->Next;    
                temp->Next=NULL;
                temp->Exponent=y->Exponent;
                temp->Coefficient=y->Coefficient;
            }
            y=y->Next;
        }
        else{
            if(y->Coefficient+x->Coefficient){
                temp->Next=(Polynomial)malloc(sizeof(struct Node));
                temp=temp->Next;    
                temp->Next=NULL;
                temp->Exponent=x->Exponent;
                temp->Coefficient=y->Coefficient+x->Coefficient;
            }
            x=x->Next;y=y->Next;
        }
    }
    while (x){
        if(x->Coefficient){
            temp->Next=(Polynomial)malloc(sizeof(struct Node));
            temp=temp->Next;    
            temp->Next=NULL;
            temp->Exponent=x->Exponent;
            temp->Coefficient=x->Coefficient;
        }
        x=x->Next;
    }
    while (y)
    {
        if(y->Coefficient){
            temp->Next=(Polynomial)malloc(sizeof(struct Node));
            temp=temp->Next;    
            temp->Next=NULL;
            temp->Exponent=y->Exponent;
            temp->Coefficient=y->Coefficient;
        }
        y=y->Next;
    }
    
    
    return res;
}