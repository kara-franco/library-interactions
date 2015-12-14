/*************************************************************
 ** Author: Kara Franco					    **
 ** Date: June 1, 2015					    **
 ** Description: A header file that contains the class      **
 ** declaration of Movie class, a class derived from	    **
 ** LibraryItem class.					    **
 *************************************************************/

#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include <vector>
#include "LibraryItem.hpp"

// class declaration
class Movie : public LibraryItem {

	private:
		std::string director;

	public:
		static const int CHECK_OUT_LENGTH = 7;

		int getCheckOutLength();

		std::string getDirector();

		// constructor
		Movie(std::string idc, std::string t, std::string inputDirector);

};

#endif
