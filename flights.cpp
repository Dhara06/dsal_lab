#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void display(vector<vector<int>>adj,int numCities, string cities[]){
    cout << "\nAdjacency Matrix (cost of flights between cities):\n\n";
    cout << setw(12) << " ";
    for (int i = 0; i < numCities; i++)
        cout << setw(12) << cities[i];
    cout << endl;

    for (int i = 0; i < numCities; i++) {
        cout << setw(12) << cities[i];
        for (int j = 0; j < numCities; j++) {
            if (adj[i][j] == 0)
                cout << setw(12) << "-";
            else
                cout << setw(12) << adj[i][j];
        }
        cout << endl;
    }
}


int main(){
    int n;
    char ans;
    cout<<"enter no. of cities: ";
    cin>>n;
    string cities[n];
    for(int i = 0; i<n ;i++){
        cout<<"\nenter "<<i+1<<" City: ";
        cin>>cities[i];
    }
    vector<vector<int>>adj_mat(n,vector<int>(n,0));
    for(int i = 0;i<n; i++){
        for(int j = 0;j<n;j++){
            cout<<"is there flight from "<<cities[i]<<" to "<<cities[j]<<"?"<<endl;
            cin>>ans;
            if(ans =='y'|| ans == 'Y'){
                cout<<"Enter fuel: ";
                cin>>adj_mat[i][j];
            }
            else{
                adj_mat[i][j]=0;
            }
        }
    }
    display(adj_mat,n,cities);
    return 0;
}