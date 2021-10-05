#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
typedef struct node* Ptr2Node;
struct node{
    ElementType val;
    Ptr2Node next;
};
typedef Ptr2Node stack;


ElementType pop(stack S){
    stack temp=S->next;
    if(temp){
        ElementType res=temp->val;
        S->next=temp->next;
        free(temp);
        return res;
    }else return Infinity;
}

stack push(stack S,ElementType v){
    stack tempNode=(stack)malloc(sizeof(struct node));
    tempNode->next=S->next;
    tempNode->val=v;
    S->next=tempNode;
    return S;
}

ElementType EvalPostfix( char *expr ){
    stack S=(stack)malloc(sizeof(struct node));
    S->val=Infinity; S->next=NULL;
    char str[Max_Expr+1];
    int cnt=0;

    ElementType num1,num2,res;
    while (1)
    {
        if(*expr!=' '&& *expr!='\0') str[cnt++]=*expr;
        else {
            str[cnt]='\0';
            if(cnt==1){
                if(str[0]=='+'){
                    num1=pop(S);
                    num2=pop(S);
                    if(num1==Infinity ||num2==Infinity) return Infinity;
                    res=num2+num1;
                    push(S,res);
                }
                else if(str[0]=='-'){
                    num1=pop(S);
                    num2=pop(S);
                    if(num1==Infinity ||num2==Infinity) return Infinity;
                    res=num2-num1;
                    push(S,res);
                }
                else if(str[0]=='*'){
                    num1=pop(S);
                    num2=pop(S);
                    if(num1==Infinity ||num2==Infinity) return Infinity;
                    res=num2*num1;
                    push(S,res);
                }
                else if(str[0]=='/'){
                    num1=pop(S);
                    num2=pop(S);
                    if(num1==0||num1==Infinity ||num2==Infinity) return Infinity;
                    res=num2/num1;
                    push(S,res);
                }
                else if(str[0]>='0' && str[0]<='9')
                    push(S,atof(str));
            }
            else push(S,atof(str));
            cnt=0;
        }
        if(*expr=='\0') break;
        expr++;
    }
    res=pop(S);
    if(S->next) return Infinity;
    return res;
}