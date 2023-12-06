#include<iostream>

using namespace std;

class Figure {
private:
    double x;
    double y;

public:
	Figure(double  x, double  y) : x(x), y(y) {}

    double  getX() const {
        return x;
    }

    double  getY() const {
        return y;
    }

    virtual void getSquare() = 0;

    virtual ~Figure() = default;
};


class Rectangle : public Figure {
private:
    int width;
    int height;
public:
    Rectangle(double x, double y, int width, int height): Figure(x, y), width(width), height(height) {}

    void getSquare() override {
        cout << "Square for Rectangle " << width * height << endl;
    }

    void getPerimeter() {
        cout << "Perimeter for Rectangle " << 2 * (width + height) << endl;
    }
};



class Circle : public Figure {
private:
    int radius;
public:
    Circle(double x, double y, int radius): Figure(x, y), radius(radius) {}

    void getSquare() override {
        cout << "Square for circle " << (2 * radius) * 3.14 << endl;
    }

    void getPerimeter()  {
        cout << "Perimetr for circle " << 2 * 3.14 * radius << endl;
    }
};



class Square : public Rectangle {
public:
    Square(double x, double y, int size  ): Rectangle(x, y, size, size) {}

    
};



int main() {
    Rectangle rectangle(1.0, 2.0, 3.0, 4.0);
    Circle circle(5.0, 6.0, 2.5);
    Square square(8.0, 9.0, 3.0);

    cout << "Rectangle Coordinates: " << rectangle.getX() << ", " << rectangle.getY()<< endl;
    rectangle.getSquare();
    rectangle.getPerimeter();

    cout << "Circle Coordinates: " << circle.getX() << ", " << circle.getY() << endl;
    circle.getSquare();
    circle.getPerimeter();

    cout << "Square Coordinates: " << square.getX() << ", " << square.getY() << endl;
    square.getSquare();
    square.getPerimeter();

    unique_ptr<Figure> rectangle_p(make_unique<Rectangle>(10.0, 11.0, 5, 6));

    Rectangle* castRectangle = dynamic_cast<Rectangle*>(rectangle_p.get());
    if (castRectangle) {
        cout << "New Rectangle coordinate: " << castRectangle->getX() << ", " << castRectangle->getY() << endl;
        castRectangle->getSquare();
        castRectangle->getPerimeter();
    }
    else {
        cout << "You dont have perimeter" << endl;
    }
        
    delete castRectangle;

 
    return 0; 
}