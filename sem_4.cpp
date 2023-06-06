#include <vector>

class Base {
public:
    Base() = default;
    virtual ~Base() = default;
    virtual Base* clone() const
    {
        return new Base(*this);
    }
};

class Derived : public Base {
public:
    Derived() = default;
    ~Derived() override = default;
    virtual Derived* clone() const override
    {
        return new Derived(*this);
    }
};

class Parent {
public:
    Parent() = default;
    Parent(const Parent& other)
    {
        for (Base* ptr : other.vec)
        {
            vec.push_back(ptr->clone());
        }
    }
    ~Parent()
    {
        for (auto & i : vec)
        {
            delete i;
        }
        vec.clear();
    }
    private:
        std::vector<Base*> vec;
};

class Child : public Parent {
public:
    Child() : vec2(new std::vector<Base*>()), Parent() {}
    Child(const Child& other) : Parent(other)
    {
        vec2 = new std::vector<Base*>();
        for (Base* ptr : *(other.vec2))
        {
            vec2->push_back(ptr->clone());
        }
    }
    ~Child() {
        for (Base* ptr : *vec2)
        {
            delete ptr;
        }
        delete vec2;
    }
    private:
        std::vector<Base*>* vec2;
};

int main (){
return 0;
}
