#include <cstdint>
#include <vector>


#define UDP_MAGIC_NUMBER 0x80081E51

struct MessageChunk{
	uint32_t magic_number;
	uint16_t message_ID;
	uint16_t payload_size;
	uint16_t message_fraction;
	uint8_t *message_data;
};

//Ids best UDP manager ebar :DDDD
class SpurdoMessage{
	private:
		vector<MessageChunk> inbound_pool, inbound_resend_pool;
		vector<MessageChunk> outbound_pool, outbound_resend_pool;
		vector<uint8_t> inbound_buffer, outbound_buffer;
	public:
		SpurdoMessage();
	
		void lossless_send_to(IP_Portnum ip_port, uint32_t size, uint8_t* data);
		uint8_t* lossless_recv_from(IP_Portnum ip_port, uint32_t &size);
	
		void send_to(IP_Portnum ip_port, uint32_t size, uint8_t* data);
		uint8_t* recv_from(IP_Portnum ip_port, uint32_t &size);
};
