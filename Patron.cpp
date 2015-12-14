/**************************************************************
 ** Author: Kara Franco					     **
 ** Date: June 1, 2015					     **
 ** Description: An implementation file for the Patron class **
 ** that controls Patron data and shares this information    **
 ** with Library class through pointers.		     **
 **************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Patron.hpp"

using namespace std;

// constructor
Patron::Patron(std::string idn, std::string n){
	idNum = idn;
	name = n;
}

/*************************************************************
 ** getIdNum Description: This get method will return the   **
 ** identification number of the patron.		    **
 *************************************************************/

std::string Patron::getIdNum(){
	return idNum;
}

/***************************************************************
 ** getName Description: This get method will return the name **
 ** of the patron.			  		      **
 ***************************************************************/

std::string Patron::getName(){
	return name;
}

/***************************************************************
 ** getCheckedOutItems Description: This get method will      **
 ** return a vector of the items that are checked out by the  **
 ** patron. The items belong to LibraryItem class.	      **
 ***************************************************************/

std::vector<LibraryItem*> Patron::getCheckedOutItems(){
	return checkedOutItems;
}

/*****************************************************************
 ** addLibraryItem Description: This function adds the specific **
 ** LibraryItem to checkedOutItems vector.		        **
 *****************************************************************/

void Patron::addLibraryItem(LibraryItem* b){
	checkedOutItems.push_back(b);

}

/******************************************************************
 ** removeLibraryItem Description: This function will remove the **
 ** specific LibraryItem from the checkedOutItems vector.	 **
 ******************************************************************/

void Patron::removeLibraryItem(LibraryItem* b){
	checkedOutItems.erase(std::remove(checkedOutItems.begin(),
	checkedOutItems.end(), b), checkedOutItems.end());
}

/******************************************************************
 ** getFineAmount Description: This get method will return the   **
 ** amount of the fine.						 **
 ******************************************************************/

double Patron::getFineAmount(){
	return fineAmount;
}

/******************************************************************
 ** amendFine Description: This function will either increase    **
 ** the fine amount or descrease it.				 **
 ******************************************************************/
// a positive amount arguement will increase the total fine
// a negative amount arguement will decrease the total fine
void Patron::amendFine(double amount){
	fineAmount += amount;
}
