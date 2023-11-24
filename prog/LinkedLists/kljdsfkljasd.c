//VICTORIENNE TIU h-21

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM		10 
#define STRING_LENGTH	30
#define TRUE			1
#define FALSE			0
#define MAX_RACK		5

typedef char String[STRING_LENGTH];
typedef int Boolean;					// Boolean either TRUE or FALSE value

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	int prodID;
	String prodName;
	Date manufactureDate;
	Date expiryDate;
	float prodPrice;
} Product;

typedef struct {
	Product list[MAX_ITEM];				// the current products in rack
	int itemCount;						// the current number of product items in rack
} Rack;

typedef struct {
	Boolean shelves[MAX_RACK]; 			// TRUE if occupied and FALSE if unocccupied
	Rack rackItems[MAX_RACK];			// the rack that contains actual product items
	float totalMoney;					// total amount in the machine
} VendingMachine;

//main functions

/*
 *	Creates a vending machine instance that will set it as an empty machine.
*/
VendingMachine createVendingMachine();

/*
 * 	The displayVendingMachine() is a simple visualization of the contents. It will
 *	show the racks and the individual items in each rack in order with the 
 *	name and price of the product.
*/
void displayVendingMachine(VendingMachine vm);

/*
 * 	Creates a date with the given integer value of day, month, and year.
*/
Date createDate(int day, int month, int year);

/*
 * 	Creates a product with a given id, name, date of manufacture, date of expriry,
 *	and the price.
*/
Product createProduct(int id, String name, Date mfDate, Date expDate, float price);

/*
 *  The addProduct() function is a simple way to restock a product from a vending machine.
 *  It takes two parammeters: the rack number in which the product will be added and
 *  the product itself. The function then adds the product in the rack considering the 
 *  expiry date of the product. Products near expiry should placed ahead, so they may be
 *	able to dispense first. The function also checks if the rack number is valid and if the
 *	selected rack is not yet full, this will be considered as a successful transaction.
 *  Otherwise it will display the error message and returns a failure transaction.
*/
Boolean addProduct(VendingMachine *vm, int rackNumber, Product prodItem);

/*
 *  The purchaseProduct() function is a simple way to buy a product from a vending machine. 
 *  It takes two parameters: the rack number of the product and the amount of money to pay. 
 *  The function checks if the rack number is valid, if the product is available, and if 
 *	the amount is enough; it will then displays the necessary error message and returns a failure 
 *	transaction. If all conditions are met, the function dispenses the product 
 *	(removes from the vending machine), shows the the change, and returns a successful transaction.
*/
Boolean purchaseProduct(VendingMachine *vm, int rackNumber, float amount);

//helper functions
int days_in_month(int month, int year);
int date_difference(Date d1, Date d2);


int main() {
	VendingMachine vm1 = createVendingMachine();
	/*CHECKING
	VendingMachine vm2 = createVendingMachine();
	
	vm2.rackItems[2].itemCount = 1;
	
	strcpy(vm2.rackItems[2].list[0].prodName, "Coke");
	vm2.rackItems[2].list[0].prodID= 1;
	vm2.rackItems[2].list[0].prodPrice= 40.00;
	vm2.rackItems[2].list[0].expiryDate.day= 5;
	vm2.rackItems[2].list[0].expiryDate.month= 5;
	vm2.rackItems[2].list[0].expiryDate.year= 5;
	vm2.rackItems[2].list[0].manufactureDate.month= 5;
	vm2.rackItems[2].list[0].manufactureDate.day= 5;
	vm2.rackItems[2].list[0].manufactureDate.year= 5;
	*/
	
	printf("VICTORIENNE TIU VENDING MACHINE\n");
	printf("[1.0] DISPLAY OF AN EMPTY VENDING MACHINE.\n");
//	NO.1 Activate the given code below to show an empty vending machine.
	displayVendingMachine(vm1);
	
	system("PAUSE");
	system("CLS");
	
	printf("[2.0] INITIALLY POPULATED VENDING MACHINE. DISPLAY OF VENDING MACHINE.\n");
//	{take note that the addProduct below are just samples and may not be the same when its checked}	
//	NO.2 Activate lines below to initially populate the vending machine and display it.
	addProduct(&vm1, 2, createProduct(4, "Coke", createDate( 1,1,2023), createDate(05,05,2023), 40.0));
	addProduct(&vm1, 2, createProduct(10, "Sprite", createDate(1,1,2023), createDate(25,05,2023), 50.0));
	addProduct(&vm1, 4, createProduct(12, "Beer", createDate(1,1,2023), createDate(02,05,2023), 100.0));
	addProduct(&vm1, 4, createProduct(10, "Sprite", createDate(1,1,2023), createDate(15,05,2023), 50.0));
	addProduct(&vm1, 2, createProduct(2, "Vodka", createDate(1,1,2023), createDate(10,05,2023), 120.0));
	addProduct(&vm1, 0, createProduct(5, "Royal", createDate(1,1,2023), createDate(02,05,2023), 45.0));
	displayVendingMachine(vm1);
	
//	int dif;
//
//	dif = date_difference(vm1.rackItems[4].list[0].manufactureDate, vm1.rackItems[4].list[0].expiryDate);
//	
//	printf("\n\n\n\ DIF of %s and %s: %d", vm1.rackItems[4].list[0].prodName, vm1.rackItems[4].list[1].prodName, dif);

	system("PAUSE");
	system("CLS");
	
	printf("[3.1] PURCHASING PRODUCT in rack zero with more than the required amount.\n");
//	NO. 3.1 Activate the 2 lines below.	
	purchaseProduct(&vm1, 0, 50);
	displayVendingMachine(vm1);
	
	printf("[3.2] PURCHASING PRODUCT in rack 2 with lacking amount.\n");
//	NO. 3.2 Activate the 2 lines below.
	purchaseProduct(&vm1, 2, 20);
	displayVendingMachine(vm1);
	
	printf("[3.3] PURCHASING PRODUCT in rack 1 (in an empty rack).\n");
//	NO. 3.2 Activate the 2 lines below.
	purchaseProduct(&vm1, 1, 20);
	displayVendingMachine(vm1);
	
	system("PAUSE");
	return 0;
}

