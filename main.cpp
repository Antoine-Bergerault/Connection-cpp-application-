#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")

int main()
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 2), &data);

	SOCKET socket_var = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (socket_var == INVALID_SOCKET)
	{
		std::cout << "Erreur creation socket : " << WSAGetLastError() << std::endl;
		return 0;
	}
	sockaddr_in server;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(6666);
	if (connect(socket_var, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		std::cout << "Erreur connection : " << WSAGetLastError() << std::endl;
		return 0;
	}
	std::cout << "Socket connecte !" << std::endl;
	closesocket(socket_var);
	WSACleanup();
}
