#ifndef prot_cpp_h
#define prot_cpp_h

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

SDL_Texture* load_img_cpp (const char path[], SDL_Renderer *renderer);
bool ld_img_cpp (SDL_Texture **text, SDL_Renderer *rend, std::string img);
bool ttf_print_so_cpp (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C);
bool ttf_print_sh_cpp (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C, SDL_Color F);
bool ttf_print_B_cpp (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C);
bool ttf_print_R_so_cpp (const char str [], SDL_Texture **T, SDL_Rect rect, SDL_Renderer *R, TTF_Font *pol, SDL_Color C);
bool ttf_print_R_sh_cpp (const char str [], SDL_Texture **T, SDL_Rect rect, SDL_Renderer *R, TTF_Font *pol, SDL_Color C, SDL_Color F);
bool ttf_print_R_B_cpp (const char str [], SDL_Texture **T, SDL_Rect rect, SDL_Renderer *R, TTF_Font *pol, SDL_Color C);
std::string itostr (int integer);
char* itoCstr (int integer);

int menu_2poss_cpp (const char* mess_1, const char* mess_2, SDL_Texture* select, SDL_Window* fenetre, SDL_Renderer* renderer, TTF_Font* police);
int menu_3poss_cpp (char *mess_1, char *mess_2, char *mess_3, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police);
int menu_4poss_cpp (char *mess_1, char *mess_2, char *mess_3, char *mess_4, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police);
int menu_2poss_message_cpp (const char *mess_1, const char *mess_2, const char *mess, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police);
int menu_3poss_message_cpp (char *mess_1, char *mess_2, char *mess_3, char *mess, SDL_Texture *select, SDL_Window *fenetre, SDL_Renderer *renderer, TTF_Font *police);
int menu_X_poss_with_imgs_cpp (int nb_strs, int long_str, char** strs, SDL_Texture** texts, SDL_Texture* select, SDL_Window* fenetre, SDL_Renderer* renderer, TTF_Font* police);

#endif
