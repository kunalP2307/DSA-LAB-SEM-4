#include<iostream>
#include <iomanip>
#include <ios>
#include <string>
#include<sstream>
#define MAX 100
using namespace std;

class ChainNode{    

    long int teleNumber;
    string name;
    ChainNode* nextPtr;

    public:

    ChainNode() {}

    ChainNode(long int teleNumber,string name){
        this->teleNumber = teleNumber;
        this->name = name;
        nextPtr = NULL;
    }

    static void addChainElement(ChainNode* &head,long int teleNumber,string name){
        
        ChainNode* chainNode = new ChainNode(teleNumber,name);

        if(head == NULL){
            head = chainNode;
            return;
        }
        
        ChainNode* temp = head;

        while(temp->nextPtr != NULL)
            temp = temp->nextPtr;
        
        temp->nextPtr = chainNode;

    }
    
    static string searchKeyInChain(ChainNode* head,long int key){

        ChainNode* temp = head;
        int searchingComplexity = 1;

        while(temp != NULL){
            cout<<temp->teleNumber;
            searchingComplexity += 1;
            if(temp->teleNumber == key)
                return temp->name;
            temp = temp->nextPtr;
        }
        return "";

    }
    
    static void deleteNode(ChainNode* head,long int key){
        
        ChainNode* temp = head;
            
        if(head->nextPtr == NULL){
            head = NULL;
            free(temp);
            return;
        }

        while(temp->teleNumber != key)
            temp = temp -> nextPtr;
        
        ChainNode* delNode = temp->nextPtr;
        free(delNode);

        if(temp->nextPtr->nextPtr == NULL)
            temp->nextPtr = NULL;

        temp->nextPtr = temp->nextPtr->nextPtr;
        
        cout<<"\nDeletion Complete..";

    }

    static void displayChain(ChainNode* head){

        ChainNode* temp = head;

        while(temp != NULL) {
            cout<<" "<<temp->teleNumber<<" | "<<temp->name<<" -> ";
            temp = temp->nextPtr;
        }
        cout<<" X";
    }

};

class StringHashTable{

    string name[MAX];
    long int hashTable[MAX];
    ChainNode *chains[MAX];
    int size;
    
    public:

    StringHashTable(){

        for(int i=0; i<MAX; i++){
            chains[i] = new ChainNode();
            chains[i] = NULL;
            hashTable[i] = -1;
            name[i] = ""; 
        }

    }

    void setTableSize(){
        cout<<"Enter No of Elements to be placed in Hash Table : ";
        cin>>size;
    }

    int getHashCode(long int ele){

        string intStr = to_string(ele);
        int mid = intStr.length()/2;
        string strHashConde = "";
        strHashConde += intStr[mid];
        strHashConde += intStr[mid - 1];
        //cout<<strHashConde;
        return stoi(strHashConde);
        
    }       

    string searchKey(long int key){

        int hashCode = getHashCode(key);
    
        if(hashTable[hashCode] == -1)
            return "";
        else if(hashTable[hashCode] != key && chains[hashCode] == NULL)
            return "";
        else if(hashTable[hashCode] == key){
            cout<<name[hashCode];
            return name[hashCode];
        }
        else
            return ChainNode::searchKeyInChain(chains[hashCode],key);
    
    }

    bool deleteRecord(long int key){
        
        if(searchKey(key) == ""){
            cout<<"\nRecord Not present in Hash Table..";
            return false;
        }

        int hashCode = getHashCode(key);
        
        if(hashTable[hashCode] == key){
            hashCode[hashTable] = -1;
            name[hashCode] = "";
            cout<<"\nDeletion Complete..";
            return 1;
        }
        else {
            ChainNode::deleteNode(chains[hashCode],key);
        }
    }

    void addRecord(int long ele, string name){
        
        ChainNode chain;
        
        int hashCode = getHashCode(ele);

        if(hashTable[hashCode] == -1){
            hashTable[hashCode] = ele;
            this->name[hashCode] = name;
        }   

        else
            ChainNode::addChainElement(chains[hashCode],ele,name);    
              
    }

    void displayHashTable(){
        
        cout<<"\n\tHash Table"<<endl<<endl;
        cout<<"  Array "<<"|   Chains"<<endl;
        cout<<"  -------------------";
        for(int i=0; i<MAX; i++){
            cout<<endl<<setw(10)<<hashTable[i]<<" | "<<name[i]<<" ->";
            ChainNode::displayChain(chains[i]);
        }
        cout<<endl;
    }
};

int main(){

    StringHashTable table;
    long int mobNo;
    string name;
    int n;
    
    cout<<"Enter the number of Elements you want to Insert In Hash Table : ";
    cin>>n;
    for(int i=0; i<n; i++)  {
        cout<<"Enter Client Name : ";
        cin>>name;
        cout<<"Enter Mobile Number : ";
        cin>>mobNo;
        table.addRecord(mobNo,name);
    }

    int choice;

    do{
        cout<<"\n-------------------------\n";
        cout<<"->1 Insert Record"
            <<endl<<"->2 Search Record"
            <<endl<<"->3 Delete Record"
            <<endl<<"->4 Display"<<endl;
        
        cout<<"Select Operation : ";
        cin>>choice;

        switch (choice){
        
        case 1:{

            cout<<"Enter Client Name : ";
            cin>>name;
            cout<<"Enter Mobile Number : ";
            cin>>mobNo;
            table.addRecord(mobNo,name);

            break;
        }

        case 2:{
        
            cout<<"Enter Telephone Number To Search In Hash Table : ";
            cin>>mobNo;

            string clientName = table.searchKey(mobNo);
    
            if(clientName == "")
                cout<<"\nElement Not Present in Hash Table";
            else
                cout<<"\nElement is Present in Hash Table "<<endl<<"Name of Client : "<<clientName<<endl;
    
            break;
        }
        
        case 3:{

            cout<<"Enter Telephone Number To Delete In Hash Table : ";
            cin>>mobNo;
            table.deleteRecord(mobNo);

            break;
        }

        case 4:{
            table.displayHashTable();
            break;
        }
        default:
            cout<<"\n Invalid Choice Try Again..!";
            break;
        }
        
        cout<<"\n Do you want to continue (Y/N) : [1/0] : ";
        cin>>choice;
            
    }while(choice == 1);

    cout<<"\nExited!";
    return 0;
}