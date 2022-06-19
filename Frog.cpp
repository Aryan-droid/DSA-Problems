#include<bits/stdc++.h>
using namespace std;

const int a = 1e5+7;
int dp[a];

int frog(vector<int>height,int n){
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];
	int twojump;
	int onejump = frog(height,n-1) + abs(height[n] - height[n-1]);
	if(n>1)
		twojump = frog(height,n-2) + abs(height[n] - height[n-2]);
	dp[n] = min(onejump,twojump);
	return dp[n];
}


int main(){
	memset(dp,-1,sizeof(dp));
	vector<int> height= {30,10,60 , 10 , 60 , 50};
	int n=height.size();
	cout<<frog(height,n-1);
	return 0;
}