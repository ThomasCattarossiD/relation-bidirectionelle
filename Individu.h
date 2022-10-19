/**
 * @file Individu.h
 * @author Lopistéguy
 * @brief Spécifie une classe Individu en relation réciproque avec sa Voiture (de manière non sexuelle)
 * @details Ce fichier implante un Individu défini par un nom, prénom.
 * La classe définit également la Voiture conduite par l'Individu.
 * @version 1.0
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INDIVIDU_H
#define INDIVIDU_H

using namespace std;

#include "Voiture.h" // Utilisée ci-dessous
#include <iostream>

class Voiture; /* Annonce une définition ultérieure de Voiture
                   permet de faire référence aux membres de Voiture dans la classe Individu */
/**
 * @brief Représente un Individu.
 * @warning Un Individu est associé à AU PLUS Une Voiture
 * @deprecated Arrêtez d'utiliser ce programme nul.
 */

class Individu
{
    // ATTRIBUTS
  public:
    /**
     * @brief Le nom de l'Individu
     * 
     */
    string nom;   
    /**
     * @brief Le prénom de l'Individu
     * 
     */
    string prenom;
    /**
     * @brief La Voiture de l'Individu
     * 
     */
    Voiture *maVoiture;

    // MÉTHODES
  public:
    // Constructeur
    /**
     * @brief Construit un nouvel objet Individu.
     * 
     */
    Individu(string = "", string = "");
    // destructeur
    ~Individu();

    // Méthodes usuelles : toString
    /**
     * @brief Affiche l'identité de l'individu
     * 
     * @return chaîne de caractères nom+prénom
     * @bug Un espace de trop entre le nom et le prénom
     * @todo Choisir si on veut retourner la chaîne au format nom+prénom ou prénom+nom
     */
    string toString();
    string toStringAndLink(); // Affiche l'identité de l'individu et de sa voiture s'il en a une

    // Méthodes spécifiques
    void majMaVoiture(Voiture* voiture);
    /**
     * @brief Définit la Voiture conduite par l'Individu.
     * 
     * @param [in] voiture un pointeur vers l'objet Voiture conduit par l'Individu
     */
    void setMaVoiture(Voiture* voiture);
    void supprimerLien();
};

#endif // INDIVIDU_H