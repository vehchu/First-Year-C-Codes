#include <stdio.h>
#include <stdlib.h>
#include "cis1201.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	printf("[1.0 ] Empoyee List (ID & Name): \n\n");
	// start of no.1
	// make the code below work by updating the populateEmployeeList() in cis1201.c
	EmployeePtr employees = populateEmployeeList();
	displayEmployees(employees);
	// end of no.1
	
	printf("\n\n\n");
	system("pause");
	system("cls");
	
	printf("[2.0 ] Convert 12-hour time format to 24-hour time format:\n");
	// start of no.2
	/* make your declaration and function calls here for no.2
	 * utilize the newly created function and usable functions in cis1201 files
	 */
	 MyTime oldTime={1,01,false}; // <--- 1:00PM in 12HRS
	  MyTime newTime=convertTime(oldTime);
	  
	  displayTime12(oldTime);
	  printf("\n");
	  displayTime24(newTime);
	




	//end of no.2
	
	printf("\n\n\n");
	system("pause");
	system("cls");
	
	printf("[3.0 ] Employee Information (DISPLAY):\n\n");
	// start of no.3
	/* using the employee list in no.1 display all there information
	 * utilizing the display employee info (single employee) function
	 * create necessary decleration here for no.3
	 */
	 
	 
	 
	 int i=0;
	 for(i=0;i<5;i++){
	 	displaySingleEmployee(employees[i]);
	 }
	
	
	
	
	// end of no.3
	
	printf("\n\n\n");
	system("pause");
	system("cls");
	
	printf("[4.0 ] Employees that are late on a specified day in the morning(DISPLAY NAMES):\n\n");
	// start of no.4
	// display all the late employees and make you necessary declaration here
	int counter =5;
	
	NamePtr lateNames=getLateEmployees(employees,&counter,2);
	
	for(i=0;i<counter;i++){
	displayName(lateNames[i]);
}
	
	
	

	//end of no.4
	
	printf("\n\n\n");
	system("pause");
	return 0;
}
