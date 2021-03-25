/**
 * @file main.c
 * @author your name Pietro Queiroz
 * @brief 
 * @version 0.1
 * @date 2021-03-25
 * 
 * @license GBL General Buzz License
 * 
 */
/**
 * Fiz essa merda enquanto nao tinha nada pra fazer, se divirta (se souber C tenta fazer um sistema de save) 
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sleep.h"
#if __WIN32
    #define c "cls"
#else
    #define c "clear"
#endif  
#define PRICE_PER_COOKIE 5
#define COOKIE_PRODUCT_COST 2
#define COOKIE_PRODUCT_TIME 500 // miliseconds
int fazerbiscoito();
int biscoitos = 5;
int dinheiros = 10;
int menu(){
    int choose;
    printf("**********************\n1. Fazer Biscoitos.\n2. Vender Biscoitos\n**********************\n");
    printf("Escolha a opcao: ");
    scanf("%d", &choose);
    return choose;

}
int main(){

    while(1){
        system(c);
        printf("Dinheiros: R$: %d\nBiscoitos: %d\n\n\n", dinheiros, biscoitos);
        int option = menu();
        srand(time(NULL)); // ja vai entender
        if(option == 1){
            if(dinheiros < COOKIE_PRODUCT_COST){
                printf("Voce precisa de mais dinheiro para fazer cookies!");
            }else{
                const int maxCookies = dinheiros / COOKIE_PRODUCT_COST;
                printf("Quantos biscoitos voce quer fazer? Maximo de %d\n", maxCookies);
                int biscoitosParaFazer;
                scanf("%d", &biscoitosParaFazer);
                if(biscoitosParaFazer > maxCookies){
                    printf("Voce não tem dinheiro para fazer tantos cookies! venda seus cookies para ganhar mais dinheiros!\n(digite qualquer tecla para continuar: )");
                    
                }else{
                    int totalCost = biscoitosParaFazer * COOKIE_PRODUCT_COST;
                    dinheiros = dinheiros - totalCost;
                    for(int i = 0; i < biscoitosParaFazer; i++){
                        printf("\r fazendo biscoitos: %d / %d\n", i, biscoitosParaFazer);
                        printf("preparando biscoito\n");
                        sleep(1);
                        printf("cozinhando massa\n");
                        sleep(COOKIE_PRODUCT_COST * 2);
                        printf("Adicionando chocolatos\n");
                        sleep(1);
                        biscoitos = biscoitos +1;
                        system(c);

                        printf("Dinheiros: R$: %d\nBiscoitos: %d\n\n\n", dinheiros, biscoitos);

                    }
                }
         }

        }
        if(option == 2){
            
            int quantosVender;
            int vendidos;

            printf("Quantos cookies voce quer vender? ");
            scanf("%d", &quantosVender);
            if(quantosVender <= 0){
                printf("Coloque um numero maior que 1\n(digite qualquer tecla para continuar: )");
                    int *v;
                    char back;
                    v = malloc(sizeof(back));
                    scanf("%s", &back);
                    free(v);
            }else{
                vendidos = 0;
                 do{
                     system(c);
                    

                     srand(time(NULL));
                     int timer = rand() % 10 + 1;
                     int vender = rand() % 3;
                     if(vender < 2){
                         printf("Uma pessoa apareceu, mas não comprou!\n");
                     }else{
                         
                         srand(time(NULL));
                         int cookiesLevados = rand() % (quantosVender - vendidos) + 1;
                         dinheiros = dinheiros + (cookiesLevados * PRICE_PER_COOKIE);
                         printf("Uma pessoa apareceu e levou %d biscoito(s) OOOOOO\n", cookiesLevados);
                        biscoitos = biscoitos - cookiesLevados;
                        vendidos = vendidos + cookiesLevados;
                        
                        
                     }
                     printf("Dinheiros: R$: %d\nBiscoitos: %d\n\n\n", dinheiros, biscoitos);
                     sleep(timer);
                }while(vendidos < quantosVender);

            }
           
        }
    }
}