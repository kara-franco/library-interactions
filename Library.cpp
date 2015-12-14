/******************************************************************
 ** Author: Kara Franco						 **
 ** Date: June 1, 2015						 **
 ** Description: An implementation file for the Library class    **
 ** that demonstrates aggregation through pointers.		 **
 ******************************************************************/

#include <string>
#include <vector>
#include "Book.hpp"
#include "Album.hpp"
#include "Movie.hpp"
#include "Patron.hpp"
#include "Library.hpp"

Library::Library(){
}

/*********************************************************************
 ** addLibraryItem Description: This function adds the LibraryItem  **
 ** object parameter to holdings.				    **
 *********************************************************************/

void Library::addLibraryItem(LibraryItem* anItem){
	holdings.push_back(anItem);
}

/**********************************************************************
 ** addPatron Description: This funtion adds a Patron object to the  **
 ** members vector.						     **
 **********************************************************************/

void Library::addPatron(Patron* aPatron){
	members.push_back(aPatron);
}

/***********************************************************************
 ** getLibraryItem Description: This get method returns a pointer to  **
 ** the LibraryItem corresponding to the ID parameter, or NULL if the **
 ** LibraryItem is not in the holdings.				      **
 ***********************************************************************/

LibraryItem* Library::getLibraryItem(std::string ItemID){
	// search the vector of objects for the object with the specific ID
	for (int i = 0; i < holdings.size(); i++){
		std::string _idOfItem = holdings[i]->getIdCode();
		// compare the IDs
		if (_idOfItem == ItemID){
			return holdings.at(i);
		}
	}
	return NULL;
}

/********************************************************************
 ** getPatron Description: This get method returns a pointer to    **
 ** the Patron corresponding to the patron identification number,  **
 ** or NULL if the patron is not a member.			   **
 ********************************************************************/

Patron* Library::getPatron(std::string patronID){
	// search the vector of Patron objects for the object with the specific ID
	for (int i = 0; i < members.size(); i++){
		std::string _idOfpatron = members[i]->getIdNum();
		// compare the IDs
		if (_idOfpatron == patronID){
			return members.at(i);
		}
	}
	return NULL;
}

/*********************************************************************
 ** checkOutLibraryItem Description: This function allows a patron  **
 ** to check out a LibraryItem and updates the data in LibraryItem  **
 ** and returns a string responding to the status of the checkout.  **
 *********************************************************************/

std::string Library::checkOutLibraryItem(std::string patronID, std::string ItemID){
	// get the pointer to objects of both the patron and item
	LibraryItem* itemToCheckOut = getLibraryItem(ItemID);
	Patron* patronCheckingOut = getPatron(patronID);

	// if the LibraryItem is not in the Library
	if (itemToCheckOut == NULL){
		return "item not found";
	}
	// if the Patron is not in the Library
	if (patronCheckingOut == NULL) {
		return "patron not found";
	}
	// get the location of the item and the pointer to patron of requests
	Locale locationOfItem = itemToCheckOut->getLocation();
	Patron* patronRequestingItem = itemToCheckOut->getRequestedBy();

	// if the LibraryItem is already checked out
	if (locationOfItem == CHECKED_OUT){
		return "item already checked out";
	}
	// if the Library Item is on hold by another patron
	if (locationOfItem == ON_HOLD_SHELF &&  patronRequestingItem != patronCheckingOut){
		return "item on hold by other patron";
	}
	// if the LibraryItem was on hold for this Patron or on the shelf
	else {
		// update checkedOutBy
		itemToCheckOut->setCheckedOutBy(patronCheckingOut);
		// update dateCheckedOut
		itemToCheckOut->setDateCheckedOut(currentDate);
		// update Patron's checkedOutItems
		patronCheckingOut->addLibraryItem(itemToCheckOut);

		if (locationOfItem == ON_HOLD_SHELF) {
			// update requestedBy
			itemToCheckOut->setRequestedBy(NULL);
		}
		// update location
		itemToCheckOut->setLocation(CHECKED_OUT);
		return "check out successful";
	}
}

/**********************************************************************
 **  returnLibraryItem Description: This function allows a patron    **
 ** to return a LibraryItem. The data in LibraryItem will be updated **
 ** with a return of a string responding to the status of the return.**
 **********************************************************************/

