#include<stdio.h>
const float LABOR_RATE=17.50;
const float TAX_RATE=12;
//FUNCTION PROTOTYPES
int getArea(int l, int w);

/*******************************************************************************
 * The computeInstalledPrice() will calculate the installed price. The installed 
 * price is the cost of carpet and the cost of labor.
 */
float computeInstalledPrice(int length, int width, float carpetCost);

/*******************************************************************************
 * The computeSubtotal() will calculate the subtotal. Based on installed price
 * and the discount.
 */
float computeSubtotal(int length, int width, float carpetCost, float discount);

/*******************************************************************************
 * The computeTotal() will calculate the total. Based on installed price, the 
 * discount and added tax.
 */
float computeTotal(int length, int width, float carpetCost, int discount);

/*******************************************************************************
 * The printMeasurement() will display all the measurements base on format. The
 * length, width and area.
 */
void printMeasurement(int length, int width);

/*******************************************************************************
 * The printCharges() will display all charges base on format (see output for
 * charges).
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
  printMeasurement(room_length,room_width);
  
  printf("\n");
  printCharges(room_length,room_width,carpet_price,customer_discount);
  
  return 0;
}

//function definitions
int getArea(int l, int w) 
{
  return l * w;
}

float computeInstalledPrice(int length, int width, float carpetCost){
float ip=0;
    ip=((length*width)*(carpetCost))+((length*width)*(LABOR_RATE));
return ip; 
}

float computeSubtotal(int length, int width, float carpetCost, float discount){
float sub;
    sub = computeInstalledPrice(length,width,carpetCost)*((100-discount)/100); 
return sub;   
}

float computeTotal(int length, int width, float carpetCost, int discount){
float total;
    total= computeSubtotal(length,width,carpetCost,discount)*((100+TAX_RATE)/100);
return total;
}

void printMeasurement(int length, int width){
    int area= getArea(length,width);
    printf("MEASUREMENT");
    printf("\n%-15s%d  feet", "Length", length);
    printf("\n%-15s%d  feet", "Width", width);
    printf("\n%-14s%d  square feet", "Area", area);
}

void printCharges(int length, int width, float carpetCost, int discount){
    float tc=getArea(length,width)*carpetCost;
    float IP=computeInstalledPrice(length, width, carpetCost);
    float labor= LABOR_RATE*getArea(length,width);
    float sub= computeSubtotal( length, width, carpetCost, discount);
    float dis=IP-sub;
    float total= computeTotal(length,  width, carpetCost, discount);
    float tax=total-sub;
    
    printf("CHARGES");
    printf("\nDESCRIPTION  COST/SQ.FT     CHARGE");
    printf("\n-----------  -------------  -------------");
    printf("\n%-20s%.2f  ", "Carpet       Php", carpetCost);
    printf("%-4s%.2f", "Php ", tc);
    printf("\n%-21s%.2f  ", "Labor", LABOR_RATE);
    printf("%-6s%.2f", "Php ", labor);
    printf("\n%-21s  ", "INSTALLED PPRICE");
    printf("%-6s%.2f", "Php ", IP);
     printf("\n%-21s  ", "Discount");
    printf("%-6s%.2f", "Php ", dis);
     printf("\n%-21s  ", "Subtotal");
    printf("%-6s%.2f", "Php ", sub);
     printf("\n%-21s  ", "Tax");
    printf("%-6s%.2f", "Php ", tax);
     printf("\n%-21s  ", "TOTAL");
    printf("%-6s%.2f", "Php ", total);
    

}
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