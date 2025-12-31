#include<iostream>
using namespace std;
int main(){
	int i=1;
	while(i<12){
	char ch;
	cout<<"Enter any character: ";
	cin>>ch;
	if(ch=='a'|| ch=='A')
		cout<<ch<<" is a vowel"<<endl;
	else if(ch=='e'|| ch=='E')
		cout<<ch<<" is a vowel"<<endl;
	else if(ch=='i'|| ch=='I')
		cout<<ch<<" is a vowel"<<endl;
	else if(ch=='o'|| ch=='O')
		cout<<ch<<" is a vowel"<<endl;
	else if(ch=='u'|| ch=='U')
		cout<<ch<<" is a vowel"<<endl;
	else
		cout<<ch<<" is not a vowel"<<endl;
	i++;
	}
	return 0;
}