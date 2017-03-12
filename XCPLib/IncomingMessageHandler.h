#pragma once
#include "IIncomingMessageHandler.h"
#include "ConnectPositivePacket.h"
#include "XCPMaster.h"

class IncomingMessageHandler :
	public IIncomingMessageHandler
{
private:
	XCPMaster& m_Master;
	uint32_t m_ProcessedSeedLength;
	int32_t m_RemainingSeedLength;
	std::vector<uint8_t> m_SeedBytes;
	uint8_t m_KeyLength;
	std::vector<uint8_t> m_Key;
public:
	IncomingMessageHandler(XCPMaster& Master);
	virtual ~IncomingMessageHandler();
	virtual void Handle(ConnectPositivePacket& Packet);
	virtual void Handle(ResponsePacket& Packet);
	virtual void Handle(GetStatusResponsePacket& Packet);
	virtual void Handle(SynchResponsePacket& Packet);
	virtual void Handle(UploadResponse& Packet);
	virtual void Handle(ErrorAccessLockedPacket& Packet);
	virtual void Handle(ErrorOutOfRangePacket& Packet);
	virtual void Handle(ErrorSequencePacket& Packet);
	virtual void Handle(ErrorMemoryOverflowPacket& Packet);
	virtual void Handle(StartStopDaqListPositiveResponse& Packet);
	virtual void Handle(GetSeedResponsePacket& Packet);
};

