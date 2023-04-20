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
        t.join(); // 스레드가 끝날 때 까지, 기다린다
        cout << result << endl;
    }

    // task-based parallelism
    {
        // 일반적인 리턴과 다르다. 바로 리턴 될 수 있음을 보장하지 않는다.
        auto fut = std::async([] {return 1 + 2; }); 
        cout << fut.get() << endl; // 작업이 끝날 때 까지, get() 이 기다린다.
    }

    // future and promise
    {
        std::promise<int> prom;
        // 스레드는 스레드 자신을 리턴하기 때문에... future 를 주지 않음
        auto fut = prom.get_future(); // 2

        auto t = std::thread([](std::promise<int>&& prom) {
            prom.set_value(1 + 2); // 1
        } , std::move(prom));

        cout << fut.get() << endl; // 3
        t.join();
    }

    {
        // future 와의 연결이 끊기면 sequential 하게 실행된다

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