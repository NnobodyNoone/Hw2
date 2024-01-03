#include<iostream>
#include<cmath>

class Figure{
    public:
        virtual double area()=0;
        virtual double perimeter()=0;
};
class Triangle : public Figure{
    private:
        double side1,side2,side3;

    public:
        Triangle(double s1, double s2, double s3) : side1(s1),side2(s2),side3(s3){}

        double getSide1() const{ return side1;}
        double getSide2() const{ return side2;}
        double getSide3() const{ return side3;}

    virtual double area(){
        double s= (side1+side2+side3)/2;
        return sqrt(s*(s-side1)*(s-side2)*(s-side3));
    }
    virtual double perimeter(){
        return side1+side2+side3;
    }
};
class Rectangle: public Figure{
    private:
        double length,width;
    public:
        Rectangle(double l,double w): length(l),width(w){}
    
    double getLen() const{return length;}
    double getWidth() const{return width;}

    virtual double area(){
        return length*width;
    }
    virtual double perimeter(){
        return (length*2)+(width*2);
    }
};
class Circle: public Figure{
    private:
        double radius;
    public:
        Circle(double r): radius(r){}
    
    double getRadius() const{return radius;}

    virtual double area(){
        return 3.14*(radius*radius);
    }
    virtual double perimeter(){
        return 3.14*(2*radius);
    }
};

int main(){
    double a,b,c;
    std::cout << "Enter values for the first length:\n";
    std::cin >> a;
    std::cout << "Enter values for the second length:\n";
    std::cin >> b;
    std::cout << "Enter values for the third length:\n";
    std::cin >> c;
    Triangle t(a,b,c);
    std::cout << "Value of Area of Triangle: " << t.area() << std::endl;
    std::cout << "Value of Perimeter of Triangle: " << t.perimeter() << std::endl;

    double x,y;
    std::cout << "Enter values for length:\n";
    std::cin >> x;
    std::cout << "Enter values for width:\n";
    std::cin >> y;
    Rectangle rec(x,y);
    std::cout << "Value of Area of Rectangle: " << rec.area() << std::endl;
    std::cout << "Value of Perimeter of Rectangle: " << rec.perimeter() << std::endl;
    
    double z;
    std::cout << "Enter values for radius:\n";
    std::cin >> z;
    Circle cir(z);
    std::cout << "Value of Area of Circle: " << cir.area() << std::endl;
    std::cout << "Value of Perimeter of Circle: " << cir.perimeter() << std::endl;
    
}

