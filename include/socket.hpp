#pragma once

#include <string>
#include <stdint.h>

namespace Orbital {
	namespace IO {

		enum SocketState {
			Unknown,
			Waiting,
			Listen,
			Connect,
			Error
		};

		class Socket {
		public:
			Socket();
			Socket(const Socket&);
			~Socket();

			Socket& SetAddress(const std::string address);
			Socket& SetPort(const uint16_t port);
			Socket& Listen();

		protected:
		
		private:
			std::string 		m_Address;
			uint16_t			m_Port;
			SocketState 		m_State;
		};
	}
}