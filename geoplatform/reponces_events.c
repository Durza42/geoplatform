
/*
 * reponces_events
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
 * Dans ce fichier on trouve toutes les fonction en relation directe avec un évennement
 */



   /* appele les fonctions correspondantes aux actions demandées */
void action_event (Var *var, int space) {

   doit_voler (var); // on vérifie si le perso doit voler ou non
   non_doit_voler (var); // on vérifie si le perso ne doit  pas arêter de voler

   if (space == true || var -> perso.saute != 0) { // espace est appuillé ou le perso est déjà en train de qauter mais n'a pas fini son saut

      if (var -> vol) { // si le perso vole
         var -> perso.Rperso.y -= 8; // on fait monter le perso
      }
      else { // c'est normal
         if (var -> perso.saute == 0) // si le perso ne saute pas encore
            if (!test_perso_tombe (var)) // si le perso n'est pas en l'air
               var -> perso.saute = SDL_GetTicks () + 250; // le saut dureraa 250 * 2 = 500 ms

         if (var -> perso.saute != 0)
            if (saut (var) == 0) // si le perso est bien toujours en train de sauter (il n'a pas rencontré le sol)
               saut (var); // on resaute, pour le faire sauter assez haut
      }
   }

   fait_tomber_perso (var); // on teste si le perso doit tomber et on agit en conséquence (y compris en mode vol)

   if (var -> vol) // si le perso vole
      fait_tomber_perso (var); // on refait tomber le perso

   if (var -> perso.Rperso.y < HAUT_WIND / 2 - 100) {
      descend_sprites (var);
   }
}



   /* met le programme en pause */
int pause () {

   SDL_Event event; // pour stocker les events

   bool ctrl = false, q = false; // 2 variables qui prennent la valeur true si les touches (respectivement) <control> ou <q> sont appuillées

   int space = 0; // prendra la valeur 3 si espace est relaché

   while (1) {

      SDL_WaitEvent (&event); // on attend un event

      if (event.type == SDL_WINDOWEVENT) { // une touche est pessée
         if (event.window.event == SDL_WINDOWEVENT_CLOSE) // Fermeture de la fenêtre
            return 0;//on quitte le programe
      }
      else if (event.type == SDL_KEYDOWN) { // une touche est pessée

         if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche appuillée est <ctrl gauche> ou <ctrl droite>
            ctrl = true;
         else if (event.key.keysym.sym == SDLK_q) // la touche appuillée est <q>
            q = true;
         else if (event.key.keysym.sym == SDLK_p) // la touche appuillée est <p>
            return space; // on ne quitte que la fonction

      }
      else if (event.type == SDL_KEYUP) { // une touche est relachée

         if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) // la touche relachée est <ctrl gauche> ou <ctrl droite>
            ctrl = false;
         else if (event.key.keysym.sym == SDLK_q) // la touche relachée est <q>
            q = false;
         else if (event.key.keysym.sym == SDLK_SPACE) // la touche relachée est <espace>
            space = 3;
      }

      if (ctrl && q) // les touches <controle> et <q> sont appuillées
         return 1; // on doit quitter
   }
}



   /* le perso saute */
