/*
  Ce programme montre comment implanter une relation symétrique 1-1 entre Voiture et Individu.
  Auteur : Lopistéguy
  Version : 0.1
  Date : 12/08/2022
*/

#include <cstdlib>
#include <iostream>

#include "Individu.h"
#include "Voiture.h"

using namespace std;

int main(void)
{

    // 1. Mise en place
    cout << "\n\n1 - Mise en place\n\n";

    // Déclaration des objets
    Voiture voit1("RenaultClio", "123AB64");    // Création d'une voiture de type Renault Clio
    Voiture voit2("Peugeot106", "678CD96");     // Création d'une voiture de type Peugeot 106
    Voiture voit3("CitroenPicasso", "456EF75"); // Création d'une voiture de type Citroen Picasso

    Individu ind1("Dupond", "Pierre"); // Création du pilote Pierre Dupond
    Individu ind2("Martin", "Louis");  // Création du pilote Louis Martin
    Individu ind3("Durand", "Marcel"); // Création du pilote Marcel Durand

    // Affichage des pilotes et des voitures
    cout << ind1.toString() << endl
         << ind2.toString() << endl
         << ind3.toString() << endl;
    cout << voit1.toString() << endl
         << voit2.toString() << endl
         << voit3.toString() << endl;

    //3.  Mise en relation correcte de l'individu 3 et de la voiture 3
    ind3.maVoiture = &voit3;
    voit3.monPilote = &ind3;

    // Affichage du lien entre l'individu 3 et la voiture 3
    cout << "La voiture de " << ind3.toString()
         << " est " << ind3.maVoiture->toString()
         << endl
         << endl;

    // Changement de la plaque de la voiture 3
    voit3.imat = "77777NO22";

    // Affichage de la nouvelle plaque de voiture 3
    cout << "La nouvelle plaque de " << voit3.marque
         << " est devenue " << voit3.imat
         << endl
         << endl;

    // Réaffichage du lien entre l'individu 3 et la voiture 3
    cout << "La voiture de " << ind3.toString()
         << " est " << ind3.maVoiture->toString()
         << endl
         << endl;

    // 4. AFFICHER TOUT
    cout << "\n\n4 - Afficher tout quand on dispose d'un correspondant\n\n";
    cout << ind3.toStringAndLink() << endl
         << voit3.toStringAndLink() << endl
         << ind2.toStringAndLink() << endl
         << voit2.toStringAndLink() << endl;

    // 5. LIEN RECIPROQUE
    cout << "\n\n5 - Gestion de la symétrie du lien avec un seul appel !\n";
    ind3.setMaVoiture(&voit3); // Lie ind3 à voit3 avec un seul 'set'
    cout << voit3.toStringAndLink() << endl
         << ind3.toStringAndLink() << endl
         << endl;

    // Lie voit3 et ind2 avec un seul 'set' qui gère la réciproque
    voit3.setMonPilote(&ind2);              // et délie ce qui est à délier
    cout << ind3.toStringAndLink() << endl  // N'est plus lié
         << voit3.toStringAndLink() << endl // Lié à ind2
         << ind2.toStringAndLink() << endl; // Lié à voit3

    // 6. DETRUIRE OBJET LIÉ
    cout << "\n\n6 - Detruire un objet lie\n\n";
    cout << ind2.toStringAndLink() << endl; // Objet ind2 lié à voit3
    delete (&voit3);                        // Destruction de voit3
    cout << ind2.toStringAndLink();         // Objet ind2 n'est plus lié à voit3
}