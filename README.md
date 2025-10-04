# Binary Injection - Outils de chiffrement et d'exécution de payload binaire

Ce dépôt contient deux programmes C permettant de :

- **Crypter un fichier binaire en un fichier header C (.h)** contenant le binaire chiffré sous forme d’un tableau d’octets.
- **Déchiffrer ce fichier header pour recréer le binaire en mémoire**, l’écrire dans un fichier temporaire exécutable, puis l’exécuter.

---

## Programme 1 : Création du header avec binaire chiffré

### Description

Ce programme lit un fichier binaire (ex : un exécutable), chiffre son contenu avec un chiffrement XOR simple à clé répétée, puis génère un fichier `payload.h`.

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

---

## Programme 2 : Déchiffrement et exécution du payload

### Description

Ce programme inclut le `payload.h`, déchiffre le tableau d’octets en appliquant la même clé XOR, crée un fichier temporaire exécutable, écrit le binaire déchiffré dedans, puis exécute ce fichier.

Le fichier temporaire est ensuite supprimé automatiquement après exécution.

### Utilisation

``` bash
./binary_crypted_injection <arguments_exécutables> <cle_de_chiffrement>

```


- `<arguments_exécutables>` : arguments à passer au binaire exécuté.
- `<cle_de_chiffrement>` : la même clé utilisée au chiffrement.

### Exemple


``` bash
./binary_crypted_injection arg1 arg2 ma_cle_secrete

```


---

## Détails techniques

- Le chiffrement/déchiffrement utilise un XOR avec une clé répétée.
- Utilisation de fonctions systèmes sécurisées `mkstemp`, `chmod`, `fork`, `execv` pour manipuler le binaire temporaire.
- Suppression propre du fichier temporaire avec `unlink` après exécution.
- Gestion d’erreurs robuste lors de la lecture, écriture, exécution et permissions.

---

## Prérequis

- Compilateur C compatible (ex : gcc)
- Système UNIX/Linux pour gestion des fichiers temporaires et exécution système.

---
## Compilation exemple

- Rendez-vous dans le répertoire du programme souhaité :

``` bash
cd binary_crypted_injection
```
- Puis compilez avec `make` :

``` bash
make
```


