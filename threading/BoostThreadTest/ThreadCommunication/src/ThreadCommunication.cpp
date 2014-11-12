/*
 * ThreadCommunication.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: ErnieOnTheRun
 */

#include <iostream>
#include <string>
#include <list>

#include <boost/thread/thread.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/mutex.hpp>

class Request { };

template<typename T>
	class JobQueue {
	public:
		JobQueue () {};
		~JobQueue () {};

		void submitJob (const T& x){
			boost::mutex::scoped_lock lock(mutex_);
			list_.push_back(x);
			workToBeDone_.notify_one();
		}

		T getJob(){
			boost::mutex::scoped_lock lock(mutex_);

			workToBeDone_.wait(lock);

			T tmp = list_.front();
			list_.pop_front();

			return tmp;
		}

	private:
		std::list<T> list_;
		boost::mutex mutex_;
		boost::condition workToBeDone_;

	};

JobQueue<Request> myJobQueue;

void boss() {

	for (;;) {
		Request req;
		myJobQueue.submitJob(req);
	}

}

void worker (){

	for (;;) {
		Request r(myJobQueue.getJob());
	}
}

int main(){

	boost::thread thr1(boss);
	boost::thread thr2(worker);
	boost::thread thr3(worker);

	thr1.join();
	thr2.join();
	thr3.join();

}
