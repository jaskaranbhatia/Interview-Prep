#include<iostream>
using namespace std;

void input_2dArray(char **arr,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
}

void output_2dArray(int **arr,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void magical_park(char **arr,int m,int n,int k,int s){
	bool success = true;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			char ch = arr[i][j];
			if(s<k){
				success = false;
				break;
			}
			if(ch == '*'){
				s += 5;
			}
			else if(ch == '.'){
				s -= 2;
			}
			else{
				break;
			}
			if(j!=n-1){
				s--;
			}
		}
	}
	if(success){
		cout<<"yes";
	}
	else{
		cout<<"no";
	}
}


int main(){
	int n,m;
	cin>>n>>m;
	int s,k;
	cin>>s>>k;
	char **arr = new char*[n];
	for(int i=0;i<m;i++){
		arr[i] = new char[m];
	}	
	input_2dArray(arr,n,m);
	magical_park(arr,n,m,s,k);
	return 0;
}
