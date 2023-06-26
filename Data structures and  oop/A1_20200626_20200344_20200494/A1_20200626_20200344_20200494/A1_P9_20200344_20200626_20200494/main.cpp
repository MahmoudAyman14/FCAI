#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
class Sorter
{
public:
    virtual void Sort(vector<int> &arr, int Size ){}
    virtual ~Sorter(){}
};
class SelectionSorter : public Sorter
{
public:
    virtual ~SelectionSorter(){}
    void Sort(vector<int> &arr , int Size )
    {
        for(int i=0 , j , least ; i < Size-1 ; i++ )
        {
            for( j = i+1 , least = i ; j <Size ; j++  )
            {
                if( arr[j] < arr[least]  )
                {
                    least = j ;
                }
            }
            swap( arr[least] , arr[i] ) ;
        }
    }
};
class QuickSorter : public Sorter
{
public:
    virtual ~QuickSorter(){}
    int Left, Right ;
    int Partition (vector<int> &arr, int left , int right )
    {
        int x = arr[left] ;
        int i = left ;
        for( int j = left+1 ; j<right ; j++ )
        {
            if( arr[j] < x )
            {
                i++ ;
                swap( arr[i] , arr[j] ) ;
            }
        }
        swap( arr[i] , arr[left] ) ;
        return i ;
    }
    void quickSort (vector<int> &arr , int left , int right )
    {
        if( left >= right )
        {
            return ;
        }
        else
        {
            int middle = Partition( arr , left , right ) ;
            quickSort( arr , left , middle-1 ) ;
            quickSort( arr , middle+1  , right ) ;
        }
    }
    void Sort(vector<int> &arr, int Size)
    {
        quickSort (arr , 0 , Size) ;
    }
};
class TestBed
{
public:
    vector<int> GenerateRandomList( int m , int M , int Size )
    {
        vector<int> vec;
        for(int x = 0 ; x < Size; x++)
        {
             vec.push_back((rand()%( M - m  + 1 ) + m)) ;
        }
        return vec ;
    }
    vector<int> GenerateReverseOrderedList( int m , int M , int Size )
    {
        vector<int> vec;
        for(int x = 0 ; x < Size; x++)
        {
             vec.push_back( rand()%( M - m  + 1 ) + m ) ;
        }
        SelectionSorter s;
        s.Sort(vec,Size);
        reverse(vec.begin(),vec.end());
        return vec;
    }
    unsigned long RunOnce( Sorter * x , vector<int> arr, int Size )
    {
        using namespace std::chrono;
        auto start = high_resolution_clock::now() ;
        x->Sort(arr,Size);
        auto stop = high_resolution_clock::now() ;
        unsigned long duration = duration_cast<microseconds> ( stop - start ).count() ;
        return duration;
    }

    long RunAndAverage(Sorter *X , bool type , int Min, int Max, int Size, int sets_num)
    {
        long sum = 0;
        if( type == 0  )
        {
            for(int x = 0 ; x < sets_num ; x++ )
            {
                vector<int> v = GenerateRandomList( Min , Max , Size ) ;
                long z = RunOnce( X , v , Size ) ;
                sum+=z;
            }
        }
        else
        {
            for(int x = 0 ; x < sets_num ; x++ )
            {
               vector<int> v = GenerateReverseOrderedList( Min , Max , Size  ) ;
                long z = RunOnce( X , v , Size ) ;
                sum+=z;
            }
        }

        long avg = sum/sets_num;
        return avg;
    }

    void RunExperient(Sorter *s,bool type,int Min, int Max, int min_val, int max_val, int sets_num, int step)
    {
        if(type == 0)
        {
            cout << "Using Random number" << endl;
            long aver = RunAndAverage(s, type, Min, Max, min_val, sets_num);
            cout << "The Average After Generate "<< sets_num << "  Sets With Size " << min_val << " Using RunAndAverage: " << aver << " microsecond"<< endl;
            cout << endl;

            cout << "Size " << "\t" << "Average Time(Microsec)" << "\t" << endl;
            for(int x = min_val ; x <= max_val ; x+=step )
            {
                long aver = RunAndAverage(s, type, Min, Max, x, sets_num);
                cout << x << "\t" << aver << "\t" << endl;
            }
        }

        if(type == 1)
        {
            cout << "Using Random Reverse Number" << endl;
            long aver = RunAndAverage(s, type, Min, Max, min_val, sets_num);
            cout << "The Average After Generate "<< sets_num << "  Sets With Size " << min_val << " Using RunAndAverage: " << aver << " microsecond"<< endl;
            cout << endl;

            cout << "Size " << "\t" << "Average Time(Microsec)" << "\t" << endl;
            for(int x = min_val ; x <= max_val ; x+=step )
            {
                long aver = RunAndAverage(s, type, Min, Max, x, sets_num);
                cout << x << "\t" << aver << "\t" << endl;
            }
        }

        cout << "----------------------------------------------------------------" << endl;

    }




};
int main ()
{
    cout << "Experiment Using SelectionSort:" << endl << endl;
    TestBed T;
    Sorter *ptr = new SelectionSorter;
    T.RunExperient(ptr, 0, 5000, 10000, 1000, 10000, 10, 1000);
    T.RunExperient(ptr, 1, 5000, 10000, 1000, 10000, 10, 1000);

    cout << "-------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------" << endl << endl;

    cout << "Experiment Using QuickSort:" << endl << endl;
    Sorter *pt = new QuickSorter;
    T.RunExperient(pt, 0, 5000, 10000, 1000, 10000, 10, 1000);
    T.RunExperient(pt, 1, 5000, 10000, 1000, 10000, 10, 1000);
    return 0 ;
}


