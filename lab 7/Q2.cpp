#include <iostream>
#include <cmath>
using namespace std;

class Shape{
	protected:
	int posX,posY;
	string colour;
	public:
		Shape(int x,int y,string c):posX(x),posY(y),colour(c){}
		
		virtual void draw()
		{
			cout<<"Drawing a shape\n";
		}
		virtual void calculateArea()
		{
			cout<<"Calculating area\n";
		}
		virtual void calculatePerimeter()
		{
			cout<<"Calculating perimeter\n";
		}
};

class Circle:public Shape{
	protected:
		float radius;
		int cpX,cpY;
	public:
		Circle(int x,int y,string c,float r,int cx,int cy):Shape(x,y,c),radius(r),cpX(cx),cpY(cy){}
		void draw() override
		{
			cout<<"Drawing a circle\n";
		}
		void calculateArea() override
		{
			float area=3.14*(radius*radius);
			cout<<"The area of the circle is "<<area<<endl;
		}
		void calculatePerimeter() override
		{
			float perimeter=2*3.14*radius;
			cout<<"The perimeter of the circle is "<<perimeter<<endl;
		}
};

class Rectangle:public Shape{
	protected:
		float width,height;
		int tlcX,tlcY;
	public:
		Rectangle(int x,int y,string c,float w,float h,int cx,int cy):Shape(x,y,c),width(w),height(h),tlcX(cx),tlcY(cy){}
		void draw() override
		{
			cout<<"Drawing a rectangle\n";
		}
		void calculateArea() override
		{
			float area=width*height;
			cout<<"The area of the Rectangle is "<<area<<endl;
		}
		void calculatePerimeter() override
		{
			float perimeter=2*(width+height);
			cout<<"The perimeter of the Rectangle is "<<perimeter<<endl;
		}
};

class Triangle:public Shape{
	protected:
		float height;
		int sA,sB,sC;
	public:
		Triangle(int x,int y,string col,float h,int a,int b,int c):Shape(x,y,col),height(h),sA(a),sB(b),sC(c){}
		
		void draw() override
		{
			cout<<"Drawing a triangle\n";
		}
		void calculateArea() override
		{
			float area=(sB*height)/2;
			cout<<"The area of the Triangle is "<<area<<endl;
		}
		void calculatePerimeter() override
		{
			float perimeter=sA+sB+sC;
			cout<<"The perimeter of the Triangle is "<<perimeter<<endl;
		}
};

class Polygon:public Shape{
	protected:
		int length;
		int sides;
	public:
		Polygon(int x,int y,string c,int l,int s):Shape(x,y,c),length(l),sides(s){}
		
		void draw() override
		{
			cout<<"Drawing a polygon\n";
		}
		void calculateArea() override
		{
			float area=(sides * length * length)/(4*tan(3.14/sides));
			cout<<"The area of the Polygon is "<<area<<endl;
		}
		void calculatePerimeter() override
		{
			float perimeter=length*sides;
			cout<<"The perimeter of the Polygon is "<<perimeter<<endl;
		}
};

int main() {
    Circle circle(0, 0, "Red", 5, 0, 0);
    Rectangle rectangle(1, 1, "Blue", 4, 6, 1, 1);
    Triangle triangle(2, 2, "Green", 5, 3, 4, 5);
    Polygon polygon(3, 3, "Yellow", 6, 5);

    cout << "Testing Circle:\n";
    circle.draw();
    circle.calculateArea();
    circle.calculatePerimeter();
    cout << endl;

    cout << "Testing Rectangle:\n";
    rectangle.draw();
    rectangle.calculateArea();
    rectangle.calculatePerimeter();
    cout << endl;

    cout << "Testing Triangle:\n";
    triangle.draw();
    triangle.calculateArea();
    triangle.calculatePerimeter();
    cout << endl;

    cout << "Testing Polygon:\n";
    polygon.draw();
    polygon.calculateArea();
    polygon.calculatePerimeter();
    cout << endl;
}

