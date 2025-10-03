/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_print_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:14:02 by ascordil          #+#    #+#             */
/*   Updated: 2025/09/02 11:28:51 by ascordil         ###   ########.fr       */
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

int main(int count, char **argv) {

  FILE *fd;
  unsigned char *buf;
  long long size_of_payload;
  long long read_size;

  (void)buf;
  if (count == 2) {

    fd = fopen(argv[1], "rb");
    if (fd == NULL) {
      perror("Probleme lors de l'ouverture du fichier");
      return (1);
    }
    // Je positione le curseur a la fin ( le 0 indique le caractere a partir de
    // la fin dans le cas present SEEk_END ex: -7 ==> je serai au 7 eme
    // char avant la fin )
    fseek(fd, 0, SEEK_END);
    // Je recupere la position du curseur du coup la length
    size_of_payload = ftell(fd);
    printf("%lld\n", size_of_payload);
    // Je retabli le curseur au debut du fichier je pourrai aussi faire
    // fseek(fp, 0, SEEK_SET);
    rewind(fd);
    buf = malloc(sizeof(char) * (size_of_payload));
    read_size = fread(buf, 1, size_of_payload, fd);
    fclose(fd);
    if (read_size != size_of_payload) {
      perror("Probleme lors de la lecture\n");
      return (1);
    }

    // Print sous le format d'un header en c afin de copier coller'
    printf("#ifndef __PAYLOAD_H\n");
    printf("#define __PAYLOAD_H\n");
    printf("unsigned char payload[] = {\n");
    for (int i = 0; i < size_of_payload; i++) {
      printf("0x%02x", buf[i]);
      if (i < size_of_payload - 1)
        printf(", ");
      if ((i + 1) % 12 == 0 && i != size_of_payload - 1)
        printf("\n   ");
    }
    printf("};\n\n");
    printf("unsigned int payload_len = %lld;\n\n", size_of_payload);
    printf("#endif\n");

    return (0);
  } else
    printf("Format: %s <path of file to transform in header>\n", argv[0]);
  return (1);
}
