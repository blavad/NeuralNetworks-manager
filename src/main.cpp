#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <vector>

#include "ihm/Panneau.hpp"

using namespace std;

int main(int argc, char **argv)
{

  Gtk::Main::init_gtkmm_internals();

  /* Apprentissage *app = new Apprentissage();
  ReseauNeurones *rn = new ReseauNeurones();

  app->setRN(rn);

  cout << "bon"; */

  auto app = Gtk::Application::create(argc, argv, "grn.reseauneurones.affichage");
  Panneau win;
  // Gtk::Window win;

  /* Couche *c = new TanH("TanH_1"), *c2 = new TanH("TanH_2"), *c3 = new TanH("TanH_3"), *c4 = new TanH("TanH_4"), *c5 = new TanH("TanH_5"), *c6 = new TanH("TanH_6"), *c7 = new TanH("TanH_7");
  vector<Couche *> c_init{c, c2, c3, c4, c5};
  ReseauNeurones *rn = new ReseauNeurones(c_init, "RN_Test_FC");
  rn->setDimInput(vector<int>{5, 5, 3});

  BoiteArchitecture archiDraw(rn);
  archiDraw.show();
  win.add(archiDraw); */

  return app->run(win);
}