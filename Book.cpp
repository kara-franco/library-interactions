/*********************************************************
 ** Author: Kara Franco				**
 ** Date: June 1, 2015					**
 ** Description: A program that demonstrates Book's     **
 ** ability to override the base class, LibraryItem's   **
 ** pure virtual function.				**
 *********************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "LibraryItem.hpp"
#include "Book.hpp"

// Book constructor definition with LibraryItem specification
Book::Book(std::string idc, std::string t, std::string inputAuthor)
	:LibraryItem(idc, t){
		author = inputAuthor;
	}

/*****************************************************************
 ** getCheckOutLength Description: This get method overrides    **
 ** the pure virtual function in LibraryItem to return the      **
 ** number of days that a book may be checked out, which is 21. **
 *****************************************************************/

int Book::getCheckOutLength(){
	return CHECK_OUT_LENGTH;
}

/****************************************************************
 ** getAuthor Description: This get method returns the name of **
 ** the Book's author.					       **
 ****************************************************************/

std::string Book::getAuthor(){
	return author;
}
