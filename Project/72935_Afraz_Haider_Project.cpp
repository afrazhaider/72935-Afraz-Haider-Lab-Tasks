#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
//--------------declaring structure for products---------
struct Products{
	int id;
	string name;
	double price;
	int stock;
};
//----------------------code for product catalog starts here------------------------------
struct cartitems{
	int productid;
	int quantity;
};
Products catalog[50]{
	{101, "Headphones", 6000, 30},
	{102, "Keyboard", 4500, 20},
	{103, "Mouse", 1200, 25},
	{104, "Laptop Stand", 11000, 15},
	{105, "Laptop Bag", 900, 25},
	{106, "USB 64GB", 3000, 50}
	};
int catalogcount=6;
//-----------------------------------------------------------

//-----------------code that shows the products when choice is entered-----------------
cartitems cart[100];
int cartsize=0;
void showcatalog(){
	cout<<" "<<setfill('-')<<setw(10)<<" "<<"Product Catalog"<<setfill('-')<<setw(10)<<" "<<endl;
	for(int i=0;i<catalogcount;i++){
		cout<<"["<<catalog[i].id<<"] "<<catalog[i].name<<" - Rs "<<catalog[i].price<<"  (In Stock: "<<catalog[i].stock<<")"<<endl;
	}
	cout<<endl;
}
//----------------------------------------------

//code for adding items to cart
void addtocart(int id, int qty){
	int productindex=-1;
	for(int i=0;i<catalogcount;i++){
		if(catalog[i].id == id){
			productindex=i;
			break;
		}
	}
	if(productindex == -1){
		cout<<"Product ID not found..."<<endl;
		return;
	}
	if(catalog[productindex].stock < qty){
		cout<<"Out of Stock!"<<catalog[productindex].stock<<" remaining items."<<endl;
		return;
	}
	
	for(int i=0;i<cartsize;i++){
		if(cart[i].productid == id){
			cart[i].quantity += qty;
			cout<<"Updated Quantity in cart"<<endl;
			return;
		}
	}
	
	if (cartsize < 100) {
        cart[cartsize].productid = id;
        cart[cartsize].quantity = qty;
        cartsize++;
        cout<<"Item Added to Cart."<<endl;
    } else {
        cout << "Cart is full!\n";
    }
}
//-----------------------------------------------------------------
void checkoutandreducestock(){		//when user completes purchase, this function decreases stock amount
	for(int i=0;i<cartsize;i++){
		int purchasedid = cart[i].productid;
		int purchasedqty = cart[i].quantity;
		
		for(int j=0;j<catalogcount;j++){
			if(catalog[j].id == purchasedid){
				catalog[j].stock -= purchasedqty;
				break;
			}
		}
	}
	cartsize=0;
}
//---------------------------------------------------------------------

//--------------------code that shows your cart----------------------------
void showcart(){
	if(cartsize==0){
		cout<<"Cart is empty."<<endl;
		return;
	}
	double total = 0;
	cout<<setfill('-')<<setw(10)<<" "<<"Your Cart "<<setfill('-')<<setw(10)<<" "<<endl;
	cout<<setw(10)<<setfill(' ')<<"Product Name\t|\t Quantity|\t Price\t\t|"<<endl;
	for(int i=0; i<cartsize;i++){
		for(int j=0;j<6;j++){
			if(catalog[j].id == cart[i].productid){
				double subtotal = catalog[j].price*cart[i].quantity;
				total+=subtotal;
				cout<<setw(10)<<setfill(' ')<<catalog[j].name<<"\t|\t\t"<<cart[i].quantity<<"|\t = Rs"<<fixed<<setprecision(2)<<subtotal<<"\t|"<<endl;
			}
		}
	}
}

//------------------------------------------------------------------------

//------------------check whether new id for product already exists(admin case 1)
bool isProductidExist(int id){
	for(int i=0;i<catalogcount;i++){
		if(catalog[i].id == id){
			return true; //this means id already exists
		}
	}
	return false; //This means id can be used
}

