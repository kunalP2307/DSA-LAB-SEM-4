#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    
    int key;
    Node *rightChild,*leftChild;
    bool rightThread;

    Node(int key){
        this->key = key;
        this->rightChild = NULL;
        this->leftChild = NULL;
    }

};

Node* convertToTBT(Node *root){

    if(root == NULL)
        return NULL;

    if(root->leftChild == NULL && root->rightChild == NULL)
        return root;
    
    if(root->leftChild != NULL){

        Node* rightMost = convertToTBT(root->leftChild);
        rightMost->rightChild = root;
        rightMost->rightThread = true;

    }

    if(root->rightChild == NULL)
        return root;

    return convertToTBT(root->rightChild);

}

Node *leftMost(Node *node){

    while(node != NULL && node->leftChild != NULL){
        node = node->leftChild;
    }
    return node;
}


void inOrder(Node *root){

    if(root == NULL)
        return;
    Node *temp = leftMost(root);
    while(temp != NULL){
        cout<<temp->key<<"\t";
        if(temp->rightThread)
            temp = temp->rightChild; 
        else    
            temp = leftMost(temp->rightChild);
    }
}


int main(){

    int n;

    Node *head = new Node(50);

    head->rightChild = new Node(12);
    head->leftChild = new Node(24);
    head->leftChild->leftChild = new Node(3);
    head->rightChild->leftChild = new Node(67);
  
    
    convertToTBT(head);

    inOrder(head);


    return 0;
}
