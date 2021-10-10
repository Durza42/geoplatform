#ifndef GEO_OPERATIONS_H
 #define GEO_OPERATIONS_H


/*
 * geo_operations.h
 * This file is part of the malo's library
 *
 * Copyright (C) 2021 - Malo Montillaud
 *
 * the malo's library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * the malo's library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the malo's library. If not, see <http://www.gnu.org/licenses/>.
 */




   // point struct
typedef struct {
   int x, y;
} Point;


   // like Rect_wh. I use it at default.
typedef struct {
   int x, y, w, h;
} Rect;


   // rect struct defined by the coordinates of the left-bottom corner, the weigt and the height
typedef struct {
   int x, y, w, h;
} Rect_wh;


   // rect struct defined by the coordinates of the center, the weigt and the height
typedef struct {
   int x, y, w, h;
} Rect_center;


   // rect struct defined by the coordinates of the left-bottom corner and the coordinates of the right-top corner
typedef struct {
   int x, y, max_x, max_y;
} Rect_op;


   // test if two rects has intesection. return true if true, false else.
bool has_intercect (Rect rect1, Rect rect2);

   // test if the point is in the rect, for each format of rect :
bool is_in_rect (Point point, Rect rect);
bool is_in_rect_wh (Point point, Rect rect_wh);
bool is_in_rect_op (Point point, Rect rect_op);
bool is_in_rect_center (Point point, Rect rect_center);


#endif /* GEO_OPERATIONS_H */
