#include <iostream>
#include "Resource.h"

int main()
{
    {
        /*Resource* res = new Resource(3);
        res->setAll(1);*/



        //std::shared_ptr<Resource> ptr1(res);

        auto ptr1 = std::make_shared<Resource>(3);

        ptr1->print();

        {
            //std::shared_ptr<Resource> ptr2(ptr1);
            auto ptr2 = ptr1; // 소유권을 여러개 가질 수 있다.

            ptr2->setAll(3);
            ptr2->print();

            std::cout << "going out of the block" << std::endl;
        }

        ptr1->print();

        std::cout << "going out of the outer block" << std::endl;
    }

    return 0;
}