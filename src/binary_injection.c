/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_injection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:14:02 by ascordil          #+#    #+#             */
/*   Updated: 2025/09/02 11:28:51 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/injection.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main(int count, char **argv) {

  (void)count;
  char fileName[] = "/tmp/fileXXXXXX";
  size_t writeBytes;
  int fd = mkstemp(fileName);
  if (fd == -1) {
    perror("Erreur lors de la creation du fichier temporaire");
    return 1;
  }

  chmod(fileName, 0700);
  writeBytes = write(fd, binary_injection, binary_injection_len);
  if (writeBytes != binary_injection_len) {
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
  // faire un fork
  execv(fileName, argv);

  perror("execv");
  unlink(fileName);
  return 1;
}
