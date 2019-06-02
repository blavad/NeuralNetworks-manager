#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <vector>
#include "pretraitement/Pretraitement.hpp"
#include "ihm/Panneau.hpp"
#include "Magick++.h"

using namespace std;

int main(int argc, char **argv)
{

  Magick::InitializeMagick(*argv);

  // -------------------------------------------------
  // PROGRAMME PRINCIPAL

  /* Gtk::Main::init_gtkmm_internals();
  auto app = Gtk::Application::create(argc, argv, "grn.reseauneurones.affichage");
  Panneau win;
  
  return app->run(win); */

  // -------------------------------
  // EXEMPLE UTILISATION DE TENSEURS

  /* Pretraitement p;
  Tenseur *timg;
  timg = p.imageToTenseur("/home/david/Images/albert.png", 50, 50);

  cout << *timg;
  timg = p.imageToTenseur("/home/david/Images/albert.png", 50, 50);

  cout << *timg; */
  // -------------------------------
  // EXEMPLE UTILISATION DE TENSEURS

  // Différentes initialisations de tenseurs grâce à ses dimensions
  /* Tenseur t1({3,5}), t2({5,5}), tGaussien = {3,5}, tMoins = tGaussien, tRes;
  t1 = 3.1; // Les valeurs du tenseurs seront mises à 5.1
  t2 = 5.2;
  tGaussien.initValeurGaussienne();
  tMoins = 29.3;
  
  tRes = (t1 * t2) + tGaussien - tMoins;

  cout << "Resultat : " << tRes << endl; */

  // -------------------------------------------------
  // EXEMPLE CREATION RESEAU DE NEURONE ET PROPAGATION

  Tenseur *tout = new Tenseur({5}), *res = new Tenseur({5, 5});
  res->initValeurConstant(5.5);
  tout->initValeurConstant(3.);

  ReseauNeurones *r2 = new ReseauNeurones("MonRN");
  r2->setDimInput(tout->getDim());

  Couche *c1 = new CoucheConnectee(10, "FC_1");
  Couche *c2 = new CoucheConnectee(10, "FC_2");
  Couche *c3 = new CoucheConnectee(10, "FC_3");
  Couche *c4 = new Sigmoid("Sigmoid2");
  Couche *c5 = new TanH("Tanh3");
  Couche *c6 = new Sigmoid("Sigmoid3");

  r2->ajouterNoeud(c1);
  r2->ajouterNoeud(c2);
  r2->ajouterNoeud(c3);
  r2->ajouterNoeud(c4);
  r2->ajouterNoeud(c5);
  r2->ajouterNoeud(c6);

  r2->ajouterCoucheInitiale(c1);
  r2->ajouterCoucheInitiale(c2);
  r2->ajouterCoucheInitiale(c3);
  r2->ajouterCoucheFinale(c5);
  r2->ajouterCoucheFinale(c6);

  r2->ajouterArc(c1, c5);
  r2->ajouterArc(c1, c4);
  r2->ajouterArc(c2, c4);
  r2->ajouterArc(c3, c4);
  r2->ajouterArc(c4, c5);
  r2->ajouterArc(c4, c6);

  *res = r2->propagation(*tout);

  cout << "RESULTAT FINAL !!! \n\n" << *res << endl;

  DimTenseur dim ;
  dim = res->getDim();
  Tenseur* label = new Tenseur(dim);
  for (int i=0; i<label->getTaille();i++){
    label->setValeur(res->getValeur(std::vector<int> {i}) + 1 , std::vector<int> {i});
  }
  cout << "Label \n" << *label << endl;

  ErreurL1 *err = new ErreurL1();
  Tenseur e = err->eval(*res, *label);

  cout << "Erreur L1" << e <<endl;
  CoucheActivation* ca = new CoucheActivation("fin");

  r2->retro(r2->getCouchesFinales(), ca, res, 0.2);
 
}
