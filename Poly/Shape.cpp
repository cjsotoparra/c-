#include <iostream>

class Shape {
	protected:
		double a, b;

	public:

		virtual void area() = 0;
};//Shape

class Rectangle: public Shape{
public:
	Rectangle(double width, double height){

		a = width;
		b = height;
	}

	void area(){

		std::cout << "Rectangle :" << a*b << std::endl;
	}

};//Rectangle

class Ellipse: public Shape{
public:
	Ellipse(double bigRadius, double smallRadius){

		a = bigRadius;
		b = smallRadius;
	}

	void area(){

		std::cout << "Ellipse: " << a*b*3.14 << std::endl;
	}

};

int main(){

	Rectangle rec(10.5, 7.0);
	rec.area();

	Ellipse el(10.5, 7.0);
	el.area();

	return 0;

}
