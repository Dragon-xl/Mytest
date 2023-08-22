#pragma once
#include"Codec.h"
class CodecFactory
{
public:
	CodecFactory();
	virtual Codec* createCodecFactory();
	virtual ~CodecFactory();
};

