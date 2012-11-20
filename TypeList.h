#ifndef TYPELIST_H
#define TYPELIST_H

#include <cstddef>

namespace Patterns
{

	///////////////////////////////////////////////////////////////////////////
	// class End
	// An empty class to mark the end of TypeList.
	///////////////////////////////////////////////////////////////////////////
	struct End {};

	///////////////////////////////////////////////////////////////////////////
	// class template TypeList
	// Defines Head and Tail types.
	// See:
	//   Modern C++ Design (Chapter 3. Typelists)
	///////////////////////////////////////////////////////////////////////////
	template <class H, class T>
	struct TypeList
	{
		typedef H Head;
		typedef T Tail;
	};

	///////////////////////////////////////////////////////////////////////////
	// class template Length
	// Get the length of a TypeList.
	///////////////////////////////////////////////////////////////////////////
	template <class List> struct Length;

	template <> struct Length<End>
	{
		enum { Value = 0 };
	};

	template <class Head, class Tail>
	struct Length<TypeList<Head, Tail> >
	{
		enum { Value = 1 + Length<Tail>::Value };
	};

	///////////////////////////////////////////////////////////////////////////
	// class template TypeAt
	// Get the type at the given index in a TypeList.
	///////////////////////////////////////////////////////////////////////////
	template <class List, std::size_t Index> struct TypeAt;

	template <class Head, class Tail>
	struct TypeAt<TypeList<Head, Tail>, 0>
	{
		typedef Head Type;
	};

	template <class Head, class Tail, std::size_t Index>
	struct TypeAt<TypeList<Head, Tail>, Index>
	{
		typedef typename TypeAt<Tail, Index - 1>::Type Type;
	};

}

///////////////////////////////////////////////////////////////////////////////
// macro TYPELISTN
// Use this macro to declare TypeList.
///////////////////////////////////////////////////////////////////////////////
#define TYPELIST1(T1) \
	Patterns::TypeList<T1, Patterns::End>

#define TYPELIST2(T1, T2) \
	Patterns::TypeList<T1, TYPELIST1(T2) >

#define TYPELIST3(T1, T2, T3) \
	Patterns::TypeList<T1, TYPELIST2(T2, T3) >

#define TYPELIST4(T1, T2, T3, T4) \
	Patterns::TypeList<T1, TYPELIST3(T2, T3, T4) >

#define TYPELIST5(T1, T2, T3, T4, T5) \
	Patterns::TypeList<T1, TYPELIST4(T2, T3, T4, T5) >

#define TYPELIST6(T1, T2, T3, T4, T5, T6) \
	Patterns::TypeList<T1, TYPELIST5(T2, T3, T4, T5, T6) >

#define TYPELIST7(T1, T2, T3, T4, T5, T6, T7) \
	Patterns::TypeList<T1, TYPELIST6(T2, T3, T4, T5, T6, T7) >

#define TYPELIST8(T1, T2, T3, T4, T5, T6, T7, T8) \
	Patterns::TypeList<T1, TYPELIST7(T2, T3, T4, T5, T6, T7, T8) >

#define TYPELIST9(T1, T2, T3, T4, T5, T6, T7, T8, T9) \
	Patterns::TypeList<T1, TYPELIST8(T2, T3, T4, T5, T6, T7, T8, T9) >

#define TYPELIST10(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) \
	Patterns::TypeList<T1, TYPELIST9(T2, T3, T4, T5, T6, T7, T8, T9, T10) >

#define TYPELIST11(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11) \
	Patterns::TypeList<T1, TYPELIST10(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11) >

#define TYPELIST12(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12) \
	Patterns::TypeList<T1, TYPELIST11(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12) >

#define TYPELIST13(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13) \
	Patterns::TypeList<T1, TYPELIST12(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13) >

#define TYPELIST14(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14) \
	Patterns::TypeList<T1, TYPELIST13(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14) >

#define TYPELIST15(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15) \
	Patterns::TypeList<T1, TYPELIST14(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15) >

#define TYPELIST16(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16) \
	Patterns::TypeList<T1, TYPELIST15(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16) >

#define TYPELIST17(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16, T17) \
	Patterns::TypeList<T1, TYPELIST16(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16, T17) >

#define TYPELIST18(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16, T17, T18) \
	Patterns::TypeList<T1, TYPELIST17(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16, T17, T18) >

#define TYPELIST19(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16, T17, T18, T19) \
	Patterns::TypeList<T1, TYPELIST18(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16, T17, T18, T19) >

#define TYPELIST20(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16, T17, T18, T19, T20) \
	Patterns::TypeList<T1, TYPELIST19(T2, T3, T4, T5, T6, T7, T8, T9, T10, \
		T11, T12, T13, T14, T15, T16, T17, T18, T19, T20) >

#endif
