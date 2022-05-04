#ifndef BOTTLE_H
#define BOTTLE_H

#include <QString>

class Bottle
{
public:
    Bottle();
    void setCapacity(int c);
    void setQuantity(int q);
    int getCapacity() const;
    int getQuantity() const;
    void fill();
    void empty();
private:
    int maxCapacity;
    int currentQuantity;
};

#endif // BOTTLE_H
