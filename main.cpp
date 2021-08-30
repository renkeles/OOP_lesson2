#include <iostream>
#include <string>
#include <cmath>

class Person {
private:
    std::string p_name = "NoName";
    int         p_age = 0;
    int         p_sex = 0; // 0 - female, 1 - male
    int         p_weight = 0;
public:
    Person() {}

    Person(std::string name, int age, int sex, int weight) : p_name(name), p_age(age), p_sex(sex), p_weight(weight) {}

    void setName(std::string name) {
        p_name = name;
    }

    bool setAge(int age) {
        if (age > 0) {
            p_age = age;
            return true;
        }
        else {
            return false;
        }
    }

    bool setSex(int sex) {
        if (sex >= 0 && sex <= 1) {
            p_sex = sex;
            return true;
        }
        else return false;
    }
    bool setWeight(int weight) {
        if (weight > 0) {
            p_weight = weight;
            return true;
        }
        else return false;
    }

    std::string getName() {
        return p_name;
    }
    int getAge() {
        return p_age;
    }
    int getSex() const {
        return p_sex;
    }
    int getWeight() const {
        return p_weight;
    }

};

class Student : public Person {
private:
    int s_year = 1;
    static int s_count;
public:
    Student() {
        s_count++;
    }

    Student(std::string name, int age, int sex, int weight, int year) : Person(name, age, sex, weight), s_year(year) {
        s_count++;
    }

    ~Student() {
        s_count--;
    }

    void setYear(int year) {
        s_year = year;
    }

    bool incrementYear(int inc) {
        if (inc > 0) {
            for (int i = 0; i < inc; i++) {
                s_year++;
            }
            return true;
        }
        else if (inc < 0) {
            if (abs(inc) >= s_year) {
                s_year = 1;
                return true;
            }
            for (int i = 0; i < abs(inc); i++) {
                s_year--;
            }
            return true;
        }
        else {
            return false;
        }

    }

    int getYear() {
        return s_year;
    }

    int getCount() {
        return s_count;
    }

};

int Student::s_count = 0;

class Fruit{
private:
    std::string name;
    std::string color;
public:
    Fruit(std::string _color, std::string _name = "fruit") : color(_color), name(_name){}

    void setName(std::string _name){
        _name = name;
    }
    void setColor(std::string _color){
        _color = color;
    }
    std::string getName(){
        return name;
    };
    std::string getColor(){
        return color;
    }
};

class Apple : public Fruit{
public:
    Apple(std::string _color, std::string _name = "apple") : Fruit(_color, _name){}
};

class Banana : public Fruit{
public:
    Banana(std::string _color = "yellow", std::string _name = "banana") : Fruit(_color, _name){}
};

class GrannySmith : public Apple{
public:
    GrannySmith(std::string _color = "green", std::string _name = "Granny Smith apple") : Apple(_color, _name){}
};

void task1(){
    Student first;
    first.setYear(4);
    first.incrementYear(-1);

    std::cout   << first.getName()
                << " "
                << first.getAge()
                << " "
                << first.getSex()
                << " "
                << first.getWeight()
                << " "
                << first.getYear()
                << " "
                << first.getCount()
                << std::endl;

    Student second("Vasya", 23, 1, 90, 1);
    second.setYear(2);
    second.incrementYear(1);

    std::cout   << second.getName()
                << " "
                << second.getSex()
                << " "
                << second.getAge()
                << " "
                << second.getWeight()
                << " "
                << second.getYear()
                << " "
                << second.getCount()
                << std::endl;
}

void task2(){
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}

int main() {
    //task1();

    task2();

    return 0;
