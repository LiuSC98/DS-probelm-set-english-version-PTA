/*
7-5 Tree Traversals Again (25 分)
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. 
For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, 
the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). 
Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. 
Your task is to give the postorder traversal sequence of this tree.

Figure 1
Input Specification:
Each input file contains one test case. For each case, 
the first line contains a positive integer N (≤30) 
which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). 
Then 2N lines follow, each describes a stack operation in the format: 
"Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. 
A solution is guaranteed to exist. All the numbers must be separated by exactly one space, 
and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

Sample Output:
3 4 2 6 5 1
*/

#include <iostream>
#include <stack>

using namespace std;

typedef struct treeNode *ptr2TreeNode;
struct treeNode{
    int nodeVal;
    bool beenPoped;
    ptr2TreeNode leftSon,rightSon,parent;
};
typedef ptr2TreeNode binaryTree;

inline binaryTree newNode(int val,binaryTree parentNode){
    binaryTree tempNode=new treeNode;
    tempNode->leftSon=tempNode->rightSon=NULL;
    tempNode->parent=parentNode;
    tempNode->nodeVal=val;
    tempNode->beenPoped=0;
    return tempNode;
}
int flag=0;
void postorderTravel(binaryTree tree){
    if(tree->leftSon) postorderTravel(tree->leftSon);
    if(tree->rightSon) postorderTravel(tree->rightSon);
    if(flag) cout<<' ';
    else flag=1;
    cout<<tree->nodeVal;
}
int main(){
    int N;
    cin>>N;
    string str;
    int x;
    
    cin>>str>>x;
    binaryTree root= newNode(x,NULL);
    binaryTree nodeNow=root;
    for(int i=0;i<2*N-1;i++){
        cin>>str;
        if(str=="Push"){
            cin>>x;
            if(!nodeNow->leftSon) {
                nodeNow->leftSon=newNode(x,nodeNow);
                nodeNow=nodeNow->leftSon;
            }
            else if(!nodeNow->rightSon) {
                nodeNow->rightSon=newNode(x,nodeNow);
                nodeNow=nodeNow->rightSon;
            }
        }
        else if(str=="Pop"){
            if(nodeNow->beenPoped==0) nodeNow->beenPoped=1;
            else {
                while(nodeNow->beenPoped==1) nodeNow=nodeNow->parent;
                nodeNow->beenPoped=1;
            }
        }
    }
    postorderTravel(root);

    return 0;
}