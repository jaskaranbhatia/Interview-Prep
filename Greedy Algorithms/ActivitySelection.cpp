#include<bits/stdc++.h>
#define ll long long int
using namespace std;

/*
Explanation ------>>>>>
Pick the next activity whose finish time is least among the 
remaining activities and the start time is more than or equal 
to the finish time of previously selected activity.Sort the activities
according to their finishing time so that one can always consider the 
next activity as minimum finishing time activity.
*/


int main(){
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		pair<ll,ll> p[n];
		for(ll i=0;i<n;i++){
			cin>>p[i].second; //Putting Starting time as second
		}
		for(ll i=0;i<n;i++){
			cin>>p[i].first; //Putting Finishing time as First
		}
		sort(p,p+n);
		ll i=0,j=1,ans=1;
		while(i<n && j<n){
			if(p[i].first <= p[j].second){
				i = j
				j++;
				ans++;
			}
			else{
				j++;
			}
		}
	}
	return 0;
}

