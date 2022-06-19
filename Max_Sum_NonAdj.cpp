#include<bits/stdc++.h>
using namespace std;

const int a =1e5+7;
int dp[a];

int Max_sum(vector<int>&arr, int n){
	if(n==0) return arr[n];
	if(n<0) return 0;
	if(dp[n]!=-1) return dp[n];
	int take = Max_sum(arr,n-2) + arr[n];
	int ntake = Max_sum(arr,n-1);
	return dp[n]=max(take,ntake);

}

int main(){
	memset(dp,-1,sizeof(dp));
	vector<int>arr= {2,1,4,9};
	int n = arr.size()-1;
	cout<<Max_sum(arr,n);
	return 0;
}