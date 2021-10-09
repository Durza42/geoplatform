

SDL_Surface *createSurfaceFromTexture(SDL_Texture *texture)
{
    Uint32 format_pixels;
    SDL_Surface *surface = NULL;
    void *pixels = NULL;
    int pitch, w, h;

    if (SDL_QueryTexture(texture, &format_pixels, NULL, &w, &h) != 0)
    {
        fprintf(stderr, "SDL_QueryTexture: %s.\n", SDL_GetError());
        return NULL;
    }

    surface = SDL_CreateRGBSurfaceWithFormatFrom(pixels, w, h, 32, w * sizeof(Uint32), format_pixels);
    if(NULL == surface)
        fprintf(stderr, "Erreur SDL_CreateSurfaceFrom : %s.\n", SDL_GetError());

    return surface;
}


#ifndef CPP

void setPixel(SDL_Surface *surface, Uint8 r, Uint8 g, Uint8 b, Uint8 a, size_t x, size_t y)
{
    Uint32 *pixels = surface->pixels; /* Nos pixels sont sur 32 bits */
    Uint32 couleur = SDL_MapRGBA(surface->format, r, g, b, a);
    pixels[y * surface->w + x] = couleur;
}



   /* renvoie une chaine de caractère sasie par le joueur (dans la fenetre) */
