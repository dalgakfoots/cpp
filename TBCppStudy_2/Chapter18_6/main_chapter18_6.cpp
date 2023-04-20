#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
    if (false)
    {
        ofstream ofs("my_first_file.dat");
        //ofs.open("my_first_file.dat");

        if (!ofs)
        {
            cerr << "Couldn't open file" << endl;
            exit(1);
        }

        ofs << "Line 1" << endl;
        ofs << "Line 2" << endl;


    } // ������ ����� ofs �� �ڵ����� �Ҹ�ȴ�

    if (true)
    {
        ofstream ofs("my_first_file.dat");

        if (!ofs)
        {
            cerr << "Couldn't open file" << endl;
            exit(1);
        }

        const unsigned num_data = 10; // �� ������ ����

        ofs.write((char*)&num_data, sizeof(num_data));

        for (int i = 0; i < num_data; i++)
        {
            ofs.write((char*)&i, sizeof(i));
        }
        
    }

    if (false)
    {
        ifstream ifs("my_first_file.dat");

        if (!ifs)
        {
            cerr << "cannot open file" << endl;
            exit(1);
        }

        while (ifs)
        {
            std::string str;
            getline(ifs, str);

            std::cout << str << endl;
        }
    }

    if (true)
    {
        ifstream ifs("my_first_file.dat");

        if (!ifs)
        {
            cerr << "cannot open file" << endl;
            exit(1);
        }

        unsigned num_data = 0;
        ifs.read((char*)&num_data, sizeof(num_data));
        
        for (unsigned i = 0; i < num_data; i++)
        {
            int num;
            ifs.read((char*)&num ,sizeof(num));

            cout << num << endl;
        }
    }
}