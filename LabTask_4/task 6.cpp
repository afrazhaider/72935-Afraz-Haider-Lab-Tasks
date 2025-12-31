#include<iostream>
using namespace std;
int main(){
	int seconds, hrs, mins, secs;
	cout<<"Enter total seconds: ";
	cin>>seconds;
	hrs= seconds / 3600;
	seconds = seconds % 3600;
	mins = seconds / 60;
	secs = seconds % 60;
	cout<< hrs <<"hrs"<< mins << "mins" << secs << "secs" << endl;
	return 0;
}