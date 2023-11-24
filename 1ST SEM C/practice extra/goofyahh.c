#include<stdio.h>
#define LABOR_RATE 17.50
#define TAX_RATE .12

//FUNCTION PROTOTYPES
int getArea(int l, int w);

/*******************************************************************************
 * The computeInstalledPrice() will calculate the installed price. The installed 
 * price is the cost of carpet and the cost of labor.
 */
float computeInstalledPrice(int length, int width, float carpetCost);

/*******************************************************************************
 * The computeSubtotal() will calculate the subtotal. Based on installed price and the discount.
 */
float computeSubtotal(int length, int width, float carpetCost, int discount);

/*******************************************************************************
 * The computeTotal() will calculate the total. Based on installed price, the discount and added tax.
 */
float computeTotal(int length, int width, float carpetCost, int discount);

/*******************************************************************************
 * The printMeasurement() will display all the measurements base on format. The length, width and area.
 */
void printMeasurement();

/*******************************************************************************
 * The printCharges() will display all charges base on format (see output for charges).
 */
void printCharges(int length, int width, float carpetCost, int discount);

int main(void) 
{
  int room_length, room_width, customer_discount;
  float carpet_price;
  
  printf("%-42s ", "Enter length of room (feet):");
  scanf("%d", &room_length);
  printf("%-42s ", "Enter width of room (feet):");
  scanf("%d", &room_width);
  printf("%-42s ", "Enter customer discount (percentage):");
  scanf("%d", &customer_discount);
  printf("%-42s ", "Enter cost of carpet in square foot (Php):");
  scanf("%f", &carpet_price);
  
  printf("\n");
  printMeasurement(int room_length, int room_width, int room_area);
  
  printf("\n");
  printCharges();
  
  return 0;
}

//function definitions
int getArea(int l, int w) 
{
  int area = l*w;
}

void printMeasurement(int length, int width){

  int area= getArea(length, width);
  printf("MEASUREMENT/n");
    printf("\n%-15s%d  feet", "Length", length);
    printf("\n%-15s%d  feet", "Width", width);
    printf("\n%-14s%d  square feet", "Area", area);
    
}

void printCharges(int length, int width, float carpetCost, int discount){

  printf("hi");
}

//Implement your function definitions here.


/**
 * NOTE: formatting guide
 * printf("%15sEND", "hello world");
 *     hello worldEND
 * ^^^^^^^^^^^^^^^^^^
 * hello world will allocate 15 character and it will appear as right justified
 * 
 * printf("%-15sEND", "hello world");
 * hello world    END
 * ^^^^^^^^^^^^^^^^^^
 * hello world will allocate 15 character and adding the negative(-) will appear 
 * as left justified
 * 
 * This applies to all format specifiers.
 */