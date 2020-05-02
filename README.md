# Projet

Nous mettrons pour chaque test 10 bactéries de chaque type en confrontation au bout de 20 nutriments générés.
Les valeurs associées à chaque type de bactérie correspondent à une stabilisation.

**TEST 1:**
Nutriments verts = 100%  
Nutriments bleus = 0% 
génération = 0.5 secondes

*Résultats:*
Twitching = mort
Simple = 10
swarm = 5

Augmentation de la température à 50°C

*Résultats:*
Twitching = 10
Simple = 10 puis mort
swarm = 5

**TEST 2:**
Nutriments verts = 80%  
Nutriments bleus = 20% 
génération = 0.5 secondes
Energie min division = 140

*Résultats:*
Twitching = 30
Simple = 10 puis mort
swarm = mort

Augmentation de la température à 30°C

*Résultats:*
Twitching = 30
Simple = 10 puis mort
swarm = mort

Augmentation de la température à 50°C

*Résultats:*
Twitching = 50
Simple = 10 puis mort
swarm = mort

Augmentation de la température à 60°C

*Résultats:*
Twitching = 50
Simple = mort
swarm = mort

**TEST 3:**
Nutriments verts = 80%  
Nutriments bleus = 20% 
génération = 0.5 secondes
Energie min division = 100

*Résultats:*
Twitching = 50
Simple = mort
swarm = mort

Augmentation de la température à 30°C

*Résultats:*
Twitching = 30
Simple = 10 puis mort
swarm = mort

Augmentation de la température à 50°C

*Résultats:*
Twitching = 50
Simple = mort
swarm = mort

Augmentation de la température à 60°C

*Résultats:*
Twitching = 40
Simple = mort
swarm = mort

**TEST 4:**
Nutriments verts = 0%  
Nutriments bleus = 100% 
génération = 0.5 secondes

*Résultats:*
Twitching = 50
Simple = mort rapide
swarm = mort très rapide

**TEST 5:**
Nutriments verts = 50%  
Nutriments bleus = 50% 
génération = 0.5 secondes

*Résultats:*
Twitching = 20
Simple = mort (au bout d'une trentaine de secondes)
swarm = mort (au bout d'une minute environ)

Augmentation de la température à 30°C

*Résultats:*
Twitching = 40
Simple = mort (au bout d'une minute environ)
swarm = mort (au bout d'une minute trente environ)

**TEST 6:**
Nutriments verts = 50%  
Nutriments bleus = 50% 
génération = 0.5 secondes
poison factor = 2
resistance factor = 5

*Résultats:*
Twitching = 20
Simple = mort (au bout de deux minutes trente environ)
swarm = mort (au bout d'une minute trente environ)

Augmentation de la température à 30°C

*Résultats:*
Twitching = 50
Simple = mort (au bout de deux minutes trente environ voire trois minutes)
swarm = mort (au bout d'une minute trente environ)


###CONCLUSION DES EXPERIMENTATIONS

De part la résistance et l'empoisonnement, un environnement contenant des nutriments bleu en quantité équivalente ou inférieure aux ntriments verts est très favorable aux TwitchingBacterium  et défavorable voire très défavorable aux autres. Jouer sur ces facteurs permet une meilleure survie de tous les types de bactéries.
Augmenter le gradient permet aux bacteries de mieux percevoir les nutriments proches d'eux, favorable aux Twitching.
Avec que des nutriments verts, la survie ou mort d'une espèce dépend plus ou moins du hasard.