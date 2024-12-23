#include "terrain.h"
#include <fstream>
#include <iostream>

using namespace std;

terrain::terrain()
{
    d_terrain.clear(); // Initialise la grille comme vide
}

bool terrain::chargerDepuisFichier(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << endl;
        return false;
    }

    d_terrain.clear();
    string ligne;
    int y = 0;

    while (getline(fichier, ligne)) {
        vector<char> ligneTerrain;
        for (int x = 0; x < (int)ligne.size(); ++x) {
            char c = ligne[x];
            ligneTerrain.push_back(c);

            if (c == 'D') {
                d_depart.setPosition(x,y);
            } else if (c == 'A') {
                d_arrivee.setPosition(x,y);
            }
        }
        d_terrain.push_back(ligneTerrain);
        ++y;
    }

    d_longueur = d_terrain.size();
    d_largeur = d_terrain.empty() ? 0 : d_terrain[0].size();
    fichier.close();
    return true;
}

void terrain::afficher() const {
    for (const auto& ligne : d_terrain) {
        for (char c : ligne) {
            cout << c;
        }
        cout << endl;
    }
}

int terrain::getLargeur() const {
    return d_largeur;
}

int terrain::getLongueur() const {
    return d_longueur;
}

position terrain::getCaseDepart() const {
    return d_depart;
}

position terrain::getCaseArrivee() const {
    return d_arrivee;
}

bool terrain::estLibre(const position& sp) const {
    int x = sp.getX();
    int y = sp.getY();

    if (x < 0 || x >= d_largeur || y < 0 || y >= d_longueur) {
        return false;
    }

    return d_terrain[y][x] == '.' || d_terrain[y][x] == 'A' || d_terrain[y][x] == 'D';
}
