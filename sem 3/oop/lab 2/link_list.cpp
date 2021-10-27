//Dheeraj kumar
//cs20b1119
//program to merge to link list

#include <iostream>
using namespace std;

//declaration of class
class node
{
private:
	int number;
	node *next;

public:
	//function to create link list........
	node *create(int num, node *head)
	{
		if (head == NULL)
		{
			head = new node();
			head->number = num;
			head->next = NULL;
			return head;
		}
		else
		{
			node *temp = head;
			int p = 1;
			while (p == 1)
			{
				if (temp->next == NULL)
				{
					temp->next = new node();
					temp = temp->next;
					temp->number = num;
					temp->next = NULL;
					p = 0;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
		return head;
	}
	// function to delete nodes from linked list.........
node*  delNode(node *head,int num)
{
    if(head==NULL)	//checking memory
    {
        cout<<"List is Empty.\n";
        return head;
    } 

    else if(head->next==NULL)
    {
        if(num==1)
        {
            head=NULL;
            return head;
        }
        else
        {
            cout<<"The node is not in the list.\n";
            return head;
        }
    } 
    else if(num==1)
    {
        head=head->next;
        return head;
    }
    else
    {
        node * temp = head;
        node * tempDel=NULL;
        int i=1;
        while(head->next!=NULL && i<=num)
        {
             cout<<"The node .\n"; 
            if(i==num-1)
            tempDel=head;
            head = head->next;
             ++i;
            

        }
        if(i<num)
        {
            cout<<"The node is not in the list.\n";
        }
        else
        {
            cout<<"The node deleted.\n";
            tempDel->next=tempDel->next->next;
        }
    } 
}


// function to display all list present here
	void display(node *head)
	{
		node *x = head;
		cout << "Head :";
		while (x != NULL)
		{
			cout << x->number << " ->";
			x = x->next;
		}
		cout << "NULL" << endl;
	}
	
	//for merging the lists
	node *mergeList(node *temp_fir, node *temp_sec)
	{
		node * final = NULL;
		if (temp_fir == NULL)
		{
			return temp_sec;
		}
		if (temp_sec == NULL)
		{
			return temp_fir;
		}
		if (temp_fir->number < temp_sec->number)
		{
			 final = temp_fir;
			 final->next = mergeList(temp_fir->next, temp_sec);
		}
		else
		{
			 final = temp_sec;
			 final->next = mergeList(temp_fir, temp_sec->next);
		}
		return  final;
	}
};



int main()
{
	node *head1 = NULL, *head2 = NULL, *merge_head = NULL;
	int choice, s, j, n;
	cout << "1.INSERT TO LIST\n2.DELETE FROM LIST\n3.DISPLAY THE LIST\n4.MERGE TWO LIST\n5.EXIT\n";
	
	
	while (1)
	{
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter list number(1 or 2): ";
			cin >>  s;
			cout << "Enter total no. of element to be inserted: ";
			cin >> n;
			if ( s == 1)
			{
				for (int i = 0; i < n;  ++i)
				{
					cout << "Enter the elements : ";
					cin >> j;
					head1 = head1->create(j, head1);
				}
			}
			else if ( s == 2)
			{
				for (int i = 0; i < n;  ++i)
				{
					cout << "Enter the elements : ";
					cin >> j;
					head2 = head2->create(j, head2);
				}
			}
			else
			{
				cout << "CHOOSEN LIST IS INVALID \n";
			}
			break;
		case 2:
		       cout<<"enter list no. delete(1=list 1 or any other for list 2)"<<endl;
		      int num,k;
		      cin>>num;
		       if(num = 1)
		      {    
		       	cout<<"enter the node to delete"<<endl;
		                cin>>k;
		                head1->delNode(head1, k);
		                merge_head->delNode(merge_head, k);
		      }
		      else
		      {                 
		             cout<<"enter the node to delete"<<endl;
		               cin>>k;
		               head2->delNode(head2, k);
				merge_head->delNode(merge_head, k);
		      }
		
			break;
		case 3:
		  
			head1->display(head1);
			head2->display(head2);
			merge_head->display(merge_head);
			
		case 4:
			merge_head = merge_head->mergeList(head1, head2);
			head1 = head2 = NULL;
			cout << "Merged successfully\n";
			break;
		case 5:
			exit(1);
			break;
		default:
			cout << "incorrect input ! try again...   \n";
			break;
		}
	}
	return 0;
}
