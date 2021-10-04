/*
7-9 Huffman Codes (30 points)
In 1953, David A. Huffman published his paper "A Method for the Construction of Minimum-Redundancy Codes", and hence printed his name in the history of computer science. As a professor who gives the final exam problem on Huffman codes, I am encountering a big problem: the Huffman codes are NOT unique. For example, given a string "aaaxuaxz", we can observe that the frequencies of the characters 'a', 'x', 'u' and 'z' are 4, 2, 1 and 1, respectively. We may either encode the symbols as {'a'=0, 'x'=10, 'u'=110, 'z'=111}, or in another way as {'a'=1, 'x'=01, 'u'=001, 'z'=000}, both compress the string into 14 bits. Another set of code can be given as {'a'=0, 'x'=11, 'u'=100, 'z'=101}, but {'a'=0, 'x'=01, 'u'=011, 'z'=001} is NOT correct since "aaaxuaxz" and "aazuaxax" can both be decoded from the code 00001011001001. The students are submitting all kinds of codes, and I need a computer program to help me determine which ones are correct and which ones are not.

Input Specification:
Each input file contains one test case. For each case, the first line gives an integer N (2≤N≤63), then followed by a line that contains all the N distinct characters and their frequencies in the following format:

c[1] f[1] c[2] f[2] ... c[N] f[N]
where c[i] is a character chosen from {'0' - '9', 'a' - 'z', 'A' - 'Z', '_'}, and f[i] is the frequency of c[i] and is an integer no more than 1000. The next line gives a positive integer M (≤1000), then followed by M student submissions. Each student submission consists of N lines, each in the format:

c[i] code[i]
where c[i] is the i-th character and code[i] is an non-empty string of no more than 63 '0's and '1's.

Output Specification:
For each test case, print in each line either "Yes" if the student's submission is correct, or "No" if not.

Note: The optimal solution is not necessarily generated by Huffman algorithm. Any prefix code with code length being optimal is considered correct.

Sample Input:
7
A 1 B 1 C 1 D 3 E 3 F 6 G 6
4
A 00000
B 00001
C 0001
D 001
E 01
F 10
G 11
A 01010
B 01011
C 0100
D 011
E 10
F 11
G 00
A 000
B 001
C 010
D 011
E 100
F 101
G 110
A 00000
B 00001
C 0001
D 001
E 00
F 10
G 11

Sample Output:
Yes
Yes
No
No

*/

#include <iostream>
#include <algorithm>
using namespace std;

struct CFC{
    char c;
    int freq;
    string code;
};

typedef struct treeNode* Ptr2Node;
struct treeNode{
    CFC nodeValue;
    Ptr2Node left,right;
};
typedef Ptr2Node BiTree;

// sort by frequence
bool greaterF(BiTree a, BiTree b){
    if(a->nodeValue.freq>b->nodeValue.freq) return 1;
    return 0;
}

// sort by ASCII
bool greaterA(CFC a,CFC b){
    if(a.c>b.c) return 1;
    return 0;
}

// merge 2 small tree to a large tree
BiTree merge2Tree(BiTree t1,BiTree t2){
    BiTree root=new treeNode;
    root->nodeValue={0,0,""};
    root->left=t1; root->right=t2;
    if(t1) root->nodeValue.freq+=t1->nodeValue.freq;
    if(t2) root->nodeValue.freq+=t2->nodeValue.freq;
    return root;
};


// generate huffman code and return the code's total cost
void huffmanCode(BiTree root,CFC X[],int N){ 
    if(!root) return ;
    if(root->left){
        root->left->nodeValue.code=root->nodeValue.code+'0';
        huffmanCode(root->left,X,N);
    }
    if(root->right){
        root->right->nodeValue.code=root->nodeValue.code+'1';
        huffmanCode(root->right,X,N);
    }
    if(root->nodeValue.c){
        for(int i=0;i<N;i++){
            if(root->nodeValue.c==X[i].c)
                X[i].code=root->nodeValue.code;
        }
    }
    return;
}

