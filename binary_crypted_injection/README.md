# Binary_injection


## Génération d'un fichier header C avec un tableau d'octets à l'aide de `xxd`

Pour inclure dans un programme C un tableau d'octets représentant un fichier binaire, la commande `xxd` avec l'option `-i` permet de générer automatiquement un fichier header au format C.

### Commande


```bash
xxd -i fichier_binaire > fichier.h
```


Cette commande transforme le contenu `fichier_binaire` en un tableau C statique dans `fichier.h`.

### Exemple de sortie générée
```bash
unsigned char fichier_binaire[] = {
0x00, 0x01, 0x02, 0x03, /* etc. */
};
unsigned int fichier_binaire_len = sizeof(fichier_binaire);
```


### Utilisation dans le code C

Il suffit d'inclure le header généré dans vos fichiers C :
```bash
#include "fichier.h"

// Utilisation de fichier_binaire et fichier_binaire_len
```

Le tableau est initialisé en lecture seule et peut être utilisé directement comme un tableau classique d'octets (`unsigned char`).

---

Cette méthode est simple et efficace pour intégrer du contenu binaire directement dans le code source C sans avoir à gérer des fichiers externes à l'exécution.
