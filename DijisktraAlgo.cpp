#include<bits/stdc++.h>
using namespace std;

const int n=1e5+7;
const int INF=1e7+5;
vector<pair<int,int>>g[n];
vector<bool>vis[n];
set<pair<int,int>>st;
vector<int>dist;

void dijisktra(int source){
	st.insert({0,source});
	dist[source]=0;
	while(st.size()>0){
		auto node = *st.begin();
		int v_wt = node.first;
		int v = node.second;
		st.erase(st.begin());
		if(vis[v]) continue;
		vis[v]=1;
		for(auto child : g[v]){
			if(dist[v] + child.second  < dist[child.first])
				dist[child.first] = dist[v] + child.second;
				st.insert({dist[child.first],child.first});
		}
	}
	for(int ans=1;ans<dist.size();ans++){
		cout<<" Weight: "<<ans<<endl;
	}
}

int main(){
	int e,v,x,y,wt;
	cin>>e>>v;
	for(int i=1;i<=v;i++){
		cin>>x>>y>>wt;
		g[x].push_back({wt,y});
	}
	dijisktra(1);
	
}