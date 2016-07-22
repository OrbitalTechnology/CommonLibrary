#include "queue.hpp"

namespace Orbital {
	namespace Queuing {
		Queue::Queue(const std::string topic) {
			this->m_Topic = topic;		
		}
		
		Queue::Queue(const Queue& queue) {
			this->m_Topic = queue.m_Topic;
		}
		
		Queue::~Queue() {

		}

		Queue& Queue::Subscribe(Orbital::Queuing::QueueHandler& handler) {
			this->m_Handlers.push_back(handler);
			
			return *this;
		}
	}
}