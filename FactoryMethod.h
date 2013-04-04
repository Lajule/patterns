#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <map>
#include <stdexcept>

namespace Patterns
{

	///////////////////////////////////////////////////////////////////////////
	// class template FactoryMethod
	// Factory Method pattern.
	// See:
	//   Design Patterns (Chapter 3. Creational Patterns)
	//   Modern C++ Design (Chapter 8. Object Factories)
	///////////////////////////////////////////////////////////////////////////
	template <class Product, class Identifier, class Creator = Product* (*)()>
	class FactoryMethod
	{
	public:
		bool Register(const Identifier& id, Creator c)
		{ return _map.insert(typename CreatorMap::value_type(id, c)).second; }

		bool Unregister(const Identifier& id)
		{ return _map.erase(id) == 1; }

		virtual Product* Create(const Identifier& id)
		{
			typename CreatorMap::iterator it = _map.find(id);
			if (it != _map.end())
				return (*it).second();
			throw std::out_of_range("FactoryMethod::Create");
		}

	protected:
		typedef std::map<Identifier, Creator> CreatorMap;
		CreatorMap _map;
	};

}

#endif
