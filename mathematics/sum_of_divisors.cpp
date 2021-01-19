#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod=1e9+7;
ll N=1e6+5;
void solve(){
	ll n;
	cin>>n;

	ll sqn=sqrt(n);
	ll sum=0;
	for(ll i=1;i<=n;i++){
		sum += (n/i)*i;
		sum%=mod;
	}
	cout<<sum<<endl;
}

int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	auto start = chrono::high_resolution_clock::now();
	solve();
	auto stop = chrono::high_resolution_clock::now(); 
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
    cerr << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
	return 0;
}