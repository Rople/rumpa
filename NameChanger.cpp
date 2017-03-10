#include "NameChanger.h"

void CNameChanger::Do() {
	int targetEnt = GetValidEnt();

	if (!targetEnt)
		return;

	const char* targetNick = GetNick(targetEnt);
	std::cout << targetNick << std::endl;
	int targetNickLen = strlen(targetNick);
	std::string newNick = "";

	char lastChar = targetNick[targetNickLen - 1];
	newNick.append(targetNick);
	newNick += lastChar;

	std::string command = "darkrp name " + newNick;
	//G::pEngineClient->ClientCmd(command.c_str());
}

bool CNameChanger::LuaIsValid() { // make sure global table and isvalid subject is on the stack respectively
	G::pClientLuaInterface->GetField(-1, "IsValid");
	G::pClientLuaInterface->Push(-2);
	G::pClientLuaInterface->Call(1, 1);

	bool isValid = G::pClientLuaInterface->GetBool(-1);
	G::pClientLuaInterface->Pop(1);

	std::cout << "IsValid = " << isValid << std::endl;

	return isValid;
}

int CNameChanger::GetValidEnt() {
	srand(time(0));
	int randomIndex = rand() % G::pEngineClient->GetMaxClients() + 1;

	if (G::pEngineClient->GetLocalPlayer() == randomIndex || !G::pClientEntityList->GetClientEntity(randomIndex) || lastIndex == randomIndex || !randomIndex)
		return 0;

	lastIndex = randomIndex;

	std::cout << "randomIndex = " << randomIndex << std::endl;
	return randomIndex;
}

const char* CNameChanger::GetNick(int entIndex) {
	G::pClientLuaInterface->PushSpecial(SPECIAL_GLOB);
	G::pClientLuaInterface->GetField(-1, "Entity");
	G::pClientLuaInterface->PushNumber(entIndex);
	G::pClientLuaInterface->Call(1, 1);

	Misc::DumpStack(420);
	if (!LuaIsValid())
		return "invalid";

	G::pClientLuaInterface->GetField(-1, "Nick");
	G::pClientLuaInterface->Push(-2);
	G::pClientLuaInterface->Call(1, 1);

	const char* nick = G::pClientLuaInterface->GetString(-1);
	G::pClientLuaInterface->Pop(3);

	return nick;
}