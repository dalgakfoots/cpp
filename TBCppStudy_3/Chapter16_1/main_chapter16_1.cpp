#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void sequence_containers()
{
    // vector
    /*{
        vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
            vec.push_back(i);
        }

        for (auto& e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }*/

    //deque
    /*{
        deque<int> deq;
        for (int i = 0; i < 10; i++)
        {
            deq.push_back(i);
            deq.push_front(i);
        }

        for (auto& e : deq)
        {
            cout << e << " ";
        }
        cout << endl;
    }*/
}

void associative_containers()
{
    //set

    /*{
        set<string> str_set;
        str_set.insert("Hello");
        str_set.insert("world");
        str_set.insert("Hello");

        cout << str_set.size() << endl;

        for (auto& e : str_set)
            cout << e << " ";

        cout << endl;
    }*/

    // multi-set

    /*{
        std::multiset<string> str_set;

        str_set.insert("Hello");
        str_set.insert("world");
        str_set.insert("Hello");

        cout << str_set.size() << endl;

        for (auto& e : str_set)
            cout << e << " ";

        cout << endl;
    }*/

    // map
    /*{
        std::map<char, int> map;
        map['a'] = 10;
        map['b'] = 20;
        map['c'] = 50;

        cout << map['a'] << endl;
        
        map['a'] = 100;

        cout << map['a'] << endl;

        for (auto& e : map)
            cout << e.first << " " << e.second << " ";
        cout << endl;
    }*/

    //multimap
    /*{
        std::multimap<char, int> map;
        map.insert(std::pair<char, int>('a', 10));
        map.insert(std::pair<char, int>('b', 10));
        map.insert(std::pair<char, int>('c', 10));
        map.insert(std::pair<char, int>('d', 100));

        cout << map.count('a') << endl;

        for (auto& e : map)
            cout << e.first << " " << e.second << " ";
        cout << endl;
    }*/
}

void container_adapters()
{
    //{
    //    cout << "Stack" << endl;
    // 
    //    std::stack<int> stack;
    //    stack.push(1); // adds a copy
    //    stack.emplace(2); // constructs a new object
    //    stack.emplace(3);
    //    cout << stack.top() << endl;
    //    stack.pop();
    //    cout << stack.top() << endl;
    //}

    /*{
        cout << "Queue" << endl;

        std::queue<int> queue;
        queue.push(1);
        queue.push(2);
        queue.push(3);

        cout << queue.front() << " " << queue.back() << endl;
        queue.pop();
        cout << queue.front() << " " << queue.back() << endl;
    }*/

    /*{
        cout << "Priority queue" << endl;

        std::priority_queue<int> queue;

        for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
            queue.push(n);

        for (int i = 0; i < 10; i++)
        {
            cout << queue.top() << endl;
            queue.pop();
        }
    }*/
}

int main()
{
    sequence_containers();
    associative_containers();
    container_adapters();
    return 0;
}