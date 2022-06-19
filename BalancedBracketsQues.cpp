#include<bits/stdc++.h>
using namespace std;

string isBalanced(string s) {
	unordered_map<char,int> symbols = {{'[',-1},{'(',-2},{'{',-3},{']',1},{')',2},{'}',3}};
	stack<char> s1;
	for(auto brackets : s){
		if(symbols[brackets]<0){
			s1.push(brackets);
		}
		else{
			if(s1.empty()) return "NO";
			char top = s1.top();
			s1.pop();
			if(symbols[top]+symbols[brackets]!=0) return "NO";

		}
	}
	if(s1.empty()) return "YES";
	return"NO";
}

 int main(){
 	int n;
 	string s;
 	cin>>n;
 	while(n--){
 		cin>>s;
 		cout<<isBalanced(s)<<endl;
 	}
 	return 0;
 }