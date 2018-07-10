#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int sd;
	struct sockaddr_in addr;

	sd = socket(PF_INET,SOCK_STREAM,0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(33333);
	
	inet_aton("127.0.0.1",&addr.sin_addr); //convert string to int

	connect(sd,&addr,sizeof(addr));

	send(sd,"Hello",strlen("Hello"),0);

	close(sd);
	
	return 0;
}

//no need to bind and listen
//just need to connect and send
