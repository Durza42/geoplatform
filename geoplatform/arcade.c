/*
 * arcade.c
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
 *    ici, on trouve le fonctionnement du jeu en arcade.
 */






   /* traite les evenement. retourne false si il faut quitter, true si le joueur veut continuer. */
int boucle_arcade (Var *var, Gal *gal) {

   Fragm fragms [NB_FRAGMS_JEU];
   fragms -> score_plus = 0;
   Datas datas =  {
                     0,
                     "temps : \0",
                     NULL,
                     {150, 75, 200, 50},
                     0,
                     "score : \0",
                     NULL,
                     {400, 75, 200, 50},
                  };

   int der_enregistrement_temps = SDL_GetTicks ();
   int fragm_act = rand () % NB_FRAGMS_JEU, fragm_suiv = 0;
   int der_changement_fragm = 0;
   unsigned int X_abs = 0;
   bool att_un_peu = false;
   int deb_fragm = 0;
   int delai = 500;

   basic_initialiser (var);
   var -> perso.Rperso.y = var -> p_lvl [0].Sol.y - var -> perso.Rperso.h; // on place le perso à la bonne ordonnée
   var -> perso.Rperso.x = 0; // on place le perso à la bonne abscice

   enleve_sprites (&fragms [fragm_act]);

   fragms [fragm_act].fin_x = LONG_WIND + 300;

   fragms [fragm_act].them.r = 125;
   fragms [fragm_act].them.g = 125;
   fragms [fragm_act].them.b = 125;

   fragms -> fin_x = LONG_WIND;

   SDL_Event event; // stockera les evenements

   bool ctrl = false, q = false, space = false; // 3 variables qui prennent la valeur true si les touches (respectivement) <control>, <q> ou <espace> sont appuillées

   int itt = 0; // nombre d'ittérations de la boucle principale. les premières itérations, le perso avence sur la fenetre, après, c'est la fenetre qui bouge.

   int paused = 0; // prendra la valeur de pause ()

   while (1) {

      SDL_Delay (15);

      itt += 1; // une ittération de la boucle en plus

      if (der_enregistrement_temps + 1000 < SDL_GetTicks ()) {
         datas.temps += 1;
         der_enregistrement_temps += 1000;
      }

      decaler_sprites_arcade (var, gal, itt, &fragms [fragm_act]); // on fait bouger tous les sprites pour donner une impression de mouvement
      X_abs += var -> depl;

      action_event_arcade (var, space, &fragms [fragm_act]); // on agit selon l'évenement

      if (test_game_over_arcade (&fragms [fragm_act], var, gal, &datas)) {
         der_enregistrement_temps = SDL_GetTicks ();
         fragm_act = rand () % NB_FRAGMS_JEU, fragm_suiv = 0;
         der_changement_fragm = 0;
         X_abs = 0;
         att_un_peu = false;
         deb_fragm = 0;
         delai = 500;

         datas = (Datas) {
                     0,
                     "temps : \0",
                     NULL,
                     {150, 75, 200, 50},
                     0,
                     "score : \0",
                     NULL,
                     {400, 75, 200, 50},
                  };
      }

      mettre_datas_a_jour (&datas, var -> renderer, var -> police, (SDL_Color) {200, 200, 200});

      if (itt * var -> depl > LONG_WIND / 2 - var -> perso.Rperso.w / 2) { // tant que le perso n'est pas à la moitié de la fenetre

         if (datas.temps < 20)
            delai = 500;
         else if (datas.temps > 20 && datas.temps < 60)
            delai = 350;
         else if (datas.temps > 60 && datas.temps < 180)
            delai = 250;
         else if (datas.temps > 180 && datas.temps < 300)
            delai = 200;
         else if (datas.temps > 300 && datas.temps < 600)
            delai = 150;
         else if (datas.temps > 600 && datas.temps < 1200)
            delai = 100;
         else if (datas.temps > 1200 && datas.temps < 1800)
            delai = 75;
         else if (datas.temps > 1800 && datas.temps < 2400)
            delai = 50;
         else if (datas.temps > 2400 && datas.temps < 3000)
            delai = 25;
         else if (datas.temps > 3000 && datas.temps < 3600)
            delai = 0;

         if (X_abs - LONG_WIND / 2 - 50 - delai > fragms [fragm_act].fin_x + der_changement_fragm) {
            printf ("%d \n", fragms [fragm_act].score_plus);
            basic_initialiser (var);
            enleve_sprites (&fragms [fragm_act]);
            gen_new_fragm (&fragms [fragm_act], fragm_act, datas.temps);
            der_changement_fragm = X_abs;
         }
      }

      while (SDL_PollEvent (&event)) { // il y a eu un evenement depuis la derniere fois

         if (event.type == SDL_WINDOWEVENT) { // une touche est pressée
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
            else if (event.key.keysym.sym == SDLK_ESCAPE) // on demande de sauter (définit dan params.h)
               return 0;

            if (event.key.keysym.sym == PAUSE) { // on demande de mettre en pause (définit dan params.h)

               paused = pause (); // on met le jeu en pause

               if (paused == 1) // pause vaut 1
                  exit_geoplatform (var, gal); // on quitte
               else if (paused == 3) // pause vaut 3
                  space = false; // comme <espace> a été relaché pendant la pause, space vaut maintenant false

               paused = 0; // on remet paused à 0
            }

            if (event.key.keysym.sym == REGLAGES) { // on demande d'accéder aux réglages (définit dan params.h)
               if (params (var, gal) == 1) {
                  return true;
               }
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

      refresh_arcade_mode (var, gal, &fragms [fragm_act], &datas);
   }
}




   /* met la fenetre à jour */
void refresh_arcade_mode (Var *var, Gal *gal, Fragm *fragm, Datas *datas) {

   int i = 0;

   SDL_SetRenderTarget (var -> renderer, var -> render); // on dessine maintenant sur var -> arriere_plan et non sur la fenetre

   SDL_SetRenderDrawColor (var -> renderer, 0, 0, 0, 0); // on nétoit en noir (par principe)
   SDL_RenderClear (var -> renderer); // on nettoie la fenetre
      /* C'est là que l'on copie tous les sprites */

   SDL_SetRenderDrawColor (var -> renderer, 125, 125, 125, 0); // on définit la couleur avec laquelle on va dessiner le sol

   SDL_RenderFillRect (var -> renderer, &var -> p_lvl [0].Sol); // on dessine le sol sur l'arriere plan


   for (i = 0 ; i < NB_SOLSEC_LOCAL ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de sols secondaires
      SDL_RenderFillRect (var -> renderer, &fragm -> sol_sec [i]); // on dessine les sols secondaires sur l'arriere plan
   }

   for (i = 0 ; i < NB_DEADZONES_LOCAL ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de sols secondaires
      SDL_SetRenderDrawColor (var -> renderer, 255, 0, 0, 0);

      SDL_RenderFillRect (var -> renderer, &fragm -> dead_zones [i].dead); // on dessine les sols secondaires sur l'arriere plan
   }

   for (i = 0 ; i < NB_PICS_LOCAL ; i += 1) // on parcourt la boucle autant de fois qu'il y a de pics
      SDL_RenderCopy (var -> renderer, gal -> pic, NULL, &fragm -> pics [i].Rect); // on copie le perso sur l'arriere plan

   if (!var -> perso.perso_is_u)
      SDL_RenderCopy (var -> renderer, var -> perso.perso, NULL, &var -> perso.Rperso); // on copie le perso sur l'arriere plan
   else
      SDL_RenderCopy (var -> renderer, var -> perso.perso, &var -> perso.R_du_perso, &var -> perso.Rperso); // on copie le perso sur l'arriere plan

   for (i = 0 ; i < NB_CANNONS_LOCAL ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de cannons
      SDL_SetRenderDrawColor (var -> renderer, 200, 200, 200, 100);
      SDL_RenderFillRect (var -> renderer, &fragm -> cannons [i].surf); // on dessine le rectangle surf sur l'arrière plan
      SDL_RenderCopy (var -> renderer, gal -> cannon, NULL, &fragm -> cannons [i].Rcannon);
   }

   if (var -> aff) // si on doit afficher la texture params
      SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur l'arriere plan

   SDL_RenderCopy (var -> renderer, datas -> text_temps, NULL, &datas -> Rtemps); // on copie les scores et le temps sur l'arriere plan
   SDL_RenderCopy (var -> renderer, datas -> text_score, NULL, &datas -> Rscore); // on copie les scores et le temps sur l'arriere plan

   SDL_SetRenderTarget (var -> renderer, NULL); // on redessine maintenant sur la fenetre

   SDL_RenderClear (var -> renderer); // on nettoie la fenetre
   SDL_RenderCopy (var -> renderer, var -> render, NULL, NULL); // on copie l'arriere_plan (sur lequel on a maintenant ajouté les sprites) sur la fenetre
   SDL_RenderPresent (var -> renderer); // on met la fenetre à jour
}




   /* décale tous les sprites vers la gauche */
void decaler_sprites_arcade (Var *var, Gal *gal, int itt, Fragm *fragms) {

   int i = 0, j = 0; // pour parcourir les boucles for

   if (itt * var -> depl < LONG_WIND / 2 - var -> perso.Rperso.w / 2) { // tant que le perso n'est pas à la moitié de la fenetre
      var -> perso.Rperso.x += var -> depl; // on fait avencer le perso, toujours à la même vitesse
   }
   else { // sinon (tout le niveau en fait)

      for (i = 0 ; i < NB_PICS_LOCAL ; i += 1) {
         fragms -> pics [i].Rect.x -= var -> depl; // on décale le pic #i vers la gauche
         fragms -> pics [i].rects_h.x -= var -> depl; // on décale le minirect horizontal du pic #i vers la gauche
         fragms -> pics [i].rects_v.x -= var -> depl; // on décale le minirect vertical du pic #i vers la gauche
      }
      for (i = 0 ; i < NB_SOLSEC_LOCAL ; i += 1) {
         fragms -> sol_sec [i].x -= var -> depl; // on décale le sol secondaire #i vers la gauche
      }
      for (i = 0 ; i < NB_DEADZONES_LOCAL ; i += 1) {
         fragms -> dead_zones [i].dead.x -= var -> depl; // on décale le sol secondaire #i vers la gauche
      }
      for (i = 0 ; i < NB_CANNONS_LOCAL ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de cannons
         fragms -> cannons [i].surf.x -= var -> depl; // on décale le sol secondaire #i vers la gauche
         fragms -> cannons [i].Rcannon.x -= var -> depl; // on décale le sol secondaire #i vers la gauche
      }
   }

   anim_perso_u (var);
}



   /* regarde si le joueur a perdu, et agit en concéquance */
bool test_game_over_arcade (Fragm *fragms, Var *var, Gal *gal, Datas *datas) {

   if (coll_perso_pic_arcade (var, fragms)   ||
       coll_perso_deadzones_arcade (var, fragms)) { // si le joueur est en collision avec un pic ou avec une zone de mort

      print_message_arcade (var, gal, "game over", fragms, datas);

      return true; // on retourne true, car le joueur a perdu
   }
   return false; // on retourne false, le joueur n'a pas perdu
}



   /* définie si le perso touche un des pic */
bool coll_perso_pic_arcade (Var *var, Fragm *fragms) {

   int i = 0; // pour parcourir la boucle for

   for (i = 0 ; i < NB_PICS_LOCAL ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de pic
      if (SDL_HasIntersection (&var -> perso.Rperso, &fragms -> pics [i].rects_h)    ||
          SDL_HasIntersection (&var -> perso.Rperso, &fragms -> pics [i].rects_v)) { // on regarde si le perso est en contacte avec un des rectangles d'un des pics

         return true; // si oui, on retourne true
      }
   }

   return false; // le perso ne touche pas les pics
}


   /* définie si le perso touche une des zones de mort */
bool coll_perso_deadzones_arcade (Var *var, Fragm *fragms) {

   int i = 0; // pour parcourir la boucle for

   for (i = 0 ; i < NB_DEADZONES_LOCAL ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de zones de mort
      if (SDL_HasIntersection (&var -> perso.Rperso, &fragms -> dead_zones [i].dead)) { // on regarde si le perso est en contacte avec une des zones de mort

         return true; // si oui, on retourne true
      }
   }

   return false; // le perso ne touche aucune zone de mort
}



   /* on affiche un message à l'écran */
void print_message_arcade (Var *var, Gal *gal, char *mess, Fragm *fragm, Datas *datas) {

   SDL_Texture *text; // texture qui sera affichée à l'écran, sur laquelle on va écrir la chaine mess
   SDL_Rect Rgo = {150, 200, 300, 50}; // portion de l'écran sur lequel sera affiché la texture

   ttf_print_B (mess, &text, var -> renderer, var -> police, fragm -> them); // on écrit la chaine sur la texture

   /* en réalité presque  le copier-coller du code de refresh_arcade */

   int i = 0;

   SDL_SetRenderTarget (var -> renderer, var -> render); // on dessine maintenant sur var -> arriere_plan et non sur la fenetre

   SDL_SetRenderDrawColor (var -> renderer, 0, 0, 0, 0); // on nétoit en noir (par principe)
   SDL_RenderClear (var -> renderer); // on nettoie la fenetre
      /* C'est là que l'on copie tous les sprites */
   SDL_SetRenderDrawColor (var -> renderer, fragm -> them.r, fragm -> them.g, fragm -> them.b, 0); // on définit la couleur avec laquelle on va dessiner le sol (rgba)
   SDL_RenderFillRect (var -> renderer, &var -> p_lvl [0].Sol); // on dessine le sol sur l'arriere plan

   for (i = 0 ; i < NB_SOLSEC_LOCAL ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de sols secondaires
      SDL_RenderFillRect (var -> renderer, &fragm -> sol_sec [i]); // on dessine les sols secondaires sur l'arriere plan
   }

   for (i = 0 ; i < NB_DEADZONES_LOCAL ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de sols secondaires
      SDL_SetRenderDrawColor (var -> renderer, 0, 0, 0, 0);

      SDL_RenderFillRect (var -> renderer, &fragm -> dead_zones [i].dead); // on dessine les sols secondaires sur l'arriere plan
   }

   for (i = 0 ; i < NB_PICS_LOCAL ; i += 1) // on parcourt la boucle autant de fois qu'il y a de pics
      SDL_RenderCopy (var -> renderer, gal -> pic, NULL, &fragm -> pics [i].Rect); // on copie le perso sur l'arriere plan

   if (!var -> perso.perso_is_u)
      SDL_RenderCopy (var -> renderer, var -> perso.perso, NULL, &var -> perso.Rperso); // on copie le perso sur l'arriere plan
   else
      SDL_RenderCopy (var -> renderer, var -> perso.perso, &var -> perso.R_du_perso, &var -> perso.Rperso); // on copie le perso sur l'arriere plan

   for (i = 0 ; i < NB_CANNONS_LOCAL ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de cannons
      SDL_SetRenderDrawColor (var -> renderer, 200, 200, 200, 100);
      SDL_RenderFillRect (var -> renderer, &fragm -> cannons [i].surf); // on dessine le rectangle surf sur l'arrière plan
      SDL_RenderCopy (var -> renderer, gal -> cannon, NULL, &fragm -> cannons [i].Rcannon);
   }

   SDL_RenderCopy (var -> renderer, var -> arrivee.texture, NULL, &var -> arrivee.rect); // on copie l'arrivée sur l'arriere plan

   if (var -> aff) // si on doit afficher la texture params
      SDL_RenderCopy (var -> renderer, var -> params, NULL, &var -> Rparams); // on copie la texture params sur l'arriere plan

   SDL_RenderCopy (var -> renderer, text, NULL, &Rgo); // on copie l'arriere_plan (sur lequel on a maintenant ajouté les sprites) sur la fenetre

   SDL_RenderCopy (var -> renderer, datas -> text_temps, NULL, &datas -> Rtemps); // on copie les scores et le temps sur l'arriere plan
   SDL_RenderCopy (var -> renderer, datas -> text_score, NULL, &datas -> Rscore); // on copie les scores et le temps sur l'arriere plan

   SDL_SetRenderTarget (var -> renderer, NULL); // on redessine maintenant sur la fenetre

   SDL_RenderClear (var -> renderer); // on nettoie la fenetre
   SDL_RenderCopy (var -> renderer, var -> render, NULL, NULL); // on copie l'arriere_plan (sur lequel on a maintenant ajouté les sprites) sur la fenetre
   SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

   SDL_Delay (1000); // on attend 1 seconde que le joueur voit le message s'afficher

   SDL_DestroyTexture (text); // texture qui sera affichée à l'écran, sur laquelle on va écrir la chaine mess
}



   /* le perso saute */
int saut_arcade (Var *var, Fragm *fragms) {

   int i = 0; // pour parcourir les boucles for

   if (var -> perso.saute > SDL_GetTicks ()) { // si l'on n'a pas passé la moitié du saut
      var -> perso.Rperso.y -= var -> perso.saute / 50 - SDL_GetTicks () / 50; // le perso monte, et plus au début du saut qu'a la fin
      return 0; // le perso continue à sauter
   }

   for (i = 0 ; i < NB_SOLSEC_LOCAL ; i += 1) { // on teste pour tous les sols secondaires
      if (SDL_HasIntersection (&var -> perso.Rperso, &fragms -> sol_sec [i])) { // le perso percute le sol secondaire testé
         var -> perso.Rperso.y = fragms -> sol_sec [i].y - var -> perso.Rperso.h; // on le remet à la bonne ordonnée
         var -> perso.saute = 0; // le perso ne saute plus
         return 1; // le perso doit arrêter de sauter
      }
   }

   if (var -> perso.Rperso.y + var -> perso.Rperso.h + SDL_GetTicks () / 50 - var -> perso.saute / 50 < var -> p_lvl [var -> lvl - 1].Sol.y) { // le perso descend, c'est la deuxieme moitié du saut. on teste si il touche le sol
      var -> perso.Rperso.y += SDL_GetTicks () / 50 - var -> perso.saute / 50; // il ne le touche pas, il descend
   }
   else { // le perso est redescendu sur terre
      var -> perso.Rperso.y = var -> p_lvl [0].Sol.y - var -> perso.Rperso.h; // on le remet à la bonne ordonnée
      var -> perso.saute = 0; // le perso ne saute plus
      return 1; // le perso doit s'arretter de sauter
   }
   return 0; // le perso continue à sauter
}



   /* appele les fonctions correspondantes aux actions demandées */
void action_event_arcade (Var *var, int space, Fragm *fragms) {

   doit_voler (var); // on vérifie si le perso doit voler ou non
   non_doit_voler (var); // on vérifie si le perso ne doit  pas arêter de voler

   if (space == true || var -> perso.saute != 0) { // espace est appuillé ou le perso est déjà en train de qauter mais n'a pas fini son saut

      if (var -> vol) { // si le perso vole
         var -> perso.Rperso.y -= 8; // on fait monter le perso
      }
      else { // c'est normal
         if (var -> perso.saute == 0) // si le perso ne saute pas encore
            if (!test_perso_tombe_arcade (var, fragms)) // si le perso n'est pas en l'air
               var -> perso.saute = SDL_GetTicks () + 250; // le saut dureraa 250 * 2 = 500 ms

         if (var -> perso.saute != 0)
            if (saut_arcade (var, fragms) == 0) // si le perso est bien toujours en train de sauter (il n'a pas rencontré le sol)
               saut_arcade (var, fragms); // on resaute, pour le faire sauter assez haut
      }
   }

   fait_tomber_perso_arcade (var, fragms); // on teste si le perso doit tomber et on agit en conséquence (y compris en mode vol)
   if (var -> vol) // si le perso vole
      fait_tomber_perso_arcade (var, fragms); // on refait tomber le perso
}




   /* vérifie si le perso doit tomber ou pas et agit en conséquence */
int fait_tomber_perso_arcade (Var *var, Fragm *fragms) {

   int i = 0; // pour parcourir les boucles for

   if (var -> perso.saute == 0) { // si le perso ne saute pas (car lors, il se remettra de lui même)
      if (test_perso_tombe_arcade (var, fragms)) // si le perso peut tomber,
         var -> perso.Rperso.y += 2; // le perso tombe.
   }
   return 0; // si on arrive jusque là, le perso ne tombera pas
}


   /* teste si le perso peut tomber ou pas */
bool test_perso_tombe_arcade (Var *var, Fragm *fragms) {

   int i = 0;

   for (i = 0 ; i < NB_SOLSEC_LOCAL ; i += 1) // on teste pour tous les sols secondaires
      if (SDL_HasIntersection (&var -> perso.Rperso, &fragms -> sol_sec [i])) // le perso percute le sol secondaire testé
         return false; // on ne descend pas

   if (var -> perso.Rperso.y + var -> perso.Rperso.h + 1 < var -> p_lvl [0].Sol.y) { // il ne touche pas le sol
      return true;
   }

   return false; // si on arrive jusque là, le perso ne tombera pas
}




   /* vérifie si le perso doit commencer à voler */
bool doit_voler_arcade (Var *var, Fragm *fragms) {

   int i = 0; // pour la boucle for

for (i = 0 ; i < NB_CANNONS_LOCAL ; i += 2) { // autant de fois qu'il y a de cannons. Que les paires, ceux sont eux qui démarquent le début de la zone de vol
      if (SDL_HasIntersection (&var -> perso.Rperso, &fragms -> cannons [i].surf)) { // si le perso entre dans une zone de vol
         var -> perso.Rperso.y = HAUT_WIND / 2 - var -> perso.Rperso.h / 2; // on centre le perso en y
         var -> vol = true; // maintenant il vole
         var -> perso.saute = false; // si il vole il ne saute pas
         return true; // on retourne oui
      }
   }

   return false; // si on est ici, le perso ne vole pas
}



   /* vérifie si le perso doit s'aretter de voler */
bool non_doit_voler_arcade (Var *var, Fragm *fragms) {

   int i = 0; // pour la boucle for

   for (i = 1 ; i < NB_CANNONS_LOCAL ; i += 2) { // autant de fois qu'il y a de cannons; que les impères, ce csont eux qui démarquent la fin de la zone de vol
      if (SDL_HasIntersection (&var -> perso.Rperso, &fragms -> cannons [i].surf)) { // si le perso entre dans une zone de vol
         var -> vol = false; // maintenant il ne vole plus
         return true; // on retourne oui
      }
   }

   return false; // si on est ici, le perso ne vole pas
}



void mettre_datas_a_jour (Datas *datas, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   sprintf (datas -> C_temps, "temps : %d%c", datas -> temps, '\0');
   sprintf (datas -> C_scores, "score : %d%c", datas -> scores, '\0');

   SDL_DestroyTexture (datas -> text_temps);
   ttf_print_B (datas -> C_temps, &datas -> text_temps, R, pol, C);

   SDL_DestroyTexture (datas -> text_score);
   ttf_print_B (datas -> C_scores, &datas -> text_score, R, pol, C);
}









