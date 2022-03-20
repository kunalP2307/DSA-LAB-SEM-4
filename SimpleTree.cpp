#include<iostream>
using namespace std;

class TreeNode{

    
    public :    
    string data;
    TreeNode *leftPtr;
    TreeNode *rightPtr;

    TreeNode(string data){
        this->data = data;
        this->leftPtr = NULL;
        this->rightPtr = NULL;
    }

};

void display(TreeNode *head){
    

    if(head == NULL){
        return;
    }

    cout<<head->data<<"  ";
    display(head->leftPtr);
    display(head->rightPtr);
 
}

int main(){

    TreeNode *arr[100];                       

    string str;

    cout<<"Enter Year : ";
    cin>>str;
    arr[0] = new TreeNode(str);
    
    
    cout<<"Enter Name of First Book : ";
    cin>>str;
    arr[1] = new TreeNode(str);
    arr[0]->rightPtr = arr[1];

    cout<<"Enter Name of Second Book : ";
    cin>>str;
    arr[2] = new TreeNode(str);
    arr[0]->leftPtr = arr[2];

    cout<<"Enter Two Topics for Book1 : ";
    cin>>str;
    arr[3] = new TreeNode(str);
    arr[1]->leftPtr = arr[3];

    cin>>str;
    arr[4] = new TreeNode(str);
    arr[1]->rightPtr = arr[4];

    cout<<"Enter Two Topics for Book2 : ";
    cin>>str;
    arr[5] = new TreeNode(str);
    arr[2]->leftPtr = arr[5];

    cin>>str;
    arr[6] = new TreeNode(str);
    arr[2]->rightPtr = arr[6];

    cout<<"Tree Traversal : ";
    display(arr[0]);
    

    return 0;
}

/*

year----                SE
                |               |
books---       OOPS             OS
            |       |       |       |
topics---   Inheri  Cons    thread  process

*/