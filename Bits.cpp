#include<bits/stdc++.h>
using namespace std;

void binary(int n){
	cout<<n<<": ";
	for(int i=10;i>=0;--i){
		cout<<((n>>i) & 1);
	}
}

int main(){
	// for(int j=1;j<=10;j++){
	// 	binary(j);
	// 	cout<<endl;
	// }
	int n=65;
	
	int a= (n | (1<<5));
	b=binary(a);
	cout<<char(b);
}