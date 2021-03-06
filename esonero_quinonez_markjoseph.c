#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include<time.h>
 char plainText[128],key[128],cipherText[128];
 void case1();
 void case2();

 void case1(){
   printf("|Hai scelto di scrivere la chiave!|\n");
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
 }
 void case2(){
   printf("\n");
   printf("Hai scelto la modalità casuale!\n");
   time_t t ;
   srand((unsigned) time(&t));

   //creo la chiave casuale lunga 128 e la stampo in esadecimale
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
 }


 int main(){
   printf("|RC4|\n");
   //utente inserisce un testo in chiaro (plainText)
   printf("|Inserisci plain Text:|\n");
  //questo comando legge la stringa scritta dall'uente
   fgets(plainText, 128, stdin);
   //variabile di controllo, se l'utente preme '1' o '2' o '3'
   int variabile;
   do{
     //Menu dove l'utente può scegliere l'opzione desiderata
     printf("|Scegli come vuoi criptare il messaggio|\n");
     printf("|1|\t DIGITA UNA CHIAVE\n");
     printf("|2|\t CHIAVE CASUALE\n");
     printf("|3|\t ESCI\n");
     scanf("%d",&variabile);

     switch(variabile){
       //chiave scritta dall'utente
        case 1 :
        case1();
        break;

      //chiave scritta casuale
        case 2 :
        case2();
        break;

        case 3: break; //annulla

        default : //Messaggio di errore
        printf("Opzione non riconosciuta. RIPROVA!\n");
      }
   } while(variabile<1 || variabile>3);

}
