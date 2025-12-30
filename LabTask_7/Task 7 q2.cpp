#include<iostream>
using namespace std;
int main(){
	double quiz[10];
	double sum, avg;
	for(int i=0;i<10;i++){
		cout<<"Enter Marks#"<<i+1<<": ";
		cin>>quiz[i];
	}
	for(int j=0;j<10;j++){
		sum=sum+quiz[j];
	}
	cout<<"The sum of all marks is: "<<sum<<endl;
	avg=sum/10;
	cout<<"Average Marks are: "<<avg<<endl;
	return 0;
}