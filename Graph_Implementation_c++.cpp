#include<bits/stdc++.h>
using namespace std;

// To get adjacency list representation of a graph 

void getAdjacencyList(vector<int>adj[],pair<int,int>edge){
    adj[edge.first].push_back(edge.second);
    adj[edge.second].push_back(edge.first);
}

//To print adjacency List of a graph 

void printAdjacencyList(vector<int>adj[],int n){
    for(int node=0;node<n;node++){
        cout<<node;
        for(int list:adj[node]){
            cout<<"->"<<list;
        }
        cout<<endl;
    }
}

void BFS(vector<int>adj[],vector<bool>&visited,int src){
    visited[src]=true;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int node:adj[curr]){
            if(visited[node]==false){
                visited[node]=true;
                q.push(node);
            }
        }
    }

}

void DFS(vector<int>adj[],vector<bool>&visited,int src){
    visited[src]=true;
    cout<<src<<" ";
    for(int node: adj[src]){
        if(visited[node]==false){
            DFS(adj,visited,node);
        }
    }
}


int main(){
    int n;
    cout<<"Enter the total no of nodes"<<endl;
    cin>>n;
    int e;
    cout<<"Enter No of edges"<<endl;
    cin>>e;
    cout<<"Enter all edges"<<endl;
    vector<pair<int,int>>edges;
    while(e--){
        pair<int,int>temp;
        int x,y;
        cin>>x>>y;
        temp.first=x;
        temp.second=y;
        edges.push_back(temp);
    }

    vector<int>adj[n];
    for(pair<int,int>edge:edges){
        getAdjacencyList(adj,edge);
    }

    //printAdjacencyList(adj,n);
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            DFS(adj,visited,i);
        }
    }

    return 0;

}