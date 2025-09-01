#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // pure virtual
};

class Circle : public Shape {
private:                      // ❗ draw() marked private here
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

class Rectangle : public Shape {
private:                      // ❗ draw() marked private here
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main(){

    /*
    Access control is checked at compile time against the type of the pointer/reference you are using.

        Shape* sees Shape::draw() (public) → ✅ allowed.

        Circle instance sees Circle::draw() (private) → ❌ not allowed.

        At runtime, the virtual dispatch (vtable) makes sure the correct implementation (Circle::draw) is called.
    */
    Shape* shape = new Circle();
    shape->draw();

    // Circle* c = new Circle();
    // c->draw();

    Shape* shape2 = new Rectangle();
    shape2->draw();


    // Now this is called abstraction because you can only access the Circle and Rectangle classes through the Shape class(Interface for other classes).
    return 0;
}