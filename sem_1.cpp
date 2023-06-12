#include <iostream>
#include <vector>

using namespace std;

class Pack {
protected:
    float* m_v;
public:
    Pack() {
        m_v = new float(0);
    }
    Pack(const float var) {
        m_v = new float (var);
    }
    virtual ~Pack(){}
};
class Box : public Pack {
private:
    int m_Kv;
public:
    Box(const int var) {
        m_Kv = var;
    }
    ~Box(){}
};

vector <Pack*> Wagon;
vector <Pack*> Lorry;

void fill() {
    for (int i = 0; i < 3; i++) {
        Wagon.push_back(new Pack(i + i / 10));
        Wagon.push_back(new Box(i));
    }
}

int main()
{
    fill();
    for (int i = 0; i < 3; i++) {
        Lorry.push_back(Wagon.back());
        Wagon.pop_back();
    }
}

