Equipe : Gianni Delannoye
         Jade Thiriat
         Loïc Vial

Pour compiler le projet : faire 'qmake' pour générer le Makefile
                          puis 'make' pour compiler le projet
                          enfin './nagasana' pour lancer le projet

Une fenêtre va apparaitre, contenant le sol, un décor, un château, des arbres et un dragon.
La seule action visible initialement est le mouvement de queue du dragon.
Pour lancer le scénario, il faut appuyer sur 'o'.
Le dragon va s'élever, replier ses pattes, et battre des ailes.
Arrivé à une hauteur de croisière, il va se diriger vers le château tout en battant des ailes.
Face au château, il va ouvrir la gueule pour cracher du feu et transfomer le château en cendres.
Une fois son forfait accompli, il arrête de cracher du feu, s'élève de nouveau et tourne autour du château.
Lorsqu'il est autour du château, appuyer et maintenir la touche 'p' lui fait cracher du feu.

La première vidéo, nommée "Attack on Castle" (fichier attack_on_castle.avi) permet d'illustrer l'animation du dragon, de ses membres et de ses ailes ainsi que son déplacement.
Elle permet de voir les différents états de l'attaque du château.
Les ombres sont affichées, avec un léger brouillard ambiant dans la scène.

Une autre version de cette vidéo, "Attack on Castle (White)" (fichier attack_on_castle_white.avi) est identique à la première, à l'exception de la texture du dragon.
Avec cette texture, on peut mieux voir la lumière générée par le feu craché par le dragon quand celui-ci brûle le château (on peut voir l'éclairage rouge sous sa gueule). 

La deuxième vidéo, nommée "Run away", permet d'illustrer l'utilisation d'un sol non plat généré avec une HeightMap, ainsi que la lumière dû au feu sur le torse et sur la bouche du dragon, vu de face.

Les fichiers sources (.cpp) sont dans le dossier src.
Les fichiers d'en-tête (.h) sont dans le dossier include.
Les textures nécessaires à l'application dans dans le dossier res.
