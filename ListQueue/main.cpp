#include <stdio.h>

using namespace std;

class QueueUnderFlowException {
    public:
        QueueUnderFlowException(){
            printf("Queue Under Flow Exception\n");
        }
};
class Node {
public:
    Node* next;
    int val;

};

class ListQueue{
private:
    Node* head;
    Node* tail;
    int cnt;

public:
    ListQueue(){
        head = NULL;
        tail = NULL;
        cnt = 0;
    }
    void Enqueue(int val){
        Node* tmp = new Node();
        tmp -> val = val;
        tmp -> next = NULL;
        if(isEmpty()){
            head = tail = tmp;
        }
        else {
            tail -> next = tmp;
            tail = tmp;
        }
        cnt++;
    }
    int Dequeue(){
        if(isEmpty()){
            throw new QueueUnderFlowException();
        }
        int ret = head -> val;
        Node* tmp = head;
        head = head -> next;
        delete tmp;
        cnt--;
        return ret;
    }
    int Front(){
        if(isEmpty()){
            throw new QueueUnderFlowException();
        }
        return head->val;
    }
    inline int Size(){
        return cnt;
    }
    inline bool isEmpty(){
        return (cnt==0?true:false);
    }

};
int main()
{
    int n;
    scanf("%d",&n);
    ListQueue q;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        q.Enqueue(x);
    }
    while(!q.isEmpty()){
        printf("%d\n",q.Dequeue());
    }
}
