// TestingCppFeatures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"Parent.h"
#include "Child.h"
int time_two(int a) {
    return a * 2;
}

void time_three(int& a) {
    a *= 3;
}

void time_four(int* a) {
    *a *= 4;
}


int main()
{
    std::cout << "Hello World!\n";
    Parent p = Parent();
    Child child = Child();

    std::cout << "parent:" << p << std::endl;
    std::cout << "child :" << child << std::endl;

    std::cout << "Week4" << std::endl;
    std::cout << "=====" << std::endl;

    //Week4
   
    //Pointers

    int *age = nullptr;
    double* weight = nullptr;   //
    char * letter = nullptr;

    //*weight = 2.0;

    double result=0.0;
    //  result= *weight;


    class Pizza { 
    public:
        void doSth() {};
        int size; //in inchs
    };
    Pizza* pPizza = nullptr;
    pPizza->doSth();

    double* pResult = &result;

    double* weight2 = weight;

    Pizza* pPizza2 = new Pizza();

    //Obtaining a pointer
    int number = 13;
    std::cout << number << '\n';  //outputs 13
    //address operator get the address of its operand
    std::cout << &number << '\n'; //outputs hexadecimal address

    //obtaining a pointer from the address of variable
    int* number_ptr1 = &number;
    std::cout << "* number_ptr1=" << * number_ptr1 << '\n'; //outputs hexadecimal address


    //Sizeof operator
    std::cout << "Sizeof operator" << std::endl;
    std::cout << "===============" << std::endl;
    int a = 11;
    double b = 13.0;
    bool c = false;
    int* pp = &a;
    double* q = &b;
    bool* r = &c;

    short d = 6;

    short *s = &d;


    //Sizes
    std::cout << "Sizes" << std::endl;
    std::cout << "=====" << std::endl;
    std::cout << sizeof(pp) << "btyes\n";    //outputs 8
    std::cout << sizeof(q) << "btyes\n";    //outputs 8
    std::cout << sizeof(r) << "btyes\n";    //outputs 8
    std::cout << sizeof(s) << "btyes\n";    //outputs 8

    std::cout << sizeof(*pp) << "btyes\n";   //outputs 4
    std::cout << sizeof(*q) << "btyes\n";   //outputs 8
    std::cout << sizeof(*r) << "btyes\n";   //outputs 1
    std::cout << sizeof(*s) << "btyes\n";    //outputs 8

    //Arrays
    std::cout << "Pointer can be used as an array name 1" << std::endl;
    std::cout << "====================================" << std::endl;
    int primes[] = { 2, 3, 5, 7, 11 };
    std::cout << std::hex;               //subsequent outputs will be in hex
    std::cout << primes << '\n';         //outputs a hex address


    //Array name can be used as a pointer constant
    std::cout << "Pointer can be used as an array name 2" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << *primes << '\n';        //outputs 2
    std::cout << *(primes + 1) << '\n';  //outputs 3
    std::cout << *(primes + 2) << '\n';  //outputs 5

    //Pointer can be used as an array name
    std::cout << "Pointer can be used as an array name 3" << std::endl;
    std::cout << "====================================" << std::endl;
    int* prime_ptr = primes;
    std::cout << prime_ptr[2] << '\n';  //outputs 5
    std::cout << std::hex << &prime_ptr[2] << '\n';  //outputs 5

    std::cout << std::oct << prime_ptr[4] << '\n';  //outputs 13

    //Passing Argiments to functions
    std::cout << "Passing Argiments to functions" << std::endl;
    std::cout << "==============================" << std::endl;
    int aa = 3;
    std::cout << std::dec;
    std::cout << time_two(aa) << '\n';
    std::cout << aa << '\n'; //outputs 3

    time_three(aa); //using reference argument
    std::cout << aa << '\n'; //outputs 9

    time_four(&aa); //using pointer argument
    std::cout << aa << '\n'; //outputs 36
    
    //Constatnt pointers 
    std::cout << "Constatnt pointers" << std::endl;
    std::cout << "==================" << std::endl;

    int aaa = 11;
    int bbb = 13;
    const int* const_ptr = &aaa;
    const_ptr = &bbb;  //change what the pointer points to

    //the statement below is not legal
    //*const_ptr = 17;  //assign pointer to a new variable

    //2nd type of const ptr
    int* const const_ptr2 = &aaa;
    *const_ptr2 = 19;  //still pointing to a

    //the statement below is not legal
    //const_ptr2 = &bbb;  //assign pointer to a new variable

    //References
    std::cout << "References" << std::endl;
    std::cout << "==========" << std::endl;
    //declaring reference variables
    int& e = aaa;
    double& f = b;

    //Raw pointers, memory leaks (loss)
    {
        Parent* ptr1 = new Parent();
        std::cout << ptr1 << std::endl;
    }
    //scope has ended, but the memory was not released
    //and there is not way to access it.
    //Affectively – Lost memory (or Memory Leak)

    //Unique Pointers
    std::cout << "Unique Pointers" << std::endl;
    std::cout << "===============" << std::endl;
    std::unique_ptr<int> p1 = std::make_unique<int>(12);
    //auto p2 = p1;          //illegal to copy; 


    auto p2 = std::move(p1); //transfer ownership to p2, p1 is no longer valid
    std::cout << "*p2: " << *p2 << std::endl;    //p2->print_info();        
    
    //All To Well by: Taylor Swift
    int v2 = 42;
    p1.reset(&v2); //the previous object is freed

    std::cout << "*p1: " << *p1 << std::endl;    //p1->print_info();        

    p2.swap(p1);

    std::cout << "After p2.swap(p1)" << std::endl;
    std::cout << "*p2: " << *p2 << std::endl;    //p2->print_info();        
    std::cout << "*p1: " << *p1 << std::endl;    //p1->print_info();        

    //Shared Pointers
    std::cout << "\n\nShared Pointers" << std::endl;
    std::cout << "===============" << std::endl;
    {
        std::shared_ptr<double> pd1 = std::make_shared<double>(12.0);
        std::cout << "pd1 shared count " << pd1.use_count() << std::endl;
        {
            auto pd2 = pd1; //shared ownership
            std::cout << "pd1 shared count " << pd1.use_count() << std::endl;
            std::cout << "pd2 shared count " << pd2.use_count() << std::endl;
        }
        std::cout << "pd1 shared count before pd3:" << pd1.use_count() << std::endl;
        auto pd3(pd1);      //shared ownership
        std::cout << "pd1 shared count " << pd1.use_count() << std::endl;
        //std::cout << "pd2 shared count " << p21.use_count() << std::endl;  //NOT VALID -> COMP. ERROR
        std::cout << "pd3 shared count " << pd3.use_count() << std::endl;
    }
    //just one object was created, and it was destroyed when the scope ended
    //std::cout << "pd1 shared count " << pd1.use_count() << std::endl;  //NOT VALID -> COMP. ERROR
    //std::cout << "pd2 shared count " << pd2.use_count() << std::endl;  //NOT VALID -> COMP. ERROR
    //std::cout << "pd3 shared count " << pd3.use_count() << std::endl;  //NOT VALID -> COMP. ERROR


    //Weak Pointers
    std::cout << "\n\nWeak Pointers" << std::endl;
    std::cout << "==============" << std::endl;
    {
        std::shared_ptr<float> pf1 = std::make_shared<float>(12.0f);
        std::cout << "pf1 shared count " << pf1.use_count() << std::endl;
            
        std::weak_ptr<float> pf2= pf1; //Works very well

        std::cout << "pf1 shared count " << pf1.use_count() << std::endl;
        std::cout << "pf2 shared count " << pf2.use_count() << std::endl;  
        if (auto tmp = pf2.lock()) { //lock() return true only if the shared pointer is still valid
            std::cout << "*tmp " << *tmp << std::endl;
            std::cout << "tmp shared count " << tmp.use_count() << std::endl;
        }else {
            std::cout << "Weak pointer has expired\n";
        }
        std::cout << "After tmp block " << std::endl;
        //std::cout << "pf1 shared count " << tmp.use_count() << std::endl; //NOT VALID -> COMP. ERROR (Out of Scope now)
        std::cout << "pf1 shared count " << pf1.use_count() << std::endl;
        std::cout << "pf2 shared count " << pf2.use_count() << std::endl;
    }


    //Expenations of pointers
    int aaaa=42;
    //std::cout << aaaa << std::endl;  // does not compile - why?

    //std::cout << &aaaa << std::endl;
    //what does the above line produce?

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
