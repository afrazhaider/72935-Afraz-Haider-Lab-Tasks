#include<iostream>
using namespace std;
int main(){
	int a,b,c,max;
	cout<<"Enter first number: ";
	cin>>a;
	cout<<"Enter second number: ";
	cin>>b;
	cout<<"Enter third number: ";
	cin>>c;
	if(a>b&&a>c){
		max=a;
	}
	else if(b>a&&b>c){
		max=b;
	}
	else{
		max=c;
	}
	cout<<"Greatest number is "<<max<<endl;
	cout<<"Name: Afraz Haider"<<endl;
	cout<<"Sap ID: 72935";
	return 0;
}
