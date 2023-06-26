#include "Fraction.h"
#include <iostream>
using namespace std ;
Fraction::Fraction()
{
    numerator = 0 ;
}
Fraction :: Fraction( int a , int b )
{
    numerator = a ;
    denominator = b ;
    this -> reduceFractions() ;
}
Fraction :: Fraction( const Fraction &result )
{
    numerator = result.numerator ;
    denominator = result.denominator ;
    this -> reduceFractions() ;
}
int Fraction :: GCD( int x , int y)
{
    if ( y == 0 )
    {
        return x ;
    }
    else
    {
        return GCD( y , x%y );
    }
}
void Fraction :: reduceFractions()
{
    int gcd = GCD( numerator , denominator ) ;
    numerator /= gcd ;
    denominator /= gcd ;
}
bool Fraction :: operator> ( Fraction &secFraction )
{
    if( (float)numerator/denominator  > (float)secFraction.numerator/secFraction.denominator  )
    {
        return 1 ;
    }
    return 0 ;
}
bool Fraction :: operator< ( Fraction &secFraction )
{
    if( (float) numerator/denominator  < (float)  secFraction.numerator/secFraction.denominator  )
    {
        return 1 ;
    }
    return 0 ;
}
bool Fraction :: operator== ( Fraction &secFraction )
{
    if( (numerator == secFraction.numerator) && (denominator == secFraction.denominator) )
    {
        return 1 ;
    }
    return 0 ;
}
bool Fraction :: operator!= ( Fraction &secFraction )
{
    if( (numerator != secFraction.numerator) || (denominator != secFraction.denominator) )
    {
        return 1 ;
    }
    return 0 ;
}
bool Fraction :: operator<= ( Fraction &secFraction )
{
    if( (float) numerator/denominator  <= (float) secFraction.numerator/secFraction.denominator  )
    {
        return 1 ;
    }
    return 0 ;
}
bool Fraction :: operator>= ( Fraction &secFraction )
{
    if( (float) numerator/denominator  >= (float)  secFraction.numerator/secFraction.denominator  )
    {
        return 1 ;
    }
    return 0 ;
}
Fraction Fraction :: operator+ ( Fraction &secFraction )
{
    Fraction RESULT ;
    RESULT.numerator = (numerator*secFraction.denominator) + ( secFraction.numerator*denominator) ;
    RESULT.denominator = denominator*secFraction.denominator ;
    RESULT.reduceFractions() ;
    return RESULT ;
}
Fraction Fraction :: operator- ( Fraction &secFraction )
{
    Fraction RESULT ;
    RESULT.numerator = (numerator*secFraction.denominator) - ( secFraction.numerator*denominator) ;
    RESULT.denominator = denominator*secFraction.denominator ;
    RESULT.reduceFractions() ;
    return RESULT ;
}
Fraction Fraction :: operator* ( Fraction &secFraction )
{
    Fraction RESULT ;
    RESULT.numerator = numerator*secFraction.numerator ;
    RESULT.denominator = denominator*secFraction.denominator ;
    RESULT.reduceFractions() ;
    return RESULT ;
}
Fraction Fraction :: operator/ ( Fraction &secFraction )
{
    Fraction RESULT ;
    RESULT.numerator = numerator*secFraction.denominator ;
    RESULT.denominator = denominator*secFraction.numerator ;
    RESULT.reduceFractions() ;
    return RESULT ;
}
istream& operator >> ( istream &in , Fraction &secFraction )
{
    cout << "Enter nomerator please :  " ;
    in >> secFraction.numerator ;
    cout << endl << "Enter denominator please : " ;
    while(true)
    {
        in >> secFraction.denominator ;
        if( secFraction.denominator == 0 )
        {
            cout << " You can't devide by zero, Please try another number " ;
            cout << endl << "Enter denominator again please : " ;
        }
        else
        {
            break ;
        }
    }
    secFraction.reduceFractions() ;
    return in ;
}
ostream& operator << ( ostream &out , const Fraction &secFraction )
{
    if( secFraction.numerator == 0 )
    {
        out << 0 << endl ;
    }
    else if( secFraction.denominator == 1)
    {
        out << secFraction.numerator << endl ;
    }
    else if( secFraction.denominator == 0 )
    {
        out << endl << " ERROR!!! You can't devide by zero " ;
    }
    else if( secFraction.numerator == secFraction.denominator )
    {
        out << 1 << endl ;
    }
    else
    {
        out << secFraction.numerator << '/' <<  secFraction.denominator ;
    }
    return out ;
}
