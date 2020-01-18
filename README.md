# MasseMolaire.c
Programme de calcul de masse molaire à partir d'une formule brute.

## License

MIT License

Copyright (c) 2020 Enzo PICAS

## Utilisation
Le programme dispose d'une base de données contenant les noms, les symboles, et les masses molaires des différents éléments du tableau périodique.

**Important :** Mettre à jour le `#define ATOMSFILE` de main.c avec l'adresse du fichier qui indique les informations des atome.

Pour obtenir la masse molaire de la molécule, il suffit d'entrer la formule brute de la molécule :
* Si un élément est présent plusieurs fois, entrer le nombre à gauche de l'élément --> ex: H2O
* Si un élément n'apparaît qu'une seule fois, inutile de le préciser
* Entrer la première lettre de chaques éléments en majuscule --> ex: NaCl

## Contributeur
* Enzo PICAS
