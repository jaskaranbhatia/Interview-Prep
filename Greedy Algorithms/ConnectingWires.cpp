#include<bits/stdc++.h>
using namespace std;

int main(){
	int black[] = {3,4,1};
	int white[] = {2,5,6};
	int n1 = sizeof(black)/sizeof(black[0]);
	int n2 = sizeof(white)/sizeof(white[0]);
	sort(white,white+n1);
	sort(black,black+n2);
	int i=0,j=0,ans=0;
	while(i<n1 && j<n2){
		int minLen = abs(black[i] - white[j]);
		i++;
		j++;
		ans += minLen;
	}
	cout<<ans<<endl;
	return 0;
}

