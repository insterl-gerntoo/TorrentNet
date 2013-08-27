//Ids best UDP manager ebar :DDDD
class SpurdoMessage{
	public:
		SpurdoMessage();
	
		void lossless_send_to(IP_Portnum ip_port, uint32_t size, uint8_t* data);
		uint8_t* lossless_recv_from(IP_Portnum ip_port, uint32_t &size);
	
		void send_to(IP_Portnum ip_port, uint32_t size, uint8_t* data);
		uint8_t* recv_from(IP_Portnum ip_port, uint32_t &size);
};
