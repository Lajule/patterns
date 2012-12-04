#ifndef TUPLE_H
#define TUPLE_H

#include <cstddef>
#include "TypeList.h"

namespace Patterns
{

	///////////////////////////////////////////////////////////////////////////
	// class template TupleUnit.
	// A unit of the Tuple hierarchy.
	///////////////////////////////////////////////////////////////////////////
	template <class T, std::size_t>
	struct TupleUnit
	{
		T _value;

		operator T&()
		{ return _value; }

		operator const T&() const
		{ return _value; }
	};

	///////////////////////////////////////////////////////////////////////////
	// class template Tuple
	// Tuple idiom.
	// See:
	//   Modern C++ Design (3.13 Class Generation with Typelists)
	///////////////////////////////////////////////////////////////////////////
	template <class T> class Tuple;

	template <class Head, class Tail>
	struct Tuple<TypeList<Head, Tail> > :
		public TupleUnit<Head, Length<TypeList<Head, Tail> >::Value>,
		public Tuple<Tail>
	{
	public:
		typedef TypeList<Head, Tail> List;
	};

	template <class Head>
	class Tuple<TypeList<Head, End> > : public TupleUnit<Head, 1> {};

	namespace Private
	{
		// helper for Field function
		template <std::size_t Index, class T>
		struct FieldHelper {
			typedef typename T::List List;
			typedef typename TypeAt<List, Index>::Type Type;

			enum { Value = Length<List>::Value - Index };
			typedef TupleUnit<Type, Value> Unit;

			typedef Type Result;
		};

		template <std::size_t Index, class T>
		struct FieldHelper<Index, const T> {
			typedef typename T::List List;
			typedef typename TypeAt<List, Index>::Type Type;

			enum { Value = Length<List>::Value - Index };
			typedef const TupleUnit<Type, Value> Unit;

			typedef const Type Result;
		};
	}

	///////////////////////////////////////////////////////////////////////////
	// function Field
	// Gives access to a TupleUnit from a Tuple.
	///////////////////////////////////////////////////////////////////////////
	template <std::size_t Index, class T>
	typename Private::FieldHelper<Index, T>::Result& Field(T& tuple)
	{
		typename Private::FieldHelper<Index, T>::Unit& unit = tuple;
		return unit;
	}

}

#endif
