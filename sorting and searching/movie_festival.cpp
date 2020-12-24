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

bool compare(pll &a, pll &b){
	if(a.S==b.S)
		return a.F<b.F;
	return a.S < b.S;
}

void solve(){
	ll n,a,b;
	cin>>n;
	vector<pll> movies(n);
	for(int idx=0;idx<n;idx++){
		cin>>a>>b;
		movies[idx]={a,b};
	}
	sort(all(movies), compare);
	ll i=0;
	ll timer=0, cnt=0;
	while(i<n){
		if(movies[i].F >= timer){
			timer = movies[i].S;
			cnt++;
		}
		i++;
	}
	cout<<cnt<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}