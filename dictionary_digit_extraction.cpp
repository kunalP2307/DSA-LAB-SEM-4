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
    void storeElementsInHashTable(){
        
        long int ele;
        string name;
        ChainNode chain;
        for(int i=0; i<size; i++){
            cout<<"Enter Client Name : ";
            cin>>name;
            cout<<"Enter Telephone No : ";
            cin>>ele;
            int hashCode = getHashCode(ele);

            if(hashTable[hashCode] == -1){
                hashTable[hashCode] = ele;
                this->name[hashCode] = name;
            }   

            else
                ChainNode::addChainElement(chains[hashCode],ele,name);    
        }      
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
    long int key;
    table.setTableSize();
    table.storeElementsInHashTable();
    table.displayHashTable();

    cout<<"Enter Telephone Number To Search In Hash Table : ";
    cin>>key;

    string name = table.searchKey(key);
    
    if(name == "")
        cout<<"\nElement Not Present in Hash Table";
    else
        cout<<"\nElement is Present in Hash Table "<<endl<<"Name of Client : "<<name<<endl;
    return 0;
}