int saisie_texte (SDL_Renderer *renderer, SDL_Window *fenetre, TTF_Font *police, long long_limite, char str_returned [long_limite], char *message) {

   int w_wind = 0, h_wind = 0;
   SDL_GetWindowSize (fenetre, &w_wind, &h_wind);

   int i = 0;
   for (i = 0; i < long_limite; i += 1) {
      str_returned [i] = '\0';
   }

   int num_carac_act = 0;

   bool maj = false, ctrl = false, q = false;

   SDL_Color C = {25, 25, 25}, c = {200, 200, 200};

   SDL_Texture *text_act = NULL, *mess = NULL;
   ttf_print_B (message, &mess, renderer, police, c);

   SDL_Rect Zone_text = {w_wind / 5, h_wind / 3, w_wind / 1.75, h_wind / 3};

   SDL_Rect Rmess = {w_wind / 5, h_wind / 7, w_wind / 1.5, h_wind / 5};

   SDL_Event event;
   bool condition = true;

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);
   SDL_RenderClear (renderer);

   SDL_DestroyTexture (text_act);
   ttf_print_B (str_returned, &text_act, renderer, police, C);

   SDL_SetRenderDrawColor (renderer, 230, 230, 230, 0);
   SDL_RenderFillRect (renderer, &Zone_text);

   SDL_RenderCopy (renderer, mess, NULL, &Rmess);

   SDL_RenderPresent (renderer);

   while (condition) {

      SDL_Delay (50);

      if (SDL_PollEvent (&event)) {
         if (event.type == SDL_QUIT) {
            return -1;
         }
         else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_RETURN) {
               return num_carac_act;
            }
            if (event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_RSHIFT) {
               maj = true;
            }
            if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) {
               ctrl = true;
            }

            if (event.key.keysym.sym == SDLK_q) {
               if (maj)
                  str_returned [num_carac_act] = 'Q';
               else
                  str_returned [num_carac_act] = 'q';
               num_carac_act += 1;

               q = true;
            }

            if (event.key.keysym.sym == SDLK_BACKSPACE) {
               
               if (num_carac_act > 0)
                  num_carac_act -= 1;

               str_returned [num_carac_act] = '\0';
            }

            if (num_carac_act < long_limite) {

               if (event.key.keysym.sym == SDLK_SPACE) {
                  str_returned [num_carac_act] = ' ';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_1) {
                  str_returned [num_carac_act] = '1';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_2) {
                  str_returned [num_carac_act] = '2';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_3) {
                  str_returned [num_carac_act] = '3';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_4) {
                  str_returned [num_carac_act] = '4';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_5) {
                  str_returned [num_carac_act] = '5';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_6) {
                  str_returned [num_carac_act] = '6';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_7) {
                  str_returned [num_carac_act] = '7';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_8) {
                  str_returned [num_carac_act] = '8';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_9) {
                  str_returned [num_carac_act] = '9';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_0) {
                  str_returned [num_carac_act] = '0';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_a) {
                  if (maj)
                     str_returned [num_carac_act] = 'A';
                  else
                        str_returned [num_carac_act] = 'a';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_b) {
                  if (maj)
                     str_returned [num_carac_act] = 'B';
                  else
                     str_returned [num_carac_act] = 'b';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_c) {
                  if (maj)
                     str_returned [num_carac_act] = 'C';
                  else
                     str_returned [num_carac_act] = 'c';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_d) {
                  if (maj)
                     str_returned [num_carac_act] = 'D';
                  else
                     str_returned [num_carac_act] = 'd';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_e) {
                  if (maj)
                     str_returned [num_carac_act] = 'E';
                  else
                     str_returned [num_carac_act] = 'e';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_f) {
                  if (maj)
                     str_returned [num_carac_act] = 'F';
                  else
                     str_returned [num_carac_act] = 'f';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_g) {
                  if (maj)
                     str_returned [num_carac_act] = 'G';
                  else
                     str_returned [num_carac_act] = 'g';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_h) {
                  if (maj)
                     str_returned [num_carac_act] = 'H';
                  else
                     str_returned [num_carac_act] = 'h';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_i) {
                  if (maj)
                     str_returned [num_carac_act] = 'I';
                  else
                     str_returned [num_carac_act] = 'i';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_j) {
                  if (maj)
                     str_returned [num_carac_act] = 'J';
                  else
                     str_returned [num_carac_act] = 'j';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_k) {
                  if (maj)
                     str_returned [num_carac_act] = 'K';
                  else
                     str_returned [num_carac_act] = 'k';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_l) {
                  if (maj)
                     str_returned [num_carac_act] = 'L';
                  else
                     str_returned [num_carac_act] = 'l';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_m) {
                  if (maj)
                     str_returned [num_carac_act] = 'M';
                  else
                     str_returned [num_carac_act] = 'm';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_n) {
                  if (maj)
                     str_returned [num_carac_act] = 'N';
                  else
                     str_returned [num_carac_act] = 'n';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_o) {
                  if (maj)
                     str_returned [num_carac_act] = 'O';
                  else
                     str_returned [num_carac_act] = 'o';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_p) {
                  if (maj)
                     str_returned [num_carac_act] = 'P';
                  else
                     str_returned [num_carac_act] = 'p';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_r) {
                  if (maj)
                     str_returned [num_carac_act] = 'R';
                  else
                     str_returned [num_carac_act] = 'r';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_s) {
                  if (maj)
                     str_returned [num_carac_act] = 'S';
                  else
                     str_returned [num_carac_act] = 's';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_t) {
                  if (maj)
                     str_returned [num_carac_act] = 'T';
                  else
                     str_returned [num_carac_act] = 't';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_u) {
                  if (maj)
                     str_returned [num_carac_act] = 'U';
                  else
                     str_returned [num_carac_act] = 'u';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_v) {
                  if (maj)
                     str_returned [num_carac_act] = 'V';
                  else
                     str_returned [num_carac_act] = 'v';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_w) {
                  if (maj)
                     str_returned [num_carac_act] = 'W';
                  else
                     str_returned [num_carac_act] = 'w';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_x) {
                  if (maj)
                     str_returned [num_carac_act] = 'X';
                  else
                     str_returned [num_carac_act] = 'x';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_y) {
                  if (maj)
                     str_returned [num_carac_act] = 'Y';
                  else
                     str_returned [num_carac_act] = 'y';
                  num_carac_act += 1;
               }
               if (event.key.keysym.sym == SDLK_z) {
                  if (maj)
                     str_returned [num_carac_act] = 'Z';
                  else
                     str_returned [num_carac_act] = 'z';
                  num_carac_act += 1;
               }
            }
         }
         else if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_RSHIFT) {
               maj = false;
            }
            if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) {
               ctrl = false;
            }
            if (event.key.keysym.sym == SDLK_q) {
               q = false;
            }
         }

         if (ctrl && q)
            return -1;

      }

      SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);
      SDL_RenderClear (renderer);

      SDL_DestroyTexture (text_act);
      ttf_print_B (str_returned, &text_act, renderer, police, C);

      SDL_SetRenderDrawColor (renderer, 230, 230, 230, 0);
      SDL_RenderFillRect (renderer, &Zone_text);

      SDL_RenderCopy (renderer, text_act, NULL, &Zone_text);
      SDL_RenderCopy (renderer, mess, NULL, &Rmess);

      SDL_RenderPresent (renderer);
   }
}



