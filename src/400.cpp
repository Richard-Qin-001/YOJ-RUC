#include <iostream>
#include <cstdlib>
using namespace std;

/*********结点类模板的声明与实现**********/
template <class T>
class Node {
private:
    Node<T> *next;    //指向后继结点的指针
public:
    T data;    //数据域
    Node(const T &data, Node<T> *next = NULL);    //构造函数
    void insertAfter(Node<T> *p);    //在本结点之后插入一个同类结点p
    Node<T> *deleteAfter();      //删除本结点的后继结点，并返回其地址
    Node<T> *nextNode();            //获取后继结点的地址
    const Node<T> *nextNode() const;    //获取后继结点的地址
};

//构造函数，初始化数据和指针成员
template <class T>
Node<T>::Node(const T& data, Node<T> *next/* = NULL */) : data(data), next(next) { }

//返回后继结点的指针
template <class T>
Node<T> *Node<T>::nextNode() {
    return next;
}

//返回后继结点的指针
template <class T>
const Node<T> *Node<T>::nextNode() const {
    return next;
}
//在当前结点之后插入一个结点p
template <class T>
void Node<T>::insertAfter(Node<T> *p) {
    p->next = next; //p结点指针域指向当前结点的后继结点
    next = p;     //当前结点的指针域指向p
}

//删除当前结点的后继结点，并返回其地址
template <class T> Node<T> *Node<T>::deleteAfter() {
    Node<T> *tempPtr = next;   //将欲删除的结点地址存储到tempPtr中
    if (next == NULL)          //如果当前结点没有后继结点，则返回空指针
        return NULL;
    next = tempPtr->next; //使当前结点的指针域指向tempPtr的后继结点
    return tempPtr;         //返回被删除的结点的地址
}
/*****************************************/
/***********链表类模板的声明与实现************/
template <class T>
class LinkedList {
private:
    Node<T> *front, *rear;  //表头和表尾指针
    Node<T> *prevPtr, *currPtr;  //记录链表当前遍历位置的指针，由插入和删除操作更新
    int size;  //表中的元素个数
    int position;  //当前元素在表中的位置序号。由函数reset使用

    Node<T> *newNode(const T &item, Node<T> *ptrNext=NULL);  //生成新结点，数据域为 item，指针域为 ptrNext
    void freeNode(Node<T> *p);  //释放结点
    void copy(const LinkedList<T>& L);  //将链表 L 拷贝到当前表（假设当前表为空）。被复制构造函数和“operator =”调用
public:
    LinkedList();  //构造函数
    LinkedList(const LinkedList<T> &L);  //复制构造函数
    ~LinkedList();  //析构函数
    LinkedList<T> & operator = (const LinkedList<T> &L);  //重载赋值运算符
    int getSize() const;  //返回链表中元素个数
    bool isEmpty() const;  //链表是否为空
    void reset(int pos = 0);  //初始化游标的位置
    void next();  //使游标移动到下一个结点
    bool endOfList() const;  //游标是否到了链尾
    int currentPosition(void) const;  //返回游标当前的位置
    void insertFront(const T &item);  //在表头插入结点
    void insertRear(const T &item);  //在表尾插入结点
    void insertAt(const T &item);  //在当前结点之前插入结点
    void insertAfter(const T &item);  //在当前结点之后插入结点
    T deleteFront();  //删除头结点
    void deleteCurrent();  //删除当前结点
    T& data();  //返回对当前结点成员数据的引用
    const T& data() const;  //返回对当前结点成员数据的常引用
    void clear();  //清空链表：释放所有结点的内存空间。被析构函数和“operator =”调用
};

// ____qcodep____
#ifndef nullptr
#define nullptr NULL
#endif
template <class T>
LinkedList<T>::LinkedList() : front(nullptr), rear(nullptr), size(0), position(0), prevPtr(nullptr), currPtr(nullptr) {}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &L) : front(nullptr), rear(nullptr), size(0), position(0), prevPtr(nullptr), currPtr(nullptr)
{
    copy(L);
}

template <class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &L){
    if (this != &L){
        clear();
        copy(L);
    }
    return *this;
}

template <class T>
bool LinkedList<T>::endOfList() const {
    return currPtr == nullptr;
}

template <class T>
int LinkedList<T>::currentPosition() const{
    return position;
}

template <class T>
T& LinkedList<T>::data() {
    return currPtr->data;
}

