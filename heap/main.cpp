#include <vector>
#include <iostream>
#include "heap.h"


int main()
{
	Heap h;
	h.push(2);
	h.push(1);
	h.push(10);
	h.push(5);
	h.push(8);
	h.push(3);
	h.print();
	h.extract();
	h.print();
	h.extract();
	h.print();
	h.extract();
	h.print();
	h.extract();
	h.print();
	h.extract();
	h.print();
	h.extract();
	h.print();

	return 0;
}
