#include <QApplication>
#include <QTextStream>
#include <QtGlobal>
#include <bottle.h>

using namespace std;

QTextStream cout(stdout);

int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    const int bottleOneCapacity  = 15;
    const int bottleOneQuantity = 5;

    Bottle one, two;

    one.setCapacity(bottleOneCapacity);
    one.setQuantity(bottleOneQuantity);

    // Test happy path for setCapacity and getCapacity
    Q_ASSERT (one.getCapacity() == bottleOneCapacity);

    // Test happy path for setQuantity and getQuantity
    Q_ASSERT (one.getQuantity() == bottleOneQuantity);

    // Test that fill sets the Quantity to Capacity
    one.fill();
    Q_ASSERT (one.getQuantity() == one.getCapacity());

    // Test that empty sets the Quantity to zero
    one.empty();
    Q_ASSERT (one.getQuantity() == 0);

    // Test that Capacity cannot be set less than zero
    try {
        two.setCapacity(-1);
        Q_ASSERT_X (false, "setCapacity", "value less than zero");
    } catch (const char* msg) {
        Q_ASSERT (strcmp(msg,"Capacity cannot be less than zero.") == 0);
    }

    // Test that Quantity cannot be set less than zero
    try {
        two.setQuantity(-1);
        Q_ASSERT_X (false, "setQuantity", "value less than zero");
    } catch (const char* msg) {
        Q_ASSERT (strcmp(msg,"Quantity cannot be less than zero.") == 0);
    }

    // Test that Quantity cannot be set greater than Capacity
    two.setCapacity(10);
    try{
        two.setQuantity(11);
        Q_ASSERT_X (false, "setQuantity", "greater than Capacity");
    } catch (const char* msg){
        Q_ASSERT (strcmp(msg, "Quantity cannot be more than Capacity.") == 0);
    }

    cout << "All tests passed!" << endl;

    return app.exec();
}

