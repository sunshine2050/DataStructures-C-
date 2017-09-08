#include <stdio.h>

using namespace std;


class Node {
private:
    int val;
    Node* next;
public:
    Node(){};
    inline int getVal(){ return val;};
    inline Node* getNext(){return next;};
    inline void setVal(int x){ val = x;};
    inline void setNext(Node* tmp){ next = tmp;};
};

class List{
private:
    Node* head;
    int cnt;
public:
    List(){ head=NULL; cnt=0; };
    void Print();
    void Append(int data);
    void Delete(int data);
};

void List::Print(){
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

void List::Append(int val){
    Node* newNode = new Node();
    newNode->setVal(val);
    newNode->setNext(NULL);

    Node* tmp = head;
    if(tmp==NULL){
        head = newNode;
    }
    else{
        while(tmp->getNext()!=NULL){
            tmp=tmp->getNext();
        }
        tmp->setNext(newNode);
    }
    cnt++;
}
void List::Delete(int val){
    Node* tmp = head;

    if(tmp==NULL) return;

    if(tmp->getVal()==val){
        head = tmp->getNext();
        delete tmp;
        return;
    }
    if(tmp->getNext()==NULL){
        if(tmp->getVal()==val){
            delete tmp;
            head=NULL;
        }
        else{
            printf("No Element with this value\n");
        }
    }
    else{
        Node* prev;

        do{
            if(tmp->getVal()==val) break;
            prev = tmp;
            tmp = tmp->getNext();
        }while(tmp!=NULL);
        if(tmp==NULL) printf("No Element with this value\n");
        else prev ->setNext(tmp->getNext());
        delete tmp;
        cnt--;

    }
}
int main()
{
    List ls;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        ls.Append(x);
        ls.Print();
    }
    ls.Delete(4);
    ls.Print();
    ls.Delete(5);
    ls.Print();
    ls.Delete(1);
    ls.Print();
    ls.Delete(0);
    ls.Print();

}