#endif


   /*attendre pendant X temps, tout en restant à l'affut d'une eventuelle demande de fermeture de la fenetres*/
void att_nn_blqte (const int delay, SDL_Window *wind, bool Pw) {
   
   int comm = SDL_GetTicks ();
   bool continuer = true, press_p = false, press_w = false;
   SDL_Event event;

   while (continuer) {
      SDL_Delay (10);
      if (comm + delay < SDL_GetTicks ())
         continuer = false;

      if (SDL_PollEvent (&event)) {//si il y a eu un evenement
         switch (event.type) {//on regarde lequel
            case SDL_QUIT://fermer la fenetre SVP!
               SDL_DestroyWindow (wind);//on la ferme
               SDL_Quit ();//on quitte la SDL
               exit (EXIT_SUCCESS);//on quitte le programe
           break;
            case SDL_KEYDOWN:
               if (Pw)
                  if (event.key.keysym.sym == SDLK_p)
                     press_p = true;
                  else if (event.key.keysym.sym == SDLK_w)
                     press_w = true;
           break;
            case SDL_KEYUP:

               if (event.key.keysym.sym == SDLK_p)
                  press_p = false;

               if (event.key.keysym.sym == SDLK_w)
                  press_w = false;

           break;
            default://par défaut, on ne fait rien.
           break;
         }
      }
      if (press_p && press_w) {
         SDL_DestroyWindow (wind);//on la ferme
         SDL_Quit ();//on quitte la SDL
         exit (EXIT_SUCCESS);//on quitte le programe
      }
   }
}

void trie_tableau (const int origine [], int rendu [], int taille) {
   
   int i = 0, j = 0, c = 0;

   for (i = 0 ; i < taille ; i += 1) {
      rendu [i] = origine [i];
   }

   for (i = 0 ; i < taille - 1 ; i++) {
       for(j = i + 1 ; j < taille ; j++) {
           if (rendu [i] > rendu [j]) {
               c = rendu [i];
               rendu [i] = rendu [j];
               rendu [j] = c;
           }
      }
   }
}


int plus_petit_du_tableau (const int origine [], int taille) {

   int tableau_trie [taille];

   trie_tableau (origine, tableau_trie, taille);

   return tableau_trie [0];
}


int plus_grand_du_tableau (const int origine [], int taille) {

   int tableau_trie [taille];

   trie_tableau (origine, tableau_trie, taille);

   return tableau_trie [taille - 1];
}


double moyenne_tableau (const int tableau [], int taille) {

   double moyenne = 0;
   int i = 0;

   for (i = 0; i < taille; i += 1) {
      moyenne += tableau [i];
   }

   moyenne /= taille;

   return moyenne;
}


