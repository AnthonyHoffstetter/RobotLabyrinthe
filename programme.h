#ifndef PROGRAMME_H_INCLUDED
#define PROGRAMME_H_INCLUDED


#include "terrain.h"
#include "robot.h"
#include "compteur_deplacement.h"
#include "afficheurRobot.h"
#include "algorithmeMainDroite.h"
#include"algorithmePledge.h"
#include "calcul_temps.h"
#include "compteur_rotation.h"

using namespace std ;

class programme {
public:

    programme();


    void initialiser();
      bool isTerrainCharge() const { return terrainCharge; }
      terrain& returnterain() {return ter; }


    void executerChoixAlgorithme();
    void choisirAlgorithme(int choix, robot& r, terrain& ter);
    bool choisirAffichage(int choix,terrain &ter);


private:

    bool terrainCharge;
    terrain ter;
    unique_ptr<compteur_deplacement> compteur;

    unique_ptr<afficheurRobot> afficheur;
};



#endif // PROGRAMME_H_INCLUDED
