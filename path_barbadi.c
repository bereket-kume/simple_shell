#include "main.h"
char *path_barbadi(const char command)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char full_path(PATH_MAX);
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

		if (access(full_path,X_OK) == 0)
		{
			return strdup(full_path);
		}
		token=strtok(NULL, ":");
	}
	return NULL;
}


