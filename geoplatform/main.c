/*
 * main.c
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
 * geoplatform est un jeu de platforme géométrique, où vous incarnez un petit carré qui avence sans cesse mais doit sauter au dessus 
 * d'obstacles pour ne pas mourir.
 */


int main (void) {
   Var var = {
                NULL, // fenetre
                NULL, // renderer
                NULL, // render
                {0, 0, LONG_WIND, HAUT_WIND}, // Rrender
                NULL, // police
                1, // lvl
                1, // lvl_max_atteint
                0, // monde_max_atteint
                5, // depl
                { // perso
                   {0, 0, 40, 40}, // Rperso
                   NULL, // perso
                   false, // saute
                   false, // perso_is_u
                   {0, 0, 238 / 2, 238 / 2}, // R_du_perso
                   0,
                },
                { // arrivee
                   NULL, //texure
                   {0, 0, 0, 0}, //rect
                },
                { // p_lvl [] (on donne juste des valeurs, ce sera initialisé dans le fichier init_lvls.c)
                   {
                      0, // longeur de la map
                      {0, 0, 0, 0}, // Sol
                      {0, 0, 0}, // couleur_sol
                      {0}, // sol_sec
                      { // pics []
                         {
                            {0, 0, 50, 150}, // Rect
                            {0, 0, 0, 0}, // rects_v
                            {0, 0, 0, 0}, // rects_h
                            NULL, // text_pic
                         },
                      },
                      { // dead_zones []
                         {
                            {0, 0, 0, 0}, // on initialise tout à 0
                            {0, 0, 0},
                         },
                      },
                      { // cannons
                         {
                            {0}, // surf
                            {0}, // Rcannon
                            NULL, // Tcannon
                         }
                      },
                   },
                },
                false, // extr_data
                false, // vol
                NULL, // params
                {25, 25, 179, 76}, // Rparams
                true, // aff
                0, // nb_skin
                0, // perso_act
                NULL, // data_file
                0, // itt
                false, // is_paused
             };

   Gal gal = {
                NULL // toutes les variables sont à NULL
             };

   Gal_mus gal_mus;

   if (!Inits (&var, &gal, &gal_mus)) // l'initialisation a échoué (Inits () est la fonction ci-dessous)
      return EXIT_FAILURE; // on quitte.

   if (menu_2poss ("utiliser les donnees d'une partie precedente", "nouvelle partie", gal.select, var.fenetre, var.renderer, var.police) == 1)
      var.data_file = recup_datas (&var, &gal);

   bool continuer = true; //boolean pour la boucle suivante

   char oui [10];

   int monde = 0;

   while (continuer) { // tant que le jeu continue

      for (int i = 0; i < NB_LVLS_TOTAL; i += 1) {
         gal_mus.deja_vu [i] = false;
      }

      monde = select_monde (&var, &gal); // on récupère le niveau demandé par la fonction sélect_lvl

      if (monde == -1 || var.lvl == -1) // si la selection de niveau et/ou de monde ne s'est pas passée correctement
         exit_geoplatform (&var, &gal); // on quitte
      else
         var.lvl += (monde - 1) * 4;

      init_lvls (&var, &gal); // on initialise le niveau correspondant

      continuer = boucle_principale (&var, &gal, &gal_mus); // LE jeu en lui même. 

      if (gal_mus.Bmusique [var.lvl - 1]) {
         Mix_PauseMusic();
         Mix_RewindMusic();
      }

      if (var.lvl_max_atteint >= NB_LVLS [var.monde_max_atteint])
         var.monde_max_atteint += 1;

      /* ici, continuer vaut true si le joueur veut un autre niveau. */
   }

   exit_geoplatform (&var, &gal);

   return EXIT_SUCCESS;
}



   /* initialisation de l'ensemble des variables */
