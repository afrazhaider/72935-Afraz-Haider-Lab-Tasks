#include<iostream>
using namespace std;
int main(){
	float a,b, sum, sub, mul,div;
	char op;
	cout<<"Enter two numbers: ";
	cin>>a>>b;
	cout<<"Choose operator(+, -,*./,): ";
	cin>>op;
	switch(op){
		case '+'
			sum=a+b;
			cout<<"Sum= "<<sum<<endl;
			break;
		case '-':
			sub-a-b;
			cout<<"Sub= "<<sub<<endl;
			break;
		case '*':
			mul=a*b;
			cout<<"Product= "<<mul<<endl;
			break;
		case '/':
			if (a==0 &&b==0){
				cout<<"Enter non-zero numbers."<<endl;
			}
			else{
			div=a/b;
			cout<<"Division= "<<div<<endl;
			}
			break;
		default:
			cout<<"Invalid operator"<<endl; break;
		}
	return 0;
}