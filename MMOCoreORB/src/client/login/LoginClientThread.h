/*
 * LoginClientThread.h
 *
 *  Created on: Sep 6, 2009
 *      Author: theanswer
 */

#pragma once

#include "LoginClient.h"

class LoginClientThread : public Thread {
	Reference<BaseClient*> client;

public:
	LoginClientThread(LoginClient* client) {
		LoginClientThread::client = client->getClient();

		setDetached();
	}

	~LoginClientThread() {
		client = nullptr;

	#ifdef WITH_STM
		TransactionalMemoryManager::closeThread();
	#endif
	}

	void run() {
		client->recieveMessages();
	}

	void stop() {
		client->stop();
	}
};