void afficher_message (char *str, int size_str, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *font) {

   char c = ' ';
   int i = 0;

   if (size_str == 0)
      for (i = 0; c != '\0' && c != '\n'; i += 1)
         c = str [i];

   size_str = i;

   SDL_Texture *text [(int)size_str / 20 + 1];
   SDL_Color C = {255, 255, 255};

   char true_str [20] = {' '};

   int j = 0, l = 0;

   int w, h;
   
   SDL_GetWindowSize (fenetre, &w, &h);

   SDL_Rect rect [(int)size_str / 20 + 1];

   rect [0].w = w / 1.5;
   rect [0].y = 50;
   rect [0].x = w / 2 - rect [0].w / 2;
   rect [0].h = 50;

   for (i = 1 ; i < (int)size_str / 20 + 1 ; i += 1) {
      rect [i].y = rect [i - 1].y + 80;
      rect [i].h = rect [0].h;
      rect [i].w = rect [0].w;
      rect [i].x = rect [0].x;
   }

   for (i = 0 ; i < (int)size_str / 20 + 1 ; i += 1) {

      for (j = 0; j < 20; j += 1)
         true_str [j] = str [i * 20 + j];

      true_str [j] = '\0';

      ttf_print_B (true_str, &text [i], renderer, font, C);
   }

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);

   SDL_RenderClear (renderer);

   for (i = 0 ; i < (int)size_str / 20 + 1 ; i += 1)
   {
      SDL_RenderCopy (renderer, text [i], NULL, &rect [i]);
   }

   printf ("\n\n");

   SDL_RenderPresent (renderer);

   for (i = 0 ; i < (int)size_str / 20 ; i += 1)
      SDL_DestroyTexture (text [i]);
}




   /* on attend l'appuie d'une touche */
void att_touche (int id_touche) {

   SDL_Event event;

   bool press_ctrl = false, press_q = false;

   while (1) {
      SDL_WaitEvent (&event);

      if (event.type == SDL_QUIT)
         exit (0);
      else if (event.type == SDL_KEYDOWN)
         if (event.key.keysym.sym == id_touche)
            return;
         else if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
            press_ctrl = true;
         else if (event.key.keysym.sym == SDLK_q)
            press_q = true;
      else if (event.type == SDL_KEYUP)
         if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
            press_ctrl = false;
         else if (event.key.keysym.sym == SDLK_q)
            press_q = false;

      if (press_ctrl && press_q)
         exit (0);
   }
}





