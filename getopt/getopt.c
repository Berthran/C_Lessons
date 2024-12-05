// Include the necessary header file
#include <unistd.h>
#include <stdio.h>

// Define the main function
int main(int argc, char *argv[]) {

	// Define the option flags and their expected behaviour
	char *optstring = "ho:v";

	// Set up a loop to process arguments using switch/case
	int opt;
	while ((opt = getopt(argc, argv, optstring)) != -1) {
		switch (opt) {
			case 'h':
				// Handle the help option
				printf("Help message\n");
				break;
			case 'o':
				// handle the output option with an argument
				// use the optarg variable to retrieve the  argument associated with an option
				// (e.g., -o filename gives filename in optarg
				printf("Output file: %s\n", optarg);
				break;
			case 'v':
				// handle the verbose option
				printf("Verbose mode enabled\n");
				break;
			default:
				// handle unknown options
				fprintf(stderr, "Usage: %s [-h] [-o filename] [-v]\n", argv[0]);
				return 1;
		}
	}

	// Handle non-option arguments
	for (int i = optind; i < argc; i++) {
		printf("Non-option argument: %s\n", argv[i]);
	}
	return 0;
}

