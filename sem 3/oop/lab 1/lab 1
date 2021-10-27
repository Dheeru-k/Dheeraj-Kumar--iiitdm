//cs20b1119
//Dheeraj kumar
//program to implemented queue ;

#include <iostream>
#define size 5
using std::cout;
using std::endl;

//CLASS definition for Queue ADT
class queue
{

private:
  int front;
  int rear;
  int array[size];
public:
  void isEmpty ();
  void isFull ();
  void enqueue (int);
  int dequeue ();
  void display ();
  int peak ();
    queue ()
  {
    front = -1;
    rear = -1;
  }


};
//funtion to check for queue is empty
void
queue::isEmpty ()
{
  if (front == -1)
    {
      cout << "queue is empty" << endl;
    }
}

//funtion to check for queue is full
void
queue::isFull ()
{
  if (rear == (size - 1))
    {
      cout << "queue is full" << endl;
      exit;
    }
}

//function to enqueue an element into an queue
void
queue::enqueue (int number)
{
  if (rear == (size - 1))
    {
      isFull ();
    }
  else
    {
      if (front == -1)
	{
	  front = 0;
	}
      rear = rear + 1;
      array[rear] = number;

    }

}

//function to display the element of queue
void
queue::display ()
{
  int i = front;
  if (front == -1)
    {
      cout << "queue is empty" << endl;
    }
  else
    {
      for (i = front; i <= rear; i++)
	{
	  cout << array[i] << endl;
	}
    }
}

//function for peak element of an array
int
queue::peak ()
{
  isEmpty ();
  int temp = array[front];
  return temp;
}

//function to dequeue an element into an queue
int
queue::dequeue ()
{
  isEmpty ();

  if (front == rear)
    {
      front = -1;
      rear = -1;
    }
  else
    {
      int temp = array[front];
      front = front + 1;
      return temp;
    }
}
