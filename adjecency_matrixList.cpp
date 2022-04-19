/*
    There are flight paths between cities. If there is a flight between city A and city B then
    there is an edge between the cities. The cost of the edge can be the time that flight take to reach
    city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node
    can be represented by airport name or name of the city. Use adjacency list representation of the
    graph or use adjacency matrix representation of the graph. Justify the storage representation
    used.
*/

#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class GraphRepresentation{
    
    private:
    
    int noOfCities;
    string cities[MAX];
    int fuelRequired[MAX][MAX];
    
    public:

    GraphRepresentation(int noOfCities){
        this->noOfCities = noOfCities;
    }
    
    void setStations(){

        for(int i=0; i<noOfCities; i++){
            cout<<"Enter "<<i<<"st"<<" City : ";
            cin>>cities[i];
        }
        cout<<"\n";

    }

    void setFlightsBetweenStations(){

        int temp;
        
        for(int i=0; i<noOfCities; i++){
            for(int j=0; j<noOfCities; j++){
                
                cout<<"Press 1 if there is flight between "<<cities[i]<<" to "<<cities[j]<<" : ";
                cin>>temp;

                if(temp == 1){
                    cout<<" Enter fuel required for flight from "<<cities[i]<<" to "<<cities[j]<<" in Ltrs : ";
                    cin>>fuelRequired[i][j];
                }   
            }
        }
    }

    void printAdjecencyMatrix(){
        
        cout<<"\nAdjecency Matrix Representation : \n";
        cout<<"(City)";
        for(int i=0; i<noOfCities; i++)
            cout<<cities[i]<<"\t";
            
        cout<<"\n";
        for(int i=0; i<noOfCities; i++){

            cout<<cities[i]<<"\t";

            for(int j=0; j<noOfCities; j++)
                cout<<fuelRequired[i][j]<<"\t";

            cout<<"\n";
            
        }
    }

    void printAdjecencyList(){

        cout<<"\nAdjecency List Representation : \n";
        
        cout<<"\nCities";
            
        for(int i=0; i<noOfCities; i++){

            cout<<"\n"<<cities[i]<<"\t";

            for(int j=0; j<noOfCities; j++){
                
                if(fuelRequired[i][j] != 0)
                    cout<<" -> "<<cities[j]<<" | "<<fuelRequired[i][j];
    
            }

            cout<<" -> NULL";        
        }
        cout<<"\n";
    }
};

int main(){

    int n;
    
    cout<<"Enter Number of Cities : ";
    cin>>n;

    GraphRepresentation a(n);

    a.setStations();
    a.setFlightsBetweenStations();
    a.printAdjecencyMatrix();
    a.printAdjecencyList();

    return 0;

}
