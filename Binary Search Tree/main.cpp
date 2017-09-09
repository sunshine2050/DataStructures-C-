#include <stdio.h>

using namespace std;

class BSTEmpty{
public:
    BSTEmpty(){
        printf("BST is Empty\n");
    }
};
class Node {
public:
    Node* left;
    Node* right;
    Node* parent;
    int val;
};

class BST{
    Node* root;
public:
    BST(){
        root = NULL;

    }
    ~BST(){
        delete root;
    }
    inline Node* Root(){ return root;};
    Node* Search(int val);
    void Insert(int val);
    void Delete(int val);
    void Print(Node* tmp,bool R);
};

void BST::Insert(int val){
    Node* newNode = new Node();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->val = val;

    if(root == NULL) root = newNode;
    else{
        Node* tmp = root;
        bool R=false;
        do{
            if(val>tmp->val){
                if(tmp->right==NULL){R=true; break;}
                tmp=tmp->right;

            }
            else{
                if(tmp->left==NULL){R=false; break;}
                tmp=tmp->left;
            }
        }while(tmp!=NULL);
        newNode->parent=tmp;
        if(R) tmp->right=newNode;
        else tmp->left = newNode;
    }
}

Node* BST::Search(int val){
    if(root==NULL){
        throw new BSTEmpty();
    }
    Node* tmp = root;
    do{
        if(tmp->val == val) return tmp;
        else{
            if(val>tmp->val){
                if(tmp->right==NULL) break;
                tmp=tmp->right;
            }
            else{
                if(tmp->left==NULL) break;
                tmp=tmp->left;
            }
        }
    }while(tmp!=NULL);

    if(tmp==NULL){return NULL;}
}

void BST::Delete(int val){
    Node* tmp = Search(val);
    if(tmp == NULL){
        printf("Not Found!\n");
        return;
    }
    if(tmp->parent==NULL){
        printf("Can't delete root element\n");
        return;
    }
    if(tmp->left!=NULL && tmp->right!=NULL){
        if(tmp->val>tmp->parent->val){tmp->left->parent= tmp->parent; tmp->parent->right=tmp->left;}
        else{tmp->left->parent= tmp->parent; tmp->parent->left=tmp->left;}
        delete tmp;
    }
    else if(tmp->left==NULL && tmp->right==NULL){
        if(tmp->val>tmp->parent->val) tmp->parent->right=NULL;
        else tmp->parent->left=NULL;
        delete tmp;
    }
    else{
        if(tmp->val>tmp->parent->val){
            if(tmp->left!=NULL){tmp->left->parent= tmp->parent; tmp->parent->right=tmp->left;}
            else{tmp->right->parent= tmp->parent; tmp->parent->right=tmp->right;}
        }
        else{
            if(tmp->left!=NULL){tmp->left->parent= tmp->parent; tmp->parent->left=tmp->left;}
            else{tmp->right->parent= tmp->parent; tmp->parent->left=tmp->right;}
        }
        delete tmp;
    }
}

void BST::Print(Node* tmp,bool R){
    if(tmp==NULL) return;
    printf("%d->%d ",R,tmp->val);
    Print(tmp->left,false);
    Print(tmp->right,true);
}
int main()
{
    int n;
    BST bst;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        bst.Insert(x);

    }
    bst.Print(bst.Root(),false);
    int del;
    scanf("%d",&del);
    bst.Delete(del);
    bst.Print(bst.Root(),false);
}
