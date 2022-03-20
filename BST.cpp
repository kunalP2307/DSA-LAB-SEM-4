#include<iostream>
using namespace std;

class Node{

    public:
    
    string studentName;
    Node *leftTree, *rightTree;

    Node(string studentName){
        this->studentName = studentName;
        leftTree = NULL;
        rightTree = NULL;
    }
};

void insert(Node* &root, string studentName){

    Node *node = new Node(studentName);
    if(root == NULL){
        root = node;
        return;
    }

    int i = 0;
    while(i < root->studentName.length() && i < studentName.length()){

        if(root->studentName[i] < studentName[i]){
            if(root->rightTree == NULL)
                root->rightTree = node;
            else
                insert(root->rightTree,studentName);
            break;
        }
        else{
         
            if(root->leftTree == NULL)
                root->leftTree = node;
            else
                insert(root->leftTree,studentName);
            break;
        }
        i++;
    }
}

void search(Node *root,string key){

    if(root == NULL){
        cout<<"not found";
        return;
    }
    if(root->studentName == key){
        cout<<"found";
        return;
    }
    
    else{

        int i = 0;

        while(i < root->studentName.length() && i < key.length()){

            if(root->studentName[i] < key[i]){
                search(root->rightTree, key);
                break;
            }
            else{
                search(root->leftTree, key);
                break;
            }
            i++;
        }
    }
}

void inOrder(Node *root){
    if(root == NULL)
        return;
    else{
        inOrder(root->leftTree);
        cout<<root->studentName<<"\t";
        inOrder(root->rightTree);
    }
}

int main(){

    Node *Root = NULL;
    insert(Root,"sahil");
    insert(Root,"sahkl");
    insert(Root,"khubham");
    insert(Root,"qwadeep");
    insert(Root,"anil");
    
    
    inOrder(Root);

    search(Root,"sahl");
    
    return 0;
    
}
