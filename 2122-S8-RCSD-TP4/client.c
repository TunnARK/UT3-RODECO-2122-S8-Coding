#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

const int port = 8000;
const char * message = "Bonjour";

int main(int argc, char ** argv)
{
	struct sockaddr_in sock_host;
	int sock;

	/* ouverture d'une socket */
	sock = socket(AF_INET, SOCK_STREAM, 0);

	/* on cree l'adresse de la machine distante */
	memset(& sock_host, '\0', sizeof(sock_host));
	sock_host.sin_family = AF_INET;
	sock_host.sin_port = htons(port);
	inet_aton("127.0.0.1", & sock_host.sin_addr);

	/* on demande un connection sur l'adresse distante */
	connect(sock, (struct sockaddr *) & sock_host, sizeof(sock_host));

	/* on envoi le message sur le serveur */
	write(sock, message, strlen(message));

	/* on ferme la socket */
	close(sock);
return 0;
}
