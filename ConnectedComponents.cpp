#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+10;
vector<int>g[n];
bool visited[n];
vector<int>C_CC;
vector<vector<int>>CC;

void dfs(int vertex){
    visited[vertex]=true;
    C_CC.push_back(vertex);
    for(int child:g[vertex]){
        if(visited[child]) continue;

        dfs(child);
    }
}

int main(){
    int n,e,v1,v2,cnt=0;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        C_CC.clear();
        dfs(i);
        CC.push_back(C_CC);
        cnt++;
    }
    cout<<"Total Connected Components: "<<cnt<<endl;
 	for(auto i:CC){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
 	return 0;
 }