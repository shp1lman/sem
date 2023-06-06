#include <vector>
#include <string>
#include <iostream>

class Base {
public:
    Base()
    {
        num = new int(88);
    };
    Base(const Base& obj)
    {
        num = new int(*obj.num);
    }
    virtual ~Base()
    {
        delete num;
    }

    virtual Base* clone() const
    {
        return new Base(*this);
    }
    int* num;
};

class Derived final : public Base {
public:
    Derived() : Base()
    {
        str = "OLEG";
    };
    ~Derived()
    {
    str.clear();
    };
    Derived(const Derived& obj) :Base(obj)
    {
        str = obj.str;
    }

    virtual Derived* clone() const override
    {
        return new Derived(*this);
    }
    std::string str{};
};

class DB {
public:
    DB()
    {
        _vec = new std::vector<Base*>;
    }
    DB(const DB& other)
    {
        _vec = new std::vector<Base*>();
        for (Base* ptr : *(other._vec))
        {
            _vec->push_back(ptr->clone());
        }
    }
    ~DB()
    {
        for (Base* ptr : *_vec)
        {
            delete ptr;
        }
        delete _vec;
    }

    DB& operator= (const DB& r)
    {
        if (this == &r)
        {
            return *this;
        }
        for (Base* ptr : *(r._vec))
        {
            _vec->push_back(ptr->clone());
        }
        return *this;
    }
    void add(){
    _vec->push_back(new Base());
    _vec->push_back(new Derived());
    }
    void printAddres()
    {
        std::cout << &_vec[0] << '\n';
    }
    private:
        std::vector<Base*>* _vec;
};

int main (){

DB db1, db2;
db1.add();
db1.add();
db1.add();
db1.add();

db2 = db1;
db1.printAddres();
db2.printAddres();

return 0;
}
