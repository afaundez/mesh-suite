#ifndef FACTORY_H
#define FACTORY_H

class Factory
{
    public:
        virtual ~Factory() {}
        virtual void build() = 0;
};
#endif // FACTORY_H
