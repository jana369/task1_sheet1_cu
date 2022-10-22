#include <iostream>
#include <string>
using namespace std;

class BigDecimalInt {
private:
    char sign = '+';
    string value="";
    int decimal_value = 0 ;
public:
    string get_value();
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    bool operator < (BigDecimalInt anotherDec);
    bool operator == (BigDecimalInt anotherDec);
    BigDecimalInt operator = (BigDecimalInt anotherDec);
    int size();
    char Sign();
    void set_value(string res);
    
};
ostream& operator<<(ostream& out, BigDecimalInt& b);