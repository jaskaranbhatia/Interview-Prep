#include <iostream>
#define ll long long int
using namespace std;

class Pair{
public:
    ll idx1;
    ll idx2;
};

Pair findSum(ll arr[],ll n,ll sum){
    ll i=0,j=1;
    ll result = arr[0];
    Pair p;
    while(i<=j){
        if(j >=n+1 || i >= n){
            p.idx1 = p.idx2 = -1;
            break;
        }
        if(result == sum){
            break;
        }
        else if(result < sum){
            result += arr[j++];
        }
        else{
            result -= arr[i++];
        }
    }
    if(p.idx1 == -1){
        return p;
    }
    p.idx1 = i;
    p.idx2 = j;
    return p;
}

int main() {
	ll T;
	cin>>T;
	while(T--){
	    ll n,sum;
	    cin>>n>>sum;
	    ll arr[n];
	    for(ll i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    Pair p = findSum(arr,n,sum);
	    if(p.idx1 == -1){
	        cout<<-1<<endl;
	    }
	    else{
	        cout<<(p.idx1)+1<<" "<<p.idx2<<endl;
	    }
	}
	return 0;
}
