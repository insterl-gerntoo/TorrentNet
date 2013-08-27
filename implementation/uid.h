class UID{
	private:
		uint8_t bytes[16];
	public:
		UID operator+(UID &other);
		UID operator-(UID &other);
		UID operator+=(UID &other);
		UID operator-=(UID &other);
		void operator=(UID &assignment);
};
