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

/* Global Variables */
  unsigned char Minimun = 0;
  unsigned char Maximun = 0;
  unsigned int  Mean    = 0;
  unsigned int Median  = 0;
  unsigned char *SortedArray = 0;



void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Statistics and Printing Functions Go Here */
  printf("\nThe elements that contain this array are:");
  print_array(test, SIZE);
  SortedArray = sort_array(test, SIZE);
  Minimun = find_minimum( SortedArray, SIZE);
  Maximun = find_maximum(SortedArray, SIZE);
  Mean = find_mean(SortedArray, SIZE);
  Median = find_median(SortedArray, SIZE);

  printf("\nSORTED ARRAY:");
  print_array(test, SIZE);
  print_statistics();


}


/* Name:        print_statistics()
 * Description: A function that prints the statistics of an array including minimum, maximum, mean, and median.
 */
void print_statistics( void )
{
  printf ("Statistics:\n");
  printf ("Minimun Value: %d\n", Minimun);
  printf ("Maximun Value: %d\n", Maximun);
  printf ("Mean Value: %d\n", Mean);
  printf ("Median Value: %d\n", Median);
}

/* Name:        print_array()
 * Description: Given an array of data and a length, prints the array to the screen.
 */
void print_array(unsigned char Array[], unsigned char length)
{
  int i;
  for(i = 0; i < SIZE; i++)
  {
    if (!(i%8))			        // If the remainder is cero
    {
      printf("\n");			// Print a Line Break
    } 	
    printf("%d\t", Array[i]);		// Print a Array [i]
  }
  printf("\n");				// Print a Line Break
}

/* Name:        find_median()
 * Description: Given an array of data and a length, returns the median value.
 */
unsigned char find_median(unsigned char Array[], unsigned char length)
{
  unsigned int MedianValue;

  // Get the Mean Value
  MedianValue = Array[length/2];

  return MedianValue;
}


/* Name:        find_mean()
 * Description: Given an array of data and a length, returns the mean.
 */
unsigned char find_mean(unsigned char Array[], unsigned char length)
{
  int Temp;
  short Sum;
  int MeanValue;
   // Calculing the sum
  for ( int i = 0; i < length; i++ ) {
    Temp =  Array[i];
    Sum += Temp;
  }

  // Calculate the Mean Value
  MeanValue = Sum ;

 return MeanValue;
}

/* Name:        find_maximum()
 * Description: Given an array of data and a length, returns the maximum.
 */
unsigned char find_maximum(unsigned char Array[], unsigned char length)
{
 //Assume that the array is sorted from largest to smallest.
 return Array[0];
}

/* Name:        find_minimum()
 * Description: Given an array of data and a length, returns the minimum.
 */
unsigned char find_minimum(unsigned char Array[], unsigned char length)
{
//Assume that the array is sorted from largest to smallest.
 return Array[length - 1];
}

/* Name:        sort_array()
 * Description: Given an array of data and a length, sorts the array from largest to smallest. 
 *              (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.)
 */
unsigned char *sort_array(unsigned char Array[], unsigned char length)
{

  int Temp;

 for (int i = 0; i < SIZE; i++) 
  { 
    for (int j = 0; j < (SIZE-1); j++) 
    { 
      if (Array[j] < Array[j+1]) 
      { 
        Temp = Array[j]; 
        Array[j] = Array[j+1]; 
        Array[j+1] = Temp; 
      } 
    } 
  } 

 return Array;
}

