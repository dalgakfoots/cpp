#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx; // mutual exclusion ��ȣ����

int main()
{
    const int num_pro = thread::hardware_concurrency();

    //cout << std::thread::hardware_concurrency() << endl; // �ھ� ����
    //cout << std::this_thread::get_id() << endl; // ���� �Լ��� ����ǰ� �ִ� �������� id

    /*cout << std::this_thread::get_id() << endl;

    vector<std::thread> my_threads;
    my_threads.resize(num_pro);

    for (auto& e : my_threads)
    {
        e = std::thread
        ([]()
            {
                cout << std::this_thread::get_id() << endl;
                while (true) {}
            }
        );
    }

    for (auto& e : my_threads)
        e.join();*/

    auto work_func = [](const string& name)
    {
        for (int i = 0; i < 5; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            mtx.lock();
            cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
            mtx.unlock();
        }
    };
    
    thread t1 = std::thread(work_func, "JackJack");
    thread t2 = std::thread(work_func, "Dash");

    t1.join();
    t2.join();

    return 0;
}