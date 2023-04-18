#include <iostream>
#include <string>
#include <iomanip> // i/o manipulators
 

using namespace std;

int main()
{

    /*int i;
    float f;

    cin >> i >> f;

    cout << i << " " << f << endl;*/

    //char buf[10];
    //cin >> setw(5) >> buf; // istream 이 버퍼를 가지고 있음. -> 입력받은 5개만 가져온다.
    //// 나머지는 버퍼에 남아있다.
    //cout << buf << endl;

    /*char buf[5];
    cin.get(buf, 5);
    cout << cin.gcount() << " " << buf << endl;*/

    /*string buf;
    
    getline(cin, buf);
    cout << cin.gcount() << " " << buf << endl;

    return 0;*/

    char buf[1024];
    
    /*cout << (char)cin.peek() << endl;

    cin.ignore(2);
    */
    cin >> buf;
    cout << buf << endl;

    cin.unget(); // 마지막 글자를 버퍼에 남겨둠

    cin >> buf;
    cout << buf << endl;


}