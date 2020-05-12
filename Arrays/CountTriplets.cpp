#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> arr,int n){
    sort(arr.begin(),arr.end());
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = arr[i] + arr[j];
            if(find(arr.begin(),arr.end(),sum) != arr.end()){
                count++;
            }
        }
    }
    return count;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    vector<int> arr;
	    for(int i=0;i<n;i++){
	        int data;
	        cin>>data;
	        arr.push_back(data);
	    }
	    int ans = countTriplets(arr,n);
	    if(ans == 0){
	        cout<<-1<<endl;
	    }
	    else{
	        cout<<ans<<endl;
	    }
	}
	return 0;
}
