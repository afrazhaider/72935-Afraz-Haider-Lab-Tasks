#include<iostream>
using namespace std;
int main(){
	int temp;
	cout<<"Enter temperature: ";
	cin>>temp;
	if(temp>35)
		cout<<"It is a hot day."<<endl;
	else if(temp>=25 && temp<=35)
		cout<<"It is a pleasant day."<<endl;
	else
		cout<<"It is a cold day."<<endl;
	return 0;
}