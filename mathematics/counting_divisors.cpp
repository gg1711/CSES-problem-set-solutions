#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define ll long long int


int main(){
	FAST;
	auto start = chrono::high_resolution_clock::now();
	int n;
	cin>>n;
	vector<ll>prime;
	int N=1000002;
	int temp[N];
	memset(temp,0,sizeof(temp));
	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j+=i)
			temp[j]++;
	}
	while(n--){
		ll x;
		cin>>x;
		cout<<temp[x]<<endl;
	}
	auto stop = chrono::high_resolution_clock::now(); 
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
    cerr << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
	return 0;
}