SDL_Color choose_color (SDL_Window *fenetre, SDL_Renderer *renderer, SDL_Color color, TTF_Font *font, int* error) {

   int champ = 0;
   int i = 0;

   bool q = false, ctrl = false, maj = false;

   SDL_Texture *render = NULL;
   render = SDL_CreateTexture (renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 650, 500);

   SDL_Rect Rcolor = {650 / 2 - 100 / 2, 100, 100, 50};

   SDL_Rect zones_ecrit [3] = {{125, 250, 100, 50}, {275, 250, 100, 50}, {425, 250, 100, 50}};
   SDL_Rect zones_texte [3] = {{150, 185, 25, 30}, {300, 185, 25, 30}, {450, 185, 25, 30}};

   SDL_Texture *leg_zones [3] = {NULL, NULL, NULL};

   ttf_print_B ("r", &leg_zones [0], renderer, font, (SDL_Color) {255, 255, 255});
   ttf_print_B ("g", &leg_zones [1], renderer, font, (SDL_Color) {255, 255, 255});
   ttf_print_B ("b", &leg_zones [2], renderer, font, (SDL_Color) {255, 255, 255});

   SDL_Texture *aff_values [3] = {NULL, NULL, NULL};
   char value_r [] = "   \0", value_g [] = "   \0", value_b [] = "   \0";

   sprintf (value_r, "%d%c", color.r, '\0');
   sprintf (value_g, "%d%c", color.g, '\0');
   sprintf (value_b, "%d%c", color.b, '\0');

   ttf_print_B (value_r, &aff_values [0], renderer, font, (SDL_Color) {0, 0, 0});
   ttf_print_B (value_g, &aff_values [1], renderer, font, (SDL_Color) {0, 0, 0});
   ttf_print_B (value_b, &aff_values [2], renderer, font, (SDL_Color) {0, 0, 0});


   SDL_Event event;
   
   while (true) {

      SDL_Delay (50);

      while (SDL_PollEvent (&event)) {

         if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_q) {
               q = true;
            }

            if (event.key.keysym.sym == SDLK_ESCAPE) {
               *error = -1;
               return color;
            }
            if (event.key.keysym.sym == SDLK_SPACE) {
               return color;
            }
            else if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL) {
               ctrl = true;
            }
            else if (event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_RSHIFT) {
               maj = true;
            }
            else if (event.key.keysym.sym == SDLK_TAB) {
               if (maj) {
                  if (champ - 1 >= 0)
                     champ -= 1;
               }
               else {
                  if (champ < 2)
                     champ += 1;
               }
            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
               if (champ == 0) {
                  if (color.r > 9)
                     color.r /= 10;
                  else
                     color.r = 0;
               }
               else if (champ == 1) {
                  if (color.g > 9)
                     color.g /= 10;
                  else
                     color.g = 0;
               }
               else if (champ == 2) {
                  if (color.b > 9)
                     color.b /= 10;
                  else
                     color.b = 0;
               }
            }
            else if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_3 ||
                     event.key.keysym.sym == SDLK_4 || event.key.keysym.sym == SDLK_5 || event.key.keysym.sym == SDLK_6 ||
                     event.key.keysym.sym == SDLK_7 || event.key.keysym.sym == SDLK_8 || event.key.keysym.sym == SDLK_9 ||
                     event.key.keysym.sym == SDLK_0) {

               if (champ == 0) {
                  if (color.r * 10 < 255) {
                     color.r *= 10;
                     color.r += event.key.keysym.sym - 48; // SDLK_0 = 48, SDLK_1 = 49, SDLK_2 = 50, ...
                  }
               }
               else if (champ == 1) {
                  if (color.g * 10 < 255) {
                     color.g *= 10;
                     color.g += event.key.keysym.sym - 48;
                  }
               }
               else if (champ == 2) {
                  if (color.b * 10 < 255) {
                     color.b *= 10;
                     color.b += event.key.keysym.sym - 48;
                  }
               }
            }
         }
         if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_q)
               q = false;
            else if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
               ctrl = false;
            else if (event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_RSHIFT)
               maj = false;

         }
         if (event.type == SDL_QUIT) {
            *error = true;
            return (SDL_Color){0, 0, 0};
         }
      }

      if (q == true && ctrl == true) {
         *error = true;
         return (SDL_Color){0, 0, 0};
      }

      sprintf (value_r, "%d%c", color.r, '\0');
      sprintf (value_g, "%d%c", color.g, '\0');
      sprintf (value_b, "%d%c", color.b, '\0');

      for (i = 0; i < 3; i += 1)
         SDL_DestroyTexture (aff_values [i]);

      ttf_print_B (value_r, &aff_values [0], renderer, font, (SDL_Color) {0, 0, 0});
      ttf_print_B (value_g, &aff_values [1], renderer, font, (SDL_Color) {0, 0, 0});
      ttf_print_B (value_b, &aff_values [2], renderer, font, (SDL_Color) {0, 0, 0});

      SDL_SetRenderTarget (renderer, render);

      SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);
      SDL_RenderClear (renderer);

      SDL_SetRenderDrawColor (renderer, color.r, color.g, color.b, 0);
      SDL_RenderFillRect (renderer, &Rcolor);

      SDL_SetRenderDrawColor (renderer, 255, 255, 255, 0);
      for (i = 0; i < 3; i += 1)
         SDL_RenderFillRect (renderer, &zones_ecrit [i]);

      SDL_SetRenderDrawColor (renderer, 255, 0, 0, 0);
      SDL_RenderDrawRect (renderer, &zones_ecrit [champ]);

      for (i = 0; i < 3; i += 1)
         SDL_RenderCopy (renderer, leg_zones [i], NULL, &zones_texte [i]);

      for (i = 0; i < 3; i += 1)
         SDL_RenderCopy (renderer, aff_values [i], NULL, &zones_ecrit [i]);

      SDL_SetRenderTarget (renderer, NULL);

      SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);
      SDL_RenderClear (renderer);

      SDL_RenderCopy (renderer, render, NULL, NULL);
      SDL_RenderPresent (renderer);
   }
}





int search_str_str (char *str, int size_str, char *str_searched, int size_str_searched) {

   int i = 0, j = 0;

   for (i = 0; i < size_str; i += 1) {

      if (j >= size_str_searched)
         return i - size_str_searched;

      if (str [i] == str_searched [j])
         if (j >= size_str_searched)
            return i;
         else
            j += 1;
      else
         j = 0;
   }

   return -1;
}





