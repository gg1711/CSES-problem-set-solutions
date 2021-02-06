#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod=1e9+7;
ll N=1e6+5;

ll power(ll a, ll b){
	if(b==0) return 1;
	ll temp=power(a,b/2);
	temp = (temp*temp)%mod;
	if(b%2)temp*=a;
	return temp%mod;
}

ll inverse(ll a){
	return power(a,mod-2);
}

ll series(ll a, ll x){
	return ((power(a,x+1)-1)*inverse(a-1))%mod;
}

void solve(){
	ll n;
	cin>>n;
	ll total=1;
	vector<ll>nums(n), times(n);
	for(int i=0;i<n;i++){
		cin>>nums[i]>>times[i];
		total*=(times[i]+1);
		total%=mod;
	}
	ll sum=1;
	for(int i=0;i<n;i++){
		sum*=series(nums[i],times[i]);
		sum%=mod;
	}

	/*
	this method is correct but problem is inverse of 2 for (mod-1) doesn't exist
	thus we avoid division by times[i]+1 and multiply by pre and suff array
	ll ptotal=1;
	ll pmod=mod-1;
	for(int i=0;i<n;i++){
		ptotal*=(times[i]+1);
		ptotal%=pmod;
	}

	for(int i=0;i<n;i++){
		prod*=power(nums[i],((times[i]*ptotal)/2)%pmod);
		prod%=mod;
	}
	*/
	ll prod=1;
	vector<ll> pre(n+1,1),suff(n+1,1);
	ll pmod=mod-1;
	for(ll i=1;i<=n;i++)
		pre[i] = pre[i-1]*(times[i-1]+1)%pmod;
	
	for(ll i=n-2;i>-1;i--)
		suff[i] = suff[i+1]*(times[i+1]+1)%pmod;

	for(int i=0;i<n;i++){
		prod = prod * power(nums[i],(times[i]*(times[i]+1)/2)%pmod * pre[i]%pmod * suff[i]%pmod) %mod;
	}

	cout<<total<<" "<<sum<<" "<<prod<<endl;
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