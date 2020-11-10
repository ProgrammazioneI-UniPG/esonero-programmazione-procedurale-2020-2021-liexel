#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include<time.h>
 int main(){
   //utente inserisce un testo in chiaro (plainText)
 printf("|RC4|\n");
 printf("|Inserisci plain Text:|\n");
 char plainText[128];
 fgets(plainText, 128, stdin);//fgets(plainText, sizeof(plainText), stdin); //questo comando legge la stringa scritta dall'uente

 //chiave scritta dall'utente [case 1]
 char key[128];
 char cipherText[128];

 int variabile; //variabile di controllo, se l'utente preme '1' o '2'
 //Menu dove l'utente può scegliere l'opzione desiderata
 printf("|Scegli come vuoi criptare il messaggio|\n");
 printf("|1|\t DIGITA UNA CHIAVE\n");
 printf("|2|\t CHIAVE CASUALE\n");
 printf("|3|\t ESCI\n");
 scanf("%d",&variabile);

  switch(variabile){

    case 1 : //chiave scritta dall'utente
    printf("|Hai scelto di scrivere la chiave!|\n");
    //char plainText[128], cipherText[128], key[128];
    printf("|Inserisci key:|\n");
    scanf("%s", key);

    printf("\n");
    printf("|CIPHERTEXT CIFRATA E SCRITTA IN ESADECIMALE|\n");
    //XOR
    for(int i=0; i<strlen(plainText);i++){
      cipherText[i]=plainText[i]^key[i];
      printf("%x", cipherText[i]);
    }
    printf("\n");

    printf("\n");
    printf("|PLAINTEXT DECIFRATA|\n");
    for(int i=0; i<strlen(plainText);i++){
      plainText[i]=cipherText[i]^key[i];
      printf("%c", plainText[i]);
    }
    break;

    case 2 : //chiave scritta casuale
    printf("\n");
    printf("Hai scelto la modalità casuale!\n");
    time_t t ;
    srand((unsigned) time(&t));
    //creomla chiave casuale lunga 128 e la stampo in esadecimale
    printf("|CHIAVE CASUALE SCRITTA IN ESADECIMALE|\n");
    for(int i=0; i<strlen(plainText);i++){
      key[i]=rand()%128;
      printf("%x", key[i]);
    }
    printf("\n");
    //XOR
    printf("\n");
    printf("|CIPHERTEXT CIFRATA SCRITTA IN ESADECIMALE|\n");
    for(int i=0; i<strlen(plainText);i++){
      cipherText[i]=plainText[i]^key[i];
      printf("%x", cipherText[i]);
    }
    printf("\n");

    printf("\n");
    printf("|PLAINTEXT DECIFRATA|\n");
    for(int i=0; i<strlen(plainText);i++){
      plainText[i]=cipherText[i]^key[i];
      printf("%c", plainText[i]);
    }
    break;

    case 3: break; //annulla

    default : //Messaggio di errore
    printf("Opzione non riconosciuta.");
    }

}
