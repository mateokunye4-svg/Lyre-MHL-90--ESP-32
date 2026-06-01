Ce projet utilise une ESP-32 et une carte Arduino. En effet, j'utilise une lyre type MHL 90 pour établir un protocole communication via requête POST pour pouvoir avoir un jeu de lumière.

Fonctionnement du système:

-Nous utilisons donc une ESP-32 et une carte Arduino avec deux codes distincts. Un code pour la carte Arduino avec la bibliothèque DMXSimple pour pouvoir piloter la lyre. Et un code pour l'ESP-32 pour pouvoir établir la communication entre l'étudiant ER et l'IR, l'étudiant IR établit la communication avec Node red.

-Le shield est utilisé sur la carte et avec le composant DMX.

-Le programme Arduino étant réalisé avec un JSON fonctionnelle et le programme ESP-32 fonctionnelle, l'étudiant IR n'a plus qu'à faire bouger comme il le souhaite ma lyre.
