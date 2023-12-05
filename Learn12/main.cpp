#include<iostream>

class Figure {
private:
    float x;
    float y;

public:
	Figure(float  x, float  y) : x(x), y(y) {}

    float  getX() const {
        return x;
    }

    float  getY() const {
        return y;
    }

};


class Rectangle : private Figure {
private:
    int width;
    int height;
public:
    Rectangle(float x, float y, float width, float height): Figure(x, y), width(width), height(height) {}
};



class Circle : public Figure {
private:
    int radius;
public:
    Circle(float x, float y, int radius): Figure(x, y), radius(radius) {}
};



class Square : private Rectangle {
public:
    Square(float x, float y, int width , int height ): Rectangle(x, y, width, height) {}
};



int main() {

}