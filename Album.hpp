/*************************************************************
 ** Author: Kara Franco					    **
 ** Date: June 1, 2015					    **
 ** Description: A header file that contains the class      **
 ** declaration of Album class, a class derived from	    **
 ** LibraryItem class.					    **
 *************************************************************/

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include <vector>
#include "LibraryItem.hpp"

// class declaration
class Album : public LibraryItem {

	private:
		std::string artist;

	public:
		static const int CHECK_OUT_LENGTH = 14;

		int getCheckOutLength();

		std::string getArtist();

		// constructor
		Album(std::string idc, std::string t, std::string inputArtist);

};

#endif
