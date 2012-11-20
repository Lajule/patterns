#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "TypeList.h"

namespace Patterns
{

	///////////////////////////////////////////////////////////////////////////
	// class template AbstractFactory
	// Abstract Factory pattern.
	// See:
	//   Design Patterns (Chapter 3. Creational Patterns)
	//   Modern C++ Design (Chapter 8. Object Factories)
	///////////////////////////////////////////////////////////////////////////
	template <class T>
	class AbstractFactory
	{
	public:
		virtual ~AbstractFactory() {}
		virtual T* Create(T*) const = 0;
	};

	// partial template specialization for TypeList
	template <class Head, class Tail>
	class AbstractFactory<TypeList<Head, Tail> > :
		public AbstractFactory<Head>,
		public AbstractFactory<Tail>
	{
	public:
		using AbstractFactory<Head>::Create;
		using AbstractFactory<Tail>::Create;
	};

	template <class Head>
	class AbstractFactory<TypeList<Head, End> > : public AbstractFactory<Head>
	{
	public:
		using AbstractFactory<Head>::Create;
	};

	///////////////////////////////////////////////////////////////////////////
	// function Create
	// Create a concrete product with given AbstractFactory.
	///////////////////////////////////////////////////////////////////////////
	template <class T>
	T* Create(AbstractFactory<T>& factory, T* model = 0)
	{
		return factory.Create(model);
	}

	template <class T>
	T* Create(const AbstractFactory<T>& factory, T* model = 0)
	{
		return factory.Create(model);
	}
}

#endif
