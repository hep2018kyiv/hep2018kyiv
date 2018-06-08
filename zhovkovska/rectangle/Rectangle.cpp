#include <iostream>
#include <fstream>
using namespace std;


class Rectangle
{
    private:
        int width, length;
    public:
//         Rectangle(int w, int l)
//         {
//             width = w;
//             length = l;
//         }
        Rectangle():
            width(0),
            length(0)
            {}
        
        Rectangle(int w, int l):
            width(w),
            length(l)
            {}
        
    int area()
    {
        return width*length;
    }
};