/*
 * base_repository.cpp
 *
 *  Created on: Mar 17, 2019
 *      Author: bartlomiej
 */

#include "base_repository.hpp"

namespace infrastructure {

const char* BaseRepository::DATA_PATH = "../data/";

BaseRepository::BaseRepository( const char* file_path ) : file_path_( BaseRepository::DATA_PATH )
{
	file_path_.append( file_path );
}

const char* BaseRepository::get_path() const
{
	return file_path_.c_str();
}
}


