#include<iostream>
using namespace std;
int main(){
	cout<<"=====Using While Loop====="<<endl;
	int i=1;
	while(i<=5){
		int j=1;
		while(j<=5){
		cout<<"* ";
		j++;}
	i++;
	cout<<endl;
	}
	cout<<endl<<"=====Using Do-While Loop====="<<endl;
	i=1;
	do{
		int j=1;
		while(j<=5){
		cout<<"* ";
		j++;}
	i++;
	cout<<endl;
	}while(i<=5);
	return 0;
}