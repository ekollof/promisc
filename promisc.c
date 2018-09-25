
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pcap.h>


int daemon(int nochdir, int noclose)
{
	int             fd;

	switch (fork()) {
	case -1:
		return -1;
	case 0:
		break;
	default:
		exit(0);
	}
	if (setsid() == -1)
		return -1;
	if (!nochdir)
		chdir("/");

	if (!noclose && (fd = open("/dev/null", O_RDWR, 0)) != -1) {
		dup2(fd, 0);
		dup2(fd, 1);
		dup2(fd, 2);
		if (fd > 2)
			close(fd);
	}
	return 0;
}

int main(int argc, char **argv) {

    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    if (argc < 2) {
        printf("No args. Looking up default nic\n");
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL) {
            fprintf(stderr, "Can't find default device. Pick one yourself\n");
            return 1;
        }           
    } else {
        dev = argv[1];
    }

    printf("Using device: %s\n", dev);

    if (daemon(0,0) < 0) {
        printf("Can't go into the background. Bailing\n");
    }



    handle = pcap_open_live(dev, BUFSIZ, 1, 100, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    while(1);

}
