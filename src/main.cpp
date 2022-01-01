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

    uint8_t count = 0;
    while (1) {
        count++;
        pixel_t pixel;
        pixel.r = count; pixel.g = count; pixel.b = count; pixel.a = count;

        if (count == 201) count = 0;

        dataShare.lock.lock();
        dataShare.pixels.push(pixel);
        dataShare.lock.unlock();
    }
}

void graphicsThread() {
    graphicsEngine engine(800, 600, &dataShare, "Hello World!");
}
