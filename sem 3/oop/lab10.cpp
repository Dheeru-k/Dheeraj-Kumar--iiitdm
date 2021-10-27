#include<iostream>

using namespace std;
#define size 100 


template <typename T>
class sorting
{


public:

	T arr[size];
	int n;
	T create ()
	{
	
	
	 	cout<<"\nenter no. of elements (	< 100	)	\n";
	 	cin>>n;
		
		try 
		{
			if( n > 100)
			{
				throw n;
			}
		}
		catch (...)
		{
			cout<<"\nsize insufficient\nexit successfully\n\n";
			return 0;
		}
		cout<<"\nenter elements\n";
		for(int i=0 ; i< n ; ++i)
		{
			cin>>arr[i];
		}
	}	
		
	void sort()
	{
		cout<<"\nsorting is in progress\n";
		for(int i=0; i<n-1 ; ++i)
		{
			for (int j=i+1 ;j< n ; ++j)
			{
				if(arr[j] < arr[i])
				{
					T temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}
		
		cout<<"\nsorted successfully\n";
	}
		
	void display()
	{
		cout<<"\nelement are sorted in ascending order\n";
	 	cout<<"\nthe sorted elements are here\n";
		for(int i=0 ; i< n ; ++i)
		{
			cout<<arr[i]<<" ";
		}
	

	}
};
int main()
{		

sorting <string>S;
sorting <int>I;
sorting <char>C;


int choice;
int a;

while(1)
{
	
	    cout<<"1. int\n"
	    <<"2. char\n"
	    <<"3. string\n"
	    <<"4. exit\n\n";
	    
	    cin>>choice;
	    cout<<"entered choice is : "<<choice<<endl;
	    
	    switch(choice)
	    {
	    	case 1:
	    		while(1)
	    		{
	    			cout<<"\n\n1. Get values\n"
				    <<"2. sort\n"
				    <<"3. display \n"
				    <<"4. exit\n";	
	    			    cin>>a;
	    			    
	    			    cout<<"entered choice is : "<<a<<endl;
	    			    
	    			    switch(a)
	    			    {
	    			    	case 1:
	    			    		 I.create();
	    			    		 break;
	    			    	case 2:
	    			    		I.sort();
	    			    		break;
	    			    	case 3:
	    			    		I.display();
	    			    		break;
	    			    	case 4:
	    			    		exit(0);
	    			    		break;
	    			    	default:
	    			    		cout<<"wrong choice !1 try again";
	    			    				 
	    			    	
	    			    }
	    			    
	    		}
	    		break;
	    	case 2:
	    		while(1)
	    		{
	    			cout<<"\n\n1. Get values\n"
				    <<"2. sort\n"
				    <<"3. display \n"
				    <<"4. exit\n";	
	    			    cin>>a;
	    			    cout<<"entered choice is : "<<a<<endl;
	    			    switch(a)
	    			    {
	    			    	case 1:
	    			    		 C.create();
	    			    		 break;
	    			    	case 2:
	    			    		C.sort();
	    			    		break;
	    			    	case 3:
	    			    		C.display();
	    			    		break;
	    			    	case 4:
	    			    		exit(0);
	    			    		break;
	    			    	default:
	    			    		cout<<"wrong choice !1 try again";
	    			    				 
	    			    	
	    			    }
	    			    
	    		}
	    		break;
	    	case 3:
	    		while(1)
	    		{
	    			cout<<"\n\n1. Get values\n"
				    <<"2. sort\n"
				    <<"3. display \n"
				    <<"4. exit\n";	
	    			    cin>>a;
	    			    cout<<"entered choice is : "<<a<<endl;
	    			    switch(a)
	    			    {
	    			    	case 1:
	    			    		 S.create();
	    			    		 break;
	    			    	case 2:
	    			    		S.sort();
	    			    		break;
	    			    	case 3:
	    			    		S.display();
	    			    		break;
	    			    	case 4:
	    			    		exit(0);
	    			    		break;
	    			    	default:
	    			    		cout<<"wrong choice !1 try again";
	    			    				 
	    			    	
	    			    }
	    			    
	    		}
	    		break;	
	    	case 4:
	    		exit(0);
	    		break;
	    	default:
	    		cout<<"try again !! enter correct choice\n";		
	    }	
}
return 0;
}
