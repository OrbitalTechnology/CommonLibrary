#pragma once

#include <string>
#include <vector>

#include "message.hpp"

namespace Orbital {
	namespace Queuing {

		typedef void (QueueHandler)(const Orbital::Queuing::Message);

		class Queue {
			public:
				Queue(const std::string topic);
				Queue(const Queue&);
				~Queue();

				Queue& Subscribe(Orbital::Queuing::QueueHandler& handler);

			protected:

			private:
				std::string 									m_Topic;
				std::vector<Orbital::Queuing::QueueHandler*> 	m_Handlers;
		};
	}
}