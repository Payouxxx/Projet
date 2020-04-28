#Projet programmation orientée objet (SSV)

##REPONSES du groupe *28* (*Claire Payoux* & *Florence Crozat*) 

*************************************************
##Q1.1


- On évite la duplication de code en utilisant les méthodes codées préalablement.

*************************************************
##Q1.2


- On choisit la surcharge externe qui est préférable quand on le peut, ce qui était le cas pour tous les opérateurs puisque des fonctions get et set étaient programmées, sauf pour l'opérateur d'affectation sur lequel la syntaxe aurait été lourde puisaue cet opérateur est proche de la classe.

*************************************************
##Q1.3


- Les arguments de méthodes justifiant un passage par référence constante sont tous les arguments qui n'ont pas a etre modifiés par la méthode et qui risquent de prendre de la mémoire (classes par exemple).

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
##Q3.5


- Il faut ajouter à la méthode update de Lab un appel à la méthode update de l'attribut de type NutrimentGenerator pour générer automatiquement des nutriments.

*************************************************
##Q3.6


- La méthode set() peut s'occuper du plafonnage de l'attribut value entre les bornes min et max si elles sont effectives.

*************************************************
##Q3.7


- Il faut mettre les 2 méthodes probability et les 2 positive en "static" dans le header de la classe pour ne pas créér de nouvelle instance à chaque appel de ces méthodes. 

*************************************************
##Q3.8


- La classe Bacterium hérite de CirularBody et des classes Drawable et Updatable car Bacterium utilise une méthode update et drawOn. Au niveau des attributs, Bacterium a besoin d'une énergie modélisée comme une "Quantity" (=double), un Vec2d pour sa direction, un booléen pour savoir si elle est en abstinence ou non. Un MutableColor pour la couleur de la bactérie et une liste de paramètres mutables modélisés à l'aide d'un sf::map<string, MutableNumber>. Pour les méthodes, il y a bien sur update et drawOn, mais aussi une méthode alive permettant de savoir si la bactérie est encore en vie, une méthode clone qui lors de la divison scinde en 2 la bactérie et une méthode move pour le déplacement de la bactérie en fonction du temps.

*************************************************
##Q3.9


- La méthode Bacterium::move(sf::Time dt) aurait besoin d'être virtuelle pure car elle diffère pour chaque type de bactérie et la méthode Bacterium::clone() devrait aussi être virtuelle car toutes les bacteries ne se divisent pas de la meme façon et chaque bactérie ne peut se divisier qu'en 2 autres bacteries de même type. Update et drawOn sont des virtuelles héritées de Drawable et Updatable.

*************************************************
##Q3.10


- La méthode getConfig pour la classe Bacterium doit être virtuelle pure car elle doit s'adapter automatiquement à la nature réelle de l'instance pointée par b. 

*************************************************
##Q3.11


- On retrouve la couleur SFML de la bactérie en faisant appel à la méthode get() de la classe MutableColor sur l'attribut "couleur" de la bacterie.

*************************************************
##Q3.12


- Non ça n'est pas un frein car la méthode move() est une méthode virtuelle.

*************************************************
##Q3.13


- Pour coder la méthode Lab::getNutrimentColliding(CircularBody const& body), il faut créer une nouvelle méthode dans la classe PetriDish PetriDish::getNutrimentColliding(CircularBody const& body) puis l'appeler dans le Lab.

*************************************************
##Q3.14


- Il faut modifier PetriDish::update(sf::Time dt) afin de pouvoir appeler la méthode Bacterium::update(sf::Time dt) sur toutes les bactéries de PetriDish.

*************************************************
##Q3.15


- Pour faire en sorte que les bactéries et sources de nutriments meurent/disparaissent si leur énergie/quantité devient nulle, nous avons modifié la méthode PetriDish::update(sf::Time) en effectuant un test pour chaque nutriment/bactérie afin de vérifier leur état de quantité/énérgie et de les transformer en nullptr si vide/morte. Puis nous avons erase les nullptr de nos vecteurs de nutriments et bacteries.

*************************************************
##Q3.16


- La classe SimpleBacterium, en tant qu'objet soumis à une force de déplacement, doit hériter de la classe DiffEqFonction pour hériter de la méthode virtuelle pure f calculant la force, qui devra être redéfinie. 

*************************************************
##Q3.17


- Il faudrait déclarer et initialiser le temps t dans un endroit où il pourra être incrémenté en fonction du temps, par conséquent t devrait être un attribut de la classe SimpleBacterium qui sera incrémenté dans la méthode update redéfinie dans SimpleBacterium. Il sera initialisé dans le constructeur d'une SimpleBacterium.

*************************************************
##Q3.18


- Pour mémoriser l'angle de direction, il faudrait l'initialiser en tant qu'attribut d'une Bacterium et lui donner la valeur direction.angle(), puis le mettre à jour dans la foncion Bacterium::drawOn en ajoutant une ligne angleDir=direction.angle() afin de s'assurer d'avoir toutjours le bon angle.

*************************************************
##Q3.19


- On doit donc ajouter à PetriDish un nouvel argument puissance, à initialiser dans le consutructeur selon les indications de l'énoncé, puis de coder un PetriDish::getPositionScore que l'on pourra réutiliser dans Lab, qui retournera la somme des scores pour chaque source de nutriments pour une position p donnée en paramètre.

