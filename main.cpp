#include <iostream>
#include <string>
#include <cmath>

class Person {
private:
    std::string p_name = "NoName";
    int         p_sex = 0; // 0 - female, 1 - male
    int         p_weight = 0;
public:
    Person() {}

    Person(std::string name, int sex, int weight) : p_name(name), p_sex(sex), p_weight(weight) {}

    void setName(std::string name) {
        p_name = name;
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
    Student() {}

    Student(std::string name, int sex, int weight, int year) : Person(name, sex, weight), s_year(year) {}

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

};

int main() {

    Person person("Katya", 0, 60);
    std::cout << person.getName() << " " << person.getSex() << " " << person.getWeight() << std::endl;

    person.setName("Vasya");
    person.setSex(1);
    person.setWeight(90);

    std::cout << person.getName() << " " << person.getSex() << " " << person.getWeight() << std::endl;

    Student student;
    student.setYear(4);
    student.incrementYear(-1);

    std::cout << student.getName() << " " << student.getSex() << " " << student.getWeight() << " " << student.getYear();


    return 0;
}
