/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision$
 ***********************************************************************EHEADER*/


#include <math.h>
#include "_hypre_utilities.h"

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_swap( HYPRE_Int *v,
           HYPRE_Int  i,
           HYPRE_Int  j )
{
   HYPRE_Int temp;

   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_swap2(HYPRE_Int     *v,
           HYPRE_Real  *w,
           HYPRE_Int      i,
           HYPRE_Int      j )
{
   HYPRE_Int temp;
   HYPRE_Real temp2;

   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
   temp2 = w[i];
   w[i] = w[j];
   w[j] = temp2;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_BigSwap2(HYPRE_BigInt     *v,
           HYPRE_Real  *w,
           HYPRE_Int    i,
           HYPRE_Int    j )
{
   HYPRE_BigInt temp;
   HYPRE_Real temp2;

   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
   temp2 = w[i];
   w[i] = w[j];
   w[j] = temp2;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_swap2i(HYPRE_Int  *v,
                  HYPRE_Int  *w,
                  HYPRE_Int  i,
                  HYPRE_Int  j )
{
   HYPRE_Int temp;

   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
   temp = w[i];
   w[i] = w[j];
   w[j] = temp;
}


/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/


/* AB 11/04 */

void hypre_swap3i(HYPRE_Int  *v,
                  HYPRE_Int  *w,
                  HYPRE_Int  *z,
                  HYPRE_Int  i,
                  HYPRE_Int  j )
{
   HYPRE_Int temp;

   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
   temp = w[i];
   w[i] = w[j];
   w[j] = temp;
   temp = z[i];
   z[i] = z[j];
   z[j] = temp;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_swap3_d(HYPRE_Real  *v,
                  HYPRE_Int  *w,
                  HYPRE_Int  *z,
                  HYPRE_Int  i,
                  HYPRE_Int  j )
{
   HYPRE_Int temp;
   HYPRE_Real temp_d;
   

   temp_d = v[i];
   v[i] = v[j];
   v[j] = temp_d;
   temp = w[i];
   w[i] = w[j];
   w[j] = temp;
   temp = z[i];
   z[i] = z[j];
   z[j] = temp;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_BigSwap4_d(HYPRE_Real  *v,
                  HYPRE_BigInt  *w,
                  HYPRE_Int  *z,
                  HYPRE_Int *y, 
                  HYPRE_Int  i,
                  HYPRE_Int  j )
{
   HYPRE_Int temp;
   HYPRE_BigInt big_temp;
   HYPRE_Real temp_d;
   

   temp_d = v[i];
   v[i] = v[j];
   v[j] = temp_d;
   big_temp = w[i];
   w[i] = w[j];
   w[j] = big_temp;
   temp = z[i];
   z[i] = z[j];
   z[j] = temp;
   temp = y[i];
   y[i] = y[j];
   y[j] = temp;

}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_swap_d( HYPRE_Real *v,
                   HYPRE_Int  i,
                   HYPRE_Int  j )
{
   HYPRE_Real temp;

   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_qsort0( HYPRE_Int *v,
             HYPRE_Int  left,
             HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
      return;
   hypre_swap( v, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
      if (v[i] < v[left])
      {
         hypre_swap(v, ++last, i);
      }
   hypre_swap(v, left, last);
   hypre_qsort0(v, left, last-1);
   hypre_qsort0(v, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_qsort1( HYPRE_Int *v,
	     HYPRE_Real *w,
             HYPRE_Int  left,
             HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
      return;
   hypre_swap2( v, w, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
      if (v[i] < v[left])
      {
         hypre_swap2(v, w, ++last, i);
      }
   hypre_swap2(v, w, left, last);
   hypre_qsort1(v, w, left, last-1);
   hypre_qsort1(v, w, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_BigQsort1( HYPRE_BigInt *v,
	     HYPRE_Real *w,
             HYPRE_Int  left,
             HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
      return;
   hypre_BigSwap2( v, w, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
      if (v[i] < v[left])
      {
         hypre_BigSwap2(v, w, ++last, i);
      }
   hypre_BigSwap2(v, w, left, last);
   hypre_BigQsort1(v, w, left, last-1);
   hypre_BigQsort1(v, w, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_qsort2i( HYPRE_Int *v,
                    HYPRE_Int *w,
                    HYPRE_Int  left,
                    HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
   {
      return;
   }
   hypre_swap2i( v, w, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
   {
      if (v[i] < v[left])
      {
         hypre_swap2i(v, w, ++last, i);
      }
   }
   hypre_swap2i(v, w, left, last);
   hypre_qsort2i(v, w, left, last-1);
   hypre_qsort2i(v, w, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/*   sort on w (HYPRE_Real), move v (AB 11/04) */


void hypre_qsort2( HYPRE_Int *v,
	     HYPRE_Real *w,
             HYPRE_Int  left,
             HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
      return;
   hypre_swap2( v, w, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
      if (w[i] < w[left])
      {
         hypre_swap2(v, w, ++last, i);
      }
   hypre_swap2(v, w, left, last);
   hypre_qsort2(v, w, left, last-1);
   hypre_qsort2(v, w, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/* sort on v, move w and z (AB 11/04) */

void hypre_qsort3i( HYPRE_Int *v,
                    HYPRE_Int *w,
                    HYPRE_Int *z,
                    HYPRE_Int  left,
                    HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
   {
      return;
   }
   hypre_swap3i( v, w, z, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
   {
      if (v[i] < v[left])
      {
         hypre_swap3i(v, w, z, ++last, i);
      }
   }
   hypre_swap3i(v, w, z, left, last);
   hypre_qsort3i(v, w, z, left, last-1);
   hypre_qsort3i(v, w, z, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/* sort min to max based on absolute value */

void hypre_qsort3_abs(HYPRE_Real *v,
                      HYPRE_Int *w,
                      HYPRE_Int *z,
                      HYPRE_Int  left,
                      HYPRE_Int  right )
{
   HYPRE_Int i, last;
   if (left >= right)
      return;
   hypre_swap3_d( v, w, z, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
      if (fabs(v[i]) < fabs(v[left]))
      {
         hypre_swap3_d(v,w, z, ++last, i);
      }
   hypre_swap3_d(v, w, z, left, last);
   hypre_qsort3_abs(v, w, z, left, last-1);
   hypre_qsort3_abs(v, w, z, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/* sort min to max based on absolute value */

void hypre_BigQsort4_abs(HYPRE_Real *v,
                      HYPRE_BigInt *w,
                      HYPRE_Int *z,
                      HYPRE_Int *y,
                      HYPRE_Int  left,
                      HYPRE_Int  right )
{
   HYPRE_Int i, last;
   if (left >= right)
      return;
   hypre_BigSwap4_d( v, w, z, y, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
      if (fabs(v[i]) < fabs(v[left]))
      {
         hypre_BigSwap4_d(v,w, z, y, ++last, i);
      }
   hypre_BigSwap4_d(v, w, z, y, left, last);
   hypre_BigQsort4_abs(v, w, z, y, left, last-1);
   hypre_BigQsort4_abs(v, w, z, y, last+1, right);
}


/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/
/* sort min to max based on absolute value */

void hypre_qsort_abs(HYPRE_Real *w,
                     HYPRE_Int  left,
                     HYPRE_Int  right )
{
   HYPRE_Int i, last;
   if (left >= right)
      return;
   hypre_swap_d( w, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
      if (fabs(w[i]) < fabs(w[left]))
      {
         hypre_swap_d(w, ++last, i);
      }
   hypre_swap_d(w, left, last);
   hypre_qsort_abs(w, left, last-1);
   hypre_qsort_abs(w, last+1, right);
}




/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_BigSwapbi(HYPRE_BigInt  *v,
                  HYPRE_Int  *w,
                  HYPRE_Int  i,
                  HYPRE_Int  j )
{
   HYPRE_BigInt big_temp;
   HYPRE_Int temp;

   big_temp = v[i];
   v[i] = v[j];
   v[j] = big_temp;
   temp = w[i];
   w[i] = w[j];
   w[j] = temp;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_BigQsortbi( HYPRE_BigInt *v,
                    HYPRE_Int *w,
                    HYPRE_Int  left,
                    HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
   {
      return;
   }
   hypre_BigSwapbi( v, w, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
   {
      if (v[i] < v[left])
      {
         hypre_BigSwapbi(v, w, ++last, i);
      }
   }
   hypre_BigSwapbi(v, w, left, last);
   hypre_BigQsortbi(v, w, left, last-1);
   hypre_BigQsortbi(v, w, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_BigSwapLoc(HYPRE_BigInt  *v,
                  HYPRE_Int  *w,
                  HYPRE_Int  i,
                  HYPRE_Int  j )
{
   HYPRE_BigInt big_temp;

   big_temp = v[i];
   v[i] = v[j];
   v[j] = big_temp;
   w[i] = j;
   w[j] = i;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_BigQsortbLoc( HYPRE_BigInt *v,
                    HYPRE_Int *w,
                    HYPRE_Int  left,
                    HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
   {
      return;
   }
   hypre_BigSwapLoc( v, w, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
   {
      if (v[i] < v[left])
      {
         hypre_BigSwapLoc(v, w, ++last, i);
      }
   }
   hypre_BigSwapLoc(v, w, left, last);
   hypre_BigQsortbLoc(v, w, left, last-1);
   hypre_BigQsortbLoc(v, w, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/


void hypre_BigSwapb2i(HYPRE_BigInt  *v,
                     HYPRE_Int  *w,
                     HYPRE_Int  *z,
                     HYPRE_Int  i,
                     HYPRE_Int  j )
{
   HYPRE_BigInt big_temp;
   HYPRE_Int temp;

   big_temp = v[i];
   v[i] = v[j];
   v[j] = big_temp;
   temp = w[i];
   w[i] = w[j];
   w[j] = temp;
   temp = z[i];
   z[i] = z[j];
   z[j] = temp;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_BigQsortb2i( HYPRE_BigInt *v,
                       HYPRE_Int *w,
                       HYPRE_Int *z,
                       HYPRE_Int  left,
                       HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
   {
      return;
   }
   hypre_BigSwapb2i( v, w, z, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
   {
      if (v[i] < v[left])
      {
         hypre_BigSwapb2i(v, w, z, ++last, i);
      }
   }
   hypre_BigSwapb2i(v, w, z, left, last);
   hypre_BigQsortb2i(v, w, z, left, last-1);
   hypre_BigQsortb2i(v, w, z, last+1, right);
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/
void hypre_BigSwap( HYPRE_BigInt *v,
           HYPRE_Int  i,
           HYPRE_Int  j )
{
   HYPRE_BigInt temp;

   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

void hypre_BigQsort0( HYPRE_BigInt *v,
             HYPRE_Int  left,
             HYPRE_Int  right )
{
   HYPRE_Int i, last;

   if (left >= right)
      return;
   hypre_BigSwap( v, left, (left+right)/2);
   last = left;
   for (i = left+1; i <= right; i++)
      if (v[i] < v[left])
      {
         hypre_BigSwap(v, ++last, i);
      }
   hypre_BigSwap(v, left, last);
   hypre_BigQsort0(v, left, last-1);
   hypre_BigQsort0(v, last+1, right);
}

