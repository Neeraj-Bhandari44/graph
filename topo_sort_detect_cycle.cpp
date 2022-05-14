#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool topo_cycle(vector<int>adj[],int v,int indegree[])
{
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto x:adj[u]){
            indegree[x]=indegree[x]-1;
            if(indegree[x]==0)
            q.push(x);
            count++;
        }
    }
    return (count!=v);
}
int main()
{
    int v,u;
    cin>>v>>u;
    vector<int>adj[v];
    int indegree[v]={0};
    for(int i=0;i<u;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    bool a=topo_cycle(adj,v,indegree);
    if(a==1)
    cout<<"cycle found"<<endl;
    else{
        cout<<"no cycle"<<endl;
    }
}