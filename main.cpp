#include <iostream>
#include <string>

class Person{
private:
    std::string p_name =   "NoName";
    int         p_sex =    0; // 0 - female, 1 - male
    int         p_weight = 0;
public:

    Person(std::string name, int sex, int weight) : p_name(name), p_sex(sex), p_weight(weight){}

    void setName(std::string name){
        p_name = name;
    }
    bool setSex(int sex){
        if(sex >= 0 && sex <= 1){
            p_sex = sex;
            return true;
        }else return false;
    }
    bool setWeight(int weight){
        if(weight > 0){
            p_weight = weight;
            return true;
        }else return false;
    }

    std::string getName(){
        return p_name;
    }
    int getSex() const{
        return p_sex;
    }
    int getWeight() const{
        return p_weight;
    }

};

class Student : public Person{
private:
    int s_year = 1;
public:
    Student(std::string name, int sex, int weight, int year) : Person(name, sex, weight), s_year(year){

    }
    
};

int main(){

    Person person("Katya", 0, 60);
    std::cout << person.getName() << " " << person.getSex() << " " << person.getWeight() << std::endl;

    person.setName("Vasya");
    person.setSex(1);
    person.setWeight(90);

    std::cout << person.getName() << " " << person.getSex() << " " << person.getWeight() << std::endl;

    return 0;
}
