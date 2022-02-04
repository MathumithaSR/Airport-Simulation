#include <iostream>
#include <iomanip>
#include <stdlib.h>

enum Error_code {success,overflow,underflow};

class Queue
{
	Node *front,*rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    void clear()
    {
        while(!empty())
        serve();
    }
    bool empty()
    {
        return front == NULL;
    }
    bool full() const;
    int size() const;
    Error_code retrieve(Flight &item) ;
    Error_code serve();
    Error_code append(const Flight &item);
    ~Queue()
    {
        while (!empty())
        serve();
    }
    Queue(const Queue &original);
    void operator=(const Queue &original);
};

int Queue::size() const
{
    int count = 0;
    Node *temp = front;
    while (temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Error_code Queue::retrieve(Flight &item)
{
    if (empty())
	{
	    return underflow;
	}
	item = front->entry;
    return success;
}

Error_code Queue::serve()
{
    if (empty())
	{
        return underflow;
	}
	Node *old_front = front;
    front = front->next;
    if (front==NULL)
	{
        rear = NULL;
	}
    delete old_front;
    return success;
}

Error_code Queue::append(const Flight &item)
{
    Node *new_rear = new Node(item);
    if (new_rear==NULL)
	{
	    return overflow;  // FULL
    }
    if (rear==NULL)
	{
	    front = rear = new_rear;
    }
    else
    {
        rear->next = new_rear;
        rear = new_rear;
    }
    return success;
}

Queue::Queue(const Queue &original)
{
    Node *new_copy, *original_node = original.front;

    if (original_node == NULL)
		front = rear = NULL;

    else
    {
        front = new_copy = new Node(original_node->entry);
        while (original_node->next != NULL)
        {
            original_node = original_node->next;
            new_copy->next = new Node(original_node->entry);
            new_copy = new_copy->next;
            rear = new_copy;
        }
    }
}

void Queue::operator=(const Queue &original)
{
    Node *new_front,*new_rear,*new_copy, *original_node = original.front;
    if (original_node == NULL)
		new_front = new_rear = NULL;
    else
    {
        new_copy = new_front = new_rear = new Node(original_node->entry);
        while (original_node->next != NULL)
        {
            original_node = original_node->next;
            new_copy->next = new Node(original_node->entry);
            new_copy = new_copy->next;
            new_rear = new_copy;
        }
    }
    while (!empty())
		serve();
    front = new_front;
    rear = new_rear;
}
