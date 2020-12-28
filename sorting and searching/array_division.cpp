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


bool isPossible(vecll &a, ll k, ll val){
	ll cnt=1,currSum=0;
	for(ll i=0;i<size(a);i++){
		if(currSum+a[i]>val){
			currSum=0;
			cnt++;
		}
		if(val<a[i]) return false;
		currSum+=a[i];
	}
	return cnt <= k;
}

void solve(){
	ll n,k;
	cin>>n>>k;
	vecll a(n);
	for(ll &i:a) cin>>i;

	ll low=1,high= (*max_element(all(a)))*n, ans=-1;
	
	while(low<=high){
		ll mid = (low+high)/2;

		if(isPossible(a,k,mid)){
			ans=mid;
			high = mid-1;
		}
		else 
			low = mid+1;
	}
	cout<<ans<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}