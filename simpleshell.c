
/*
 * Read a line:
 *
 * 	"reading a line from stdin can be a hassle in C"
 * 	we don't know how much text user will enter so dynamically reallocate as necessary
 *
 * 	NOTE: C's stdio.h library has a function getline() that does the following
 * 
 */
#define LSH_RL_BUFSIZE 1024
char *lsh_read_line(void){
	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c; // reminder that EOF is an integer in C
	
	if (!buffer){
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while(1){
		// read a char
		c = getchar();

		// if hitting EOF, replace with null char and return
		if (c == EOF || c=='\n'){
			buffer[position] = '\0';
			return buffer;
		}

		else {
			buffer[position] = c;
		}

		position++;

		// dealing with buffer overflow, reallocate
		if (position >= bufsize){
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer){
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
/*
 * Continuing the comment about getline() above, the above function can be rewritten as:
 * char *lsh_read_line(void){
 * 	char *line = NULL;
 * 	ssize_t bufsize = 0; // getline will allocate buffer
 * 	getline(%line, %bufsize, stdin);
 * 	return line;
 * }


/*
 * PARSING THE LINE:
 * 	using space as the delimiter
 */
char **lsh_split_line(char *line){
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens){
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIM);
	while(token != NULL){
		tokens[position] = token;
		position++;

		if (position >= bufsize){
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));



/*
 * The bulk main loop
 */
void lsh_loop(void){
	char *line;
	char **args;
	int status;

	do{
		printf("> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while (status);
}
	

int main(int argc, char **argv){

	//load config files, if any
	
	
	// Run command loop
	lsh_loop();

	// perform any shutdown/cleanup
	
	return EXIT_SUCCESS;

}

