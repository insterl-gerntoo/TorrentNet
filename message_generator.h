struct Message{
	uint16_t type_identifier;
	uint32_t message_ID;
	uint32_t message_size;
	uint32_t message_crc;
	uint8_t *message_payload;
};

class MessageGenerator{
	private:
		uint32_t crc_table[256];
		void fill_crc_table(void);
		uint32_t crc32_calculate(uint32_t size, uint8_t *data);
	public:
		Message* getNodesRequest(NodeID node_id);
};
