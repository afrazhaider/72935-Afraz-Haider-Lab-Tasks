#include<iostream>
using namespace std;
int main(){
	int salary[6];
	for (int i=0;i<6;i++){
		cout<<"Enter Salary#"<<i+1<<": ";
		cin>>salary[i];
	}
	cout<<"Salary of your 6 employees is: "<<endl;
	for(int j=0;j<6;j++){
		cout<<salary[j]<<endl;
	}
	return 0;
}