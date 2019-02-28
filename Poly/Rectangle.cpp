#include <iostream>

class Rectangle: public Shape{

	public:

		Rectangle(double width, double heigth){

			a = width;
			b = heigth;
		}

		void area(){
			std::cout << "Rectangle: " << (b*a) << std::endl;
		}

};
