//Dheeraj kumar
//cs20b1119
//c++ program for multiple inheritance 

#include<iostream>
//#include<string>
using namespace std;

 //class employee for employee details 
class employee				
{
	protected:
		//declaring variables related to employee details
		int employee_id;
		string employee_name;
	public:
		//member function for creating the details
		void setData()
		{
			cout<<"enter employee id\n";
			cin>>employee_id;
			
			cout<<"enter employee name\n";
			cin>>employee_name;
		}	
	
}; 
//derived class contract under base class employee 
class contract: protected employee
{
	protected:
		double pay_hourly;
	public:
	//member function to set the hourly pay
		void setPay()
		{
			cout<<"enter the salary to be paid hourly\n";
			cin>>pay_hourly;
		}
	//member function to print the hourly of employee
		void getPay()
		{
			cout<<"houtly pay for intern is is $"<<pay_hourly<<endl<<endl;
		}	
	
};

class salaried : protected employee
{
	protected:
		double pay_monthly;
	public:
	//memner function to set the pay for the employee paid monthly
		void setPay()
		{
			cout<<"enter the salary to be paid monthly\n";
			cin>>pay_monthly;
		}
	//member function to print the monthly pay of the employee	
		void getPay()
		{
			cout<<"monthly salary for manager is $"<<pay_monthly<<endl<<endl;
		}
};

class manager : private salaried
{
	public:
	//member function to update the details of employee
		void setDetails()
		{
		//calling set data function g-from class employee
			setData();
			cout<<"enter the salary to be paid monthly\n";
			cin>>pay_monthly;
			cout<<endl<<endl;
			cout<<"updated successfully \n\n\n";
		}
		//getting details for the employee
		void getDetails()
		{
			cout<<"ID of the employee is : "<<employee_id<<endl<<endl;
			cout<<employee_name<<" is employe for this company as manager\n\n";
			cout<<"employee is having salary  $"<<pay_monthly<<endl<<endl<<endl;
			
		}
		//member function to calculate total salary of the employee
		void calculateSalary()
		{
			int months , total;
			cout<<"enter the number of months\n";
			cin>>months;
			
			total = months*pay_monthly;
			cout<<"total salary for "<<months<< " months is $"<<total<<endl<<endl<<endl;
		}
		//updating the pay for manager
		void setSalary()
		{
			cout<<"enter the salary to be updated\n";
			cin>>pay_monthly;
			cout<<"updated successfully \n\n\n";
		}
	
	
};

class intern : private contract
{
	public:
	//member function to update the details of employee
		void setDetails()
		{
			//calling set data function g-from class employee
			setData();
			cout<<"enter the salary to be paid monthly\n";
			cin>>pay_hourly;
			cout<<endl<<endll;
			cout<<"updated successfully \n\n\n";
		}
		//getting details for the employee
		void getDetails()
		{
			cout<<"ID of the employee is : "<<employee_id<<endl<<endl<<endl;
			cout<<employee_name<<" is employe for this company as manager\n\n";
			cout<<"employee is having salary  $"<<pay_hourly<<endl<<endl<<endl;
		}
		//member function to calculate total salary of the employee
		void calculateSalary()
		{
			int hours , total;
			cout<<"enter the number of months\n";
			cin>>hours;
			
			total = hours*pay_hourly;
			cout<<"total salary for "<<hours<< " hours is $"<<total<<endl<<endl<<endl;
		}
		//updating the pay for intern 
		void setSalary()
		{
			cout<<"enter the salary to be updated\n\n";
			cin>>pay_hourly;
			cout<<"updated successfully \n\n\n";
		}
};

int main()

