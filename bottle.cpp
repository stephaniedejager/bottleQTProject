#include <QDebug>
#include <QTextStream>
#include "bottle.h"

Bottle::Bottle()
{
}

void Bottle::setCapacity(int c) {
    QTextStream cout(stdout);
    if (c<0)
    {
        throw "Capacity cannot be less than zero.";
    };
    maxCapacity = c;
}

void Bottle::setQuantity(int q) {
    QTextStream cout(stdout);
    if (q<0)
    {
        throw "Quantity cannot be less than zero.";
    };
    if (q>maxCapacity)
    {
        throw "Quantity cannot be more than Capacity.";
    };
    currentQuantity = q;
}

int Bottle::getCapacity() const {
    return maxCapacity;
}

int Bottle::getQuantity() const {
    return currentQuantity;
}

void Bottle::fill() {
    currentQuantity = maxCapacity;
}

void Bottle::empty() {
    currentQuantity = 0;
}

