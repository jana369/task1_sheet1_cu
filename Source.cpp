#include "header.h"

int main()
{
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+1111111111111111110000000000000000000000011111111111");
    BigDecimalInt num3("-200000000000000000000000000000");
    
    BigDecimalInt num4 = num2 + num1;
    cout << "num2 + num1 = " << num4 << endl;

    //BigDecimalInt num5 = num2 - num1;
    //cout << "num2 - num1 = " << num5 << endl;

}
//operator<<(cout, num4); => to print num4
    
    //cout<<num4.size()<<endl;

    //cout<<num4.Sign()<<endl;