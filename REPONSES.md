#Projet programmation orientée objet (SSV)

##REPONSES du groupe *No groupe* (*Claire Payoux* & *Florence Crozat*) 

*************************************************
##Q1.1


- On évite la duplication de code en utilisant les méthodes codées préalablement.

*************************************************
##Q1.2


- On choisit la surcharge externe qui est préférable quand on le peut, ce qui était le cas pour tous les opérateurs puisque des fonctions get et set étaient programmées, sauf pour l'opérateur d'affectation sur lequel la syntaxe aurait été lourde puisaue cet opérateur est proche de la classe.

*************************************************
##Q1.3


- Les arguments de méthodes justifiant un passage par référence constante sont tous les arguments   qui n'ont pas a etre modifiés par la méthode et qui risquent de prendre de la mémoire (classes par exemple).

*************************************************
##Q1.4


- Les méthodes justifiant une déclaration en tant que const sont les deux "contains", "isColliding" et les deux getters.

*************************************************
##Q2.1


- Il faudrait que la classe PetriDish herite de CircularBody pour être elle même un cercle.

*************************************************
##Q2.2


- La méthode DrawOn semble être la seule méthode qui ne modifie pas la boite de Pétri donc la seule adaptée avec un const. 

*************************************************
##Q2.3


- Il faut supprimer le constructeur de copie et l'opérateur d'affectation avec la commande =delete.

*************************************************
##Q2.4


- Il va falloir l'espace mémoire occupé par les tableaux de pointeurs de la boite de Pétri.

*************************************************
##Q2.5


- On peut utiliser les fonctions de même nom déja programmées de la boite de Pétri.

*************************************************
##Q2.7


- La classe nutriment doit hériter de la classe CircularBody et le fichier correspondant au code de la classe doit être inclus dans le fichier de Nutriment.

*************************************************
##Q2.8


- Le type Quantity est utile pour une question de meilleure lisibilité du code.

*************************************************
##Q2.9


- Il nous faut une méthode addNutriment dans la classe Lab pour pouvoir correspondre au code de NutrimentTest.
De plus la méthode onEvent de NutrimentTest a besoin d'un sf::Event en argument donc il nous faut une méthode 
dans la classe Lab qui retournera un sf::Event afin de faire fonctionner l'affichage via cette méthode onEvent, 
il faudrait donc modifier la méthode DrawOn de la classe PetriDish pour que les nutriments se dessinent d'eux même.

*************************************************
##Q2.10


- La fonction getAppEnv retourne un Lab donc on peut utiliser un getTempérature dans la classe Lab utilisant 
le getTemperature de la boite de pétri pour accéder à la température de la boite sans donner d'accès à la boite 
de Pétri entière.

*************************************************
##Q2.11


-il faut modifier les méthodes update de Lab et PetriDish qui doivent appeler la méthode update de Nutriments. 
Nous avions cependant déjà effectué les liens entre ces méthodes et la question nous a beacoup perturbée.

*************************************************
##Q2.12


- Il faut ajouter des méthodes increaseTemperature et decreaseTempertature dans les classes Lab et PetriDish pour 
modifier la température. On peut de plus ajouter dans le fichier Application dans la gestion de la touche C 
pour pouvoir mieux recharger la configuration, en ajoutant un appel à une fonction réinitialisant la tepérature 
qui serait dans PetriDish et dans Lab.

*************************************************
##Q


- réponse à la question 

*************************************************
##Q


- réponse à la question 

*************************************************
##Q


- réponse à la question 

*************************************************
##Q


- réponse à la question 

*************************************************