int saut (Var *var) {

   int i = 0; // pour parcourir les boucles for

   if (var -> perso.saute > SDL_GetTicks ()) { // si l'on n'a pas passé la moitié du saut
      var -> perso.Rperso.y -= var -> perso.saute / 50 - SDL_GetTicks () / 50; // le perso monte, et plus au début du saut qu'a la fin
      return 0; // le perso continue à sauter
   }

   for (i = 0 ; i < NB_SOLSEC ; i += 1) { // on teste pour tous les sols secondaires
      if (SDL_HasIntersection (&var -> perso.Rperso, &var -> p_lvl [var -> lvl - 1].sol_sec [i])) { // le perso percute le sol secondaire testé
         var -> perso.Rperso.y = var -> p_lvl [var -> lvl - 1].sol_sec [i].y - var -> perso.Rperso.h; // on le remet à la bonne ordonnée
         var -> perso.saute = 0; // le perso ne saute plus
         return 1; // le perso doit arrêter de sauter
      }
   }

   if (var -> perso.Rperso.y + 40 > HAUT_WIND - 50)
      return 0;

   if (var -> perso.Rperso.y + var -> perso.Rperso.h + SDL_GetTicks () / 50 - var -> perso.saute / 50 < var -> p_lvl [var -> lvl - 1].Sol.y) { // le perso descend, c'est la deuxieme moitié du saut. on teste si il touche le sol
      var -> perso.Rperso.y += SDL_GetTicks () / 50 - var -> perso.saute / 50; // il ne le touche pas, il descend
   }
   else { // le perso est redescendu sur terre
      var -> perso.Rperso.y = var -> p_lvl [var -> lvl - 1].Sol.y - var -> perso.Rperso.h; // on le remet à la bonne ordonnée
      var -> perso.saute = 0; // le perso ne saute plus
      return 1; // le perso doit s'arretter de sauter
   }
   return 0; // le perso continue à sauter
}



   /* affiche les paramètres */
bool params (Var *var, Gal *gal) {

   int dem = true;

   bool continuer = true;

   while (continuer) { // tant que l'on demande qqchose
      dem = menu_X_poss_with_imgs (5, 28, (char [5][28]) {"affichage params\0", "touches\0", "personnages\0", "defis\0", "retour au menu des mondes\0"}, NULL, gal -> select, var -> fenetre, var -> renderer, var -> police); // on voit ce que l'on demande
      
      if (dem == 1) { // on affiche l'aide ou pas

         continuer = true; // c'est mieux que la boucle soit faite

         while (continuer) {

            dem = menu_2poss_message ("montrer", "cacher", "affichage de l'aide", gal -> select, var -> fenetre, var -> renderer, var -> police); // on voit ce que l'on demande

            printf ("%d\n", dem);

            if (dem == 1) // si on demande de ne plus afficher la texture params
            {
               printf ("true;\n");
               var -> aff = true; // ok
            }
            else if (dem == 2) // si on demande de montrer la texture params
            {
               printf ("false;\n");
               var -> aff = false; // ok
            }
            else // on demande de quitter
            {
               continuer = false; // on retournes au menu des paramètres
            }

            dem = true;
         }
      }
      else if (dem == 2) { // on configure les touches

         continuer = true; // c'est mieux que la boucle soit faite

         while (continuer) {

            dem = menu_3poss_message ("sauter", "pause", "reglages", "touches :", gal -> select, var -> fenetre, var -> renderer, var -> police); // on voit ce que l'on demande

            if (dem == 1) { // si on demande de modifier la touche pour sauter
               dem = get_touche (var -> fenetre, var -> renderer, var -> police); // on regarde quelle touche le joueur appuye, elle correspondra à l'action sauter
               if (dem != 0) // si ce n'est pas <esc>
                  SAUTER = dem;
            }
            else if (dem == 2) { // si on demande de modifier la touche pour mettre sur pause
               dem = get_touche (var -> fenetre, var -> renderer, var -> police); // on regarde quelle touche le joueur appuye, elle correspondra à l'action pause
               if (dem != 0) // si ce n'est pas <esc>
                  PAUSE = dem;
            }
            else if (dem == 3) { // si on demande de modifier la touche pour faire les réglages
               dem = get_touche (var -> fenetre, var -> renderer, var -> police); // on regarde quelle touche le joueur appuye, elle correspondra à l'action reglages
               if (dem != 0) // si ce n'est pas <esc>
                  REGLAGES = dem;
            }
            else { // on demande de quitter
               continuer = false; // on retournes au menu des paramètres
            }

            dem = true;
         }
      }
      else if (dem == 3) { // le joueur veut choisir un skin

         dem = choose_skin (var, gal); // on montre au joueur les skins disponibles

         if (dem == -1) // si on a quitté sans demander de skins
            return 0; // on ne change pas le skin
         else if (dem == -2) // si on demande de quitter complettement geoplatform
            exit_geoplatform (var, gal);
         else if (dem > var -> nb_skins - 1) // si on demande un skin que l'on n'a pas encore
            return 0;
         else // on demande un nouveau skin
            var -> perso.perso = gal -> skins [dem]; // on change le skin
      }
      else if (dem == 4) { // le joueur veut faire un défi
         defis (var, gal);
      }
      else if (dem == 5) { // le joueur veut retourner au menu des mondes
         return 1;
      }
      else {
         return 0;
      }
   }
}




   /* renvoie la touche appuillé */