VendingMachine createVendingMachine() {
	VendingMachine vm;
	int i;
	
	vm.totalMoney = 0;
	for(i = 0; i < MAX_RACK; ++i) {
		vm.shelves[i] = FALSE;
		vm.rackItems[i].itemCount = 0;
	}
	
	return vm;
}


void displayVendingMachine(VendingMachine vm) {
	
	//display
	//1. rack # 
	//2. item #
	//3. name
	//4. price
	//5. exp date
	
	Product p;
	int i, j;
	
	printf("\n");
	for(i = 0; i < MAX_RACK; ++i){
		printf("\nRACK - %d\n", i);
		    if(vm.rackItems[i].itemCount > 0){
                for(j = 0; j < vm.rackItems[i].itemCount; ++j){
                    printf("\tItem   %d -\t\t %10s - Php\t %.2f - %d/%d/%d\n", j, vm.rackItems[i].list[j].prodName, vm.rackItems[i].list[j].prodPrice, vm.rackItems[i].list[j].expiryDate.day, vm.rackItems[i].list[j].expiryDate.month, vm.rackItems[i].list[j].expiryDate.year);
		        }
        }
		else{
		    printf("\n\tEMPTY RACK\n");
		}
	}
}

Date createDate(int day, int month, int year) {
	Date d;
	
	d.day = day;
	d.month = month;
	d.year = year;
	
	return d;	
}

Product createProduct(int id, String name, Date mfDate, Date expDate, float price) {
	Product p;
	
	p.prodID = id;
	strcpy(p.prodName, name);
	p.manufactureDate = mfDate;
	p.expiryDate = expDate;
	p.prodPrice = price;
	
	return p;
}

Boolean addProduct(VendingMachine *vm, int rackNumber, Product prodItem) {
	
	int i, j;
	Product temp;
	
	//checks:
	//1. rack # is valid
	
	if(rackNumber < 0 || rackNumber >= MAX_RACK){
		printf("\nRACK NUMBER IS NOT VALID");
		return FALSE;
	}
	
	//2. rack is full
	if(vm->rackItems[rackNumber].itemCount >= MAX_ITEM){
		printf("\nRACK IS FULL");
		return FALSE;
	}
	
	//insertAt == insert first if exp date is ahead
	
	int idx = vm->rackItems[rackNumber].itemCount;  //position of item
	
	// prd.expdate > 0 (not exp)
	for(i = idx; i > 0 && date_difference(prodItem.expiryDate, vm->rackItems[rackNumber].list[i - 1].expiryDate) < 0; --i){ 
		vm->rackItems[rackNumber].list[i] =	vm->rackItems[rackNumber].list[i-1] ; //shift to right 
	}
	
	vm->rackItems[rackNumber].list[i] = prodItem;
	vm->rackItems[rackNumber].itemCount++;
	vm->shelves[rackNumber] == TRUE; 
	
	printf("\nSuccessfully Added!");
	return TRUE;
}

Boolean purchaseProduct(VendingMachine *vm, int rackNumber, float amount) {
	
	/*
 *  The purchaseProduct() function is a simple way to buy a product from a vending machine. 
 *  It takes two parameters: the rack number of the product and the amount of money to pay. 
 *  The function checks if the rack number is valid, if the product is available, and if 
 *	the amount is enough; it will then displays the necessary error message and returns a failure 
 *	transaction. If all conditions are met, the function dispenses the product 
 *	(removes from the vending machine), shows the the change, and returns a successful transaction.
*/

	int i;

	//1. rack # is valid
	if(rackNumber < 0 || rackNumber >= MAX_RACK){
		printf("\nRACK NUMBER IS NOT VALID\n");
		return FALSE;
	}

	//2. check if amount is enough
	if(amount-vm->rackItems[rackNumber].list[0].prodPrice < 0){
		printf("\nAMOUNT NOT ENOUGH\n");
		return FALSE;
	}
	
	//delete front
	for(i = 0; i < vm->rackItems[rackNumber].itemCount; ++i){
		vm->rackItems[rackNumber].list[i] = vm->rackItems[rackNumber].list[i+1];
	}
	
	vm->rackItems[rackNumber].itemCount--;
	
//	if(amount-vm->rackItems[rackNumber].list[0].prodPrice > 0){
//		amount=vm->rackItems[rackNumber].list[0].prodPrice-amount;
//		printf("Total Amount: %d", amount);
//	}
	
	printf("\nTransaction Success!");
	
	return TRUE;
	
}

int days_in_month(int month, int year) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return 29;
        else
            return 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int date_difference(Date d1, Date d2) {
    int days1, days2;

    days1 = d1.day;
    days2 = d2.day;

    int i;

    for (i = 1; i < d1.month; i++) {
        days1 += days_in_month(i, d1.year);
    }

    for (i = 1; i < d2.month; i++) {
        days2 += days_in_month(i, d2.year);
    }

    days1 += (d1.year - 1) * 365 + (d1.year - 1) / 4 - (d1.year - 1) / 100 + (d1.year - 1) / 400;
    days2 += (d2.year - 1) * 365 + (d2.year - 1) / 4 - (d2.year - 1) / 100 + (d2.year - 1) / 400;

    return days2 - days1;
}