#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cout << fixed << setprecision(10);

#define chk(a) cerr<<"check "<<#a<<" = "<<a<<endl;
#define chk2(a,b) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<endl;
#define chk3(a,b,c) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<endl;
#define chk4(a,b,c,d) cerr<<"check "<<#a<<" = "<<a<<" , "<<#b<<" = "<<b<<" , "<<#c<<" = "<<c<<" , "<<#d<<" = "<<d<<endl;
#define print(v) cerr<<#v<<": ";for(auto &i:v) cout<<i<<" "; cout<<endl;

#define ll	long long int
#define ld   long double
#define pii  pair<int,int>
#define pll pair<ll,ll>
#define veci vector<int>
#define vecll vector<ll>
#define all(a) a.begin(),a.end()
#define pb push_back
#define mod 1000000007
#define F first
#define S second
#define size(a)	(int)a.size()


void solve(){
	ll n;
	cin>>n;
	vecll songs(n);
	for(int idx=0;idx<n;idx++)
		cin>>songs[idx];

	map<ll,ll> mp;
	//to store mapping of song id and last idx in which it is found

	ll ans=0, last=0;
	for(int idx=0;idx<n;idx++){
		ll id = songs[idx];
		if(mp.count(id)> 0 && mp[id]>=last)
			last = mp[id]+1;
		mp[id]=idx;
		ans = max(ans, idx-last+1);
	}
	cout<<ans<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}