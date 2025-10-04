/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_crypted_header.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:14:02 by ascordil          #+#    #+#             */
/*   Updated: 2025/10/04 00:15:00 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>

static int crypt_xor(unsigned char *payload, long long size_pload, char *key) {

  int key_len = strlen(key);

  for (int i = 0; i < size_pload; i++) {
    payload[i] ^= key[i % key_len];
  }
  return (1);
}

int main(int count, char **argv) {

  FILE *fd;
  FILE *out;
  unsigned char *buf;
  long long size_of_payload;
  long long read_size;

  if (count == 3) {

    fd = fopen(argv[1], "rb");
    if (fd == NULL) {
      perror("Probleme lors de l'ouverture du fichier d'entree");
      return (1);
    }

    fseek(fd, 0, SEEK_END);
    size_of_payload = ftell(fd);
    rewind(fd);

    buf = malloc(sizeof(char) * (size_of_payload + 1));
    if (!buf) {
      perror("Erreur d'allocation memoire");
      fclose(fd);
      return (1);
    }

    read_size = fread(buf, 1, size_of_payload, fd);
    fclose(fd);
    if (read_size != size_of_payload) {
      perror("Probleme lors de la lecture du fichier");
      free(buf);
      return (1);
    }
    buf[size_of_payload] = '\0';
    out = fopen("payload.h", "w");
    if (out == NULL) {
      perror("Impossible de creer le fichier payload.h");
      free(buf);
      return (1);
    }
    printf("Encryption en cours\n");
    crypt_xor(buf, size_of_payload, argv[2]);
    printf("Encryption ok\n");
    fprintf(out, "#ifndef __PAYLOAD_H\n");
    fprintf(out, "#define __PAYLOAD_H\n\n");
    fprintf(out, "static unsigned char payload[] = {\n   ");

    for (int i = 0; i < size_of_payload; i++) {
      fprintf(out, "0x%02x", buf[i]);
      if (i < size_of_payload - 1)
        fprintf(out, ", ");
      if ((i + 1) % 12 == 0 && i != size_of_payload - 1)
        fprintf(out, "\n   ");
    }

    fprintf(out, "\n};\n\n");
    fprintf(out, "static const unsigned int payload_len = %lld;\n\n",
            size_of_payload);
    fprintf(out, "#endif\n");

    fclose(out);
    free(buf);

    printf("Le fichier payload.h a été généré avec succès.\n");
    return (0);
  } else {
    printf("Format: %s <path of binary to encrypt and transform in header> "
           "<key for encryption>\n",
           argv[0]);
    return (1);
  }
}
