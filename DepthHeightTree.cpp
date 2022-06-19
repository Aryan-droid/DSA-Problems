#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+10;
vector<int>g[n];
int depth[n],height[n];

void dfs(int vertex,int par=0){
	for(int child : g[vertex]){
		if(child==par) continue;
		depth[child] = depth[vertex]+1;
		dfs(child,vertex);
		height[vertex]=max(height[vertex],height[child]+1);
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
	dfs(1);
	for(int j=1;j<=n;j++){

		cout<<"Depth of node "<<j<<": "<<depth[j]<<endl;
		cout<<"Height of node "<<j<<": "<<height[j]<<endl;
	}

}