#include<iostream>
#include<string>
using namespace std;

class AbstractEmployee{
    virtual void askForPromotion()=0;
};

class Employee:AbstractEmployee{

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

    void work(){
        cout<< name + "is performing some tasks";
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
           cout<< getName() + "is performing coding.";
        }
};


class Teacher: public Employee{
    
    public:
        string subject;
        Teacher(string name, string company, int age, string subject):
        Employee(name, company, age)
        {
            this-> subject = subject;
        }
        
        void work(){
           cout<< getName() + "is teaching.";
        }
};

int main(){

    Developer dev = Developer("dev1", "company1", 21, "java");
    dev.work();
    Teacher teacher = Teacher("dev1", "company1", 21, "history");
    teacher.work();
    return 0;
}