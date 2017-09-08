#include <stdio.h>

using namespace std;

class DequeueEmptyException{
public:
    DequeueEmptyException(){
        printf("Dequeue is Empty\n");
    }
};
class Node {
private:
    int val;
    Node* next;
    Node* prev;
public:
    Node(){};
    inline int getVal(){ return val;};
    inline Node* getNext(){return next;};
    inline void setVal(int x){ val = x;};
    inline void setNext(Node* tmp){ next = tmp;};
    inline Node* getPrev(){return prev;};
    inline void setPrev(Node* tmp){ prev = tmp;};
};

class Dequeue{
private:
    Node* head;
    Node* tail;
    int cnt;
public:
    Dequeue(){ head=NULL; tail= NULL; cnt=0; };
    int Front();
    int Back();
    int RemoveFront();
    int RemoveBack();
    void PushFront(int data);
    void PushBack(int data);
    inline bool isEmpty(){return !cnt;}
    void Print();
    inline int Size();
};
int Dequeue::Size(){ return cnt;}
int Dequeue::Back(){
    if(isEmpty()){
        throw new DequeueEmptyException();
    }
    return tail->getVal();
}
int Dequeue::Front(){
    if(isEmpty()){
        throw new DequeueEmptyException();
    }
    return head->getVal();
}

void Dequeue::PushBack(int val){
    Node* newNode = new Node();
    newNode->setVal(val);
    newNode->setNext(NULL);
    newNode->setPrev(NULL);


    if(isEmpty()){
        head=tail=newNode;
    }
    else{
        newNode->setPrev(tail);
        tail->setNext(newNode);
        tail=newNode;
    }
    cnt++;
}
void Dequeue::PushFront(int val){
    Node* newNode = new Node();
    newNode->setVal(val);
    newNode->setNext(NULL);
    newNode->setPrev(NULL);

    if(isEmpty()){
        head=tail=newNode;
    }
    else{
        newNode->setNext(head);
        head->setPrev(newNode);
        head=newNode;
    }
    cnt++;

}
int Dequeue::RemoveBack(){
    if(isEmpty()){
        throw new DequeueEmptyException();
    }
    Node* tmp = tail;
    int r = tmp->getVal();
    if(Size()==1){
        tail=NULL;
        head=NULL;
    }
    else {
        tail = tail->getPrev();
        tail->setNext(NULL);
    }
    delete tmp;
    cnt--;
    return r;
}
int Dequeue::RemoveFront(){
    if(isEmpty()){
        throw new DequeueEmptyException();
    }
    Node* tmp = head;
    int r = tmp->getVal();
    if(Size()==1){
        head = NULL;
        tail=NULL;
    }
    else{
        head = head->getNext();
        head->setPrev(NULL);
    }
    delete tmp;
    cnt--;
    return r;
}
void Dequeue::Print(){
    Node* tmp = head;
    if(tmp == NULL){
        printf("Empty\n");
        return;
    }
    do {
        printf("%d --> ",tmp->getVal());
        tmp = tmp->getNext();
    }
    while(tmp!=NULL);
    printf("NULL\n");
}

int main()
{
    Dequeue dq;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(i%2==0) dq.PushBack(x);
        else dq.PushFront(x);
        printf("%d\n",dq.Size());
        dq.Print();
    }
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(i%2==0) dq.RemoveBack();
        else dq.RemoveFront();
        printf("%d\n",dq.Size());
        dq.Print();
    }
}
