#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll N=1e6+5;
void solve(){
	ll n;
	cin>>n;
	vector<int>temp(N,0);
	ll num;
	for(int i=0;i<n;i++){
		cin>>num;
		temp[num]++;
	}
	
	for(int i=N;i>0;i--){
		ll cnt=0;
		for(ll j=i;j<N;j+=i)
			cnt+=temp[j];
		if(cnt>1){
			cout<<i<<endl;
			return;
		}
	}
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