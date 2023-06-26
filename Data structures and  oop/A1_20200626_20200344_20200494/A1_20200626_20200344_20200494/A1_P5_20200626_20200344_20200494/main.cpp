#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

class StudentName
{
private:
    string name;

public:

    StudentName(string name)
    {
        int index=0;
        int num_space=0;

        for(int i=0;i<name.length();i++)
        {
            if(name[i]==' ')
            {
                num_space++;
                index=i;
            }
        }
        if(num_space<2)
        {
            if(num_space==0)
                this->name = name + " " + name + " " + name;
            else
                this->name = name + name.substr(index);
        }

        else
            this->name=name;
    }

    void print()
    {
        int a=0;

        cout<< "Name: "<<name<<endl;

        for(int i=0;i<4;i++)
        {
            cout<<i+1<< ". ";
            while(name[a]!=' '&&a<name.length())
            {
                cout<<name[a];
                a++;
            }

            if(name[a]==' ')
                a++;

            cout<<endl;

            if(a==name.length())
               {
                   break;
               }
        }

    }


    bool replace_(int i,int j)
    {
        int num_space=0;
        int a=0;

        string temp;
        vector <string> arr;


        for(int num=0;num<name.length();num++)
        {
            if(name[num]==' ')
                num_space++;
        }



     for(int j=0; j<=num_space ;j++)
     {


        while(name[a]!=' ' && a<name.length() )
        {
            temp+=name[a];
            a++;

        }


        arr.push_back(temp);
        temp="";
        a++;


     }




     if(i<=0||j<=0 || i>arr.size() || j>arr.size() )
            return false;



     temp=arr[i-1];
     arr[i-1]=arr[j-1];
     arr[j-1]=temp;

     cout<<endl<<endl<<endl;

     cout<< "Replaced ( "<<i<<" , "<<j<<" )"<<endl;
     for(int i=0; i<arr.size() ;i++)
     {
         cout<<i+1<< ". "<<arr[i]<<endl;
     }


     cout<<endl<<endl<<endl;
     return true;

    }


};

int main()
{
    bool ch;
    StudentName a1("ahmed mohamed sayed");
    a1.print();
    ch=a1.replace_(1,2);

    if(ch==false)
        cout<< "Error"<<endl;

    StudentName a2("sara ahmed");
    a2.print();
    ch=a2.replace_(2,4);

    if(ch==false)
        cout<<endl<< "Error 'out of range...'"<<endl<<endl;

    StudentName a3("khaled");
    a3.print();
    ch=a3.replace_(3,1);

    if(ch==false)
        cout<< "Error"<<endl;

    StudentName a4("aya ali ahmed sayed");
    a4.print();
    ch=a4.replace_(2,4);

    if(ch==false)
        cout<< "Error"<<endl;


    StudentName a5("walid mohamed ramadan");
    a5.print();
    ch=a5.replace_(1,3);

    if(ch==false)
        cout<< "Error"<<endl;



    return 0;
}
