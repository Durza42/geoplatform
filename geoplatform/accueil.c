/*
 * acceil.c
 * This file is part of geoplatform
 *
 * Copyright (C) 2020 - malo.montillaud-ubuntu
 *
 * geoplatform is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * geoplatform is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with geoplatform. If not, see <http://www.gnu.org/licenses/>.
 */


/*
 *    ce fichier rescence les fonction appelées pour le visuel de la mise en route.
 */



   /* écran de départ (selection de niveau, assignation des touches, vitesse, etc.) */
int select_lvl (Var *var, Gal *gal, int monde) {
   
   var -> Rrender.x = 0; // on remet l'écran titre à 0

      /* on affiche notre image gal -> ecran_titre */
   SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
   SDL_RenderCopy (var -> renderer, gal -> ecran_titre, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre
   if (var -> aff) // si on doit afficher la texture params
      SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetred
   SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

   SDL_Event event; // variable dans laquelle sera stocké les evenements

   bool ctrl = false, q = false; // ces 2 variables prendront la valeur true si appuillées. si elles sont toutes deux appuillées, on quitte

   int lvl = 1, i = 0; // niveau retourné, pour parcourir des boucles

      /* on attend la selection de nivrau ou la fermetture de la fenetre */
   while (true) { // boucle infinie

      SDL_WaitEvent (&event); // on attend un evenement

      if (event.type == SDL_QUIT) // demande de quitter
         return -1;

      if (event.type == SDL_KEYDOWN) // appuie sur une touche
         if (event.key.keysym.sym == SDLK_RETURN) { // la touche appuillée est <enter>
            return lvl; // fin de la fonction donc de la boucle infinie, on retourne le niveau demandé
         }
         else if (event.key.keysym.sym == SDLK_ESCAPE) { // la touche appuillée est <enter>
            return -10; // fin de la fonction donc de la boucle infinie, on retourne -10 : on retourne au menu des mondes
         }
         else if (event.key.keysym.sym == SDLK_a) { // la touche appuillée est <enter>
            boucle_arcade (var, gal); // fin de la fonction donc de la boucle infinie, on retourne le niveau demandé

            SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
            SDL_RenderCopy (var -> renderer, gal -> ecran_titre, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre
            if (var -> aff) // si on doit afficher la texture params
               SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetred
            SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

         }
         else if (event.key.keysym.sym == REGLAGES) { // on demande les réglages
            params (var, gal);

            SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
            SDL_RenderCopy (var -> renderer, gal -> ecran_titre, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre

            if (var -> aff) // si on doit afficher la texture params
               SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetre

            SDL_RenderPresent (var -> renderer); // on met la fenetre à jour
         }
         else if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche appuillée est <ctrl gauche> ou <ctrl droite>
            ctrl = true;
         else if (event.key.keysym.sym == SDLK_q) // la touche appuillée est <q>
            q = true;
         else if (event.key.keysym.sym == SDLK_RIGHT) { // la touche appuillée est <flèche droite> ; on demande un niveau plus difficile
            if ((monde - 1) * 4 + lvl < var -> lvl_max_atteint && lvl + 1 <= 4) { // si le niveau plus difficile est débloqué
               lvl += 1; // on retournera un niveau plus difficile
               for (i = 0 ; i < LONG_WIND / 5 ; i += 1) { // on fait l'opération autant de fois que nécéssaire

                  var -> Rrender.x += 5; // on fait bouger la portion de la texture que l'on fait apparaitre à l'écran

                  SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
                  SDL_RenderCopy (var -> renderer, gal -> ecran_titre, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre
                  if (var -> aff) // si on doit afficher la texture params
                     SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetred
                  SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

                  SDL_Delay (5); // on attent r donner une impression de fluidité
               }
            }
         }
         else if (event.key.keysym.sym == SDLK_LEFT) // la touche appuillée est <flèche gauche> ; on demande un niveau plus facile
            if (lvl - 1 > 0) { // si on ne demande pas un niveau négatif...
               lvl -= 1; // on retournera un niveau plus difficile
               for (i = 0 ; i < LONG_WIND / 5 ; i += 1) { // on fait l'opération autant de fois que nécéssaire

                  var -> Rrender.x -= 5; // on fait bouger la portion de la texture que l'on fait apparaitre à l'écran

                  SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
                  SDL_RenderCopy (var -> renderer, gal -> ecran_titre, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre
                  if (var -> aff) // si on doit afficher la texture params
                     SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetred
                  SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

                  SDL_Delay (5); // on attent r donner une impression de fluidité
               }
            }

      else if (event.type == SDL_KEYUP) // une touche est relachée.
         if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche relachée est <ctrl gauche> ou <ctrl droite>
            ctrl = false;
         else if (event.key.keysym.sym == SDLK_q) // la touche relachée est <q>
            q = false;
         
      if (ctrl && q) { // les touches <controle> et <q> sont appuillées
         return -1;
      }
   }
}



   /* récupère les données demandées */
FILE* recup_datas (Var *var, Gal *gal) {

      /* on ouvre le fichier contenant le nom de l'ensemble des fichiers de sauvegarde, et on copie son contenu dans la chaine cont_file */

   FILE *data_file = NULL;

   data_file = fopen ("fichier_de_sauvegarde.sauv", "r+");

   char charac = ' ';

   int nb = 0, i = 0;

   fseek (data_file, 0, SEEK_SET); // on replace le curseur au début du fichier

   do {
      charac = fgetc (data_file); // on lit le caractère [nombre d'ittération de la boucle do] du fichier

      if (charac != EOF) // si ce caractère n'est pas un retour à la ligne ou la fin du fichier
         nb += 1; // il y a un caratère en plus

   } while (charac != EOF); // tant que ce caractère n'est pas un retour à la ligne ou la fin du fichier

   fseek (data_file, 0, SEEK_SET); // on replace le curseur au début du fichier

   char cont_file [nb + 1];

   for (i = 0 ; i < nb ; i += 1) {
      cont_file [i] = fgetc (data_file); // on place les caractères du fichier dans cette chaine
   }
   cont_file [nb] = '\0'; // on place la symbole de fin de chaine pour éviter les segfault

   char lvl = cont_file [0]; // parce que il y a moins de 10 lvl.
   var -> lvl_max_atteint = atoi (&lvl);

   char monde = cont_file [2]; // parce que il y a moins de 10 lvl et moins de 10 mondes.
   var -> monde_max_atteint = atoi (&monde);

   char skins [3] = "  ";
   sprintf (skins, "%c%c", cont_file [4], cont_file [5]);
   var -> nb_skins = atoi (skins);
}





   /* on choisit un monde */
int select_monde (Var *var, Gal *gal) {

   var -> Rrender.x = 0; // on remet l'écran titre à 0

      /* on affiche notre image gal -> ecran_titre */
   SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
   SDL_RenderCopy (var -> renderer, gal -> mondes, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre
   if (var -> aff) // si on doit afficher la texture params
      SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetre
   SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

   SDL_Event event; // variable dans laquelle sera stocké les evenements

   bool ctrl = false, q = false; // ces 2 variables prendront la valeur true si appuillées. si elles sont toutes deux appuillées, on quitte

   int monde = 1, i = 0; // niveau retourné, pour parcourir des boucles

      /* on attend la selection de nivrau ou la fermetture de la fenetre */
   while (true) { // boucle infinie

      SDL_WaitEvent (&event); // on attend un evenement

      if (event.type == SDL_QUIT) // demande de quitter
         return -1;

      if (event.type == SDL_KEYDOWN) // appuie sur une touche
         if (event.key.keysym.sym == SDLK_RETURN) { // la touche appuillée est <enter>
            var -> lvl = select_lvl (var, gal, monde);
            if (var -> lvl != -10)
               return monde;
         }
         else if (event.key.keysym.sym == SDLK_a) { // la touche appuillée est <a>
            boucle_arcade (var, gal); // fin de la fonction donc de la boucle infinie, on retourne le niveau demandé

            SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
            SDL_RenderCopy (var -> renderer, gal -> mondes, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre

            if (var -> aff) // si on doit afficher la texture params
               SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetre

            SDL_RenderPresent (var -> renderer); // on met la fenetre à jour
         }
         else if (event.key.keysym.sym == REGLAGES) { // on demande les réglages
            params (var, gal);

            SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
            SDL_RenderCopy (var -> renderer, gal -> mondes, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre

            if (var -> aff) // si on doit afficher la texture params
               SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetre

            SDL_RenderPresent (var -> renderer); // on met la fenetre à jour
         }
         else if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche appuillée est <ctrl gauche> ou <ctrl droite>
            ctrl = true;
         else if (event.key.keysym.sym == SDLK_q) // la touche appuillée est <q>
            q = true;
         else if (event.key.keysym.sym == SDLK_RIGHT) { // la touche appuillée est <flèche droite> ; on demande un niveau plus difficile

            if (var -> monde_max_atteint > monde) { // si le monde plus difficile est débloqué

               monde += 1; // on retournera un niveau plus difficile

               for (i = 0 ; i < LONG_WIND / 5 ; i += 1) { // on fait l'opération autant de fois que nécéssaire

                  var -> Rrender.x += 5; // on fait bouger la portion de la texture que l'on fait apparaitre à l'écran

                  SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
                  SDL_RenderCopy (var -> renderer, gal -> mondes, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre

                  if (var -> aff) // si on doit afficher la texture params
                     SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetred

                  SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

                  SDL_Delay (5); // on attent r donner une impression de fluidité
               }
            }
         }
         else if (event.key.keysym.sym == SDLK_LEFT) // la touche appuillée est <flèche gauche> ; on demande un niveau plus facile

            if (monde - 1 > 0) { // si on ne demande pas un niveau négatif...

               monde -= 1; // on retournera un niveau plus difficile

               for (i = 0 ; i < LONG_WIND / 5 ; i += 1) { // on fait l'opération autant de fois que nécéssaire

                  var -> Rrender.x -= 5; // on fait bouger la portion de la texture que l'on fait apparaitre à l'écran

                  SDL_RenderClear (var -> renderer); // on nettoie la fenetre (elle est maintenant tout noire)
                  SDL_RenderCopy (var -> renderer, gal -> mondes, &var -> Rrender, NULL); // on copie la partie de la texture correspondant au niveau demandé de ecran titre sur la fenetre

                  if (var -> aff) // si on doit afficher la texture params
                     SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur la fenetred

                  SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

                  SDL_Delay (5); // on attent r donner une impression de fluidité
               }
            }

      else if (event.type == SDL_KEYUP) // une touche est relachée.
         if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche relachée est <ctrl gauche> ou <ctrl droite>
            ctrl = false;
         else if (event.key.keysym.sym == SDLK_q) // la touche relachée est <q>
            q = false;
         
      if (ctrl && q) // les touches <controle> et <q> sont appuillées
         return -1;
   }
}



   /* sauvegarde les données du joueur dans un fichier */
void save_datas (FILE *data_file, Var *var) {

}















