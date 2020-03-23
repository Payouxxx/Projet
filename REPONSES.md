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


- Il nous faut une méthode addNutriment dans la classe Lab pour pouvoir correspondre au code de NutrimentTest. Il faudrait donc modifier la méthode DrawOn de la classe PetriDish pour que les nutriments se dessinent d'eux même, donc appeler la fonction DrawOn des nutriments dans celle de PetriDish.

*************************************************
##Q2.10


- La fonction getAppEnv retourne un Lab donc on peut utiliser un getTempérature dans la classe Lab utilisant le getTemperature de la boite de pétri pour accéder à la température de la boite sans donner d'accès à la boite de Pétri entière.

*************************************************
##Q2.11


- il faut modifier les méthodes update de Lab et PetriDish qui doivent appeler la méthode update de Nutriments. Nous avions cependant déjà effectué les liens entre ces méthodes et la question nous a beacoup perturbée.

*************************************************
##Q2.12


- Il faut ajouter des méthodes increaseTemperature et decreaseTempertature dans les classes Lab et PetriDish pour modifier la température.
- on peut de plus ajouter dans le fichier Application dans la gestion de la touche C (ligne 487 du cpp) pour pouvoir mieux recharger la configuration, en ajoutant un appel à une fonction réinitialisant la tepérature qui serait dans PetriDish et dans Lab.

*************************************************
##Q3.1


- les classes Nutriment, PetriDish, Lab et Bacterium pourraient hériter de ces deux classes.

*************************************************
##Q3.2


- DrawOn et update des nouvelles sous classes doivent être redéfinies et leurs définitions doivent être adaptées pour si le Nutriment est un NutimentA ou un NutrimentB. 

*************************************************
##Q3.3


- La méthode getConfig doit être définie comme virtuelle pure dans la classe Nutriment pour ne pas être définie concretement. Elle doit donc être redéfinie dans les sous classes pour ne pas prendre dans "nutriments" mais dans "nutriment A" ou "nutriment B" selon la sous classe.

*************************************************
##Q3.4


- La méthode getConfig redéfinie permet de changer les caractéristiques des nutriments en recherchant les caractéristiques spécifiques dans le fichier app.json une fois redéfinie comme fait dans la question 3.3 sans changer les méhodes DrawOn et update qui utilisent cette méthode AppConfig.

*************************************************
##Q


- réponse à la question 

*************************************************
##Q3.6


- La méthode setValue() peut s'occuper du plafonnage de l'attribut value. Cette méthode est ensuite appelée dans mutate() et dans le constructeur.

*************************************************
##Q3.7


- Pour ne pas avoir à créer une instance systématiquement, nous avons mis en "static" les méthodes probability et positif.

*************************************************
##Q


- réponse à la question 

*************************************************

*************************************************