#include<iostream>
#include<string>
using namespace std;

class AbstractEmployee{ //like an interface in c++
    virtual void askForPromotion()=0; // contract which the extending class has to implement.
};

class Employee:AbstractEmployee // extending AbstractEmployee.
{

//private by default
    string name;
    string company;
    int age;

public:
    Employee(string name, string company, int age){
        this -> name = name;
        this -> company = company;
        this -> age = age;
    }

    void introduce(){
        cout<<"name:"+name+",company-"+company+", age-"+ to_string(age)<<endl;
    }

    void askForPromotion(){
        cout<<"Employee:"+name+" asked for promotion"<<endl;
    }

    //virtual allows the child classes to have it's own implementation.
    virtual void work(){
        cout<< name + "is performing some tasks"<<endl;
    }

    string getName(){
        return name;
    }
};

class Developer: public Employee{
    public:
        string language;

        Developer(string name, string company, int age, string favLanguage):
            Employee(name, company, age){
                language = favLanguage;
            }
        
        void work(){
           cout<< getName() + " is coding."<<endl;
        }

};


class Teacher: public Employee{
    
    public:
        string subject;

        Teacher(string name, string company, int age, string subject):
        Employee(name, company, age) //kind of like super.
        {
            this-> subject = subject;
        }
        
        void work(){
           cout<< getName() + " is teaching."<<endl;
        }
};

// int main(){

//     Developer dev = Developer("dev1", "company1", 21, "java");
//     dev.work();
//     Teacher teacher = Teacher("dev1", "company1", 21, "history");
//     teacher.work();
    
//     cout<<endl;

//     Employee* e1 =  &dev;
//     e1 -> work();
//     Employee* e2 = &teacher;
//     e2 -> work();

//     return 0;
// }