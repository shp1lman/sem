#include <iostream>
#include <vector>

class Base
{
public:
    Base(int _in) : pInt(new int(_in))
    {
        std::cout << "Base constructor called" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "Base destructor called" << std::endl;
        delete pInt;
    }

    Base(const Base& other) : pInt(new int(*other.pInt))
    {
        std::cout << "Base copy constructor called" << std::endl;
    }

    virtual Base* clone() {
    return new Base(*this);
    };

    int* pInt;
};

class Derived1 : public Base
{
public:
    Derived1(int _in) : Base(_in), mFloat(2.61f)
    {
        std::cout << "Derived1 constructor called" << std::endl;
    }

    Derived1(const Derived1& other) : Base(other), mFloat(other.mFloat)
    {
        std::cout << "Derived1 copy constructor called" << std::endl;
    }

    float mFloat;

    virtual Base* clone() override
    {
        return new Derived1(*this);
    }
};

class Derived2 : public Base
{
public:
    Derived2(int _in, char c_in) : Base(_in), mChar(c_in)
    {
        std::cout << "Derived2 constructor called" << std::endl;
    }

    Derived2(const Derived2& other) : Base(other), mChar(other.mChar)
    {
        std::cout << "Derived2 copy constructor called" << std::endl;
    }

    virtual Base* clone() override
    {
        return new Derived2(*this);
    }

        void setChar(char c)
    {
        mChar = c;
    }

    char getChar() const
    {
        return mChar;
    }
    private:
    char mChar;
};

int main()
{
    std::vector<Base*> vec1;
    vec1.push_back(new Base(4));
    vec1.push_back(new Derived1(5));
    vec1.push_back(new Derived2(6, 's'));

    std::vector<Base*> vec2(vec1.size());
    for (size_t i = 0; i < vec1.size(); ++i)
    {
        vec2[i] = vec1[i]->clone();
    }
    for (auto p : vec1)
    {
        delete p;
    }
    vec1.clear();
    for (auto p : vec2)
    {
        delete p;
    }
    vec2.clear();
    return 0;
};
