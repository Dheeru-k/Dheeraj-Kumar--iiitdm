//cs20b1119
//dheeraj
//menu driven program for queue 
#include "queue"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int
main ()
{
  queue Que;
  int
    choice,
    number;
  while (1)
    {
      cout <<
	"\n 1.Add to print queue \n 2.current job \n 3.execute a job\n 4.display job\n 5.exit";
      cout << "\nEnter your choice:";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  cout << "Enter job id in integer:\n";
	  cin >> number;
	  Que.enqueue (number);
	  break;
	case 2:
	  number = Que.peak ();
	  cout << "current job is :" << number << endl;
	  break;
	case 3:
	  number = Que.dequeue ();
	  if (number == -1)
	    {
	      cout << "\nThe queue is empty\n";
	    }
	  else
	    {
	      cout << "\nThe executed job is:" << number << endl;
	    }
	  break;

	case 4:
	  Que.display ();
	  break;
	case 5:
	  exit (1);
	default:
	  cout << "\nWrong choice, try again!\n";
	}
    }
  return 1;
}
