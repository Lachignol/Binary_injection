# Binary Crypted Injection -  Déchiffrement et exécution du payload

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


