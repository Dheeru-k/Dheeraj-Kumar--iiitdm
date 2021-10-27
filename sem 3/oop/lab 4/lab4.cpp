//program to calculate area and volume
//cs20b1119
//dheeraj kumar

#include<iostream>

using namespace std;
#define pi 3.14

//declared and defined class

class area{
	private:
		float length=1, breadth=1, radius=1;  	//declared variables of area class
	public:
		
		 void getRectdata()			//function for taking input from user
		 {
		 	
		 	cout<<"enter length and breadth"<<endl;
		 	cin>>length>>breadth;
		 }
		 void getCircledata()
		 {
		 	cout<<"enter RADIUS"<<endl;
		 	cin>>radius;
		 }
		friend float areaRectangle(area R);   //declared frien functions
		friend float areaCircle(area C);
		friend class volume;  
		
		
};
//defined friend function declared above for area

inline float areaRectangle(area R)
{
	 return R.length*R.breadth;	 
}



inline float areaCircle(area C)
{
	return C.radius*C.radius*pi;
}


////declared and defined class
class volume{
	private:
		float length=1, breadth=1, height=1, radius=1;		///declared variables of area class
	public:
	int x,z;
		void getCuboiddata()
		 {
		 	cout<<"enter length and breadth and height"<<endl;
		 	cin>>length>>breadth>>height;
		 }
		 void getSpheredata()			////function for taking input from user
		 {
		 	cout<<"enter radius\n";
		 	cin>>radius;
		 }
		// function to calculate volume of circle
		inline float volumeSphere()
		{	
			
			return (radius*radius*radius*pi*4)/3  ; 
			
		}
		
		// function for calculating volume to cuboid
	 	inline float volumeCuboid()
	 	{
	 		return height*breadth*length;
	 	}
	 	//function for comparing volume
	 	int compareCuboid(volume a, volume b)
	 	{
	 		if(a.volumeCuboid() > b.volumeCuboid())
	 		{	
	 			 z=a.volumeCuboid();
	 			return this->z;
	 		}
	 		else
	 		{
	 			 x=b.volumeCuboid();
	 			return this->x;
	 			}
	 	}
	 	float compareSphere(volume a, volume b)
	 	{
	 		if(a.volumeSphere() > b.volumeSphere())
	 		{
	 			z=a.volumeSphere();
	 			return this->z;
	 		}
	 		else
	 		{
	 			x=b.volumeSphere();
	 			return this->x;
	 		} 
	 	}
	 	
	 	
		
};

		

//   main function begins here
int main()
{
area A;
volume V , V1;
V.volumeSphere();


int choice;

while(1)
{
	cout<<"\n 1. unit area of rectangle\n 2. Area of Rectangle\n 3. unit area of circle\n 4. area of circle\n 5. unit volume of cuboid\n 6.volume of cuboid\n 7. unit volume of sphere\n 8. volume of sphere\n 9. compare volume of two cuboids\n 10. compare volume of two spheres options.\n 11. quit\n"<<endl;
	
	cout<<"enter choice\n";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"unit area of rectangle is  :  "<<areaRectangle(A)<<" m^2"<<endl<<endl;
			break;
		case 2:
			A.getRectdata();
			cout<<"Area of Rectangle  :  "<<areaRectangle(A)<<" m^2"<<endl<<endl;
			break;
		case 3:
			cout<<"unit area of circle is  :  "<<areaCircle(A)<<" m^2"<<endl<<endl;
			break;
		case 4:
			A.getCircledata();
			cout<<"area of circle is  :  "<<areaCircle(A)<<" m^2"<<endl<<endl;
			break;
		case 5:
			cout<<"unit volume of cuboid is  :  "<<V.volumeCuboid()<<" m^3"<<endl<<endl;
			break;
		case 6:
			V.getCuboiddata();
			cout<<"volume of cuboid is  :  "<<V.volumeCuboid()<<" m^3"<<endl<<endl;
			break;
		case 7:
			cout<<"unit volume of sphere is  :  "<<V.volumeSphere()<<" m^3"<<endl<<endl;
			break;
		case 8:
			V.getSpheredata();
			cout<<"volume of sphere is  :  "<<V.volumeSphere()<<" m^3"<<endl<<endl;
			break;
		case 9:
			cout<<"enter dimensions of first cuboid\n";
			V.getCuboiddata();
			cout<<"enter dimensions of second cuboid\n";
			 V1.getCuboiddata();
			cout<<"bigger one is  :  "<<V.compareCuboid(V , V1)<<" m^3"<<endl<<endl;
			break;
		case 10:
			cout<<"enter radius of first sphere\n";
			V.getSpheredata();
			cout<<"enter radius of second sphere\n";
			 V1.getSpheredata();
			cout<<"bigger one is  :  "<<V.compareSphere(V , V1)<<" m^3"<<endl<<endl;
			break;
		case 11:
			exit (1);
		default:
			cout<<"wrong choice ! try again\n";		
				
				
				
							
	}
}

return 0;
}








































