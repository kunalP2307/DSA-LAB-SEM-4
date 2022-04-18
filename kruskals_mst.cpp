#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class Edge{

    public :
        char source;
        char destination;
        int weight;

    Edge(){

    }

    Edge(char source, char destination, int weight){

        this->source = source;
        this->destination = destination;
        this->weight = weight;

    }

};

class Graph{

    char vertices[MAX];
    Edge edges[MAX],mst[MAX];
    int noOfEdges,noOfvertices;

    public:

    Graph(int noOfEdges,int noOfvertices){

        this->noOfEdges = noOfEdges;
        this->noOfvertices = noOfvertices;
        setVertices();
        setEdges();

    }

    void setVertices(){

        cout<<"Enter the Vertices : ";
        for(int i=0; i<noOfvertices; i++)
            cin>>this->vertices[i];

    }

    void setEdges(){
    
        char source,destination;
        int weight;
            
        for(int i=0; i<noOfEdges; i++){

            cout<<"Enter Source Vertex , Destination Vertex, Weight for "<<i+1<<"th Edge : ";
            cin>>source>>destination>>weight;
            Edge e(source,destination,weight);

            this->edges[i] = e;       

        }
    }

    void sortEdges(){

        for(int i=0; i<noOfEdges; i++){
            for(int j=0; j < noOfEdges; j++){
                
                if(edges[i].weight < edges[j].weight){
                    
                    Edge temp = edges[i];
                    edges[i] = edges[j];
                    edges[j] = temp;

                }
            }
        }
    }  

    bool isEdgeFormingCycle(Edge e,int n){
        
        if(n == 0)
            return false;
        
        else{
            
            for(int i=0; i<n; i++){
                if(mst[i].source == e.destination)
                    return true;
            }

        }
        return false;

    }
    
    void findMSTUsingKruskals(){

        cout<<"\nGiven Graph : \n";
        printEdges(edges,noOfEdges);

        sortEdges();
        int i=0;
        int j=0;

        while(j < noOfvertices - 1) {

            if(!isEdgeFormingCycle(edges[i],j)){
                mst[j] = edges[i];
                j++;
            }

            i++;

        }

        cout<<"\nMinimum Spannig Tree for the Given Tree is : \n";
        printEdges(mst,noOfvertices-1);
        
        int mstCost = 0;
        for(int i=0; i<noOfvertices-1; i++)
            mstCost += mst[i].weight;

        cout<<"\nWeight of MST : "<<mstCost<<"\n";

    }

    void printEdges(Edge edges[],int n){
        
        cout<<"Source\tDestination\tWeight\n";
        for(int i=0; i<n; i++)
            cout<<edges[i].source<<"\t"<<edges[i].destination<<"\t"<<edges[i].weight<<"\n";

    }
};

int main(){

    Graph g(3,3);

    g.findMSTUsingKruskals();

    return 0;
}
