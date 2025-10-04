/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_crypted_injection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:14:02 by ascordil          #+#    #+#             */
/*   Updated: 2025/09/02 11:28:51 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/payload.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>

static int decrypt_xor(unsigned char *payload, long long size_pload,
                       char *key) {

  int key_len = strlen(key);

  for (int i = 0; i < size_pload; i++) {
    payload[i] ^= key[i % key_len];
  }
  return (1);
}

int main(int count, char **argv) {

  if (count >= 3) {
    if (strlen(argv[count - 1]) == 0) {
      fprintf(stderr, "La clé de déchiffrement ne peut pas être vide.\n");
      return 1;
    }
    char *new_argv[count - 1];
    char fileName[] = "/tmp/fileXXXXXX";
    size_t writeBytes;
    int fd = mkstemp(fileName);
    if (fd == -1) {
      perror("Erreur lors de la creation du fichier temporaire");
      return 1;
    }
    decrypt_xor(payload, payload_len, argv[count - 1]);
    writeBytes = write(fd, payload, payload_len);
    if (writeBytes != payload_len) {
      perror("write");
      close(fd);
      unlink(fileName);
      return 1;
    }
    close(fd);
    if (chmod(fileName, 0700) == -1) {
      perror("chmod");
      unlink(fileName);
      return 1;
    }
    int pid = fork();
    if (pid < 0) {
      perror("Probleme lors du fork");
      return (1);
    }
    if (pid == 0) {
      new_argv[0] = fileName;
      for (int i = 1; i < count - 1; i++) {
        new_argv[i] = argv[i];
      }
      new_argv[count - 1] = NULL;
      printf("Execution de ma payload:\n");
      execv(fileName, new_argv);
      perror("execv");
      return 1;
    } else {
      wait(&pid);
      unlink(fileName);
      printf("\nRetour dans mon programme principal\n");
      return (0);
    }
  } else {
    printf("./binary_crypted_injection <arguments_exécutables> "
           "<cle_de_chiffrement>\n");
  }
}
