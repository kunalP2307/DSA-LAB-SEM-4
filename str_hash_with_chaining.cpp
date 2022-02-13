#include<iostream>
#include <iomanip>
#include <ios>
#define MAX 10
using namespace std;

class ChainNode{

    string name;
    ChainNode* nextPtr;

    public:

    ChainNode() {}

    ChainNode(string name){
        this->name = name;
        nextPtr = NULL;
    }

    static void addChainElement(ChainNode* &head,string name){
        
        ChainNode* chainNode = new ChainNode(name);

        if(head == NULL){
            head = chainNode;
            return;
        }
        
        ChainNode* temp = head;

        while(temp->nextPtr != NULL)
            temp = temp->nextPtr;
        
        temp->nextPtr = chainNode;

    }
    
    static int searchKeyInChain(ChainNode* head,string key){

        ChainNode* temp = head;
        int searchingComplexity = 1;

        while(temp != NULL){
            cout<<temp->name;
            searchingComplexity += 1;
            if(temp->name == key)
                return searchingComplexity;
            temp = temp->nextPtr;
        }
        return -1;

    }

    static void displayChain(ChainNode* head){

        ChainNode* temp = head;

        while(temp != NULL) {
            cout<<" "<<temp->name<<" -> ";
            temp = temp->nextPtr;
        }
        cout<<" X";
    }

};

class StringHashTable{

    string hashTable[MAX];
    ChainNode *chains[MAX];
    int size;
    
    public:

    StringHashTable(){
        for(int i=0; i<MAX; i++){
            chains[i] = new ChainNode();
            chains[i] = NULL;
            hashTable[i] = "-X-";
        }
    }

    void setTableSize(){
        cout<<"Enter No of String Elements to be placed in Hash Table : ";
        cin>>size;
    }

    int getAsciiCode(string str){

        int sum = 0;
        for(int i=0; i<size; i++)
            sum += (int)(str[i]);
        
        return sum;
 
    }     

    int getHashCode(string str){

        int asciiEqui = getAsciiCode(str);
        return asciiEqui % size;

    }   

    int searchKey(string key){

        int hashCode = getHashCode(key);
    
        if(hashTable[hashCode] == "-X-")
            return -1;
        else if(hashTable[hashCode] != key && chains[hashCode] == NULL)
            return -1;
        else if(hashTable[hashCode] == key)
            return 1;
        else
            return ChainNode::searchKeyInChain(chains[hashCode],key);
    
    }
    void storeElementsInHashTable(){
        
        string str;
        ChainNode chain;
        for(int i=0; i<size; i++){
            cout<<"Enter String : ";
            cin>>str;
            int hashCode = getHashCode(str);

            if(hashTable[hashCode] == "-X-")
                hashTable[hashCode] = str;   

            else
                ChainNode::addChainElement(chains[hashCode],str);    
        }      
    }

    void displayHashTable(){
        
        cout<<"\n\tHash Table"<<endl<<endl;
        cout<<"  Array "<<"|   Chains"<<endl;
        cout<<"  -------------------";
        for(int i=0; i<size; i++){
            cout<<endl<<setw(10)<<hashTable[i]<<" ->";
            ChainNode::displayChain(chains[i]);
        }
        cout<<endl;
    }
};

int main(){

    StringHashTable table;
    table.setTableSize();
    table.storeElementsInHashTable();
    table.displayHashTable();
    cout<<table.searchKey("patil");
    
    return 0;
}

