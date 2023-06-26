#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std ;
class BigInt
{
public:
    bool check2 = 0 ;
    char sign = '+' ;
    int sum,carry ;
    string number ;
    int Size()
    {
        return number.length() ;
    }
    BigInt (string decStr)
    {
        number = decStr ;
    }
    BigInt (int decInt)
    {
        if( decInt < 0 )
        {
            decInt *= -1 ;
            while ( decInt > 0 )
            {
                number += ( decInt % 10 ) + '0' ;
                decInt -= ( decInt % 10 )  ;
                decInt /= 10 ;
            }
            number += '-' ;
        }
        else if ( decInt > 0 )
        {
            while ( decInt > 0 )
            {
                number += ( decInt % 10 ) + '0' ;
                decInt -= ( decInt % 10 )  ;
                decInt /= 10 ;
            }
        }
        else if ( decInt == 0 )
        {
            number = "0" ;
        }
        reverse( number.begin() , number.end() ) ;
    }
    BigInt()
    {
        number = "" ;
    }
    bool checkBigger( string number1 , string number2)
    {
        if( number1.length() == number2.length() )
        {
            for(int i=0;i<number1.length();i++)
            {
                if( number1[i] > number2[i] )
                {
                    return 1 ;
                }
                else
                {
                    return 0 ;
                }
            }
        }
    }
    bool checkIfEqual( string number1 , string number2)
    {
        if( number1.length() == number2.length() )
        {
            for(int i=0;i<number1.length();i++)
            {
                if( number1[i] == number2[i] )
                {
                    continue ;
                }
                else
                {
                    return 0 ;
                }
            }
            return 1 ;
        }
    }
    bool checkSign( BigInt &NUMBER )
    {
        string holder = "" ;
        if( NUMBER.number[0] == '-' )
        {
            for(int i=1;i<NUMBER.number.length();i++)
            {
                holder += NUMBER.number[i] ;
            }
            NUMBER.number = holder ;
            return 1 ;
        }
        else if ( NUMBER.number[0] == '+' )
        {
            for(int i=1;i<NUMBER.number.length();i++)
            {
                holder += NUMBER.number[i] ;
            }
            NUMBER.number = holder ;
            return 0 ;
        }
        else
        {
            return 0 ;
        }
    }
    bool checkValidation ( BigInt &NUMBER )
    {

        for(int j=1;j<NUMBER.number.length();j++)
        {
            if( NUMBER.number[0] != '+' && NUMBER.number[0] != '-' && NUMBER.number[0] > '9' && NUMBER.number[0] < '0' )
            {
            return 0 ;
            }
            if( NUMBER.number[j] > '9' && NUMBER.number[j] < '0' )
            {
                return 0 ;
            }
        }
        return 1 ;
    }
    void removeRemainingZeros( string &num )
    {
        if ( num[0] == '-' || num[0] == '+' )
        {
            int x = 0 ;
            for(int c=x+1;c<num.length();c++)
            {
                if( number[c] == '0' )
                {
                    x++ ;
                }
                else
                {
                    break ;
                }
            }
            num.erase(1,x) ;
        }
        if ( num[0] == '0' )
        {
            int x = 0 ;
            for(int c=x;c<num.length();c++)
            {
                if( number[c] == '0' )
                {
                    x++ ;
                }
                else
                {
                    break ;
                }
            }
            num.erase(0,x) ;
        }
    }
    BigInt operator+ ( BigInt &anotherDec )
    {
       if( ( number[0] == '+' || ( number[0] >= '0' && number[0] <= '9' ) ) && anotherDec.number[0] == '-'  )
       {
           checkSign( anotherDec ) ;
           return *this - anotherDec ;
       }
       if( number[0] == '-' && ( anotherDec.number[0] == '+' || (anotherDec.number[0] >= '0' && anotherDec.number[0] <= '9' ) ) )
       {
           checkSign( *this ) ;
           return anotherDec - *this ;
       }
            if ( number.length() > anotherDec.number.length() )
            {
                int difference = number.length() - anotherDec.number.length() ;
                bool check = checkSign(*this) && checkSign(anotherDec) ;
                BigInt result ;
                result.number = "";
                result.carry = 0;
                for ( int i=( anotherDec.number.length()-1 ); i>=0; i-- )
                {
                    result.sum = 0;
                    result.sum = ( anotherDec.number[i] - '0' )+( number[i+difference] - '0' )+result.carry;
                    result.carry=0;
                    if ( result.sum>9 )
                    {
                        result.sum -= 10 ;
                        result.carry++ ;
                    }
                result.number += result.sum +'0';
                }
                for (int i = difference-1; i>=0; i--)
                {
                    result.sum=0;
                    result.sum += number[i] + ( result.carry - '0' );
                    result.carry=0;
                    if ( result.sum > 9 )
                    {
                        result.sum-=10;
                        result.carry++;
                    }
                result.number += result.sum + '0';
                }
                if (result.carry>0)
                {
                    result.number += result.carry + '0';
                }
                if( check || sign == '-' )
                {
                    result.number += '-' ;
                }
                reverse( result.number.begin(),result.number.end() ) ;
                return result ;
            }
            if ( anotherDec.number.length() > number.length())
            {
                int difference = anotherDec.number.length()- number.length();
                bool check = checkSign(*this) && checkSign(anotherDec) ;
                BigInt result;
                result.number = "";
                result.carry = 0;
                for ( int i=(number.length()-1); i>=0; i-- )
                {
                    result.sum = 0;
                    result.sum = ( number[i] - '0' )+( anotherDec.number[i+difference] - '0' ) + result.carry;
                    result.carry=0;
                    if ( result.sum>9 )
                    {
                        result.sum -= 10 ;
                        result.carry++ ;
                    }
                result.number += result.sum + '0';
                }
                for (int i = difference-1; i>=0; i--)
                {
                    result.sum=0;
                    result.sum += anotherDec.number[i] + ( result.carry - '0' );
                    result.carry=0;
                    if ( result.sum > 9 )
                    {
                        result.sum-=10;
                        result.carry++;
                    }
                result.number += result.sum + '0';
                }
                if (result.carry>0)
                {
                    result.number += result.carry + '0';
                }
                if( check || sign == '-' )
                {
                    result.number += '-' ;
                }
                reverse( result.number.begin(),result.number.end() ) ;
                return result ;
            }
            if ( number.length() == anotherDec.number.length() )
            {
                bool check = checkSign(*this) && checkSign(anotherDec) ;
                BigInt result;
                result.number = "";
                result.carry = 0;
                for ( int i=( anotherDec.number.length()-1 ); i>=0; i-- )
                {
                    result.sum = 0;
                    result.sum = ( anotherDec.number[i] - '0' )+( number[i] - '0' )+result.carry;
                    result.carry=0;
                    if ( result.sum>9 )
                    {
                        result.sum -= 10 ;
                        result.carry++ ;
                    }
                result.number += result.sum + '0';
                }
                if (result.carry>0)
                {
                    result.number += result.carry + '0';
                }
                if( check || sign == '-'  )
                {
                    result.number += '-' ;
                }
                reverse( result.number.begin(),result.number.end() ) ;

                return result ;
            }


    }
    BigInt operator- (BigInt &anotherDec)
    {
        if( ( number[0] == '+' || ( number[0] >= '0' && number[0] <= '9' ) ) && anotherDec.number[0] == '-'  )
        {
            checkSign( anotherDec ) ;
            return *this + anotherDec ;
        }
        if( number[0] == '-' && ( anotherDec.number[0] == '+' || (anotherDec.number[0] >= '0' && anotherDec.number[0] <= '9' ) ) )
        {
            sign = '-' ;
            checkSign( *this ) ;
            return *this + anotherDec ;
        }
        if ( number[0] == '-' && anotherDec.number[0] == '-' )
        {
            check2 = 1 ;
            checkSign( *this ) ;
            checkSign( anotherDec ) ;
            return *this - anotherDec ;
        }
        if ( number.length() > anotherDec.number.length() )
            {
                int difference = number.length() - anotherDec.number.length() ;

                BigInt result;
                result.number = "";
                result.carry = 0;
                for ( int i=( anotherDec.number.length()-1 ); i>=0; i-- )
                {
                    result.sum = 0;
                    result.sum = ( number[i+difference] - '0' ) - ( anotherDec.number[i] - '0' ) +result.carry;
                    result.carry=0;
                    if ( result.sum<0 )
                    {
                        result.sum += 10 ;
                        result.carry-- ;
                    }
                result.number += result.sum+'0';
                }
                for (int i = difference-1; i>=0; i--)
                {
                    result.sum=0;
                    result.sum += number[i] + ( result.carry - '0' );
                    result.carry=0;
                    if ( result.sum < 0 )
                    {
                        result.sum+=10;
                        result.carry--;
                    }
                result.number += result.sum+'0';
                }
                if ( check2 == 1 )
                {
                    result.number += '-' ;
                }
                reverse( result.number.begin(),result.number.end() ) ;
                removeRemainingZeros( result.number ) ;
                return result ;
            }
            if ( anotherDec.number.length() > number.length())
            {
                int difference = anotherDec.number.length()- number.length();

                BigInt result;
                result.number = "";
                result.carry = 0;
                for ( int i=(number.length()-1); i>=0; i-- )
                {
                    result.sum = 0;
                    result.sum = ( anotherDec.number[i+difference] - '0' ) - ( number[i] - '0' )+result.carry;
                    result.carry = 0;
                    if ( result.sum < 0 )
                    {
                        result.sum += 10 ;
                        result.carry-- ;
                    }
                result.number += result.sum+'0';
                }
                for (int i = difference-1; i>=0; i--)
                {
                    result.sum = 0 ;
                    result.sum += anotherDec.number[i] + ( result.carry - '0' );
                    result.carry = 0 ;
                    if ( result.sum < 0 )
                    {
                        result.sum += 10;
                        result.carry-- ;
                    }
                result.number += result.sum+'0';
                }
                if( !check2 )
                {
                    result.number += '-' ;
                }
                reverse( result.number.begin(),result.number.end() ) ;
                removeRemainingZeros( result.number ) ;
                return result ;
            }
            if( number.length() == anotherDec.number.length() )
            {
                if( checkIfEqual( number , anotherDec.number ) )
                {
                    BigInt result ;
                    result.number = "0" ;
                    return result ;
                }
                if ( checkBigger( number , anotherDec.number ) )
                {
                    BigInt result;
                    result.number = "";
                    result.carry = 0;
                    for ( int i=( anotherDec.number.length()-1 ); i>=0; i-- )
                    {
                        result.sum = 0;
                        result.sum = ( number[i] - '0' ) - ( anotherDec.number[i] - '0' ) +result.carry;
                        result.carry=0;
                        if ( result.sum<0 )
                        {
                            result.sum += 10 ;
                            result.carry-- ;
                        }
                        result.number += result.sum+'0';

                    }
                    if ( check2 == 1 )
                    {
                        result.number += '-' ;
                    }
                    reverse( result.number.begin(),result.number.end() ) ;
                    removeRemainingZeros( result.number ) ;
                    return result ;
                }
                if( checkBigger( anotherDec.number , number ) )
                {
                    BigInt result;
                    result.number = "";
                    result.carry = 0;
                    for ( int i=(number.length()-1); i>=0; i-- )
                    {
                        result.sum = 0;
                        result.sum = ( anotherDec.number[i] - '0' ) - ( number[i] - '0' ) + result.carry ;
                        result.carry = 0;
                        if ( result.sum < 0 )
                        {
                            result.sum += 10 ;
                            result.carry -- ;
                        }
                    result.number += result.sum+'0';
                    }
                    reverse( result.number.begin(),result.number.end() ) ;
                    removeRemainingZeros( result.number ) ;
                    return result ;
                }

                }
    }
    friend ostream& operator << (ostream& out, const BigInt number3 )
    {
        out << number3.number ;
    }

};
int main ()
{
    BigInt intNum ( 15623 ) ;
    BigInt intNum2 ( 78956 ) ;
    BigInt result = intNum + intNum2 ;
    cout << result << endl ;
    //94579
    BigInt num1("123456789012345678901234567890");
    BigInt num2("113456789011345678901134567890");
    BigInt num3 = num1 + num2 ;
    cout << num3 << endl  ;
    //236913578023691357802369135780
    BigInt num4("-123456789012345678901234567890");
    BigInt num5("-113456789011345678901134567890");
    BigInt num6 = num4 + num5 ;
    cout << num6 << endl ;
    //-236913578023691357802369135780
    BigInt num7("-225");
    BigInt num8("105");
    BigInt num9 = num7 - num8 ;
    cout << num9 << endl ;
    //-330
    BigInt num10("2078");
    BigInt num11("-219");
    BigInt num12 = num10 - num11 ;
    cout << num12 << endl ;
    //2297
    BigInt num13("-1078");
    BigInt num14("-219");
    BigInt num15 = num13 - num14 ;
    cout << num15 << endl ;
    //-859

}
