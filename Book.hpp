/*************************************************************
 ** Author: Kara Franco					    **
 ** Date: June 1, 2015					    **
 ** Description: A header file that contains the class      **
 ** declaration of Book  class, a class derived from	    **
 ** LibraryItem class.					    **
 ************************************************************/

#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <vector>
#include "LibraryItem.hpp"

// class declaration
class Book : public LibraryItem {

	private:
		std::string author;

	public:
		static const int CHECK_OUT_LENGTH = 21;

		int getCheckOutLength();

		std::string getAuthor();

		// constructor
		Book(std::string idc, std::string t, std::string inputAuthor);

};

#endif
