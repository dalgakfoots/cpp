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
    //cin >> setw(5) >> buf; // istream �� ���۸� ������ ����. -> �Է¹��� 5���� �����´�.
    //// �������� ���ۿ� �����ִ�.
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

    cin.unget(); // ������ ���ڸ� ���ۿ� ���ܵ�

    cin >> buf;
    cout << buf << endl;


}