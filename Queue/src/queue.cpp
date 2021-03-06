//============================================================================
// Name        : queue.cpp
// Author      : Luca Pierobon
//============================================================================

#include <iostream>
#include "queue.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
	Queue<int> pi;
	for(int i=0; i<10; ++i)
		pi.add(i);
	Queue<int> pi2(pi);
	for(int i=0; i<10; ++i)
		cout<<pi.remove()<<" ";
	cout<<endl;
	for(int i=0; i<10; ++i)
		cout<<pi2.remove()<<" ";

	return 0;
}
