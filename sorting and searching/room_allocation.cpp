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

	vector<pll> arv(n);
	vector<pll> dept(n);

	ll a,b;
	for(int idx=0;idx<n;idx++){
		cin>>a>>b;
		arv[idx] = {a, idx};
		dept[idx] = {b, idx};
	}
	sort(all(arv));
	sort(all(dept));

	vecll result(n);
	set<ll> empty;
	ll i=0,j=0,cnt=1,timer=0;

	while(i<n){
		timer = min(arv[i].F, dept[j].F);

		if(timer==arv[i].F){
			if(size(empty)==0) empty.insert(cnt);
			result[arv[i++].S] = *empty.begin();
			empty.erase(empty.begin());
			cnt++;
		}
		else{
			cnt--;
			empty.insert(result[dept[j++].S]);
		}
	}
	cout<<*max_element(all(result))<<endl;
	for (ll room:result)
		cout<<room<<" ";
	cout<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}