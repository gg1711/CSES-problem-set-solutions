#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
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

ll leftSum=0, rightSum=0;

void balance(multiset<ll>&left, multiset<ll>&right){
	if(size(left)>(size(right)+1)){
		ll val = *left.rbegin();
		right.insert(*(left.rbegin()));
		left.erase(--left.end());
		rightSum+=val;
		leftSum-=val;
	}
	else if(size(left) < size(right)){
		ll val = *right.begin();
		left.insert(*(right.begin()));
		right.erase(right.begin());
		leftSum+=val;
		rightSum-=val;
	}
}

void add(multiset<ll>&left, multiset<ll>&right, ll val){
	if(size(left)>0 && val > *(left.rbegin())){
		rightSum+=val;
		right.insert(val);
	}
	else{
		leftSum+=val;
		left.insert(val);
	}
	balance(left, right);	
}

void erase(multiset<ll>&left, multiset<ll>&right, ll val){
	if(left.count(val)>0){
		leftSum-=val;
		left.erase(left.find(val));
	}
	else{
		rightSum-=val;
		right.erase(right.find(val));
	}
	balance(left,right);
}

ll getCost(multiset<ll>&left, multiset<ll>&right){
	ll val = *left.rbegin();
	ll sum=0;
	sum+=(size(left)*val - leftSum);
	sum+=(rightSum - size(right)*val);
	return sum;
}

void solve(){
	leftSum=0;
	rightSum=0;
	ll n,k;
	cin>>n>>k;
	vecll a(n);
	for(ll &i:a)
		cin>>i;
	//left keeps min element and right keeps maximum
	multiset<ll>left, right;

	//add()
	//erase()
	//median()
	for(ll idx=0;idx<n;idx++){
		add(left, right,a[idx]);
		if(idx>=k-1){
			cout<<getCost(left, right)<<" ";
			// print(left);
			// print(right);
			erase(left, right,a[idx-(k-1)]);
		}
	}
	cout<<endl;
	return;

}

int main(){
	FAST;
	solve();
	return 0;
}