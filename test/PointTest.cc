#include "../include/Point.h"
#include "PointTest.h"
#include <gtest/gtest.h>

TEST (PointPrintTest, TestPrint1){
    Point point = Point(10,1);
    string result = point.print();
    EXPECT_EQ(result, "(10, 1)");
}

TEST (PointPrintTest, TestPrint3){
    Point point = Point(11,1);
    string result = point.print();
    EXPECT_EQ(result, "(11, 1)");
}

TEST (PointGetX, Test_1){
    Point point = Point(10,1);
    int x = point.getX();
    EXPECT_EQ(x, 10);
}

bool PointTest::TestGetX(){
    Point point = Point(10,1);
    int x = point.getX();

    if (x != 10){
        cout << "Getting x failed" << endl;
        cout << "Expected 10 but received " << x << endl;
        return false;
    }

    return true;
}

bool PointTest::TestGetY(){
    Point point = Point(10,1);
    int y = point.getY();

    if (y != 1){
        cout << "Getting y failed" << endl;
        cout << "Expected 1 but received " << y << endl;
        return 0;
    }

    return true;
}

bool PointTest::TestSetX(){
    Point point = Point(10,1);
    point.setX(20);
    int x = point.getX();
    
    if (x != 20){
        cout << "Setting x failed" << endl;
        cout << "Expected 20 but received " << x << endl;
        return false;
    }

    return true;
}

bool PointTest::TestSetY(){
    Point point = Point(10,1);
    point.setY(20);
    int y = point.getY();

    if (y != 20){
        cout << "Setting x failed" << endl;
        cout << "Expected 20 but received " << y << endl;
        return false;
    }

    return true;
}

bool PointTest::TestCopyConstructor(){
    Point point = Point(10,1);
    Point newPoint = Point(point);

    if(point.getX() != newPoint.getX() || point.getY() != newPoint.getY()){
        cout << "Copy constructor failed" << endl;
        cout << "Expected " << point.print() << " but received " << newPoint.print() << endl;
        return false;
    } 

    return true;
}

bool PointTest::TestDistanceTo(){
    Point point1 = Point(10,1);
    Point point2 = Point(20, 1);
    Point point3 = Point(10, -11);
    Point point4 = Point(24, 1);

    double distance = point1.distanceTo(point2);

    if (point1.distanceTo(point2) != 10){
        cout << "Calculating Distance failed between " << point1.print() << " and " << point2.print() << endl;
        cout << "Expected 10 but received " << distance << endl;
        return false;
    }

    distance = point2.distanceTo(point3);

    if (abs(distance - 15.6205) > 0.0001){
        cout << "Calculating Distance failed between " << point2.print() << " and " << point3.print() << endl;
        cout << "Expected 15.6205 but received " << distance << endl;
        return false;
    }

    distance = point2.distanceTo(point4);

    if( distance != 4){
        cout << "Calculating Distance failed between " << point2.print() << " and " << point4.print() << endl;
        cout << "Expected 4 but received " << distance << endl;
        return false;
    }

    distance = point3.distanceTo(point4);

    if (abs(distance - 18.4391) > 0.0001){
        cout << "Calculating Distance failed between " << point3.print() << " and " << point4.print() << endl;
        cout << "Expected 18.4391 but received " << distance << endl;
        return false;
    }


    return true;

}

bool PointTest::TestAll(){


    cout << "All point class tests passed!" << endl;
    return true;

}