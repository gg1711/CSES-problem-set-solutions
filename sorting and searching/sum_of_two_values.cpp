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
	ll n,x,t1,t2;
	cin>>n>>x;
	vector<pll>a(n);
	for(int idx=0;idx<n;idx++){
		cin>>t1;
		a[idx] = {t1, idx+1};
	}

	sort(all(a));
	ll i=0,j=n-1;
	while(i<j){
		if(a[i].F+a[j].F<x) i++;
		else if(a[i].F+a[j].F>x) j--;
		else{
			cout<<a[i].S<<" "<<a[j].S<<endl;
			return;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}