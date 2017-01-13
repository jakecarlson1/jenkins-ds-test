#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class ListNode
{
    template<class U> friend class LinkedList;
public:
    
    //Add functionality here to provide access to the ListNode Object.
    ListNode(): next(nullptr), last(nullptr) {}
    ListNode(T value): next(nullptr), last(nullptr), data(value) {}
    ListNode(const ListNode<T>& rhs): next(nullptr), last(nullptr), data(rhs.value) {}
    
    /*tests only*/
    ListNode<T>* getNext(){return next;};
    ListNode<T>* getLast(){return last;};
    T getData() {return data;};
    
private:
    ListNode<T>*next;
    ListNode<T>*last;
    T data;
    
    
};

template<class T>
class LinkedList
{
public:

    LinkedList();
    LinkedList(T);
    LinkedList(const LinkedList<T>&);

    void add(T);
    void addToFront(T);
    T get(int);
    int size();
    T remove(int);
//    bool isEmpty();
//    
//    ~LinkedList();
//
//    T& operator[] (int);
//    LinkedList<T>& operator=(LinkedList<T>&);
    
    /*tests only*/
    ListNode<T>* getHead() {return head;};
    int getLength() {return length;};

private:

    ListNode<T>* head;
    ListNode<T>* tail;
    ListNode<T>* curr;
    int length;

};

//default constructor
template<class T>
LinkedList<T>::LinkedList():
    head(nullptr), tail(nullptr), length(0)
{}

//constructor from value
template<class T>
LinkedList<T>::LinkedList(T value):
    length(1)
{
    head = new ListNode<T>(value);
    tail = head;
}

//overloaded copy constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
    length = rhs.length;
    ListNode<T>* tempCurr = rhs.head;
    if(rhs.head != nullptr)
    {
        head = new ListNode<T>(rhs.head->data);
        curr = head;
    }
    while(tempCurr->next != nullptr)
    {
        curr->next = new ListNode<T>(tempCurr->next->data);
        tail = curr->next;
        curr->next->last = curr;
        tempCurr = tempCurr->next;
    }
    
}

//add adds an element to the end of the linked list
template<class T>
void LinkedList<T>::add(T value)
{
    if(head == nullptr)
    {
        head = new ListNode<T>(value);
        tail = head;
        length++;
    }
    else
    {
        curr = head;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new ListNode<T>(value);
        tail = curr->next;
        curr->next->last = curr;
        length++;
    }
}

//addToFront adds an element to he front of the linked list
template<class T>
void LinkedList<T>::addToFront(T value)
{
    if(head == nullptr)
    {
        head = new ListNode<T>(value);
        tail = head;
        length++;
    }
    else
    {
        ListNode<T>* temp = new ListNode<T>(value);
        temp->next = head;
        head->last = temp;
        head = temp;
        length++;
    }
}

//returns the element stored in the pos'th position
template<class T>
T LinkedList<T>::get(int pos)
{
    curr = head;
    if(pos >= (-1 * length) && pos < 0)
    {
        curr = tail;
        pos++;
        while(pos < 0 && curr->last != nullptr)
        {
            curr = curr->last;
            pos++;
        }
    }
    else if(pos < length)
    {
        while(pos > 0 && curr->next != nullptr)
        {
            curr = curr->next;
            pos--;
        }
    }
    return curr->data;
}

//returns the length of the linked list
template<class T>
int LinkedList<T>::size()
{
    return length;
}

//removes the element at pos
template<class T>
T LinkedList<T>::remove(int pos)
{
    curr = head;
    if(pos == 0)
    {
        curr = head;
        head = head->next;
        head->last = nullptr;
        T temp = curr->data;
        delete curr;
        length--;
        return temp;
    }
    else if(pos >= (-1 * length) && pos < 0)
    {
        curr = tail;
        pos++;
        while(pos < 0 && curr->last != nullptr)
        {
            curr = curr->last;
            pos++;
        }
    }
    else if(pos < length)
    {
        while(pos > 0 && curr->next != nullptr)
        {
            curr = curr->next;
            pos--;
        }
    }
    curr->next->last = curr->last;
    curr->last->next = curr->next;
    T temp = curr->data;
    delete curr;
    length--;
    return temp;
}

#endif
