#ifndef imgs_cpp
#define imgs_cpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>

SDL_Texture* load_img_cpp (const char path[], SDL_Renderer *renderer) {

   SDL_Surface *tmp = NULL;
   SDL_Texture *tex = NULL;

   tmp = SDL_LoadBMP(path);

   if (tmp == NULL) {
      printf("Erreur SDL_LoadBMP : %s\n", SDL_GetError());
      return 0;
   }

   SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB (tmp -> format, 255, 255, 255));

   tex = SDL_CreateTextureFromSurface(renderer, tmp);

   SDL_FreeSurface(tmp);

   if (tex == NULL) {
      printf ("Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError());
      return 0;
   }

   return tex;
}

   /*chargement d'une image + test*/
bool ld_img_cpp (SDL_Texture **text, SDL_Renderer *rend, std::string img) {

   *text = load_img_cpp (img.c_str (), rend);//chargement de l'image
   if (text == NULL) {//echec
      printf ("erreur à l'image %s : %s \n", img.c_str (), SDL_GetError ());//message d'erreur
      return false;//retour d'erreur
   }

   return true;
}











   /*print directement sur la texture, en solide*/
bool ttf_print_so_cpp (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      std::cout << "erreur : ptr \"pol\" null. " << std::endl;
      return false;
   }

   SDL_Surface *texte = NULL;
   texte = TTF_RenderText_Solid (pol, str, C);

   *T = SDL_CreateTextureFromSurface (R, texte);
   SDL_FreeSurface (texte);

   return true;
}


   /*print directement sur la texture, en shaded*/
bool ttf_print_sh_cpp (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C, SDL_Color F) {

   if (pol == NULL) {
      std::cout << "erreur : ptr \"pol\" null. " << std::endl;
      return false;
   }

   SDL_Surface *texte = NULL;
   texte = TTF_RenderText_Shaded (pol, str, C, F);

   *T = SDL_CreateTextureFromSurface (R, texte);
   SDL_FreeSurface (texte);

   return true;
}


   /*print directement sur la texture, en Blended*/
bool ttf_print_B_cpp (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      std::cout << "error : ptr \"pol\" null. " << std::endl;
      return false;
   }

   SDL_Surface *texte = NULL;
   texte = TTF_RenderText_Blended (pol, str, C);

   *T = SDL_CreateTextureFromSurface (R, texte);
   SDL_FreeSurface (texte);

   return true;
}

   /*print sur un rect de la texture, en solide*/
bool ttf_print_R_so_cpp (const char str [], SDL_Texture **T, SDL_Rect rect, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      printf ("erreur : ptr \"pol\" null. \n");
      return false;
   }

   SDL_Surface *S_texte = NULL;
   S_texte = TTF_RenderText_Solid (pol, str, C);

   SDL_SetColorKey(S_texte, SDL_TRUE, SDL_MapRGB (S_texte -> format, 255, 255, 255));

   SDL_Texture *texte = SDL_CreateTextureFromSurface (R, S_texte);

   SDL_SetRenderTarget (R, *T);
   SDL_RenderCopy (R, texte, NULL, &rect);
   SDL_SetRenderTarget (R, NULL);

   SDL_DestroyTexture (texte);
   SDL_FreeSurface (S_texte);

   return true;
}


   /*print directement sur la fenetre, en shaded*/
bool ttf_print_R_sh_cpp (const char str [], SDL_Texture **T, SDL_Rect rect, SDL_Renderer *R, TTF_Font *pol, SDL_Color C, SDL_Color F) {

   if (pol == NULL) {
      printf ("erreur : ptr \"pol\" null. \n");
      return false;
   }

   SDL_Surface *S_texte = NULL;
   S_texte = TTF_RenderText_Shaded (pol, str, C, F);

   SDL_SetColorKey(S_texte, SDL_TRUE, SDL_MapRGB (S_texte -> format, 255, 255, 255));

   *T = SDL_CreateTextureFromSurface (R, S_texte);

   SDL_FreeSurface (S_texte);

   return true;
}


   /*print directement sur la fenetre, en Blended*/
bool ttf_print_R_B_cpp (const char str [], SDL_Texture **T, SDL_Rect rect, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      printf ("erreur : ptr \"pol\" null. \n");
      return false;
   }

   SDL_Surface *S_texte = NULL;
   S_texte = TTF_RenderText_Blended (pol, str, C);

   SDL_SetColorKey(S_texte, SDL_TRUE, SDL_MapRGB (S_texte -> format, 255, 255, 255));

   SDL_Texture *texte = SDL_CreateTextureFromSurface (R, S_texte);

   SDL_SetRenderTarget (R, *T);
   SDL_RenderCopy (R, texte, NULL, &rect);
   SDL_SetRenderTarget (R, NULL);

   SDL_DestroyTexture (texte);
   SDL_FreeSurface (S_texte);

   return true;
}



#endif
