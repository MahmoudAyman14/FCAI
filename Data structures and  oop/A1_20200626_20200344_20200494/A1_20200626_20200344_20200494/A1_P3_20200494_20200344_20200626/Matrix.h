
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template <class T>


class Matrix
{
private: T** MatrixData;
int row,col;
public:
    Matrix();
    Matrix(int row,int col,T num[]);
    Matrix(int row,int col);
    Matrix(const Matrix<T>& first);

 int getrow();
 int getcol();

 template<class T2>
	friend istream& operator>> (istream& in, Matrix<T2>& Matr);


	template <class T2>
	friend ostream& operator<< (ostream& out, const Matrix<T2>& Matr);


	Matrix<T> operator+(Matrix<T> & Matr2);


	Matrix<T> operator-(Matrix<T> &Matr2);


	Matrix<T> operator*(Matrix<T> &Matr2);


	Matrix<T> operator+(T Numb);


	Matrix<T> operator-(T Numb);


	Matrix<T> operator*(T Numb);


	template <class T2>
	friend Matrix<T2>& transpose(Matrix<T2>& Matr);

	virtual ~Matrix();
};


template <class T>
Matrix<T>::Matrix() {}


template <class T>
Matrix<T>::Matrix(int row, int col, T num[])
{
    this->row = row;
    this->col = col;
    MatrixData = new T*[row];

    for (int i = 0; i < row; i++)
        MatrixData[i] = new T[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            MatrixData[i][j] = num[i * col + j];
}


template <class T>
Matrix<T>::Matrix(int row, int col)
{
    this->row = row;
    this->col = col;
    MatrixData = new T*[row];
    for (int i = 0; i < row; i++)
        MatrixData[i] = new T[col];
}


template<class T>
Matrix<T>::getrow()
{
    return row;
}

template<class T>
Matrix<T>::getcol()
{
    return col;
}


template<class T2>
istream& operator>> (istream& in, Matrix<T2>& Matr)
{
    cin >> Matr.row >> Matr.col;

    Matr.MatrixData = new T2*[Matr.row];

    for (int i = 0; i < Matr.row; i++)
        Matr.MatrixData[i] = new T2[Matr.col];

    for (int i = 0; i < Matr.row; i++)
        for (int j = 0; j < Matr.col; j++)
            in >> Matr.MatrixData[i][j];

    return in;
}


template<class T2>
ostream& operator<< (ostream& out, const Matrix<T2>& Matr)
{
    for (int i = 0; i < Matr.row; i++)
    {
        out << endl;
        for (int j = 0; j < Matr.col; j++)
            out << Matr.MatrixData[i][j] << "  ";
    }
    out << endl;

    return out;
}


template<class T>
Matrix<T>::Matrix(const Matrix<T>& first)
{
    this->col = first.col;
    this->row = first.row;
    this->MatrixData = new T*[row];

    for (int i = 0; i < row; i++)
        this->MatrixData[i] = new T[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            this->MatrixData[i][j] = first.MatrixData[i][j];
}



template<class T>
Matrix<T> Matrix<T>::operator+( Matrix<T> & Matr2)
{
    Matrix<T> Matr(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            Matr.MatrixData[i][j] = 0;

    for (int i = 0; i < Matr.row; i++)
    {
        for (int j = 0; j < Matr.col; j++)
        {
            Matr.MatrixData[i][j] = (MatrixData[i][j] + Matr2.MatrixData[i][j]);
        }
    }
    return Matr;
}


template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &Matr2)
{
    Matrix<T> Matr(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            Matr.MatrixData[i][j] = 0;

    for (int i = 0; i < Matr.row; i++)
    {
        for (int j = 0; j < Matr.col; j++)
        {
            Matr.MatrixData[i][j] = (MatrixData[i][j] - Matr2.MatrixData[i][j]);
        }
    }
    return Matr;
}


template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &Matr2)
{
    Matrix<T> Matr(row, col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < Matr2.col; j++)
            Matr.MatrixData[i][j] = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < Matr2.col; j++)
            for (int k = 0; k <col; k++)
            {
                Matr.MatrixData[i][j] += MatrixData[i][k] * Matr2.MatrixData[k][j];
            }
    return Matr;
}


template <class T>
Matrix<T> Matrix<T>::operator+(T Numb)
{
    Matrix<T> Matr(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            Matr.MatrixData[i][j] = 0;


    for (int i = 0; i < Matr.row; i++)
    {
        for (int j = 0; j < Matr.col; j++)
        {
            Matr.MatrixData[i][j] = (MatrixData[i][j] + Numb);
        }
    }
    return Matr;
}


template <class T>
Matrix<T> Matrix<T>::operator-(T Numb)
{
    Matrix<T> Matr(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            Matr.MatrixData[i][j] = 0;


    for (int i = 0; i < Matr.row; i++)
    {
        for (int j = 0; j < Matr.col; j++)
        {
            Matr.MatrixData[i][j] = (MatrixData[i][j] - Numb);
        }
    }
    return Matr;
}


template <class T>
Matrix<T> Matrix<T>::operator*(T Numb)
{

    Matrix<T> Matr(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            Matr.MatrixData[i][j] = 0;


    for (int i = 0; i < Matr.row; i++)
    {
        for (int j = 0; j < Matr.col; j++)
        {
            Matr.MatrixData[i][j] = (MatrixData[i][j] * Numb);
        }
    }
    return Matr;
}


template<class T2>
Matrix<T2>& transpose(Matrix<T2>& Matr)
{
    Matrix<T2> Matr1(Matr.col, Matr.row);

    for (int i = 0; i < Matr.row; i++)
        for (int j = 0; j < Matr.col; j++)
            Matr1.MatrixData[i][j] = Matr.MatrixData[j][i];

    for (int i = 0; i < Matr.row; i++)
        for (int j = 0; j < Matr.col; j++)
            Matr.MatrixData[i][j] = Matr1.MatrixData[i][j];

    return Matr;
}

template<class T>
Matrix<T>::~Matrix()
{}







