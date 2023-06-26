#include <iostream>
#include <algorithm>
using namespace std;


template <class T>
 struct node
    {
        T item;
        node* next;
        node* prev;
    };


template<class T> class List
{
    node<T> *first;
    node<T> *last;
    int length;
    int counter=0;

public:

    List()
    {
        first=NULL;
        last=NULL;
    }
    List(T value , int initial_size)
    {
        node<T> *temp=new node<T>;
        temp->item=value;
        temp->next=NULL;
        first=temp;
        last=temp;
        temp=NULL;


        for(int i=0;i<initial_size-1;i++)
        {
            node<T> *temp=new node<T>;
            temp->item=value;
            temp->next=NULL;
            last->next=temp;
            last=temp;
        }
    }

    void insert_first(T item)
    {
        node<T> *newNode= new node<T>;
        newNode->item=item;
        if(counter==0)
        {
            first=last=newNode;
            newNode->next=newNode->prev=NULL;
        }

        else{
            newNode->next=first;
            newNode->prev=NULL;
            first->prev=newNode;
            first=newNode;
        }

        counter++;
    }

    void insert_last(T item)
    {
        node<T> *newNode= new node<T>;
        newNode->item=item;
        if(counter==0)
        {
            first=last=newNode;
            newNode->next=newNode->prev=NULL;
        }

        else{
            newNode->next=NULL;
            newNode->prev=last;
            last->next=newNode;
            last=newNode;
        }

        counter++;
    }




    void insert_(T item ,int position)
    {
        if(position<0 ||position>counter)
            cout<< "out of range.";
        else{
            node<T> *newNode= new node<T>;
            newNode->item=item;
            if(position==0)
                insert_first(item);
            else if(position==counter)
                insert_last(item);

            else{
                node<T> *curr=first;
                for(int i=1;i<position;i++)
                {
                    curr=curr->next;
                }
                newNode->next=curr->next;
                newNode->prev=curr;
                curr->next=newNode;
                curr->next->prev=newNode;
                counter++;
            }
        }

    }



    void print()
    {
        cout<<endl;
        node<T> *curr=first;
        while(curr!=NULL)
        {
            cout<<curr->item<<" ";
            curr=curr->next;
        }
        cout<<endl<<endl;
    }



    public:class iterator
    {
    public:
        node<T> *firstit;
        node<T> *nodeit;

    public:
        iterator()
        {
            firstit=nullptr;
            nodeit=nullptr;
        }

        iterator(node<T> *ptr,node<T> *f)
        {
            firstit=f;
            nodeit=ptr;
        }

        void operator--()
        {
            List<T>:: iterator num;
            num.nodeit=this->firstit;
            num.firstit=this->firstit;

            if(this->firstit==this->nodeit)
            {
                cout<< "Error"<<endl;
            }
            else{
                while(num.nodeit->next!=NULL)
                {
                    if(num.nodeit->next==this->nodeit)
                    {
                        this->nodeit=num.nodeit;
                        return;
                    }
                    num++;
                }
            }
        }

        void operator++()
        {
            if(nodeit->next==NULL)
            {
                cout<<"Error";
                return;
            }

            nodeit=nodeit->next;
        }

        T& operator*()
        {
            return nodeit->item;
        }

        bool operator==(const iterator& it) const
        {
            return nodeit==it.nodeit;
        }

        bool operator!=(const iterator& it) const
        {
            return nodeit!=it.nodeit;
        }
    };



       void remove_first()
    {
        if(counter==0)
          cout<< "Empty..."<<endl;
        else if(counter==1)
        {
            delete first;
            last=first=NULL;
        }

        else{
            node<T> *curr=first;
            first=first->next;
            first->prev=NULL;
            delete curr;
        }
        counter--;
    }



    void remove_last()
    {
        if(counter==0)
          cout<< "Empty..."<<endl;
        else if(counter==1)
        {
            delete first;
            last=first=NULL;
        }

        else{
            node<T> *curr=last;
            last=last->prev;
            last->next=NULL;
            delete curr;
        }
        counter--;
    }


    void remove_item(T item)
    {
        if(counter==0)
            {cout<<"Empty..."<<endl;}

        else if(first->item == item)
            {remove_first();}

        else{

            node<T> *curr=first->next;
            while(curr!=NULL)
            {
                if(curr->item==item)
                    break;
                curr=curr->next;
            }


        if(curr==NULL)
            cout<< "Not found."<<endl;
        else if(curr->next==NULL)
            remove_last();

        else{

            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            delete curr;
            counter--;
        }
    }
}


bool search(T value)
{
    node<T> *temp=new node<T>;
    temp=first;
    while(temp!=NULL)
    {
        if(temp->item==value)
            return 1;
        temp=temp->next;
    }

    return 0;
}

iterator begin()
{
    return iterator(first,first);
}

iterator end()
{
    return iterator(last,first);
}

    int size_()
    {
        return counter;
    }

    ~List()
    {/*
        do
        {
            remove_last();
        }while(first!=last);
        delete first;
        delete last;
*/
    }
};



int main()
{
    List<int> a(5,2);
    a.insert_last(5);
    a.insert_last(7);
    a.insert_last(8);
    a.print();
    a.insert_(2,5);
    a.print();
    a.search(7);
    a.remove_first();
    a.print();

    return 0;
}
