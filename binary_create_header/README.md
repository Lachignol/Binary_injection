# Binary Injection - Génération manuelle d'un header binaire

Ce programme C permet de générer un fichier header `.h` contenant un tableau d'octets représentant un fichier binaire, à l'image de la commande système **xxd -i**.

***

## Fonctionnalité originale de `xxd -i`

La commande `xxd` est un utilitaire populaire pour générer une représentation hexadécimale d'un fichier. Avec l'option `-i`, elle produit un fichier header C déclarant un tableau statique global correspondant au contenu du fichier binaire.

**Exemple d'utilisation :**

```bash
xxd -i fichier_binaire > fichier.h
```

Ce fichier `fichier.h` contient par exemple :

```bash

unsigned char fichier_binaire[] = {
0x00, 0x01, 0x02, 0x03, /* ... */
};
unsigned int fichier_binaire_len = sizeof(fichier_binaire);

```


Cela permet d’inclure directement des données binaires dans des programmes C sans gérer des fichiers externes.

***

## Description de votre programme

Ce programme implémente cette fonctionnalité directement en C, sans dépendre de `xxd`. Il :

- Ouvre un fichier binaire spécifié en paramètre.
- Lit entièrement son contenu en mémoire.
- Génère un fichier `payload.h` contenant un tableau C statique nommé `payload` avec tous les octets du fichier.
- Ajoute une variable `payload_len` indiquant la taille.
- Formate le tableau avec 12 octets par ligne pour la lisibilité.
- Ajoute une protection classique contre inclusion multiple (`#ifndef ... #define ... #endif`).

### Avantages

- Indépendance d’une commande externe.
- Facilité de modification ou d’extension (exemple : ajout de chiffrement).

### Utilisation

```bash
./votre_programme fichier_binaire
```

Produit `payload.h` dans le répertoire courant, prêt à être inclus dans un projet C.

***

## Exemple d'extrait généré


```bash
#ifndef __PAYLOAD_H
#define __PAYLOAD_H

static unsigned char payload[] = {
0x89, 0x50, 0x4e, 0x47, /* et ainsi de suite */
};

static unsigned int payload_len = 1024;

#endif
```



Vous pouvez directement inclure ce fichier et utiliser `payload` et `payload_len` dans votre code.

***

## En résumé

Cette solution reproduit en C la génération d’un tableau binaire au format header C identique à celle de `xxd -i`. Elle vous donne le contrôle total sur la génération et permet une intégration directe en application sans dépendance à des outils externes.

***

*lachignol — 2025*
