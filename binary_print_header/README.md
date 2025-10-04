# binary_print_header

Ce programme C affiche le contenu d’un fichier binaire sous forme d’un fichier header C (.h), prêt à être copié-collé dans un projet.

---

## Description

Le programme lit un fichier binaire passé en argument, puis :

- Calcule la taille du fichier
- Lit entièrement le contenu en mémoire
- Affiche un format de header C avec :
  - Un tableau statique nommé `payload` contenant tous les octets en hexadécimal
  - Une variable `payload_len` indiquant la taille du tableau
  - Une protection classique contre inclusion multiple (`#ifndef`, `#define`, `#endif`)

Ce format est compatible avec ce que produit `xxd -i`.

---

## Utilisation

Compiler le programme :

- Rendez-vous dans le répertoire:

``` bash
cd binary_print_header
```
- Puis compilez avec `make` :

``` bash
make
```



Exécuter le programme avec un fichier binaire :

```bash
./binary_print_header mon_fichier_binaire
```



Le programme affiche sur la sortie standard le contenu formaté en header C.

---

## Exemple de sortie


```bash
#ifndef __PAYLOAD_H
#define __PAYLOAD_H

static unsigned char payload[] = {
0x89, 0x50, 0x4e, 0x47, /* etc. */
};

static const unsigned int payload_len = 1024;

#endif
```
---

## Note

Veillez à rediriger la sortie vers un fichier si vous souhaitez sauvegarder ce header :


```bash
./binary_print_header mon_fichier > payload.h
```
---

lachignol — 2025


