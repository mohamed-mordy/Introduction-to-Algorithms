#include <stdio.h>
#include <stdlib.h>

int parse_line(FILE *fptr, int *vertex, int *edges, int *len)
{
	if (feof(fptr) == 0) {
		char buffer[1000];
		FILE *tmp_fptr = tmpfile();
		fgets(buffer, 999, fptr);
		fprintf(tmp_fptr, "%s", buffer);
		rewind(tmp_fptr);
		*len = 0;
		fscanf(tmp_fptr, "%d", vertex);
		while (fscanf(tmp_fptr, "%d", &(edges[*len])) != EOF)
			(*len)++;
		fclose(tmp_fptr);
		return *len;
	} else {
		return EOF;
	}
}