int get_touche (SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *pol) {

   SDL_Event event; // contient les events
   
   SDL_Texture *text = NULL; // il y aura la chaine qui sera sur text à la fenetre
   
   SDL_Rect R = {0, 200, 650, 100}; // portion de l'écran sur laquelle sera affiché text
   SDL_Color C = {0, 255, 0}; // couleur avec laquelle on va écrire

   ttf_print_B ("appuillez sur la touche correspondant a l'action que vous modifiez ou sur <esc> pour annuler", &text, renderer, pol, C); // on écit la chaine sur text

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0); // on nettoiera en noir

   SDL_RenderClear (renderer); // on nettoit
   SDL_RenderCopy (renderer, text, NULL, &R); // on copie la chaine à la fenetre
   
   SDL_RenderPresent (renderer); // on met la fenetre à jour

   while (1) { // boucle infinie
   
      SDL_WaitEvent (&event); // on attent un évent

      if (event.type == SDL_KEYDOWN) // appuie sur une touche
         if (event.key.keysym.sym == SDLK_ESCAPE) // la touche appuillée est <echap>
            return 0; // on indique que l'on a quitté sans donner de touche
         else // une autre touche que <esc> est appuillée
            return event.key.keysym.sym; // on retourne la touche appuillée
   }
}




   /* le joueur choisit un skin */
