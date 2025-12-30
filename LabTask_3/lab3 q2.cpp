#include<iostream>
using namespace std;
int main(){
	double S1,S2,S3,avg;
	cout<<"Enter marks of first subject: ";
	cin>>S1;
	cout<<"Enter marks of second subject: ";
	cin>>S2;
	cout<<"Enter marks of third subject: ";
	cin>>S3;
	avg=(S1+S2+S3)/3;
	if(avg>80){
		cout<<"You are above standard"<<endl;
		cout<<"Admission Granted"<<endl;
	}
	else{
		cout<<"Not above standard, admission rejected"<<endl;//optional else statement, for neatness of code 
	}
	cout<<"Name: Afraz Haider"<<endl;
	cout<<"Sap ID: 72935";
	return 0;
}
