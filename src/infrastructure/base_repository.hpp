/*
 * base_repository.hpp
 *
 *  Created on: Mar 17, 2019
 *      Author: bartlomiej
 */

#ifndef INFRASTRUCTURE_BASE_REPOSITORY_HPP_
#define INFRASTRUCTURE_BASE_REPOSITORY_HPP_

#include <string>

namespace infrastructure {

class BaseRepository {

private:
	static const char* DATA_PATH;
	std::string file_path_;
public:
	BaseRepository( const char* file_path );
	const char* get_path() const;
};

}



#endif /* INFRASTRUCTURE_BASE_REPOSITORY_HPP_ */
