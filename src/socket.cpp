#include "socket.hpp"

namespace Orbital {
	namespace IO {
		Socket::Socket() {
			this->m_Address = std::string("127.0.0.1");
			this->m_Port = 4895;
			this->m_State = Waiting;
		}

		Socket::Socket(const Socket& socket) {
			this->m_Address = socket.m_Address;
			this->m_Port = socket.m_Port;
			this->m_State = socket.m_State;
		}

		Socket::~Socket() {

		}

		Socket& Socket::SetAddress(const std::string address) {
			this->m_Address = address;
			return *this;
		}

		Socket& Socket::SetPort(const uint16_t port) {
			this->m_Port = port;
			return *this;
		}

		Socket& Socket::Listen() {
			this->m_State = SocketState::Listen;
			return *this;
		}
	}
}