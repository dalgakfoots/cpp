#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit()
#include <sstream>

using namespace std;

int main()
{
    const string filename = "my_file.txt";

    //make a file
    if(false)
    {
        ofstream ofs(filename);

        for (char i = 'a'; i <= 'z'; i++)
        {
            ofs << i;
        }
        ofs << endl;
    }

    // read the file
    if(false)
    {
        ifstream ifs(filename);

        ifs.seekg(5); // 5����Ʈ �̵��� ������ �о�鿩��
        cout << (char)ifs.get() << endl;

        ifs.seekg(5, ios::cur); // �� Ŀ����ġ���� 5����Ʈ �̵��� ������ �о�鿩��
        cout << (char)ifs.get() << endl;

        /*ifs.seekg(0, ios::end);
        cout << ifs.tellg() << endl;*/

        string str;
        getline(ifs, str);
        cout << str << endl;
    }

    {
        fstream iofs(filename);

        iofs.seekg(5);
        cout << (char)iofs.get() << endl; // read

        iofs.seekg(5);
        iofs.put('A'); // write
    }
}