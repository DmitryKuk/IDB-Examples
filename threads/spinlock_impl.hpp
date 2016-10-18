// Author: Dmitry Kukovinets (d1021976@gmail.com), 18.06.2016, 22:08


inline
bool
colius::multithreading::spinlock::try_lock() noexcept
{
	return !this->test_and_set();
}


inline
void
colius::multithreading::spinlock::lock() noexcept
{
	while (this->test_and_set())
		;
}


inline
void
colius::multithreading::spinlock::unlock() noexcept
{
	this->state_.clear(std::memory_order_release);
}


// private
inline
bool
colius::multithreading::spinlock::test_and_set() noexcept
{
	return this->state_.test_and_set(std::memory_order_acquire);
}
