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
#define sz(a)	(int)(a).size()

ll inf = 1e10;


//topDown
void solve2(){
	
}

//bottomUp
void solve(){
	ll n;
	cin>>n;
	vecll a(n);

	for(auto &i:a) cin>>i;

	set<int>st;
	
	for(auto val:a){
		auto itr = st.lower_bound(val);
		if(itr!=st.end()){
			st.erase(itr);
		}
		st.insert(val);
	}
	cout<<sz(st)<<endl;
}

int main(){
	FAST
	solve();
	return 0;
}