template <class T>
const T& LinkedList<T>::data() const {
    return currPtr->data;
}

template <class T>
void LinkedList<T>::clear() {
    while (!isEmpty())
    {
        deleteFront();
    }
    return void(0);
}

template <class T>
void LinkedList<T>::insertFront(const T &item)
{
    Node<T> *new_node = newNode(item, front);
    front = new_node;
    if (isEmpty()){
        rear = new_node;
    }
    size++;
    reset(position);
}

template <class T>
void LinkedList<T>::insertAt(const T &item) {
    if (currPtr == front){
        insertFront (item);
    } else if (prevPtr != nullptr){
        Node<T> *new_node = newNode(item, currPtr);
        prevPtr->insertAfter(new_node);
        if (currPtr == nullptr)
        {
            rear = new_node;
        }
        size++;
        position++;
    }
    return void(0);
}

template <class T>
void LinkedList<T>::deleteCurrent() {
    if (currPtr != nullptr)
    {
        if (currPtr == front)
        {
            deleteFront();
            currPtr = front;
            position = 0;
        }
        else
        {
            if (currPtr == rear)
            {
                rear = prevPtr;
            }

            Node<T> * tempPtr = prevPtr->deleteAfter();
            freeNode(tempPtr);

            size--;
            currPtr = prevPtr->nextNode();
        }
    }
}


// __end__


template <class T>
Node<T> *LinkedList<T>::newNode(const T &item, Node<T> *ptrNext)
{
    Node<T> *newNode;

    newNode = new Node<T>(item, ptrNext);

    if (newNode == NULL) {
        cerr << "Memory allocation failure!" << endl;
        exit(1);
    }

    return newNode;
}

template <class T>
void LinkedList<T>::freeNode(Node<T> *p) {
    delete p;
}

template <class T>
void LinkedList<T>::copy(const LinkedList<T> &L)  {
    if (L.size == 0)
        return;

    front = rear = newNode(L.front->data);

    for (Node<T> *srcNode = L.front->nextNode();
        srcNode != NULL;
        srcNode = srcNode->nextNode())
    {
        Node<T> *newNode = newNode(srcNode->data);
        rear->insertAfter(newNode);
        rear = newNode;
    }

    size = L.size;
    reset(position = L.currentPosition());
}

template <class T>
int LinkedList<T>::getSize() const {
    return size;
}

template <class T>
bool LinkedList<T>::isEmpty(void) const {
    return (size == 0);
}

template <class T>
void LinkedList<T>::reset(int pos) {
    if (0 <= pos && pos <= size) {
        position = 0;
        prevPtr = NULL;
        currPtr = front;
        // 游标回到头结点，再逐步前移
        while (pos--)
            next();
    } else {
        position = pos;
        prevPtr = NULL;
        currPtr = NULL;
    }
}

template <class T>
void LinkedList<T>::next() {
    position++;
    prevPtr = currPtr;

    if (currPtr != NULL)
        currPtr = currPtr->nextNode();
}

template <class T>
void LinkedList<T>::insertRear(const T &item) {
    Node<T> *newNode = newNode(item);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->insertAfter(newNode);
        rear = newNode;
    }

    size++;
    reset(position);
}

template <class T>
void LinkedList<T>::insertAfter(const T &item) {
    if (currPtr != NULL) {
        Node<T> *newNode = newNode(item, currPtr->nextNode());
        currPtr->insertAfter(newNode);

        if (rear == currPtr)
            rear = newNode;

        size++;
    }
}

template <class T>
T LinkedList<T>::deleteFront() {
    if (isEmpty()) {
        cerr << "List is empty, delete error." << endl;
        exit(1);
    }

    Node<T> *delNode = front;
    front = front->nextNode();

    if (--size == 0)
        rear = NULL;

    reset(--position);

    T item = delNode->data;
    freeNode(delNode);

    return item;
}

int main() {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        int item;
        cin >> item;
        list.insertFront(item);
    }
    int key;
    cin >> key;

    cout << "List: ";
    list.reset();
    while (!list.endOfList()) {
         cout << list.data() << "  ";
        list.next();
    }
    cout << endl;

    list.reset();
    while (!list.endOfList()) {
        if (list.data() == key)
            list.deleteCurrent();
        else
            list.next();
    }
    cout << "After deleting " << key << ": ";
    list.reset();
    while (!list.endOfList()) {
          cout << list.data() << "  ";
        list.next();
    }
    cout << endl;
    return 0;
}