bool Inits (Var *var, Gal *gal, Gal_mus *gal_mus) {

   int i = 0, j = 0; // pour parcourir les boucles for

   if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) { // initialisation de la SDL2 ; si ça a planté
      printf ("erreur initialisation de la SDL2 : %s.\n\n", SDL_GetError ()); // on affiche un message d'erreur
      return false; // on retournela valeur corespondant à erreur
   }

   if (TTF_Init () < 0) { // initialisation de SDL_TTF ; si ça a planté
      printf ("erreur initialisation de SDL_TTF : %s.\n\n", TTF_GetError ()); // on affiche un message d'erreur
      return false; // on retournela valeur corespondant à erreur
   }

   if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) { // initialisation de SDL_Mixer ; si ça a planté
      printf ("erreur initialisation de SDL_Mixer : %s.\n\n", Mix_GetError ()); // on affiche un message d'erreur
      return false; // on retournela valeur corespondant à erreur
   }

   var  -> fenetre = SDL_CreateWindow ("geoplatform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LONG_WIND, HAUT_WIND, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE); // la fenetre. titre : geoplatform. position : peu importe. taille : 650 x 500. redimentionnable.

   var -> renderer = SDL_CreateRenderer (var -> fenetre, -1, SDL_RENDERER_ACCELERATED); // renderer, que l'on acocie à la fenetre

   var -> render = SDL_CreateTexture (var -> renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, LONG_WIND, HAUT_WIND); // on peut maintenant dessiner sur var -> arriere_plan ou sur la fenetre.

   if (!init_gal (gal, var -> renderer)) { // le chargement des images à échoué (inits_gal () est la fonction ci-dessous)
      printf ("le chargement des images a échoué.\n\n"); // message d'erreur
      return false;
   }
   if (!init_gal_mus (gal_mus, var -> renderer)) {
      printf ("le chargement des musiques a échoué. On continue, mais on vous conseille tres vivement de regler le probleme au plus vite, car il pourrait avoir des concequences sur la qualite de jeu.\n\n"); // message d'erreur
   }

   SDL_SetWindowIcon (var -> fenetre, load_img_surface ("images/miniature.bmp"));

   var -> police = TTF_OpenFont ("../lib_malo/Purisa.ttf", 25); // on charge la police
   if (var -> police == NULL) { // si cela n'a pas fonctionné
      printf ("erreur initialisation de la police : %s\n", SDL_GetError ()); // on affiche un message d'erreur
      return false; // on quitte
   }

   var -> lvl = 1; // on commence au niveau 1;

   var -> perso.perso = gal -> perso; // on initialise la variable perso (l'image apparente du personnage) à la variable gal -> perso (l'image du perso stockée en mémoire vive)

   var -> arrivee.texture = gal -> arrivee;

   for (i = 0 ; i < NB_CANNONS ; i += 1) // fait pour tous les cannons
      for (j = 0 ; j < 4; j += 1) // de tous les niveaux
         var -> p_lvl [j].cannons [i].Tcannon = gal -> cannon; // on charge l'image du cannon

   for (i = 0 ; i < NB_PICS ; i += 1) // fait pour tous les pics
      for (j = 0 ; j < 4 ; j += 1) // de tous les niveaux
         var -> p_lvl [j].pics [i].text_pic = gal -> pic; // pareil pour le pic

   var -> params = gal -> params;

   var -> nb_skins = 1;

   return true;
}

   /* initialisation da la structure gal : chargement des images */
