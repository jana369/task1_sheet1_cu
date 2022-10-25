#include "header.h"
#include <regex>

BigDecimalInt::BigDecimalInt(string decStr)
{

    regex entry_pattern("[+-]?[0-9][0-9]*");
    if (regex_match(decStr, entry_pattern))
    {
        if (decStr[0] == '+' || decStr[0] == '-') {
            sign = decStr[0];
            decStr.erase(0, 1);
        }
        else {
            sign = '+';
        }
        int i = 0;
        while (decStr[i] == '0' && decStr[i] != '\0') {
            i++;
        }
        if (decStr[i] == '\0')
        {
            value = "0";
        }
        else
        {
            if (i != 0)
                decStr.erase(0, i);
            value = decStr;
            cout << value << endl;
        }
    }
    else
    {
        cout << "Invalid Entry";
    }
}

BigDecimalInt::BigDecimalInt(int decInt)
{
    if (decInt < 0)
    {
        sign = '-';
        decInt * -1;
    }
    else if (decInt >= 0)
    {
        sign = '+';
    }
    value = to_string(decInt);
    cout << value << endl;
}
BigDecimalInt BigDecimalInt :: operator+(BigDecimalInt anotherDec)
{
    string res = "0";
    BigDecimalInt result_obj(res);
    if (sign == anotherDec.sign)
    {
        result_obj.sign = sign;
        if (value.length() >= anotherDec.value.length())
        {
            int carry = 0;
            res = value;
            for (int i = value.length() - 1, j = anotherDec.value.length() - 1; j >= 0; i--, j--)
            {
                int tmp_res = (value[i] - '0') + (anotherDec.value[j] - '0') + carry;
                carry = (tmp_res / 10) % 10;
                res[i] = (tmp_res % 10) + '0';
            }
            for (int i = value.length() - anotherDec.value.length() - 1; i >= 0; i--)
            {
                int tmp_res = ((res[i] - '0') + carry);
                res[i] = ((res[i] - '0') + carry) % 10 + '0';
                carry = (tmp_res / 10) % 10;
            }
            if (carry != 0)
            {
                res.insert(0, 1, carry + '0');
            }
        }
        else
        {
            int carry = 0;
            res = anotherDec.value;
            for (int i = anotherDec.value.length() - 1, j = value.length() - 1; j >= 0; i--, j--)
            {
                int tmp_res = (value[j] - '0') + (anotherDec.value[i] - '0') + carry;
                carry = (tmp_res / 10) % 10;
                res[i] = (tmp_res % 10) + '0';
            }
            for (int i = anotherDec.value.length() - value.length() - 1; i >= 0; i--)
            {
                int tmp_res = ((res[i] - '0') + carry);
                res[i] = ((res[i] - '0') + carry) % 10 + '0';
                carry = (tmp_res / 10) % 10;
            }
            if (carry != 0)
            {
                res.insert(0, 1, carry + '0');
            }
        }
    }
    else
    {
        // mohammed omar implementation for the subtraction operator
    }
    result_obj.value = res;
    //cout << res;
    return result_obj;
}
// a boolean function that checks if this object is less than anotherDec or not #jana
bool BigDecimalInt::operator>(BigDecimalInt anotherDec)
{
    if (anotherDec.sign == sign) {
        int anotherDec_length = anotherDec.value.length();
        int this_length = value.length();

        if (this_length == anotherDec_length) {
            for (int i = 0; i < anotherDec_length; i++) {
                if (value[i] != anotherDec.value[i]) {
                    if (value[i] > anotherDec.value[i]) {
                        if (sign == '+')
                            return true;
                        else return false;
                    }
                    else {
                        if (sign == '-')
                            return true;
                        else return false;
                    }
                }
            }
                return false;

            }
            else if (sign == '+') {
            if (this_length > anotherDec_length) { return true; }
            else 
            { return false;
            }
             }
            else {
            if (this_length < anotherDec_length)return true;
            else return false;
            }
        }
        else {
            if (anotherDec.sign == '+')
                return true;
            else return false;
        }
    }

// a boolean function that checks if this object is equal to anotherDec or not #jana
bool BigDecimalInt::operator==(BigDecimalInt anotherDec)
{
    int i = value.length();
    int j = anotherDec.value.length();
    if (i == j) {
        for (int k = 0; k < value.length(); k++) {
            if(value[0]== anotherDec.value[0])
            return true;
        }
    }
    else {
        return false;
    }
}


// an assign operator (operator overloading) with anotherDec #jana
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec)
{
    value.assign(anotherDec.value);
    //value = anotherDec.value;
    return value;
}


//a function that returns the length of the object #jana
int BigDecimalInt::size()
{
    int i = value.length();

    return i;
}


// a function that returns the sign of an object #jana
char BigDecimalInt::Sign()
{
    sign = value[0];
    if (value[0] != '+' || value[0] != '-') {
        sign = '+';
    }
    return sign;
}


//an operator function the prints out the value #jana
ostream& operator<<(ostream& out, BigDecimalInt& b) {

    out <<"the number is "<< b.get_value() << endl;
    return out;
}

void BigDecimalInt::set_value(string res)
{
    value = res;
}

string BigDecimalInt::get_value()
{
    return value;
}
