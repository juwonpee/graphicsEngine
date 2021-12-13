#pragma once

#include "types.h"
#include <SFML/Graphics.hpp>
#include <mutex>
#include "string.h"

using namespace sf;
using namespace std;

namespace graphicsEngine {

    typedef struct dataShare_t {
        mutex lock;
        mutex processed;
        Uint8* pixels;
    } dataShare_t;

    class graphicsEngine {
        public:
            graphicsEngine(int with, int height, dataShare_t _dataShare, string name);
            ~graphicsEngine();

            void update();

        private:
            dataShare_t* dataShare;
            RenderWindow* window;
    };
}

