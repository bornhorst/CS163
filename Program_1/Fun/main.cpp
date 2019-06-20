//functions


#include <iostream>
using namespace std;

int volume_sphere(int radius);

int main()
{
int rad = 0;
cout<<"Enter the radius of the circle: ";
cin>>rad;
cout<<endl;

int number = volume_sphere(rad);

cout<<endl<<number<<endl;





return 0;
}

int volume_sphere(int radius)
{

int vol = 3.14*radius*radius*radius;

return vol;
}
