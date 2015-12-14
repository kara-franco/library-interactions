/*********************************************************
 ** Author: Kara Franco					**
 ** Date: June 1, 2015					**
 ** Description: A program that demonstrates Movie's    **
 ** ability to override the base class, LibraryItem's   **
 ** pure virtual function.				**
 *********************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "LibraryItem.hpp"
#include "Movie.hpp"

// Book constructor definition with LibraryItem specification
Movie::Movie(std::string idc, std::string t, std::string inputDirector)
	:LibraryItem(idc, t){
		director = inputDirector;
	}

/*****************************************************************
 ** getCheckOutLength Description: This get method overrides    **
 ** the pure virtual function in LibraryItem to return the      **
 ** number of days that a movie may be checked out, which is 7. **
 *****************************************************************/

int Movie::getCheckOutLength(){
	return CHECK_OUT_LENGTH;
}

/*****************************************************************
 ** getAuthor Description: This get method returns the name of  **
 ** the Movie's director.				        **
 *****************************************************************/

std::string Movie::getDirector(){
	return director;
}
