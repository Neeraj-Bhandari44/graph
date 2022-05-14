#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void topolgical_sort(vector<int>adj[],int v,int indegree[])
{
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x:adj[u])
        {
            indegree[x]=indegree[x]-1;
            if(indegree[x]==0)
            q.push(x);
        }
    }
}
int main()
{
    int v,u;
    cin>>v>>u;
    int indegree[v]={0};
    vector<int>adj[v];
    for(int i=0;i<u;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    topolgical_sort(adj,v,indegree);
}