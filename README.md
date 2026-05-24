# Fract-ol

Bienvenue dans **Fract-ol**, mon interprétation du projet de l'école 42 consistant à générer et explorer des fractales célèbres telles que Mandelbrot et Julia.

## Description

**Fract-ol** est un programme graphique qui permet de visualiser et d'interagir avec différentes fractales. Une fractale est une figure géométrique fragmentée qui se répète à l'infini à des échelles plus petites. Ce projet utilise la bibliothèque graphique MiniLibX de l'école 42.

## Fonctionnalités

- **Fractales disponibles** : Mandelbrot, Julia, Burningship.
- **Zoom** : Utilisez la molette de la souris.
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

## Compilation et Exécution avec Docker

**Fract-ol** est aussi disponible en tant qu'image Docker, ce qui permet de compiler et exécuter le projet sur n'importe quel PC sans installer les dépendances manuellement.

### Prérequis

- **Docker** (v29+)
- **docker-compose** ou `docker compose` (intégré à Docker)

### Utilisation

1. **Via Makefile** (recommandé) :

   ```bash
   # Compiler l'image Docker
   make docker-build

   # Lancer les différentes fractales
   make docker-mandelbrot
   make docker-julia
   make docker-burningship

   # Nettoyer les conteneurs et l'image Docker
   make docker-clean
   ```

2. **Directement avec docker compose** :

   ```bash
   # Construire et exécuter Mandelbrot
   docker compose build
   docker compose run --rm fract-ol ./fract-ol mandelbrot
   ```

### Notes

- Sur Linux, le programme affichera l'interface graphique directement.
- L'image Docker inclut automatiquement toutes les dépendances (build-essential, X11, libXext, libX11, etc.).
- Les conteneurs sont automatiquement supprimés après exécution grâce au flag `--rm`.
- Pour nettoyer les conteneurs orphelins : `make docker-clean`

## Contrôles

- **Zoom** : Molette de la souris.
- **Déplacement** : Touches fléchées.
- **Changer de palette de couleurs** : Touches `-` ou `+`.
- **Pour le changement continue de couleur** : Touches `m`
- **Activation/Désactivation du mode interactif pour Julia** : Clique droit de la souris.
- **Mode interactif pour Julia** : Déplacez la souris pour modifier les paramètres en temps réel.
- **Quitter** : Touche `Échap` ou fermer la fenêtre.

## Dépendances

- **MiniLibX** : Bibliothèque graphique utilisée pour l'affichage.
- **Libft** : Bibliothèque de fonctions standard C développée dans le cadre du cursus 42.

Ces bibliothèques sont incluses dans le dépôt pour faciliter la compilation.

## Captures d'écran

- Julia:  
  
   - ![julia2](https://github.com/user-attachments/assets/77eddab9-739b-4de7-bd9f-400dbce93a3a)  
   - ![julia3](https://github.com/user-attachments/assets/09bc39be-e760-43c5-b395-de80fdcc16a4)  
   - ![julia4](https://github.com/user-attachments/assets/7be9d4e4-ada4-4a96-81f1-65c30225c79f)
- Mandelbrot:
  
   - ![Mandelbrot1](https://github.com/user-attachments/assets/9fcdd921-81e8-4a94-ad4b-15ce55ade587)  
- Burningship:  
  
   - ![Burningship](https://github.com/user-attachments/assets/f0b4df7e-2fbd-437e-85c1-496a678b90b1)  
   - ![Burningship1](https://github.com/user-attachments/assets/75c79a3b-431e-4ac6-b012-87e2b66a0199)  

## Auteurs

- **PageBlanc** - [Profil GitHub](https://github.com/PageBlanc)

---

N'hésitez pas à explorer le code, à proposer des améliorations ou à signaler des problèmes via des issues. Bon voyage dans le monde fascinant des fractales ! 🚀
