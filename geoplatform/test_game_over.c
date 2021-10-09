
/*
 * test_game_over.c
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
 * Ici se trouvent les fonction qui testent les games-overs et les win, et celles qui les annoncent
*/





   /* regarde si le joueur a perdu, et agit en concéquance */
bool test_game_over (Var *var, Gal *gal, Gal_mus *gal_mus) {

   if (coll_perso_pic (var)   ||
       coll_perso_deadzones (var)) { // si le joueur est en collision avec un pic ou avec une zone de mort

      if (gal_mus != NULL) {
         if (gal_mus -> Bmusique [var -> lvl - 1]) {
            Mix_PauseMusic();
            Mix_RewindMusic();
         }
      }

      print_message (var, gal, "game over");

      init_lvls (var, gal); // on réinitialise le niveau
      return true; // on retourne true, car le joueur a perdu
   }
   return false; // on retourne false, le joueur n'a pas perdu
}



   /* regarde si le joueur a gagné, et agit en concéquance */
bool test_win (Var *var, Gal *gal) {

   if (SDL_HasIntersection (&var -> perso.Rperso, &var -> arrivee.rect)) { // si le joueur est en collision avec l'arrivé, il a gagné

      print_message (var, gal, "you win");

      if (var -> lvl == var -> lvl_max_atteint && var -> lvl_max_atteint + 1 <= NB_MONDES * 4) { // à condition que ce soit le dernier niveau atteint que l'on ai réussit, et que le suivant existe !

         if (var -> lvl_max_atteint % 4 == 0 && var -> lvl_max_atteint != 0)
            var -> monde_max_atteint += 1;

         var -> lvl_max_atteint += 1; // on a maintenant acces au niveau suppérieur
      }

      return true; // on retourne true, car le joueur a gagné
   }
   return false; // on retourne false, le joueur n'a pas gagné
}




   /* on affiche un message à l'écran */
void print_message (Var *var, Gal *gal, char *mess) {

   SDL_Texture *text; // texture qui sera affichée à l'écran, sur laquelle on va écrir la chaine mess
   SDL_Rect Rgo = {150, 50, 300, 50}; // portion de l'écran sur lequel sera affiché la texture

   ttf_print_B (mess, &text, var -> renderer, var -> police, var -> p_lvl [var -> lvl - 1].couleur_sol); // on écrit la chaine sur la texture

   /*en réalité presque  le copier-coller du code de refresh*/


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

   SDL_RenderCopy (var -> renderer, var -> perso.perso, NULL, &var -> perso.Rperso); // on copie le perso sur l'arriere plan

   for (i = 0 ; i < NB_CANNONS ; i += 1) { // on parcourt la boucle autant de fois qu'il y a de cannons
      SDL_SetRenderDrawColor (var -> renderer, 200, 200, 200, 100);
      SDL_RenderFillRect (var -> renderer, &var -> p_lvl [var -> lvl - 1].cannons [i].surf); // on dessine le rectangle surf sur l'arrière plan

      SDL_RenderCopy (var -> renderer, var -> p_lvl [var -> lvl - 1].cannons [i].Tcannon, NULL, &var -> p_lvl [var -> lvl - 1].cannons [i].Rcannon);
   }

   if (!var -> perso.perso_is_u)
      SDL_RenderCopy (var -> renderer, var -> perso.perso, NULL, &var -> perso.Rperso); // on copie le perso sur l'arriere plan
   else
      SDL_RenderCopy (var -> renderer, var -> perso.perso, &var -> perso.R_du_perso, &var -> perso.Rperso); // on copie le perso sur l'arriere plan

   SDL_RenderCopy (var -> renderer, var -> arrivee.texture, NULL, &var -> arrivee.rect); // on copie l'arrivée sur l'arriere plan

   SDL_SetRenderTarget (var -> renderer, NULL); // on redessine maintenant sur la fenetre

   SDL_RenderClear (var -> renderer); // on nettoie la fenetre
   SDL_RenderCopy (var -> renderer, var -> render, NULL, NULL); // on copie l'arriere_plan (sur lequel on a maintenant ajouté les sprites) sur la fenetre
   SDL_RenderCopy (var -> renderer, text, NULL, &Rgo); // on copie "game over" sur l'arriere plan
   SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

   SDL_Delay (1000); // on attend 1 seconde que le joueur voit le message s'afficher

   SDL_DestroyTexture (text); // texture qui sera affichée à l'écran, sur laquelle on va écrir la chaine mess
}


