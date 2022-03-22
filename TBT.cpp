#include<bits/stdc++.h>
using namespace std;
class Node {

    public :
    int data;
    Node *right,*left;
    bool rightThread, leeftThread;

    Node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
        this->rightThread = false;
    }
    
};

vector<Node*> vec(10,NULL);

void insertNode(int value, Node *root){

        Node *node = new Node(value);

        if(value < root->data){
            if(root->left == NULL)
                root->left = node;
            else
                insertNode(value,root->left);    
        }
        else{
            if(root->right == NULL)
                root->right = node;
            else   
                insertNode(value,root->right);
        }

    }
    void makeTbt(Node *root){
        if(root == NULL)
            return;
        makeTbt(root->left);
        if(root->right == NULL)
            root->rightThread = true;
        makeTbt(root->right);
    }

    void inOrder(Node *root){
        if(root == NULL)
            return;
        inOrder(root->left);
        if(root->rightThread)
            cout<<root->data<<" : True "<<endl;
        else    
            cout<<root->data<<" : False "<<endl;
        inOrder(root->right);
    }

    
    void search(Node *root,int key){
        if(root == NULL){
            cout<<"not found";
            return;
        }
        if(root->data == key){
            cout<<"found";
            return;
        }
        if(root->data < key)
            search(root->right,key);
        else
            search(root->left,key);
    }

Node* FindMin(Node* root){
	while(root->left != NULL) 
        root = root->left;
	return root;
}

Node* deleteNode(Node *root,int key){
    if(root == NULL)
        return root;
    else if(key < root->data)
        root->left = deleteNode(root->left,key);
    else if(key > root->data)
        root->right = deleteNode(root->right,key);
    else{

        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node *node = root;
            root = root->left;
            delete node;
        }
        else if(root->right == NULL){
            Node *node = root;
            root = root->left;
            delete node;
        }
        else{
            Node *node = FindMin(root->right);
            root->data = node->data;
            root->right = deleteNode(root->right,node->data);
        }
    }
    return root;
        
}
int main(){
    int data;

    Node *node = new Node(50);
    for(int i=0; i<5; i++){
        cout<<"Enter Data : " ;
        cin>>data;
        insertNode(data,node);
    }
    cout<<"Before Making TBT : "<<endl;
    inOrder(node);

    makeTbt(node);
    cout<<"After Making TBT : "<<endl;
    inOrder(node);

    /*search(node,21);
    cout<<"\n";
    node = deleteNode(node,32);
    inorder(node); */
    return 0;
}
