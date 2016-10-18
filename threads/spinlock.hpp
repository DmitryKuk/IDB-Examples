// Author: Dmitry Kukovinets (d1021976@gmail.com), 18.06.2016, 22:08

// This file contains class spinlock, which provides same functionality as std::mutex,
// but allows to avoid context switching, if threads locks and unlocks it frequently.
// Objects of class spinlock are 100% thread-safe (all methods).


#ifndef COLIUS_MULTITHREADING_SPINLOCK_HPP
#define COLIUS_MULTITHREADING_SPINLOCK_HPP

#include <atomic>


namespace colius {
namespace multithreading {


class spinlock
{
public:
	spinlock() noexcept = default;
	
	
	spinlock(const spinlock &other) = delete;
	spinlock(spinlock &&other) = delete;
	
	spinlock & operator=(const spinlock &other) = delete;
	spinlock & operator=(spinlock &&other) = delete;
	
	
	inline bool try_lock() noexcept;
	inline void lock() noexcept;
	inline void unlock() noexcept;
private:
	inline bool test_and_set() noexcept;
	
	
	// Data
	std::atomic_flag state_ = ATOMIC_FLAG_INIT;
};	// class spinlock


};	// namespace multithreading
};	// namespace colius


#include "spinlock_impl.hpp"

#endif	// COLIUS_MULTITHREADING_SPINLOCK_HPP
