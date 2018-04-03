#ifndef LIST_H
#define LIST_H

template<typename T>
class List
{
public:
    List(int increment = 5);
    virtual ~List();
    List(const List& other);
    List& operator=(const List& other);

    int size() const;
    T& get(int index) const;
    void set(T newElement, int index);
    void add(T newElement, int index);
    T remove(int index);

private:
    T* elements;
    int nrOfElements;
    int maxElements;
    int increment;

    void expand();
    void copy(const List& other);
};

template<typename T>
List<T>::List(int increment)
{
    elements = new T[increment];
    nrOfElements = 0;
    maxElements = increment;
    this->increment = increment;
}

template<typename T>
List<T>::~List()
{
    delete elements;
}

template<typename T>
List<T>::List(const List& other)
{
    copy(other);
}

template<typename T>
List<T>& List<T>::operator=(const List& other)
{
    delete elements;
    copy(other);
    return *this;
}

template<typename T>
int List<T>::size() const
{
    return nrOfElements;
}

template<typename T>
T& List<T>::get(int index) const
{
    return elements[index];
}

template<typename T>
void List<T>::set(T newElement, int index)
{
    elements[index] = newElement;
}

template<typename T>
void List<T>::add(T newElement, int index)
{
    if(nrOfElements > maxElements)
    {
        expand();
    }

    for(int i = index; i < nrOfElements - 1; i++)
    {
        elements[i] = elements[i + 1];
    }

    elements[index] = newElement;
    nrOfElements++;
}

template<typename T>
T List<T>::remove(int index)
{
    T result = elements[index];

    for(int i = index; i < nrOfElements - 1; i++)
    {
        elements[i + 1] = elements[i];
    }
    nrOfElements--;
    return result;
}

template<typename T>
void List<T>::expand()
{
    maxElements += increment;
    T* temp = new T[maxElements];

    for(int i = 0; i < nrOfElements; i++)
    {
        temp[i] = elements[i];
    }

    delete elements;
    elements = temp;
}

template<typename T>
void List<T>::copy(const List& other)
{
    this->elements = new T[other.maxElements];
    this->nrOfElements = other.nrOfElements;
    this->maxElements = other.maxElements;
    this->increment = other.increment;

     for(int i = 0; i < other.nrOfElements; i++)
    {
        this->elements[i] = other.elements[i];
    }
}


#endif // LIST_H
