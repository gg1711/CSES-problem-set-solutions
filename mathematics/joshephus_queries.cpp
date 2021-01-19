#include<bits/stdc++.h>
using namespace std;

#define ll long long int


void solve(){
	ll n,k;
	cin>>n>>k;
	ll pow = 2;
	int cnt=0;
	while(cnt + n/pow <k){
		cnt += (n/pow);
		pow*=2;
	}
}


int main(){
	ll q;
	cin>>q;
	while(q--){
		solve();
	}
}