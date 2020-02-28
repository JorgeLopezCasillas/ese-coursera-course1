/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Implementation of functions>
 *
 * Functions:
 * <maximum, minimum, mean, and median of the data set>
 *
 * @author <JORGE LOPEZ>
 * @date <01-02-2020 >
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main(int argc, char *argv[]) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char u8Minimun = 0;
  unsigned char u8Maximun = 0;
  unsigned char u8Mean    = 0;
  unsigned char u8Median  = 0;
  unsigned char *u8SortedArray = 0;
  /* Statistics and Printing Functions Go Here */
  printf("Hola Mundo\n");
  
  u8Minimun = find_minimum( test, SIZE);
  //u8Mean = find_mean(test, SIZE);
  //u8Median = find_median(test, SIZE);
  //u8Maximun = find_maximum(test, SIZE);
  u8SortedArray = sort_array(test, SIZE);

  print_array(test, SIZE);
  //print_statistics();

  return 0;
}


/* Name:        print_statistics()
 * Callsby:     main()
 * Calls:       None
 * Description: A function that prints the statistics of an array including minimum, maximum, mean, and median.
 */
void print_statistics( void )
{
  //printf ("Minimun Value: %d", u8Minimun);
  //printf ("Maximun Value: %d", u8Maximun);
  //printf ("Mean Value: %d", u8Mean);
  //printf ("Median Value: %d", u8Median);
}

/* Name:        print_array()
 * Callsby:     main()
 * Calls:       None
 * Param:       u8Array[], u8length
 * Description: Given an array of data and a length, prints the array to the screen.
 */
void print_array(unsigned char u8Array[], unsigned char u8length)
{
  int i;

  printf("The elements that contain this array are:\n");
  for(i = 0; i < SIZE; i++)
  {
    printf("%d\t", u8Array[i]);
  }
}

/* Name:        find_median()
 * Callsby:     main()
 * Calls:       None
 * Param:       u8Array[], u8length
 * Description: Given an array of data and a length, returns the median value.
 */
unsigned char find_median(unsigned char u8Array[], unsigned char u8length)
{

 return 0;
}


/* Name:        find_mean()
 * Callsby:     main()
 * Calls:       None
 * Param:       u8Array[], u8length
 * Description: Given an array of data and a length, returns the mean.
 */
unsigned char find_mean(unsigned char u8Array[], unsigned char u8length)
{

 return 0;
}

/* Name:        find_maximum()
 * Callsby:     main()
 * Calls:       None
 * Param:       u8Array[], u8length
 * Description: Given an array of data and a length, returns the maximum.
 */
unsigned char find_maximum(unsigned char u8Array[], unsigned char u8length)
{

 return 0;
}

/* Name:        find_minimum()
 * Callsby:     main()
 * Calls:       None
 * Param:       u8Array[], u8length
 * Description: Given an array of data and a length, returns the minimum.
 */
unsigned char find_minimum(unsigned char u8Array[], unsigned char u8length)
{

 return 0;
}

/* Name:        sort_array()
 * Callsby:     main()
 * Calls:       None
 * Param:       u8Array[], u8length
 * Description: Given an array of data and a length, sorts the array from largest to smallest. 
 *              (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.)
 */
unsigned char *sort_array(unsigned char u8Array[], unsigned char u8length)
{
  int i;
  int j;
  int Temp;

 for (i = 0; i < (SIZE - 1); i++) 
  { 
    for (j = i + 1; j < SIZE; j++) 
    { 
      if (u8Array[j] < u8Array[i]) 
      { 
        Temp = u8Array[j]; 
        u8Array[j] = u8Array[i]; 
        u8Array[i] = Temp; 
      } 
    } 
  } 

 return u8Array;
}

