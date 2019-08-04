#include <iostream>

class LinkedList
{
public:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };
    Node *head;
    Node *tail;
    int length;
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    void add(int data);
    void add(int data, int position);
    void delete_node(int position);
    int get_length();
    void print();
    int get_first();
};

void LinkedList::add(int data)
{
    Node *node = new Node(data);

    if (this->head == nullptr)
    {
        this->head = node;
    }
    else
    {
        this->tail->next = node;
    }
    this->tail = node;
    this->length = this->length + 1;
}

void LinkedList::add(int data, int position)
{
    Node *temp_head = this->head;
    Node *node = new Node(data);
    int i = 0;
    while (i < this->length)
    {
        if (i == position - 1)
        {
            node->next = this->head->next;
            this->head->next = node;
        }
        this->head = this->head->next;
        i++;
    }
    this->head = temp_head;
    this->length = this->length + 1;
}

void LinkedList::print()
{
    Node *temp_head = this->head;
    while (this->head != nullptr)
    {
        std::cout << this->head->data << '\n';
        this->head = this->head->next;
    }
    this->head = temp_head;
}

int LinkedList::get_length()
{
    return this->length;
}

int LinkedList::get_first()
{
    return this->head->data;
}

int main()
{
    LinkedList *llist = new LinkedList();
    llist->add(0);
    llist->add(1);
    llist->add(3);
    llist->add(4);
    llist->add(2, 2);
    llist->print();
    std::cout << "Length: " << llist->get_length() << '\n';
    std::cout << "First Element : " << llist->get_first() << '\n';
}