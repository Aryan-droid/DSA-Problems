#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;

	node(int val){
		data = val;
		left = right = NULL;
	}
};


void inorder(node *root){
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}

void preorder(node *root){
	if(root == NULL) return;

	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}

void postorder(node *root){
	if(root == NULL) return;
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
}

int nodecount(node *root){
	int total_node=0;
	if(root==NULL) return 0;
	return nodecount (root->left)+ nodecount(root->right) + 1;
}

int treeheight(node *root){
	if(root==NULL) return 0;
	int lh = treeheight (root->left);
	int rh = treeheight(root->right);
	 return 1 + max(lh,rh);
}

vector<vector<int>>levelorder(node *root){
	vector<vector<int>>ans;
	queue<node*>q;
	vector<int>level;
	if(root == NULL) return ans;
	q.push(root);
	 while(!q.empty()){
	 	int size = q.size();
	 	for(int i=0;i<size;i++){
		 	node *nodenew = q.front();
		 	q.pop();
		 	if(nodenew->left!=NULL) q.push(nodenew->left);
		 	if(nodenew->right!=NULL) q.push(nodenew->right);
		 	level.push_back(nodenew->data);
	 	}
	 	ans.push_back(level);
	 }
	 return ans;
}

int dia_height(node *root, int &diameter){
	if(root==NULL) return 0;

	int lh = dia_height(root->left, diameter);
	int rh = dia_height(root->right, diameter);

	diameter = max(diameter,lh+rh+1);
	return 1+ max(lh,rh);
}

int diafunc(node *root){
	int diameter = INT_MIN ;
	dia_height(root,diameter);
	return diameter;
}

int maxPathdown(node *root, int &maxi){
	if(root==NULL) return 0;
	int leftsum = max(0,maxPathdown(root->left, maxi));
	int rightsum = max(0,maxPathdown(root->right, maxi));
	maxi = max(maxi, leftsum + rightsum + root->data);
	return max(leftsum,rightsum) + root->data;
}

int maxpathsum(node *root){
	int maxi = INT_MIN ;
	maxPathdown(root,maxi);
	return maxi;
}


int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->left->left->left = new node(6);
	cout<<"PREORDER"<<endl;
	preorder(root);
	cout<<endl<<"INORDER"<<endl;
	inorder(root);
	cout<<endl<<"POSTORDER"<<endl;
	postorder(root);
	cout<<endl;
	// cout<<endl<<"LEVELORDER"<<endl;
	// vector<vector<int>>a=levelorder(root);
	// for(int i=0;i<a.size();i++){
	// 	for(int j=0;j<a[i].size();j++){
	// 	cout<<a[i][j]<<endl;
	// 	}
	// }
	cout<<"HEIGHT"<<endl;
	cout<<treeheight(root)<<endl;
	cout<<"NODE COUNT"<<endl;
	cout<<nodecount(root)<<endl;
	cout<<"DIAMETER"<<endl;
	cout<<diafunc(root)<<endl;
	cout<<"MAX PATH SUM"<<endl;
	cout<<maxpathsum(root);
	return 0;
}