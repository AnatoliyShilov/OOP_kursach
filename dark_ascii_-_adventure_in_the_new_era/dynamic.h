#ifndef DYNAMIC_H
#define DYNAMIC_H

#ifndef NULL
#define NULL 0
#endif

template<class Data>
struct Link
{
    Data data;
    Link<Data>* Next;
    Link<Data>* Prev;
};

template <class Data>
class List
{
    Link<Data>* begin;
    Link<Data>* end;
public:
    List();
    ~List();
    void add(Data data);
    Data get(int number);
    void remuveAll();
    void remuve(int number);
    Link<Data>* getBegin();
    Link<Data>* getEnd();
};

template<class Data>
List<Data>::List()
{
    begin = end = NULL;
}

template<class Data>
List<Data>::~List()
{
    remuveAll();
}

template<class Data>
void List<Data>::remuve(int number)
{
    Link<Data> *temp = begin;
    for (; temp && number; number--)
        temp = temp->Next;
    temp->Next->Prev = temp->Prev;
    temp->Prev->Next = temp->Next;
    delete temp;
}

template<class Data>
void List<Data>::remuveAll()
{
    Link<Data> *temp;
    while (begin)
    {
        temp = begin;
        begin = begin->Next;
        delete temp;
    }
}

template<class Data>
Data List<Data>::get(int number)
{
    Link<Data> *temp = begin;
    for (; temp && number; number--)
        temp = temp->Next;
    return temp->data;
}

template<class Data>
Link<Data> *List<Data>::getBegin()
{
    return begin;
}

template<class Data>
Link<Data> *List<Data>::getEnd()
{
    return end;
}

template<class Data>
void List<Data>::add(Data data){
    if (begin)
    {
        end->Next = new Link<Data>;
        end->Next->data = data;
        end->Next = NULL;
        end->Prev = end;
        end = end->Next;
    }
    else
    {
        begin = new Link<Data>;
        begin->data = data;
        end = begin;
        begin->Next = begin->Prev = NULL;
    }
}

#endif // DYNAMIC_H
