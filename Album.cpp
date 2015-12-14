/*********************************************************
 ** Author: Kara Franco					**
 ** Date: June 1, 2015					**
 ** Description: A program that demonstrates Album's    **
 ** ability to override the base class, LibraryItem's   **
 ** pure virtual function.				**
 *********************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "LibraryItem.hpp"
#include "Album.hpp"

// Book constructor definition with LibraryItem specification
Album::Album(std::string idc, std::string t, std::string inputArtist)
	:LibraryItem(idc, t){
		artist = inputArtist;
	}

/*******************************************************************
 ** getCheckOutLength Description: This get method overrides      **
 ** the pure virtual function in LibraryItem to return the        **
 ** number of days that an album may be checked out, which is 14. **
 *******************************************************************/

int Album::getCheckOutLength(){
	return CHECK_OUT_LENGTH;
}

/****************************************************************
 ** getAuthor Description: This get method returns the name of **
 ** the artist of the album.				       **
 ****************************************************************/

std::string Album::getArtist(){
	return artist;
}