int choose_skin (Var *var, Gal *gal) {

   int i = 0, j = 0; // pour parcourir les boucles for
   int skin_choosed = 0; // id du skin choisit

   bool press_q = false, press_ctrl = false; // si <q> est pressé / si <controle> est pressé 

   SDL_Rect skins [NB_SKINS_MAX] = {0}; // emplacement de chacuns des skins à l'écra,
   SDL_Rect select = {77, 33, 100, 108}; // emplacement du selecteur
   
   for (i = 0 ; i < 4 ; i += 1) { // on parcourt en y
      for (j = 0 ; j < 5 ; j += 1) { // on parcourt en x
            /* on place tous les skins au même endroit, celui du premier skin */
         skins [i * 5 + j].x = 90; // en x
         skins [i * 5 + j].y = 50; // en y
         skins [i * 5 + j].w = 75; // en w
         skins [i * 5 + j].h = 75; // en h
      }
   }

   for (i = 0 ; i < 4 ; i += 1) { // on parcourt en y
      for (j = 0 ; j < 5 ; j += 1) { // on parcourt en x

         if (j != 0) { // si on ne vient pas de sauter une ligne
            skins [i * 5 + j].x = skins [i * 5 + j - 1].x + 100; // on place le skin actuellement désigné par i * 5 + j en x
            skins [i * 5 + j].y = skins [i * 5 + j - 1].y; // on place le skin actuellement désigné par i * 5 + j en y
         }
         else if (i * 5 + j != 0) { // si ce n'est pas le premier skin (qui est déjà bien placé)
            skins [i * 5 + j].x = 90; // on retourne à la ligne
            skins [i * 5 + j].y = skins [i * 5 + j - i].y + 100; // on retourne à la ligne
         }
      }
   }

   SDL_RenderClear (var -> renderer); // on nettoie l'écran

   SDL_RenderCopy (var -> renderer, gal -> select_carre, NULL, &select); // on copie le selectionneur à l'écran

   for (i = 0 ; i < 4 ; i += 1) { // on parcourt en y
      for (j = 0 ; j < 5 ; j += 1) { // on parcourt en x
         if (i * 5 + j < var -> nb_skins) // si on a un skin à copier
            SDL_RenderCopy (var -> renderer, gal -> skins [i * 5 + j], NULL, &skins [i * 5 + j]); // on copie ce skin
         else
            SDL_RenderCopy (var -> renderer, gal -> unknow, NULL, &skins [i * 5 + j]); // sinon, on affiche "skin non débloqué"
      }
   }

   SDL_RenderPresent (var -> renderer); // on met la fenetre à jour

   SDL_Event event; // stockera les events

   while (1) { // boucle infinie

      SDL_Delay (75); // on est à ~15 fps (pas besoin de mieux)

      if (SDL_PollEvent (&event)) { // si on détecte un event

         if (event.type == SDL_QUIT) { // si on veut fermer la fenetre
            exit_geoplatform (var, gal); // on quitte tout
         }
         else if (event.type == SDL_KEYDOWN) { // une touche est appuillée
            if (event.key.keysym.sym == SDLK_RIGHT) { // touche flèche droite
               if (select.x + 100 <= 477) { // si on peut décaller le select
                  select.x += 100; // on décalle le select vers la droite
                  skin_choosed += 1; // le skin sélectionné est celui à droite de celui d'avant
               }
            }
               /* comme ci dessus, adapté vers la gauche */
            else if (event.key.keysym.sym == SDLK_LEFT) {
               if (select.x - 100 >= 77) {
                  select.x -= 100;
                  skin_choosed -= 1;
               }
            }
               /* comme ci dessus, adapté vers le bas */
            else if (event.key.keysym.sym == SDLK_DOWN) {
               if (select.y + 100 <= 333) {
                  select.y += 100;
                  skin_choosed += 5;
               }
            }
               /* comme ci dessus, adapté vers le haut */
            else if (event.key.keysym.sym == SDLK_UP) {
               if (select.y - 100 >= 33) {
                  select.y -= 100;
                  skin_choosed -= 5;
               }
            }
            else if (event.key.keysym.sym == SDLK_RETURN) { // <entré>
               if (skin_choosed == NB_SKINS_MAX - 1 && var -> nb_skins >= NB_SKINS_MAX - 1) // si le perso choisit est le perso ultime, et que l'on peut l'avoir
                  var -> perso.perso_is_u = true;
               else // si le perso choisit n'est pas le perso ultime
                  var -> perso.perso_is_u = false;
               return skin_choosed; // on retourne le skin choisit par le perso
            }
            else if (event.key.keysym.sym == SDLK_ESCAPE) { // on veut retourner au menu
               return -1;
            }
            else if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) { // <controlle>
               press_ctrl = true;
            }
            else if (event.key.keysym.sym == SDLK_q) { // <q>
               press_q = true;
            }
         }
         else if (event.type == SDL_KEYUP) { // une touche rellachée
            if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) { // <controlle>
               press_ctrl = false;
            }
            else if (event.key.keysym.sym == SDLK_q) { // <q>
               press_q = false;
            }
         }

            /* on met la fenetre à jour */
         SDL_RenderClear (var -> renderer);

         SDL_RenderCopy (var -> renderer, gal -> select_carre, NULL, &select);

         for (i = 0 ; i < 4 ; i += 1) { // on parcourt en y
            for (j = 0 ; j < 5 ; j += 1) { // on parcourt en x
               if (i * 5 + j < var -> nb_skins)
                  SDL_RenderCopy (var -> renderer, gal -> skins [i * 5 + j], NULL, &skins [i * 5 + j]);
               else
                  SDL_RenderCopy (var -> renderer, gal -> unknow, NULL, &skins [i * 5 + j]);
            }
         }

         SDL_RenderPresent (var -> renderer);
      }
      if (press_q && press_ctrl) // si ctrl + q
         exit_geoplatform (var, gal); // on quitte tout
   }
}














