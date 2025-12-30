#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void addition(float a, float b){
	float sum=a+b;
	cout<<a<<" + "<<b<<" = "<<sum<<endl;
}

void subtraction(float a, float b){
	float sub=a-b;
	cout<<a<<" - "<<b<<" = "<<sub<<endl;
}

void multiplication(float a,float b){
	float product=a*b;
	cout<<a<<" x "<<b<<" = "<<product<<endl;
}

void division(float a,float b){
	float div;
	if(b!=0){
		div=a/b;
		cout<<a<<" / "<<b<<" = "<<div<<endl;
	}
	else{
		cout<<"Error, Division by zero!"<<endl;
	}
}

void power(float a, float b){
	float power, result1, result2;
	cout<<"Enter Power: ";
	cin>>power;
	result1= pow(a,power);
	result2= pow(b,power);
	cout<<a<<" raised to power "<<power<<" = "<<result1<<endl;
	cout<<b<<" raised to power "<<power<<" = "<<result2<<endl;
}

int main(){
	float a, b;
	int choice;
	cout<<"Afraz Haider\n72935"<<endl<<endl;
	cout<<"Enter First Number: ";
	cin>>a;
	cout<<"Enter Second Number: ";
	cin>>b;
	cout<<setfill('=')<<setw(10)<<" Menu "<<setfill('=')<<setw(10)<<" "<<endl;
	cout<<"1. Addition (+)"<<endl;
	cout<<"2. Subtraction (-)"<<endl;
	cout<<"3. Multiplication (*)"<<endl;
	cout<<"4. Division (/)"<<endl;
	cout<<"5. Power (P)"<<endl;
	cout<<"6. Exit Program."<<endl;
	do{
	cout<<endl<<"Enter your choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			addition(a,b);
			break;
		case 2:
			subtraction(a,b);
			break;
		case 3:
			multiplication(a,b);
			break;
		case 4:
			division(a,b);
			break;
		case 5:
			power(a,b);
			break;
		case 6:
			cout<<"Exiting Program..."<<endl;
			break;
		default:
			cout<<"Invalid Choice!"<<endl;
			break;
	}}while(choice!=6);
	return 0;
}