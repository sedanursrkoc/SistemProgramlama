#include <stdio.h>

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>


typedef struct {
  int kelimeSayisi;
  char kelime[100][100];
} giris;

typedef struct {
  char *kelime;
  char *kod;
} sifreliMetin;


void girisDosyasiniOku(giris* dizi){
	int i=0;

	char line[100];
	char junk[100];
	int kelimeSayisi = 0;

	FILE *in_file = fopen("input.txt", "r");

	FILE *file = fopen("input.txt", "r");
	if(!file) {
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

sifreliDosyayiOku(){
	
}

kilitDosyasiniOKu(){

}

encrypt(){

}

decrypt(){

}


int main(int argc, char **argv){
	if (argc != 4) { fprintf(stderr, "usage: printwords filename\n"); exit(1); }
	if (argv[1] == "-e"){

		giris* dizi;
		dizi = (giris *)malloc(sizeof(giris));

		girisDosyasiniOku(dizi);
		kilitDosyasiniOKu();
	}
	else if (argv[1] == "-d"){
		sifreliDosyayiOku();
		kilitDosyasiniOKu();
	}
	else { fprintf(stderr, "Hatali parametre\n"); exit(1); }
}














