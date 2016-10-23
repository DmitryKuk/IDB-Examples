// Author: Dmitry Kukovinets (d1021976@gmail.com), 23.10.2016, 21:52

#ifndef NET_LOADED_HPP
#define NET_LOADED_HPP

#include <string>


namespace net {


class loaded
{
public:
	inline int status() const noexcept;
};	// class loaded


loaded get(std::string url);


};	// namespace net


#include "get_impl.hpp"

#endif	// NET_LOADED_HPP
