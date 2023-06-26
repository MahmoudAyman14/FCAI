#include <iostream>
#include <vector>
using namespace std;



class PhoneDirectory
{
private:

    string first_name;
    string last_name;
    string phone_number;
    vector <string> arr;

public:

    PhoneDirectory()
    {

    }



    void Add(string First_name,string Last_name,string Phone_number)
    {

        arr.push_back(First_name);
        arr.push_back(Last_name);
        arr.push_back(Phone_number);

    }

   void lookup_by_firstname(string First_name)
    {
        bool check= true ;

        sorting(1);
        cout<<endl<<endl<<endl;
        for(int i=0; check==true &&i<arr.size() ;i+=3)
        {
            if(arr[i]==First_name)
            {
                check=false;
                cout<<arr[i]<<"  "<<arr[i+1]<<"  "<<arr[i+2];
                cout<<endl<<endl;
                break;
            }
        }
        if(check==true)
            cout<< "Not found."<<endl<<endl;
    }


    void lookup_by_phoneNumber(string Phone_number)
    {
        bool check= true ;
        cout<<endl<<endl<<endl;
        for(int i=2; check==true && i<arr.size() ;i+=3)
        {
            if(arr[i]==Phone_number)
            {
                check=false;
                cout<<arr[i-2]<<"  "<<arr[i-1]<<"  "<<arr[i];
                cout<<endl<<endl;
                break;
            }
        }
        if(check==true)
            cout<<"Not found."<<endl<<endl;
    }



    void SelectionSort()
{
    int min_index;
    string temp;


    for(int i=0;i<arr.size()-1;i+=3)
    {
        min_index=i;

        for(int j=i+3;j<arr.size();j+=3)
        {
            if(arr[j]<arr[min_index])
                {
                    min_index=j;

                }

            if(min_index!=i)
            {
                temp=arr[i];
                arr[i]=arr[min_index];
                arr[min_index]=temp;

                temp=arr[i+1];
                arr[i+1]=arr[min_index+1];
                arr[min_index+1]=temp;

                temp=arr[i+2];
                arr[i+2]=arr[min_index+2];
                arr[min_index+2]=temp;

            }
        }
    }

    cout<<endl<<endl;
    /*
    for(int i=0;i<arr.size();i+=3)
    {
        cout<<arr[i]<<" "<<arr[i+1]<<" "<<arr[i+2]<<endl;
    }
    cout<<endl<<endl;
*/
}


void insertionSort(vector <string>arr_print,int num)
{
    int j;
    string temp;
    for(int i=1;i<num;i++)
    {
        j=i;
        while(j>0 && arr_print[j-1]>arr_print[j])
        {
            temp=arr_print[j];
            arr_print[j]=arr_print[j-1];
            arr_print[j-1]=temp;
            j--;
        }
    }

   cout<<endl<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<arr_print[i]<<endl;
    }
    cout<<endl<<endl;
}


void shellSort(vector<string>arr_print,int num)
{
    int gap;
    string temp;

    for(gap=num/2;gap>0;gap/=2)
    {
        for(int i=gap;i<num;i++)
        {
            for(int j=i-gap;j>=0 && arr_print[j]>arr_print[j+gap]; j-=gap)
            {
                temp=arr_print[j];
                arr_print[j]=arr_print[j+gap];
                arr_print[j+gap]=temp;
            }
        }
    }

    cout<<endl<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<arr_print[i]<<endl;
    }
    cout<<endl<<endl;
}





   void sorting(int num)
    {
        vector <string> arr_print;


        for(int i=0;i<arr.size();i+=3)
        {
            arr_print.push_back(arr[i]+" "+arr[i+1]+" "+arr[i+2]);
        }


        if(num==1)
        {
            SelectionSort();
        }

        if(num==2)
        {
            shellSort(arr_print,arr_print.size());
        }

        if(num==3)
        {
            insertionSort(arr_print,arr_print.size());
        }



    }


   void Delete()
    {
        string element;
        bool check=false;

        sorting(1);

        cout<<endl<<endl<< "Enter the phone number to delete information: ";
        cin>>element;

        for(int i=2;i<arr.size();i+=3)
        {

            if(arr[i]==element)
            {
                arr.erase( arr.begin()+i );
                arr.erase( arr.begin()+(i-1) );
                arr.erase( arr.begin()+(i-2) );


                cout<<endl<< "Done."<<endl;
                check=true;

            }
        }

        if(check==false)
            cout<< "Not found";
        cout<<endl<<endl;

    }

    void print()
    {
        sorting(1);

    cout<<endl<<endl;
    for(int i=0;i<arr.size();i+=3)
    {
        cout<<arr[i]<<" "<<arr[i+1]<<" "<<arr[i+2]<<endl;
    }
    cout<<endl<<endl<<endl;
    }




};



int main()
{
    PhoneDirectory a;
    int num=0;
    string phone_number;
    string first_name;
    string last_name;

    do
    {
        cout<<endl<<endl<<endl;
        cout<< "choose number of this: "<<endl;
        cout<< "1. Add an entry to the directory"<<endl
        << "2. Look up a phone number"<<endl
        << "3. Look up by first name"<<endl
        << "4. Delete an entry from the directory"<<endl
        << "5. List All entries in phone directory"<<endl
        << "6. Exit from this program"<<endl;
        cin>>num;
        cout<<endl<<endl<<endl;


        if(num==1)
        {
          cout<< "Enter first name: ";
          cin>>first_name;

          cout<< "Enter last name: ";
          cin>>last_name;

          cout<< "Enter phone number: ";
          cin>>phone_number;

          a.Add(first_name,last_name,phone_number);

        }

        if(num==2)
        {

            cout<< "Enter the phone number: ";
            cin>>phone_number;

            a.lookup_by_phoneNumber(phone_number);
            phone_number="";
        }

        if(num==3)
        {
            cout<<endl<<endl;
            cout<< "Enter the first name: ";
            cin>>first_name;
            a.lookup_by_firstname(first_name);
            first_name="";

        }

        if(num==4)
        {
            a.Delete();
        }

        if(num==5)
        {
            a.print();
        }


    }while(num!=6&&num>0&&num<6);



    return 0;
}
