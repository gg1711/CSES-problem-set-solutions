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
	ll n, maxWeight;
	cin>>n>>maxWeight;
	vecll weight(n);

	for(int idx=0;idx<n;idx++)
		cin>>weight[idx];

	sort(all(weight));

	ll left=0,right=n-1, cnt=1;
	ll curr=0, numCnt=0;
	while(left<=right){
		if(numCnt==2){
			numCnt=0;
			curr=0;
			cnt++;
		}
		if(curr + weight[right] <= maxWeight)
			curr+=weight[right--], numCnt++;
		else if(curr + weight[left] <= maxWeight)
			curr+=weight[left++], numCnt++;
		else{
			numCnt=0;
			curr=0;
			cnt++;
		}
	}
	cout<<cnt<<endl;
}

int main(){
	FAST;
	solve();
	return 0;
}