// build huffman tree from frequency
BiTree huffmanTree(CFC X[],int N){
    if(N<1) return NULL;
    BiTree *treeHeap= new BiTree[N];
    for (size_t i = 0; i < N; i++)
    {
        treeHeap[i]=new treeNode;
        treeHeap[i]->nodeValue=X[i];
        treeHeap[i]->left=treeHeap[i]->right=NULL;
    }
    make_heap(treeHeap,treeHeap+N,greaterF);

    BiTree root,tree1,tree2;
    for(int i=N;i>1;i--){
        tree1 = treeHeap[0];
        pop_heap(treeHeap,treeHeap+i,greaterF);
        tree2 = treeHeap[0];
        pop_heap(treeHeap,treeHeap+i-1,greaterF);
        root = merge2Tree(tree1,tree2);
        treeHeap[i-2]=root;
        push_heap(treeHeap,treeHeap+i-1,greaterF);
    }
    huffmanCode(root,X,N);
    return root;
}

// build huffman tree from huffman code
bool isHuffmanTree(CFC X[],int N){
    if(N<1) return 1;
    BiTree root=new treeNode;
    root->nodeValue={0,0,""};
    root->left=root->right=NULL;
    BiTree tempNode;
    for (int i = 0; i < N; i++)
    {
        tempNode=root;
        for (int j = 0; j < X[i].code.length(); j++)
        {
            if(X[i].code[j]=='0'){
                if(tempNode->left){
                    if(tempNode->left->nodeValue.c){
                        return 0;
                    }
                    else tempNode=tempNode->left;
                }else{
                    tempNode->left=new treeNode;
                    tempNode=tempNode->left;
                    if(j==X[i].code.length()-1) tempNode->nodeValue=X[i];  
                    else tempNode->nodeValue={0,0,""};
                    tempNode->left=tempNode->right=NULL;
                }
                
            }else if(X[i].code[j]=='1'){
                if(tempNode->right){
                    if(tempNode->right->nodeValue.c){
                        return 0;
                    }
                    else tempNode=tempNode->right;
                }else{
                    tempNode->right=new treeNode;
                    tempNode=tempNode->right;
                    if(j==X[i].code.length()-1) tempNode->nodeValue=X[i];  
                    else tempNode->nodeValue={0,0,""};
                    tempNode->left=tempNode->right=NULL;
                }

            }
        }
        
    }
    return 1;
}

int totalCost(CFC X[],int N){
    int cost=0;
    for (int i = 0; i < N; i++)
    {
        cost+=X[i].freq*X[i].code.length();
    }
    return cost;
}

int main(){

    //input characters and their frequence;
    int N;
    cin>>N;
    CFC *X0=new CFC[N],*X1=new CFC[N];
    int freq[63]={0,};
    char c;
    int f;
    for (int i = 0; i < N; i++)
    {
        cin>>c>>f;
        X0[i].code="";
        X0[i].c=c;
        X0[i].freq=f;
    }
    sort(X0,X0+N,greaterA);

    //generate a set of possible huffmancodes
    huffmanTree(X0,N);
    int cost0=totalCost(X0,N);

    //input codes and check if they were Huffman Codes;
    int M;
    string s;
    cin>>M;
    while(M--){
        for(int i=0;i<N;i++){
            cin>>c>>s;
            X1[i].freq=0;
            X1[i].c=c;
            X1[i].code=s;
        }
        sort(X1,X1+N,greaterA);
        int diffCh=0;
        for(int i=0;i<N;i++){
            if(X0[i].c!=X1[i].c){
                diffCh=1;
                break;
            }
            else X1[i].freq=X0[i].freq;
        }
        // different character, fail 
        if(diffCh){
            cout<<"No"<<endl;
            continue;
        }
        // different cost, fail
        int cost1=totalCost(X1,N);
        if(cost0!=cost1){
            cout<<"No"<<endl;
            continue;
        }
        // these codes cannot build a huffman tree, fail
        if(!isHuffmanTree(X1,N)){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;

    }
    
    return 0;
}