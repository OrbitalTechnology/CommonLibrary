#pragma once

#include <string>
#include <vector>
#include <deque>
#include <map>

#include "message.hpp"

namespace Orbital {
	namespace Queuing {

		typedef void (QueueHandler)(const Orbital::Queuing::Message);
		typedef std::map<Orbital::Queuing::QueueHandler*, std::deque<Orbital::Queuing::Message>* > MessageQueue;
		
		class Queue {
			public:
				Queue(const std::string topic);
				Queue(const Queue&);
				~Queue();

				Queue& Subscribe(Orbital::Queuing::QueueHandler& queueHandler);
				Queue& Publish(Orbital::Queuing::Message message);

				const bool Process();

			protected:

			private:
				std::string 									m_Topic;
				std::vector<Orbital::Queuing::QueueHandler*> 	m_Handlers;
				MessageQueue 									m_MessageQueues;
		};
	}
}