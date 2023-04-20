#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric> // std::inner_product
#include <execution> // parallel executuion

using namespace std;

mutex mtx;

void doProductNaive(const vector<int>& v0, const vector<int>& v1,
    const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
    for (unsigned i = i_start; i < i_end; i++)
    {
        sum += v0[i] * v1[i];
    }
}

void doProductLock(const vector<int>& v0, const vector<int>& v1,
    const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
    for (unsigned i = i_start; i < i_end; i++)
    {
        // scoped_lock (lock_guard) 는 작은 영역에 둘 수록 좋다
        std::lock_guard<mutex> lock(mtx);
        sum += v0[i] * v1[i];
    }
}

void doProductAtomic(const vector<int>& v0, const vector<int>& v1,
    const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum)
{
    for (unsigned i = i_start; i < i_end; i++)
    {
        sum += v0[i] * v1[i];
    }
}

int doProductFuture(const vector<int>& v0, const vector<int>& v1,
    const unsigned i_start, const unsigned i_end)
{
    int sum = 0;
    for (unsigned i = i_start; i < i_end; i++)
    {
        sum += v0[i] * v1[i];
    }
    return sum;
}

int main()
{
    /*
    v0 = {1,2,3}
    v1 = {4,5,6}

    v0_dot_v1 = 1*4 + 2*5 + 3*6
    
    */

    const long long n_data = 100'000'00;
    const unsigned n_threads = 4;

    std::vector<int> v0, v1;
    v0.reserve(n_data);
    v1.reserve(n_data);

    random_device seed;
    mt19937 engine(seed());

    uniform_int_distribution<> uniformDist(1, 10);

    for (long long i = 0; i < n_data; i++)
    {
        v0.push_back(uniformDist(engine));
        v1.push_back(uniformDist(engine));
    }

    cout << "std::inner_product" << endl;
    {
        const auto sta = chrono::steady_clock::now();
        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull); // 0ull => unsigned long long 0

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }


    cout << "Naive" << endl;
    {
        const auto sta = chrono::steady_clock::now();
        unsigned long long sum = 0;

        vector<thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads;

        for (unsigned t = 0; t < n_threads; t++)
        {
            threads[t] = std::thread(doProductNaive, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        }

        for (unsigned t = 0; t < n_threads; t++)
        {
            threads[t].join();
        }

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Lockguard" << endl;
    {
        const auto sta = chrono::steady_clock::now();

        unsigned long long sum = 0;

        vector<thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads;

        for (unsigned t = 0; t < n_threads; t++)
        {
            threads[t] = std::thread(doProductLock, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        }

        for (unsigned t = 0; t < n_threads; t++)
        {
            threads[t].join();
        }

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Atomic" << endl;
    {
        const auto sta = chrono::steady_clock::now();

        atomic<unsigned long long> sum = 0;

        vector<thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads;

        for (unsigned t = 0; t < n_threads; t++)
        {
            threads[t] = std::thread(doProductAtomic, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        }

        for (unsigned t = 0; t < n_threads; t++)
        {
            threads[t].join();
        }

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Future" << endl;
    {
        const auto sta = chrono::steady_clock::now();

        unsigned long long sum = 0;

        vector<std::future<int>> futures;
        futures.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads;

        for (unsigned t = 0; t < n_threads; t++)
        {
            futures[t] = std::async(doProductFuture, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread);
        }

        for (unsigned t = 0; t < n_threads; t++)
        {
            sum += futures[t].get();
        }

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }
}