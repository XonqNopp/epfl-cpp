
Bonjour!


              /***** * *  _____      ____            ____     ____   * * * * *****/
             /***** * *  /          /    \   /      /    \   /    \   * * * *****/
            /***** * *  /          /     /  /      /     /  /     /  * * * *****/
           /***** * *   \_____    /     /  /      /_____/  /_____/    * * *****/
          /***** * * *        \  /     /  /      /     /  /   \      * * *****/
         /***** * * *         / /     /  /      /     /  /     \    * * *****/
        /***** * * * * ______/  \____/   \____ /     /  /      /   * * *****/

      /***** * *  _____      __  _  __                     ____   ______  ____     ____   * * * * *****/
     /***** * *  /           /  / \/  \   /     /  /      /    \    /    /    \   /    \   * * * *****/
    /***** * *  /           /  /  /   /  /     /  /      /     /   /    /     /  /     /  * * * *****/
   /***** * *   \_____     /  /  /   /  /     /  /      /_____/   /    /     /  /_____/    * * *****/
  /***** * * *        \   /  /  /   /  /     /  /      /     /   /    /     /  /   \      * * *****/
 /***** * * *         /  /  /  /   /  /     /  /      /     /   /    /     /  /     \    * * *****/
/***** * * * * ______/ _/  /  /   /   \____/   \____ /     /   /     \____/  /      /   * * *****/

								By Gael Induni and Steve Neithardt


	,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,


	- utilisateurs de Mac OS X -

IMPORTANT: pour pouvoir utiliser ce programme, vous devez auparavant avoir installe les "Developments tools", qui se trouvent sur les CDs d'installation de Mac OS X. Si vous
n'avez plus ces CDs pour une quelconque raison, il doit etre possible de telecharger les Developments tools depuis le site de Apple au prix d'une simple inscription gratuite.

	- utilisateurs de LINUX -

LINUX a deja un compilateur integre, et le programme ne necessite pas d'installations supplementaires.

	-utilisateurs de Windows -

Etant les 2 des Mac-eux, nous n'avons aucune idee de la facon de faire fonctionner ce programme sous Windows. Neanmoins, nous n'allons pas vous laisser dans l'ignorance et vous empecher d'utiliser notre projet, pour cela c'est tres simple: installer Linux et referrez-vous ensuite au point concernant les utilisateurs Linux...


	,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,

	- Initialisation et Lancement du programme -

Afin de proceder a l'execution du programme, il est necessaire de suivre les etapes suivantes.
1) - Ouvrir un Terminal.
2) - Aller dans le dossier "projet/znugdu/", depuis l'endroit ou se trouve le dossier projet.
3) - Tapez la commande "make". Ceci compile le programme et fait un executable "simulation3dXML".
4) - Ouvrir l'executable depuis le Terminal, en tapant "./simulation3dXML [-start] [-names] [-center] [le_nom_du_fichier.xml]".
5) - Quelques messages seront affiches dans le Terminal, vous renseignant sur les erreurs eventuelles presentes dans [le_nom_du_fichier.xml]. A la fin, le programme vous demande
si vous souhaitez proceder. Vous avez le choix entre arreter le programme (en saisissant "n" dans le Terminal), ou lancer la simulation graphique (en saisissant "y" dans le
Terminal).

Remarques:
1) - Si aucun fichier n'est choisit, le programme utilise "universtest.xml" par defaut.
2) - La commande "make" n'est necessaire qu'a la premiere utilisation du programme. Ensuite, l'executable existe, et n'a pas besoin d'etre refait.
3) - Pour initialiser le programme en utilisant un autre fichier que le fichier par defaut, il est necessaire de choisir un fichier lors de la commande "./simulation3dXML
[le_nom_du_fichier.xml]". [le_nom_du_fichier.xml] est l'adresse complete du fichier d'extension ".xml", depuis le dossier courant.
4) - Pour ecrire un fichier ".xml", se referer a la section correspondante dans ce ReadMe.


	,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,

	- Affichage et Interface Clavier -

- Mouvements de la camera (uniquement dans la fenetre de base)

- translations:
j	gauche
l	droite
i	haut
k	bas

- rotations sur la camer:
a	plan horizontal, vers la gauche
d	plan horizontal, vers la droite
w	plan vertical, vers l'avant
s	plan vertical, vers l'arriere
x	plan de cote, vers la droite
y	plan de cote, vers la gauche

- rotations autour du centre:
^	vers le haut
v	vers le bas
>	vers la droite
<	vers la gauche

- zoom:
+	s'approcher
-	s'eloigner

- Evenements d'affichage

h	active/desactive l'affichage des noms
n	efface l'affichage courant
q	quitte le programme
espace	demarre/met en pause la simulation
c	active/desactive le centrage sur le centre de masse, dans l'affichage de l'univers standard.
w	ferme la fenetre des distances, lorsqu'elle est active.
1-6	passe a l'affichage correspondant.
		1 univers; 2 orbites; 3 projection sur les 3 plans; 4 projection sur le plan X = 0;
		5 projection sur le plan Y = 0; 6 projection sur le plan Z = 0;
t	ne pas appuyer.
z	SURTOUT ne pas appuyer.


	,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,

	- Affichage et Interface Souris -

- Dans la fenetre de base

