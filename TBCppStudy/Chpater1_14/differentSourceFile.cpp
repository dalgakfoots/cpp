#include <iostream>


void doSomething()
{
	using namespace std;
#ifdef LIKE_APPLE
	cout << "APPLE" << endl;
#endif // LIKE_APPLE

#ifndef LIKE_APPLE
	cout << "ORANGE" << endl;

#endif
}