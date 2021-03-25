#include <time.h>
#include <stdio.h>

void sleep(int seconds){
    long start = time(NULL);
    while(time(NULL) < start + seconds) continue;
}
void sleepf(int miliseconds){
    long start = time(NULL);
    
    while(time(NULL) < start + (miliseconds / 1000)) continue;
}