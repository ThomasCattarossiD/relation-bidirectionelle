/*
  Implémente les méthodes de la classe Voiture
  Auteur : Lopistéguy
  Version : 0.1
  Date : 12/08/2022
*/

#include "Voiture.h"

Voiture::Voiture(string m, string i) : imat(i), marque(m)
{
    monPilote = nullptr;
}

string Voiture::toString()
{
    return (marque + " " + imat);
}

string Voiture::toStringAndLink()
{
    string resultat;
    resultat = toString();
    if (monPilote != nullptr)
    {
        resultat += " a le pilote : " + monPilote->toString();
    }
    return resultat;
}

void Voiture::majMonPilote(Individu *pilote)
{
    monPilote = pilote;
}

void Voiture::supprimerLien()
{ // Idem pour Individu
    if (monPilote != nullptr)
    {
        monPilote->majMaVoiture(nullptr);
        monPilote = nullptr;
    }
}

void Voiture::setMonPilote(Individu *pilote)
{ // Idem pour Individu
    // Supprimer mon éventuel lien actuel
    supprimerLien();

    if (pilote != nullptr)
    { // Construire le nouveau lien
        // Supprimer l'éventuel lien actuel de mon correspondant
        pilote->supprimerLien();

        // Établir le lien croisé avec mon correspondant
        pilote->majMaVoiture(this); // Il pointe sur moi
        majMonPilote(pilote);       // Je pointe sur lui
    }
}

Voiture::~Voiture()
{
    supprimerLien();
}