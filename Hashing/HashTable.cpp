#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
public:
	string key;
	T value;
	Node<T> *next;
	Node(string key,T val){
		this->key = key;
		value = val;
		next = NULL;
	}
	~Node(){
		if(next != NULL){
			delete next;
		}
	}
};

template<typename T>
class HashTable{
	Node<T> **table;
	int curr_size;
	int table_size;
	int hashFnc(string key){
		int idx = 0;
		int p = 1;
		for(int j=0;j<key.length();j++){
			idx = idx + (key[j]*p)%table_size;
			idx = idx % table_size;
			p = (p*27)%table_size;
		}
		return idx;
	}
	void rehash(){
		Node<T> ** oldTable = table;
		int oldTableSize = table_size;
		table_size = 2*table_size;
		table = new Node<T>*[table_size];
		for(int i=0;i<table_size;i++){
			table[i] = NULL;
		}
		curr_size = 0;
		//shift the elements
		for(int i=0;i<oldTableSize;i++){
			Node<T> *temp = oldTable[i];
			while(temp != NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			if(oldTable[i] != NULL){
				delete oldTable[i];	
			}
		}
		delete [] oldTable;
	}
public:
	HashTable(int ts=7){
		table_size = ts;
		table = new Node<T>*[table_size];
		curr_size = 0;
		for(int i=0;i<table_size;i++){
			table[i] = NULL;
		}
	}
	void insert(string key, T value){
		int idx = hashFnc(key);
		Node<T> *n = new Node<T>(key,value);
		//Insert at head of LL with id = idx
		n->next = table[idx];
		table[idx] = n;
		curr_size++;
		float load_factor = curr_size/(1.0*table_size);
		if(load_factor>0.7){
			rehash();
		}
	}
	void print(){
		for(int i=0;i<table_size;i++){
			cout<<"Bucket"<<i<<" -> ";
			Node<T> *temp = table[i];
			while(temp != NULL){
				cout<<temp->key<<" -> "<<temp->value<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	T* search(string key){
		int idx = hashFnc(key);
		Node<T> *temp = table[idx];
		while(temp != NULL){
			if(temp->key == key){
				return &temp->value;
			}
			temp = temp->next;
		}
		return NULL;		
	}
	void erase(string key){
		int h = hashFnc(key);
		Node<T> *temp = table[h];
		Node<T> *prev = NULL;
        while(temp != NULL){
        	if (temp->key == key)
            	break;
            prev = temp;
            temp = temp->next;
        }
        if (table[h] == NULL) {
        	cout<<"No Element found"<<endl;
            return;
        } else {
        	if(prev == NULL){
        		table[h] = NULL;
        		delete temp;
			}
			else{
				prev->next = temp->next;
				table[h] = prev;
        		delete temp;	
			}
        }
        cout<<"Element Deleted"<<endl;
	}
};

int main(){
	HashTable<int> price_menu;
	price_menu.insert("Burger",120);
	price_menu.insert("Pizza",240);
	price_menu.insert("Sandwich",90);
	price_menu.insert("Pepsi",20);
	price_menu.insert("Momos",80);
	price_menu.insert("Chat",60);
	price_menu.insert("Paneer Tikka",110);
	price_menu.insert("Tikki",50);
	price_menu.insert("GolGappe",50);
	price_menu.insert("Tandoori Momos",100);
	price_menu.erase("Chat");
	price_menu.print();
	cout<<"Search For Price ->\n";
	cout<<"Enter Item Name : ";
	string item;
	cin>>item;
	int *price = price_menu.search(item);
	if(price == NULL){
		cout<<"Not Found";
	}
	else{
		cout<<"Price of "<<item<<" is "<<*price;
	}
}
