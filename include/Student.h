//
// Created by andy on 17/08/18.
//

#ifndef TEST_STUDENT_H
#define TEST_STUDENT_H


#include<string>

class Student{
private:
    std::string name;
public:
    Student(std::string);
    virtual void display();
    std::string studentName();
};


#endif //TEST_STUDENT_H
