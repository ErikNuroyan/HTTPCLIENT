#include "CLIENT.h"
#include <string>
using namespace std;
void main() {
	WSAData second;
	WORD smth;
	smth = MAKEWORD(2, 1);
	long SUCCESS;
	SOCKET sock;
	char  STRING [150];
	string GetInfo;
	char answer;
	SUCCESS = WSAStartup(smth, &second);
	
	sock = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN AddressToBeConnected;
	AddressToBeConnected.sin_addr.s_addr = inet_addr("127.0.0.1");
	AddressToBeConnected.sin_family = AF_INET;
	AddressToBeConnected.sin_port = htons(8000);
loop1:
	
	cout << "Do you wish to connect to the server?(y/n):";
	cin >> answer;

	if (answer == 'y') {

		
		int a=connect(sock, (SOCKADDR*)&AddressToBeConnected, sizeof(AddressToBeConnected));
		cout << a << endl;

		send(sock, "GET /index.html HTTP/1.1\r\n Host: 127.0.0.1\r\n\r\n", sizeof("GET / index.html HTTP / 1.1\r\n Host : 127.0.0.1\r\n\r\n"), 0);
		
		
			SUCCESS = recv(sock, STRING,50, 0);
			GetInfo = STRING;
			cout << "You've got a Message from Client" << GetInfo << endl;
			closesocket(sock);
			WSACleanup();
		
		
	}
	else if (answer == 'n') {
		cout << "Exiting" << endl;

	}
	else {
		cout << "Wrong input!!!" << endl;
		goto loop1;
	}











}