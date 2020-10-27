#include <iostream>
#include <utility>
#include <memory>
using namespace std;
class Box{
    int le;
    int br;
    int he;
public:
    Box(int l,int b,int h):
        le(l),br(b),he(h){}
    int volume(){
        return le*br*he;
    }
};
int main()
{
    //Box b;
    //Box *p = new Box(1,2,3);
    std::unique_ptr<Box> p = std::make_unique<Box>(1,2,3);
    cout << p -> volume();
    return 0;
}


