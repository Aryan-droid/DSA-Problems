#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+10;
vector<int>g[n];
bool visited[n];

void dfs(int vertex){
    cout<<vertex<<endl;
    visited[vertex]=true;
    for(int child:g[vertex]){
        if(!visited[child])
        cout<<"Parent "<<vertex<<" Child "<<child<<endl;
        if(visited[child]) continue;

        dfs(child);
    }
}

int main(){
    int n,e,v1,v2;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for(auto vertex:g[n]){
        dfs(vertex);
    }
 	

 	return 0;
 }