#include "geo_operations.h"


bool has_intercect (Rect rect1, Rect rect2) {

      // trop à droite
   if (rect1.x >= rect2.max_x)
      return false;

      // trop à gauche
   if (rect1.max_x <= rect2.x)
      return false;

      // trop en haut
   if (rect1.y >= rect2.max_y)
      return false;

      // trop en bas
   if (rect1.max_y <= rect2.y)
      return false;

      // pas de non-intersection => intersection
   return true;
}


bool is_in_rect (Point point, Rect rect) {

   if (point.x > rect.x && point.x < rect.x + rect.w
    && point.y > rect.y && point.y < rect.y + rect.h)
      return true;
   else
      return false;
}


bool is_in_rect_wh (Point point, Rect_wh rect) {

   if (point.x > rect.x && point.x < rect.x + rect.w
    && point.y > rect.y && point.y < rect.y + rect.h)
      return true;
   else
      return false;
}


bool is_in_rect_op (Point point, Rect_op rect) {

   if (point.x > rect.x && point.x < rect.max_x
    && point.y > rect.y && point.y < rect.max_y)
      return true;
   else
      return false;
}


bool is_in_rect_center (Point point, Rect_center rect) {

   if (point.x > rect.x - rect.w / 2.0 && point.x < rect.x + rect.w / 2.0
    && point.y > rect.y - rect.h / 2.0 && point.y < rect.y + rect.h / 2.0)
      return true;
   else
      return false;
}