Clique-droit (Mac: Ctrl-clique)
Ouvre un menu avec differentes options:
	"Simulation" (ouvre un sous-menu)
		"Quitter la simulation" -> quitte la simulation.
		"Arreter Reprendre la simulation" -> met la simulation en pause
		"Activer Desactiver le centrage" -> active ou desactive le centrage sur le centre de masse de l'univers.
		"Activer Desactiver les noms" -> active ou desactive l'affichage des noms a cote des planetes.
		"Effacer l'affichage courant" -> Efface l'affichage courant, pour prendre a zero.
	"Univers" -> change l'affichage courant pour afficher les corps en 3D au moment present.
	"Orbites Tracees" -> change l'affichage courant pour afficher la trace des corps dans le temps, les orbites.
	"Distance entre deux corps" -> Ouvre une deuxieme fenetre qui affiche un graphique de la distance entre deux corps au cours du temps.
	"Projection sur les plans" -> change l'affichage courant pour afficher la projection de la position des corps sur les trois plans.
	"Projection sur le plan des X" -> change l'affichage courant pour afficher la projection de la position sur le plan X = 0.
	"Projection sur le plan des Y" -> change l'affichage courant pour afficher la projection de la position sur le plan Y = 0.
	"Projection sur le plan des Z" -> change l'affichage courant pour afficher la projection de la position sur le plan Z = 0.

- Dans la deuxieme fenetre

Clique-droit (Mac: Ctrl-clique)
Selectionne le premier corps
Clique-milieu (Mac: alt-clique)
Selectionne le deuxieme corps
	"Simulation" (ouvre un sous-menu)
		"Fermer la fenetre" -> ferme la deuxieme fenetre.
		"Quitter la Simulation" -> quitte la simulation.
Si aucun corps n'est selectionne, aucune distance ne s'affiche.
Il est imperatif de choisir deux corps, un dans chaque menu, pour qu'un graphique se dessine.


	,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,

	- Ecriture d'un fichier ".xml"

Pour creer votre propre univers, il faut ecrire un fichier XML avec les donnees necessaires. Pour cela, je vous propose de copier le fichier modele.xml:
ouvrez dans un temrminal, allez dans le dossier projet/znugdu/ et tapez la commande "cp modele.xml [le_nom_du_fichier_que_vous_souhaitez_creer.xml]" Ouvrez ce fichier et passons
a la partie traduction francais-XML...

Si vous voulez mettre des commentaires dans votre fichier afin de mieux comprendre le code XML, ecrivez vos commentaires entre les balises "<!--" et "-->". Pour creer un univers
en XML, il vous faut une balise "<univers>" au debut du fichier et une balise "</univers>" a la fin. Votre univers a une camera qui permet de modifier le point de vue. Il faut
ecrire les balises "<camera>" et "</camera>", qui ouvrent le bloc concernant la camera. Entre ces 2 balises, ecrivez les balises "<oeil>", "</oeil>", "<visee>", "</visee>",
"<verticale>" et "</verticale>". A l'interieur de ces balises, ecrivez 3 nombres reels separes par des espaces. Ce sont des coordonnees cartesiennes. Entre les balises oeil, se
trouvent la position du point de vue, entre les balises visee, la position du point vise, et les coordonnees entre les balises verticale correspondent a l'axe pieds-tete de
l'observateur.

Votre univers contient un temps et un pas de temps. Ecriviez les balises "<temps>", "</temps>", "<pasdetemps>" et "</pasdetemps>". A l'interieur de ces paires de balises,
inscrivez un nombre rationnel, le premier correspondant au temps a partir duquel la simulation s'arretera (entrez une valeur negative si vous voulez que la simulation continue
indeffiniment) et le second au pas de temps effectue a chaque mise a jour.

Vient ensuite la grosse partie de l'initialisation de l'univers, la serie de corps. On utilise les balises "<corps>" et "</corps>". Entre ces balises viennent plusieurs paires
de balises, en voici l'integralite: "<type>" et "</type>", qui precisent le type de corps (etoile, planete ou satellite); "<nom>" et "</nom>", qui indiquent le nom du corps
(Note: il est formellement impossible d'avoir 2 corps differents avec le meme nom!); "<position>" et "</position>", qui correspondent aux coordonnes cartesiennes du centre du
corps (entrez trois nombres rationnels, separes par des espaces); "<vitesse>" et "</vitesse>", prennent aussi trois nombres rationnels, correspondant a la vitesse vectorielle du
corps; "<acceleration>" et "</acceleration>" correspondent a l'acceleration vectorielle (toujours trois nombres rationnels); entre "<masse>" et "</masse>" se trouve la masse du
corps, un nombre rationnel; "<couleur>" et "</couleur>" prennent 4 nombres reels, correspondant aux valeurs de couleurs du corps, avec pour format rouge, vert, bleu et la
transparence (0.0 minimum, 1.0 maximum).

Il ne reste plus qu'a sauvegarder votre fichier (si ce n'est pas encore fait), et de lancer le programme comme il est mentionne plus haut... Bon amusement! :)


	,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,

	- Remerciements -

Nous remercions tout les gens qui nous ont soutenus pendant toute la duree du projet, en repondant et en posant des questions.

Nous remercions egalement les messages d'erreur du Terminal lors de la compilation, qui sont toujours tres significatifs et utiles, ainsi que les plantages lors de l'execution du
programme, avec pour seul message "Abort" ou "Segmentation Fault".


	,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,,,,,,;,,,,

