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
	ll n,x;
	cin>>n>>x;

	vector<pll> a(n);
	for(int idx=0;idx<n;idx++){
		cin>>a[idx].F;
		a[idx].S = idx+1;
	}

	sort(all(a));

	for(ll i=0;i<n-3;i++)
		for(ll j=i+1;j<n-2;j++){
		ll left=j+1, right=n-1;
		ll sum = x-a[i].F - a[j].F;
		while(left<right){
			if(a[left].F+a[right].F > sum) right--;
			else if(a[left].F+a[right].F < sum) left++;
			else{
				cout<<a[i].S<<" "<<a[j].S<<" "<<a[left].S<<" "<<a[right].S<<endl;
				return;
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;

}

int main(){
	FAST;
	solve();
	return 0;
}