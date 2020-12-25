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
	ll x,n,val;
	cin>>x>>n;

	set<ll> st; //holds info about light placed
	multiset<ll> mst; //keeps set of length btw traffic lights

	st.insert(0);
	st.insert(x);

	mst.insert(x);
	
	for(ll idx=0;idx<n;idx++){
		cin>>val;
		auto itr1 = st.lower_bound(val);
		itr1--;
		auto itr2 = st.lower_bound(val+1);
		// chk3(*itr1, val, *itr2);
		mst.erase(mst.find(*itr2 - *itr1));

		mst.insert(val - *itr1);
		mst.insert(*itr2 - val);
		st.insert(val);
		cout<<*(mst.rbegin())<<" ";
	}

}

int main(){
	FAST;
	solve();
	return 0;
}