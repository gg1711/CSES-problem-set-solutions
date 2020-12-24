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
	ll n,m,val;
	cin>>n>>m;
	multiset<ll>price;
	vecll traveller(m);
	vecll result(m);

	for(int idx=0;idx<n;idx++){
		cin>>val;
		price.insert(-val);
	}
	for(int idx=0;idx<m;idx++)
		cin>>traveller[idx];

	for(int idx=0;idx<m;idx++){
		multiset<ll>::iterator itr = price.lower_bound(-traveller[idx]);
		if(itr!=price.end()){
			result[idx] = -(*itr);
			price.erase(itr);
		}
		else 
			result[idx]=-1;
	}
	for(ll value:result)
		cout<<value<<endl;

}

int main(){
	FAST;
	solve();
	return 0;
}