
/*
 * boucle.c
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
 *    ce fichier comprend la boucle principale des evenements. C'est ici que l'on traite les evenements.
 */


   /* traite les evenement. retourne false si il faut quitter, true si le jouur veut continuer. */
int boucle_principale (Var *var, Gal *gal, Gal_mus *gal_mus) {

   SDL_Event event; // stockera les evenements

   bool ctrl = false, q = false, space = false; // 3 variables qui prennent la valeur true si les touches (respectivement) <control>, <q> ou <espace> sont appuillées

   int itt = 0; // nombre d'ittérations de la boucle principale. les premières itérations, le perso avence sur la fenetre, après, c'est la fenetre qui bouge.

   int paused = 0; // prendra la valeur de pause ()

   if (gal_mus -> Bmusique [var -> lvl - 1])
   {
      printf ("musique !\n");

      Mix_PlayMusic (gal_mus -> Musique [var -> lvl - 1], 1);
      redirect_intro_musique (var, gal_mus, gal);
   }

   while (1) {

      SDL_Delay (15);

      itt++; // une ittération de la boucle en plus

      decaler_sprites (var, gal, itt); // on fait bouger tous les sprites pour donner une impression de mouvement

      action_event (var, space); // on agit selon l'évenement

      if (test_game_over (var, gal, gal_mus)) {
         if (gal_mus -> Bmusique [var -> lvl - 1])
            Mix_PlayMusic (gal_mus -> Musique [var -> lvl - 1], 1);

         itt = 0;
      }

      if (test_win (var, gal))
         return 1; //on retourne 1 : le perso à gagné

      while (SDL_PollEvent (&event)) { // il y a eu un evenement depuis la derniere fois

         if (event.type == SDL_WINDOWEVENT) { // une touche est pessée
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) // Fermeture de la fenêtre
               exit_geoplatform (var, gal); // on quitte
         }
         else if (event.type == SDL_KEYDOWN) { // une touche est pessée

            if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche appuillée est <ctrl gauche> ou <ctrl droite>
               ctrl = true;
            else if (event.key.keysym.sym == SDLK_q) // la touche appuillée est <q>
               q = true;
            else if (event.key.keysym.sym == SAUTER) // on demande de sauter (définit dan params.h)
               space = true;

            if (event.key.keysym.sym == PAUSE) { // on demande de mettre en pause (définit dan params.h)

               paused = pause (); // on met le jeu en pause

               if (paused == 1) // pause vaut 1
                  exit_geoplatform (var, gal); // on quitte
               else if (paused == 3) // pause vaut 3
                  space = false; // comme <espace> a été relaché pendant la pause, space vaut maintenant false

               paused = 0; // on remet paused à 0
            }

            if (event.key.keysym.sym == REGLAGES) { // on demande d'accéder aux réglages (définit dan params.h)
               Mix_PauseMusic ();
               if (params (var, gal) == 1) {
                  return true;
               }
               Mix_ResumeMusic();
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

      if (ctrl && q) { // les touches <controle> et <q> sont appuillées
         exit_geoplatform (var, gal); // on quitte
         q = false;
         ctrl = false;
      }

      refresh (var, gal);
   }
}



   /* met la fenetre à jour */
void refresh (Var *var, Gal *gal) {

   int i = 0;

   SDL_SetRenderTarget (var -> renderer, var -> render); // on dessine maintenant sur var -> arriere_plan et non sur la fenetre

   SDL_SetRenderDrawColor (var -> renderer, 0, 0, 0, 0); // on nétoit en noir (par principe)
   SDL_RenderClear (var -> renderer); // on nettoie la fenetre
      /* C'est là que l'on copie tous les sprites */
   SDL_RenderCopy (var -> renderer, gal -> arriere_plan [var -> lvl - 1], NULL, NULL); // on copie l'arriere_plan sur l'arriere plan (oui).
   SDL_SetRenderDrawColor (var -> renderer, var -> p_lvl [var -> lvl - 1].couleur_sol.r, var -> p_lvl [var -> lvl - 1].couleur_sol.g, var -> p_lvl [var -> lvl - 1].couleur_sol.b, 0); // on définit la couleur avec laquelle on va dessiner le sol (rgba)
   SDL_RenderFillRect (var -> renderer, &var -> p_lvl [var -> lvl - 1].Sol); // on dessine le sol sur l'arriere plan

   for (i = 0 ; i < NB_SOLSEC ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de sols secondaires
      SDL_RenderFillRect (var -> renderer, &var -> p_lvl [var -> lvl - 1].sol_sec [i]); // on dessine les sols secondaires sur l'arriere plan
   }

   for (i = 0 ; i < NB_DEADZONES ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de sols secondaires
      SDL_SetRenderDrawColor (var -> renderer, 0, 0, 0, 0);

      SDL_RenderFillRect (var -> renderer, &var -> p_lvl [var -> lvl - 1].dead_zones [i].dead); // on dessine les sols secondaires sur l'arriere plan
   }

   for (i = 0 ; i < NB_PICS ; i += 1) // on parcourt la boucle autant de fois qu'il y a de pics
      SDL_RenderCopy (var -> renderer, var -> p_lvl [var -> lvl - 1].pics [i].text_pic, NULL, &var -> p_lvl [var -> lvl - 1].pics [i].Rect); // on copie le perso sur l'arriere plan

   if (!var -> perso.perso_is_u)
      SDL_RenderCopy (var -> renderer, var -> perso.perso, NULL, &var -> perso.Rperso); // on copie le perso sur l'arriere plan
   else
      SDL_RenderCopy (var -> renderer, var -> perso.perso, &var -> perso.R_du_perso, &var -> perso.Rperso); // on copie le perso sur l'arriere plan

   for (i = 0 ; i < NB_CANNONS ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de cannons
      SDL_SetRenderDrawColor (var -> renderer, 200, 200, 200, 100);
      SDL_RenderFillRect (var -> renderer, &var -> p_lvl [var -> lvl - 1].cannons [i].surf); // on dessine le rectangle surf sur l'arrière plan

      SDL_RenderCopy (var -> renderer, var -> p_lvl [var -> lvl - 1].cannons [i].Tcannon, NULL, &var -> p_lvl [var -> lvl - 1].cannons [i].Rcannon);
   }

   SDL_RenderCopy (var -> renderer, var -> arrivee.texture, NULL, &var -> arrivee.rect); // on copie l'arrivée sur l'arriere plan

   if (var -> aff) // si on doit afficher la texture params
      SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur l'arriere plan

   SDL_SetRenderTarget (var -> renderer, NULL); // on redessine maintenant sur la fenetre

   SDL_RenderClear (var -> renderer); // on nettoie la fenetre
   SDL_RenderCopy (var -> renderer, var -> render, NULL, NULL); // on copie l'arriere_plan (sur lequel on a maintenant ajouté les sprites) sur la fenetre
   SDL_RenderPresent (var -> renderer); // on met la fenetre à jour
}



   /* décale tous les sprites vers la gauche */
void decaler_sprites (Var *var, Gal *gal, int itt) {

   int i = 0, j = 0; // pour parcourir les boucles for

   if (itt * var -> depl < LONG_WIND / 2 - var -> perso.Rperso.w / 2) { // tant que le perso n'est pas à la moitié de la fenetre
      var -> perso.Rperso.x += var -> depl; // on fait avencer le perso, toujours à la même vitesse
   }
   else { // sinon (tout le niveau en fait)

      var -> arrivee.rect.x -= var -> depl; // on décale l'arrivée vers la gauche

      for (i = 0 ; i < NB_PICS ; i += 1) {
         var -> p_lvl [var -> lvl - 1].pics [i].Rect.x -= var -> depl; // on décale le pic #i vers la gauche
         var -> p_lvl [var -> lvl - 1].pics [i].rects_h.x -= var -> depl; // on décale le minirect horizontal du pic #i vers la gauche
         var -> p_lvl [var -> lvl - 1].pics [i].rects_v.x -= var -> depl; // on décale le minirect vertical du pic #i vers la gauche
      }
      for (i = 0 ; i < NB_SOLSEC ; i += 1) {
         var -> p_lvl [var -> lvl - 1].sol_sec [i].x -= var -> depl; // on décale le sol secondaire #i vers la gauche
      }
      for (i = 0 ; i < NB_DEADZONES ; i += 1) {
         var -> p_lvl [var -> lvl - 1].dead_zones [i].dead.x -= var -> depl; // on décale le sol secondaire #i vers la gauche
      }
      for (i = 0 ; i < NB_CANNONS ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de cannons
         var -> p_lvl [var -> lvl - 1].cannons [i].surf.x -= var -> depl; // on décale le sol secondaire #i vers la gauche
         var -> p_lvl [var -> lvl - 1].cannons [i].Rcannon.x -= var -> depl; // on décale le sol secondaire #i vers la gauche
      }
   }

   anim_perso_u (var);
}


   /* vérifie si le perso doit tomber ou pas et agit en conséquence */
int fait_tomber_perso (Var *var) {

   if (var -> perso.saute == 0) {
      if (test_perso_tombe (var)) // si le perso peut tomber,
         if (var -> perso.Rperso.y + 40 <= HAUT_WIND - 50)
            var -> perso.Rperso.y += 2; // le perso tombe.
         else
            monte_sprites (var);

      return 1; // si on arrive jusque là, le perso ne tombera pas
   }
   else {
      if (var -> perso.Rperso.y + 40 > HAUT_WIND - 50)
         monte_sprites (var);
      return 0;
   }
   return 0; // si on arrive jusque là, le perso ne tombera pas
}



   /* décale tous les sprites vers le haut */
void monte_sprites (Var *var) {

   int i = 0, j = 0; // pour parcourir les boucles for

   var -> arrivee.rect.y -= 2; // on décale l'arrivée vers la gauche

   for (i = 0 ; i < NB_PICS ; i += 1) {
      var -> p_lvl [var -> lvl - 1].pics [i].Rect.y -= 2; // on décale le pic #i vers la gauche
      var -> p_lvl [var -> lvl - 1].pics [i].rects_h.y -= 2; // on décale le minirect horizontal du pic #i vers la gauche
      var -> p_lvl [var -> lvl - 1].pics [i].rects_v.y -= 2; // on décale le minirect vertical du pic #i vers la gauche
   }
   for (i = 0 ; i < NB_SOLSEC ; i += 1) {
      var -> p_lvl [var -> lvl - 1].sol_sec [i].y -= 2; // on décale le sol secondaire #i vers la gauche
   }
   for (i = 0 ; i < NB_DEADZONES ; i += 1) {
      var -> p_lvl [var -> lvl - 1].dead_zones [i].dead.y -= 2; // on décale le sol secondaire #i vers la gauche
   }
   for (i = 0 ; i < NB_CANNONS ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de cannons
      var -> p_lvl [var -> lvl - 1].cannons [i].surf.y -= 2; // on décale le sol secondaire #i vers la gauche
      var -> p_lvl [var -> lvl - 1].cannons [i].Rcannon.y -= 2; // on décale le sol secondaire #i vers la gauche
   }

   var -> p_lvl [var -> lvl - 1].Sol.y -= 2; // on décale le sol secondaire #i vers la gauche

   anim_perso_u (var);
}



   /* décale tous les sprites vers le haut */
void descend_sprites (Var *var) {

   int i = 0, j = 0; // pour parcourir les boucles for

   var -> arrivee.rect.y += 2; // on décale l'arrivée vers la gauche

   for (i = 0 ; i < NB_PICS ; i += 1) {
      var -> p_lvl [var -> lvl - 1].pics [i].Rect.y += 2; // on décale le pic #i vers la gauche
      var -> p_lvl [var -> lvl - 1].pics [i].rects_h.y += 2; // on décale le minirect horizontal du pic #i vers la gauche
      var -> p_lvl [var -> lvl - 1].pics [i].rects_v.y += 2; // on décale le minirect vertical du pic #i vers la gauche
   }
   for (i = 0 ; i < NB_SOLSEC ; i += 1) {
      var -> p_lvl [var -> lvl - 1].sol_sec [i].y += 2; // on décale le sol secondaire #i vers la gauche
   }
   for (i = 0 ; i < NB_DEADZONES ; i += 1) {
      var -> p_lvl [var -> lvl - 1].dead_zones [i].dead.y += 2; // on décale le sol secondaire #i vers la gauche
   }
   for (i = 0 ; i < NB_CANNONS ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de cannons
      var -> p_lvl [var -> lvl - 1].cannons [i].surf.y += 2; // on décale le sol secondaire #i vers la gauche
      var -> p_lvl [var -> lvl - 1].cannons [i].Rcannon.y += 2; // on décale le sol secondaire #i vers la gauche
   }

   var -> p_lvl [var -> lvl - 1].Sol.y += 2; // on décale le sol secondaire #i vers la gauche

   anim_perso_u (var);
}



   /* teste si le perso peut tomber ou pas */
bool test_perso_tombe (Var *var) {

   int i = 0;

   for (i = 0 ; i < NB_SOLSEC ; i += 1) // on teste pour tous les sols secondaires
      if (SDL_HasIntersection (&var -> perso.Rperso, &var -> p_lvl [var -> lvl - 1].sol_sec [i])) // le perso percute le sol secondaire testé
         return false; // on ne descend pas

   if (var -> perso.Rperso.y + var -> perso.Rperso.h + 1 < var -> p_lvl [var -> lvl - 1].Sol.y) { // il ne touche pas le sol
      return true;
   }

   return false; // si on arrive jusque là, le perso ne tombera pas
}


   /* définie si le perso touche un des pic */
bool coll_perso_pic (Var *var) {

   int i = 0; // pour parcourir la boucle for

   for (i = 0 ; i < NB_PICS ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de pic
      if (SDL_HasIntersection (&var -> perso.Rperso, &var -> p_lvl [var -> lvl - 1].pics [i].rects_h)    ||
          SDL_HasIntersection (&var -> perso.Rperso, &var -> p_lvl [var -> lvl - 1].pics [i].rects_v)) { // on regarde si le perso est en contacte avec un des rectangles d'un des pics

         return true; // si oui, on retourne true
      }
   }

   return false; // le perso ne touche pas les pics
}


   /* définie si le perso touche une des zones de mort */
bool coll_perso_deadzones (Var *var) {

   int i = 0; // pour parcourir la boucle for

   for (i = 0 ; i < NB_DEADZONES ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de zones de mort
      if (SDL_HasIntersection (&var -> perso.Rperso, &var -> p_lvl [var -> lvl - 1].dead_zones [i].dead)) { // on regarde si le perso est en contacte avec une des zones de mort

         return true; // si oui, on retourne true
      }
   }

   return false; // le perso ne touche aucune zone de mort
}



   /* vérifie si le perso doit commencer à voler */
bool doit_voler (Var *var) {

   int i = 0; // pour la boucle for

   for (i = 0 ; i < NB_CANNONS ; i += 2) { // autant de fois qu'il y a de cannons. Que les paires, ceux sont eux qui démarquent le début de la zone de vol
      if (SDL_HasIntersection (&var -> perso.Rperso, &var -> p_lvl [var -> lvl - 1].cannons [i].surf)) { // si le perso entre dans une zone de vol
         var -> perso.Rperso.y = HAUT_WIND / 2 - var -> perso.Rperso.h / 2; // on centre le perso en y
         var -> vol = true; // maintenant il vole
         var -> perso.saute = false; // si il volen il ne saute pas
         return true; // on retourne oui
      }
   }

   return false; // si on est ici, le perso ne vole pas
}



   /* vérifie si le perso doit s'aretter de voler */
bool non_doit_voler (Var *var) {

   int i = 0; // pour la boucle for

   for (i = 1 ; i < NB_CANNONS ; i += 2) { // autant de fois qu'il y a de cannons; que les impères, ce csont eux qui démarquent la fin de la zone de vol
      if (SDL_HasIntersection (&var -> perso.Rperso, &var -> p_lvl [var -> lvl - 1].cannons [i].surf)) { // si le perso entre dans une zone de vol
         var -> vol = false; // maintenant il ne vole plus
         return true; // on retourne oui
      }
   }

   return false; // si on est ici, le perso ne vole pas
}



   /* animme le perso ultime */
void anim_perso_u (Var *var) {
   if (var -> perso.perso_is_u) { // si le perso est le perso ultime

      if (var -> perso.dir == 1) // si le rect doit descendre
         if (var -> perso.R_du_perso.y + 1 <= 575) // si le rect peut descendre
            var -> perso.R_du_perso.y += 1; // on le descend
         else // si on est arrivé en bas de l'image
            var -> perso.dir = 2; // le rect doit maintenant aller à droite

      else if (var -> perso.dir == 2) // si le rect doit aller à droite
         if (var -> perso.R_du_perso.x + 1 <= 237) // si le rect peut aller à droite
            var -> perso.R_du_perso.x += 1; // on l'emmenne sur la droite
         else // si on est arrivé à droite de l'image
            var -> perso.dir = 0; // le rect doit maintenant monter

      else if (var -> perso.dir == 0) // le rect doit  monter
         if (var -> perso.R_du_perso.y - 1 >= 0) // si il peut monter
            var -> perso.R_du_perso.y -= 1; // on le monte
         else // si on est arrivé en haut de l'image
            var -> perso.dir = 3; // le rect doit maintenant aller à gauche

      else if (var -> perso.dir == 3) // si le rect doit aller à gauche
         if (var -> perso.R_du_perso.x - 1 >= 0) // si le rect peut aller à gauche
            var -> perso.R_du_perso.x -= 1; // on l'emmenne à gauche
         else // si on est arrivé à gauche de l'image
            var -> perso.dir = 1; // le rect doit descendre
   }
}





