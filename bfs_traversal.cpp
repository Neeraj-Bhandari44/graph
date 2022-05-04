#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<int>vec[],int v,int s)
{
    bool visited[v];
    for(int i=0;i<v;i++){
      visited[i]=false;
    }
queue<int>q;
visited[s]=true;
q.push(s);
while(q.empty()==false){
int u=q.front();
q.pop();
cout<<u<<" ";
for(int x:vec[u])
{
    if(visited[x]==false){
        visited[x]=true;
        q.push(x);
    }
}
}
}
int main()
{
    int v,u;
    cout<<"enter the no of vertes"<<endl;
    cin>>v;
    cout<<"enter the no of edges"<<endl;
    cin>>u;
    int x,y;
    vector<int>vec[v];
    for(int i=0;i<u;i++){
        cin>>x>>y;
       vec[x].push_back(y);
       vec[y].push_back(x);
    }
    cout<<"enter the starting point"<<endl;
    int s;
    cin>>s;
    bfs(vec,v,s);
}