#ifndef DYNAMIC_H
#define DYNAMIC_H
#ifndef NULL
#define NULL 0
#endif

template<class Data>
struct Link//узел списка
{
    Data data;//данные
    Link<Data>* Next;//след. узел
    Link<Data>* Prev;//пред. узел
};

template <class Data>
class List//список
{
    Link<Data>* begin;//начало
    Link<Data>* end;//конец
public:
    List();
    ~List();
    int size();//вернуть количество элементов в списке
    bool isEmpty();//истинна, если список пуст
    void add(Data data);//добавить новый элемент в список
    Data get(int number);//вернуть данные узла под указанным номером
    void removeAll();//удалить все элементы
    static void swap(Link<Data> *to, Link<Data> *from);//поменять местами 2 узла
    void remove(int number);//удалить узел под указанным номером
    void remove(Link<Data> *link);//удалить указанный узел
    Link<Data>* getBegin();//вернуть начало
    Link<Data>* getEnd();//вернуть конец
};

template <class Data>
void List<Data>::swap(Link<Data> *to, Link<Data> *from)
{
    Data temp = from->data;
    from->data = to->data;
    to->data = temp;
}

template <class Data>
bool List<Data>::isEmpty()
{
    if (begin == NULL)
        return true;
    else
        return false;
}

template<class Data>
int List<Data>::size()
{
	int size = 0;
	for (Link<Data> *temp = begin; temp; temp = temp->Next)
		size++;
	return size;
}

template<class Data>
List<Data>::List()
{
    begin = end = NULL;
}

template<class Data>
List<Data>::~List()
{
    List<Data>::removeAll();
}

template<class Data>
void List<Data>::remove(Link<Data> *link)
{
    if (link == begin)
    {
        begin = begin->Next;
        if (!begin)
            end = begin;
        else
            begin->Prev = NULL;
    }
    else
        if (link == end)
        {
            end = end->Prev;
            end->Next = NULL;
        }
        else
        {
            link->Next->Prev = link->Prev;
            link->Prev->Next = link->Next;
        }
    delete link;
}

template<class Data>
void List<Data>::remove(int number)
{
    Link<Data> *temp = begin;
    for (; temp && number; number--)
        temp = temp->Next;
    if (temp == begin)
    {
        begin = begin->Next;
        begin->Prev = NULL;
    }
    else
        if (temp == end)
        {
            end = end->Prev;
            end->Next = NULL;
        }
        else
        {
            temp->Next->Prev = temp->Prev;
            temp->Prev->Next = temp->Next;
        }
    delete temp;
}

template<class Data>
void List<Data>::removeAll()
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
    for (; temp && number > 0; number--)
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
        end->Next->Prev = end;
        end->Next->Next = NULL;
        end = end->Next;
    }
    else
    {
        begin = new Link<Data>;
        begin->data = data;
        begin->Next = begin->Prev = NULL;
        end = begin;
    }
}

#endif // DYNAMIC_H
