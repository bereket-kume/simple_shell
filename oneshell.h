void _puts(char *str);
int execute_cmd(char **av, char **args, char **environ, int ymh, int kotari);
char **search(char **environ);
char **_which(char *fpath);
void handle_signal(int signal);
int _stat(char **cmd, char **menged);
int *_error(char *argv, int count, char *args);
void *_calloc(unsigned int nmemb, unsigned int size);
