/*************************************************************
 ** Author: Kara Franco					    **
 ** Date: June 1, 2015					    **
 ** Description: An implementation file for the LibraryItem **
 ** class. This demonstrates an abstract parent class with  **
 ** a pure virtual function.  		                    **
 *************************************************************/
#include <iostream>
#include <string>
#include "LibraryItem.hpp"

using namespace std;

// constructor
LibraryItem::LibraryItem(std::string idc, std::string t) {
	idCode = idc;
	title = t;
	checkedOutBy = NULL;
	requestedBy = NULL;
	setLocation(ON_SHELF);
}

/**************************************************************
 ** setLocation Description: This set method will set the    **
 ** _location parameter to the location data member.	     **
 **************************************************************/

void LibraryItem::setLocation(Locale _location){
	location = _location;
}

/***************************************************************
 ** setCheckedOutBy Description: This set method will set     **
 ** the Patron information to the checkedOutBy data member.   **
 ***************************************************************/

void LibraryItem::setCheckedOutBy(Patron* _checkPatronInfo){
	checkedOutBy = _checkPatronInfo;
}

/****************************************************************
 ** setRequestedBy Description: This set method will set the   **
 ** Patron information to the requestedBy data member.	       **
 ****************************************************************/

void LibraryItem::setRequestedBy(Patron* _requestPatronInfo){
	requestedBy = _requestPatronInfo;
}

/*****************************************************************
 ** setDateCheckedOut Description: When an item is checked out  **
 ** this set method will set the dateCheckedOut to the data     **
 ** member currentDate of the Library.			        **
 *****************************************************************/

void LibraryItem::setDateCheckedOut(int currentDate){
	dateCheckedOut = currentDate;
}

/***************************************************************
 ** getIdCode Description: This get method will return the    **
 ** unique string Identification Code.			      **
 ***************************************************************/

std::string LibraryItem::getIdCode(){
	return idCode;
}

/***************************************************************
 ** getTitle Description: This get method will return the     **
 ** string Title.					      **
 ***************************************************************/

std::string LibraryItem::getTitle(){
	return title;
}

/***************************************************************
 ** getLocation Description: This get method will return the  **
 ** location of the LiraryItem.				      **
 ***************************************************************/

Locale LibraryItem::getLocation(){
	return location;
}

/****************************************************************
 ** getCheckedOutBy Description: This get method will return   **
 ** the Patron information that has the item checked out.      **
 ****************************************************************/

Patron* LibraryItem::getCheckedOutBy(){
	return checkedOutBy;
}

/*****************************************************************
 ** getRequestedBy Description This get method will return the  **
 ** the Patron information who has requested the LibraryItem.   **
 *****************************************************************/

Patron* LibraryItem::getRequestedBy(){
	return requestedBy;
}

/*****************************************************************
 ** getDateCheckedOut Description: This get method will return  **
 ** the date that the LibraryItem was checked out.	        **
 *****************************************************************/

int LibraryItem::getDateCheckedOut(){
	return dateCheckedOut;
}
