#include<iostream>
using namespace std;
int main(){
	double eng,math,sci,comp,phys,total_marks,om,percentage;
	cout<<"Enter marks of English: ";
	cin>>eng;
	cout<<"Enter marks of Math: ";
	cin>>math;
	cout<<"Enter marks of Science: ";
	cin>>sci;
	cout<<"Enter marks of Computer: ";
	cin>>comp;
	cout<<"Enter marksof Physics: ";
	cin>>phys;
	total_marks=500; //assuming each subject is of 100 each
	om=eng+math+sci+comp+phys; //the total marks obtained
	percentage=(om/total_marks)*100;
	cout<<"Your total obtained marks are: "<<om<<endl;
	cout<<"Your percentage is: "<<percentage<<endl;
	cout<<"Name: Afraz Haider"<<endl;
	cout<<"Sap ID: 72935";
	return 0;
}