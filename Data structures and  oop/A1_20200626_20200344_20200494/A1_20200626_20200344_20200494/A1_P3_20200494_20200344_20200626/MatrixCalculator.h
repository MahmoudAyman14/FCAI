#include "Matrix.h"

class MatrixCalculator
{
    public:
        MatrixCalculator();
        virtual ~MatrixCalculator();
        template <class T>
        void print(Matrix<T>& m);
};

template<class T>
void MatrixCalculator::print(Matrix<T>& m)
{
    cout<<"Welcome to MOW Matrix calculator ^_^ : "<<endl;
    cout<<"--------------------------------------"<<endl;

    Matrix<T>Matr2,Matr3;
    int MatrixMode;


    bool choice =true;



    while(choice){


        cout<< "1- Perform Matrix Addition"<<endl<<"2- Perform Matrix Subtraction"<<endl
             <<"3- Perform Matrix Multiplication"<<endl<<"4- Matrix Transpose"<<endl<<endl;


        cout<<"#Enter 0 to close the program -_-"<<endl;


             cin>>MatrixMode;

       switch(MatrixMode)
        {
        case 0:
            choice=false;
            break;
        case 1:
            cout << "Enter your First Matrix : "<<endl;
            cin >> m;
            cout << "Enter your Second Matrix : "<<endl;
            cin>>Matr2;
            if(m.getrow()==Matr2.getrow() && m.getcol()==Matr2.getcol()){
                Matr3 = m + Matr2;
                cout <<"Matrix 1 + Matrix 2 = "<< Matr3<<endl;
            }
            else    cout<<"Rows and Columns are different!"<<endl;
            break;
        case 2:
            cout << "Enter your First Matrix : "<<endl;
            cin >> m;
            cout << "Enter your Second Matrix : "<<endl;
            cin>>Matr2;
            if(m.getrow()==Matr2.getrow() && m.getcol()==Matr2.getcol()){
                Matr3 = m - Matr2;
                cout <<"Matrix 1 - Matrix 2 = "<< Matr3<<endl;
            }
            else    cout<<"Rows and Columns are different!"<<endl;
            break;
        case 3:
            cout << "Enter your First Matrix : "<<endl;
            cin >> m;
            cout << "Enter your Second Matrix : "<<endl;
            cin>>Matr2;
            if(m.getcol()==Matr2.getrow()){
                 Matr3 = m * Matr2;
                cout <<"Matrix 1 * Matrix 2 = "<<Matr3<<endl;
            }
            else    cout<<"Rows and Columns are different!"<<endl;
            break;
        case 4:
            cout << "Enter your Matrix : "<<endl;
            cin >> m;
            cout << "Transposed Matrix : " << endl;
            cout << transpose(m) <<endl;
            break;
        default:
            continue;
        }
    }



    }


