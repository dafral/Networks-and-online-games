#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include "Windows.h"
#include "WinSock2.h"
#include "Ws2tcpip.h"

bool InitializeLibs()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR)
	{
		// Log and handle error
		return false;
	}

	return true;

}

bool CleanupLibs()
{
	int iResult = WSACleanup();
	if (iResult != NO_ERROR)
	{
		//log and handle error
		return false;
	}

	return true;

}

int main(int argc, char **argv)
{
	SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in bindAddr;

	bindAddr.sin_family = AF_INET;
	bindAddr.sin_port = htons(bindAddr.sin_port);

	//IP address for bind()
	bindAddr.sin_addr.S_un.S_addr = INADDR_ANY;

	//Bind
	int enable = 1;
	int res = setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (const char*)&enable, sizeof(int));
	
	if (res == SOCKET_ERROR) {
		// Log and handle error
	}

	res = bind(s, (const struct sockaddr *)&bindAddr, sizeof(bindAddr));

	closesocket(s);
}