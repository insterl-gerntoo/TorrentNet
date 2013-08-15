struct Message{
	uint16_t type_identifier;
	uint32_t message_ID;
	uint32_t message_size;
	uint32_t message_crc;
};

struct MessagePack{
	uint8_t *data;
	uint32_t size;
};

class MessageGenerator{
	MessagePack *getNodesRequest();
	MessagePack *getNodesResponse(
};
