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

ll getCost(vecll &len, ll reqLen){
	ll cost=0;
	for(ll idx=0;idx<size(len);idx++){
		cost+=abs(len[idx]-reqLen);
	}
	return cost;
}


void solve(){
	ll n;
	cin>>n;
	vecll len(n);
	for(ll idx=0;idx<n;idx++)
		cin>>len[idx];

	ll low=1,high=1e9+5,ans=getCost(len, high);
	while(true){
		ll part = (high-low)/3;
		ll m1 = low + part;
		ll m2 = high - part;
		// chk4(low, high, ans, part);
		if(part==0) break; 
		if(getCost(len, m1) > getCost(len, m2)){
			low = m1 + 1;
		}
		else{
			high = m2 - 1;
		}
	}
	for(ll val=low;val<=high;val++)
		ans =  min(ans, getCost(len, val));
	cout<<ans<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}