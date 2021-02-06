#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define sz(a) (int)a.size()
#define print(v) cerr<<#v<<": ";for(auto &i:v) cout<<i<<" "; cout<<endl;

ll N=1e6+5;

void getNumber(vector<ll>&a,ll &res ,int s,ll num,ll idx=0){
	if(s==0){
		res+=num;
		return;
	}
	for(int i=idx;i<sz(a);i++){
		getNumber(a,res,s-1,num/a[i],i+1);
	}
}

void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll>a(k);
	for(ll &i:a)
		cin>>i;
	ll ans=0;
	for(int i=1;i<=k;i++){
		ll res=0;
		getNumber(a,res,i,n);
		if(i%2)
			ans+=res;
		else
			ans-=res;
		// cout<<res<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
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