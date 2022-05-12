#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    
    int key;
    Node *rightChild,*leftChild;

    Node(int key){
        this->key = key;
        this->rightChild = NULL;
        this->leftChild = NULL;
    }

};
Node *head = NULL;

void insertNode(Node* &head, int key){

    if(head == NULL){
        head = new Node(key);
        return;
    }

    if(key < head->key){
        
        if(head->leftChild == NULL){
            Node* node = new Node(key);
            head->leftChild = node;
        }
        else{
            insertNode(head->leftChild,key);
        }

    }
    else if(key > head->key){

        if(head->rightChild == NULL){
            Node* node = new Node(key);
            head->rightChild = node;
        }
        else{
            insertNode(head->rightChild,key);
        }
    }
    else{
        return;
    }
}

void search(Node *head,int key){

    if(head == NULL){
        cout<<"Not Found";
        return;
    }

    else if(head->key == key){

        cout<<"Fount";
        return;
    }

    else{

        if(key < head->key){
            search(head->leftChild,key);
        }
        else{
            search(head->rightChild,key);
        }
    }

}

Node* findMin(Node *node){

    while(node->leftChild != NULL)
        node = node->leftChild;
    
    return node;
}

void inOrder(Node *head){

    if(head != NULL){

        inOrder(head->leftChild);
        cout<<head->key<<"\t";
        inOrder(head->rightChild);

    }
}

Node* deleteNode(Node *head,int key){

    if(head == NULL)
        return head;
    else if(key < head->key)
        head->leftChild = deleteNode(head->leftChild,key);
    else if(key > head->key)
        head->rightChild = deleteNode(head->rightChild,key);

    else{

        if(head->rightChild == NULL && head->leftChild){
            Node *node = NULL;
            head = NULL;
        }

        else if(head->rightChild == NULL){

            Node *node = head;
            head = head->leftChild;
            delete node;
        }

        else if(head->leftChild == NULL){

            Node *node = head;
            head = head->rightChild;
            delete node;

        }

        else{
            
            Node *node = findMin(head->rightChild);
            head->key = node->key;
            head->rightChild = deleteNode(head->rightChild,node->key);

        }

    }

    return head;
}

vector<int> longestPath(Node *head){

    if(head == NULL){
        vector<int> temp = {};
        return temp;
    }

    vector<int> left = longestPath(head->rightChild);

    vector<int> right = longestPath(head->rightChild);
    
    if(right.size() < left.size())
        left.push_back(head->key);

    else 
        right.push_back(head->key);

    
    if(right.size() > left.size())
        return right;

    return left;


}

int longPathWithoutVector(Node *head){

    if(head == NULL){
        return 0;
    }

    int right = longPathWithoutVector(head->rightChild);

    int left = longPathWithoutVector(head->leftChild);

    if(right < left)
        left ++;
    
    else
        right ++;

    if(right > left)
        return right;

    return left;

}

void swapTree(Node *node){

    if(node == NULL)
        return;

    else{

        swapTree(node->leftChild);
        swapTree(node->rightChild);

        Node *temp;

        temp = node->leftChild;
        node->leftChild = node->rightChild;
        node->rightChild = temp;

    }
}

int main(){

    int n;

    for(int i=0; i<5; i++){
        
        cin>>n;
        insertNode(head,n);
        
    }

    inOrder(head);

    search(head,54);

    head = deleteNode(head,3);

    inOrder(head);


    vector<int> longestPathVe = longestPath(head);
    
    cout<<"Longest Path"<<longestPathVe.size();

    cout<<"Long Path "<<longPathWithoutVector(head);


    swapTree(head);

    inOrder(head);

    return 0;
}
