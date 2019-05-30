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

![alt text](https://gitlab.insa-rouen.fr/dalbert/gestion_reseau_neurones/blob/master/res/ImageLogiciel.png)
