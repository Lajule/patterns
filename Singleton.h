//        __         _______    __
//       / /  ___   /__  __/ __/ /  ____
//      / /  / _ |_   / / / / / /  / __/     patterns
//     / /__/ __ | \_/ / /_/ / /__/ -__      2012, Julien Rouzieres
//    /____/_/ |_|\___/|____/____/____/      https://github.com/Lajule/patterns
//
#ifndef SINGLETON_H
#define SINGLETON_H

#include "SmartPtr.h"

namespace Patterns
{

	///////////////////////////////////////////////////////////////////////////
	// class template Singleton
	// Singleton pattern.
	// See:
	//   Design Patterns (Chapter 3. Creational Patterns)
	///////////////////////////////////////////////////////////////////////////
	template <class T>
	class Singleton
	{
	public:
		static T& Reference() 
		{ return *_instance; }

		static T* Pointer()
		{ return _instance.Get(); }

	private:
		static SmartPtr<T> _instance;
	};

	// static initialization
	template <class T>
	SmartPtr<T> Singleton<T>::_instance(new T());

}

#endif
