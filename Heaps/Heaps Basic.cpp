#include<bits/stdc++.h>
using namespace std;

void upheapify(vector<int> &heap,int idx){
	if(idx == 0){
		return;
	}
	int parentIdx = (idx - 1)/2;
	if(heap[idx] > heap[parentIdx]){
		int temp = heap[idx];
		heap[idx] = heap[parentIdx];
		heap[parentIdx] = temp;
		upheapify(heap,parentIdx);
	}
	else{
		return;	
	}
}

void downheapify(vector<int> &heap,int idx){
	int leftIdx = 2*idx + 1;
	int rightIdx = 2*idx + 2;
	if(leftIdx >= heap.size() && rightIdx >= heap.size()){
		return;
	}
	int largestIdx = idx;
	if(leftIdx < heap.size() && heap[leftIdx] > heap[largestIdx]){
		largestIdx = leftIdx;
	}
	if(rightIdx < heap.size() && heap[rightIdx] > heap[largestIdx]){
		largestIdx = rightIdx;
	}
	if(largestIdx == idx){
		return;
	}
	swap(heap[idx],heap[largestIdx]);
	downheapify(heap,largestIdx);
}

void insert(vector<int> &heap,int key){
	heap.push_back(key);
	upheapify(heap,heap.size()-1);
}

void deletePeek(vector<int> &heap){
	swap(heap[0],heap[heap.size()-1]);
	heap.pop_back();
	downheapify(heap,0);
}

void display(vector<int> &heap){
	for(auto i:heap){
		cout<<i<<" ";
	}
}

void buildHeap(vector<int> &heap){
	for(int i=heap.size()-1;i>=0;i--){
		downheapify(heap,i);
	}
}

int main()
{
	int n;
	cin>>n;
	vector<int> heap;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		heap.push_back(data);
	}
	buildHeap(heap);
	display(heap);
	return 0;
}


