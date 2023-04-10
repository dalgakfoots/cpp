#include <iostream>
//#include <cstdint> iostream 에서 include 하고 있어 iostream 사용 시, 별도로 선언할 필요 없음

int main()
{
    using namespace std;

    std::int16_t i(5);
    std::int8_t myint = 65;

    cout << myint << endl;

    std::int_fast8_t fi(5); // 8비트 사이즈 중에 가장 빠른 데이터 타입
    std::int_least64_t fl(5); // 적어도 64비트를 갖는 데이터 타입
    return 0;
}