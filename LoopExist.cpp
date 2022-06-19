#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+10;
vector<int>g[n];
bool visited[n];

bool dfs(int vertex, int par){
    bool isloopexist = false;
    visited[vertex]=true;
    for(int child:g[vertex]){
        if(visited[child] && child==par) continue;
        if(visited[child]) return true;

        isloopexist |= dfs(child,vertex);
    }
    return isloopexist;
}

int main(){
    int n,e,v1,v2,cnt=0;
    cin>>n>>e;
    bool isloopexist=false;
    for(int i=1;i<=e;i++){
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        if(dfs(i,0)){
            isloopexist = true;
            break;
        }
    }
    cout<<isloopexist;
        
 	return 0;
 }