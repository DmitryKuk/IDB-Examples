// Dmitry Kukovinets <d1021976@gmail.com>, 10.11.2016, 21:06

#ifndef ANY_HPP
#define ANY_HPP

#include <iostream>
#include <memory>
#include <utility>
#include <type_traits>
#include <stdexcept>

#include <boost/type_index.hpp>


class bad_any_cast: public std::logic_error
{
public:
	template<class T>
	inline bad_any_cast(T &&message):
		std::logic_error{std::forward<T>(message)}
	{}
};	// class bad_any_cast



class handler_base
{
public:
	virtual ~handler_base() = default;
	
	virtual const void * data_ptr(const std::type_info &ti) const = 0;
	virtual void * data_ptr(const std::type_info &ti) = 0;
	
	virtual std::unique_ptr<handler_base> clone() const = 0;
	
	virtual void print(std::ostream &stream) const = 0;
};	// class handler_base



template<class T>
class handler: public handler_base
{
public:
	using value_type = T;
	
	
	template<class... Args>
	inline handler(Args &&... args):
		data_(std::forward<Args>(args)...)
	{}
	
	
	
	virtual inline const void * data_ptr(const std::type_info &ti) const override final
	{
		this->assert_type(ti);
		return std::addressof(this->data_);
	}
	
	virtual inline void * data_ptr(const std::type_info &ti) override final
	{
		this->assert_type(ti);
		return std::addressof(this->data_);
	}
	
	
	virtual inline std::unique_ptr<handler_base> clone() const override final
	{
		return std::make_unique<handler<value_type>>(this->data_);
	}
	
	
	virtual inline void print(std::ostream &stream) const override final
	{
		stream << this->data_ << " (of type: " << boost::typeindex::type_id<value_type>().pretty_name() << ')';
	}
private:
	inline void assert_type(const std::type_info &ti) const
	{
		if (ti != typeid(value_type))
			throw bad_any_cast{"Incorrect type"};
	}
	
	
	T data_;
};	// class handler



class any
{
public:
	any() = default;
	
	
	// Set value
	template<class T>
	inline any(T &&value)
	{
		(*this) = std::forward<T>(value);
	}
	
	
	// Move
	any(any &&other) = default;
	any & operator=(any &&other) = default;
	
	
	// Copy
	inline any(const any &other)
	{
		(*this) = other;
	}
	
	inline any & operator=(const any &other)
	{
		if (other.handler_ptr_ != nullptr)
			this->handler_ptr_ = other.handler_ptr_->clone();
		return *this;
	}
	
	
	inline void print(std::ostream &stream) const
	{
		if (this->handler_ptr_ != nullptr)
			this->handler_ptr_->print(stream);
		else
			stream << "<empty any>";
	}
	
	
	// Set value
	template<class T>
	inline any & operator=(T &&value)
	{
		this->handler_ptr_ = std::make_unique<handler<std::decay_t<T>>>(std::forward<T>(value));
		return *this;
	}
	
	
	template<class T>
	inline T & get()
	{
		this->assert_ptr();
		return *static_cast<T *>(this->handler_ptr_->data_ptr(typeid(T)));
	}
	
	template<class T>
	inline const T & get() const
	{
		this->assert_ptr();
		return *static_cast<const T *>(this->handler_ptr_->data_ptr(typeid(T)));
	}
private:
	inline void assert_ptr() const
	{
		if (this->handler_ptr_ == nullptr)
			throw std::logic_error{"Empty any"};
	}
	
	
	std::unique_ptr<handler_base> handler_ptr_;
};	// class any



template<class T>
inline T & any_cast(any &a)
{
	return a.template get<T>();
}


template<class T>
inline const T & any_cast(const any &a)
{
	return a.template get<T>();
}



inline std::ostream & operator<<(std::ostream &stream, const any &a)
{
	a.print(stream);
	return stream;
}


#endif	// ANY_HPP
