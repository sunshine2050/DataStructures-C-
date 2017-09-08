#include <stdio.h>

using namespace std;

class StackOverFlowException {
    public:
        StackOverFlowException(){
            printf("Stack OverFlow\n");
        }
};
class StackUnderFlowException {
    public:
        StackUnderFlowException(){
            printf("Stack UnderFlow\n");
        }
};

class Node {
public:
    int val; // Change type later
    Node* next;
};

class ListStack
{
    private:
        Node* head;
        int count;
    public:
        ListStack()
        {
            head = NULL;
            count = 0;
        }
        void Push(int val){ //Change type later
            Node* temp = new Node();
            temp -> val = val;
            temp -> next = head;
            head = temp;
            count++;
        }
        int Pop(){
            if(head==NULL){
                throw new StackUnderFlowException();
            }
            int ret = head -> val;
            Node* temp = head -> next;
            delete head;
            head = temp;
            count--;
            return ret;
        }
        inline int Top(){
            return head->val;
        }
        inline int Size(){
            return count;
        }
        inline bool isEmpty(){
            return (count==0)?true:false;
        }
};
int main()
{
    ListStack st;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        st.Push(x);
    }
    while(!st.isEmpty()){
        printf("%d\n",st.Pop());
    }
}
