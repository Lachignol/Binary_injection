# Binary Crypted Header -  Création du header avec binaire chiffré

### Description

Ce programme lit un fichier binaire (ex : un exécutable), chiffre son contenu avec un chiffrement XOR simple à clé répétée, puis génère un fichier `payload.h` (comme xxd -i mais avec le chiffrement en plus).


Ce fichier header contient :

- Un tableau statique `unsigned char payload[]` contenant les octets du binaire chiffré.
- La taille originale du payload.

### Utilisation

``` bash
./binary_crypted_header <chemin_du_binaire> <cle_de_chiffrement>

```


### Exemple

``` bash
./binary_crypted_header mon_programme.bin ma_cle_secrete

```


Ce qui génère un fichier `payload.h` à inclure dans votre projet C.


## Détails techniques
- Le chiffrement/déchiffrement utilise un XOR avec une clé répétée.

## Prérequis

- Compilateur C compatible (ex : gcc)
- Système UNIX/Linux.

---
## Compilation exemple

- Rendez-vous dans le répertoire:

``` bash
cd binary_crypted_header
```
- Puis compilez avec `make` :

``` bash
make
```
---
