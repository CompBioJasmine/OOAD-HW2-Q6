#include <iostream>

using namespace std;

class Shape {
 public:
  Shape () {
  }
  Shape (int a) {
    area = a;
  }
  int get_area() {
    return area;
  }
  virtual void display() {
    display();
  }
  
 protected:
  int area;

};

class Circle: public Shape {
 public:
  Circle (int a, int r) {
    area = a;
    radius = r;
  }
  int get_radius() {
    return radius;
  }
  virtual void display() {
    printf("Shape Type: Circle, Area: %d, Radius: %d\n",area,radius);
  }
 private:
  int radius;
};

class Triangle: public Shape {
 public:
  Triangle (int a, int p, int an) {
    area = a;
    perimeter = p;
    angles = an;
  }
  int get_total_perimeter() {
    return perimeter;
  }
  int get_angle_degrees_total() {
    return angles;
  }
  virtual void display() {
    printf("Shape Type: Triangle, Area: %d, Perimeter: %d, Angle Degrees: %d\n",area,perimeter,angles);
  }
 private:
  int perimeter;
  int angles;
};

class Square: public Shape {
 public:
  Square (int a, int p) {
    area = a;
    perimeter = p;
  }
  int get_total_perimeter() {
    return perimeter;
  }
  void display() {
    printf("Shape Type: Square, Area: %d, Perimeter: %d\n",area,perimeter);
  }
 private:
  int perimeter;
};

int main(void) {
  Shape* shape1 = new Circle(30.0,5.0); //not checking that these are possible values
  Shape* shape2 = new Triangle(25.0,7.0,180);
  Shape* shape3 = new Square(9.0,12.0);

  Shape* shapes[] = {shape1,shape2,shape3};

    for(int i=0; i<3; i++){
      for(int j=0; j<3-i-1; j++){
	if (shapes[j]->get_area() < shapes[j+1]->get_area()) {
	  Shape* temp = shapes[j];
	  shapes[j] = shapes[j+1];
	  shapes[j+1] = temp;
	}
      }

    for(int i=0; i<3; i++){
      shapes[i]->display();
    }

    return 0;
  
}
}
