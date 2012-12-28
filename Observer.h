//        __            __      __
//       / /  ___      / /_  __/ /  ____
//      / /  / _ |_   / / / / / /  / __/     patterns
//     / /__/ __ | \_/ / /_/ / /__/ -__      2012, Julien Rouzieres
//    /____/_/ |_|\___/|____/____/____/      https://github.com/Lajule/patterns
//
#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>
#include <algorithm>
#include <functional>

namespace Patterns
{

	// forward declaration
	class Subject;

	///////////////////////////////////////////////////////////////////////////
	// class Observer
	// Observer pattern.
	// See:
	//   Design Patterns (Chapter 5. Behavioral Patterns)
	///////////////////////////////////////////////////////////////////////////
	class Observer
	{
	public:
		virtual ~Observer() {}
		virtual void Update(Subject&) = 0;
	};

	namespace Private
	{
		// helper for Subject::Notify method
		struct Update : public std::unary_function<Observer*, void>
		{
			Subject& _subject;

			Update(Subject& subject) : _subject(subject) {}

			void operator()(Observer* observer)
			{ observer->Update(_subject); }
		};
	}

	///////////////////////////////////////////////////////////////////////////
	// class Subject
	// The subject of Observer classes.
	// See:
	//   Design Patterns (Chapter 5. Behavioral Patterns)
	///////////////////////////////////////////////////////////////////////////
	class Subject
	{
	public:
		virtual ~Subject()
		{ _list.clear(); }

		void Attach(Observer& observer)
		{ _list.push_back(&observer); }

		void Detach(Observer& observer)
		{ _list.remove(&observer); }

		void Notify()
		{ std::for_each(_list.begin(), _list.end(), Private::Update(*this)); }

	protected:
		typedef std::list<Observer*> ObserverList;
		ObserverList _list;
	};

}

#endif
