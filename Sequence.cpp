#include "Sequence.h"
#include <iostream>

Sequence::Iterator::Iterator(Position* p, const Sequence* s) : pos(p), data(s) { }

template<class T>
void swap(T& t1, T& t2)
{
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

Elem& Sequence::Iterator::operator*()
{
	return pos->elem;
}

bool Sequence::Iterator::operator==(const Iterator& it) const
{
	return pos == it.pos;
}

bool Sequence::Iterator::operator!=(const Iterator& it) const
{
	return pos != it.pos;
}

Sequence::Iterator& Sequence::Iterator::operator++()
{
	pos = data->elements[(pos->index + 1)];
	return *this;
}

Sequence::Iterator& Sequence::Iterator::operator--()
{
	pos = data->elements[(pos->index - 1)];
	return *this;
}

Sequence::Sequence() : n(0), capacity(10)
{
	elements = new Position*[capacity];
	elements[0] = new Position;
	elements[0]->index = 0;
}

Sequence::Sequence(const Sequence& s) 
{
	n = s.n;
	capacity = s.capacity;
	elements = new Position*[capacity];
	for (int i = 0; i < n + 1; i++)
		elements[i] = new Position(s.elements[i]->elem, s.elements[i]->index);
	
}

Sequence::~Sequence()
{
	for (int i = 0; i <= n; i++)
		delete elements[i];

	delete [] elements;
}

Sequence& Sequence::operator=(const Sequence& s) 
{
	Sequence temp(s);
	swap(temp.n, n);
	swap(temp.capacity, capacity);
	swap(temp.elements, elements);
	return *this;
}

int Sequence::size() const { return n; }

bool Sequence::empty() const { return n == 0; }

Sequence::Iterator Sequence::begin() const
{
	return Iterator(elements[0], this);
}

Sequence::Iterator Sequence::end() const
{
	return Iterator(elements[n], this);
}

void Sequence::insertFront(const Elem& e) 
{
	insert(begin(), e);
}
void Sequence::insertBack(const Elem& e) 
{
	insert(end(), e);
}
void Sequence::insert(const Iterator& p, const Elem& e)// insert e before p
{
	int temp_pos = p.pos->index;
	for (int i = n + 1; i > temp_pos; --i)
	{
		elements[i] = elements[i - 1];
		elements[i]->index++;
	}

	elements[temp_pos] = new Position;
	elements[temp_pos]->elem = e;
	elements[temp_pos]->index = temp_pos;
	n++;
}

void Sequence::eraseFront() 
{
	erase(begin());
}
void Sequence::eraseBack() 
{
	erase(--end());
}
void Sequence::erase(const Iterator& p)
{
	for (int i = p.pos->index; i <= n; i++)
	{
		elements[i] = elements[i + 1];
		elements[i]->index--;
	}
	n--;
}

int Sequence::indexOf(const Iterator& it) 
{
	return it.pos->index;
}

Sequence::Iterator Sequence::atIndex(int i) 
{
	return Iterator(elements[i], this);
}

void Sequence::print()
{
	std::cout << "| ";
	for (int i = 0; i < n; ++i)
		std::cout << elements[i]->index << " | ";
	
	std::cout << "\n| ";

	for (int i = 0; i < n; ++i)
		std::cout << elements[i]->elem << " | ";

	std::cout << "\n\n";

}