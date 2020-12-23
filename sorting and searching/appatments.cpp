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

//multiset
void solve(){
	ll n,m,k,x;
	cin>>n>>m>>k;
	veci req(n);
	multiset<int>avail;
	for(int idx=0;idx<n;idx++)
		cin>>req[idx];
	for(int idx=0;idx<m;idx++){
		cin>>x;
		avail.insert(x);
	}
	sort(all(req));
	
	int cnt=0;

	for(int idx=0;idx<n;idx++){
		int val = req[idx];
		auto itr = avail.lower_bound(val-k);
		if(itr!=avail.end() && (*itr) <= val+k ){
			cnt++;
			avail.erase(itr);
		}
	}
	cout<<cnt<<endl;
}

//2 pointer
void solve2(){
	ll n,m,k;
	cin>>n>>m>>k;
	veci req(n), avail(m);
	for(int idx=0;idx<n;idx++)
		cin>>req[idx];
	for(int idx=0;idx<m;idx++)
		cin>>avail[idx];

	int i=0,j=0;
	sort(all(req));
	sort(all(avail));
	int cnt=0;
	while(i<n && j<m){
		if(req[i]-k<=avail[j] && req[i]+k>=avail[j]){
			cnt++;i++;j++;
		}
		else if(req[i]-k > avail[j]) j++;
		else i++;
	}
	cout<<cnt<<endl;
}

int main(){
	FAST;
	solve2();
	return 0;
}