//program to set TA details
//cs20b1119
//Dheeraj kumar

#include<iostream>
#include<string>
using namespace std;


template <typename k>   //template for class person
//class person 
class person
{
protected:
	 string name;
	 k roll_no ;
public:

	person (string Name , k roll) //parametrised constructor for person class
	{
		name = Name;
		roll_no = roll;
	}
	void display()    //printint name and roll number
	{
		cout<<"name of student is "<< name <<"\n";
		cout<<"roll number of student is "<< roll_no <<"\n";
	}
	

};
template <typename S>         //template for class student (all variable declared in person using template(k)
                              // ---used here as template S 
class student :  virtual protected person<S>
{
protected:
	string course1;         //declaring of courses
	string course2;
	string course3;
public:
	student(string m, S n , string C1 , string C2 , string C3) : person<S>(m , n) //parametrised constructor for student class
	{
		course1 = C1;
		course2 = C2;
		course3 = C3;
	}
	void display()
	{
	      person<S>::display();               ////printint name and roll number
		cout<<"course assigned to the student are : \n";      //printing courses
		cout<<course1<<"\n";
		cout<<course2<<"\n";
		cout<<course3<<"\n";
		
	}	 


};
template <typename R>                //template for class student (all variable declared in person using template(k)
                                    // ---used here as template R

class research_student : virtual protected person<R>
{
protected:
	string course1;         // declaring course assigned to research student
	string research_area;   //declaring research_area
public:	

	research_student( string m , R n , string C1 , string res_area) : person<R>(m , n)        //parametrised constructor for student class
	{
		course1 = C1;
		research_area = res_area ;
		
	}
	void display()
	{
		person<R>::display();         //printint name and roll number
		cout<<"course for the research student is : "<<course1<<" \n";          //printing course and research_area
		cout<<"area under research is : "<<research_area<<"\n";
	}
};

template <typename T>
class TA : protected student<T>  , protected research_student<T>        
{
protected:
	string course_assigned;
	string role;
	
public:
TA ( string m, T n, string C1 , string C2 , string C3, string courseAss, string rol) : student<T>(m ,n, C1 ,C2,C3 ) , person<T>(m , n) , research_student<T>(m , n ,"" , "")//parametrized constructor for TA class under student class
	{
		course_assigned = courseAss;
		role = rol ;
		
	}
	TA ( string m, T n, string C1 , string researchArea, string courseAss, string rol) : research_student<T>(m , n,C1 ,researchArea ) , person<T>(m , n) , student<T> (m , n, "", "", "")//parametrized constructor for TA class under research student class
	{
		course_assigned = courseAss;
		role = rol ;
		
	}
	void display()          //function to display all data option wise
	{
	      
	      int choice;

		
		cout<<"1. person\n"
		    <<"2. student(research student is hidden)\n"   
		    <<"3. Research Student(student is hidden)\n" 
		    <<"4. Teaching Assistant\n\n";
		cout<<"enter your choice\n";
		cin>>choice;
		switch (choice)
		{
		case 1:
		
		     person<T>::display();          //display person data
		     cout<<endl<<endl;
		      break;
		case 2:
		
		      student<T>::display();        //display student data
		      cout<<endl<<endl;
		      break;
		case 3:
		
		      research_student<T>::display();           // display research_student data
		      cout<<endl<<endl;
		      break;
		case 4:
		
		      person<T>::display();
		      cout<<endl<<endl;
		     	cout<<"course assigned for the teaching assistant is : "<<course_assigned<<" \n";
		      cout<<"Role of teaching assistant is : "<<role<<"\n";
		      break;
		default:
		      cout<<"enter correct choice!!";
		      break;
		}
	             
	}

};

int main ()
{

int choice;
string name,rollNumber2,sub1,sub2,sub3,assCourse,rolle,rCourse,rArea;
int rollNumber1;
//TA<int>A;
cout<<"welcome here\n\n";
                  cout<<"enter student name\t";   cin>>name;
                  cout<<"enter roll number\t";     cin>>rollNumber1;
                  cout<<"please confirm roll number\t";   cin>>rollNumber2;
                  cout<<"enter subjects for student\t";     cin>>sub1>>sub2>>sub3;
                   cout<<"enter course assigned to TA\t";   cin>>assCourse;
                   cout<<"enter role assigned to TA\t";   cin>>rolle;
                   cout<<"enter course assigned to research student\t";   cin>>rCourse;
                   cout<<"enter research area for research student\t";   cin>>rArea;
                    TA<int>A(name, rollNumber1 , sub1,sub2,sub3,assCourse,rolle);
                    TA <string>B(name,rollNumber2,rCourse,rArea,assCourse,rolle);
while (1)
{
      cout<<"1. Set TA Details\n"
            <<"2. Display\n"
            <<"3. Exit\n\n";
      cin>>choice;
      
      switch(choice)
      {
            case 1:
                 
                   cout<<"you already setted all the details\n";
                  
                   
                   break;
            case 2:
                  A.display();
                  B.display();
                  break;
            case 3:
                  exit(0);
                  break;
            default:
                  cout<<"enter correct choice !!";
                  
                   
                   
      }
            
}
	return 0;
}
