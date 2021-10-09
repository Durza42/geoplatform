
/*
 * intros_musiques.c
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



void redirect_intro_musique (Var *var, Gal_mus *gal_mus, Gal *gal) {

   char title [] = "                                 ";
   char compositeur [] = "                               ";
   char tire_de [] = "                                                                             ";

   if (var -> lvl == 5) {
      if (!gal_mus -> deja_vu [var -> lvl - 1]) {
         sprintf (title, "titre : for a few dollars more%c", '\0');
         sprintf (compositeur, "compositeur : ennio morricone%c", '\0');
         sprintf (tire_de, "tire de : for a few dollars more (film de Sergio Leone)%c", '\0');
      }
   }
   else if (var -> lvl == 6) {
      if (!gal_mus -> deja_vu [var -> lvl - 1]) {
         sprintf (title, "titre : man with harmonica%c", '\0');
         sprintf (compositeur, "compositeur : ennio morricone%c", '\0');
         sprintf (tire_de, "tire de : Once upon a time in the west (film de Sergio Leone)%c", '\0');
      }
   }
   else if (var -> lvl == 7) {
      if (!gal_mus -> deja_vu [var -> lvl - 1]) {
         sprintf (title, "titre : My fault ?%c", '\0');
         sprintf (compositeur, "compositeur : ennio morricone%c", '\0');
         sprintf (tire_de, "tire de : My name is nobody (film de Sergio Leone)%c", '\0');
      }
   }
   else if (var -> lvl == 8) {
      if (!gal_mus -> deja_vu [var -> lvl - 1]) {
         Mix_PauseMusic ();

         sprintf (title, "titre : The wild horde%c", '\0');
         sprintf (compositeur, "compositeur : ennio morricone%c", '\0');
         sprintf (tire_de, "tire de : My name is nobody (film de Sergio Leone)%c", '\0');
      }
   }

   if (gal_mus -> long_intro [var -> lvl - 1] > 0)
      intro (title, compositeur, tire_de, gal_mus -> long_intro [var -> lvl - 1], var, gal);
   else
      intro (title, compositeur, tire_de, 20000, var, gal);

   if (gal_mus -> long_intro [var -> lvl - 1] == -1)
      Mix_ResumeMusic ();
}





void intro (char *title, char *compositeur, char *tire_de, int long_intro, Var *var, Gal *gal) {

   SDL_Event event; // stockera les evenements

   bool ctrl = false, q = false; // 2 variables qui prennent la valeur true si les touches (respectivement) <control> ou <q> sont appuillées

   int paused = 0; // prendra la valeur de pause ()

   unsigned int tmp_transac = 0;
   short int transac = 1;

   afficher_message (title, 0, var -> fenetre, var -> renderer, var -> police);

   while (1) {

      SDL_Delay (30);

         /* on change me message affiché */
      if (long_intro < SDL_GetTicks ()) {
         return;
      }
      else if (tmp_transac + long_intro / 3  < SDL_GetTicks ()) {
         if (transac == 1) {
            afficher_message (compositeur, 0, var -> fenetre, var -> renderer, var -> police);

            tmp_transac = SDL_GetTicks ();
            transac = 2;
         }
         else {
            afficher_message (tire_de, 0, var -> fenetre, var -> renderer, var -> police);

            tmp_transac = SDL_GetTicks ();
            transac = 5;
         }
      }

      while (SDL_PollEvent (&event)) {
         if (event.type == SDL_WINDOWEVENT) { // un event de fenetre est survenu
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) // Fermeture de la fenêtre
               exit_geoplatform (var, gal); // on quitte
         }
         else if (event.type == SDL_KEYDOWN) { // une touche est pessée

            if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche appuillée est <ctrl gauche> ou <ctrl droite>
               ctrl = true;
            else if (event.key.keysym.sym == SDLK_q) // la touche appuillée est <q>
               q = true;

            if (event.key.keysym.sym == PAUSE) { // on demande de mettre en pause (définit dan params.h)

               paused = pause (); // on met le jeu en pause

               if (paused == 1) // pause vaut 1
                  exit_geoplatform (var, gal); // on quitte

               paused = 0; // on remet paused à 0
            }

            if (event.key.keysym.sym == REGLAGES) { // on demande d'accéder aux réglages (définit dans params.h)
               if (params (var, gal) == 1) {
                  return;
               }
               if (tmp_transac + long_intro / 3  < SDL_GetTicks ()) {
                  if (transac == 1) {
                     afficher_message (compositeur, 0, var -> fenetre, var -> renderer, var -> police);
                  }
               }
               else {
                  afficher_message (tire_de, 0, var -> fenetre, var -> renderer, var -> police);
               }
            }
         }
         else if (event.type == SDL_KEYUP) { // une touche est relachée

            if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche relachée est <ctrl gauche> ou <ctrl droite>
               ctrl = false;
            else if (event.key.keysym.sym == SDLK_q) // la touche relachée est <q>
               q = false;
         }

         if (ctrl && q) { // les touches <controle> et <q> sont appuillées
            exit_geoplatform (var, gal); // on quitte
            q = false;
            ctrl = false;
         }
      }
   }
}












