//        __          _______    __
//       / /  ___    /__  __/ __/ /  ____
//      / /  / _ | __  / / / / / /  / __/    patterns
//     / /__/ __ |/ /_/ / /_/ / /__/ -__     2012, Julien Rouzieres
//    /____/_/ |_|\____/|____/____/____/     https://github.com/Lajule/patterns
//
#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <set>
#include <iostream>

namespace Patterns
{

	///////////////////////////////////////////////////////////////////////////
	// class template Flyweight
	// Flyweight pattern.
	// See:
	//   Design Patterns (Chapter 4. Structural Patterns)
	///////////////////////////////////////////////////////////////////////////
	template <class T>
	class Flyweight
	{
	public:
		Flyweight(const T& value) : _value(*_set.insert(value).first) {}

		operator const T&() const
		{ return _value; }

		bool operator==(const Flyweight& rhs) const
		{ return _value == rhs._value; }

		bool operator!=(const Flyweight& rhs) const
		{ return  !(*this == rhs); }

		bool operator<(const Flyweight& rhs) const
		{ return _value < rhs._value; }

		bool operator>(const Flyweight& rhs) const
		{ return rhs < *this; }

		bool operator<=(const Flyweight& rhs) const
		{ return !(rhs < *this); }

		bool operator>=(const Flyweight& rhs) const
		{ return !(*this < rhs); }

		const T& Value() const
		{ return _value; }

		static std::set<T>& Values()
		{ return _set; }

		static typename std::set<T>::size_type Count()
		{ return _set.size(); }

	protected:
		const T& _value;
		static std::set<T> _set;
	};

	// static initialization
	template <class T>
	std::set<T> Flyweight<T>::_set;

	template <class T>
	std::ostream& operator<<(std::ostream& o, const Flyweight<T>& rhs)
	{
		return o << rhs.Value();
	}

}

#endif
