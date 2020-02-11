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
 * @file <stats.h> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <JORGE LOPEZ>
 * @date <10-02-20020>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


/* Name:        print_statistics()
 * Callsby:     main()
 * Calls:       None
 * Return:      None
 * Description: A function that prints the statistics of an array including minimum, maximum, mean, and median.
 */
extern void print_statistics()


/* Name:        print_array()
 * Callsby:     main()
 * Calls:       None
 * Return:      None
 * Description: Given an array of data and a length, prints the array to the screen.
 */
extern void print_array(uint8_t u8Array[], uint8_t u8Length);


/* Name:        find_median()
 * Callsby:     main()
 * Calls:       None
 * Return:      u8MedianValue
 * Description: Given an array of data and a length, returns the median value.
 */
extern unsigned char find_median(uint8_t u8Array[], uint8_t u8Length);


/* Name:        find_mean()
 * Callsby:     main()
 * Calls:       None
 * Return:      u8meanValue
 * Description: GGiven an array of data and a length, returns the mean.
 */
extern unsigned char find_mean(uint8_t u8Array[], uint8_t u8Length);


/* Name:        find_maximum()
 * Callsby:     main()
 * Calls:       None
 * Return:      u8MaximumValue
 * Description: Given an array of data and a length, returns the maximum.
 */
extern unsigned char find_maximum(uint8_t u8Array[], uint8_t u8Length);


/* Name:        find_minimum()
 * Callsby:     main()
 * Calls:       None
 * Return:      u8minimunValue
 * Description: Given an array of data and a length, returns the minimum.
 */
extern unsigned char find_minimum(uint8_t u8Array[], uint8_t u8Length);


/* Name:        sort_array()
 * Callsby:     main()
 * Calls:       None
 * Return:      u8Array[]
 * Description: Given an array of data and a length, sorts the array from largest to smallest. 
 *              (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.)
 */
extern unsigned char sort_array(uint8_t u8Array[], uint8_t u8Length);



#endif /* __STATS_H__ */
