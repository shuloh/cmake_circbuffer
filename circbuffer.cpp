#include <iostream>
#include "circbuffer.h"
#include "ds_circularbuffer.h"
int main(int argc, char *argv[])
{
    using namespace std;
    cout << argv[0] << " version "
         << VERSION_MAJOR << "." << VERSION_MINOR << endl;
    auto cbuf = circular_buffer<int>(5);
    for (int i = 1; i <= 10; i++)
    {
        cbuf.put(i);
    }
    cout << cbuf.get() << endl;
    cout << cbuf.get() << endl;
    cout << cbuf.get() << endl;
    cout << cbuf.get() << endl;
    cout << cbuf.get() << endl;
    cout << cbuf.get() << endl;
}