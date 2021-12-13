#include "graphicsEngine.h"

using namespace sf;
using namespace std;

namespace graphicsEngine {
    graphicsEngine::graphicsEngine(int width, int height, dataShare_t dataShare, string name) {
        window = new RenderWindow(VideoMode(width, height), name);
    }

    graphicsEngine::~graphicsEngine() {
        
    }
    
}