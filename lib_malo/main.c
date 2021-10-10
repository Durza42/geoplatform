
#include "malo.h"

void test1 (SDL_Window *fenetre, SDL_Renderer *renderer, SDL_Texture *T);

int main (int argc, char **argv) {

   int a = 0;
   SDL_Window *fenetre = NULL;
   SDL_Renderer *renderer = NULL;
   SDL_Texture *T = NULL, *txt = NULL;

   if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
      printf ("SDL : %s \n", SDL_GetError ());

   if (TTF_Init () != 0)
      printf ("TTF : %s \n", TTF_GetError ());

   fenetre = SDL_CreateWindow("lib", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);//pointage du pointeur
   renderer = SDL_CreateRenderer (fenetre, -1, SDL_RENDERER_ACCELERATED);

   if (ld_img (&T, renderer, "fire.bmp"))
      printf ("ok\n");
   else 
      printf ("NEIN ! \n");
   
   SDL_RenderCopy (renderer, T, NULL, NULL);
   SDL_RenderPresent (renderer);

   SDL_Delay (1000);
   test1 (fenetre, renderer, T);
}


void test1 (SDL_Window *fenetre, SDL_Renderer *renderer, SDL_Texture *T) {
   
   SDL_Texture *txt = NULL;
   TTF_Font *pol = NULL;
   SDL_Color C = {0, 255, 0}, F = {255, 255, 255};
   SDL_Rect Rtxt = {50, 300, 500, 200};
   pol = TTF_OpenFont("Purisa.ttf", 65);
   if (pol == NULL)
      printf ("erreur : %s.\n", TTF_GetError ());


   ttf_print_so ("solide", &txt, renderer, pol, C);

   if (txt == NULL)
      printf ("erreur : ttf_print_so. \n");

   SDL_RenderClear (renderer);
   SDL_RenderCopy (renderer, T, NULL, NULL);
   SDL_RenderCopy (renderer, txt, NULL, &Rtxt);
   SDL_RenderPresent (renderer);

   SDL_Delay (1000);

   C.r = 255;
   C.g = 0;
   C.b = 0;

   ttf_print_sh ("shaded", &txt, renderer, pol, C, F);

   if (txt == NULL)
      printf ("erreur : ttf_print_so. \n");

   SDL_RenderClear (renderer);
   SDL_RenderCopy (renderer, T, NULL, NULL);
   SDL_RenderCopy (renderer, txt, NULL, &Rtxt);
   SDL_RenderPresent (renderer);

   SDL_Delay (1000);

   C.r = 0;
   C.g = 0;
   C.b = 255;

   ttf_print_B ("shaded", &txt, renderer, pol, C);

   if (txt == NULL)
      printf ("erreur : ttf_print_so. \n");

   SDL_RenderClear (renderer);
   SDL_RenderCopy (renderer, T, NULL, NULL);
   SDL_RenderCopy (renderer, txt, NULL, &Rtxt);
   SDL_RenderPresent (renderer);

   SDL_Delay (1000);

}









