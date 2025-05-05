#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
void BFS(int start){
    queue<int> q;
    vector<bool> visited(n,false);
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<< " ";
        for(int i = 0;i<n;i++){
            if(adj[node][i]==1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }

}

void DFS(int start){
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(start);
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(!visited[node]){
            cout<<node<<" ";
            visited[node] =true;
        }
        for(int i = 0;i<n;i++){
            if(adj[node][i] ==1 && !visited[i] ){
                s.push(i);
            }
        } 

    }
}

int main(){
    int u,v;
    cout<<"enter no. of vertices: ";
    cin>>n;
    cout<<"Enter no. of edges: ";
    cin>>m;
    adj.assign(n, vector<int>(n,0));
    cout<<"enter the edges (u,v)";
    for(int i = 0; i <m;i++){
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int st;
    cout<<"Enter start vertices: ";
    cin>>st;
    cout<<"BFS: "<<endl;
    BFS(st);
    cout<<"DFS: "<<endl;
    DFS(st);
    return 0;
}