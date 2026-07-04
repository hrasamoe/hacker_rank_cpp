#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Person{
    private:
        string name;
        int age;

    public:
        virtual void getdata(){
            cin >> name;
            cin >> age;
        }
        virtual void putdata()
        {
            cout << name  << " " << age << " ";
        }
        virtual ~Person() {}
};

class Professor: public Person {
    private:
        static int id;
        int publication = 0;

    public:
        void getdata() override{
            Person::getdata();
            cin >> publication;
        }
        void putdata() override {
            Person::putdata();
            id++;
            cout << publication << " " << id << endl;
        }
};
int Professor::id = 0;

class Student: public Person {
    private:
        static int id; 
        int marks[6];
        int sums  = 0;

    public:
        void getdata() override{
            Person::getdata();
            for (int i = 0; i < 6; i++)
            {
                cin >> marks[i];
                sums += marks[i];
            }
        }
        void putdata() override {
            Person::putdata();
            id++;
            cout << sums << " " << id << endl;
        }
};
int Student::id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++) 
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
