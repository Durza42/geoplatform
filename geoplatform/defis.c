/*
 * defis.c
 * This file is part of geoplatform
 *
 * Copyright (C) 2020 - malo.montillaud-ubuntu
 *
 * geoplatform is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * geoplatform is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with geoplatform. If not, see <http://www.gnu.org/licenses/>.
 */


/*
 *    ce fichier contient tous les défis pouvant donner des skins
 */




   /* choit du défi */
void defis (Var *var, Gal *gal) {

   int defi = 0;

   char str [2][7];

   str [0][0] = 'd';
   str [0][1] = 'e';
   str [0][2] = 'f';
   str [0][3] = 'i';
   str [0][4] = ' ';
   str [0][5] = '1';
   str [0][6] = '\0';

   str [1][0] = 'd';
   str [1][1] = 'e';
   str [1][2] = 'f';
   str [1][3] = 'i';
   str [1][4] = ' ';
   str [1][5] = '2';
   str [1][6] = '\0';

   SDL_Texture *texts [2] = {gal -> cadena, gal -> cadena_ouvert};

   defi = menu_X_poss_with_imgs (2, 7, str, texts, gal -> select, var -> fenetre, var -> renderer, var -> police);

   switch (defi) {
      case 1:
         defi_1 (var, gal);
     break;
      case 2:
         defi_1 (var, gal);
     break;
      default:
     break;
   }

}



   /* défi #1. renvoie true si réussit, false sinon */
bool defi_1 (Var *var, Gal *gal) {

   /* ce défi consiste à réussir tout l'entrainement sans mourir une seule fois */

   int bp = 0;

   for (var -> lvl = 1 ; var -> lvl < NB_LVLS [0] + 1 ; var -> lvl += 1) {

      init_lvls (var, gal); // on initialise le niveau correspondant
      bp = boucle_principale_no_dead (var, gal); // LE jeu en lui même... mais interdit de mourir !

      if (bp == -1) { // on a quitté
         exit_geoplatform (var, gal);
         bp = 0;
      }
      else if (bp == 0) { // le joueur a fait game over

         afficher_message ("vous avez rate le defi. appuillez sur retour pour retourner au menu des mondes.", 79, var -> fenetre, var -> renderer, var -> police); // on affichele message passé en paramètre

         att_touche (SDLK_RETURN); // on attend l'appuit sur retour
         return false; // on retourne "perdu"
      }
   }
      /* si on arrive ici, le perso a gagné */
   afficher_message ("vous avez gagne le defi ! appuillez sur retour pour retourner au menu des mondes. Vous avez gagne un nouveau personnage.", 121, var -> fenetre, var -> renderer, var -> police);

   var -> nb_skins += 1; // le perso a 1 skin de plus

   att_touche (SDLK_RETURN); // on attend l'appuit sur retour
   return true; // on retourne "perdu"
}






   /* traite les evenement. retourne false si il faut quitter, true si le jouer veut continuer. le tout, sans mourir...*/
int boucle_principale_no_dead (Var *var, Gal *gal) {

   SDL_Event event; // stockera les evenements

   bool ctrl = false, q = false, space = false; // 3 variables qui prennent la valeur true si les touches (respectivement) <control>, <q> ou <espace> sont appuillées

   int itt = 0; // nombre d'ittérations de la boucle principale. les premières itérations, le perso avence sur la fenetre, après, c'est la fenetre qui bouge.

   int paused = 0; // prendra la valeur de pause ()

   while (1) {

      SDL_Delay (15);

      itt++; // une ittération de la boucle en plus

      decaler_sprites (var, itt); // on fait bouger tous les sprites pour donner une impression de mouvement

      action_event (var, space); // on agit selon l'évenement

      if (test_game_over (var, gal, NULL)) // le perso a perdu ; point. il n'avait pas le droit.
         return 0;

      if (test_win (var, gal))
         return 1; //on retourne 1 : le perso à gagné

      while (SDL_PollEvent (&event)) { // il y a eu un evenement depuis la derniere fois

         refresh (var, gal);

         if (event.type == SDL_WINDOWEVENT) { // une touche est pessée
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) // Fermeture de la fenêtre
               return -1;//on quitte le programe
         }
         else if (event.type == SDL_KEYDOWN) { // une touche est pessée

            if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche appuillée est <ctrl gauche> ou <ctrl droite>
               ctrl = true;
            else if (event.key.keysym.sym == SDLK_q) // la touche appuillée est <q>
               q = true;
            else if (event.key.keysym.sym == SAUTER) // on demande de sauter (définit dans params.h)
               space = true;

            if (event.key.keysym.sym == PAUSE) { // on demande de mettre en pause (définit dans params.h)

               paused = pause (); // on met le jeu en pause

               if (paused == 1) // pause vaut 1, il y a eu demande de fermetture lors de pause
                  return -1; // on quitte
               else if (paused == 3) // pause vaut 3
                  space = false; // comme <espace> a été relaché pendant la pause, space vaut maintenant false

               paused = 0; // on remet paused à 0
            }

            if (event.key.keysym.sym == REGLAGES) { // on demande d'accéder aux réglages (définit dans params.h)
               params (var, gal);
            }
         }
         else if (event.type == SDL_KEYUP) { // une touche est relachée

            if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche relachée est <ctrl gauche> ou <ctrl droite>
               ctrl = false;
            else if (event.key.keysym.sym == SDLK_q) // la touche relachée est <q>
               q = false;
            else if (event.key.keysym.sym == SAUTER) // la touche relachée est celle qui correspond à l'action sauter
               space = false;
         }
      }

      if (ctrl && q) // les touches <controle> et <q> sont appuillées
         return -1; // on quitte

      refresh (var, gal);
   }
}





