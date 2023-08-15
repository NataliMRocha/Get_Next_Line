if (nb_read < BUFFER_SIZE)
	{
		buffer_nb_read = (char *)malloc((nb_read + 1) * sizeof(char));
		if (!buffer_nb_read)
		{
			free(buffer);
			return (malloc(0));
		}
		i = -1;
		while (i++ < (nb_read + 1))
			buffer_nb_read[i] = buffer[i];
		free(buffer);
	}
	i = 0;