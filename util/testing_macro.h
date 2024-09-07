#ifndef TEST_MACRO
#define TEST_MACRO

// If not condition, then failure, hence message
// Didnt want assert, failed tests needn't call abort()

#include <stdio.h>
#include <stdlib.h>

// Can double stringize but tbh do not understand it completely. Hence used printf instead of puts.
#define test(EXPECTED_CONDITION, FAILURE_MESSAGE)\
if(!(EXPECTED_CONDITION)){\
    printf("File:"__FILE__ " Line:%d " #EXPECTED_CONDITION " : " FAILURE_MESSAGE "\n", __LINE__);\
    exit(-1);\
}

#endif