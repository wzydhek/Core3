/*
 * AccountManager.h
 *
 *  Created on: Oct 13, 2010
 *      Author: crush
 */

#pragma once

#include "server/login/account/Account.h"

namespace server {
	namespace login {

		class LoginServer;
		class LoginClient;

		namespace account {

			class Account;

			class AccountManager : public Singleton<AccountManager>, public Logger, public Object {
				ManagedReference<LoginServer*> loginServer;

				String requiredVersion;

				bool autoRegistration;

				bool enableSessionId;

				uint32 maxOnlineCharacters;

				String dbSecret;

				static ReadWriteLock mutex;

			public:
				AccountManager(LoginServer* loginserv);
				~AccountManager();

				void loginAccount(LoginClient* client, Message* packet);

				bool loginFinalize(LoginClient* client, ManagedReference<Account*> account);

#ifdef WITH_SWGREALMS_API
				void loginApprovedAccount(LoginClient* client, ManagedReference<Account*> account);
#else // !WITH_SWGREALMS_API
				Reference<Account*> validateAccountCredentials(LoginClient* client, const String& username, const String& password);

				Reference<Account*> createAccount(const String& username, const String& password, String& passwordStored);

				void updateHash(const String& username, const String& password);
#endif // WITH_SWGREALMS_API

				//These lookup an account on the mysql database...
				//Account* lookupAccount(uint32 accountID);
				//Account* lookupAccount(uint64 characterID);
				//Account* lookupAccount(const String& username);

				void setRequiredVersion(const String& version);

				void setAutoRegistrationEnabled(bool enabled);

				void setDBSecret(const String& secret);

				bool isRequiredVersion(const String& version);

				bool isAutoRegistrationEnabled();

#ifndef WITH_SWGREALMS_API
				static void expireSession(Reference<Account*> account, const String& sessionID);
#endif

				static Reference<Account*> getAccount(uint32 accountID, bool forceSqlUpdate = false);

				static Reference<Account*> getAccount(const String& accountName, bool forceSqlUpdate = false);

#ifndef WITH_SWGREALMS_API
				static Reference<Account*> getAccount(uint32 accountID, String& passwordStored, bool forceSqlUpdate = false);

			private:
				static Reference<Account*> getAccount(String query, String& passwordStored, bool forceSqlUpdate = false);
#endif // !WITH_SWGREALMS_API
			};
		}
	}
}

using namespace server::login::account;
