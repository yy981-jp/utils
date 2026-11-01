#define _WIN32_WINNT 0x0600

#include <iostream>
#include <string>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <windows.h>
#include <locale>
#include <codecvt>	// 変換用
#include <string_view>

std::string get_lan_ipv4() {
	ULONG bufferSize = 0;
	GetAdaptersAddresses(AF_INET, GAA_FLAG_INCLUDE_PREFIX, nullptr, nullptr, &bufferSize);

	std::string result;
	std::vector<BYTE> buffer(bufferSize);
	IP_ADAPTER_ADDRESSES* adapter = reinterpret_cast<IP_ADAPTER_ADDRESSES*>(buffer.data());

	if (GetAdaptersAddresses(AF_INET, GAA_FLAG_INCLUDE_PREFIX, nullptr, adapter, &bufferSize) != NO_ERROR) {
		return "";
	}

	for (; adapter != nullptr; adapter = adapter->Next) {
		if (adapter->OperStatus != IfOperStatusUp) continue;

		// アダプター名が "Wi-Fi" を含むか判定（wstring → string 変換）
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		std::string name = conv.to_bytes(adapter->FriendlyName);
		if (name.find("Wi-Fi") == std::string::npos) continue;

		for (IP_ADAPTER_UNICAST_ADDRESS* ua = adapter->FirstUnicastAddress; ua != nullptr; ua = ua->Next) {
			if (ua->Address.lpSockaddr->sa_family == AF_INET) {
				sockaddr_in* sa_in = reinterpret_cast<sockaddr_in*>(ua->Address.lpSockaddr);
				char ipStr[INET_ADDRSTRLEN];
				inet_ntop(AF_INET, &(sa_in->sin_addr), ipStr, sizeof(ipStr));
				result = ipStr;
				return result;
			}
		}
	}

	return "";
}


int main() {
	std::string ip = get_lan_ipv4();
	if (!ip.empty()) {
		std::cout << "LAN IP: " << ip << std::endl;
	} else {
		std::cout << "LAN IPが見つかりませんでした。" << std::endl;
	}
	return 0;
}
