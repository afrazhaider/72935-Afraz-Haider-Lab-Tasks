#include<iostream>
#include<iomanip>
using namespace std;
int admin(){
	const string adminpass="1290";
	int i=3;
	string password;
	do{
		cout<<"Enter Password: ";
		cin>>password;
		if(password==adminpass){ //checks whether password is correct or not.
			cout<<"Welcome!"<<endl;
			return true;
		}
		else{
			cout<<"Incorrect Password. Try Again."<<endl;
			cout<<"You have "<<i-1<<" attempts left"<<endl;
		}
		i--;
	}while(i>0);
	return false;
}

int main(){
	bool i=true;
	do{
	cout<<endl<<setfill('=')<<setw(25)<<"Menu"<<setfill('=')<<setw(25)<<" "<<endl;
	cout<<"1. Admin Panel"<<endl;				//asks user to choose which menu to open
	cout<<"2. Customer Panel"<<endl;
	cout<<"3. Exit"<<endl;
	int choice, choice1, choice2;
	cout<<"Enter Choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			if(admin()){		//checks password
				do{
				cout<<endl<<setfill('=')<<setw(40)<<" "<<endl;
				cout<<"\t\tAdmin Panel"<<endl;
				cout<<setfill('=')<<setw(40)<<" "<<endl<<endl;
				cout<<"1. Add New Product. "<<endl;			//shows admin menu after entering correct password
				cout<<"2. View All Products. "<<endl;
				cout<<"3. Search Product. "<<endl;
				cout<<"4. Update Product Details "<<endl;
				cout<<"5. Delete Product."<<endl;
				cout<<"6. Inventory Stock Report"<<endl;
				cout<<"7. Sales Report"<<endl;
				cout<<"8. Generate/Print Invoice"<<endl;
				cout<<"9. Back to main menu."<<endl;
				cout<<"Enter your choice: ";
				cin>>choice1;
			}while(choice1!=9);
			}else{
				cout<<endl<<"You have entered Incorrect Password. Try Again Later!"<<endl;
			}
			break;
		case 2:	
			do{				//shows the customer menu
			cout<<setfill('=')<<setw(40)<<" "<<endl;
			cout<<"\t\tCustomer Panel"<<endl;
			cout<<setfill('=')<<setw(40)<<" "<<endl;	
			cout<<"1. View All Accessories."<<endl;
			cout<<"2. Add to Cart"<<endl;
			cout<<"3. View Shopping Cart/Checkout"<<endl;
			cout<<"4. Back to Main Menu."<<endl;
			cout<<endl<<"Enter your choice: ";
			cin>>choice2;
			}while(choice2!=4);
			break;
		case 3:		//stops program execution
			return 0;
		default:
			cout<<"Returning to Main Menu........."<<endl;
			break;
	}
	}while(true);		//keeps program running until user chooses exit option above
	return 0;
}