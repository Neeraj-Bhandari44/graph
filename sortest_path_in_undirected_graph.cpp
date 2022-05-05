#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void find_dis(vector<int>adj[],int v,int s,int dis[]){
    queue<int>q;
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    q.push(s);
    visited[s]=true;
    dis[s]=0;
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        for(int x :adj[u]){
            if(visited[x]==false){
                dis[x]=dis[u]+1;
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
int main(){
    int u,v;
    cout<<"enter the no of vertices"<<endl;
    cin>>v;
    cout<<"enter the no of edges"<<endl;
    cin>>u;
    vector<int>adj[v];
    int x,y;
    for(int i=0;i<u;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int dis[v];
    for(int i=0;i<v;i++){
        dis[i]=-1;
    }
    int s;
    cout<<"enter the starting node"<<endl;
    cin>>s;
    find_dis(adj,v,s,dis);
    for(int i=0;i<v;i++){
        cout<<dis[i]<<" ";
    }
}