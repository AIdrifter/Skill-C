/*********************************************************************************
**
**  OOP concepts in C++
**  Object Oriented Programming
**  http://www.byte-notes.com/oop-concepts-c
**  http://www.alexonlinux.com/how-inheritance-encapsulation-and-polymorphism-work-in-cpp
**  The OOP language is divided into four major concepts.
**
**     Main:
**       1.Encapsulation
**              ---->class----->overloading
**       2.Inheritance
**              ---->virtual & Abstraction function  ----> overwrite or owerride
**       3.Polymorphism
**
**
**     Others:
**       1.Abstraction
**       2.Data Hiding
**       3.Dynamic Binding
**
***********************************************************************************/

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


// -------------[Abstraction]------------------------
// 1.通常是proerty (static
//  ex string name: 動物的名子
// 2.virtual function
//   identidy() ex:動物吼叫之類的，
//
class Animal {
public:
    // defulat constructor
    Animal()
    {
        cout<<"Animal constructor"<<endl;
        aPtr = new int;
        *aPtr = 0;
    }

    // copy constructor
    Animal(string input_name)
    {
        cout<<"Animal copy constructor"<<endl;
        name=input_name;
    }

    // destructor  -- see blow for whether it's virtual
    ~Animal()
    {
        cout<<"Anima destructor"<<endl;

        if(aPtr!=NULL){
            cout<<"delete aPtr"<<endl;
            delete aPtr;
        }
    }

    // object method(dynamic
    void Animal_number_add()
    {
        cout<<"Animal Animal_number_add"<<endl;
        *aPtr++;
        cout << *aPtr << endl;
    }

    //virtual void identify()=0;
    virtual void identify()
    {
        cout << "Animal virtual identify" << endl;
    }

protected:
    // object property(static
    string name;

private:
    int *aPtr=NULL;

};


// -------------[inherantance]------------------------
// 1.Don't rewrite animal behavior
// 2.JAVA is extend
// 3.overriden and final (C+ 11
class Cat:public Animal {
public:
    Cat(string name):Animal(name)
    {
        cout <<"  cat is inhertanced from Animal(copy constructor)"<<endl;
    }

    void identify()
    {
        cout<<setw(8)<<"Cat"<<name<<endl;
    }
};


class Dog:public Animal {
public:
    Dog(string name):Animal(name)
    {
        cout <<"  dog is inhertanced from Animal (copy constructor)"<<endl;
    }

    void identify()
    {
        cout<<setw(8)<<"  Dog"<<name<<endl;
    }
};


class Tiger:public Cat {                //Tiger is inherrantanced from parents Cat
public:
    Tiger(string name):Cat(name)
    {
        cout <<"  Tiger is inhertance from cat (copy constructor)"<<endl;
    }
    void identify()
    {
        cout<<setw(8)<<"  Tiger"<<name<<endl;
    }
};



// --------------[Encapsulation]------------------
// 1.type <=> class
//
// 2.define public, protected, private is called encapsulation
//   maxAnimals and numAnimals
//
// 3.decide interface
//   you don't need which animals, just plus it.
//
// 4.Unified Modeling Language
//  ????? class name, property,

class Zoo
{
public:
    Zoo(){}
    Zoo(int max);
    ~Zoo()
    {
        delete residents;
    }

    int Accept(Animal *a);
    void ListAnimals();
private:
    int maxAnimals;
    int numAnimals;
    Animal **residents; // Animal array
};

// Zoo constructor
Zoo::Zoo(int max)
{
    cout << "[Zoo start]"<< endl;
    numAnimals = 0;                  // 原始动物数
    maxAnimals = max;             // 初始化最大圈养动物数
    residents = new Animal*[max]; // 申请指针数据
}


int Zoo::Accept(Animal *a)
{
    //cout << "[Zoo Accept animals class address] "<< setw(a) << endl;
    cout << "[Zoo Accept animals class address] "<< a << endl;
    //cout << "[Zoo Accept animals class address] "<< a->name << endl;
    if (numAnimals == maxAnimals)    // 判断是否已经到大最大圈养数
    {
        cout << "Animal is full" << endl;
        return -1;
    }
    residents[numAnimals] = a;
    cout << "total Animal is "<<numAnimals++<<" " << endl;
    //cout << "Animal's idenity " << residents[numAnimals]->identify() <<" " << endl;
    return 0;
}


// --------------[polymorphism]------------------
// 都是動物 但是做同一種行為
// 用父class 操作 子calss
//     parent:鳥飛
//     child:鴨飛 雞飛
//
// ex: idenity()
void Zoo::ListAnimals()
{
    for (int i=0; i<numAnimals; i++)
    {
        cout <<"number is "<<i<<" "<<endl;
        residents[i]->identify();    // 调用动物类中描述函数
    }
}

int main()
{
    Zoo z(100);
    //Zoo z1;
    Dog D1(" D1 ");
    Cat C1(" C1 ");
    Tiger T1(" T1 ");

    cout<<"D1 is "<<&D1<< endl;
    cout<<"C1 is "<<&C1<< endl;
    cout<<"T1 is "<<&T1<< endl;

    z.Accept(&D1);
    z.Accept(&T1);
    z.Accept(&C1);

    z.ListAnimals();
    return 0;
}
