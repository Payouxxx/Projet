# Projet

Ce projet consiste en une simulation d'une boite de Pétri, modélisant les interactions entre différents nutriments et différentes bactéries durant un certain laps de temps, selon des paramètres modifiables tels que la température ou la sensibilité aux nutriments.

Il existe deux types de utriments, des bleus et des verts, se différentiant par la température à laquelle ils peuvent grandir et leur impact sur les bactéries.

Chaque espèce de bactéries est caractérisée par certains paramètres : une couleur, une énergie, une direction, des paramètres mutables... 
Dans le cadre de ce projet, nous avons construit trois types de bactéries, se différenciant par leur aspect, leur façon de se déplacer, ect : 
- les Simple qui sont initialement bleues, ont un flagelle et se déplacent vers la plus grande quantité de nutriments indépendemment les unes des autres
- les Swarm (5 types différents) qui sont de différentes couleurs et ont comme caractéristque principale le déplacement groupé suivant une bactére leader, et qui relachent du poison dans la boite (nocif pour les autres types de bactéries et les autres types de swarm)
- les Twitching qui sont initialement rouges et possèdent un tantacule avec un grappin qui les tracte jusqu'à un nutriment s'il en rencontre
Chaque bactérie dépend de paramètres lui permettant de plus ou moins s'adapter au milieu : se déplacer, se nourrir, mourir, se faire infecter (poison et virus), se diviser.


##CIBLES PRINCIPALES

- application : correspond à la version finale du projet (visualisation de toutes les bactéries et nutriments et ajouts d'extensions et graphes)
- simpleBactTest : évolution des SimpleBacterium uniquement
- swarmTest : évolution des SwarmBacterium uniquement
- twtichingTest : évolution des TwitchingBacterium uniquement
- nutrimentTest : évolution des nutriments
et d'autres tests qui sont moins pertinents graphiquement et en terme d'évolution.


##COMMANDES

Les commandes sont indiquées dans une fenêtre d'aide à gauche de la simulation.
Elles permettent de changer la température, le gradient (sensibilité aux nutriments), les courbes affichées, d'ajouter des objets dans la boite (bactérie, nutriments, virus, adn...)


##MODIFICATION DE CONCEPTION

L'énoncé initial du projet a été intégralement réalisé. Cepandant, des ajouts ont été apportés :
- une lampe qui fait croitre les nutriments quand elle passe intégralement dessus, et met les bactéries dans un état d'abstinence, bien que leur permettant de perdre de l'énergie moins vite
- des morceaux d'ADN qui ont un impact différencié sur chacune des bactéries (l'ADN n'est absorbable qu'une fois par bactérie et est transmis à ses descendants, de plus il ne peut y avoir que 5 morceaux d'ADN en même temps dans la boite)
- des virus qui ont une probabilité différente d'infecter selon le type de bactérie (si l'infection est réussie, la bactérie meurt et le virus se clone, sinon la bactérie survit et ne pourra plus être infectée et le virus meurt)
- les nutriments se dégradent d'eux mêmes au bout d'un certain temps, différent selon le type de nutriment
- les Swarm sont maintenant capables, si l'essaim atteint une certaine taille, de projeter du poison qui atteint toutes les bactéries qui ne sont pas du swarm qui l'a émis. 


##FICHIER DE CONFIGURATION

Les fichiers de configuration à utiliser pour application sont les fichiers app.json, app2.json et app3.json.
Le premier contient le fichier de configuration de base fourni, plus les valeurs nécessaires à nos extensions.
Le app2 correspond à une génération unique des nutriments bleus, mettant en avant la survie prononcée des TwitchingBacterium.
Le app3 permet la génération de nutriments verts uniquement, qui équilibre la survie de toutes les bactéries dans la simulation.

De part la résistance et l'empoisonnement, un environnement contenant des nutriments bleu en quantité équivalente ou inférieure aux ntriments verts est très favorable aux TwitchingBacterium  et défavorable voire très défavorable aux autres. Jouer sur ces facteurs permet une meilleure survie de tous les types de bactéries.
Augmenter le gradient permet aux bacteries de mieux percevoir les nutriments proches d'eux, favorable aux Twitching.
Avec que des nutriments verts, la survie ou mort d'une espèce dépend plus ou moins du hasard.