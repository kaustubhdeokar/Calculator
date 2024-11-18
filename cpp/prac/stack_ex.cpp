#include <iostream>

using namespace std;


struct stack{
    int capacity[10];
    int amount;
    int top = 0;

    void add(int num){
        if(top < 10){
            capacity[top] = num;
            top++;
        }else{
            cout<<"Stack is full"<<endl;
        }
    }
    void remove(){
        if(top > 0){
            top--;
        }else{
            cout<<"Stack is empty"<<endl;
        }
    }
    int gettop(){
        if(top==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return capacity[top-1];
    }
};

int main(){

    stack s;

    for(int i=0;i<10;i++){
        s.add(i);
    }

    for(int i=0;i<12;i++){
        s.remove();
        cout<<s.gettop()<<endl;
    }


}