#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cis1201.h"

MyTime newTime(int hour, int minute, Boolean meridian) {
	MyTime t;
	
	t.hour = hour;
	t.minute = minute;
	t.meridian = meridian;
	
	return t;	
}

Attendance newAttendance(MyTime in, MyTime out) {
	Attendance a;
	
	a.in = in;
	a.out = out;
	
	return a;	
}

Name newName(String firstname, String middlename, String lastname) {
	Name n;
	
	strcpy(n.firstname, firstname);
	strcpy(n.middlename, middlename);
	strcpy(n.lastname, lastname);
	
	return n;	
}

Address newAddress(int houseNumber, String barangay, String city, int zip) {
	Address a;
	
	a.houseNumber = houseNumber;
	strcpy(a.barangay, barangay);
	strcpy(a.city, city);
	a.zip = zip;
	
	return a;	
}

Employee newEmployee(int empID, Name empName, Address empAddress, Attendance attMon, Attendance attTue, Attendance attWed, Attendance attThu, Attendance attFri) {
	Employee e;
	
	e.empID = empID;
	e.empName = empName;
	e.empHomeAddress = empAddress;
	e.empDTR[0] = attMon;
	e.empDTR[1] = attTue;
	e.empDTR[2] = attWed;
	e.empDTR[3] = attThu;
	e.empDTR[4] = attFri;
	
	return e;
}

EmployeePtr populateEmployeeList() {
	// create your declaration for the list of employees here...

    Employee* list = (Employee*)malloc(sizeof(Employee)*6);

	list[0] = newEmployee(1000, newName("Khent", "Yu", "dela Paz"), newAddress(12, "Talamban", "Cebu", 6000), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)));	
	list[1] = newEmployee(1001, newName("Christian", "Felix", "Maderazo"), newAddress(17, "Talamban", "Cebu", 6000), newAttendance(newTime(7, 45, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 15, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(4, 30, false)), newAttendance(newTime(8, 0, true), newTime(5, 10, false)));
	list[2] = newEmployee(1002, newName("Peter", "Fuerzas", "Fillo"), newAddress(20, "Talamban", "Cebu", 6000), newAttendance(newTime(8, 0, true), newTime(4, 0, false)), newAttendance(newTime(12, 30, false), newTime(5, 0, false)), newAttendance(newTime(8, 20, true), newTime(5, 0, false)), newAttendance(newTime(8, 5, true), newTime(5, 0, false)), newAttendance(newTime(9, 0, true), newTime(5, 0, false)));
	list[3] = newEmployee(1003, newName("Christine", "Arellano", "Pena"), newAddress(15, "Basak", "Mandaue", 6032), newAttendance(newTime(7, 0, true), newTime(7, 15, false)), newAttendance(newTime(7, 45, true), newTime(8, 0, false)), newAttendance(newTime(7, 50, true), newTime(9, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 15, false)), newAttendance(newTime(8, 0, true), newTime(5, 45, false)));
	list[4] = newEmployee(1004, newName("Patrick Troy", "Ceniza", "Elalto"), newAddress(12, "Yati", "Mandaue", 6032), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)));
	list[5] = newEmployee(0, newName("", "", ""), newAddress(0, "", "", 0), newAttendance(newTime(12, 0, true), newTime(12, 0, true)), newAttendance(newTime(12, 0, true), newTime(12, 0, true)), newAttendance(newTime(12, 0, true), newTime(12, 0, true)), newAttendance(newTime(12, 0, true), newTime(12, 0, true)), newAttendance(newTime(12, 0, true), newTime(12, 0, true)));
	
	// create a return statement for the list of employees here...
	return list;
	
}

void displayTime24(MyTime t) {
	printf("%02d:%02d", t.hour, t.minute);
}

void displayTime12(MyTime t) {
	if(t.meridian == true) {
		printf("%02d:%02d AM", t.hour, t.minute);
	} else {
		printf("%02d:%02d PM", t.hour, t.minute);
	}	
}

void displayAddress(Address a) {
	printf("%d Brgy. %s, %s City, %d", a.houseNumber, a.barangay, a.city, a.zip);
}

void displayName(Name n) {
	printf("%s, %s", n.lastname, n.firstname);
	if(strcmp(n.middlename,"") != 0) {
		printf(" %c.", n.middlename[0]);
	}
}

void displayEmployees(EmployeePtr list) {
	int i = 0;
	printf("%10s | %s\n", "ID", "NAME");
	
	while(list[i].empID != 0) {
		printf("%10d | ", list[i].empID);
		displayName(list[i].empName);
		printf("\n");
		i++;
	}
}

MyTime convertTime(MyTime t){

    if(t.meridian == false && t.hour>=1){
        t.hour+=12; 
    }
    else if(t.meridian == true && t.hour ==12){
        t.hour = 0;
    }
    
    return t;

}


void displaySingleEmployee(Employee emp){

    String days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    printf("ID: %d", emp.empID);
    printf("\nName: %s, %s %c.", emp.empName.lastname, emp.empName.firstname, emp.empName.middlename);
    printf("\nAddress: %d %s. %s, %s City %d", emp.empHomeAddress.houseNumber, emp.empHomeAddress.barangay, emp.empHomeAddress.city, emp.empHomeAddress.zip);
    printf("\nDAILY TIME RECORD:");
    for(int i = 0; i < 5; ++i){
        printf("%s    :", days[i]);
        displayTime12(emp.empDTR[i].in);
        printf(" | ");
        displayTime12(emp.empDTR[i].out);
        printf("\n");
    }


}

NamePtr getLateEmployees(Employee list[],int *count,int day){

    
 
}