std::string Library::returnLibraryItem(std::string ItemID){
	// get pointer to library item object
	LibraryItem* itemReturnedToLibrary = getLibraryItem(ItemID);
	// if the specific item is not in the library
	if (itemReturnedToLibrary == NULL){
		return "item not found";
	}
	// get the patron that is returning the item, the item location and the pointer patron requesting
	Patron* patronReturningItem = itemReturnedToLibrary->getCheckedOutBy();
	Locale locationOfItem = itemReturnedToLibrary->getLocation();
	Patron* patronRequestingItem = itemReturnedToLibrary->getRequestedBy();
	// if the item is not checked out
	if (locationOfItem == ON_SHELF){
		return "item already in library";
	}
	else{
		// update checkedOutItems
		patronReturningItem->removeLibraryItem(itemReturnedToLibrary);
		// update checkedOutBy
		itemReturnedToLibrary->setCheckedOutBy(NULL);
		// update item location depending whether another Patron has requested it
		if (patronRequestingItem != NULL){
			// update location to on hold
			itemReturnedToLibrary->setLocation(ON_HOLD_SHELF);
		}
		// update location to on shelf
		else{
			itemReturnedToLibrary->setLocation(ON_SHELF);
		}
		return "return successful";
	}
}


/***********************************************************************
 ** requestLibraryItem Description: This function allows a patron     **
 ** to request a LibraryItem. The data in LibraryItem will be updated **
 ** with a return of a string responding to the status of the request.**
 ***********************************************************************/

std::string Library::requestLibraryItem(std::string patronID, std::string ItemID){
	// get the pointers to the item and patron objects
	LibraryItem* itemToRequest = getLibraryItem(ItemID);
	Patron* patronRequesting = getPatron(patronID);

	// if the LibraryItem is not in the Library
	if (itemToRequest == NULL){
		return "item not found";
	}
	// if the Patron is not in the Library
	if (patronRequesting == NULL) {
		return "patron not found";
	}
	// get the item location and possible existing patron that has already requested the item
	Locale locationOfItem = itemToRequest->getLocation();
	Patron* existingRequester = itemToRequest->getRequestedBy();

	// if the item is already requested by another patron
	if (existingRequester != NULL){
		return "item on hold by other patron";
	}
	else {
		// update item requestedBy
		itemToRequest->setRequestedBy(patronRequesting);
		// if item is on the shelf change the locale status
		if (locationOfItem == ON_SHELF){
			itemToRequest->setLocation(ON_HOLD_SHELF);
		}
		return "request successful";
	}
}

/****************************************************************
 ** payFine Description: A function that reduces the fine for  **
 ** a specific patron after they have paid.		       **
 ****************************************************************/

std::string Library::payFine(std::string patronID, double payment){
	Patron* patronPayingFine = getPatron(patronID);
	// if the Patron is not in the Library
	if (patronPayingFine == NULL) {
		return "patron not found";
	}
	// update amendFine
	patronPayingFine->amendFine(-payment);
	return "payment successful";
}

/******************************************************************
 ** incrementCurrentDate Description: This function increments   **
 ** the date while also identifying all overdue library items,   **
 ** and charging the corresponding patron.	 		 **
 ******************************************************************/

void Library::incrementCurrentDate(){
	// increment to current date
	currentDate++;
	// search Patron's data for overdue items
	for (int i = 0; i < members.size(); i++){
		// getCheckedOutItems for each Patron
		std::vector<LibraryItem*> patronItems = members[i]->getCheckedOutItems();

		// find the amount of days item has been checked out
		for (int j = 0; j < patronItems.size(); j++){
			// get the date that patron checked out
			int checkOutDate = patronItems[j]->getDateCheckedOut();
			// daysCheckedOut is the number of days the item has been checked out
			int daysCheckedOut = currentDate - checkOutDate;
			// get the allowed check out period
			int itemCheckOutPeriod = patronItems[j]->getCheckOutLength();

			// compare for overdue item
			if (daysCheckedOut > itemCheckOutPeriod){
				// if over, charge 10 cents per day
				members[i]->amendFine(.10);
			}
		}
	}
}
