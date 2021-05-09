#include <stdio.h>

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include "jrb.h"
#include "jval.h"


typedef struct {
  int kelimeSayisi;
  char kelime[500][500];
} giris;

typedef struct {
  char *kelime;
  char *kod;
} sifreliMetin;

typedef struct {
  int kelimeSayisi;
  int sayacKelime;
  int sayacKey;
  char kelime[500][500];
  char  key[500][500];
} kilit;

JRB b;
JRB bn;


void girisDosyasiniOku(giris* dizi){
	int i=0;

	char line[100];
	char junk[100];
	int kelimeSayisi = 0;

	FILE *in_file = fopen("/home/alpagu/Desktop/son/input.txt", "r");

	if(!in_file) {
	    printf("Could not open file. Exiting application. Bye");

	}
	while(fscanf(in_file, "%s", line) != EOF) {
	    fscanf(in_file,"%[^ \n\t\r]s",line); //Get text


	strcpy(dizi->kelime[i], line);


	i++;

	    fscanf(in_file,"%[ \n\t\r]",junk); //Remove any 'white space' characters
	}
	dizi->kelimeSayisi = i;
	i=0;
	
}

/*sifreliDosyayiOku(){
	
}*/

int kilitDosyasiniOKu(kilit* dizi){
	int sayac = 0;
	dizi->sayacKelime = 0;
	dizi->sayacKey = 0;

	char line[100];

	FILE *file = fopen("/home/alpagu/Desktop/son/.kilit", "r");
	if(!file) {
	    printf("Could not open file. Exiting application. Bye");

	}
	while(fscanf(file, "%s", line) != EOF) {
	    fscanf(file,"%[^ \n\t\r]s",line); //Get text
	    char * token = strtok(line, "\"");
	 
            if(sayac % 2 == 0 && (!strstr(line, "{") && !strstr(line, "}"))){
		strcpy(dizi->key[dizi->sayacKey], token); 
		dizi->sayacKey = dizi->sayacKey + 1;
	    }
	    else if(!strstr(line, "{") && !strstr(line, "}")){
		strcpy(dizi->kelime[dizi->sayacKelime], token); 
		dizi->sayacKelime = dizi->sayacKelime + 1;
	    }
	    else 
		// do nothing

	dizi->kelimeSayisi = sayac;
	sayac = sayac + 1;
	    
	}

	return 1;

}

void JRB_agaca_ata(kilit* dizi){
	b = make_jrb();

	for(int j =0; j < dizi->kelimeSayisi/2; j++ ){
		jrb_insert_str(b, dizi->kelime[j],new_jval_v((void *)dizi));
	}

	
}


void encrypt(giris* dizi_giris, kilit* dizi_kilit){

	FILE *file_encrypt;
	file_encrypt = fopen("encrypted", "w");
	if(file_encrypt == NULL) {
		printf("file can't be opened\n");
		exit(1);
    	}	
	jrb_traverse(bn, b) {
		dizi_kilit = (kilit *) bn->val.v;
	}
		for(int i =0; i < dizi_giris->kelimeSayisi; i++){
			for(int j =0; j < dizi_kilit->kelimeSayisi/2; j++ ){
				if(!strcmp(dizi_giris->kelime[i], dizi_kilit->kelime[j])){
					fprintf(file_encrypt, "%s ",dizi_kilit->key[j]);
					j = (dizi_kilit->kelimeSayisi/2);
				}
				else if(j == (dizi_kilit->kelimeSayisi/2) - 1){
					fprintf(file_encrypt, "%s ",dizi_giris->kelime[i]);
					j = (dizi_kilit->kelimeSayisi/2);
				}
				else{
					printf("file can't be opened\n");
					exit(1);
				}
			}
		}

	
	

	fclose(file_encrypt);

}

/*decrypt(){

}*/


int main(int argc, char **argv){
	/*if (argc != 4) { fprintf(stderr, "usage: printwords filename\n"); exit(1); }
	if (argv[1] == "-e"){

		giris* dizi;
		dizi = (giris *)malloc(sizeof(giris));

		girisDosyasiniOku(dizi);

		kilit* dizi2;
		dizi2 = (kilit *)malloc(sizeof(kilit));
		kilitDosyasiniOKu(dizi2);
	}
	else if (argv[1] == "-d"){
		//sifreliDosyayiOku();
		//kilitDosyasiniOKu();
	}
	else { fprintf(stderr, "Hatali parametre\n"); exit(1); }*/

		giris* dizi;
		dizi = (giris *)malloc(sizeof(giris));
		girisDosyasiniOku(dizi);

		kilit* dizi2;
		dizi2 = (kilit *)malloc(sizeof(kilit));
		kilitDosyasiniOKu(dizi2);
		JRB_agaca_ata(dizi2);

		encrypt(dizi, dizi2);
}