{	int n ,m, index,a ,  choice , i = 0 , ids;
	cout<<"enter maximum number of employes as manager \n";
	cin>>m;
	cout<<"enter maximum number of employees as intern \n";
	cin>>n;	
	manager manager[m];
	intern intern[n];
	
while(1)
{
	cout<<"1. create employee \n2. update employee \n3. print employee details \n4. update pay \n5.calculate salary \n6. exit \n";
	
	cout<<"enter choice\n";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			
			cout<<"1. manager \n2.intern \n";
			cin>>a;
			cout<<"enter the index number of employee\n\n";
			cin>>index;
			if(a ==1)
			{
				cout<<"enter the information of "<< index << "th employee"<<endl<<endl;
				
						manager[index].setDetails();
						break;
			}
			
			if(a == 2)
			{
				cout<<"enter the information of "<< index << "th employee"<<endl<<endl;
				
						intern[index].setDetails();
						break;
			}	
		case 2:
			cout<<"1. manager \n2.intern \n";
			cin>>a;
			
			if(a = 1)
			{
			
			cout<<"enter the index number of employee to update datails\n\n ";
			cin>>index;
			
			if(index < 0)
			{
			cout<<"index must be greater than 0 \n\n\n";
			break;
			}
			
			if(index > m )
			{
			cout<<"index must be less than number of employee as manager\n\n\n";
			break;
			}
			
			else 
			{
				
				cout<<"enter the new employee details"<<endl;
				
						manager[index].setDetails();
						break;
			}
			}
			
			if(a = 2)
			{
			
			cout<<"enter the index number of employee to update datails\n\n ";
			cin>>index;
			
			if(index < 0)
			{
			cout<<"index must be greater than 0\n\n\n";
			break;
			}
			
			if(index > n )
			{
			cout<<"index must be less than number of employee as intern\n\n\n";
			break;
			}
			
			else
			{
				
				cout<<"enter the new employee details"<<endl;
				
						intern[index].setDetails();
						break;
			}
			}
			
			
			
			
			
		case 3:
			cout<<"1. manager \n2.intern \n";
			cin>>a;
			if(a = 1)
			{
			
			cout<<"enter the index number of employee to print datails\n\n ";
			cin>>index;
			
			if(index < 0)
			cout<<"index must be greater than 0 \n\n\n";
			
			if(index > m )
			cout<<"index must be less than number of employee as manager\n\n\n";
			
			else 
			{
				
				cout<<"enter the new employee details"<<endl;
				
						manager[index].getDetails();
						break;
			}
			}
			
			if(a = 2)
			{
			
			cout<<"enter the index number of employee to update datails\n\n ";
			cin>>index;
			
			if(index < 0)
			{
			cout<<"index must be greater than 0\n\n\n";
			break;
			}
			
			if(index > n )
			{
			cout<<"index must be less than number of employee as intern\n\n\n";
			break;
			}
			
			else
			{
				
				cout<<"enter the new employee details"<<endl;
				
						intern[index].getDetails();
						break;
			}
			}
			
		case 4:
			cout<<"1. manager \n2.intern \n";
			cin>>a;
			
			if(a = 1)
			{
			
			cout<<"enter the index number of employee to update monthly pay\n\n ";
			cin>>index;
			
			if(index < 0)
			{
			cout<<"index must be greater than 0\n\n\n";
			break;
			}
			
			if(index > m )
			{
			cout<<"index must be less than number of employee as manager\n\n\n";
			break;
			}
			
			else 
			{
				
				cout<<"enter the new employee details"<<endl;
				
						manager[index].setSalary();
						break;
			}
			}
			
			if(a = 2)
			{
			
			cout<<"enter the index number of employee to update hourly pay\n\n ";
			cin>>index;
			
			if(index < 0)
			{
			cout<<"index must be greater than 0\n\n\n";
			break;
			}
			
			if(index > n )
			{
			cout<<"index must be less than number of employee as intern\n\n\n";
			break;
			}
			else
			{
				
				cout<<"enter the new employee details"<<endl;
				
						intern[index].setSalary();
						break;
			}
			}
		case 5:
			cout<<"1. manager \n2.intern \n";
			cin>>a;
			if(a = 1)
			{
			
			cout<<"enter the index number of employee to calculate salary\n\n ";
			cin>>index;
			
			if(index < 0)
			{
			cout<<"index must be greater than 0\n\n\n";
			break;
			}
			
			if(index > m )
			{
			cout<<"index must be less than number of employee as manager\n\n\n";
			break;
			}
			else 
			{
				
				
				
						manager[index].calculateSalary();
						break;
			}
			}
			
			if(a = 2)
			{
			
			cout<<"enter the index number of employee to calculate salary\n\n ";
			cin>>index;
			
			if(index < 0)
			{
			cout<<"index must be greater than 0\n\n\n";
			break;
			}
			
			if(index > n )
			{
			cout<<"index must be less than number of employee as intern\n\n\n";
			break;
			}
			
			else
			{
				
				
						intern[index].calculateSalary();
						break;
			}
			}
		case 6:
			exit (1);
		default:
			cout<<"enter correct choice.....try again !!";		
			
	
	}
	
}	
return 0;
}

