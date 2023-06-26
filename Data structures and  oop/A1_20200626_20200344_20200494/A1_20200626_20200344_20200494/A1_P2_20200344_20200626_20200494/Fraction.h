#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std ;
class Fraction
{
public:
    int numerator , denominator ;
    Fraction() ;
    Fraction( int  , int ) ;
    void reduceFractions() ;
    Fraction( const Fraction &result ) ;
    int GCD( int  , int  ) ;

    bool operator > ( Fraction &secFraction ) ;
    bool operator < ( Fraction &secFraction ) ;
    bool operator == ( Fraction &secFraction ) ;
    bool operator != ( Fraction &secFraction ) ;
    bool operator >= ( Fraction &secFraction ) ;
    bool operator <= ( Fraction &secFraction ) ;

    Fraction operator+ ( Fraction &secFraction ) ;
    Fraction operator- ( Fraction &secFraction ) ;
    Fraction operator* ( Fraction &secFraction ) ;
    Fraction operator/ ( Fraction &secFraction ) ;

    friend istream& operator >> ( istream &in , Fraction &secFraction ) ;
    friend ostream& operator << ( ostream &out , const Fraction &secFraction ) ;
};

#endif // FRACTION_H
