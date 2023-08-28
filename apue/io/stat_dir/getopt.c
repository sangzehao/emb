#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	const char *optstring = "-abc:d::e";
	int c;
	
	while(1){
		c = getopt(argc, argv, optstring);
		if(-1 == c)
			break;
		switch(c)
		{
			case 'a':
				printf("all\n");
				break;
			case 'b':
				printf("blocks\n");
				break;
			case 'c':
				printf("charactor\n");
				printf("-c argument:%s\n", optarg);
				break;
			case 'd':
				printf("device\n");
				if(optarg != NULL)
				{
					printf("-d option argument: %s\n", optarg);
					break;
			case 'e':
				printf("enviornment\n");
				break;
			case 1:
				printf("nonoption argument:%s\n", argv[optind-1]);
				break;
			default:
				break;
			}

		}
	}

	return 0;

}
