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

#include "injection.h"

int	main(void)
{
	FILE *fptr;

// Create a file
	fptr = fopen("filename.txt", "w");

// Close the file
	binary_file.write(test);
	fclose(fptr);

}
