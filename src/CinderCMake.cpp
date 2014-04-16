
#include <cinder/app/AppNative.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;

class CinderCMakeApp : public AppNative {
 public:
  void setup ();
  void mouseDown (MouseEvent);
  void update ();
  void draw ();
};

void CinderCMakeApp::setup () {
  std::cout << "Setup!\n";
}

void CinderCMakeApp::mouseDown (MouseEvent event) {
  std::cout << "Mouse down\n";
}

void CinderCMakeApp::update () { }

void CinderCMakeApp::draw () {
  gl::clear (Color (0.8, 0.8, 1.0));
}

CINDER_APP_NATIVE(CinderCMakeApp, RendererGl);
