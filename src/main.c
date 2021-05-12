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


void girisDosyasiniOku(giris* dizi, char * dosya_adi){
	int i=0;

	char line[100];
	char junk[100];
	int kelimeSayisi = 0;

	FILE *in_file = fopen(dosya_adi, "r");

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

int kilitDosyasiniOKu(kilit* dizi){
	int sayac = 0;
	dizi->sayacKelime = 0;
	dizi->sayacKey = 0;

	char line[100];

	FILE *file = fopen(".kilit", "r");
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


void encrypt(giris* dizi_giris, kilit* dizi_kilit, char * dosya_adi_cikis){

	FILE *file_encrypt;
	file_encrypt = fopen(dosya_adi_cikis, "w");

	b = make_jrb();

	for(int j =0; j < dizi_kilit->kelimeSayisi/2; j++ ){
		jrb_insert_str(b, dizi_kilit->kelime[j],new_jval_v((void *)dizi_kilit));
	}

	if(file_encrypt == NULL) {
		printf("file can't be opened\n");
		exit(1);
    	}	
	jrb_traverse(bn, b) {
		dizi_kilit = (kilit *) bn->val.v;
	}
		for(int i =0; i < dizi_giris->kelimeSayisi; i++){
			bn = jrb_find_str(b, dizi_giris->kelime[i]);
			if (bn == NULL) {
				fprintf(file_encrypt, "%s ",dizi_giris->kelime[i]);
			} 
			else {
				for(int j =0; j < dizi_kilit->kelimeSayisi/2; j++ ){
					if(!strcmp(dizi_giris->kelime[i], dizi_kilit->kelime[j])){
						fprintf(file_encrypt, "%s ",dizi_kilit->key[j]);
					}
				}
			}
			
		}

	
	
	jrb_free_tree(b);
	fclose(file_encrypt);

}

void decrypt(giris* dizi_giris, kilit* dizi_kilit, char * dosya_adi_giris, char * dosya_adi_cikis){
	


	char line[100];
	FILE *file_decrypt;
	file_decrypt = fopen(dosya_adi_cikis, "w");

	b = make_jrb();

	for(int j =0; j < dizi_kilit->kelimeSayisi/2; j++ ){
		jrb_insert_str(b, dizi_kilit->key[j],new_jval_v((void *)dizi_kilit));
	}

	if(file_decrypt == NULL) {
		printf("file can't be opened\n");
		exit(1);
    	}	
	jrb_traverse(bn, b) {
		dizi_kilit = (kilit *) bn->val.v;
		
	}

	FILE *in_file = fopen(dosya_adi_giris, "r");

	if(!in_file) {
	    printf("Could not open file. Exiting application. Bye");

	}
	while(fscanf(in_file, "%s", line) != EOF) {

		bn = jrb_find_str(b, line);
		if (bn == NULL) {
			fprintf(file_decrypt, "%s ",line);
		} 
		else {
			for(int i =0; i < dizi_kilit->kelimeSayisi/2; i++ ){
				if(!strcmp(dizi_kilit->key[i], line)){
					fprintf(file_decrypt, "%s ",dizi_kilit->kelime[i]);
				}
			}
		}


	}


	fclose(file_decrypt);

}


int main(int argc, char **argv){

	giris* dizi;
	dizi = (giris *)malloc(sizeof(giris));

	kilit* dizi2;
	dizi2 = (kilit *)malloc(sizeof(kilit));

	if (argc != 4) { fprintf(stderr, "usage: printwords filename\n"); exit(1); }
	if (!strcmp(argv[1],"-e")){	
		girisDosyasiniOku(dizi, argv[2]);
		kilitDosyasiniOKu(dizi2);
		encrypt(dizi, dizi2, argv[3]);
	}
	else if (!strcmp(argv[1],"-d")){
		girisDosyasiniOku(dizi, argv[2]);
		kilitDosyasiniOKu(dizi2);
		decrypt(dizi, dizi2, argv[2], argv[3]);
	}
	else { fprintf(stderr, "Hatali parametre\n"); exit(1); }

		
		
		
}














