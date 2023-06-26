#include "FractionCalculator.h"
#include "Fraction.h"
#include <stdlib.h>
#include <iostream>
using namespace std ;
FractionCalculator::FractionCalculator()
{
    //to do nothing
}
void FractionCalculator :: StartCalculating()
{
    string x ;
    int choice ;
    Fraction F1 , F2 , F3 ;
    cout << "Hey there welcome to Fraction Calculator ..  " ;
    while(true)
    {
        cout << endl <<  " Please enter your first fraction  " << endl  ;
        cin >> F1 ;
        cout << endl << " Please enter your second fraction  " << endl  ;
        cin >> F2 ;
        cout << " Now choose the operation you want to make on fractions " << endl ;
        cout << " 1. Addition " << endl << " 2. Subtraction" << endl
        << " 3. Multiplication " << endl << " 4. Devision " << endl ;
        cin >> choice ;
        switch( choice )
        {
            case 1 : F3 = F1 + F2 ;
                    cout << "F3 = " << F3 << endl ;
                    break ;
            case 2 : F3 = F1 - F2 ;
                    cout << "F3 = " << F3 << endl ;
                    break ;
            case 3 : F3 = F1 * F2 ;
                    cout << "F3 = " << F3 << endl ;
                    break ;
            case 4 : F3 = F1 / F2 ;
                    cout << "F3 = " << F3 << endl ;
                    break ;
        }
        cout << "____________________________________________________________________________________________" << endl ;
        cout << " If you want to do another calculation please enter ( yes ) " << endl ;
        cin >> x ;
        if( x == "yes" || x == "Yes")
        {
            continue ;
        }
        else
        {
            cout << "You're Welcome <3 " << endl ;
            exit(1) ;
        }
    }

}

