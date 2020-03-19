#include<iostream>
#include<math.h>
using namespace std;

int jumpSearch(int arr[],int n,int key){
	int step = sqrt(n);
	int prev = 0;
	while(arr[min(step,n)-1] < key){
		prev = step;
		step += sqrt(n);
		if(prev >= n){
			return -1;
		}
	}
	while(arr[prev] <= key){
		if (arr[prev] == key) {
			return prev;	
		}
		prev++;
		if(prev == min(step,n)){
			return -1;
		}
	}
	return -1;
}

int main(){
	int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610 }; 
    int key = 612; 
    int n = sizeof(arr) / sizeof(arr[0]);  
    int index = jumpSearch(arr, n, key);  
    cout << "\nNumber " << key << " is at index " << index; 
    return 0; 
}
