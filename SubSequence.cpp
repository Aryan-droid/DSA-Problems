#include<bits/stdc++.h>
using namespace std;

void subseq(int ind,int s[], int length, vector<int> &ans){
	
	if(ind==length){
		for(auto it:ans){
			cout<<it;
		}
	if(ans.size()==0) cout<<"{}";
	cout<<endl;
	return;
	}
	subseq(ind+1,s,length,ans);
	ans.push_back(s[ind]);
	subseq(ind+1,s,length,ans);
	ans.pop_back();
}

int main(){
	int s[] = {1,2,3,4};
	int length = 4;
	vector<int> ans;
	subseq(0,s,length,ans);
	return 0;
}