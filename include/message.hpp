#pragma once

#include <string>

namespace Orbital {
	namespace Queuing {
		class Message {
			public:
				Message();
				Message(const std::string);
				Message(const Message&);
				~Message();

				const std::string Content() const;

			protected:

			private:
				std::string 		m_Message;
		};
	}
}