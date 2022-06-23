#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
#define vi vector<int> 
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define qi queue<int>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair

void build(int arr[], int tree[], int nd, int st, int end){
	if(st == end){
		tree[nd]=arr[st];
	}else{
		int mid=(st+end)/2;
		int lnd = 2*nd+1;
		int rnd = 2*nd+2;
		build(arr,tree,lnd,st,mid);
		build(arr,tree,rnd,mid+1,end);
		tree[nd]=tree[lnd]+tree[rnd];
	}
	
	
}
void upd(int arr[], int tree[], int nd, int st, int end,int idx, int val){
	if(st == end){
		arr[idx]=val;
		tree[nd]=val;
	}else{
		int mid=(st+end)/2;
		int lnd=2*nd+1;
		int rnd=2*nd+2;
		if(idx>=st && idx <= mid){
			upd(arr,tree,lnd,st,mid,idx,val);
		}else{
			upd(arr,tree,rnd,mid+1,end,idx,val);
		}
		tree[nd]=tree[lnd]+tree[rnd];
	}
} 
int query(int arr[], int tree[], int nd, int st, int end, int L, int R){
	if(R<st || L >end){
		return 0;
	}else if(st>=L && end <= R){
		return tree[nd];
	}else{
		int mid=(st+end)/2;
		int lnd=2*nd+1;
		int rnd=2*nd+2;
		int lsum=query(arr,tree,lnd,st,mid,L,R);
		int rsum=query(arr,tree,rnd,mid+1,end,L,R);
	}
	return lsum+rsum;
}
int main(){
    fastio;  
    return 0;
}