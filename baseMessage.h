#ifndef BASEMESSAGE
#define BASEMESSAGE
	class baseMessage {
	protected:
		unsigned char* messageBuffer;
		int messageId;
		int messageType;
	public:
		virtual void parseMessage()= 0;
		virtual void parseBack()= 0;
		virtual void print()= 0;
		unsigned char* getMessageBuffer();
		baseMessage(int messageId, int messageType);
		baseMessage();
		
	};
#endif 




