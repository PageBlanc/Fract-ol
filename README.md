# Fract-ol

Bienvenue dans **Fract-ol**, mon interprétation du projet de l'école 42 consistant à générer et explorer des fractales célèbres telles que Mandelbrot et Julia.

## Description

**Fract-ol** est un programme graphique qui permet de visualiser et d'interagir avec différentes fractales. Une fractale est une figure géométrique fragmentée qui se répète à l'infini à des échelles plus petites. Ce projet utilise la bibliothèque graphique MiniLibX de l'école 42.

## Fonctionnalités

- **Fractales disponibles** : Mandelbrot, Julia, et d'autres.
- **Zoom** : Utilisez la molette de la souris ou les boutons pour zoomer et dézoomer.
- **Déplacement** : Naviguez dans la fractale à l'aide des touches directionnelles.
- **Changement de palette de couleurs** : Modifiez dynamiquement les couleurs pour une meilleure visualisation.
- **Mode interactif pour Julia** : Ajustez les paramètres en temps réel pour explorer différentes variations de la fractale de Julia.

## Compilation et Exécution

1. **Cloner le dépôt** :

   ```bash
   git clone https://github.com/PageBlanc/Fract-ol.git
   cd Fract-ol
   ```

2. **Compiler le programme** :

   ```bash
   make
   ```

   Cela génère un exécutable nommé `fractol`.

3. **Lancer le programme** :

   ```bash
   ./fractol [nom_de_la_fractale]
   ```

   Par exemple :

   ```bash
   ./fractol mandelbrot
   ```

   Si aucun nom de fractale n'est fourni, le programme affichera les options disponibles.

## Contrôles

- **Zoom** : Molette de la souris ou touches `+` et `-`.
- **Déplacement** : Touches fléchées ou `W`, `A`, `S`, `D`.
- **Changer de palette de couleurs** : Touches `C` ou `P`.
- **Mode interactif pour Julia** : Déplacez la souris pour modifier les paramètres en temps réel.
- **Réinitialiser la vue** : Touche `R`.
- **Quitter** : Touche `Échap` ou fermer la fenêtre.

## Dépendances

- **MiniLibX** : Bibliothèque graphique utilisée pour l'affichage.
- **Libft** : Bibliothèque de fonctions standard C développée dans le cadre du cursus 42.

Ces bibliothèques sont incluses dans le dépôt pour faciliter la compilation.

## Captures d'écran

*A venir*

## Auteurs

- **PageBlanc** - [Profil GitHub](https://github.com/PageBlanc)

---

N'hésitez pas à explorer le code, à proposer des améliorations ou à signaler des problèmes via des issues. Bon voyage dans le monde fascinant des fractales ! 🚀
