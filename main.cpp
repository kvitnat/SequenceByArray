#include <iostream>
#include "Array.h"
#include "PuzzleSolve.h"
#include "LinkedStack.h"
#include "Queue.h"
#include "Deque.h"

#include "LinkedDeque.h"
#include "LinkedQueue.h"

#include "ArrayStack.h"
#include "DequeTwoStacks.h"

#include "VectorCircArr.h"
#include "StackAdapter.h"
#include "Sequence.h"
#include <vector>
#include <iostream>

int main()
{
	srand(4);
	Sequence seq;
	for (int i = 5; i < 10; ++i)
		seq.insertBack(i);

	seq.print();

	Sequence::Iterator it1 = seq.begin();
	++it1;
	++it1;
	++it1;
	++it1; //should point to 9

	std::cout << "*it1 = " << *it1 << "\n";
	

	Sequence::Iterator it2 = seq.begin();
	++it2;
	++it2;
	std::cout << "*it2 = " << *it2 << "\n";
	std::cout << "insert 1 at it2\n";
	seq.insert(it2, 1);
	std::cout << "*it2 = " << *it2 << "\n";
	seq.print();

	std::cout << "*it1 = " << *it1 << "\n";

	Sequence seq2(seq);
	std::cout << "\nseq2 is a copy of seq.\n";
	std::cout << "\nseq2 insertFront 88.\n";
	seq2.insertFront(88);

	seq.print();
	seq2.print();
	std::cout << "\nseq = seq2;\n";
	seq = seq2;

	seq.print();
	seq2.print();

	return 0;
}