#include <stdio.h>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Node{
public:
    Node(){content= ' '; marker= false;}
    ~Node() {}
    inline char Content(){ return content;}
    inline void setContent(char c){ content = c;}
    inline bool Marker(){return marker;}
    inline void setMarker(){marker=true;}
    Node* findChild(char c);
    inline void addChild(Node* c){ children.push_back(c);}
    inline vector <Node*> Children(){return children;}
private:
    char content;
    bool marker;
    vector <Node*> children;
};

Node* Node::findChild(char c){
    for(Node* node: children){
        if(node->Content()==c) return node;
    }
    return NULL;
}

class Trie{
public:
    Trie(){ root = new Node();}
    ~Trie(){ delete root;}
    void addWord(string s);
    bool searchWord(string s);
    void deleteWord(string s);
private:
    Node* root;
};

void Trie::addWord(string s){
     Node* current = root;

     if(s.length()==0){
        current->setMarker();
        return;
     }

     for(int i=0;i<(int)s.length();i++){
        Node* k = current->findChild(s[i]);
        if(k!=NULL){
            current = k;
        }
        else{
            Node* newNode = new Node();
            newNode->setContent(s[i]);
            current->addChild(newNode);
            current=newNode;
        }
        if(i==(int)s.length()-1){
            current->setMarker();
        }
     }
}
bool Trie::searchWord(string s){
     Node* current = root;

     while(current!=NULL){
        for(int i=0;i<(int)s.length();i++){
            Node* k = current->findChild(s[i]);
            if(k==NULL) return false;
            else current=k;
        }
        return current->Marker();
     }
     return false;
}

void addWord(string s){

}
int main()
{

}
