#include <iostream>
#include <fstream>
#include <cmath>
// #include "Rectangle.cpp"
using namespace std;
// template <typename myType=float>

class Rectangle
{
    private:
        float width, length;
    public:
        
        Rectangle():
            width(0),
            length(0)
            {}
        
        Rectangle(float w, float l):
            width(w),
            length(l)
            {}

        Rectangle(float area):
            width(std::sqrt(area)),
            length(std::sqrt(area))
            {}
            
        float area()
        {
            return width*length;
        }
        
        float sideLehgth()
        {
            return width;
        }
};

int main()
{
    Rectangle rect;
    cout<<rect.area()<<endl;
    Rectangle rect1(5);
    cout<<rect1.area()<<endl;
    cout<<rect1.sideLehgth()<<endl;
    Rectangle rect2(5, 7);
    cout<<rect2.area()<<endl;
    
}