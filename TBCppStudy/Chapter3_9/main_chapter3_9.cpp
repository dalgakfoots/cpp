#include <iostream>
#include <bitset>
using namespace std;


void color()
{
    const unsigned int red_mask = 0xFF0000;
    const unsigned int green_mask = 0x00FF00;
    const unsigned int blue_mask = 0x0000FF;

    cout << std::bitset<32>(red_mask) << endl;
    cout << std::bitset<32>(green_mask) << endl;
    cout << std::bitset<32>(blue_mask) << endl;


    unsigned int pixel_color = 0xDAA520;
    cout << std::bitset<32>(pixel_color) << endl;
    //
    
    unsigned char red, green, blue;

    blue = pixel_color & blue_mask;
    cout << "blue : " << std::bitset<8>(blue) << " " << int(blue) << endl;

    green = (pixel_color & green_mask) >> 8;
    cout << "green : " << std::bitset<8>(green) << " " << int(green) << endl;

    red = (pixel_color & red_mask) >> 16;
    cout << "red : " << std::bitset<8>(red) << " " << int(red) << endl;

}

int main()
{

    //const unsigned char opt0 = 1 << 0;
    //const unsigned char opt1 = 1 << 1;
    //const unsigned char opt2 = 1 << 2;
    //const unsigned char opt3 = 1 << 3;

    //cout << std::bitset<8>(opt0) << endl;
    //cout << std::bitset<8>(opt1) << endl;
    //cout << std::bitset<8>(opt2) << endl;
    //cout << std::bitset<8>(opt3) << endl;

    ///*bool item1_flag = false;
    //bool item2_flag = false;
    //bool item3_flag = false;
    //bool item4_flag = false;
    //...
    //*/
    //
    //unsigned char items_flag = 0;
    //cout << "No item " << std::bitset<8>(items_flag) << endl;

    //// item0 on
    //items_flag |= opt0;
    //cout << "item0 Obtained " << std::bitset<8>(items_flag) << endl;

    //// item3 on
    //items_flag |= opt3;
    //cout << "item3 Obtained " << std::bitset<8>(items_flag) << endl;

    //// item3 lost
    //items_flag &= ~opt3;
    //cout << "item3 lost " << std::bitset<8>(items_flag) << endl;

    //// has item1 ?
    //if (items_flag & opt1)
    //{
    //    cout << "Has item 1" << endl;
    //}
    //else {
    //    cout << "Not have item 1" << endl;
    //}

    //// has item0 ?
    //if (items_flag & opt0)
    //{
    //    cout << "Has item 0" << endl;
    //}

    //// obtain item 2, 3
    //items_flag |= (opt2 | opt3);
    //cout << "item2, 3 obtained " << std::bitset<8>(items_flag) << endl;

    //if ((items_flag & opt2) && !(items_flag & opt1))
    //{
    //    items_flag ^= opt2;
    //    items_flag ^= opt1;
    //}

    //cout  << std::bitset<8>(items_flag) << endl;

    color();

    return 0;
}