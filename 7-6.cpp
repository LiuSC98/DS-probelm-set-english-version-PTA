/*
7-6 Root of AVL Tree (25 points)
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.

Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120

Sample Output 1:
70

Sample Input 2:
7
88 70 61 96 120 90 65

Sample Output 2:
88

*/

#include <iostream>
using namespace std;

typedef struct tree_node *ptr_to_node;
struct tree_node{
    int val,left_h,right_h;
    ptr_to_node left,right;
};
typedef ptr_to_node AVL_tree;

void get_height(AVL_tree node){
    if(node->left){
        node->left_h=max(node->left->left_h,node->left->right_h)+1;
    }else node->left_h=0;
    if(node->right){
        node->right_h=max(node->right->left_h,node->right->right_h)+1;
    }else node->right_h=0;
}
AVL_tree LL(AVL_tree root){
    AVL_tree S=root->left;
    root->left=S->right;
    S->right=root;
    get_height(root);
    get_height(S);
    return S;
}
AVL_tree RR(AVL_tree root){
    AVL_tree S=root->right;
    root->right=S->left;
    S->left=root;
    get_height(root);
    get_height(S);
    return S;
}
AVL_tree LR(AVL_tree root){
    AVL_tree G=root,P=G->left,S=P->right;
    G->left=S->right;
    P->right=S->left;
    S->left=P;
    S->right=G;
    get_height(P);
    get_height(G);
    get_height(S);
    return S;
}
AVL_tree RL(AVL_tree root){
    AVL_tree G=root,P=G->right,S=P->left;
    G->right=S->left;
    P->left=S->right;
    S->left=G;
    S->right=P;
    get_height(P);
    get_height(G);
    get_height(S);
    return S;
}


AVL_tree insert(AVL_tree root, int val){
    
    if (!root){
        root=new tree_node;
        root->val=val;
        root->left=root->right=NULL;
        root->left_h=root->right_h=0;
        return root;
    }
    if(val<root->val){
        root->left=insert(root->left,val);
        get_height(root);
        if(root->left_h-root->right_h>1){
            if(val<root->left->val) root=LL(root);
            else root=LR(root);
        }
    }else if(val>root->val){
        root->right=insert(root->right,val);
        get_height(root);
        if(root->right_h-root->left_h>1){
            if(val>root->right->val) root=RR(root);
            else root=RL(root);
        }
    }
    return root;
}


int main(){
    int N,input;
    cin>>N;
    AVL_tree root=NULL;
    for (int i = 0; i < N; i++)
    {
        cin>>input;
        root=insert(root,input);
    }
    cout<<root->val;
    return 0;
}