//------------------------admin password check---------------------------
int admin(){
	const string username="Afraz";
	const string adminpass="1290";
	int i=3;
	string password, user_name;
	do{
		cout<<"Enter Username: ";
		cin>>user_name;
		cout<<"Enter Password: ";
		cin>>password;
		if(user_name==username && password==adminpass){ //checks whether password is correct or not.
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

//----------------Receipt Function---------------------------
void printInvoice() {
    if (cartsize == 0) {
        cout << "\nError: No transaction found to generate an invoice." << endl;
        return;
    }

    double grandTotal = 0;
    cout << "\n" << setfill('=') << setw(50) << "" << endl;
    cout << "\t   LAPTOP ACCESSORY STORE" << endl;
    cout << "\t    OFFICIAL SALES INVOICE" << endl;
    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ');
    
    // Header for the table
    cout << left << setw(20) << "Item Name" 
         << setw(10) << "Qty" 
         << setw(10) << "Price" 
         << "Subtotal" << endl;
    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;

    for (int i = 0; i < cartsize; i++) {
        for (int j = 0; j < catalogcount; j++) {
            if (catalog[j].id == cart[i].productid) {
                double subtotal = catalog[j].price * cart[i].quantity;
                grandTotal += subtotal;
                
                cout << left << setw(20) << catalog[j].name 
                     << setw(10) << cart[i].quantity 
                     << "Rs " << setw(7) << catalog[j].price 
                     << "Rs " << fixed << setprecision(2) << subtotal << endl;
            }
        }
    }

    // Tax and Final Calculations
    double tax = grandTotal * 0.05; // 5% GST
    double finalAmount = grandTotal + tax;

    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
    cout << right << setw(35) << "Gross Total: " << "Rs " << grandTotal << endl;
    cout << right << setw(35) << "Tax (5%): " << "Rs " << tax << endl;
    cout << right << setw(35) << "TOTAL AMOUNT: " << "Rs " << finalAmount << endl;
    cout << setfill('=') << setw(50) << "" << endl;
    cout << "\t Thank you for your business!" << endl;
    cout << setfill('=') << setw(50) << "" << endl;
}
//---------------Receipt Function End--------------------


//-------------------Main Function Start---------------------------

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
				cout<<setfill('=')<<setw(40)<<" "<<endl;
				cout<<"1. Add New Product. "<<endl;			//shows admin menu after entering correct password
				cout<<"2. View All Products. "<<endl;
				cout<<"3. Search Product. "<<endl;
				cout<<"4. Update Product Details "<<endl;
				cout<<"5. Delete Product."<<endl;
				cout<<"6. Generate/Print Invoice"<<endl;
				cout<<"7. Back to main menu."<<endl;
				cout<<"Enter your choice: ";
				cin>>choice1;
				switch(choice1){		//asks user to choose
					case 1:				// adds product
					{
						if(catalogcount<50){
							int newid;
							cout<<"Enter New Product Id: ";
							cin>>newid;
							
							if(isProductidExist(newid)){
								cout<<"Product ID already exists..."<<endl;}
							else{
							catalog[catalogcount].id=newid;
							cin.ignore();
							cout<<"Enter Product Name: ";
							getline(cin, catalog[catalogcount].name);
							cout<<"Enter Product Price: ";
							cin>>catalog[catalogcount].price;
							cout<<"Enter Stock Amount: ";
							cin>>catalog[catalogcount].stock;
							catalogcount++;
							cout<<"Product Added."<<endl;
							}
						}else{
							cout<<"Product Catalog is Full."<<endl;
						}
						break;
					}
					case 2:				//shows product catalog
						showcatalog();
						break;
					case 3:				//searches for a product from list
					{
						int searchid;
						bool found=false;
						cout<<"Enter Product Id to search for: "<<endl;
						cin>>searchid;
						
						for(int i=0; i<catalogcount; i++){
							if(catalog[i].id == searchid){
								cout<<"Product Found."<<endl;
								cout<<"["<< catalog[i].id <<"] "<< catalog[i].name <<" -Rs" << catalog[i].price <<endl;
								found=true;
							}
						}
						if(!found)
							cout<<"Product not found."<<endl;
						break;
					}
					case 4:			//updates product information
					{
						int updateid;
						bool found=false;
						cout<<"Enter Product Id to Update: ";
						cin>>updateid;
						
						for(int i=0;i<catalogcount;i++){
							if(catalog[i].id == updateid){
								cout<<"Current Product Details: "<< catalog[i].name << " - Rs"<< catalog[i].price<<endl;
								
								cout<<"Enter New Name:";
								cin.ignore();
								getline(cin, catalog[i].name);
								cout<<"Enter New Price: ";
								cin>> catalog[i].price;
								cout<<"Enter new stock amount: ";
								cin>>catalog[catalogcount].stock;
								
								cout<<"Product Details Updated Successfully."<<endl;
								found=true;
								break;
							}
						}
						if(!found)
							cout<<"Product Not Found."<<endl;
						break;
					}
					case 5:			//deletes product from catalog
					{
						int deleteid;
						int indextodelete=-1;
						cout<<"Enter Product ID to delete: ";
						cin>>deleteid;
						
						for(int i=0; i<catalogcount;i++){
							if(catalog[i].id == deleteid){
								indextodelete=i;
								break;
							}
						}
						if(indextodelete !=-1){
							cout<<"Deleting Product: "<<catalog[indextodelete].name<<endl;
							for(int i=indextodelete;i<catalogcount-1;i++){
								catalog[i]=catalog[i+1];
							}
							catalogcount--;
							cout<<"Product Deleted."<<endl;
						}else{
							cout<<"Product ID "<< deleteid <<" not found."<<endl;
						}
						break;
					}
					case 6: // Generate/Print Invoice
    					cout << "Generating invoice for the previous customer session..." << endl;
    					printInvoice();
    					break;
					case 7:				//exits back to the first menu
						break;	
					}
				}while(choice1!=7);}
			else{
				cout<<endl<<"You have entered Incorrect Password. Try Again Later!"<<endl;
			}
			break;
		case 2:					//shows the customer menu
			do{
			cout<<endl<<endl;
			cout<<setfill('=')<<setw(40)<<" "<<endl;
			cout<<"\t\tCustomer Panel"<<endl;
			cout<<setfill('=')<<setw(40)<<" "<<endl;	
			cout<<"1. View All Accessories."<<endl;
			cout<<"2. Add to Cart"<<endl;
			cout<<"3. View Shopping Cart/Checkout"<<endl;
			cout<<"4. Back to Main Menu."<<endl;
			cout<<endl<<"Enter your choice: ";
			cin>>choice2;
			switch(choice2){
				case 1:
					showcatalog();		//shows product catalog
					cout<<endl;
					break;
				case 2:				//add product to cart
					int prodid, quantity;
					showcatalog();
					do{
					cout<<"Enter Product ID: ";
					cin>>prodid;
					if(prodid==0){
						break;
					}else{
					cout<<"Enter Quantity: ";
					cin>>quantity;
					addtocart(prodid,quantity);
					cout<<"Press 0 to return to previous menu."<<endl;}
					}while(prodid!=0);
					break;
				case 3:			//shows users cart and asks if they want to confirm their purchase
					showcart();
					if(cartsize==0){
						break;
					}
					int a;
					cout<<endl<<"Continue to checkout? \n1. Yes \n2. No"<<endl;
					cin>>a;
					if(a==1){
						printInvoice();
						checkoutandreducestock();
						cout<<endl;
					}else if(a==0){
						cout<<"Purchase Cancelled!"<<endl;
					}else{
						cout<<"Invalid Choice. Try Again"<<endl;}
					break;
				default:
					cout<<"Invalid Choice, Please choose from menu."<<endl;
			}
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