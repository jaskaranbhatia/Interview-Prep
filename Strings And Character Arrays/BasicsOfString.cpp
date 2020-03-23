//It wraps a character array in a string named container
#include<iostream>
#include<string>
using namespace std;

int main(){
	string s0;
	string s1("Hello");
	string s2 = "Hello World";
	string s3(s2);
	string s4 = s3;
	char a[]= {'a','b','c','\0'};
	string s5(a);
	cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<s5<<endl;
	if(s0.empty()){
		cout<<"String is empty"<<endl;
	}
	s0.append("I love C++");
	cout<<s0<<endl;
	s0 += " and Python";
	cout<<s0<<endl;
	//Erase contents of string
	cout<<s0.length()<<endl;
	s0.clear();
	cout<<s0.length()<<endl;
	//Compare two string
	s0 = "Apple";
	s1  ="Orange";
	cout<<s0.compare(s1)<<endl;
	//Find Substrings
	string s= "I love to have apple";
	int idx = s.find("apple");
	cout<<idx<<endl;
	cout<<s.substr(15,5)<<endl;
	//Remove or Erase contents of a String
	string word = "apple";
	s.erase(idx,word.length());
	cout<<s<<endl;
	//Iterators
	for(auto it=s.begin();it!=s.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	//Using for Loop
	for(int i=0;i<s.length();i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	//for..in loop
	for(char c:s){
		cout<<c<<" ";
	}
}

