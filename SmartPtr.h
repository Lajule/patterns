//        __         _______    __
//       / /  ___   /__  __/ __/ /  ____
//      / /  / _ |_   / / / / / /  / __/     patterns
//     / /__/ __ | \_/ / /_/ / /__/ -__      2012, Julien Rouzieres
//    /____/_/ |_|\___/|____/____/____/      https://github.com/Lajule/patterns
//
#ifndef SMARTPTR_H
#define SMARTPTR_H

#include <cstddef>
#include <algorithm>

namespace Patterns
{

	///////////////////////////////////////////////////////////////////////////
	// class template SmartPtr
	// Smart Pointers idiom.
	// See:
	//   Modern C++ Design (Chapter 7. Smart Pointers)
	///////////////////////////////////////////////////////////////////////////
	template <class T>
	class SmartPtr
	{
	public:
		explicit SmartPtr(T* ptr = 0) : _ptr(ptr), _ref(0)
		{
			if (ptr)
				_ref = new std::size_t(1);
		}

		SmartPtr(const SmartPtr& sp) : _ptr(sp._ptr), _ref(sp._ref)
		{
			if (_ref)
				++*_ref;
		}

		~SmartPtr()
		{
			if (_ref && !--*_ref) {
				delete _ptr;
				delete _ref;
			}
		}

		SmartPtr& operator=(const SmartPtr& rhs)
		{
			SmartPtr tmp(rhs);
			tmp.Swap(*this);
			return *this;
		}

		T& operator*() const
		{ return *_ptr; }

		T* operator->() const
		{ return _ptr; }

		operator T*() const
		{ return _ptr; }

		bool operator!() const
		{ return _ptr == 0; }

		bool operator==(const SmartPtr& rhs) const
		{ return _ptr == rhs._ptr; }

		bool operator!=(const SmartPtr& rhs) const
		{ return !(*this == rhs); }

		bool operator<(const SmartPtr& rhs) const
		{ return _ptr < rhs._ptr; }

		bool operator>(const SmartPtr& rhs) const
		{ return rhs < *this; }

		bool operator<=(const SmartPtr& rhs) const
		{ return !(rhs < *this); }

		bool operator>=(const SmartPtr& rhs) const
		{ return !(*this < rhs); }

		T* Get() const
		{ return _ptr; }

		std::size_t Count() const
		{
			if (_ref)
				return *_ref;
			return 0;
		}

		void Swap(SmartPtr& other)
		{
			std::swap(_ptr, other._ptr);
			std::swap(_ref, other._ref);
		}

	private:
		T* _ptr;
		std::size_t* _ref;
	};

}

#endif
