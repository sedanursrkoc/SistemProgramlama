#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jrb.h"
#include "jval.h"

typedef struct {
  int kelimeSayisi;
  char kelime[500][500];
  char line[100];
} giris;

typedef struct {
  int kelimeSayisi;
  int sayacKelime;
  int sayacKey;
  char kelime[500][500];
  char  key[500][500];
  char line[100];
} kilit;

JRB b;
JRB bn;

void girisDosyasiniOku(giris*, char *);
void kilitDosyasiniOKu(kilit*);
void encrypt(giris*, kilit*, char *);
void decrypt(giris*, kilit*, char *, char *);

#endif