*************************************************
##Q3.20


- La probabilité de basculement est une propiété des bactéries simples et il faut ensuite ajouter un compteur de temps dt pour les bactéries simples qui mesurera le temps entre deux baculements. Ces attributs seront initialisés dans les constructeurs respectifs à 0 (pour éviter une valeur aléatoire) et sf::Time::Zero, puis mis à jour dans la fonction move, qui est appelée dans la fonction update.

*************************************************
##Q3.21


- Il faudrait utiliser la méthode mutate à MutableNumber afin que chacun des paramètre mutable de la bactérie puissent muter séparément, dans une nouvelle méthode update codée dans Bacterium. 

*************************************************
##Q3.22


- Les méthodes addProperty et getProperty seront adaptées dans Bacterium afin de pouvoir influer sur l'attibut std::map<string, MutableNumber>

*************************************************
##Q3.23


- La méthode de division d'une bactérie sera placée dans la classe Bacterium puisque toutes les bactéries pourront se diviser. 

*************************************************
##Q4.1


- La classe TwitchingBacterium hérite de Bacterium en tant qu'elle est un type de bacterie au même titre qu'une SimpleBacterium

*************************************************
##Q4.2


- En redéfinissant le méthode getConfig() de Bacterium comme nous l'avions fait dans SimpleBacterium

*************************************************
##Q4.3


- Il faut impérativement redéfinir les méthodes qui étaient virtuelles pures dans Bacterium, c'est à dire : move(sf::Time dt), clone(), getConfig() bien sur et le destructeur qui n'est pas hérité.

*************************************************
##Q4.4


- Nous avons crée des getteurs pour accéder aux valeurs associées à ["energy"]["consumption factor"]["move"] getEnergieMove() et à ["energy"]["consumption factor"]["tentacle"] getEnergieTentacle()

*************************************************
##Q4.5


- Nous avons crée un type énuméré "etat" ayant comme valeurs les différents états possible pour la bactérie. Puis une variable state de type etat que l'on passe en paramètre d'un switch afin de traiter tous les états possibles.

*************************************************
##Q4.6


- L'assiette de Pétri contient des Swarm donc la classe PetriDish doit contenir elle aussi une méthode addSwarm qui sera appelée dans la classe Lab sur la boite qu'elle contient. La classe PetriDish contiendra donc un nouvel attribut std::vector<Swarm>

*************************************************
##Q4.7


- La bacterie étant une force soumise à un objet, elle peut hériter de la classe DiffEqFunction modelisant cette force. 

*************************************************
##Q4.8


- Il faudra impérativment redéfiir les classes move, getConfig et clone, ainsi que DiffEqFunction::f afin d'avoir une classe instanciable et polymorphyque.

*************************************************
##Q4.9


- La méthode getSwarmWithId(id) devra donc être ajoutée à la classe Lab, elle devra retourner d'après la manière dont le code est mis en place un pointeur sur le Swarm dont l'identifiant entier est id.

*************************************************
##Q4.10


- Le destructeur de PetrDish se charge d'éliminer les bactéries de l'assiette mais le destructeur de Swarm doit se charger d'éliminer les bactéries de son swarm s'il disparait avant la PetriDish.
- Si le Swarm meurt seulement quand il n'y a plus de bactéries dedans, cependant, alors l'assiette s'est déjà occupée de l'élimination des bactéries.

*************************************************
##Q4.11


- Pour dissocier une SwarBacterium de son Swarm, il faudrait utiliser dans le destructeur d'une SwarmBacterium le fait qu'elle se retire de son Swarm, avec la méthode Swarm::removeSwarmBacterium que nous avons du programmer.

*************************************************
##Q5.1


- Il n'est pas conseillé de tester le type d'un objet à l'exécution car si l'objet passé en paramètre appartient à un sous-classe du paramètre (NutrimentB pour Nutriment) alors qu'on s'attend à un objet d'une autre sous-classe (NutrimentA), comme la méthode n'est pas polymorphique on pert les propriétés des sous-classes. 

*************************************************
##Q5.2


- Il faut aussi créer une méthode Nutriment::eatenby(Bacterium& bact), qui prend donc en paramètre un bacterie de la super classe, pour pouvoir l'appeler dans la méthode Bacterium::eat sans problème car eat s'applique sur une bacterie générale et non pas une des sous classes.

*************************************************
##Q5.3


- Nous avons créé deux map, l'une liant les id et les libellés, l'autre liant les libellés et les graphes, ce qui au final relie les 3 informations. 

*************************************************
##Q5.4


- Afin de pouvoir compter les instances spécifique de chaque type, il serait judicieux d'ajouter des méthodes getCompteur à la classe Bacterium qui serait polymorphique (virtuelle pure) et retournerait le compteur qui serait un attribut de chaque sous classe de bacterie, incrémenté dans le constructeur et décrémenté dans le destructeur.
- Pour la classe Nutriment un simple food.size() (food étant le vector de nutriments) suffit.
- On définit ensuite un switch dans la méthode fetchData

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
##Q


- réponse à la question 

*************************************************
##Q


- réponse à la question 

*************************************************
