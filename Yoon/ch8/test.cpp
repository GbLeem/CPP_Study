#include<stdio.h>

class Base
{
public:
    virtual void Foo()
    {
        printf("Base::Foo\n");
    }
    void Bar()
    {
        printf("Base::Bar\n");
    }
};

class Derived : public Base
{
public:
    virtual void Foo()
    {
        printf("Derived::Foo\n");
    }
    void Bar()
    {
        printf("Derived::Bar\n");
    }
};

int main()
{
    Derived* d = new Derived();
    Base* b = reinterpret_cast<Base*>(d);

    d->Foo();
    d->Bar();
    b->Foo();
    b->Bar();

    return 0;
}