#pragma once
typedef int Elem;


class Sequence
{
private:
	struct Position
	{
		Elem elem;
		int index;
		Position() {}
		Position(Elem e, int i) : elem(e), index(i) {}
	};
public:
	class Iterator
	{
	public:
		Elem& operator*();
		bool operator==(const Iterator& it) const;
		bool operator!=(const Iterator& it) const;
		Iterator& operator++();
		Iterator& operator--();

		friend class Sequence;
	private:
		Position* pos;
		const Sequence* data;
		Iterator(Position* p, const Sequence* s);
	};
public:
	Sequence();
	Sequence(const Sequence& s);
	~Sequence();
	Sequence& operator=(const Sequence& s);

	int size() const;
	bool empty() const;
	Iterator begin() const;
	Iterator end() const;
	void insertFront(const Elem& e);
	void insertBack(const Elem& e);
	void insert(const Iterator& p, const Elem& e); // insert e before p
	void eraseFront();
	void eraseBack();
	void erase(const Iterator& p);

	int indexOf(const Iterator& it);
	Iterator atIndex(int i);

	void print();

private:
	Position** elements;
	int n;
	int capacity;
};

