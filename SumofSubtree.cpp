#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+10;
vector<int>g[n];
int sum[n];

void dfs(int vertex,int par=0){
	sum[vertex]=sum[vertex]+vertex;
	for(int child : g[vertex]){
		if(child==par) continue;		
		dfs(child,vertex);
		sum[vertex]=sum[vertex]+child;
	}
}

int main(){
	int n,e,v1,v2,q;
	cin>>q;
	cin>>n>>e;
	for(int i=1;i<=e;i++){
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1);
	for(int j=1;j<=n;j++){
		cout<<"Sum of node "<<j<<": "<<sum[j]<<endl;
	}

}