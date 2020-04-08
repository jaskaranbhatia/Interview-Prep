#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int val){
		data = val;
		next = NULL;
	}
};

void storeEle(Node *h1,Node *h2,unordered_map<int,int> &eleOcc){
	Node *ptr1 = h1;
	Node *ptr2 = h2;
	while(ptr1 != NULL || ptr2 != NULL){
		if(ptr1 != NULL){
			eleOcc[ptr1->data]++;
			ptr1 = ptr1->next;
		}
		if(ptr2 != NULL){
			eleOcc[ptr2->data]++;
			ptr2 = ptr2->next;
		}
	}
}

void insert(Node *&head,int data){
	if(head == NULL){
		head = new Node(data);
		return;
	}
	Node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	Node *new_Node = new Node(data);
	temp->next = new_Node;
}


Node* getIntersection(unordered_map<int, int> eleOcc) 
{ 
    Node *result = NULL; 
    for (auto it=eleOcc.begin(); it!=eleOcc.end(); it++) 
        if (it->second == 2) 
            insert(result, it->first); 
    return result; 
} 

Node* getUnion(unordered_map<int,int> elecOcc){
	Node *result = NULL;
	for(auto it=elecOcc.begin();it!=elecOcc.end();it++){
		insert(result,it->first);
	}
	return result;
}

void print(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

void printUnionIntersection(Node *head1, Node *head2) 
{ 
    unordered_map<int, int> eleOcc; 
    storeEle(head1, head2, eleOcc); 
    Node *intersection_list = getIntersection(eleOcc); 
    Node *union_list = getUnion(eleOcc);
    print(intersection_list);
	cout<<endl; 
    print(union_list);
} 

int main(){
	Node *head1 = NULL;
	insert(head1,1);
	insert(head1,2);
	insert(head1,3);
	insert(head1,4);
	Node *head2 = NULL;
	insert(head2,3);
	insert(head2,4);
	insert(head2,5);
	insert(head2,6);
	printUnionIntersection(head1,head2);
}
