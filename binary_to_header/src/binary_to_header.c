/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_to_header.c                                 :+:      :+:    :+:   */
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
  char buf[1024];

  if (count > 1) {

    fd = fopen(argv[1], O_RDONLY);
    if (fd == NULL) {
      perror("Probleme lors de l'ouverture du fichier");
      return (1);
    }
    fseek(fd, 0, SEEK_END);
    while (fread(buf, 1, 1, fd) > 0) {
      for (int i = 0; i < 8; i++)
        printf("%.02x ", buf[i]);
      printf("\n");
    }

    fclose(fd);
    return (0);
  }
  printf("Format: %s <path of file to transform in header>\n", argv[0]);
  return (1);
}
