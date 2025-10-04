# Binary Injection - Exécution sécurisée d’un payload binaire depuis un header C

Ce programme C permet d’exécuter un payload binaire intégré dans un header C (`payload.h`) en créant un fichier temporaire exécutable.

---

## Description

Le programme réalise les étapes suivantes :

- Inclut un fichier header (`payload.h`) généré précédemment, qui contient un tableau d’octets statique `payload` et sa taille `payload_len`.
- Crée un fichier temporaire dans `/tmp` avec un nom unique sécurisé (`mkstemp`).
- Écrit le contenu complet du binaire stocké dans le tableau `payload` dans ce fichier temporaire.
- Modifie les permissions du fichier pour le rendre exécutable (`chmod 0700`).
- Lance un processus enfant avec `fork()`.
- Dans le processus enfant, exécute le fichier temporaire avec `execv()`, en passant les arguments du programme principal.
- Le processus parent attend la fin du processus enfant, puis supprime le fichier temporaire (`unlink`).
- Affiche des messages d’état pour informer l’utilisateur.

---

## Utilisation

Compiler le programme :

- Rendez-vous dans le répertoire:

``` bash
cd binary_injection
```
- Puis compilez avec `make` :

``` bash
make
```

Exécuter le programme (en supposant que `payload.h` est inclus correctement) :


``` bash
./binary_injection <arguments_du_payload> ...
```
---

## Fonctionnement interne

- Le fichier temporaire permet d’exécuter un binaire généré « à la volée » depuis la mémoire, ce qui évite de stocker un binaire non chiffré ou sensible de façon permanente sur le disque.
- L’utilisation de `mkstemp` garantit la création d’un fichier unique et sécurisé.
- `chmod` permet d’assurer que le fichier est exécutable uniquement par l’utilisateur actuel.
- `fork` + `execv` permet d’exécuter le payload dans un processus enfant tout en gardant le contrôle dans le processus parent.
- La suppression à la fin évite de laisser des traces persistantes.

---

## Points importants

- Assurez-vous que le header `payload.h` inclus contient bien les données binaires valides.
- Le programme ne fait pas de déchiffrement, il sert uniquement à exécuter un payload déjà prêt.
- Ce modèle est idéal pour des scénarios d’injection binaire sécurisée ou d’exécution temporaire de codes compilés dynamiques.

---

*lachignol — 2025*
