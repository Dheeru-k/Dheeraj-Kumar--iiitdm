//c++ program for implementation of operator overload
//cs20b1119'
//Dheeraj Kumar


#include<iostream>
using namespace std;

//declaring a struct for linked list
struct node
{
    int data;
    node *next;
};

//declaring a class for member functions

class Link_list
{
    private:
        node *tail, *head;			

        //function for checking memory
        bool isEmpty(node *)
        {
            if(head == NULL)
            {
                return true;
            }
            
            else
            return false;
        }


    public:
        //default constructor for head and tail for setting to NULL initially
        Link_list()
        {
            tail = NULL;
            head = NULL;
        }

        //function to add elements to the linked list
        void addNode(int n)
        {
            node *temporary = new node;
            temporary ->data = n;
            temporary ->next = NULL;

            //checking for space in list
            if(isEmpty(head))
            {
                head = temporary;
                tail = temporary;
            }
            else
            {
                tail ->next = temporary;
                tail = tail ->next;
            }
            
        }

        //displays function for the elements list
        static void displayData(node *head)
        {
            if(head == NULL)
            {
                cout << "  " << endl;
            }
            else
            {
                cout << head ->data << " ";
                displayData(head ->next);
            }
        }

        //function for returning the head pointer
        node *get_head()
        {
            return head;
        }

        //function to merge nodes using operator overload ---- ( + ) operator
        Link_list operator + (const Link_list &L)
        {
            Link_list var = *this;
            node *temporary = var.head;
            while(temporary->next != NULL)
            {
                temporary = temporary-> next;
            }
            temporary-> next = L.head;

            return var;
        }
       
       
       
        //function to swap elements of link list
        static void swap(node *s1, node *s2)
        {
            int temporary = s1 ->data;
            s1 ->data = s2 ->data;
            s2 ->data = temporary;
        }

        //function to merge link list using merge sort
        static void *merge(node *head)
        {
            int index;
            node *ptr;
            node *temporary = NULL;

            do
            {
                index = 0;
                ptr = head;
                while(ptr ->next != temporary)
                {
                    if(ptr ->data > ptr ->next ->data)
                    {
                        swap(ptr, ptr ->next);
                        index = 1;
                    }
                    ptr = ptr ->next;
                }
                temporary = ptr;
            }while(index);
            
            return 0;
        }
};

//main function begins
int main()
{
    
    Link_list L1, L2, L3;		// declaring class objects 
    int choice;

    while(1)
    {
        // menu visible to user
        cout << "\n 1.Add elements to list(IN SORTED ORDER)\n 2.Display elements of lists  \n 3.Merge and display result  \n 4.Exit  \n";
        cout << "\n Please Enter your choice \n";
        cin >> choice;
        switch(choice)
        {
            
            case 1:
                int num, number1, number2;
                cout << "\n press 1, to add in list 1 \n press 2, to add in list 2 \n";
                cin >> num ;
                switch(num)
                {
                    case 1:
                        cout <<"\n enter the element \n";
                        cin >> number1;
                        L1.addNode(number1);
                        break;

                    case 2:
                        cout <<"\n enter the element \n";
                        cin >> number2;
                        L2.addNode(number2);
                        break;
                }
                break;

            
            case 2:
                int num1;
                cout << "\n enter\n 1 to display list 1  \n 2 to display list 2 \n";
                cin >> num1;
                switch(num1)
                {
                    case 1:
                        cout << "\nLinked list 1 \n";
                        L1.displayData(L1.get_head());
                        break;

                    case 2:
                        cout << "\nLinked list 2 \n";
                        L2.displayData(L2.get_head());
                        break;
                }
                break;
            
            
            case 3:
                cout <<"\n	 Merging two Linked lists 		\n\n";
                Link_list::merge(L1.get_head());
                Link_list::merge(L2.get_head());
                L3 = L1 + L2;
                Link_list::merge(L3.get_head());
                Link_list::displayData(L3.get_head());
                break;

            
            case 4:
                exit(1);
                break;

            
            default:
                cerr << "\n\nwrong choice!, try again \n\n";
                break;
        }
    }
    return 0;
}
