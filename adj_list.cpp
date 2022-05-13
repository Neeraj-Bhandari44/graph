#include<iostream>
#include<vector>
using namespace std;
void add_edge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int>adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<"conneected edges from "<<i<<" ->";
        for(int x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main()
{
int v,u;
cout<<"enter the no of vertices"<<endl;
cin>>v;
cout<<"enter the no of edges"<<endl;
cin>>u;
vector<int>adj[v];
cout<<"enter the edges"<<endl;
for(int i=0;i<u;i++)
{
    int x,y;
    cin>>x>>y;
    // adj[x].push_back(y);
    // adj[y].push_back(x);
    add_edge(adj,x,y);
}
print(adj,v);
return 0;
}
/*output->
enter the no fo vertices
6
enter the no of edges
7
enter the edges
0 1
0 2
1 3
2 4
3 5
4 5
0 5
conneected edges from 0 ->1 2 5
conneected edges from 1 ->0 3
conneected edges from 2 ->0 4
conneected edges from 3 ->1 5
conneected edges from 4 ->2 5
conneected edges from 5 ->3 4 0
*/