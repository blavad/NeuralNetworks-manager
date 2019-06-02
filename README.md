# Logiciel Création et entraînement de Reseaux Neurones

## Présentation

Logiciel pour concevoir des architectures de réseaux de neurones et les entraîner sur des données.

### Type d'apprentissage possible :
- Classification d'image

### Couches possibles :
Couches de combinaison/aggrégation :
- Fully Connnected
- Neurone simple

Couches de d'activation :
- Sigmoïd
- Tangente hyperbolique
- ReLU (Rectified Linear Unit)

## Installation

### Dépendances

- GTKMM 3
- Magick++

```bash
sudo apt-get install libgtkmm-3.0-dev
sudo apt-get install libmagick++-dev
sudo apt install graphicsmagick-libmagick-dev-compat
```

### Compilation et exécution
```bash
make all
./bin/GestionReseauNeurones
```

## Fonctionnement

Le logiciel se présente sous la forme d'une interface graphique divisée en deux parties. Une première partie, en haut, permet d'afficher le réseau de neurones actuel et de faire des modifications sur sa structure. Une seconde partie, en bas, permet le paramétrage de l'apprentissage. 

Fonctionnalités :

- Simple Clic Gauche : Permet de sélectionner une couche. 

- Simple Clic Droit : Dans le cas où une couche est sélectionnée, permet de déplacer la couche sélectionnée à l'endroit souhaité si la zone pointée est vide. Sinon on va créer un arc entre la couche sélectionnée et la couche pointée. \\

- Double Clic Gauche : Permet de modifier les paramètres de la couche (nom, nombre de sorties pour une couche connectée par exemple). Un double clic gauche sur la couche Input permet de choisir les données. 
- Double Clic Droit : Permet de supprimer une couche.


![alt text](https://gitlab.insa-rouen.fr/dalbert/gestion_reseau_neurones/raw/master/res/ImageLogiciel.png)