bool init_gal (Gal *gal, SDL_Renderer *renderer) {

   gal -> ecran_titre = load_img ("images/ecran_titre.bmp", renderer); // on charge l'image de l'écran titre dans la variable ecran_titre de la structure gal
   if (gal -> ecran_titre == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> mondes = load_img ("images/mondes.bmp", renderer); // on charge l'image de l'écran titre dans la variable ecran_titre de la structure gal
   if (gal -> mondes == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> perso = load_img ("images/perso.bmp", renderer); // on charge l'image du perso dans la variable ecran_titre de la structure gal
   if (gal -> perso == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> pic = load_img ("images/pic.bmp", renderer); // on charge l'image du perso dans la variable ecran_titre de la structure gal
   if (gal -> pic == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> pic_returned = load_img ("images/pic_returned.bmp", renderer); // on charge l'image du perso dans la variable ecran_titre de la structure gal
   if (gal -> pic_returned == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> arriere_plan [0] = load_img ("images/lvl_1.bmp", renderer); // on charge l'image du fond d'écran du lvl 1 dans la variable ecran_titre de la structure gal
   if (gal -> arriere_plan [0] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> arriere_plan [1] = load_img ("images/lvl_2.bmp", renderer); // on charge l'image du fond d'écran du lvl 2 dans la variable ecran_titre de la structure gal
   if (gal -> arriere_plan [1] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> arriere_plan [2] = load_img ("images/lvl_3.bmp", renderer); // on charge l'image du fond d'écran du lvl 3 dans la variable ecran_titre de la structure gal
   if (gal -> arriere_plan [2] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> arriere_plan [3] = load_img ("images/lvl_4.bmp", renderer); // on charge l'image du fond d'écran du lvl 4 dans la variable ecran_titre de la structure gal
   if (gal -> arriere_plan [3] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> arriere_plan [4] = load_img ("images/lvl_5.bmp", renderer); // on charge l'image du fond d'écran du lvl 4 dans la variable ecran_titre de la structure gal
   if (gal -> arriere_plan [4] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> arriere_plan [5] = load_img ("images/lvl_6.bmp", renderer); // on charge l'image du fond d'écran du lvl 4 dans la variable ecran_titre de la structure gal
   if (gal -> arriere_plan [5] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> arriere_plan [6] = load_img ("images/lvl_7.bmp", renderer); // on charge l'image du fond d'écran du lvl 4 dans la variable ecran_titre de la structure gal
   if (gal -> arriere_plan [6] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> arriere_plan [7] = load_img ("images/lvl_8.bmp", renderer); // on charge l'image du fond d'écran du lvl 4 dans la variable ecran_titre de la structure gal
   if (gal -> arriere_plan [7] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> arrivee = load_img ("images/arrive.bmp", renderer); // on charge l'image du fond d'écran du lvl 1 dans la variable ecran_titre de la structure gal
   if (gal -> arrivee == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> select = load_img ("images/selectionneur.bmp", renderer); // on charge l'image du selectionneur dans la variable select de la structure gal
   if (gal -> select == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> select_carre = load_img ("images/selectionneur_carre.bmp", renderer); // on charge l'image du selectionneur dans la variable select de la structure gal
   if (gal -> select_carre == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> cannon = load_img ("images/cannon.bmp", renderer); // on charge l'image du selectionneur dans la variable cannon de la structure gal
   if (gal -> cannon == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> cannon_bas = load_img ("images/cannon_bas.bmp", renderer); // on charge l'image du selectionneur dans la variable cannon_bas de la structure gal
   if (gal -> cannon_bas == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal -> params = load_img ("images/p_for_params.bmp", renderer); // on charge l'image du selectionneur dans la variable select de la structure gal
   if (gal -> params == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie ici "erreur"
   }

   char str [] = "images/perso_00.bmp"; // une chaine dans laquelle on écrira le nom des fichiers à charger dans la boucle suivante
   int i = 0; // pour parcourir la boucle for
   
   gal -> skins [0] = load_img ("images/perso.bmp", renderer); // on charge l'image "str" dans la variable select de la structure gal
   if (gal -> skins [i] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie ici "erreur"
   }

   for (i = 1 ; i < NB_SKINS_MAX - 1 ; i += 1) {

      sprintf (str, "images/perso_%d.bmp", i + 1); // on chargera l'image perso_[i]

      gal -> skins [i] = load_img (str, renderer); // on charge l'image "str" dans la variable select de la structure gal
      if (gal -> skins [i] == NULL) { // l'opération n'a pas fonctonné
         printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
         return false; // retour d'une valeur qui signifie ici "erreur"
      }
   }
   
   gal -> skins [NB_SKINS_MAX - 1] = load_img ("images/perso_u.bmp", renderer); // on charge l'image "perso_u" dans la variable select de la structure gal
   if (gal -> skins [NB_SKINS_MAX - 1] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie ici "erreur"
   }

   gal -> unknow = load_img ("images/unknow.bmp", renderer); // on charge l'image du selectionneur dans la variable select de la structure gal
   if (gal -> unknow == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie ici "erreur"
   }

   gal -> cadena = load_img ("images/cadena.bmp", renderer); // on charge l'image du selectionneur dans la variable select de la structure gal
   if (gal -> cadena == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie ici "erreur"
   }

   gal -> cadena_ouvert = load_img ("images/cadena_ouvert.bmp", renderer); // on charge l'image du selectionneur dans la variable select de la structure gal
   if (gal -> cadena_ouvert == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal : ptr null ;\n%s\n\n", SDL_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie ici "erreur"
   }

   return true; // tout a bien fontionné, on retourne la valeur corespondante
}



   /* initialisation des musiques */
bool init_gal_mus (Gal_mus *gal_mus, SDL_Renderer *renderer) {

   Mix_VolumeMusic (MIX_MAX_VOLUME);

   gal_mus -> Musique [4] = Mix_LoadMUS ("musiques/for_a_few_dollars_more.mp3");
   if (gal_mus -> Musique [4] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal_mus : ptr null ;\n%s\n\n", Mix_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }
   gal_mus -> Musique [5] = Mix_LoadMUS ("musiques/man_with_harmonica.mp3");
   if (gal_mus -> Musique [5] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal_mus : ptr null ;\n%s\n\n", Mix_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }
   gal_mus -> Musique [6] = Mix_LoadMUS ("musiques/my_fault.mp3");
   if (gal_mus -> Musique [6] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal_mus : ptr null ;\n%s\n\n", Mix_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }
   gal_mus -> Musique [7] = Mix_LoadMUS ("musiques/the_wild_horde.mp3");
   if (gal_mus -> Musique [6] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal_mus : ptr null ;\n%s\n\n", Mix_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }


   gal_mus -> Musique_cutted [4] = Mix_LoadMUS ("musiques/for_a_few_dollars_more_cutted.mp3");
   if (gal_mus -> Musique_cutted [4] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal_mus : ptr null ;\n%s\n\n", Mix_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }
   gal_mus -> Musique_cutted [5] = Mix_LoadMUS ("musiques/man_with_harmonica_cutted.mp3");
   if (gal_mus -> Musique_cutted [5] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal_mus : ptr null ;\n%s\n\n", Mix_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }
   gal_mus -> Musique_cutted [6] = Mix_LoadMUS ("musiques/my_fault_cutted.mp3");
   if (gal_mus -> Musique_cutted [6] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal_mus : ptr null ;\n%s\n\n", Mix_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }
   gal_mus -> Musique_cutted [7] = Mix_LoadMUS ("musiques/the_wild_horde.mp3");
   if (gal_mus -> Musique_cutted [6] == NULL) { // l'opération n'a pas fonctonné
      printf ("Erreur : init_gal_mus : ptr null ;\n%s\n\n", Mix_GetError ()); // affichage du message d'erreur
      return false; // retour d'une valeur qui signifie dans ce code "erreur"
   }

   gal_mus -> Bmusique [0] = false;
   gal_mus -> Bmusique [1] = false;
   gal_mus -> Bmusique [2] = false;
   gal_mus -> Bmusique [3] = false;

   gal_mus -> Bmusique [4] = true;
   gal_mus -> Bmusique [5] = true;
   gal_mus -> Bmusique [6] = true;
   gal_mus -> Bmusique [7] = true;

   gal_mus -> long_intro [0] = 0;
   gal_mus -> long_intro [1] = 0;
   gal_mus -> long_intro [2] = 0;
   gal_mus -> long_intro [3] = 0;

   gal_mus -> long_intro [4] = 45000;
   gal_mus -> long_intro [5] = 45000;
   gal_mus -> long_intro [6] = 25000;
   gal_mus -> long_intro [7] = -1; // il y a bien une musique, mais elle prend directement...

   gal_mus -> volume = MIX_MAX_VOLUME;

   return true;
}


   /* gestion des initialisations de niveau */
void init_lvls (Var *var, Gal *gal) {

   if (var -> lvl == 1) {
      lvl_1_1 (var, gal);
   }
   else if (var -> lvl == 2) {
      lvl_2_1 (var, gal);
   }
   else if (var -> lvl == 3) {
      lvl_3_1 (var, gal);
   }
   else if (var -> lvl == 4) {
      lvl_4_1 (var, gal);
   }
   else if (var -> lvl == 5) {
      lvl_1_2 (var, gal);
   }
   else if (var -> lvl == 6) {
      lvl_2_2 (var, gal);
   }
   else if (var -> lvl == 7) {
      lvl_3_2 (var, gal);
   }
   else if (var -> lvl == 8) {
      lvl_4_2 (var, gal);
   }
   else {
      printf ("une erreur est survenu : niveau non concu.\n\n\n");
      exit_geoplatform (var, gal); // on quitte tout
   }
}




   /* on demande à quiter geoplatform */
void exit_geoplatform (Var *var, Gal *gal) {

   SDL_Event event;

   while (SDL_PollEvent (&event));

   printf ("exit_geoplatform\n\n");

   int ind = 0;

   ind = menu_3poss_message ("non", "dans le fichier de sauvegarde actuel", "dans un nouveau fichier de sauvegarde", "enregistrer votre avencement ?", gal -> select, var -> fenetre, var -> renderer, var -> police);

   if (ind == -1) {
      return;
   }
   else if (ind == 1) {
      exit (0);
   }
   else if (ind == 2) {
      save_datas (var -> data_file, var);
      exit (0);
   }
   else if (ind == 3) {
      save_datas (NULL, var);
      exit (0);
   }

   return;
}






















