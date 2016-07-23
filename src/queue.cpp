#include "queue.hpp"

#include <iostream>

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

		Queue& Queue::Subscribe(Orbital::Queuing::QueueHandler& queueHandler) {		
			Orbital::Queuing::QueueHandler* handler = &queueHandler;
			std::deque<Orbital::Queuing::Message>* queue = new std::deque<Orbital::Queuing::Message>();			

			std::pair<Orbital::Queuing::QueueHandler*, std::deque<Orbital::Queuing::Message>* > pair(queueHandler, queue);
			this->m_MessageQueues.insert(pair);

			return *this;
		}

		Queue& Queue::Publish(Orbital::Queuing::Message message) {
			// Iterate over all Handlers and push message to queue
			MessageQueue::iterator it = this->m_MessageQueues.begin();
			MessageQueue::iterator itEnd = this->m_MessageQueues.end();
			
			while(it != itEnd) {
				// Add Message to queue
				(it->second)->push_back(message);
				it++;
			}

			return *this;			
		}

		const bool Queue::Process() {
			// Iterate over all Handlers and pop message to handler
			MessageQueue::iterator it = this->m_MessageQueues.begin();
			MessageQueue::iterator itEnd = this->m_MessageQueues.end();
			
			while(it != itEnd) {
				// Process
				QueueHandler* handler = it->first;

				std::deque<Orbital::Queuing::Message>* queue = (it->second);
				std::deque<Orbital::Queuing::Message>::iterator itQueue = queue->begin();
				std::deque<Orbital::Queuing::Message>::iterator itQueueEnd = queue->end();

				while(itQueue != itQueueEnd) {
					Orbital::Queuing::Message msg = *itQueue;
					handler(msg);

					queue->erase(itQueue);

					itQueue = queue->begin();
					itQueueEnd = queue->end();
				}

				it++;
			}

			return true;
		}
	}
}