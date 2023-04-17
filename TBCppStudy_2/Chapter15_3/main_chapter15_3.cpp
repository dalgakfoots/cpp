#include "AutoPtr.h"
#include "Resource.h"

AutoPtr<Resource> generateResources()
{
    AutoPtr<Resource> res(new Resource(1000000));
    return res;
}

int main()
{
    using namespace std;

    {
        AutoPtr<Resource> main_res;
        main_res = generateResources();
    }

    return 0;
}