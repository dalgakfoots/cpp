#include <iostream>

using namespace std;

namespace MyNamespace {

	namespace InnerNamespace{
		
		int doSomething(int x, int y)
		{
			return x + y;
		}

	}

}


int main()
{
	using namespace MyNamespace::InnerNamespace;

	cout << doSomething(2, 3) << endl;

}