#include "TaxPayMailTask.h"
#include "server/zone/managers/player/PlayerManager.h"

TaxPayMailTask::TaxPayMailTask(int tax, const String& mayor, ManagedReference<ChatManager*> chat, ManagedReference<CityRegion*> cityRegion) {
	mayorName = mayor;
	chatManager = chat;
	incomeTax = tax;
	city = cityRegion;

	setCustomTaskQueue("slowQueue");
}

void TaxPayMailTask::run() {
	int totalIncome = 0;

	StringIdChatParameter params("city/city", "income_tax_paid_body");
	params.setDI(incomeTax);

	auto zoneServer = chatManager->getZoneServer();

	ManagedReference<PlayerManager*> playerManager = zoneServer->getPlayerManager();

	for (int i = 0; i < citizens.size(); ++i) {
		uint64 citizenOID = citizens.get(i);

		String name = playerManager->getPlayerName(citizenOID);

		if (name.isEmpty())
			continue;

		params.setTO(name);

		TransactionLog trx(citizenOID, TrxCode::CITYINCOMETAX, incomeTax, false);

		if (!CreditManager::subtractBankCredits(citizenOID, incomeTax)) {
			// Failed to Pay Income Tax!
			params.setStringId("city/city", "income_tax_nopay_body");
			chatManager->sendMail("@city/city:new_city_from", "@city/city:income_tax_nopay_subject", params, name, nullptr);

			// Citizen Failed to Pay Income Tax
			params.setStringId("city/city", "income_tax_nopay_mayor_body");
			chatManager->sendMail("@city/city:new_city_from", "@city/city:income_tax_nopay_mayor_subject", params, mayorName, nullptr);

			trx.abort() << "Unable to pay income tax to city";

			continue;
		} else {
			trx.commit();
		}

		// City Income Tax Paid
		params.setStringId("city/city", "income_tax_paid_body");
		chatManager->sendMail("@city/city:new_city_from", "@city/city:income_tax_paid_subject", params, name, nullptr);

		totalIncome += incomeTax;
	}

	Locker clocker(city);

	city->addToCityTreasury(totalIncome);
}

void TaxPayMailTask::addCitizen(uint64 citizen) {
	citizens.add(citizen);
}