int menu_2poss (char *mess_1, char *mess_2, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police) {

   bool continuer = true;
   Uint32 press_p = false, press_w = false;

   int ind = 1, press_down = 0, press_up = 0, i = 0;

   int w = 0, h = 0; // dim de la fenetre
   
   SDL_GetWindowSize (fenetre, &w, &h);

   SDL_Rect Rselect = {w / 7.5, h / 3.448275862, w / 1.766513057, h / 8};
   SDL_Rect R1 = {w / 7.5 + 75, h / 3.448275862 + 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R2 = {w / 7.5 + 75, h / 3.448275862 + 5 + h / 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Event event;

   SDL_Texture *m1 = NULL, *m2 = NULL;

   SDL_Color C = {0, 255, 0};

   ttf_print_B (mess_1, &m1, renderer, police, C);
   ttf_print_B (mess_2, &m2, renderer, police, C);

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);

   SDL_RenderClear (renderer);
   SDL_RenderCopy (renderer, select, NULL, &Rselect);
   SDL_RenderCopy (renderer, m1, NULL, &R1);
   SDL_RenderCopy (renderer, m2, NULL, &R2);
   SDL_RenderPresent (renderer);

   while (continuer) {

      SDL_Delay (20);//pour ne pas prendre 100% du CPU (1000fps c'est beaucoup, 50 c'est mieux)

      while (SDL_PollEvent (&event)) {//si il y a eu un evenement
         switch (event.type) {//on regarde lequel
            case SDL_QUIT://fermer la fenetre SVP!
               return -1;
           break;
            case SDL_KEYDOWN:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = true;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = true;

               if (event.key.keysym.sym == SDLK_RETURN)
                  continuer = false;

               if (event.key.keysym.sym == SDLK_ESCAPE)
                  return 0;

               if (event.key.keysym.sym == SDLK_DOWN && ind != 3) {
                  if (press_up + 400 < SDL_GetTicks ()) {
                     ind += 1;
                     press_down = SDL_GetTicks ();

                     for (i = 0 ; i < h / 5 ; i += 1) {
                        Rselect.y += 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }

               if (event.key.keysym.sym == SDLK_UP && ind != 1) {
                  if (press_down + 400 < SDL_GetTicks ()) {
                     ind -= 1;
                     press_up = SDL_GetTicks ();

                     for (i = 0; i < h / 5; i += 1) {
                        Rselect.y -= 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }
           break;
            case SDL_KEYUP:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = false;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = false;

           break;
            default://par défaut, on ne fait rien.
           break;
         }
         if (press_p && press_w) {
            return -1;
         }
      }
   }

   return ind;
}




int menu_3poss (char *mess_1, char *mess_2, char *mess_3, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police) {

   bool continuer = true;
   Uint32 press_p = false, press_w = false;

   int ind = 1, press_down = 0, press_up = 0, i = 0;

   int w = 0, h = 0; // dim de la fenetre
   
   SDL_GetWindowSize (fenetre, &w, &h);

   SDL_Rect Rselect = {w / 7.5, h / 3.448275862, w / 1.766513057, h / 8};
   SDL_Rect R1 = {w / 7.5 + 75, h / 3.448275862 + 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R2 = {w / 7.5 + 75, h / 3.448275862 + 5 + h / 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R3 = {w / 7.5 + 75, h / 3.448275862 + 5 * 2 + h * 2 / 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Event event;

   SDL_Texture *m1 = NULL, *m2 = NULL, *m3 = NULL;

   SDL_Color C = {0, 255, 0};

   ttf_print_B (mess_1, &m1, renderer, police, C);
   ttf_print_B (mess_2, &m2, renderer, police, C);
   ttf_print_B (mess_3, &m3, renderer, police, C);

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);

   SDL_RenderClear (renderer);
   SDL_RenderCopy (renderer, select, NULL, &Rselect);
   SDL_RenderCopy (renderer, m1, NULL, &R1);
   SDL_RenderCopy (renderer, m2, NULL, &R2);
   SDL_RenderCopy (renderer, m3, NULL, &R3);
   SDL_RenderPresent (renderer);

   while (continuer) {

      SDL_Delay (20);//pour ne pas prendre 100% du CPU (1000fps c'est beaucoup, 50 c'est mieux)

      while (SDL_PollEvent (&event)) {//si il y a eu un evenement
         switch (event.type) {//on regarde lequel
            case SDL_QUIT://fermer la fenetre SVP!
               return -1;
           break;
            case SDL_KEYDOWN:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = true;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = true;

               if (event.key.keysym.sym == SDLK_RETURN)
                  continuer = false;

               if (event.key.keysym.sym == SDLK_ESCAPE)
                  return 0;

               if (event.key.keysym.sym == SDLK_DOWN && ind != 3) {
                  if (press_up + 400 < SDL_GetTicks ()) {
                     ind += 1;
                     press_down = SDL_GetTicks ();

                     for (i = 0 ; i < h / 5 ; i += 1) {
                        Rselect.y += 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderCopy (renderer, m3, NULL, &R3);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }

               if (event.key.keysym.sym == SDLK_UP && ind != 1) {
                  if (press_down + 400 < SDL_GetTicks ()) {
                     ind -= 1;
                     press_up = SDL_GetTicks ();

                     for (i = 0; i < h / 5; i += 1) {
                        Rselect.y -= 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderCopy (renderer, m3, NULL, &R3);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }
           break;
            case SDL_KEYUP:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = false;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = false;

           break;
            default://par défaut, on ne fait rien.
           break;
         }
         if (press_p && press_w) {
            return -1;
         }
      }
   }

   return ind;
}


int menu_4poss (char *mess_1, char *mess_2, char *mess_3, char *mess_4, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police) {

   bool continuer = true;
   Uint32 press_p = false, press_w = false;

   int ind = 1, press_down = 0, press_up = 0, i = 0;

   int w = 0, h = 0; // dim de la fenetre
   
   SDL_GetWindowSize (fenetre, &w, &h);

   SDL_Rect Rselect = {w / 7.5, h / 8, w / 1.766513057, h / 8};
   SDL_Rect R1 = {w / 7.5 + 75, h / 8 + 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R2 = {w / 7.5 + 75, h / 8 + 5 + h / 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R3 = {w / 7.5 + 75, h / 8 + 5 * 2 + h * 2 / 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R4 = {w / 7.5 + 75, h / 8 + 5 * 2 + h * 3 / 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Event event;

   SDL_Texture *m1 = NULL, *m2 = NULL, *m3 = NULL, *m4 = NULL;

   SDL_Color C = {0, 255, 0};

   ttf_print_B (mess_1, &m1, renderer, police, C);
   ttf_print_B (mess_2, &m2, renderer, police, C);
   ttf_print_B (mess_3, &m3, renderer, police, C);
   ttf_print_B (mess_4, &m4, renderer, police, C);

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);

   SDL_RenderClear (renderer);
   SDL_RenderCopy (renderer, select, NULL, &Rselect);
   SDL_RenderCopy (renderer, m1, NULL, &R1);
   SDL_RenderCopy (renderer, m2, NULL, &R2);
   SDL_RenderCopy (renderer, m3, NULL, &R3);
   SDL_RenderCopy (renderer, m4, NULL, &R4);
   SDL_RenderPresent (renderer);

   while (continuer) {

      SDL_Delay (20);//pour ne pas prendre 100% du CPU (1000fps c'est beaucoup, 50 c'est mieux)

      while (SDL_PollEvent (&event)) {//si il y a eu un evenement
         switch (event.type) {//on regarde lequel
            case SDL_QUIT://fermer la fenetre SVP!
               return -1;
           break;
            case SDL_KEYDOWN:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = true;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = true;

               if (event.key.keysym.sym == SDLK_RETURN)
                  continuer = false;

               if (event.key.keysym.sym == SDLK_ESCAPE)
                  return 0;

               if (event.key.keysym.sym == SDLK_DOWN && ind != 4) {
                  if (press_up + 400 < SDL_GetTicks ()) {
                     ind += 1;
                     press_down = SDL_GetTicks ();

                     for (i = 0 ; i < h / 5 ; i += 1) {
                        Rselect.y += 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderCopy (renderer, m3, NULL, &R3);
                        SDL_RenderCopy (renderer, m4, NULL, &R4);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }

               if (event.key.keysym.sym == SDLK_UP && ind != 1) {
                  if (press_down + 400 < SDL_GetTicks ()) {
                     ind -= 1;
                     press_up = SDL_GetTicks ();

                     for (i = 0; i < h / 5; i += 1) {
                        Rselect.y -= 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderCopy (renderer, m3, NULL, &R3);
                        SDL_RenderCopy (renderer, m4, NULL, &R4);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }
           break;
            case SDL_KEYUP:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = false;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = false;

           break;
            default://par défaut, on ne fait rien.
           break;
         }
         if (press_p && press_w) {
            return -1;
         }
      }
   }

   return ind;
}


int menu_2poss_message (char *mess_1, char *mess_2, char *mess, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police) {

   bool continuer = true;
   Uint32 press_p = false, press_w = false;

   int ind = 1, press_down = 0, press_up = 0, i = 0;

   int w = 0, h = 0; // dim de la fenetre
   
   SDL_GetWindowSize (fenetre, &w, &h);

   SDL_Rect Rselect = {w / 7.5, h / 3.448275862, w / 1.766513057, h / 8};
   SDL_Rect R1 = {w / 7.5 + 75, h / 3.448275862 + 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R2 = {w / 7.5 + 75, h / 3.448275862 + 5 + h / 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R = {w / 7.5 + 75, 50, w / 3, h / 6};
   SDL_Event event;

   SDL_Texture *m1 = NULL, *m2 = NULL, *m = NULL;

   SDL_Color C = {0, 255, 0};

   ttf_print_B (mess_1, &m1, renderer, police, C);
   ttf_print_B (mess_2, &m2, renderer, police, C);
   ttf_print_B (mess, &m, renderer, police, C);

   SDL_RenderClear (renderer);
   SDL_RenderCopy (renderer, select, NULL, &Rselect);
   SDL_RenderCopy (renderer, m1, NULL, &R1);
   SDL_RenderCopy (renderer, m2, NULL, &R2);
   SDL_RenderCopy (renderer, m, NULL, &R);
   SDL_RenderPresent (renderer);

   while (continuer) {

      SDL_Delay (20);//pour ne pas prendre 100% du CPU (1000fps c'est beaucoup, 50 c'est mieux)

      while (SDL_PollEvent (&event)) {//si il y a eu un evenement
         switch (event.type) {//on regarde lequel
            case SDL_QUIT://fermer la fenetre SVP!
               return -1;
           break;
            case SDL_KEYDOWN:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = true;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = true;

               if (event.key.keysym.sym == SDLK_RETURN)
                  continuer = false;

               if (event.key.keysym.sym == SDLK_ESCAPE)
                  return 0;


               if (event.key.keysym.sym == SDLK_DOWN && ind != 2) {
                  if (press_up + 400 < SDL_GetTicks ()) {
                     ind = 2;
                     press_down = SDL_GetTicks ();

                     for (i = 0 ; i < h / 5 ; i += 1) {
                        Rselect.y += 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderCopy (renderer, m, NULL, &R);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }

               if (event.key.keysym.sym == SDLK_UP && ind != 1) {
                  if (press_down + 400 < SDL_GetTicks ()) {
                     ind = 1;
                     press_up = SDL_GetTicks ();

                     for (i = 0; i < h / 5; i += 1) {
                        Rselect.y -= 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderCopy (renderer, m, NULL, &R);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }
           break;
            case SDL_KEYUP:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = false;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = false;

           break;
            default://par défaut, on ne fait rien.
           break;
         }
         if (press_p && press_w) {
            return -1;
         }
      }
   }

   return ind;
}




int menu_3poss_message (char *mess_1, char *mess_2, char *mess_3, char *mess, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police) {

   bool continuer = true;
   Uint32 press_p = false, press_w = false;

   int ind = 1, press_down = 0, press_up = 0, i = 0;

   int w = 0, h = 0; // dim de la fenetre
   
   SDL_GetWindowSize (fenetre, &w, &h);

   SDL_Rect Rselect = {w / 7.5, h / 3.448275862, w / 1.766513057, h / 8};
   SDL_Rect R1 = {w / 7.5 + 75, h / 3.448275862 + 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R2 = {w / 7.5 + 75, h / 3.448275862 + 5 + h / 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R3 = {w / 7.5 + 75, h / 3.448275862 + 5 * 2 + h * 2 / 5, w / 1.766513057 - 85, h / 8 - 10};
   SDL_Rect R = {w / 7.5 + 75, 50, w / 3, h / 6};
   SDL_Event event;

   SDL_Texture *m1 = NULL, *m2 = NULL, *m3 = NULL, *m = NULL;

   SDL_Color C = {0, 255, 0};

   ttf_print_B (mess_1, &m1, renderer, police, C);
   ttf_print_B (mess_2, &m2, renderer, police, C);
   ttf_print_B (mess_3, &m3, renderer, police, C);
   ttf_print_B (mess, &m, renderer, police, C);

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);

   SDL_RenderClear (renderer);
   SDL_RenderCopy (renderer, select, NULL, &Rselect);
   SDL_RenderCopy (renderer, m1, NULL, &R1);
   SDL_RenderCopy (renderer, m2, NULL, &R2);
   SDL_RenderCopy (renderer, m3, NULL, &R3);
   SDL_RenderCopy (renderer, m, NULL, &R);
   SDL_RenderPresent (renderer);

   while (continuer) {

      SDL_Delay (20);//pour ne pas prendre 100% du CPU (1000fps c'est beaucoup, 50 c'est mieux)

      while (SDL_PollEvent (&event)) {//si il y a eu un evenement
         switch (event.type) {//on regarde lequel
            case SDL_QUIT://fermer la fenetre SVP!
               return -1;
           break;
            case SDL_KEYDOWN:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = true;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = true;

               if (event.key.keysym.sym == SDLK_RETURN)
                  continuer = false;

               if (event.key.keysym.sym == SDLK_ESCAPE)
                  return 0;

               if (event.key.keysym.sym == SDLK_DOWN && ind != 3) {
                  if (press_up + 400 < SDL_GetTicks ()) {
                     ind += 1;
                     press_down = SDL_GetTicks ();

                     for (i = 0 ; i < h / 5 ; i += 1) {
                        Rselect.y += 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderCopy (renderer, m3, NULL, &R3);
                        SDL_RenderCopy (renderer, m, NULL, &R);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }

               if (event.key.keysym.sym == SDLK_UP && ind != 1) {
                  if (press_down + 400 < SDL_GetTicks ()) {
                     ind -= 1;
                     press_up = SDL_GetTicks ();

                     for (i = 0; i < h / 5; i += 1) {
                        Rselect.y -= 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);
                        SDL_RenderCopy (renderer, select, NULL, &Rselect);
                        SDL_RenderCopy (renderer, m1, NULL, &R1);
                        SDL_RenderCopy (renderer, m2, NULL, &R2);
                        SDL_RenderCopy (renderer, m3, NULL, &R3);
                        SDL_RenderCopy (renderer, m, NULL, &R);
                        SDL_RenderPresent (renderer);
                     }
                  }
               }
           break;
            case SDL_KEYUP:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = false;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = false;

           break;
            default://par défaut, on ne fait rien.
           break;
         }
         if (press_p && press_w) {
            return -1;
         }
      }
   }

   return ind;
}




int menu_X_poss_with_imgs (int nb_strs, int long_str, char strs [nb_strs][long_str], SDL_Texture *texts [], SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police) {

   int ind = 1, press_down = 0, press_up = 0, i = 0, j = 0;

   bool continuer = true;
   Uint32 press_p = false, press_w = false;

   int w = 0, h = 0; // dim de la fenetre
   
   SDL_GetWindowSize (fenetre, &w, &h);

   SDL_Rect R [nb_strs];
   SDL_Rect Rselect = {0};
   SDL_Event event;

   R [0].x = 100;
   R [0].y = 50;
   R [0].h = (h - nb_strs / 6) / (nb_strs + 1) - 15;
   R [0].w = 350;

   Rselect.x = 0;
   Rselect.y = R [0].y - R [0].h / 2.5;
   Rselect.w = R [0].w + ((R [0].h / 2.5) * 2) + R [0].h;
   Rselect.h = R [0].h + ((R [0].h / 2.5) * 2);

   for (i = 1; i < nb_strs; i += 1) {
      R [i].x = R [i - 1].x;
      R [i].w = R [i - 1].w;
      R [i].y = R [i - 1].y + (R [i - 1].h / (50 / 65.0));
      R [i].h = R [i - 1].h;
   }

   SDL_Texture *m [nb_strs];

   SDL_Color C = {0, 255, 0};

   for (i = 0; i < nb_strs; i += 1) {
      ttf_print_B (strs [i], &m [i], renderer, police, C);
   }

   SDL_Rect Rimg [nb_strs];

   for (i = 0; i < nb_strs; i += 1) {
      Rimg [i].x = R [i].x + R [i].w + 25;
      Rimg [i].w = R [i].h;
      Rimg [i].y = R [i].y;
      Rimg [i].h = R [i].h - 15;
   }

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);

   SDL_RenderClear (renderer);

   for (i = 0; i < nb_strs; i += 1) {
      SDL_RenderCopy (renderer, m [i], NULL, &R [i]);
   }

   if (texts != NULL) {
      for (i = 0; i < nb_strs; i += 1) {
         SDL_RenderCopy (renderer, texts [i], NULL, &Rimg [i]);
      }
   }

   SDL_RenderCopy (renderer, select, NULL, &Rselect);

   SDL_RenderPresent (renderer);

   while (continuer) {

      SDL_Delay (20);//pour ne pas prendre 100% du CPU (1000fps c'est beaucoup, 50 c'est mieux)

      while (SDL_PollEvent (&event)) {//si il y a eu un evenement
         switch (event.type) {//on regarde lequel
            case SDL_QUIT://fermer la fenetre SVP!
               return -1;
           break;
            case SDL_KEYDOWN:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = true;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = true;

               if (event.key.keysym.sym == SDLK_RETURN)
                  continuer = false;

               if (event.key.keysym.sym == SDLK_ESCAPE)
                  return 0;

               if (event.key.keysym.sym == SDLK_DOWN && ind != nb_strs) {
                  if (press_up + 400 < SDL_GetTicks ()) {
                     ind += 1;
                     press_down = SDL_GetTicks ();

                     for (i = 0 ; i < R [0].h / (50 / 65.0) ; i += 1) {

                        Rselect.y += 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);

                        for (j = 0; j < nb_strs; j += 1) {
                           SDL_RenderCopy (renderer, m [j], NULL, &R [j]);
                        }

                        if (texts != NULL) {
                           for (j = 0; j < nb_strs; j += 1) {
                              SDL_RenderCopy (renderer, texts [j], NULL, &Rimg [j]);
                           }
                        }

                        SDL_RenderCopy (renderer, select, NULL, &Rselect);

                        SDL_RenderPresent (renderer);
                     }
                  }
               }

               if (event.key.keysym.sym == SDLK_UP && ind != 1) {
                  if (press_down + 400 < SDL_GetTicks ()) {
                     ind -= 1;
                     press_up = SDL_GetTicks ();

                     for (i = 0; i < R [0].h / (50 / 65.0); i += 1) {
                        Rselect.y -= 1;
                        SDL_Delay (2.5);
                        SDL_RenderClear (renderer);

                        for (j = 0; j < nb_strs; j += 1) {
                           SDL_RenderCopy (renderer, m [j], NULL, &R [j]);
                        }

                        if (texts != NULL) {
                           for (j = 0; j < nb_strs; j += 1) {
                              SDL_RenderCopy (renderer, texts [j], NULL, &Rimg [j]);
                           }
                        }

                        SDL_RenderCopy (renderer, select, NULL, &Rselect);

                        SDL_RenderPresent (renderer);
                     }
                  }
               }
           break;
            case SDL_KEYUP:

               if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                  press_p = false;

               if (event.key.keysym.sym == SDLK_q)
                  press_w = false;

           break;
            default://par défaut, on ne fait rien.
           break;
         }
         if (press_p && press_w) {
            return -1;
         }
      }
   }

   return ind;
}
