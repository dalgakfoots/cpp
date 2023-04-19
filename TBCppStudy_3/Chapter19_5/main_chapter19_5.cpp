#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

int main()
{
    // multi-threading
    {
        int result;
        std::thread t([&] {result = 1 + 2; });
        t.join(); // �����尡 ���� �� ����, ��ٸ���
        cout << result << endl;
    }

    // task-based parallelism
    {
        // �Ϲ����� ���ϰ� �ٸ���. �ٷ� ���� �� �� ������ �������� �ʴ´�.
        auto fut = std::async([] {return 1 + 2; }); 
        cout << fut.get() << endl; // �۾��� ���� �� ����, get() �� ��ٸ���.
    }

    // future and promise
    {
        std::promise<int> prom;
        // ������� ������ �ڽ��� �����ϱ� ������... future �� ���� ����
        auto fut = prom.get_future(); // 2

        auto t = std::thread([](std::promise<int>&& prom) {
            prom.set_value(1 + 2); // 1
        } , std::move(prom));

        cout << fut.get() << endl; // 3
        t.join();
    }

    {
        // future ���� ������ ����� sequential �ϰ� ����ȴ�

        /*std::async([] {
            cout << " async1 start " << endl;
            this_thread::sleep_for(chrono::milliseconds(2));
            cout << " async1 end " << endl;
            });*/

        auto f1 = std::async([] {
            cout << " async1 start " << endl;
            this_thread::sleep_for(chrono::milliseconds(2));
            cout << " async1 end " << endl;
            });

        auto f2 = std::async([] {
            cout << " async2 start " << endl;
            this_thread::sleep_for(chrono::milliseconds(1));
            cout << " async2 end " << endl;
            });

        std::cout << "Main function" << endl;
        
    }
    return 0;
}