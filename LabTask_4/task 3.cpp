
#include<iostream> 
using namespace std;
int main(){
	char grade;
	cout<<"Enter your grade: ";
	cin>>grade;
	switch(grade){
		case 'A': case 'a':
			cout<<"Score, is >=90"<<endl;
			break;
		case 'B': case 'b':
			cout<<"Score is between 80-89"<<endl;
			break;
		case 'C': case 'c':
			cout<<"Score is between 70-79"<<endl;
			break;
		case 'D': case 'd':
			cout<<"Score is between 60-69"<<endl;
			break;
		case 'F': case 'f':
			cout<<"Score is below 60"<<endl;
			break;
		default:
			cout<<"You've entered an invalid grade"<<endl;
			break;
		}
	return 0;
}