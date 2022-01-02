#include "types.h"
#include "graphicsEngine.h"
#include <thread>
#include <string>
#include <stdlib.h>

using namespace GraphicsEngine;
using namespace std;

dataShare_t dataShare;

void graphicsThread();

int main() {
    dataShare.lock.unlock();
    thread* graphics = new thread(graphicsThread);

    uint8_t r, g, b, a = 0;
    uint8_t state = 0;
    while (1) {
        pixel_t pixel;
        pixel.r = r; pixel.g = g; pixel.b = b; pixel.a = a;

        switch (state) {
            case 0:
                r++;
                if (r > 254) {
                    r = 0;
                    state = 1;
                }
                break;
            case 1:
                g++;
                if (g > 254) {
                    g = 0;
                    state = 2;
                }
                break;
            case 2:
                b++;
                if (b > 254) {
                    b = 0;
                    state = 2;
                }
                break;
        }
        a++;
        if (a >201) a = 0;

        dataShare.lock.lock();
        dataShare.pixels.push(pixel);
        dataShare.lock.unlock();
    }
}

void graphicsThread() {
    graphicsEngine engine(800, 600, &dataShare, "Hello World!");
}
