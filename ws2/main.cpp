#include "Employee.h"
#include "File.h"
using namespace seneca;

int main() {

        if (load()) {
            display();
        }
        deallocateMemory();
    return 0;
}
