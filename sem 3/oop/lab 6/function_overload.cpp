//program for function overload
//Dheeraj kumar
//cs20b1119

#include <iostream>

using namespace std;

// declaration of class for member function and member variables
class node
{
	private:			//declaration ov variable as private	
    		int data;
	    	node *next;				
	    	
	    	//function for checking memory
    		bool isEmpty(node *head)
    		{
        		if (head == NULL)
            			return true;
            			
        		else
            			return false;
    		}

	public:
    		// function to add node to a node at end
    		node *addNode(node *head, int value)
	    {
        		node *new_node = new node();
        		new_node->data = value;
        		new_node->next = NULL;

        		if (isEmpty(head))	//check for memory
        		{
        		    head = new_node;
        		}
        		else
        		{
        		    node *p1 = head; 		
        		    while (p1->next != NULL)
            		{
                		p1 = p1->next; 		// traverse end of node
            		}
            			p1->next = new_node; 		// link to newnode
        		}
        			return head;
        	}
// function to add node at specific position

    		node *addNode(node *head, int value, int position)
    		{
        		node *new_node = new node();
        		new_node->data = value;
        		new_node->next = NULL;
        		node *p1 = head;
        		node *p2 = head;
        		if (position == 1)
        		{
            			head = new_node;
            			head->next = p1;
        		}
        		else if (position > size(head) + 1 || position < 1)
        		{
            			cout << "		position is greater than the list size 		\n";
        		}
        		else
        		{
            			while (position != 1)
            		{
                		p2 = p1;
                		p1 = p1->next;
                		position--;
            		}
            			new_node->next = p1;
            			p2->next = new_node;
        		}

        		return head;
    	}
    
    //function to delete the node	
    int deleteNode(node **head)
    {
        node *current = *head;
        int k = current->data;
        node *previous = *head;
        if (*head == NULL)
        {
            cout << "		list is empty		\n";
            return -1;
        }
        else if (current->next == NULL)
        {
            cout << "		There is no such position		\n";
            return -1;
        }
        else
        {
            while (current->next != NULL)
            {
                previous = current;
                current = current->next;
            }
            current->next = NULL;
            delete current;
            current = NULL;
            previous->next = NULL;
        }
        return k;
    }
    
    //function to delete the node from specific position
        int deleteNode(node **head, int p)
    {
        node *current = *head;
        int k = current->data;
        node *previous = *head;
        if (*head == NULL)
        {
            cout << "		list is empty		\n";
            return -1;
        }
        else if (p > size(*head) || p < 1)
        {
            cout << "		position is greater than list size		\n";
            return -1;
        }
        if (p == 1)
        {
            *head = current->next;
            delete current;
            current = NULL;
            return -1;
        }
        else
        {
            while (p != 1)
            {
                previous = current;
                current = current->next;
                p--;
            }
            previous->next = current->next;
            delete current;
            current = NULL;
        }
        return k;
    }

    void displayData(node *head)
    {
    
        if (isEmpty(head))
        {
            cout << "		list is empty!			" << endl;
        }
        else
        {
            node *p1 = head;
            while (p1 != NULL)
            {
                cout << p1->data << " ";
                p1 = p1->next;
            }
            cout << endl;
        }
    }
    
    int size(node *head)
    {
        int count = 0;
        node *p1 = head;
        while (p1 != NULL)
        {
            count++;
            p1 = p1->next;
        }
        return count;
    }
    
};

// main function
//begins
int main()
{
    node *head = NULL;
    int choice, number, position;
    
    while (1)
    {
        cout << "1. insert at end\n2. insert at specific position\n3. delete at end\n4. delete at specific position\n5. display the List\n6. exit\n";
        cout << "Enter your choice  :  ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
        
            cout << "Enter the element  :  ";
            cin >> number;

            head = head->addNode(head, number);
            break;
            
        case 2:
        
            cout << "Enter the element  :  ";
            cin >> number;
            
            cout << "Enter the position  :  ";
            cin >> position;
            
            head = head->addNode(head, number, position);
            break;
            
        case 3:
        
            if (head->deleteNode(&head) == -1)
                cout << "\n";
                
            else
            {
                cout << "The deleted last element is  :  \n";
                cout << head->deleteNode(&head) << "\n";
            }
            break;
            
        case 4:
        
            cout << "Enter the position  :  ";
            cin >> position;
            if (head->deleteNode(&head, position) == -1)
                cout << "\n";
                
            else
            {
                cout << "The deleted element at " << position << " position is  :  \n";
                cout << head->deleteNode(&head, position);
            }
            break;
            
        case 5:
        
            head->displayData(head);
            break;
            
        case 6:
        
        	exit(1);
        	    
        default:
             cout<<"wrong choice , try again!!";
        }
    }
    
    
    // Deallocating the memory using delete keyword
    delete head;
    
   
    return 0;
}
