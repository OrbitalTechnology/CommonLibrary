#include "message.hpp"

namespace Orbital {
	namespace Queuing {
		Message::Message() {

		}

		Message::Message(const std::string message) {
			this->m_Message = message;
		}

		Message::Message(const Orbital::Queuing::Message& message) {
			this->m_Message = message.m_Message;
		}

		Message::~Message() {

		}

		const std::string Message::Content() const {
			return this->m_Message;
		}
	}
}