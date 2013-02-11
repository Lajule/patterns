#ifndef VISITOR_H
#define VISITOR_H

#include "TypeList.h"

namespace Patterns
{

	///////////////////////////////////////////////////////////////////////////
	// class template Visitor
	// Visitor pattern.
	// See:
	//   Design Patterns (Chapter 3. Behavioral Patterns)
	//   Modern C++ Design (Chapter 10. Visitor)
	///////////////////////////////////////////////////////////////////////////
	template <class T>
	class Visitor
	{
	public:
		virtual ~Visitor() {}
		virtual void Visit(T&) = 0;
	};

	// partial template specialization for TypeList
	template <class Head, class Tail>
	class Visitor<TypeList<Head, Tail> > :
		public Visitor<Head>,
		public Visitor<Tail>
	{
	public:
		using Visitor<Head>::Visit;
		using Visitor<Tail>::Visit;
	};

	template <class Head>
	class Visitor<TypeList<Head, End> > : public Visitor<Head>
	{
	public:
		using Visitor<Head>::Visit;
	};

}

#endif
